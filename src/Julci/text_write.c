/*
** EPITECH PROJECT, 2024
** text.c
** File description:
** THis is for clock
*/
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <math.h>
#include "my.h"
#include "../../include/jam.h"
#include <stdlib.h>
#include <stdio.h>

static int get_sec(int sec)
{
    while (sec >= 60)
        sec = sec - 60;
    return sec;
}

static int get_min(int sec)
{
    return sec / 60;
}

static int get_hour(int sec)
{
    return get_min(sec) / 60;
}

/*void my_clock(sfRenderWindow *window, print_t clock, plane_t *my_p)
{
    sfVector2f pos = {80 + 1700, 20};
    sfVector2f life_scale = {1, 1};
    sfVector2f life_value_pos = {1775, 12};
    sfTime t = sfClock_getElapsedTime(clock.clock);
    float s = t.microseconds / 1000000.0;

    fonter(pos, clock, int_str(get_hour(s)), window);
    pos.x += 35;
    fonter(pos, clock, ":", window);
    pos.x += 15;
    fonter(pos, clock, int_str(get_min(s)), window);
    pos.x += 35;
    fonter(pos, clock, ":", window);
    pos.x += 15;
    fonter(pos, clock, int_str(get_sec(s)), window);
    }*/

void fonter(sfVector2f pos, print_t clock, char *str, sfRenderWindow *w)
{
    sfText_setString(clock.text, str);
    sfText_setFont(clock.text, clock.font);
    sfText_setCharacterSize(clock.text, 30);
    sfText_setPosition(clock.text, pos);
    sfText_setColor(clock.text, sfBlack);
    sfRenderWindow_drawText(w, clock.text, NULL);
}

/*char *int_str(int nb)
{
    int one;
    int two;
    char *str = malloc(sizeof(char) * 2);
    int i = 0;

    if (nbrlen(nb) < 2){
        str[0] = '0';
        i++;
        two = nb % 10;
        str[1] = two + 48;
    }
    if (nbrlen(nb) == 2){
        one = nb / 10;
        str[0] = one + 48;
        two = nb % 10;
        str[1] = two + 48;
    }
    str[2] = '\0';
    return str;
    }*/
