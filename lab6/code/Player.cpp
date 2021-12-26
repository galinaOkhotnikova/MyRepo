#include "Player.h"

void Player::set_point(int count) {
	point = count;
	provide();
}
void Player::set_armor(bool val) {
	armor = val;
	provide();
}
int Player::get_point() {
	return point;
}

bool Player::is_armor() {
	return armor;
}

std::ostream& Player::print(std::ostream& out) const {
	time_t t = time(nullptr);
	tm* time = localtime(&t);
	out << asctime(time) << "PLAYER" << std::endl << "health: " << this->health << std::endl << "point: " << this->point <<
		std::endl << "armor: " << this->armor << std::endl << "lives: " << this->lives << std::endl;
	return out;
}