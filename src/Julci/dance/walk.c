/*
** EPITECH PROJECT, 2024
** JAM: Flame
** File description:
** move_player_t.c
*/

#include "../../../include/jam.h"

void walk_and_dance(sfRenderWindow *window)
{
    sfEvent event;
    sfRenderWindow *window;
    sfVector2f pos = {0, 500};
    sfIntRect rect = {0, 704, 64, 64};
    sfClock *clock = sfClock_create();
    sfVideoMode mode = {1920, 1080, 32};
    sfSprite *sprite = sfSprite_create();
    sfSprite *background_sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile("../img/male.png", NULL);
    sfTexture *background_texture = sfTexture_createFromFile("../images/Forest.jpg", NULL);

    sfSprite_setTexture(sprite, texture, sfFalse);
    sfSprite_setTexture(background_sprite, background_texture, sfFalse);
    window = sfRenderWindow_create(mode, "SFML window", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 10);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        if (pos.x > 500.0 && rect.top == 640) {
            rect.top = 0;
            rect.left = 0;
        }
        if (pos.x < 510) {
            if (rect.left < 550 && rect.top != 640) {
                rect.left += 64;
                pos.x += 5.5;
            }
            if (pos.x + 5.0 >= 500) {
                rect.top = 640;
                pos.x += 2.5;
            }
            rect.left = (rect.left < 128 && rect.top == 640) ? rect.left + 64 : rect.left;
            rect.left = (rect.left > 550 && rect.top != 640) ? 0 : rect.left;
        }
        if (rect.top < 1000 && pos.x >= 505) {
            rect.left = (rect.left < 420 && rect.top < 230) ? rect.left + 64 : rect.left;
            if (rect.left > 420 && rect.top < 230) {
                rect.left = 0;
                rect.top += 64;
            }
            rect.top = (rect.top > 230 && rect.top < 300) ? 832 : rect.top;
            if (rect.left < 360 && rect.top >= 832) {
                rect.left += 64;
            }
            if (rect.left > 360 && rect.top >= 832) {
                rect.left = 0;
                rect.top += 64;
            }
        }
        if (rect.top > 1000)
            rect.top = 0;
        sfSprite_setPosition(sprite, pos);
        sfSprite_setTextureRect(sprite, rect);
        sfRenderWindow_drawSprite(window, background_sprite, NULL);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
}

int main(void)
{
    sfTime time;
    sfEvent event;
    sfRenderWindow *window;
    sfVector2f pos = {0, 500};
    sfIntRect rect = {0, 704, 64, 64};
    sfClock *clock = sfClock_create();
    sfVideoMode mode = {1920, 1080, 32};
    sfSprite *sprite = sfSprite_create();
    sfSprite *background_sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile("../img/male.png", NULL);
    sfTexture *background_texture = sfTexture_createFromFile("../images/Forest.jpg", NULL);

    sfSprite_setTexture(sprite, texture, sfFalse);
    sfSprite_setTexture(background_sprite, background_texture, sfFalse);
    window = sfRenderWindow_create(mode, "SFML window", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 10);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        if (pos.x > 500.0 && rect.top == 640) {
            rect.top = 0;
            rect.left = 0;
        }
        if (pos.x < 510) {
            if (rect.left < 550 && rect.top != 640) {
                rect.left += 64;
                pos.x += 5.5;
            }
            if (pos.x + 5.0 >= 500) {
                rect.top = 640;
                pos.x += 2.5;
            }
            rect.left = (rect.left < 128 && rect.top == 640) ? rect.left + 64 : rect.left;
            rect.left = (rect.left > 550 && rect.top != 640) ? 0 : rect.left;
        }
        if (rect.top < 1000 && pos.x >= 505) {
            rect.left = (rect.left < 420 && rect.top < 230) ? rect.left + 64 : rect.left;
            if (rect.left > 420 && rect.top < 230) {
                rect.left = 0;
                rect.top += 64;
            }
            rect.top = (rect.top > 230 && rect.top < 300) ? 832 : rect.top;
            if (rect.left < 360 && rect.top >= 832) {
                rect.left += 64;
            }
            if (rect.left > 360 && rect.top >= 832) {
                rect.left = 0;
                rect.top += 64;
            }
        }
        if (rect.top > 1000)
            rect.top = 0;
        sfSprite_setPosition(sprite, pos);
        sfSprite_setTextureRect(sprite, rect);
        sfRenderWindow_drawSprite(window, background_sprite, NULL);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
    }
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
    sfSprite_destroy(background_sprite);
    sfTexture_destroy(background_texture);
    return EXIT_SUCCESS;
}
