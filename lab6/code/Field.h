#ifndef _FIELD_H_
#define _FIELD_H_

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Cell.h"
#include "Enemy1.h"
#include "Enemy2.h"
#include "Enemy3.h"
#include "IEnemy.h"
#include "Armor.h"
#include "Point.h"
#include "Live.h"

class Field{
public:
	int field_width, field_height;
	Cell** array_for_field;
	Cell entry, exit;
	Cell enemy1, enemy2, enemy3;
	Cell armor, point, live;	
	Field(int width = 10, int height = 10);
	Field(const Field& obj);
	Field& operator = (const Field& obj);
	Field(Field&& obj);
	Field& operator = (Field&& obj);
	void field_generation(int C);
	void entry_and_exit();
	void generate_enemy(IEnemy* enemy);
	void generate_stuff(IStuff* stuff);
	~Field();
};

#endif