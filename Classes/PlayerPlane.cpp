#include "PlayerPlane.h"

bool PlayerPlane::init()
{
	AirCraft::init();
	setTexture("PlayerPlane.png");
	setScale(0.1f);
	
	setPhysicsBody(PhysicsBody::createBox(getContentSize()));
	scheduleUpdate();

	setPosition(Vec2(getVisibleSize().width / 2, 30));
	return true;
}
void PlayerPlane::onKeyPressed(EventKeyboard::KeyCode keyCode)
{
	switch (keyCode)
	{
	case EventKeyboard::KeyCode::KEY_W:
		if (velocity.y < 1)
			++velocity.y;
		break;
	case EventKeyboard::KeyCode::KEY_A:
		if (velocity.x > -1)
			--velocity.x;
		break;
	case EventKeyboard::KeyCode::KEY_S:
		if (velocity.y > -1)
			--velocity.y;
		break;
	case EventKeyboard::KeyCode::KEY_D:
		if (velocity.x < 1)
			++velocity.x;
		break;
	case EventKeyboard::KeyCode::KEY_J:
		if (!onAttack) attack();
		break;
	case EventKeyboard::KeyCode::KEY_K:
		onAttack = true;
		break;
	}

}

void PlayerPlane::onKeyReleased(EventKeyboard::KeyCode keyCode)
{
	switch (keyCode)
	{
	case EventKeyboard::KeyCode::KEY_W:
		if (velocity.y >-1)
			--velocity.y;
		break;
	case EventKeyboard::KeyCode::KEY_A:
		if (velocity.x <1)
			++velocity.x;
		break;
	case EventKeyboard::KeyCode::KEY_S:
		if (velocity.y<1)
			++velocity.y;
		break;
	case EventKeyboard::KeyCode::KEY_D:
		if (velocity.x >-1)
			--velocity.x;
		break;
	case EventKeyboard::KeyCode::KEY_K:
		onAttack = false;
	}
}
void PlayerPlane::update(float dt)
{
	setPosition(getPosition() + velocity * 5);
	if (getPosition().x < getContentSize().width/2) setPositionX(getContentSize().width / 2);
	if (getPosition().x > getVisibleSize().width- getContentSize().width / 2) setPositionX(getVisibleSize().width- getContentSize().width / 2);
	if (getPosition().y < getContentSize().height / 2) setPositionY(getContentSize().height / 2);
	if (getPosition().y > getVisibleSize().height- getContentSize().height / 2) setPositionY(getVisibleSize().height- getContentSize().height / 2);

	if (onAttack && (++lastAttack>10))
	{
		attack();
		lastAttack = 0;
	}
}



void PlayerPlane::attack()
{
	auto bullet = Bullet::create();
	getParent()->addChild(bullet);
	bullet->setVelocity(Vec2(0, 2));
	bullet->setPosition(getPosition());
	bullet->scheduleUpdate();
}