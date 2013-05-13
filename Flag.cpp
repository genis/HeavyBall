#include "Flag.h"


Flag::Flag(void)
{
	livedTime = 0;
	picked = false;
}

Flag::~Flag(void)
{
}

void Flag::pick(void)
{
	picked = true;
}

bool Flag::isAlive(void)
{
	return (!picked) || (livedTime > Flag::MAX_LIVE_TIME);
}

void Flag::process(void)
{
	++livedTime;
}

int Flag::timeLeft(void)
{
	return livedTime - Flag::MAX_LIVE_TIME;
}

