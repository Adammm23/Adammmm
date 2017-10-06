#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#  dane.py
#
import csv

def dane_z_pliku(plik, delimiter='\t'):
    dane = []
    with open(plik, 'r') as plikcsv:
        tresc = csv.reader(plikcsv, delimiter='\t')
    
        for rekord in tresc:
            dane.append(rekord)
    
    print(dane)    
    

def main(args):
    #dane_z_pliku('premia.txt')
    dane_z_pliku('pracownicy.txt')
    return 0

if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
