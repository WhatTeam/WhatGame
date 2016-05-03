#include "Hero.h"

bool Hero::init()
{
	Sprite::init();

	Size heroSize = Size(44, 52);

	runAction(RepeatForever::create(FlashTool::readJsonSpriteSheet("Hero.json", 0.2f)));

	setContentSize(heroSize);
	setPhysicsBody(PhysicsBody::createBox(heroSize));
	getPhysicsBody()->setContactTestBitmask(1);
	getPhysicsBody()->setRotationEnable(0);

	return true;
}
