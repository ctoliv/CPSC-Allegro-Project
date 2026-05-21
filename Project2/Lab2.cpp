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
    int moveAmount = 25;
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
            switch (ev.keyboard.keycode)
            {
            case ALLEGRO_KEY_ESCAPE:
                done = true;
                break;

            case ALLEGRO_KEY_UP:
                playerY -= moveAmount;
                direction = 0;
                break;

            case ALLEGRO_KEY_DOWN:
                playerY += moveAmount;
                direction = 1;
                break;

            case ALLEGRO_KEY_RIGHT:
                playerX += moveAmount;
                direction = 2;
                break;

            case ALLEGRO_KEY_LEFT:
                playerX -= moveAmount;
                direction = 3;
                break;
            case ALLEGRO_KEY_U:
                playerX -= moveAmount;
                playerY -= moveAmount;
                direction = 4;
                break;

            case ALLEGRO_KEY_D:
                playerX += moveAmount;
                playerY += moveAmount;
                direction = 5;
                break;

            case ALLEGRO_KEY_R:
                playerX += moveAmount;
                playerY -= moveAmount;
                direction = 6;
                break;

            case ALLEGRO_KEY_L:
                playerX -= moveAmount;
                playerY += moveAmount;
                direction = 7;
                break;

            }
            draw_background();
            draw_player(playerX, playerY, direction);


            al_flip_display();
        }
    }

    al_destroy_event_queue(event_queue);
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

    // Pointer changing based on direction
    switch (direction)
    {
    case 0://Up
        al_draw_filled_triangle(x, y - 45, x - 12, y - 20, x + 12, y - 20, al_map_rgb(255, 60, 60));
        break;
    case 1: // Down
        al_draw_filled_triangle(x, y + 45, x - 12, y + 20, x + 12, y + 20, al_map_rgb(255, 60, 60));
        break;

    case 2: // Right
        al_draw_filled_triangle(x + 45, y, x + 20, y - 12, x + 20, y + 12, al_map_rgb(255, 60, 60));
        break;

    case 3: // Left
        al_draw_filled_triangle(x - 45, y, x - 20, y - 12, x - 20, y + 12, al_map_rgb(255, 60, 60));
        break;

    case 4: // Upper-left
        al_draw_filled_triangle(x - 35, y - 35, x - 10, y - 25, x - 25, y - 10, al_map_rgb(255, 60, 60));
        break;

    case 5: // Lower-right
        al_draw_filled_triangle(x + 35, y + 35, x + 10, y + 25, x + 25, y + 10, al_map_rgb(255, 60, 60));
        break;

    case 6: // Upper-right
        al_draw_filled_triangle(x + 35, y - 35, x + 10, y - 25, x + 25, y - 10, al_map_rgb(255, 60, 60));
        break;

    case 7: // Lower-left
        al_draw_filled_triangle(x - 35, y + 35, x - 10, y + 25, x - 25, y + 10, al_map_rgb(255, 60, 60));
        break;
    }
    // Center detail
    al_draw_filled_circle(x, y, 8, al_map_rgb(255, 255, 255));
}