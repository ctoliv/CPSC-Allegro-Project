#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

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
    display = al_create_display(800, 600);

    if (!display)
    {
        fprintf(stderr, "failed to create display!\n");
        return -1;
    }
    //needed for drawing primitatives like rectangles, cricles, etc.
    al_init_primitives_addon();

    al_clear_to_color(al_map_rgb(0, 0, 0));

    //Moon
    al_draw_filled_circle(680, 90, 45,al_map_rgb(240,240,210));
    al_draw_filled_circle(700, 80, 40, al_map_rgb(0, 0, 0));

    //House body
    al_draw_filled_rectangle(250, 300, 550, 500, al_map_rgb(160, 90, 50));
    //House Roof
    al_draw_filled_triangle(250, 300, 550, 300, 400, 190, al_map_rgb(120, 30, 30));
    //Door
    al_draw_filled_rectangle(370, 390, 430, 500, al_map_rgb(90, 50, 25));
    al_draw_filled_circle(420, 445, 5, al_map_rgb(230, 200, 60));
    //Left widow
    al_draw_filled_rectangle(285, 340, 345, 400, al_map_rgb(90, 50, 25));
    al_draw_rectangle(285, 340, 345, 400, al_map_rgb(0, 0, 0), 3);
    al_draw_line(315, 340, 315, 400, al_map_rgb(0, 0, 0), 2);
    al_draw_line(285, 370, 345, 370, al_map_rgb(0, 0, 0), 2);

    //Rigt window
    al_draw_filled_rectangle(455, 340, 515, 400, al_map_rgb(90, 50, 25));
    al_draw_rectangle(455, 340, 515, 400, al_map_rgb(0, 0, 0), 3);
    al_draw_line(485, 340, 485, 400, al_map_rgb(0, 0, 0), 2);
    al_draw_line(455, 370, 515, 370, al_map_rgb(0, 0, 0), 2);

    //Tree trunk
    al_draw_filled_rectangle(110, 350, 150, 500, al_map_rgb(100, 55, 25));

    //Tree leaves
    al_draw_filled_circle(130, 290, 50, al_map_rgb(25, 100, 30));
    al_draw_filled_circle(90, 350, 50, al_map_rgb(30, 120, 40));
    al_draw_filled_circle(170, 350, 50, al_map_rgb(30, 130, 40));



    al_flip_display();

    al_rest(20.0);

    al_destroy_display(display);

    return 0;
}