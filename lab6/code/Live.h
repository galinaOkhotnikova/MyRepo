#ifndef _LIVE_H_
#define _LIVE_H_
#include "Player.h"
#include "IStuff.h"

class Live : public IStuff {
public:
	Live() {}
	virtual void help_player(Player* player) override;;
};

#endif
