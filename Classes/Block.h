#pragma once
#include "cocos2d.h"

USING_NS_CC;

class Block:public Sprite
{
public:
	static Vector<Block*> *getBlocks();

	static Block *createWithArgs(Color3B color, Size size, std::string label, float fontSize, Color4B textColor);

	virtual bool initWithArgs(Color3B color, Size size, std::string label, float fontSize, Color4B textColor);

	void removeBlock();

	int getLineIndex();
	void setLineIndex(int lineIndex);

	void rightTap();
	void wrongTap();

	void moveDown();
private:
	static Vector<Block*> *blocks;
	int lineIndex;
};
