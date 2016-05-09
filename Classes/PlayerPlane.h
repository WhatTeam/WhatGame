#pragma once
#include "AirCraft.h"
#include "Bullet.h"

class PlayerPlane:public AirCraft
{
public:
	CREATE_FUNC(PlayerPlane);

	bool init()override;

	void onKeyPressed(EventKeyboard::KeyCode keyCode);
	void onKeyReleased(EventKeyboard::KeyCode keyCode);
	void update(float dt) override;
private:
	void attack();
	bool onAttack;
	int lastAttack;
};
