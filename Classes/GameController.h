#pragma once
#include "cocos2d.h"
#include "GameController.h"
#include "Edge.h"
#include "Block.h"
#include "Hero.h"

USING_NS_CC;

class GameController :public Ref
{
public:
	virtual bool init(Layer *layer, float positionY);
	static GameController *creat(Layer *layer, float postionY);


	bool hitTestPoint(Vec2 point);
	void onUpdate(float dt);
	void onUserTouch();
private:
	Layer *_layer;
	float _positionY;
	Size visibleSize;

	int currentFrameIndex;
	int nextFrameCount;

	void resetFrames();
	void addBlock();
	Edge *edge;
	Hero *hero;
};