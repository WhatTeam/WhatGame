#include "EnemyPlane.h"

bool EnemyPlane::init()
{
	AirCraft::init();
	setTexture("EnemyPlane.png");
	setScale(0.1f);

	setPhysicsBody(PhysicsBody::createBox(getContentSize()));
	getPhysicsBody()->setContactTestBitmask(_ENEMY_PLANE_MASK);
	getPhysicsBody()->setRotationEnable(false);

	scheduleUpdate();
	return true;
}

void EnemyPlane::setDelay(float delay)
{
	this->delay = delay;
}

void EnemyPlane::attack()
{
	auto bullet = Bullet::create();
	bullet->setVelocity(Vec2(0, -2));
	bullet->setPosition(getPosition());
	bullet->getPhysicsBody()->setContactTestBitmask(_ENEMY_BULLET_MASK);
	getParent()->addChild(bullet);

	bullet->scheduleUpdate();
}
