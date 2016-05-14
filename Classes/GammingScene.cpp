#include "GammingScene.h"

Scene* GammingScene::createScene()
{//create a scene with GammingScene layer
	auto scene = Scene::create();
	auto layer = GammingScene::create();
	scene->addChild(layer);
	return scene;
}

bool GammingScene::init()
{
	LayerColor::initWithColor(Color4B::WHITE);

	//create a physics edge
	visibleSize = Director::getInstance()->getVisibleSize();
	setContentSize(visibleSize);
	setPhysicsBody(PhysicsBody::createEdgeBox(visibleSize));

	//create the playerPlane
	playerPlane = PlayerPlane::create();
	addChild(playerPlane);

	//create the enemyPlane
	createEnemyPlanes(20, Vec2(200, 200), Vec2(0, 0), 1);

	//add a keyboard listener
	auto keyBoardListener = EventListenerKeyboard::create();
	keyBoardListener->onKeyPressed = CC_CALLBACK_2(GammingScene::onKeyPressed, this);
	keyBoardListener->onKeyReleased = CC_CALLBACK_2(GammingScene::onKeyReleased, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyBoardListener, this);

	//add a contact listener
	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(GammingScene::onContactBegin, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);

	scheduleUpdate();
	return true;
}

void GammingScene::update(float dt)
{

}

void GammingScene::onKeyPressed(EventKeyboard::KeyCode keyCode, Event*)
{
	playerPlane->onKeyPressed(keyCode);
}

void GammingScene::onKeyReleased(EventKeyboard::KeyCode keyCode, Event*)
{
	playerPlane->onKeyReleased(keyCode);
}

bool GammingScene::onContactBegin(PhysicsContact& contact)
{//get the two contacted body and deal with them
	auto bodyA = contact.getShapeA()->getBody();
	auto bodyB = contact.getShapeB()->getBody();
	switch (bodyA->getContactTestBitmask() ^ bodyB->getContactTestBitmask())
	{
	case _PLAYER_BULLET_MASK ^ _ENEMY_PLANE_MASK:
	{
		Director::getInstance()->replaceScene(GameOverScene::createScene());
	}
	case _PLAYER_PLANE_MASK ^ _ENEMY_PLANE_MASK:
	{
		this->removeChild(bodyA->getNode());
		this->removeChild(bodyB->getNode());
		break;
	}
	case _PLAYER_PLANE_MASK ^_ENEMY_BULLET_MASK:
	{
		Director::getInstance()->replaceScene(GameOverScene::createScene());
	}
	}
	return true;
}

void GammingScene::createEnemyPlanes(int number, Vec2 position, Vec2 velocity, float interval)
{
	for (int i = 0; i < number; ++i)
	{
		auto enemyPlane = EnemyPlane::create();
		addChild(enemyPlane);
		enemyPlane->setPosition((enemyPlane->getContentSize().width + 5)*i*enemyPlane->getScale(), position.y);
		enemyPlane->setVelocity(velocity);
		enemyPlane->scheduleUpdate();
	}

}
