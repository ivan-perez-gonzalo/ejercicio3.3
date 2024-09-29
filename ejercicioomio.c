#include <mysql.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    MYSQL *conexion;
    int error;
    MYSQL_RES *res;
    MYSQL_ROW fila;

    // Inicializar la conexión al servidor MySQL
    conexion = mysql_init(NULL);
    if (conexion == NULL) {
        printf("Error al crear la conexión: %u %s\n", 
               mysql_errno(conexion), mysql_error(conexion));
        exit(1);
    }

    // Conectar a la base de datos
    conexion = mysql_real_connect(conexion, "localhost", "root", "mysql", "Campeonato", 0, NULL, 0);
    
    if (conexion == NULL) {
        printf("Error al conectar al servidor: %u %s\n", 
               mysql_errno(conexion), mysql_error(conexion));
        exit(1);
    }
    char consulta_sql[256];
    snprintf(consulta_sql, sizeof(consulta_sql),
             "SELECT Jugador.NombreUsuario "
             "FROM Jugador, Participacion "
             "WHERE Participacion.Partida = 1 "
             "AND Jugador.Identificador = Participacion.Jugador");
    // Ejecutar la consulta
    error = mysql_query(conexion, consulta_sql);
    if (error != 0) {
        printf("Error al realizar la consulta: %u %s\n", 
               mysql_errno(conexion), mysql_error(conexion));
        mysql_close(conexion);
        exit(1);
    }
    // Almacenar el resultado de la consulta
    res = mysql_store_result(conexion);
    if (res == NULL) {
        printf("Error al almacenar el resultado: %u %s\n", 
               mysql_errno(conexion), mysql_error(conexion));
        mysql_close(conexion);
        exit(1);
    }
    fila = mysql_fetch_row(res);
    if (fila == NULL) {
        printf("No hay jugadores participando en la mesa 1.\n");
    } else {
        printf("Jugadores en la mesa 1:\n");
        do {
            // Imprimir el nombre de cada jugador en la mesa 1
            printf("- %s\n", fila[0]);
        } while ((fila = mysql_fetch_row(res)) != NULL);
    }
    mysql_free_result(res);  
    mysql_close(conexion);  
    exit(0);
}

