#include "GameController.h"

bool GameController::init(Layer* layer, float positionY)
{
	_layer = layer;
	_positionY = positionY;

	Size visibleSize = Director::getInstance()->getVisibleSize();

	//add edge
	edge = Edge::create();
	layer->addChild(edge);
	edge->setPositionY(positionY);

	//add ground
	auto ground = Sprite::create();
	ground->setTextureRect(Rect(0, 0, visibleSize.width, 3));
	ground->setColor(Color3B(0, 0, 0));
	layer->addChild(ground);
	ground->setPosition(visibleSize.width / 2, positionY - 1.5);

	//add hero
	hero = Hero::create();
	layer->addChild(hero);
	hero->setPosition(50, positionY + hero->getContentSize().height / 2);

	//resetFrames();
	return true;
}

GameController* GameController::creat(Layer* layer, float positionY)
{
	auto _ins = new GameController();
	_ins->init(layer, positionY);
	_ins->autorelease();
	return _ins;
}

bool GameController::hitTestPoint(Vec2 point)
{
	return edge->getBoundingBox().containsPoint(point);
}

void GameController::onUpdate(float dt)
{
	++currentFrameIndex;

	if (currentFrameIndex > nextFrameCount)
	{
		resetFrames();
		addBlock();
	}
}
void GameController::onUserTouch()
{
	hero->getPhysicsBody()->setVelocity(Vec2(0,200));
}

void GameController::resetFrames()
{
	currentFrameIndex = 0;
	
	nextFrameCount = rand() % 120 + 100;
}

void GameController::addBlock()
{
	auto block = Block::create();
	block->setPositionY(block->getContentSize().height / 2 + _positionY);
	_layer->addChild(block);

}
