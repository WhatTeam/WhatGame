#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Block.h"

USING_NS_CC;

class GammingScene : public Scene
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    // implement the "static create()" method manually
	CREATE_FUNC(GammingScene);

	void addStartLine();
	void addEndLine();
	void addNormalLine(int lineIndex);

	void startGame();

	void moveDown();

	void startTimer();
	void stopTimer();
	void update(float dt);

private:
	Size visibleSize;
	int linesCount;
	bool showEnd;
	Label *timerLabel;
	Node *gamerLayer;
	bool timerRunning;
	long startTime;

};

#endif // __HELLOWORLD_SCENE_H__
