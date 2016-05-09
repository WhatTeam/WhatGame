#include "MainScene.h"

bool MainScene::init()
{
	visibleSize = Director::getInstance()->getVisibleSize();
	LayerColor::initWithColor(Color4B(255, 255, 255, 144));
	
	auto hitPlaneLogo = createHitPlaneLogo();
	addChild(hitPlaneLogo);

	auto singlePlayerButton = createSinglePlayerButton();
	addChild(singlePlayerButton);

	auto multiPlayerButton = createMultiPlayerButton();
	addChild(multiPlayerButton);

	return true;
}

Sprite *MainScene::createHitPlaneLogo()
{
	auto hitPlaneLogo = Sprite::create();
	hitPlaneLogo->setTexture("HitPlane.png");
	setScale((visibleSize.width/2/hitPlaneLogo->getContentSize().width));
	hitPlaneLogo->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 + 200));
	return hitPlaneLogo;
}

ui::Button* MainScene::createSinglePlayerButton()
{
	auto singlePlayerButton = ui::Button::create();
	singlePlayerButton->loadTextureNormal("SinglePlayer.png");
	setScale((visibleSize.width / 2 / singlePlayerButton->getContentSize().width));
	singlePlayerButton->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 + 50));
	return singlePlayerButton;
}

ui::Button* MainScene::createMultiPlayerButton()
{
	auto multiPlayerButton = ui::Button::create();
	multiPlayerButton->loadTextureNormal("MultiPlayer.png");
	setScale((visibleSize.width / 2 / multiPlayerButton->getContentSize().width));
	multiPlayerButton->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2-50));
	return multiPlayerButton;
}
