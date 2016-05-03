#include "Block.h"

Vector<Block*> *Block::blocks = new Vector<Block*>();

Vector<Block*> *Block::getBlocks()
{
	return Block::blocks;
}

Block* Block::createWithArgs(Color3B color, Size size, std::string label, float fontSize, Color4B textColor)
{
	auto block = new Block();
	block->initWithArgs(color, size, label, fontSize, textColor);
	block->autorelease();

	blocks->pushBack(block);

	return block;
}

bool Block::initWithArgs(Color3B color, Size size, std::string label, float fontSize, Color4B textColor)
{
	Sprite::init();

	setContentSize(size);
	setAnchorPoint(Point::ZERO);
	setTextureRect(Rect(0, 0, size.width, size.height));
	setColor(color);
	lineIndex = 0;

	auto newLabel = Label::create();
	newLabel->setString(label);
	newLabel->setSystemFontSize(fontSize);
	newLabel->setTextColor(textColor);
	addChild(newLabel);
	newLabel->setPosition(size.width / 2, size.height / 2);

	return true;
}

void Block::removeBlock()
{
	log("Remove Block");
	removeFromParent();
	blocks->eraseObject(this);
}

int Block::getLineIndex()
{
	return lineIndex;
}

void Block::setLineIndex(int lineIndex)
{
	this->lineIndex = lineIndex;
}

void Block::rightTap()
{
	setColor(Color3B::GRAY);
}

void Block::wrongTap()
{
	setColor(Color3B::RED);
}

void Block::moveDown()
{
	--this->lineIndex;

	Size visibleSize = Director::getInstance()->getVisibleSize();

	runAction(Sequence::create(MoveTo::create(0.1f, Point(getPositionX(), lineIndex*visibleSize.height / 4)),
		CallFunc::create([this]{
		if (lineIndex < 0)
			this->removeBlock();
	}),NULL));


}
