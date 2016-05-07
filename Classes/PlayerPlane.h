#pragma once
#include "AirCraft.h"
#include "Bullet.h"

class PlayerPlane:public AirCraft
{
public:
	CREATE_FUNC(PlayerPlane);

	bool init()override;

private:

};
