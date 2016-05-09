#pragma once
#include "cocos2d.h"

USING_NS_CC;

class AirCraft:public Sprite
{
public:
	CREATE_FUNC(AirCraft);

	bool init() override;

	Size getVisibleSize();
	Vec2 getVelocity();
	void setVelocity(Vec2 velocity);

	float getCurrentLife();
	float getTotalLife();
	float getDamage();
	void setCurrentLife(float currentLife);
	void setTotalLife(float totalLife);
	void setDamage(float damage);

	void update(float dt) override;

	Vec2 velocity;

private:

	Size visibleSize;

	float currentLife;
	float totalLife;
	float damage;
};

