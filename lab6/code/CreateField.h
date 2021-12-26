#ifndef _CREATEFIELD_H_
#define _CREATEFIELD_H_
#include "Field.h"
#include "Logger.h"
#include "Enemy1.h"
#include "Enemy2.h"
#include "Enemy3.h"
#include "Player.h"
#include "Armor.h"
#include "Point.h"
#include "Live.h"
#include <string>
#include <typeinfo>

class CreateField {
	Field* f;
	Player* player;
	Enemy1* enemy1;
	Enemy2* enemy2;
	Enemy3* enemy3;
	Live* live;
	Point* point;
	Armor* armor;

public:
	Logger* logger;
	CreateField(Field* f1, Player* pl1, Enemy1* e1, Enemy2* e2, Enemy3* e3, Point* p1, Armor* a1, Live* l1);
	CreateField();
    void generate(int C1, int C2);
	Field* get_field();
	void show_field();
	void move_enemy(int x, int y);
	Pair move_player(Pair p1, Pair p2);
	//void move_enemy2(int* coords);
	//void move_enemy3(int* coords);
	~CreateField();
};

#endif