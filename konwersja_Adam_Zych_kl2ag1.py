#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#  konwersja.py

def konwertuj(liczba10, podst):
    reszty = []
    while liczba10 != 0:
        reszty.append(liczba10 % podst)
        liczba10 = liczba10 / podst
        
    reszty.reverse()
    print reszty

def main(args):
    liczba10 = int(raw_input("Podaj liczbe: "))
    podst = int(raw_input("Podaj podstawe: "))
    
    konwertuj(liczba10, podst)
    return 0

if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
