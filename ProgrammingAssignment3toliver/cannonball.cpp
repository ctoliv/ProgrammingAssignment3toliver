#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <cmath>
#include "cannonball.h"

Cannonball::Cannonball()
{
	x = 0;
	y = 0;
	dx = 0;
	dy = 0;
	speed = 8;
	live = false;

	image = al_load_bitmap("cannonball.png");

	if (!image)
	{
		exit(1);
	}
}

Cannonball::~Cannonball()
{
	al_destroy_bitmap(image);
}

void Cannonball::DrawCannonball()
{
	if (live)
	{
		al_draw_scaled_bitmap(
			image,
			0, 0,
			al_get_bitmap_width(image),
			al_get_bitmap_height(image),
			x, y,
			45, 45,
			0
		);
	}
}

void Cannonball::FireCannonball(float startX, float startY, float angle)
{
	if (!live)
	{
		x = startX;
		y = startY;

		// The cannonball moves based on the angle of the cannon.
		dx = speed * sin(angle);
		dy = -speed * cos(angle);

		live = true;
	}
}

void Cannonball::UpdateCannonball(int WIDTH, int HEIGHT)
{
	if (live)
	{
		x += dx;
		y += dy;

		// Remove the cannonball when it leaves the screen.
		if (x < 0 || x > WIDTH || y < 0 || y > HEIGHT)
		{
			live = false;
		}
	}
}
void Cannonball::CollideCannonball(Enemy enemies[], int cSize)
{
	if (live)
	{
		for (int i = 0; i < cSize; i++)
		{
			if (enemies[i].getLive())
			{
				if (x > enemies[i].getX() &&
					x < enemies[i].getX() + enemies[i].getBoundX() &&
					y > enemies[i].getY() &&
					y < enemies[i].getY() + enemies[i].getBoundY())
				{
					live = false;
					enemies[i].setLive(false);
				}
			}
		}
	}
}