#pragma once
#include "AirCraft.h"

class Bullet:public AirCraft
{
public:
	CREATE_FUNC(Bullet);

	bool init()override;

	void update() { log("1"); };
private:

};
