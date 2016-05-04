#include "GammingScene.h"

bool GammingScene::init()
{
	LayerColor::initWithColor(Color4B::WHITE);

	auto playerPlane = PlayerPlane::create();
	addChild(playerPlane);


	auto bullet = Bullet::create();
	addChild(bullet);


	return true;
}
