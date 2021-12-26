#ifndef _ENEMY1_H_
#define _ENEMY1_H_
#define _CRT_SECURE_NO_WARNINGS
#include "IEnemy.h"

class Enemy1 : public IEnemy {
public:
	Enemy1(int l = 1, int h = 10, bool change = false) {
		lives = l;
		health = h;
		changes = change;
	}
	void attack_player(Player* player) override;

	std::ostream& print(std::ostream& out) const override;

};

#endif