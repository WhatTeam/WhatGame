#include "GameOverScene.h"

Scene* GameOverScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = GameOverScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

bool GameOverScene::init()
{
	LayerColor::initWithColor(Color4B::WHITE);
	visibleSize = Director::getInstance()->getVisibleSize();
	
	//add the logo and buttons
	gamerOverLogo = createGamerOverLogo();
	addChild(gamerOverLogo);
	tryAgainButton = createTryAgainButton();
	addChild(tryAgainButton);
	exitButton = createExitButton();
	addChild(exitButton);
	//it is a listener of single player button
	tryAgainButton->addTouchEventListener(this, ui::SEL_TouchEvent(&GameOverScene::selTryAgain));
	exitButton->addTouchEventListener(this, ui::SEL_TouchEvent(&GameOverScene::selExit));

	return true;
}

Sprite* GameOverScene::createGamerOverLogo()
{
	auto gamerOverLogo = Sprite::create();
	gamerOverLogo->setTexture("GamerOver.png");
	gamerOverLogo->setScale((visibleSize.width / 2 / gamerOverLogo->getContentSize().width));
	gamerOverLogo->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 + 150));
	return gamerOverLogo;
}

ui::Button* GameOverScene::createTryAgainButton()
{
	auto tryAgainButton = ui::Button::create();
	tryAgainButton->loadTextureNormal("TryAgain.png");
	tryAgainButton->setScale((visibleSize.width / 2 / tryAgainButton->getContentSize().width));
	tryAgainButton->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 + 50));
	return tryAgainButton;
}

ui::Button* GameOverScene::createExitButton()
{
	auto exitButton = ui::Button::create();
	exitButton->loadTextureNormal("Exit.png");
	exitButton->setScale((visibleSize.width / 2 / exitButton->getContentSize().width));
	exitButton->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	return exitButton;
}

void GameOverScene::selTryAgain(cocos2d::Ref* pSender, ui::TouchEventType type)
{
	Director::getInstance()->pushScene(GammingScene::createScene());
}

void GameOverScene::selExit(cocos2d::Ref* pSender, ui::TouchEventType type)
{
	Director::getInstance()->end();
}
