#include "AirCraft.h"
#include "Bullet.h"

bool AirCraft::init()
{
	Sprite::init();
	velocity = Vec2::ZERO;

	return true;
}


Vec2 AirCraft::getVelocity()
{
	return velocity;
}

void AirCraft::setVelocity(Vec2 velocity)
{
	this->velocity = velocity;
}

void AirCraft::update(float dt)
{
	setPosition(getPosition()+velocity*5);
}

