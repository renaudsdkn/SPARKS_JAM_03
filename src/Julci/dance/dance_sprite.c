/*
** EPITECH PROJECT, 2024
** JAM: Flame
** File description:
** move_player_t.c
*/

#include "../../../include/jam.h"

int main(void)
{
    sfTime time;
    sfEvent event;
    sfIntRect rect;
    sfRenderWindow *window;
    sfVideoMode mode = {1920, 1080, 32};
    sfClock *clock = sfClock_create();
    sfSprite *sprite = sfSprite_create();
    sfSprite *background_sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile("../img/male.png", NULL);
    sfTexture *background_texture = sfTexture_createFromFile("../image/Forest.jpg", NULL);

    rect.top = 0;
    rect.left = 0;
    rect.width = 64;
    rect.height = 64;
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
        if (rect.top < 1000) {
            if (rect.left < 420 && rect.top < 230) {
                rect.left += 64;
            }
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
