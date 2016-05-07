#include "AirCraft.h"
#include "Bullet.h"

AirCraft* AirCraft::create()
{
	AirCraft *pRet = new(std::nothrow) AirCraft(); 
	if (pRet && pRet->init())
	{
		pRet->autorelease(); 
		return pRet;
	}
	else
	{
		delete pRet; 
		pRet = nullptr;
		return nullptr;
	}
}

bool AirCraft::init()
{
	Sprite::init();

	visibleSize=Director::getInstance()->getVisibleSize();
	scheduleUpdate();
	return true;
}

Size AirCraft::getVisibleSize()
{
	return visibleSize;
}

Size AirCraft::getBodySize()
{
	return bodySize;
}

Vec2 AirCraft::getVelocity()
{
	return velocity;
}

void AirCraft::setVelocity(Vec2 velocity)
{
	this->velocity = velocity;
}

float AirCraft::getCurrentLife()
{
	return currentLife;
}

float AirCraft::getTotalLife()
{
	return totalLife;
}

float AirCraft::getDamage()
{
	return damage;
}

void AirCraft::setCurrentLife(float currentLife)
{
	this->currentLife = currentLife;
}

void AirCraft::setTotalLife(float totalLife)
{
	this->totalLife = totalLife;
}

void AirCraft::setDamage(float damage)
{
	this->damage = damage;
}

void AirCraft::update(float dt)
{
	setPosition(getPosition()+velocity*5);
}

void AirCraft::onKeyPressed(EventKeyboard::KeyCode keyCode)
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
		attack();
	}

}

void AirCraft::onKeyReleased(EventKeyboard::KeyCode keyCode)
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
	}
}

void AirCraft::attack()
{
	auto bullet = Bullet::create();
	getParent()->addChild(bullet);
	bullet->setVelocity(Vec2(0, 1));
	bullet->setPosition(getPosition());
	bullet->scheduleUpdate();
}