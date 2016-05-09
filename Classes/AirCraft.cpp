#include "AirCraft.h"
#include "Bullet.h"

bool AirCraft::init()
{
	Sprite::init();
	velocity = Vec2::ZERO;
	visibleSize=Director::getInstance()->getVisibleSize();
	return true;
}

Size AirCraft::getVisibleSize()
{
	return visibleSize;
}

Vec2 AirCraft::getVelocity()
{
	return velocity;
}

void AirCraft::setVelocity(Vec2 velocity)
{
	this->velocity = velocity;
}

float AirCraft::getCurrentLife()
{
	return currentLife;
}

float AirCraft::getTotalLife()
{
	return totalLife;
}

float AirCraft::getDamage()
{
	return damage;
}

void AirCraft::setCurrentLife(float currentLife)
{
	this->currentLife = currentLife;
}

void AirCraft::setTotalLife(float totalLife)
{
	this->totalLife = totalLife;
}

void AirCraft::setDamage(float damage)
{
	this->damage = damage;
}

void AirCraft::update(float dt)
{
	setPosition(getPosition()+velocity*5);
}

