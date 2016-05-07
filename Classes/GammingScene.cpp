#include "GammingScene.h"

bool GammingScene::init()
{
	LayerColor::initWithColor(Color4B::WHITE);

	playerPlane = PlayerPlane::create();
	addChild(playerPlane);
	playerPlane->scheduleUpdate();

	setKeyboardEnabled(true);
	auto keyBoardListener = EventListenerKeyboard::create();
	keyBoardListener->onKeyPressed = [this](EventKeyboard::KeyCode keyCode, Event *event) {
		playerPlane->onKeyPressed(keyCode);
		return true;
	};
	keyBoardListener->onKeyReleased = [this](EventKeyboard::KeyCode keyCode, Event *event) {
		playerPlane->onKeyReleased(keyCode);
		return true;
	};
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyBoardListener, this);
	
	return true;
}