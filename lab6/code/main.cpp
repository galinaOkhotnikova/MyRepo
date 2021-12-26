#include "RuleElem.h"
#include "RuleEnd.h"
#include "Game.h"

/*void game() {
	CreateField f;
	f.generate();
	char command;
	std::cout << "If you want to see state's changes of the player or enemies in console, press y" << std::endl << 
		"If you don't, press n" << std::endl;
	std::cin >> command;
	if (command == 'y') {
		f.logger->set_cons(true);
	}
	std::cout << "If you want to see state's changes of the player or enemies in file, press y" << std::endl <<
		"If you don't, press n" << std::endl;
	std::cin >> command;
	if (command == 'y') {
		f.logger->set_file(true);
	}

	int x = f.get_field()->entry.get_xCoord();
	int y = f.get_field()->entry.get_yCoord();
	bool flag = true;
	f.show_field();
	while (flag) {
		if (_kbhit()) {
			char key = _getch();
			switch (key) {
			case 'w':
				if (f.get_field()->array_for_field[x][y + 1].get_condition() == EXIT) {
					std::cout << "GAME OVER" << std::endl;
					return;
				}
				f.get_field()->array_for_field[x][y + 1].set_player(f.get_field()->array_for_field[x][y].get_player());
				f.get_field()->array_for_field[x][y].set_player(nullptr);
				y++;
				break;
			case 'd':
				if (f.get_field()->array_for_field[x + 1][y].get_condition() == EXIT) {
					std::cout << "GAME OVER" << std::endl;
					return;
				}
				f.get_field()->array_for_field[x + 1][y].set_player(f.get_field()->array_for_field[x][y].get_player());
				f.get_field()->array_for_field[x][y].set_player(nullptr);
				x++;
				break;
			case 's':
				if (f.get_field()->array_for_field[x][y - 1].get_condition() == EXIT) {
					std::cout << "GAME OVER" << std::endl;
					return;
				}
				f.get_field()->array_for_field[x][y - 1].set_player(f.get_field()->array_for_field[x][y].get_player());
				f.get_field()->array_for_field[x][y].set_player(nullptr);
				y--;
				break;
			case 'a':
				if (f.get_field()->array_for_field[x - 1][y].get_condition() == EXIT) {
					std::cout << "GAME OVER" << std::endl;
					return;
				}
				f.get_field()->array_for_field[x - 1][y].set_player(f.get_field()->array_for_field[x][y].get_player());
				f.get_field()->array_for_field[x][y].set_player(nullptr);
				x--;
				break;
			default:
				flag = false;
				break;
			}
			f.show_field();
		}

		if (f.get_field()->array_for_field[x][y].get_condition() == EXIT) {
			std::cout << "GAME OVER" << std::endl;
			flag = false;
		}
		else {
			if (f.get_field()->array_for_field[x][y].get_player() != nullptr &&
				f.get_field()->array_for_field[x][y].get_enemy() != nullptr) {
				ICell elem;
				IEnemy* ptr = elem.attack(f.get_field()->array_for_field[x][y].get_player(), f.get_field()->array_for_field[x][y].get_enemy());
				if (f.get_field()->array_for_field[x][y].get_player()->get_lives() <= 0) {
					std::cout << "YOU LOSE, GAME OVER" << std::endl;
					flag = false;
				}
				if (ptr == nullptr) {
					f.get_field()->array_for_field[x][y].set_enemy(ptr);
				}
				else {
					if (f.get_field()->array_for_field[x][y].get_enemy()->get_type_of_enemy() == ENEMY1) {
						f.move_enemy1();
					}

					if (f.get_field()->array_for_field[x][y].get_enemy()->get_type_of_enemy() == ENEMY2) {
						f.move_enemy2();
					}

					if (f.get_field()->array_for_field[x][y].get_enemy()->get_type_of_enemy() == ENEMY3) {
						f.move_enemy3();
					}
				}
			}
			else {
				if (f.get_field()->array_for_field[x][y].get_player() != nullptr && 
					f.get_field()->array_for_field[x][y].get_stuff() != nullptr) {
						ICell elem;
						f.get_field()->array_for_field[x][y].set_stuff(elem.take(f.get_field()->array_for_field[x][y].get_player(), 
							f.get_field()->array_for_field[x][y].get_stuff()));
				}
			}
		}
	}
}*/


int main() {
	RuleElem<int, int> ruleelem(10, 5);
	RuleEnd<Condition> ruleend(EXIT);
	//Game<int, int, RuleEnd<Condition>> game(ruleelem.get_cells(), ruleelem.get_points(), ruleend);
	Game<int, int> game(ruleelem.get_cells(), ruleelem.get_points());
	game.play_game();
	return 0;
}
