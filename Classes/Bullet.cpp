#include "Bullet.h"

bool Bullet::init()
{
	AirCraft::init();
	setTexture("Bullet.png");
	setScale(0.5);
	setPosition(Vec2(0, 0));
	scheduleUpdate();
	return true;
}
