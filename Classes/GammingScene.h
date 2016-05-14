#pragma once
#include "cocos2d.h"
#include "GameOverScene.h"
#include "PlayerPlane.h"
#include "EnemyPlane.h"
#include "Bullet.h"

USING_NS_CC;

class GammingScene :public LayerColor
{
public:
	static Scene* createScene();

	CREATE_FUNC(GammingScene);

	bool init()override;

	void update(float dt) override;
private:
	Size visibleSize;
	PlayerPlane *playerPlane;

	Vector<EnemyPlane*> enemyPlanes;
	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event*);
	void onKeyReleased(EventKeyboard::KeyCode keyCode, Event*);
	bool onContactBegin(PhysicsContact& contact);

	void createEnemyPlanes(int number, Vec2 position, Vec2 velocity, float interval);
};
