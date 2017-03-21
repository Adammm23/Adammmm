#!/usr/bin/env python
# -*- coding: utf-8 -*-


def szyfruj_cezar(tekst, klucz):
    klucz = klucz % 26
    szyfrogram = ''
    i = 0
    for znak in tekst:
        if(tekst[i] == ' '):
            szyfrogram += ' '
            continue
        znak = znak.lower()
        if ord(znak) + klucz > 122:
            szyfrogram += chr(ord(znak) + klucz - 26)
        else:
            szyfrogram += chr(ord(znak) + klucz)
    return szyfrogram


def main(args):
    tekst = raw_input("Podaj tekst: ")
    klucz = int(raw_input("Podaj klucz: "))
    szyfrogram = szyfruj_cezar(tekst, klucz)
    print szyfrogram
    return 0


if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
