#include "Bullet.h"

bool Bullet::init()
{
	AirCraft::init();
	setTexture("Bullet.png");
	
	setPhysicsBody(PhysicsBody::createBox(getContentSize()));

	scheduleUpdate();
	return true;
}