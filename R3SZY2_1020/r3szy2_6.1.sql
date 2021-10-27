create table adatb_gyak.gyarto(
	adoszam int primary key,
    nev char(30) character set utf8
);
create table adatb_gyak.termek(
	adoszam int primary key,
	nev char(50) character set utf8,
    ear numeric(5,3) not null,
    gyarto int,
    foreign key(gyarto) references gyarto(adoszam)
);
