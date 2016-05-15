#include "EnemyPlane.h"

Size EnemyPlane::visibleSize = Director::getInstance()->getVisibleSize();
Rect EnemyPlane::screenArea = CCRectMake(0, 0, visibleSize.width, visibleSize.height);

bool EnemyPlane::init()
{
	AirCraft::init();
	setTexture("EnemyPlane.png");
	setScale(0.1f);
	lastAttack = 10;

	setPhysicsBody(PhysicsBody::createBox(getContentSize()));
	getPhysicsBody()->setContactTestBitmask(_ENEMY_PLANE_MASK);
	getPhysicsBody()->setRotationEnable(false);

	scheduleUpdate();
	return true;
}

void EnemyPlane::update(float dt)
{
	Vec2 position = getPosition();
	setPosition(position + velocity);
	if (rand_0_1() > 0.9&&++lastAttack>10)
	{
		attack();
		lastAttack = 0;
	}

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
