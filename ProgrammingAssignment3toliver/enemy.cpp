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

	boundx = al_get_bitmap_width(image);
	boundy = al_get_bitmap_height(image);
}

Enemy::~Enemy()
{
	al_destroy_bitmap(image);
}

void Enemy::DrawEnemy()
{
	if (live)
	{
		al_draw_bitmap(image, x, y, 0);
	}
}

void Enemy::StartEnemy(int WIDTH)
{
	if (!live)
	{
		if (rand() % 100 == 0)
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