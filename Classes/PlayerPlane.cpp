#include "PlayerPlane.h"

bool PlayerPlane::init()
{
	AirCraft::init();
	auto visibleSize = Director::getInstance()->getVisibleSize();

	setTexture("PlayerPlane.png");
	setScale(0.1f);
	setPosition(visibleSize.width / 2, 100);

	setPhysicsBody(PhysicsBody::createBox(getContentSize()));
	getPhysicsBody()->setContactTestBitmask(_PLAYER_PLANE_MASK);
	getPhysicsBody()->setRotationEnable(false);

	scheduleUpdate();
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
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto bodySize = getContentSize();

	//move
	setPosition(getPosition() + velocity * 5);

	//K attack
	if (onAttack && (++lastAttack>10))
	{
		attack();
		lastAttack = 0;
	}

	//adjust the playerPlane into visible area
	if (getPosition().x < bodySize.width*getScale() / 2)
		setPositionX(bodySize.width * getScale() / 2);
	if (getPosition().x >visibleSize.width-bodySize.width*getScale() / 2)
		setPositionX(visibleSize.width - bodySize.width * getScale() / 2);
	if (getPosition().y < bodySize.height*getScale() / 2)
		setPositionY(bodySize.height * getScale() / 2);
	if (getPosition().y >visibleSize.height - bodySize.height*getScale() / 2)
		setPositionY(visibleSize.height - bodySize.height * getScale() / 2);
}

void PlayerPlane::attack()
{
	auto bullet = Bullet::create();
	bullet->setVelocity(Vec2(0, 2));
	bullet->setPosition(getPosition());
	bullet->getPhysicsBody()->setContactTestBitmask(_PLAYER_BULLET_MASK);
	getParent()->addChild(bullet);

	bullet->scheduleUpdate();
}