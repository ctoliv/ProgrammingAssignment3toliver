#pragma once
#ifndef ENEMYH
#define ENEMYH

#include <allegro5\allegro.h>

class Enemy
{
public:
	Enemy();
	~Enemy();

	void DrawEnemy();
	void StartEnemy(int WIDTH);
	void UpdateEnemy(int HEIGHT);

	int getX() { return x; }
	int getY() { return y; }
	int getBoundX() { return boundx; }
	int getBoundY() { return boundy; }
	bool getLive() { return live; }
	void setLive(bool l) { live = l; }

private:
	int x;
	int y;
	bool live;
	int speed;
	int boundx;
	int boundy;
	ALLEGRO_BITMAP* image;
};

#endif