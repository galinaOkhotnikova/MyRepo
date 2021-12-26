#ifndef _IENEMY_H_
#define _IENEMY_H_
#include "Player.h"
#include "Cell_elem.h"


class IEnemy: public Cell_elem {
public:
	IEnemy() {};
	virtual void attack_player(Player* player) = 0;
};

#endif
