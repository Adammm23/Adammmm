#! /usr/bin/env python
# -*- coding: utf-8 -*-

import rg


class Robot:

    def act(self, game):

        # rodzaje pól: 'spawn', 'normal', 'obstacle', 'invalid'
        # rg.loc_types() - zwraca typ pola
        def czy_wejscie(poz):
            if 'spawn' in rg.loc_types(poz):
                return True
            return False
        # return['guard']
        # return ['suicide']
        # return ['move', (4, 5)]
        # return ['attack', (5, 4)]
        # ilu_wrogow = 0

        print(game.robots)

        lista_wrogow_obok = []

        for poz, robot in game.robots.iteritems():
            if robot.player_id != self.player_id:    # rozpoznanie wroga
                if rg.dist(poz, self.location) <= 1:
                    lista_wrogow_obok.append(poz)
                    # ilu_wrogow += 1
                    # return ['attack', poz]

        # rd.dist() - zwraca odległość między dwoma lokalizacjmi
        # rg.toward() - najkrótsza droga pomiędzy dwoma lokalizacjami

        if len(lista_wrogow_obok) > 2 and self.hp < 27:
            return['suicide']
        elif len(lista_wrogow_obok):
            return['attack', lista_wrogow_obok[0]]

        if self.location == rg.CENTER_POINT:
            return ['guard']

        # idź do środka planszy, ruch domyślny
        if czy_wejscie(self.poz):
            return ['move', rg.toward(self.location, rg.CENTER_POINT)]
