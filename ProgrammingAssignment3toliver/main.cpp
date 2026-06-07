#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_primitives.h>

int main(void)
{
	const int WIDTH = 800;
	const int HEIGHT = 600;
	const int FPS = 60;

	enum KEYS { LEFT, RIGHT };
	bool keys[2] = { false, false };

	bool done = false;
	bool redraw = true;

	ALLEGRO_DISPLAY* display = NULL;
	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	ALLEGRO_TIMER* timer = NULL;

	ALLEGRO_BITMAP* background = NULL;
	ALLEGRO_BITMAP* cannon = NULL;
	ALLEGRO_BITMAP* enemy = NULL;
	ALLEGRO_BITMAP* cannonball = NULL;
	ALLEGRO_BITMAP* base = NULL;

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
	al_install_keyboard();

	event_queue = al_create_event_queue();
	timer = al_create_timer(1.0 / FPS);

	if (!event_queue || !timer)
	{
		al_destroy_display(display);
		return -1;
	}

	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	// Load all images needed for the game.
	background = al_load_bitmap("background.png");
	cannon = al_load_bitmap("cannon.png");
	enemy = al_load_bitmap("enemy.png");
	cannonball = al_load_bitmap("cannonball.png");
	base = al_load_bitmap("base.png");

	// Error checking for image files.
	if (!background || !cannon || !enemy || !cannonball || !base)
	{
		al_destroy_display(display);
		al_destroy_event_queue(event_queue);
		al_destroy_timer(timer);
		return -1;
	}

	// Cannon position near the bottom center of the screen.
	float cannonX = WIDTH / 2;
	float cannonY = HEIGHT - al_get_bitmap_height(base) - 20;

	// Cannon aiming angle. Negative aims left, positive aims right.
	float cannonAngle = 0;

	al_start_timer(timer);

	while (!done)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER)
		{
			redraw = true;

			// Rotate cannon left and right with arrow keys.
			if (keys[LEFT])
			{
				cannonAngle -= 0.03;
			}

			if (keys[RIGHT])
			{
				cannonAngle += 0.03;
			}

			// Limit cannon angle so it only aims in an arc.
			if (cannonAngle < -1.0)
			{
				cannonAngle = -1.0;
			}

			if (cannonAngle > 1.0)
			{
				cannonAngle = 1.0;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
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

			case ALLEGRO_KEY_LEFT:
				keys[LEFT] = true;
				break;

			case ALLEGRO_KEY_RIGHT:
				keys[RIGHT] = true;
				break;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_UP)
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_LEFT:
				keys[LEFT] = false;
				break;

			case ALLEGRO_KEY_RIGHT:
				keys[RIGHT] = false;
				break;
			}
		}

		if (redraw && al_is_event_queue_empty(event_queue))
		{
			redraw = false;

			al_clear_to_color(al_map_rgb(0, 0, 0));

			// Draw background.
			al_draw_bitmap(background, 0, 0, 0);

			// Draw base near the bottom.
			al_draw_bitmap(base,
				WIDTH / 2 - al_get_bitmap_width(base) / 2,
				HEIGHT - al_get_bitmap_height(base),0);

			// Draw one sample enemy near the top.
			al_draw_bitmap(enemy,
				WIDTH / 2 - al_get_bitmap_width(enemy) / 2, 50, 0);

			// Draw one sample cannonball near the cannon.
			al_draw_bitmap(cannonball,
				WIDTH / 2,
				HEIGHT - 150, 0);

			// Draw the cannon rotated around its center.
			al_draw_scaled_rotated_bitmap(
				cannon,
				al_get_bitmap_width(cannon) / 2,
				al_get_bitmap_height(cannon) / 2,
				cannonX,
				cannonY,
				0.35,
				0.35,
				cannonAngle,
				0);

			al_flip_display();
		}
	}

	al_destroy_bitmap(background);
	al_destroy_bitmap(cannon);
	al_destroy_bitmap(enemy);
	al_destroy_bitmap(cannonball);
	al_destroy_bitmap(base);

	al_destroy_timer(timer);
	al_destroy_event_queue(event_queue);
	al_destroy_display(display);

	return 0;
}