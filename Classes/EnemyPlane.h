#pragma once
#include "AirCraft.h"
#include "Bullet.h"

class EnemyPlane:public AirCraft
{
public:
	CREATE_FUNC(EnemyPlane);

	bool init()override;

	void setDelay(float delay);

	void update(float dt) override;
private:
	float delay;
};
