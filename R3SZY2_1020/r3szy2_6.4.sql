CREATE TABLE adatb_gyak.termekek (tkod INT PRIMARY KEY, nev varchar(50) NOT NULL, ear INT
CHECK (EAR > 0), kategoria CHAR(20));

insert into adatb_gyak.termekek(tkod, nev, ear, kategoria)
values(1, lapát, 2000, K1);
insert into adatb_gyak.termekek(tkod, nev, ear, kategoria)
values(2, seprű, 4000, K1);
insert into adatb_gyak.termekek(tkod, nev, ear, kategoria)
values(3, "mosogató gél", 1500, K2);
insert into adatb_gyak.termekek(tkod, nev, ear, kategoria)
values(4, szappan, 1000, K2);
insert into adatb_gyak.termekek(tkod, nev, ear, kategoria)
values(5, pohár, 2400, K3);



