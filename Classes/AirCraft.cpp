﻿#include "AirCraft.h"

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
	setPosition(getPosition().x+velocity.x, getPosition().y + velocity.y);
}
