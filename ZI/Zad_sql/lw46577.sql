
#CREATE TABLE Zamowienia_UNF3
#(	NumerZam int,
#	NazwaKlienta varchar(100) CHARACTER SET utf8 COLLATE utf8_unicode_ci,
#	AdresKlienta varchar(100) CHARACTER SET utf8 COLLATE utf8_unicode_ci,
#	DataZamowienia date,
#	SzczegolyZamowienia varchar(100) CHARACTER SET utf8 COLLATE utf8_unicode_ci);
#INSERT INTO Zamowienia_UNF3(NumerZam,NazwaKlienta,AdresKlienta,DataZamowienia, SzczegolyZamowienia) 
#VALUES (101,'Jan Kowalski','ul. Jana Pawła 12, 61-600 Poznań, woj. Wielkopolskie','2012-01-02','Opony 205 R16 4szt, koszt 1200 PLN'),
#(102,'Anna Dymna','ul. Staszica 1, 30-600 Kraków, Małopolska','2012-03-22','Alufelgi Silver 4 szt, koszt 2200 PLN'),
#(103,'Piotr Wawrzyniak','al. Niepodległości 1, 30-600 Kraków, woj. Małopolskie','2012-03-22','Alufelgi Silver 4 szt, koszt 2200 PLN'),
#(104,'Jan Kowalski','ul. Jana Pawła 12, 61-600 Poznań, woj. Wielkopolskie','2012-10-22','Komplet żarówek, koszt 80 PLN'),
#(105,'Jan Kowalski','ul. Poznańska 8, 21-120 Wrocław, Dolnośląskie','2012-05-22','Płyn do spryskiwacza 1szt, Trójkąt ostrzegawczy 1szt, koszt 15 PLN')

select  * from lw46577.Zamowienia_UNF3 ;
 
 
# create table Zamowienia_1NF(
# NumerZam int(6) UNSIGNED AUTO_INCREMENT PRIMARY KEY,
# Imie VARCHAR(50) CHARACTER SET utf8 COLLATE utf8_unicode_ci,
# Nazwisko VARCHAR(50) CHARACTER SET utf8 COLLATE utf8_unicode_ci,
# Data_zam Date,
# Ulica VARCHAR(40) CHARACTER SET utf8 COLLATE utf8_unicode_ci,
# Numer_domu int(6),
# Kod_Pocztowy VARCHAR(20) CHARACTER SET utf8 COLLATE utf8_unicode_ci,
# Miasto VARCHAR(30) CHARACTER SET utf8 COLLATE utf8_unicode_ci,
# Województwo VARCHAR(30) CHARACTER SET utf8 COLLATE utf8_unicode_ci,
# Produkt_nazwa VARCHAR(60) CHARACTER SET utf8 COLLATE utf8_unicode_ci,
# Ilosc_sztuk int(6),
# Cena int(10)
# );
 
--  INSERT INTO lw46577.Zamowienia_1NF(NumerZam,Imie,Nazwisko,Data_zam,Ulica,Numer_domu,Kod_Pocztowy,Miasto,Województwo,Produkt_nazwa,Ilosc_sztuk,Cena) 
--  VALUES (101,'Jan', 'Kowalski','2012-01-02','Jana Pawła','12', '61-600', 'Poznań', 'Wielkopolskie','Opony 205 R16',4,1200),
-- (102,'Anna', 'Dymna','2012-03-22','Staszica','1', '30-600', 'Kraków', 'Małopolskie','Alufelgi Silver',4,2200),
-- (103,'Piotr', 'Wawrzyniak','2012-03-22','Niepodległości', '1', '30-600', 'Kraków', 'Małopolskie','Alufelgi Silver',4,2200),
-- (104,'Jan', 'Kowalski','2012-10-22','Jana Pawła','12', '61-600', 'Poznań', 'Wielkopolskie','Komplet żarówek',1,80),
-- (105,'Jan', 'Kowalski','2012-05-22','Poznańska', '8', '21-120', 'Wrocław', 'Dolnośląskie','Płyn do spryskiwacza',1,7),
-- (106,'Jan', 'Kowalski','2012-05-22','Poznańska', '8', '21-120', 'Wrocław', 'Dolnośląskie','Trójkąt ostrzegawczy',1,8);

 select * from lw46577.Zamowienia_1NF;
 
-- create table Klient_2NF
-- (	
-- 	Numer_Klienta int(6) UNSIGNED AUTO_INCREMENT PRIMARY KEY,
-- 	Imie VARCHAR(50) CHARACTER SET utf8 COLLATE utf8_unicode_ci,
-- 	Nazwisko VARCHAR(50) CHARACTER SET utf8 COLLATE utf8_unicode_ci,
-- 	Ulica VARCHAR(40) CHARACTER SET utf8 COLLATE utf8_unicode_ci,
-- 	Numer_domu int(6),
-- 	Kod_Pocztowy VARCHAR(20) CHARACTER SET utf8 COLLATE utf8_unicode_ci,
-- 	Miasto VARCHAR(30) CHARACTER SET utf8 COLLATE utf8_unicode_ci,
-- 	Województwo VARCHAR(30) CHARACTER SET utf8 COLLATE utf8_unicode_ci
-- );

-- INSERT INTO lw46577.Klient_2NF(Numer_Klienta,Imie,Nazwisko,Ulica,Numer_domu,Kod_Pocztowy,Miasto,Województwo) 
-- VALUES (1,'Jan', 'Kowalski','Jana Pawła','12', '61-600', 'Poznań', 'Wielkopolskie'),
-- (2,'Anna', 'Dymna','Staszica','1', '30-600', 'Kraków', 'Małopolskie'),
-- (3,'Piotr', 'Wawrzyniak','Niepodległości', '1', '30-600', 'Kraków', 'Małopolskie'),
-- (4,'Jan', 'Kowalski','Poznańska', '8', '21-120', 'Wrocław', 'Dolnośląskie');

-- CREATE TABLE Zamowienia_2NF
-- (	
-- 	NumerZam int(6),
-- 	Numer_Klienta int(6),
-- 	Numer_Detalu int(6),
-- 	DataZamowienia date
-- );

-- INSERT INTO lw46577.Zamowienia_2NF(NumerZam,Numer_Klienta,Numer_Detalu,DataZamowienia) 
-- VALUES (101,1,1,'2012-01-02'),
-- (102,2,2,'2012-03-22'),
-- (103,3,3,'2012-03-22'),
-- (104,1,4,'2012-10-22'),
-- (105,4,5,'2012-05-22'),
-- (106,4,6,'2012-05-22');

-- CREATE TABLE DetaleZamowien_2NF2
-- (	
-- 	Numer_Delatu int(6),
--     NumerZam int(6),
-- 	Numer_Produktu int(6),
--     Ilosc_sztuk int(6),
--     Wartosc int(6)
-- );

-- INSERT INTO lw46577.DetaleZamowien_2NF2(Numer_Delatu,NumerZam,Numer_Produktu,Ilosc_sztuk, Wartosc) 
-- VALUES (1,101,1,4,1200),
-- (2,102,2,4,2200),
-- (3,103,2,4,2200),
-- (4,104,3,1,80),
-- (5,105,4,1,8),
-- (6,106,5,1,7);

-- CREATE TABLE Produkty_2NF
-- (	
-- 	Numer_Produktu int(6),
-- 	Nazwa varchar(60) CHARACTER SET utf8 COLLATE utf8_unicode_ci,
--     Cena int(6)
-- );

-- INSERT INTO lw46577.Produkty_2NF(Numer_Produktu,Nazwa,Cena) 
-- VALUES (1,'Opony 205 R16',300),
-- (2,'Alufelgi Silver',550),
-- (3,'Komplet żarowek',80),
-- (4,'Płyn do spryskiwacza',7),
-- (5,'Trójkąt ostrzegawczy',8);

select zam.NumerZam,Imie,Nazwisko,DataZamowienia,Ulica,Numer_domu,Kod_Pocztowy,Miasto,Województwo,Nazwa,Ilosc_sztuk,Wartosc from lw46577.Zamowienia_2NF as zam join lw46577.Klient_2NF as kli on zam.Numer_Klienta=kli.Numer_Klienta join lw46577.DetaleZamowien_2NF2 as detal on detal.Numer_Delatu=zam.Numer_Detalu join lw46577.Produkty_2NF as prod on prod.Numer_Produktu=detal.Numer_Produktu;

-- CREATE TABLE Klient_3NF
-- (	
-- 	Numer_Klienta int(6) AUTO_INCREMENT PRIMARY KEY,
-- 	Imie VARCHAR(50) CHARACTER SET utf8 COLLATE utf8_unicode_ci,
-- 	Nazwisko VARCHAR(50) CHARACTER SET utf8 COLLATE utf8_unicode_ci,
-- 	Ulica VARCHAR(40) CHARACTER SET utf8 COLLATE utf8_unicode_ci,
-- 	Numer_domu int(6),
-- 	Kod_Pocztowy VARCHAR(20) CHARACTER SET utf8 COLLATE utf8_unicode_ci,
-- 	Miasto VARCHAR(30) CHARACTER SET utf8 COLLATE utf8_unicode_ci,
-- 	Województwo VARCHAR(30) CHARACTER SET utf8 COLLATE utf8_unicode_ci
-- );

-- INSERT INTO lw46577.Klient_3NF(Numer_Klienta,Imie,Nazwisko,Ulica,Numer_domu,Kod_Pocztowy,Miasto,Województwo) 
-- VALUES (1,'Jan', 'Kowalski','Jana Pawła','12', '61-600', 'Poznań', 'Wielkopolskie'),
-- (2,'Anna', 'Dymna','Staszica','1', '30-600', 'Kraków', 'Małopolskie'),
-- (3,'Piotr', 'Wawrzyniak','Niepodległości', '1', '30-600', 'Kraków', 'Małopolskie'),
-- (4,'Jan', 'Kowalski','Poznańska', '8', '21-120', 'Wrocław', 'Dolnośląskie');


-- CREATE TABLE Zamowienia_3NF
-- (	
-- 	NumerZam int(6) AUTO_INCREMENT PRIMARY KEY,
-- 	Numer_Klienta int(6),
-- 	Numer_Detalu int(6),
-- 	DataZamowienia date
-- );

-- INSERT INTO lw46577.Zamowienia_3NF(NumerZam,Numer_Klienta,Numer_Detalu,DataZamowienia) 
-- VALUES (101,1,1,'2012-01-02'),
-- (102,2,2,'2012-03-22'),
-- (103,3,3,'2012-03-22'),
-- (104,1,4,'2012-10-22'),
-- (105,4,5,'2012-05-22'),
-- (106,4,6,'2012-05-22');


-- CREATE TABLE DetaleZamowien_3NF
-- (	
-- 	Numer_Delatu int(6) AUTO_INCREMENT PRIMARY KEY,
-- 	Numer_Produktu int(6),
--     Ilosc_sztuk int(6)
-- );

-- INSERT INTO lw46577.DetaleZamowien_3NF(Numer_Delatu,Numer_Produktu,Ilosc_sztuk) 
-- VALUES (1,1,4),
-- (2,2,4),
-- (3,2,4),
-- (4,3,1),
-- (5,4,1),
-- (6,5,1);



-- CREATE TABLE Produkty_3NF
-- (	
-- 	Numer_Produktu int(6) AUTO_INCREMENT PRIMARY KEY,
-- 	Nazwa varchar(60) CHARACTER SET utf8 COLLATE utf8_unicode_ci,
--     Cena int(6)
-- );

-- INSERT INTO lw46577.Produkty_3NF(Numer_Produktu,Nazwa,Cena) 
-- VALUES (1,'Opony 205 R16',300),
-- (2,'Alufelgi Silver',550),
-- (3,'Komplet żarowek',80),
-- (4,'Płyn do spryskiwacza',7),
-- (5,'Trójkąt ostrzegawczy',8);


select zam.NumerZam,Imie,Nazwisko,DataZamowienia,Ulica,Numer_domu,Kod_Pocztowy,Miasto,Województwo,Nazwa,Ilosc_sztuk,(cena*Ilosc_sztuk )as Wartosc from lw46577.Zamowienia_3NF as zam join lw46577.Klient_3NF as kli on zam.Numer_Klienta=kli.Numer_Klienta join lw46577.DetaleZamowien_3NF as detal on detal.Numer_Delatu=zam.Numer_Detalu join lw46577.Produkty_3NF as prod on prod.Numer_Produktu=detal.Numer_Produktu;