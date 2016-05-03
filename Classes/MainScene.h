#pragma once
#include "cocos2d.h"

USING_NS_CC;

class MainScene :public Scene
{
public:
	bool init();
	static Scene *createScene();
	CREATE_FUNC(MainScene);
};
