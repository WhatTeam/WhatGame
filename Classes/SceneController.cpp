#include "SceneController.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* SceneController::createScene()
{
	// 'scene' is an physics world withoud gravity
	auto scene = Scene::createWithPhysics();
	scene->getPhysicsWorld()->setGravity(Vec2::ZERO);
	//scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	// 'layer' is an autorelease object
	auto layer = SceneController::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool SceneController::init()
{
	if ( !Layer::init() )
	{
		return false;
	}
	

	auto gammingScene = GammingScene::create();
	addChild(gammingScene);

	//auto mainScene = MainScene::create();
	//addChild(mainScene);

	return true;
}
