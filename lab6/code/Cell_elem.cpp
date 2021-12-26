#include "Cell_elem.h"

void Cell_elem:: set_lives(int val) {
	lives = val;
	changes = true;
	provide();
}
void Cell_elem::set_health(int val) {
	health = val;
	changes = true;
	provide();
}
int Cell_elem::get_lives() {
	return lives;
}
int Cell_elem::get_health() {
	return health;
}

bool Cell_elem::get_changes() {
	return changes;
}
void Cell_elem::set_changes(bool num) {
	changes = num;
}

std::ostream& operator <<(std::ostream& out, const Cell_elem& el) {
	return el.print(out);
}