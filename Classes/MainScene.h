#pragma once
#include "cocos2d.h"
#include <ui/UIButton.h>

USING_NS_CC;

class MainScene: public LayerColor
{
public:
	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(MainScene);

private:
	Sprite *createHitPlaneLogo();
	ui::Button *createSinglePlayerButton();
	ui::Button *createMultiPlayerButton();

	void selSinglePlayer(cocos2d::Ref *pSender, ui::TouchEventType type);

	Sprite *hitPlaneLogo;
	ui::Button * singlePlayerButton;
	ui::Button * multiPlayerButton;

	Size visibleSize;
};
