#include "Cell.h"

void Cell::choose_condition(Condition cond) {
	cell_cond = cond;
}

Condition Cell::get_condition() {
	return cell_cond;
}

void Cell::coordinates(int x, int y) {
	cell_x = x;
	cell_y = y;
}

int Cell::get_xCoord() {
	return cell_x;
}

int Cell::get_yCoord() {
	return cell_y;
}

void Cell::set_player(Player* obj) {
	player = obj;
}

void Cell::set_enemy(IEnemy* obj) {
	enemy = obj;
}

Player* Cell::get_player() {
	return player;
}

IEnemy* Cell::get_enemy() {
	return enemy;
}

void Cell::set_stuff(IStuff* obj) {
	stuff = obj;
}

IStuff* Cell::get_stuff() {
	return stuff;
}
