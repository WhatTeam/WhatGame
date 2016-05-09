#include "EnemyPlane.h"

bool EnemyPlane::init()
{
	AirCraft::init();
	setTexture("EnemyPlane.png");
	setScale(0.1f);

	setPhysicsBody(PhysicsBody::createBox(getContentSize()));
	scheduleUpdate();
	return true;
}

void EnemyPlane::setDelay(float delay)
{
	this->delay = delay;
}

void EnemyPlane::update(float dt)
{

}
