#ifndef _CELL_H_
#define _CELL_H_
#include "ICell.h"
#include "Player.h"
#include "IEnemy.h"
#include "Armor.h"
#include "Point.h"
#include "Live.h"

struct Pair {
	int x;
	int y;
};

enum Condition { ENTRY, EXIT, OPEN, CLOSE };
class Cell {
public:
	Cell() : cell_cond(OPEN), cell_x(0), cell_y(0), player(nullptr), enemy(nullptr), 
		stuff(nullptr) {}
	void choose_condition(Condition cond);
	Condition get_condition();
	void coordinates(int x, int y);
	int get_xCoord();
	int get_yCoord();
	void set_player(Player* obj);
	void set_enemy(IEnemy* obj);
	Player* get_player();
	IEnemy* get_enemy();
	void set_stuff(IStuff* obj);
	IStuff* get_stuff();

private:
	Condition cell_cond; //состояние клетки
	int cell_x, cell_y; //координаты клетки
	Player* player;
	IEnemy* enemy;
	IStuff* stuff;
};

#endif