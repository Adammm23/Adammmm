#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#  uczniowie_py.py
#  
import sqlite3

def wyniki(cur):
    wyniki = cur.fetchall()
    for row in wyniki:
        print(tuple(row))

def kw_a(cur):
    cur.execute("""
    SELECT imie, nazwisko
    FROM tbUczniowie, tbKlasy
    WHERE tbUczniowie.KlasaID = tbKlasy.IDKlasy
    AND Klasa = "1A"
    """)
    
    wyniki(cur)

def kw_b(cur):
    cur.execute("""
    SELECT MAX (egzhum)
    FROM tbUczniowie
    """)
    
    wyniki(cur)
        
def kw_c(cur):
    cur.execute("""
    SELECT AVG(egzmat)
    FROM tbUczniowie, tbKlasy
    WHERE tbUczniowie.KlasaID = tbKlasy.IDKlasy
    AND Klasa = "1A"
    """)
    
    wyniki(cur)
        
def kw_d(cur):
    cur.execute("""
    SELECT ocena
    FROM tbUczniowie, tbOceny
    WHERE tbUczniowie.IDUcznia = tbOceny.UczenID
    AND imie = "Dorota"
    AND nazwisko = "Nowak"
    """)
    
    wyniki(cur)

def kw_e(cur):
    cur.execute("""
    SELECT AVG(Ocena)
    FROM tbOceny
    WHERE PrzedmiotID = 6
    AND strftime('%m', datad) LIKE '10'
    """)
    
    ## https://sqlite.org/lang datefunc.html
    
    wyniki(cur)

def kw_4a(cur):
    cur.execute("""
    UPDATE tbUczniowie
    SET Egzjez = ?
    WHERE imie = ?
    AND nazwisko = ?   
    """, [35, "Paulina", "Dziedzic"])
    cur.execute("""
    SELECT Egzjez
    FROM tbUczniowie
    WHERE imie = "Paulina"
    AND nazwisko = "Dziedzic"  
    """)
        
    wyniki(cur)
    
def kw_4b(cur):
    cur.execute('DELETE FROM tbOceny, tbUczniowie WHERE tbOceny.UczenID = tbUczniowie.IDUcznia AND imie = ? AND nazwisko = ? AND PrzedmiotID = ? AND Ocena = ?' ["Paulina", "Dziedzic", 1, 1])
    
def dodaj(cur):
    cur.execute("""
    INSERT INTO tbKlasy
    VALUES (?, ?, ?, ?)  
    """, [None, '3C', 2015, 2017])
    
def aktualizuj(cur):
    cur.execute("""
    UPDATE tbKlasy
    SET klasa = ?
    WHERE idklasy = ?  
    """, ['3D', 13])
    
def usun(cur):
    cur.execute('DELETE FROM tbKlasy WHERE klasa = ? AND roknaboru = ?', ['3B', 2015])
    
    
def main(args):
    con = sqlite3.connect('szkola.db')
    cur = con.cursor()    #utworzenie kursora
    con.row_factory = sqlite3.Row
    
    # dodaj(cur)
    #aktualizuj(cur)
    #usun(cur)
    #con.commit()
    #wyniki(cur.execute('SELECT * FROM tbKlasy'))
    
    kw_4b(cur)
    
    return 0

if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
