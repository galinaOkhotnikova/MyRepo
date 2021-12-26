#ifndef _PLAYER_H_
#define _PLAYER_H_
#define _CRT_SECURE_NO_WARNINGS
#include "Cell_elem.h"
#include <ctime>

class Player: public Cell_elem {
public:
	Player(int h = 10, int p = 0, int l = 3, bool ar = false, bool change = false) {
		health = h;
		point = p;
		lives = l;
		armor = ar;
		changes = change;
	}
	void set_point(int count);
	void set_armor(bool val);
	int get_point();
	bool is_armor();
	
	std::ostream& print(std::ostream& out) const override;

private:
	int point;
	bool armor;
};


#endif