#include "GammingScene.h"
#include "cocostudio/CocoStudio.h"
//#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* GammingScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = GammingScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GammingScene::init()
{
    if ( !Scene::init() )
    {
        return false;
    }
	visibleSize = Director::getInstance()->getVisibleSize();

	gamerLayer = Node::create();
	addChild(gamerLayer);

	timerLabel = Label::create();
	timerLabel->setTextColor(Color4B::BLUE);
	timerLabel->setSystemFontSize(48);
	timerLabel->setSystemFontName("Courier");
	timerLabel->setPosition(visibleSize.width / 2, visibleSize.height-40);
	timerLabel->setString(timerLabel->getString());
	addChild(timerLabel);
	timerRunning = false;

	startGame();

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [this](Touch *touch,Event *event)
	{
		log(timerLabel->getString().c_str());
		for (auto it : *Block::getBlocks())
		{
			if (!timerRunning)
				this->startTimer();
			if (it->getLineIndex() == 1 &&
				it->getBoundingBox().containsPoint(touch->getLocation()))
			{
				if (it->getColor() == Color3B::BLACK)
				{
					it->rightTap();
					this->moveDown();
				}
				else if (it->getColor() == Color3B::GREEN)
				{
					this->moveDown();
					this->stopTimer();
				}
				else
				{
					it->wrongTap();
				}
				break;
			}
		}
		return false;
	};
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

    return true;
}

void GammingScene::addStartLine()
{
	auto block = Block::createWithArgs(Color3B::YELLOW, Size(visibleSize.width, visibleSize.height / 4), "", 20, Color4B::BLACK);
	block->setLineIndex(0);
	gamerLayer->addChild(block);
}

void GammingScene::addEndLine()
{
	auto block = Block::createWithArgs(Color3B::GREEN, visibleSize, "Well Done!", 36, Color4B::BLACK);
	block->setLineIndex(4);
	block->setPositionY(visibleSize.width*2);
	gamerLayer->addChild(block);
}

void GammingScene::addNormalLine(int lineIndex)
{
	Block *block;
	int blackIndex = rand() % 4;
	for (int i = 0; i < 4;i++)
	{
		block = Block::createWithArgs(blackIndex == i ? Color3B::BLACK : Color3B::WHITE,
			Size(visibleSize.width / 4 - 1, visibleSize.height / 4 - 1),"", 0, Color4B::BLACK);

		gamerLayer->addChild(block);
		block->setPosition(i*visibleSize.width / 4, lineIndex*visibleSize.height / 4);
		block->setLineIndex(lineIndex);
	}
	++linesCount;
}

void GammingScene::startGame()
{
	showEnd = false;
	linesCount = 0;
	addStartLine();
	addNormalLine(1);
	addNormalLine(2);
	addNormalLine(3);
}

void GammingScene::moveDown()
{
	if (linesCount < 50)
	{
		addNormalLine(4);
	}
	else if (!showEnd)
	{
		addEndLine();
		showEnd = true;
	}
	for (auto it : *Block::getBlocks())
	{
		it->moveDown();
	}
}

void GammingScene::startTimer()
{
	if (!timerRunning)
	{
		scheduleUpdate();
		startTime = clock();
		timerRunning = true;
	}
}

void GammingScene::stopTimer()
{
	if (timerRunning)
	{
		unscheduleUpdate();

		timerRunning = false;
	}
}

void GammingScene::update(float dt)
{
	long offset = clock() - startTime;

	timerLabel->setString(StringUtils::format("%.3f", (double)offset/1000));
}
