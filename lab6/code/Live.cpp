#include "Live.h"

void Live::help_player(Player* player) {
	player->set_lives(player->get_lives() + 1);
}

