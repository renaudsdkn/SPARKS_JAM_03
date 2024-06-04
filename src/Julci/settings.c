/*
** EPITECH PROJECT, 2024
** settings
** File description:
** settings
*/

#include "../../include/jam.h"
#define MOUSE event.mouseButton
#include "my.h"
int k;

sfSound *sound()
{
    sfSound *sound;
    sfSoundBuffer *musique;
    sound = sfSound_create();
    musique = sfSoundBuffer_createFromFile("musique/song2.ogg");
    sfSound_setBuffer(sound, musique);
    sfSound_play(sound);
    return sound;
}

void afficher_Notice(sfRenderWindow *window, sfEvent event)
{
    sfSprite *sprite;
    sfTexture *notice;
    
    notice = sfTexture_createFromFile("images/notice.png", NULL);
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, notice, sfTrue);
    sfSprite_setPosition(sprite,  (sfVector2f){710, 400});
    sfRenderWindow_drawSprite(window, sprite, NULL);
}

void draw_text(sfRenderWindow *window, char *string, sfVector2f position, int size)
{
    sfText *text;
    sfFont *font = sfFont_createFromFile("font/Serenata Vantages Regular.ttf");
    
    text = sfText_create();
    sfText_setString(text, string);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, size);
    sfText_setPosition(text, position);
    sfText_setColor(text, (sfColor)sfColor_fromRGB(173, 255, 47)); //rgb(240,128,128)
    //rgb(205,92,92)
    //rgb(220,20,60)
    //rgb(139,0,0)

    sfRenderWindow_drawText(window, text, NULL);
}

int menu_event(sfRenderWindow *window, sfEvent event, int *image_index)
{
    sfVector2i mouse = sfMouse_getPosition((const sfWindow*)window);

    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event.type == sfEvtMouseButtonPressed && MOUSE.x >= 944
        && MOUSE.x <= 1098) {
	if (MOUSE.y >= 550 && MOUSE.y <= 586)
	    printf("couper le son");
	if (MOUSE.y >= 613 && MOUSE.y <= 650)
            printf("allumer le son");
	if (MOUSE.y >= 682 && MOUSE.y <= 718)
	    k = 1;
	if (MOUSE.y >= 752 && MOUSE.y <= 790)
            printf("Appeler la fonction du menu");
        }
	if (event.type == sfEvtMouseButtonPressed && k == 1 && MOUSE.x >= 1155
	&& MOUSE.x <= 1228 && MOUSE.y >= 706 && MOUSE.y <= 747)
	    k = 0;
    return 0;
}

void settings(sfRenderWindow* window)
{
    k = 0;
    int image_index = 0;
    sfVector2f scale = {1.3, 1.3};
    sfVector2f settings = {780, 200};
    sfVector2f pos = {250, 20};
    sfSprite *sprite;
     sfSprite *setting;
    sfTexture *texture;
    sfTexture *setting_h;
    sfTime time;
    float seconds;
    sfClock *clock = sfClock_create();
    sfEvent event;
    print_t *key = malloc(sizeof(print_t));

    key->window = window;
    initialiser(key, NULL, 0, NULL);
    texture = sfTexture_createFromFile("images/image3.png", NULL);
    setting_h = sfTexture_createFromFile("images/settings_jam.png", NULL);
    setting = sfSprite_create();
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setTexture(setting, setting_h, sfTrue);
    sfSprite_setScale(sprite, scale);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            menu_event(window, event, &image_index);
        }
        sfRenderWindow_clear(window, sfBlack);
	sfSprite_setScale(setting, (sfVector2f){1, 1});
	sfSprite_setPosition(setting,  (sfVector2f){800, 400});
        sfRenderWindow_drawSprite(window, sprite, NULL);
	if (k != 1) {
	sfRenderWindow_drawSprite(window, setting, NULL);
	fonter((sfVector2f){955, 480}, key[0], "SETTINGS", window);
	fonter((sfVector2f){968, 552}, key[0], "DISABLE", window);
	fonter((sfVector2f){965, 616}, key[0], "ENABLED", window);
	fonter((sfVector2f){967, 686}, key[0], "NOTICE", window);
	fonter((sfVector2f){981, 755}, key[0], "MENU", window);
	} else 
	    afficher_Notice(window, event);
        sfRenderWindow_display(window);
    }
}

/*int main(void)
{
    sfRenderWindow* window;
    sfVideoMode mode = {1920, 1080};
    window = sfRenderWindow_create(mode, "settings", sfResize | sfClose, NULL);
    settings(window);
    }*/