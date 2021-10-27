alter table adatb_gyak.gyarto add column irsz char(40) character set utf8;
alter table adatb_gyak.gyarto add column varos char(40) character set utf8;
alter table adatb_gyak.gyarto add column utca char(100) character set utf8;

create table adatb_gyak.egysegek(
	aru int,
    foreign key(aru) references termek(tkod),
    darab numeric(5,3) not null
    );

create table adatb_gyak.alkatresz(
	akod int primary key,
    nev char(40) character set utf8
);

create table adatb_gyak.komponens(
	termek int,
    foreign key(termek) references termek(tkod),
    alkatresz int,
    foreign key(alkatresz) references alkatresz(akod)
);

