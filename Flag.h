#pragma once
#include "Point.h"
#include "Object.h"

class Flag : public Object
{
public:
	static const int MAX_LIVE_TIME = 120;

	Flag(void);
	~Flag(void);

	void pick(void);

	int timeLeft(void);
	bool isAlive(void);

	void process(void);

private:
	int livedTime;
	bool picked;
};

