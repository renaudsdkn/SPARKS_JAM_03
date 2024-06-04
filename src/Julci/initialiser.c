/*
** EPITECH PROJECT, 2024
** initialiser.c
** File description:
** my initialiser
*/

#include "../../include/jam.h"
#include <SFML/Graphics.h>
#include "my.h"
#include <stdio.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <SFML/System.h>

int initialiser(print_t *key, my_big_t *big, int ac, char **av)
{
    key->clock = sfClock_create();
    key->text = sfText_create();
    key->font = sfFont_createFromFile("font/Serenata Vantages Regular.ttf");
    key->menu_r = menu_rect(key->menu_r);
    key->fpers = sfClock_create();
    key->c_size = 55;
    sfRenderWindow_setFramerateLimit(key->window, 32);
}

sfRectangleShape **menu_rect(sfRectangleShape **m_rect)
{
    m_rect = malloc(sizeof(sfRectangleShape *) * 3);
    m_rect[0] = m_rect_s(50, 150, m_rect[0], 220);
    m_rect[1] = m_rect_s(50, 200, m_rect[1], 100);
    m_rect[2] = m_rect_s(50, 250, m_rect[2], 55);
    return m_rect;
}

sfRectangleShape *m_rect_s(float x, float y, sfRectangleShape *s, float e)
{
    sfVector2f pos = {x, y};
    sfVector2f size = {e, x};

    s = sfRectangleShape_create();
    sfRectangleShape_setSize(s, size);
    sfRectangleShape_setFillColor(s, sfTransparent);
    sfRectangleShape_setPosition(s, pos);
    return s;
}

more_sprite_t *cloud_initiation(more_sprite_t *sprite)
{
    sfVector2f p_one = {70 + 1700, 25};

    sprite->convex = sfConvexShape_create();
    sfConvexShape_setPointCount(sprite->convex, 5);
    sfConvexShape_setPoint(sprite->convex, 0, p_one);
    p_one.x += 150;
    sfConvexShape_setPoint(sprite->convex, 1, p_one);
    p_one.x = p_one.x - 150;
    p_one.y += 33;
    sfConvexShape_setPoint(sprite->convex, 4, p_one);
    p_one.x = p_one.x + 75;
    p_one.y += 25;
    sfConvexShape_setPoint(sprite->convex, 3, p_one);
    p_one.x += 75;
    p_one.y += -27;
    sfConvexShape_setPoint(sprite->convex, 2, p_one);
    sprite = clock_sprite(sprite);
    return sprite;
}

more_sprite_t *clock_sprite(more_sprite_t *sprite)
{
    sfVector2f pos = {90 + 1700, 05};
    sfVector2f scale = {0.2, 0.2};
    sfTexture *text = sfTexture_createFromFile("./timepiece.png", NULL);

    sprite->sprite = sfSprite_create();
    sfSprite_setTexture(sprite->sprite, text, sfTrue);
    sfSprite_setScale(sprite->sprite, scale);
    sfSprite_setPosition(sprite->sprite, pos);
    SFCSFC(sprite->convex, sfColor_fromRGBA(0, 0, 255, 128));
    sfConvexShape_setOutlineColor(sprite->convex, sfBlue);
    sfConvexShape_setOutlineThickness(sprite->convex, 1.6);
    return sprite;
}
