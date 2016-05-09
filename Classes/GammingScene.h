#pragma once
#include "cocos2d.h"
#include "PlayerPlane.h"
#include "EnemyPlane.h"
#include "Bullet.h"

USING_NS_CC;

class GammingScene:public LayerColor
{
public:
	CREATE_FUNC(GammingScene);

	bool init()override;

	void update(float dt) override;
private:
	Size visibleSize;
	PlayerPlane *playerPlane;

	Vector<EnemyPlane*> enemyPlanes;

	void createEnemyPlanes(int number, Vec2 position, Vec2 velocity, float interval);
};
