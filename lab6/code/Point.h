#ifndef _POINT_H_
#define _POINT_H_
#include "Player.h"
#include "IStuff.h"

class Point: public IStuff {
public:
	Point() {}
	virtual void help_player(Player* player) override;
};

#endif