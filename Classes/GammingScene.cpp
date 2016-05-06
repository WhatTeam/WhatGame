#include "GammingScene.h"

bool GammingScene::init()
{
	LayerColor::initWithColor(Color4B::WHITE);

	auto playerPlane = PlayerPlane::create();
	addChild(playerPlane);

	playerPlane->attack();
	
	return true;
}