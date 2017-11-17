# -*- coding: utf-8 -*-

from peewee import *

baza_plik = "szkola.db"
baza = SqliteDatabase(baza_plik)  # ':memory:'


class BazaModel(Model):  # klasa bazowa
    class Meta:
        database = baza


class Klasa(BazaModel):
    nazwa = CharField(null=False)
    rok_naboru = IntegerField(null=False)
    rok_matury = IntegerField(null=False)


class Przedmiot(BazaModel):
    nazwa = CharField(null=False)
    imien = CharField(null=False)
    nazwiskon = CharField(null=False)
    plecn = IntegerField(null=False)


class Uczen(BazaModel):
    imie = CharField(null=False)
    nazwisko= CharField(null=False)
    plec = IntegerField(null=False)
    klasa_id = ForeignKeyField(Klasa, related_name='Uczen')
    egzhum = IntegerField(null=False)
    egzmat = IntegerField(null=False)
    egzjez = IntegerField(null=False)


class Ocena(BazaModel):
    datad = DateField(null=False)
    uczen_id = ForeignKeyField(Uczen, related_name='Ocena')
    przedmiot_id = ForeignKeyField(Przedmiot, related_name='Ocena')
    ocena = DecimalField(decimal_places=2)


baza.connect()  # nawiązujemy połączenie z bazą

def kwerenda_3a():
    query = (Uczen
             .select(Uczen.imie, Uczen.nazwisko)
             .join(Klasa)
             .group_by(Klasa.nazwa('1a'))
             )

    for obj in query:
        print(obj.imie, obj.nazwisko)

kwerenda_3a()
