#pragma once
#include "cocos2d.h"
//
#define _PLAYER_PLANE_MASK	0b10000000
#define _PLAYER_BULLET_MASK	0b01000000
#define _ENEMY_PLANE_MASK	0b00100000
#define _ENEMY_BULLET_MASK	0b00010000

USING_NS_CC;

class AirCraft:public Sprite
{
public:
	CREATE_FUNC(AirCraft);

	bool init() override;

	Vec2 getVelocity();
	void setVelocity(Vec2 velocity);
	void update(float dt) override;

	Vec2 velocity;
private:
};
