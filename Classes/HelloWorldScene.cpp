#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::createWithPhysics();
	//scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	scene->getPhysicsWorld()->setGravity(Vec2(0,-400));
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	if (!LayerColor::initWithColor(Color4B::WHITE))
    {
        return false;
    }
	Size visibleSize = Director::getInstance()->getVisibleSize();
	srand(time(NULL));

	gcs.insert(0,GameController::creat(this, 20));
	gcs.insert(0, GameController::creat(this, 400));

	scheduleUpdate();

	auto listener = EventListenerPhysicsContact::create();
	listener->onContactBegin=[this](PhysicsContact &contact)
	{
		this->unscheduleUpdate();

		Director::getInstance()->replaceScene(GameOverScene::creatScene());

		return true;
	};
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = [this](Touch *touch, Event *event)
	{
		for (auto it : gcs)
		{
			if (it->hitTestPoint(touch->getLocation()))
			{
				it->onUserTouch();
				break;
			}
		}

		return false;
	};

	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);

    return true;
}

void HelloWorld::update(float dt)
{
	for (auto it : gcs)
	{
		it->onUpdate(dt);
	}
}
