#pragma once
#include "cocos2d.h"
#include "ui/UIButton.h"
#include "GammingScene.h"

USING_NS_CC;

class GameOverScene:public LayerColor
{
public:
	static Scene* createScene();

	bool init() override;

	CREATE_FUNC(GameOverScene);
private:
	Sprite *createGamerOverLogo();
	ui::Button *createTryAgainButton();
	ui::Button *createExitButton();

	void selTryAgain(cocos2d::Ref *pSender, ui::TouchEventType type);
	void selExit(cocos2d::Ref *pSender, ui::TouchEventType type);

	Sprite *gamerOverLogo;
	ui::Button * tryAgainButton;
	ui::Button * exitButton;

	Size visibleSize;
};
