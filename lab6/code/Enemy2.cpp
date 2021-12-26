#include "Enemy2.h"

void Enemy2::attack_player(Player* player) {
	player->set_health((int)player->get_health() - 2);
}

std::ostream& Enemy2::print(std::ostream& out) const {
	time_t t = time(nullptr);
	tm* time = localtime(&t);
	out << asctime(time) << "ENEMY2" << std::endl << "health: " << this->health << std::endl
		<< "lives: " << this->lives << std::endl;
	return out;
}