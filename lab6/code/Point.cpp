#include "Point.h"

void Point::help_player(Player* player) {
	player->set_point(player->get_point() + 5);
}
