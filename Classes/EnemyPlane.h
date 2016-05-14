#pragma once
#include "AirCraft.h"
#include "Bullet.h"

class EnemyPlane:public AirCraft
{
public:
	CREATE_FUNC(EnemyPlane);

	bool init()override;

	void update(float dt) override;
	
	static void createEnemyPlanes();

private:
	static Size visibleSize;
	static Rect screenArea;

	void attack();
};