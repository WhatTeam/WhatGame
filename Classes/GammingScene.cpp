#include "GammingScene.h"

bool GammingScene::init()
{
	LayerColor::initWithColor(Color4B::WHITE);


	//create a edge
	visibleSize = Director::getInstance()->getVisibleSize();
	setContentSize(visibleSize);
	setPhysicsBody(PhysicsBody::createEdgeBox(visibleSize));
	getPhysicsBody()->setDynamic(0);
	playerPlane = PlayerPlane::create();
	addChild(playerPlane);
	playerPlane->scheduleUpdate();

	setKeyboardEnabled(true);
	auto keyBoardListener = EventListenerKeyboard::create();
	keyBoardListener->onKeyPressed = [this](EventKeyboard::KeyCode keyCode, Event *event) {
		playerPlane->onKeyPressed(keyCode);
		return true;
	};
	keyBoardListener->onKeyReleased = [this](EventKeyboard::KeyCode keyCode, Event *event) {
		playerPlane->onKeyReleased(keyCode);
		return true;
	};
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyBoardListener, this);
	
	createEnemyPlanes(5,Vec2(200,200),Vec2(1,1),1);

	return true;
}

void GammingScene::update(float dt)
{

}

void GammingScene::createEnemyPlanes(int number,Vec2 position,Vec2 velocity,float interval)
{
	for (int i = 0; i < number;++i)
	{
		auto enemyPlane = EnemyPlane::create();
		addChild(enemyPlane);
		enemyPlane->setPosition(position);
		enemyPlane->setVelocity(velocity);
		enemyPlane->setDelay(i*interval);
		enemyPlane->scheduleUpdate();
	}

}
