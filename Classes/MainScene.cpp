#include "MainScene.h"

bool MainScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	return true;
}

Scene* MainScene::createScene()
{
	auto scene = Scene::create();
	auto layer = MainScene::create();
	scene->addChild(layer);	
	layer->setColor(Color3B::WHITE);
	layer->setContentSize(Size(100, 100));
	return scene;
}
