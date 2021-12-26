#ifndef _ARMOR_H_
#define _ARMOR_H_
#include "Player.h"
#include "IStuff.h"

class Armor: public IStuff {
public:
	Armor() {}
	virtual void help_player(Player* player) override;

};

#endif
