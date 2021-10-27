create table adatb_gyak.tanfolyam(
	tkod int primary key,
    ar int,
    tipus char(50) character set utf8,
    megnevezes char(100) character set utf8
);

create table adatb_gyak.resztvevo(
	tajszam char(20) primary key,
    nev char(100),
    lakcim char(100)
);


	