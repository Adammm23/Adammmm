#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#  pracownicy-orm.py  

from peewee import *

baza_plik = 'pracownicy.sqlite3'
baza = SqliteDatabase(baza_plik)

class BazaModel(Model):
    class Meta:
        datebase = baza
        
        
class Premia(BazaModel):
    id = CharField(primary_key = True)
    premia = DecimalField()
    
    
class Dzial(BazaModel):
    id = IntegerField(primary_key = True)
    nazwa = CharField()
    siedziba = CharField()
    
    
class Pracownik(BazaModel):
    id = CharField(primary_key = True)
    imie = CharField()
    nazwisko = CharField()
    stanowisko = ForeignKey(Premia, related_name = 'pracownicy')
    data_zatr = CharField()
    placa = DeciamlField(deciaml_places=2)
    premia = DeciamlField(deciaml_places=2, default=0)
    id_dzial = ForeignKey(Dzial, related_name = 'pracownicy')
    
baza.connect()
baza.create_tables([Premia, Dzial, Pracownik], True)
