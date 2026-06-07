#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_primitives.h>

int main(void)
{
	const int WIDTH = 800;
	const int HEIGHT = 600;

	bool done = false;

	ALLEGRO_DISPLAY* display = NULL;
	ALLEGRO_EVENT_QUEUE* event_queue = NULL;

	ALLEGRO_BITMAP* background = NULL;
	ALLEGRO_BITMAP* cannon = NULL;
	ALLEGRO_BITMAP* enemy = NULL;
	ALLEGRO_BITMAP* snowball = NULL;
	ALLEGRO_BITMAP* iceberg = NULL;

	if (!al_init())
	{
		return -1;
	}

	display = al_create_display(WIDTH, HEIGHT);

	if (!display)
	{
		return -1;
	}

	al_init_image_addon();
	al_init_primitives_addon();

	event_queue = al_create_event_queue();

	if (!event_queue)
	{
		al_destroy_display(display);
		return -1;
	}

	al_register_event_source(event_queue, al_get_display_event_source(display));

	// Load all images needed for the game.
	background = al_load_bitmap("background.png");
	cannon = al_load_bitmap("cannon.png");
	enemy = al_load_bitmap("enemy.png");
	snowball = al_load_bitmap("cannonball.png");
	iceberg = al_load_bitmap("base.png");

	// Error checking for image files.
	if (!background || !cannon || !enemy || !snowball || !iceberg)
	{
		al_destroy_display(display);
		al_destroy_event_queue(event_queue);
		return -1;
	}

	while (!done)
	{
		ALLEGRO_EVENT ev;

		if (al_get_next_event(event_queue, &ev))
		{
			if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
			{
				done = true;
			}
		}

		// Draw the starting screen.
		al_draw_bitmap(background, 0, 0, 0);

		// Draw the iceberg near the bottom.
		al_draw_bitmap(iceberg, WIDTH / 2 - al_get_bitmap_width(iceberg) / 2,
			HEIGHT - al_get_bitmap_height(iceberg), 0);

		// Draw the cannon near the bottom center.
		al_draw_bitmap(cannon, WIDTH / 2 - al_get_bitmap_width(cannon) / 2,
			HEIGHT - al_get_bitmap_height(iceberg) - al_get_bitmap_height(cannon), 0);

		// Draw one sample enemy near the top.
		al_draw_bitmap(enemy, WIDTH / 2 - al_get_bitmap_width(enemy) / 2, 50, 0);

		// Draw one sample snowball near the cannon.
		al_draw_bitmap(snowball, WIDTH / 2, HEIGHT - 150, 0);

		al_flip_display();
	}

	al_destroy_bitmap(background);
	al_destroy_bitmap(cannon);
	al_destroy_bitmap(enemy);
	al_destroy_bitmap(snowball);
	al_destroy_bitmap(iceberg);

	al_destroy_event_queue(event_queue);
	al_destroy_display(display);

	return 0;
}