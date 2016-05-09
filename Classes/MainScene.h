#pragma once
#include "cocos2d.h"
#include <ui/UIButton.h>

USING_NS_CC;

class MainScene:public LayerColor
{
public:
	CREATE_FUNC(MainScene);

	bool init()override;


private:
	Sprite *createHitPlaneLogo();
	ui::Button *createSinglePlayerButton();
	ui::Button *createMultiPlayerButton();


	Size visibleSize;
};
