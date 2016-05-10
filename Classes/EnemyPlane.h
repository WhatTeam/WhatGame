#pragma once
#include "AirCraft.h"
#include "Bullet.h"

class EnemyPlane:public AirCraft
{
public:
	CREATE_FUNC(EnemyPlane);

	bool init()override;

	void setDelay(float delay);
private:
	float delay;
	
	void attack();
};