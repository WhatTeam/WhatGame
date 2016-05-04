#include "PlayerPlane.h"

bool PlayerPlane::init()
{
	AirCraft::init();
	setTexture("PlayerPlane.png");
	setScale(0.1f);
	setPosition(Vec2(getVisibleSize().width / 2, 30));
	return true;
}

void PlayerPlane::attack()
{
	auto bullet = Bullet::create();
	addChild(bullet);
}
