/*
** EPITECH PROJECT, 2024
** Window
** File description:
** Day13
*/
#include "../../include/jam.h"

move_player_t event_handler(sfEvent e, sfRenderWindow *w, sfVector2f sc, move_player_t p, rect_t *rectangle)
{
    sfVector2i mouse = sfMouse_getPosition((const sfWindow *)w);

    while (sfRenderWindow_pollEvent(w, &e)) {
        if (e.type == sfEvtClosed)
            sfRenderWindow_close(w);
        p = cut_player_move(p, e, rectangle);
    }
    return p;
}

affiche my_texture(void)
{
    affiche key;
    sfVector2f scale = {1, 0.55};

    key.texture = sfTexture_createFromFile("./src/Tobi/lab.jpg", NULL);
    key.sprite = sfSprite_create();
    sfSprite_setTexture(key.sprite, key.texture, sfTrue);
    sfSprite_setScale(key.sprite, scale);
    return key;
}

void draw_sprite(affiche key)
{
    sfRenderWindow_drawSprite(key.window, key.sprite, NULL);
}

int launch_labyrinth(sfRenderWindow *window)
{
    affiche key = my_texture();
    sfVector2f scale = {0.4, 0.35};
    sfVector2f life_pos = {1700, 10};
    sfVideoMode m = {1920, 1080, 32};
    rect_t *rectangle = my_rectangle(rectangle);
    move_player_t p = init_move_player_t_struct(p);
    int i = 0;

    key.window = window;
    sfRenderWindow_setFramerateLimit(key.window, 700);
    while (sfRenderWindow_isOpen(key.window)){
        p = event_handler(key.event, key.window, scale, p, rectangle);
        sfRenderWindow_clear(key.window, sfBlack);
        draw_sprite(key);
        i = 0;
        while (rectangle[i].rect != NULL){
            sfRenderWindow_drawRectangleShape(key.window, rectangle[i].rect, NULL);
            i++;
        }
        set_and_draw_player(p, key.window);
        sfRenderWindow_display(key.window);
    }
    for (i = 0; rectangle[i].rect != NULL; i++)
        sfRectangleShape_destroy(rectangle[i].rect);
}