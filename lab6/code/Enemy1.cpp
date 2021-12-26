#include "Enemy1.h"

void Enemy1::attack_player(Player* player) {
	player->set_health((int)player->get_health() - 5);
}


std::ostream& Enemy1::print(std::ostream& out) const {
	time_t t = time(nullptr);
	tm* time = localtime(&t);
	out << asctime(time) << "ENEMY1" << std::endl << "health: " << this->health << std::endl 
		<< "lives: " << this->lives << std::endl;
	return out;
}