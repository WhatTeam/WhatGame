#include "MainScene.h"


cocos2d::Scene* MainScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = MainScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

bool MainScene::init()
{
	LayerColor::initWithColor(Color4B::WHITE);
	visibleSize = Director::getInstance()->getVisibleSize();

	//add the logo and buttons
	hitPlaneLogo = createHitPlaneLogo();
	addChild(hitPlaneLogo);
	singlePlayerButton = createSinglePlayerButton();
	addChild(singlePlayerButton);
	multiPlayerButton = createMultiPlayerButton();
	addChild(multiPlayerButton);
	//it is a listener of single player button
	singlePlayerButton->addTouchEventListener(this, ui::SEL_TouchEvent(&MainScene::selSinglePlayer));

	return true;
}

Sprite *MainScene::createHitPlaneLogo()
{//this is the logo of the game
	auto hitPlaneLogo = Sprite::create();
	hitPlaneLogo->setTexture("HitPlane.png");
	hitPlaneLogo->setScale((visibleSize.width / 2 / hitPlaneLogo->getContentSize().width));
	hitPlaneLogo->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 + 150));
	return hitPlaneLogo;
}

ui::Button* MainScene::createSinglePlayerButton()
{//a button of single player,once clicked,the single player game will start
	auto singlePlayerButton = ui::Button::create();
	singlePlayerButton->loadTextureNormal("SinglePlayer.png");
	singlePlayerButton->setScale((visibleSize.width / 2 / singlePlayerButton->getContentSize().width));
	singlePlayerButton->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 + 50));
	return singlePlayerButton;
}

ui::Button* MainScene::createMultiPlayerButton()
{//a button of multi player,once clicked,the multi player game will start
	auto multiPlayerButton = ui::Button::create();
	multiPlayerButton->loadTextureNormal("MultiPlayer.png");
	multiPlayerButton->setScale((visibleSize.width / 2 / multiPlayerButton->getContentSize().width));
	multiPlayerButton->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	return multiPlayerButton;
}

void MainScene::selSinglePlayer(cocos2d::Ref *pSender, ui::TouchEventType type)
{//click to remove the mainScene
	getParent()->removeChild(this);
}
