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
	visibleSize = Director::getInstance()->getVisibleSize();
	score = 0;
	scoreLabel = LabelTTF::create();
	scoreLabel->setString("0");
	scoreLabel->setFontSize(36);
	scoreLabel->setColor(Color3B::BLACK);
	scoreLabel->setPosition(30, visibleSize.height - 30);
	addChild(scoreLabel);

	//create the playerPlane
	playerPlane = PlayerPlane::create();
	addChild(playerPlane);
	schedule(schedule_selector(GammingScene::addEnemyPlane), 0.5, -1, 1);
	
	//add a keyboard listener
	auto keyBoardListener = EventListenerKeyboard::create();
	keyBoardListener->onKeyPressed = CC_CALLBACK_2(GammingScene::onKeyPressed, this);
	keyBoardListener->onKeyReleased = CC_CALLBACK_2(GammingScene::onKeyReleased, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyBoardListener, this);

	//add a contact listener
	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(GammingScene::onContactBegin, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);

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
	switch (bodyA->getContactTestBitmask() | bodyB->getContactTestBitmask())
	{
	case _PLAYER_BULLET_MASK | _ENEMY_PLANE_MASK:
	{
		/*Director::getInstance()->replaceScene(GameOverScene::createScene());*/
	}
	case _PLAYER_PLANE_MASK | _ENEMY_PLANE_MASK:
	{
		this->removeChild(bodyA->getNode());
		this->removeChild(bodyB->getNode());
		scoreLabel->setString(std::to_string(++score));
		break;
	}
	case _PLAYER_PLANE_MASK | _ENEMY_BULLET_MASK:
	{
		/*Director::getInstance()->replaceScene(GameOverScene::createScene());*/
	}
	}
	return true;
}

void GammingScene::addEnemyPlane(float dt)
{
	log("addPlane");
	auto enemyPlane= EnemyPlane::create();
	enemyPlane->setPosition(visibleSize.width *rand_0_1(), visibleSize.height);
	enemyPlane->setVelocity(Vec2(0, -2));
	enemyPlane->scheduleUpdate();
	addChild(enemyPlane);
}
