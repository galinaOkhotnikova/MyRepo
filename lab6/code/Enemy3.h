#ifndef _ENEMY3_H_
#define _ENEMY3_H_
#define _CRT_SECURE_NO_WARNINGS
#include "IEnemy.h"

class Enemy3 : public IEnemy {
public:
	Enemy3(int l =2, int h = 10, int change = false) {
		lives = l;
		health = h;
		changes = change;
	}
	void attack_player(Player* player) override;

	std::ostream& print(std::ostream& out) const override;

};

#endif
