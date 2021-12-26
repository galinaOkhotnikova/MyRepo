#ifndef _ICELL_H_
#define _ICELL_H_
#include "IEnemy.h"
#include "IStuff.h"
#include "Player.h"

class ICell {
public:
	IEnemy* attack(Player* player, IEnemy* enemy);
	IStuff* take(Player* player, IStuff* stuff);
};


#endif
