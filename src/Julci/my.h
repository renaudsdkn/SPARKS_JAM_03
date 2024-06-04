/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** This is my header
*/
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include "../../include/jam.h"
#ifndef MY_H
    #define MY_H
    #define SFCSFC sfConvexShape_setFillColor
    #define SPEED my_plane[key.i].speed
    #define SR sfSprite_setRotation
    #define DELY my_plane[k].delta.y
    #define DELX my_plane[k].delta.x
typedef struct my_file {
    sfSprite *sprite;
    sfConvexShape *convex;
    sfSprite *cloude;
}more_sprite_t;

typedef struct text {
    int c_size;
    sfTexture **text_board;
    sfSprite **board;
    sfSoundBuffer* soundbuffer;
    sfSound* sound;
    sfIntRect rect;
    sfCircleShape *shape;
    sfVideoMode mode;
    sfClock *clock;
    sfVector2f scale;
    sfFont* font;
    sfFont* font2;
    sfRenderWindow *window;
    sfEvent event;
    sfVector2i mouse;
    int *x;
    double count;
    sfTexture *texture;
    sfSprite *sprite;
    sfSprite *menu;
    sfTexture *button_text;
    sfSprite *sprite2;
    sfClock *fpers;
    sfText* text;
    more_sprite_t *more;
    sfRectangleShape **menu_r;
    int i;
}print_t;
typedef struct plane {
    sfSprite *sprite;
    sfClock *clock;
    sfVector2f delta;
    sfVector2f dep;
    sfVector2f start;
    sfVector2f end;
    sfRectangleShape *rect;
    sfRectangleShape *csg1;
    sfRectangleShape *csg2;
    sfRectangleShape *csg3;
    sfRectangleShape *csg4;
    sfRectangleShape *cig1;
    sfRectangleShape *cig2;
    sfRectangleShape *cig3;
    sfRectangleShape *cig4;
    sfRectangleShape *csd1;
    sfRectangleShape *csd2;
    sfRectangleShape *csd3;
    sfRectangleShape *csd4;
    sfRectangleShape *cid1;
    sfRectangleShape *cid2;
    sfRectangleShape *cid3;
    sfRectangleShape *cid4;
    sfText *text;
    int in_cir;
    int speed;
    sfTime t;
    int time;
    int ver;
    int vol;
    int rec;
    int out;
}plane_t;
typedef struct corner {
    int nb;
    int l;
    int h;
    sfVector2f pos;
    sfRectangleShape *rect;
}corner_t;
typedef struct coin_rect {
    int did;
    int dsd;
    int dig;
    int dsg;
    float r;
}coin_t;
typedef struct planet {
    char *name;
    int start_x;
    int start_y;
    int end_x;
    int end_y;
    int speed;
    int time;
    int tower_x;
    int tower_y;
    int rad;
}platow_t;
typedef struct linked_list {
    plane_t *plane;
    struct linked_list *next;
}linked_list_t;
typedef struct my_big {
    platow_t *parse;
    sfSprite **sprite;
    sfCircleShape **circle;
    plane_t *my_plane;
    double x;
    double y;
    int l;
    int s;
    int q;
    int menu;
}my_big_t;
typedef struct el {
    int a;
    int t;
    int bash_n;
    int space;
}el_t;
int initialiser(print_t *key, my_big_t *big, int ac, char **av);
sfRectangleShape **menu_rect(sfRectangleShape **m_rect);
sfRectangleShape *m_rect_s(float x, float y, sfRectangleShape *s, float e);
more_sprite_t *cloud_initiation(more_sprite_t *sprite);
more_sprite_t *clock_sprite(more_sprite_t *sprite);
void my_clock(sfRenderWindow *window, print_t clock, plane_t *my_p);
void fonter(sfVector2f pos, print_t clock, char *str, sfRenderWindow *w);
char *int_str(int nb);
plane_t *all_movement(sfVector2f *pos, plane_t *my_plane, int i);
char *int_to_str(int nb);
void print_framerate(print_t key);
void my_game_loop(my_big_t b, sfVector2i m, print_t key, sfVector2f *my_pos);
void draw_something(print_t key, sfVector2i mouse, sfVector2f *my_pos);
void my_game_function(my_big_t big, print_t key);
void rect_color(print_t key, sfVector2i mouse);
int is_mouse_over(sfRectangleShape *shape, sfVector2i pos);
sfRectangleShape **menu_rect(sfRectangleShape **m_rect);
sfRectangleShape *m_rect_s(float x, float y, sfRectangleShape *s, float e);
void fonter2(sfVector2f pos, print_t clock, char *str, sfRenderWindow *w);
int event_handler2(sfEvent e, print_t key, my_big_t t);
more_sprite_t *cloud_initiation(more_sprite_t *sprite);
more_sprite_t *clock_sprite(more_sprite_t *sprite);
sfSprite **initaliser_sprite(sfSprite **sprite, sfTexture **text);
sfTexture **initialiser_text(sfTexture **text);
sfSprite *initialiser_create(sfSprite *sprite, sfTexture *text);
sfVector2f *my_position(sfVector2f *pos);
more_sprite_t *clock_sprite(more_sprite_t *sprite);
plane_t *in_rect2(plane_t *my_p, int i);
plane_t *in_rect4(plane_t *my_p, int i);
plane_t *in_rect3(plane_t *my_p, int i);
plane_t *in_rect6(plane_t *my_p, int i);
plane_t *in_rect7(plane_t *my_p, int i);
plane_t *in_rect5(plane_t *my_p, int i);
sfRectangleShape *rect_creator(int size_x, int size_y, int x, int y);
more_sprite_t *cloud_initiation(more_sprite_t *sprite);
void fonter(sfVector2f pos, print_t clock, char *str, sfRenderWindow *w);
void my_clock(sfRenderWindow *window, print_t clock, plane_t *my_p);
char *int_str(int nb);
int erro_in_str(char *str);
int rect_col_2(sfRectangleShape *rect1, sfRectangleShape *rect2);
plane_t *in_rect(plane_t *my_p, int i, sfVector2f pos);
plane_t *rec(plane_t *re);
int initialiser(print_t *key, my_big_t *big, int ac, char **av);
char *clean_str(char *str);
void texture_choice(my_big_t b, print_t key, plane_t *my_p, int i);
void destroy_resource(print_t key, sfCircleShape **circle, plane_t *my_plane);
int user_infor(int ac, char **av);
int help(int ac);
void my_draw(print_t key, plane_t *my_p, my_big_t b);
void is_fly(plane_t **my_p, float s);
void distance(coin_t *d, sfVector2f pos, sfVector2f pos2);
plane_t *in_circle(plane_t *my_p, sfCircleShape **circle, int i);
void collision_draw(print_t key, my_big_t big);
void setter(my_big_t b, print_t key, double x, double y);
void draw_plane(my_big_t b, int i, print_t key, sfVector2f pos);
plane_t *cut_my_main(plane_t *my_plane, int i);
double abso(double nb);
plane_t *plane_sprite(platow_t *list, plane_t *my_plane);
int plane_num(platow_t *list);
void drawer(print_t key, my_big_t t);
void draw_other_sprite(sfRenderWindow *w, my_big_t b);
sfCircleShape **my_circle(platow_t *list, sfCircleShape **circle);
sfCircleShape *cir(sfVector2f pos, int r, sfCircleShape *s);
sfSprite **tower_sprite(platow_t *list, sfSprite **spriter);
int tow_num(platow_t *list);
int nbrlen(int nb);
platow_t *like_main(int ac, char **av);
int my_putstr(char const *str);
int my_putchar(char c);
int new_line(char *str);
int new_col(char *str);
platow_t *my_tower_coordinate(platow_t *data, char **double_line_map, int i);
platow_t *my_plane_coordinate(platow_t *data, char **double_line_map, int i);
platow_t *parsing(char **map, char **av, int col, int line);
int ligne(char *str);
int column(char *str);
char **stock(char **map, int ligne, int col, char *str);
char **allocation(int ligne, int col, char *str);
int my_strlen(char const *str);
int my_strcmp(char const *s1, char const *s2);
void display_list(platow_t *data, int line);
char *my_strdup(char const *src);
char **stock_object(char **map, int ligne, int col, char *str);
int new_line(char *str);
char **take_map(char **av, int line, int col);
int str_to_int(char *str);
int my_strcmp(char const *s1, char const *s2);
int my_putchar(char c);
int my_putstr(char const *str);
void usage(void);
print_t click_sound(void);
print_t menu_button(void);
int putnbr(int nbr);
char **map_checker(char **map);
#endif
