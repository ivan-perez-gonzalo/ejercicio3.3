DROP DATABASE IF EXISTS Campeonato;
CREATE DATABASE Campeonato;

USE Campeonato;

CREATE TABLE Jugador (
    Identificador INTEGER PRIMARY KEY NOT NULL,
    NombreUsuario TEXT NOT NULL,
    Contraseña TEXT NOT NULL
) ENGINE = InnoDB;
CREATE TABLE Partida (
    Identificador INTEGER PRIMARY KEY NOT NULL,
    FechaHoraFinalizacion DATETIME NOT NULL,
    Duracion INTEGER NOT NULL,
    Ganador INTEGER,
    FOREIGN KEY (Ganador) REFERENCES Jugador (Identificador)
) ENGINE = InnoDB;

CREATE TABLE Participacion (
    Jugador INTEGER NOT NULL,
    Partida INTEGER NOT NULL,
    FOREIGN KEY (Jugador) REFERENCES Jugador (Identificador),
    FOREIGN KEY (Partida) REFERENCES Partida (Identificador)
) ENGINE = InnoDB;
INSERT INTO Jugador VALUES(1, 'Ivan', 'contra1');
INSERT INTO Jugador VALUES(2, 'Rodrigo', 'contra2');
INSERT INTO Jugador VALUES(3, 'Asier', 'contra3');
INSERT INTO Jugador VALUES(4, 'Josep', 'contra4');
INSERT INTO Jugador VALUES(5, 'Mireia', 'contra5');

INSERT INTO Partida VALUES(1, '2024-01-15 11:30:00', 110, 4);
INSERT INTO Partida VALUES(2, '2024-01-15 12:30:00', 120, 1); 
INSERT INTO Partida VALUES(3, '2024-01-15 13:15:00', 85, 2); 


INSERT INTO Participacion VALUES(1, 1);
INSERT INTO Participacion VALUES(2, 1);
INSERT INTO Participacion VALUES(3, 1);
INSERT INTO Participacion VALUES(4, 2);
INSERT INTO Participacion VALUES(5, 2);
INSERT INTO Participacion VALUES(1, 3);
INSERT INTO Participacion VALUES(3, 3);
INSERT INTO Participacion VALUES(4, 3);
