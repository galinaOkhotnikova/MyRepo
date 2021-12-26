#ifndef _ISTUFF_H_
#define _ISTUFF_H_
#include "Player.h"
#include "Cell_elem.h"


class IStuff {
public:
	IStuff() {};
	virtual void help_player(Player* player) = 0;

};

#endif
