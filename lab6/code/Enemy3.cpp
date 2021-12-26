#include "Enemy3.h"

void Enemy3::attack_player(Player* player) {
	player->set_health((int)player->get_health() - 10);
}


std::ostream& Enemy3::print(std::ostream& out) const {
	time_t t = time(nullptr);
	tm* time = localtime(&t);
	out << asctime(time) << "ENEMY3" << std::endl << "health: " << this->health << std::endl
		<< "lives: " << this->lives << std::endl;
	return out;
}