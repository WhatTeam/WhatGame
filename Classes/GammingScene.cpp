#include "GammingScene.h"
bool GammingScene::init()
{
	LayerColor::initWithColor(Color4B::WHITE);

	//create a physics edge
	visibleSize = Director::getInstance()->getVisibleSize();
	setContentSize(visibleSize);
	setPhysicsBody(PhysicsBody::createEdgeBox(visibleSize,PHYSICSBODY_MATERIAL_DEFAULT,3));
	getPhysicsBody()->setDynamic(0);
	
	//create the playerPlane
	playerPlane = PlayerPlane::create();
	addChild(playerPlane);
	
	//create the enemyPlane
	createEnemyPlanes(20, Vec2(200, 200), Vec2(0, 0), 1);

	//add a keyboard listener
	setKeyboardEnabled(true);
	auto keyBoardListener = EventListenerKeyboard::create();
	keyBoardListener->onKeyPressed = [this](EventKeyboard::KeyCode keyCode, Event *event) 
	{
		playerPlane->onKeyPressed(keyCode);
		return true;
	};
	keyBoardListener->onKeyReleased = [this](EventKeyboard::KeyCode keyCode, Event *event) 
	{
		playerPlane->onKeyReleased(keyCode);
		return true;
	};
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyBoardListener, this);
	
	//add a contact listener
	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin=[this](PhysicsContact& contact)
	{
		log("contact!%f",rand_0_1());
		auto bodyA = contact.getShapeA()->getBody();
		auto bodyB = contact.getShapeB()->getBody();
		switch (bodyA->getContactTestBitmask() | bodyB->getContactTestBitmask())
		{

		case _PLAYER_BULLET_MASK | _ENEMY_PLANE_MASK:
		case _PLAYER_PLANE_MASK | _ENEMY_PLANE_MASK:
		{
			this->removeChild(bodyA->getNode());
			this->removeChild(bodyB->getNode());
			break;
		}

		}
		return true;
	};
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);

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
		enemyPlane->setPosition((enemyPlane->getContentSize().width+5)*i*enemyPlane->getScale(),position.y);
		enemyPlane->setVelocity(velocity);
		enemyPlane->setDelay(i*interval);
		enemyPlane->scheduleUpdate();
	}

}
