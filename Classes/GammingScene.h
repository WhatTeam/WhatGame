#pragma once
#include "cocos2d.h"
#include "PlayerPlane.h"
#include "Bullet.h"

USING_NS_CC;

class GammingScene:public LayerColor
{
public:
	CREATE_FUNC(GammingScene);

	bool init()override;

private:

	PlayerPlane *playerPlane;

};
