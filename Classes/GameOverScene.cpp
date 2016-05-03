#include "GameOverScene.h"

bool GameOverScene::init()
{
	visibleSize = Director::getInstance()->getVisibleSize();
	LayerColor::initWithColor(Color4B::WHITE);
	
	auto label = Label::create();
	label->setString("Game Over!");
	label->setSystemFontSize(40);
	label->setColor(Color3B::BLACK);
	label->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	addChild(label);

	return true;
}

Scene* GameOverScene::creatScene()
{
	auto scene = Scene::create();
	auto layer = GameOverScene::create();

	scene->addChild(layer);

	return scene;

}
