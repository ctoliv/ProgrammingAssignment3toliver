#pragma once
#ifndef CANNONBALLH
#define CANNONBALLH

#include <allegro5\allegro.h>

class Cannonball
{
public:
	Cannonball();
	~Cannonball();

	void DrawCannonball();
	void FireCannonball(float startX, float startY, float angle);
	void UpdateCannonball(int WIDTH, int HEIGHT);

	bool getLive() { return live; }

private:
	float x;
	float y;
	float dx;
	float dy;
	bool live;
	float speed;
	ALLEGRO_BITMAP* image;
};

#endif