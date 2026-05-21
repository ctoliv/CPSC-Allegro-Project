#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

// Function prototypes
void draw_background();
void draw_player(int x, int y, int direction);

int main(int argc, char** argv)
{

    ALLEGRO_DISPLAY* display = NULL;
    ALLEGRO_EVENT_QUEUE* event_queue = NULL;
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
    bool done = false;
    display = al_create_display(width, height);

    if (!display)
    {
        fprintf(stderr, "failed to create display!\n");
        return -1;
    }

    if (!al_install_keyboard())
    {
        fprintf(stderr, "failed to install keyboard!\n");
        return -1;
    }

    event_queue = al_create_event_queue();

    if (!event_queue)
    {
        fprintf(stderr, "failed to create event queue!\n");
        return -1;
    }

    event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_init_primitives_addon();

    draw_background();
    draw_player(playerX, playerY, direction);


    al_flip_display();
    while (!done)
    {
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            done = true;
        }
        else if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
        {
            if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
            {
                done = true;
            }
        }
    }


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