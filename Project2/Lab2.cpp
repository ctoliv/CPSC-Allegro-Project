#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

// Function prototypes
void draw_background();
void draw_player(int x, int y, int direction);

int main(int argc, char** argv)
{

    ALLEGRO_DISPLAY* display = NULL;

    if (!al_init())
    {
        fprintf(stderr, "failed to initialize allegro!\n");
        return -1;
    }
    
    int width = 800;
    int height = 600;
    int playerX = width / 2;
    int playerY = height / 2;
    int direction = 0;
    display = al_create_display(width, height);

    if (!display)
    {
        fprintf(stderr, "failed to create display!\n");
        return -1;
    }

    al_init_primitives_addon();

    draw_background();
    draw_player(playerX, playerY, direction);

    
    al_flip_display();

    al_rest(5.0);

    al_destroy_display(display);

    return 0;
}

void draw_background()
{
    al_clear_to_color(al_map_rgb(15, 15, 35));
    al_draw_line(0, 500, 800, 500, al_map_rgb(80, 80, 120), 3);
}

void draw_player(int x, int y, int direction)
{
    // Body
    al_draw_filled_circle(x, y, 25, al_map_rgb(0, 180, 255));
    al_draw_circle(x, y, 25, al_map_rgb(255, 255, 255), 2);

    // Pointer facing up
    al_draw_filled_triangle(x, y - 45, x - 12, y - 20, x + 12, y - 20, al_map_rgb(255, 60, 60));

    // Center detail
    al_draw_filled_circle(x, y, 8, al_map_rgb(255, 255, 255));
}