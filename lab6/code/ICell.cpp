#include "ICell.h"

IEnemy* ICell::attack(Player* player, IEnemy* enemy) {
	if (player->get_lives() > 0) {
		if (player->is_armor()) {
			player->set_armor(false);
			return nullptr;
		}
		else {
			enemy->attack_player(player);
			if (player->get_health() >= enemy->get_health()) {
				enemy->set_lives(enemy->get_lives() - 1);
			}
		}
	}
	if (player->get_health() <= 0) {
		player->set_lives(player->get_lives() - 1);
		player->set_health(player->get_health() + 10);
	}
	if (enemy->get_lives() == 0) {
		enemy = nullptr;
	}
	return enemy;
}

IStuff* ICell::take(Player* player, IStuff* stuff) {
	stuff->help_player(player);
	stuff = nullptr;
	return stuff;
}