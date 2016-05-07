#pragma once
#include "cocos2d.h"

USING_NS_CC;

class AirCraft:public Sprite
{
public:
	static AirCraft* create();
	static AirCraft* create(Vec2 _position,Vec2 _velocity,float _currentLife,float _totalLife,float _damage);

	bool init() override;

	Size getVisibleSize();
	Size getBodySize();
	Vec2 getVelocity();
	void setVelocity(Vec2 velocity);

	float getCurrentLife();
	float getTotalLife();
	float getDamage();
	void setCurrentLife(float currentLife);
	void setTotalLife(float totalLife);
	void setDamage(float damage);

	void update(float dt) override;
	void onKeyPressed(EventKeyboard::KeyCode keyCode);
	void onKeyReleased(EventKeyboard::KeyCode keyCode);
private:
	void attack();

	Size visibleSize;
	Size bodySize;
	Vec2 velocity;

	float currentLife;
	float totalLife;
	float damage;
};

