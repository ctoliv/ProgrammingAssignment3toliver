#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <cstdlib>
#include "enemy.h"

Enemy::Enemy()
{
	x = 0;
	y = 0;
	live = false;
	speed = 2;

	image = al_load_bitmap("enemy.png");

	if (!image)
	{
		exit(1);
	}

	al_convert_mask_to_alpha(image, al_map_rgb(255, 255, 255));

	boundx = 130;
	boundy = 130;
}

Enemy::~Enemy()
{
	al_destroy_bitmap(image);
}
// Draw the Enemy smaller than the original image.
void Enemy::DrawEnemy()
{
	if (live)
	{
		al_draw_scaled_bitmap(
			image,
			0, 0,
			al_get_bitmap_width(image),
			al_get_bitmap_height(image),
			x, y,
			130, 130,
			0
		);
	}
}

void Enemy::StartEnemy(int WIDTH)
{
	if (!live)
	{
		if (rand() % 300 == 0)
		{
			live = true;
			x = rand() % (WIDTH - boundx);
			y = 0;
		}
	}
}

void Enemy::UpdateEnemy(int HEIGHT)
{
	if (live)
	{
		y += speed;

		if (y > HEIGHT)
		{
			live = false;
		}
	}
}
bool Enemy::CollideBase(int baseY)
{
	if (live)
	{
		if (y + boundy >= baseY)
		{
			live = false;
			return true;
		}
	}

	return false;
}