CREATE TABLE Cliente (
	nombre VARCHAR(50) PRIMARY KEY,
	tlf    CHAR(9)     NOT NULL
);

CREATE TABLE Vacuna (
	cod_v  CHAR(20) PRIMARY KEY CHECK (cod_v LIKE 'VAC%') ,
	descr VARCHAR(1000)
);

CREATE TABLE Veterinario (
	cod_vet CHAR(20) PRIMARY KEY CHECK (cod_vet LIKE 'VET%') ,
	nombre  VARCHAR(50) NOT NULL
);

CREATE TABLE Tiene_Mascota (
	cod_m          CHAR(15) PRIMARY KEY CHECK (cod_m LIKE 'M%') ,
	nombre         VARCHAR(50) NOT NULL,
	nombre_cliente VARCHAR(50) NOT NULL REFERENCES Cliente(nombre)
);

CREATE TABLE Perro (
	cod_m CHAR(15)    NOT NULL REFERENCES Tiene_Mascota(cod_m),
	raza  VARCHAR(30) NOT NULL
);

CREATE TABLE Hamster (
	cod_m  CHAR(15)    NOT NULL REFERENCES Tiene_Mascota(cod_m),
	color  VARCHAR(15)
);

CREATE TABLE Gato (
	cod_m CHAR(15) NOT NULL REFERENCES Tiene_Mascota(cod_m),
	tam   INT      NOT NULL
);

CREATE TABLE Pone_Administra (
	cod_m   CHAR(15) NOT NULL REFERENCES Tiene_Mascota(cod_m),
	cod_v   CHAR(20) NOT NULL REFERENCES Vacuna(cod_v),
	cod_vet CHAR(20) NOT NULL REFERENCES Veterinario(cod_vet),
	fecha   DATE NOT NULL,

	PRIMARY KEY (cod_m, cod_v, fecha)
);

INSERT INTO Cliente VALUES ('Atanasio Rubio Gil', '133755585');
INSERT INTO Vacuna VALUES ('VAC365HVNSIR628WBGHR', 'Vacuna contra la tontería: Esta vacuna incrementa 1 punto de Inteligencia en la mascota objetivo. No pueden ser objetivo de esta vacuna mascotas con bónuses de Inteligencia negativos temporales.');
INSERT INTO Veterinario VALUES ('VETFHTUUIW856281BNUE', 'Hermenegildo Jovenzuelo');
INSERT INTO Tiene_Mascota VALUES ('M174HGYR6294BH', 'Perrotrón 2000', 'Atanasio Rubio Gil');
INSERT INTO Tiene_Mascota VALUES ('M7593BFHGIR37R', 'Hamsterneitor', 'Atanasio Rubio Gil');
INSERT INTO Tiene_Mascota VALUES ('M543J3B6456345', 'Pulpogato', 'Atanasio Rubio Gil');
INSERT INTO Perro VALUES ('M174HGYR6294BH', 'Lhasa Apso');
INSERT INTO Hamster VALUES ('M7593BFHGIR37R', null);
INSERT INTO Gato VALUES ('M543J3B6456345', 23);
INSERT INTO Pone_Administra VALUES ('M174HGYR6294BH', 'VAC365HVNSIR628WBGHR', 'VETFHTUUIW856281BNUE', SYSDATE);
