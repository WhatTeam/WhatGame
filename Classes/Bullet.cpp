#include "Bullet.h"

bool Bullet::init()
{
	AirCraft::init();
	setTexture("Bullet.png");
	setScale(0.5);
	setPosition(Vec2(getVisibleSize().width / 2, getVisibleSize().height / 2+100));
	setVelocity(Vec2(1, 1));
	scheduleUpdate();
	return true;
}
