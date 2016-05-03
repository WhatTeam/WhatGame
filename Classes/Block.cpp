#include "Block.h"

bool Block::init()
{
	Sprite::init();

	Size blockSize = Size(rand() % 15 + 10, rand() % 20 + 15);
	auto visibleSize = Director::getInstance()->getVisibleSize();

	setTextureRect(Rect(0, 0, blockSize.width, blockSize.height));
	setContentSize(blockSize);
	setPhysicsBody(PhysicsBody::createBox(blockSize));
	getPhysicsBody()->setContactTestBitmask(1);
	setColor(Color3B::BLACK);
	getPhysicsBody()->setDynamic(0);

	setPositionX(visibleSize.width);
	setPositionY(blockSize.height / 2);
	scheduleUpdate();


	return true;
}

void Block::update(float dt)
{
	setPositionX(getPositionX() - 4);

	if (getPositionX() < 0)
	{
		unscheduleUpdate();
		removeFromParent();
	}
}
