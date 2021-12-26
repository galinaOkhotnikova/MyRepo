#include "CreateField.h"
#include <conio.h>

CreateField::CreateField(Field* f1, Player* pl1, Enemy1* e1, Enemy2* e2, Enemy3* e3, Point* p1, Armor* a1, Live* l1) {
	f = f1;
	player = pl1;
	enemy1 = e1;
	enemy2 = e2;
	enemy3 = e3;
	point = p1;
    armor = a1;
	live = l1;
	logger = new Logger({ player, enemy1, enemy2, enemy3 });
}
CreateField::CreateField() {
	f = new Field();
	player = new Player();
	enemy1 = new Enemy1();
	enemy2 = new Enemy2();
	enemy3 = new Enemy3();
	live = new Live();
	point = new Point();
	armor = new Armor();
	logger = new Logger ({ player, enemy1, enemy2, enemy3 });
}
void CreateField::generate(int C1, int C2) {
	f->field_generation(C1);
	f->entry_and_exit();
	f->array_for_field[f->entry.get_xCoord()][f->entry.get_yCoord()].set_player(player);
	f->generate_enemy(enemy1);
	f->generate_enemy(enemy2);
	f->generate_enemy(enemy3);
	for (int i = 0; i < C2; i++) {
		f->generate_stuff(point);
	}
	f->generate_stuff(live);
	f->generate_stuff(armor);

}

Field* CreateField::get_field() {
	return f;
}

void CreateField::show_field() {
	for (int i = 0; i < f->field_height; i++) {
		for (int j = 0; j < f->field_width; j++) {
			if (f->array_for_field[i][j].get_player() == nullptr && f->array_for_field[i][j].get_enemy() == nullptr &&
				f->array_for_field[i][j].get_stuff() == nullptr) {
				if (f->array_for_field[i][j].get_condition() == ENTRY) {
					std::cout << "\x1b[33m@\x1b[0m" << ' ';
				}
				if (f->array_for_field[i][j].get_condition() == EXIT) {
					std::cout << "\x1b[33m#\x1b[0m" << ' ';
									}
				if (f->array_for_field[i][j].get_condition() == CLOSE) {
					std::cout << '1' << ' ';
				}
				if (f->array_for_field[i][j].get_condition() == OPEN) {
					std::cout << '0' << ' ';
				}
			}
			else {
				if (f->array_for_field[i][j].get_player() != nullptr) {
					std::cout << "\x1b[32mP\x1b[0m" << ' ';
				}
				if (f->array_for_field[i][j].get_enemy() != nullptr) {
					Cell_elem* en = f->array_for_field[i][j].get_enemy();
					std::string str;
					str = typeid(*en).name();
					if (str == typeid(Enemy1).name()) {
						std::cout << "\x1b[31mE\x1b[0m" << ' ';
					}
					if (str == typeid(Enemy2).name()) {
						std::cout << "\x1b[31mE\x1b[0m" << ' ';
					}
					if (str == typeid(Enemy3).name()) {
						std::cout << "\x1b[31mE\x1b[0m" << ' ';
					}
				}
				if (f->array_for_field[i][j].get_stuff() != nullptr) {
					IStuff* stuff = f->array_for_field[i][j].get_stuff();
					std::string str;
					str = typeid(*stuff).name();
					if (str == typeid(Point).name()) {
						std::cout << "\x1b[34m*\x1b[0m" << ' ';
					}
					if (str == typeid(Armor).name()) {
						std::cout << "\x1b[34mA\x1b[0m" << ' ';
					}
					if (str == typeid(Live).name()) {
						std::cout << "\x1b[34mL\x1b[0m" << ' ';
					}

				}
			}
		}
		std::cout << std:: endl;
	}
	std::cout << std::endl;
}
/*void CreateField::player() {
	f.array_for_field[f.entry.get_xCoord()][f.entry.get_yCoord()].set_player(player);
}*/

void CreateField::move_enemy(int x, int y) {
	srand(time(NULL));
	int key = rand() % 4;
	bool flag = true;
	while (flag) {
		if (key == 0) {
			if ((x + 1) >= 0 && (x + 1) < f->field_width && y >= 0 && y < f->field_height &&
				f->array_for_field[x + 1][y].get_condition() == OPEN && f->array_for_field[x + 1][y].get_enemy() == nullptr &&
				f->array_for_field[x + 1][y].get_player() == nullptr && f->array_for_field[x + 1][y].get_stuff() == nullptr) {
				flag = false;
				f->array_for_field[x + 1][y].set_enemy(f->array_for_field[x][y].get_enemy());
				f->array_for_field[x][y].set_enemy(nullptr);
			}
		}
		if (key == 1) {
			if ((x - 1) >= 0 && (x - 1) < f->field_width && y >= 0 && y < f->field_height &&
				f->array_for_field[x - 1][y].get_condition() == OPEN && f->array_for_field[x - 1][y].get_enemy() == nullptr &&
				f->array_for_field[x - 1][y].get_player() == nullptr && f->array_for_field[x - 1][y].get_stuff() == nullptr) {
				flag = false;
				f->array_for_field[x - 1][y].set_enemy(f->array_for_field[x][y].get_enemy());
				f->array_for_field[x][y].set_enemy(nullptr);
			}
		}
		if (key == 2) {
			if (x >= 0 && x < f->field_width && (y + 1) >= 0 && (y + 1) < f->field_height &&
				f->array_for_field[x][y + 1].get_condition() == OPEN && f->array_for_field[x][y + 1].get_enemy() == nullptr &&
				f->array_for_field[x][y + 1].get_player() == nullptr && f->array_for_field[x][y + 1].get_stuff() == nullptr) {
				flag = false;
				f->array_for_field[x][y + 1].set_enemy(f->array_for_field[x][y].get_enemy());
				f->array_for_field[x][y].set_enemy(nullptr);
			}
		}
		if (key == 3) {
			if (x >= 0 && x < f->field_width && (y - 1) >= 0 && (y - 1) < f->field_height &&
				f->array_for_field[x][y - 1].get_condition() == OPEN && f->array_for_field[x][y - 1].get_enemy() == nullptr &&
				f->array_for_field[x][y - 1].get_player() == nullptr && f->array_for_field[x][y - 1].get_stuff() != nullptr) {
				flag = false;
				f->array_for_field[x][y - 1].set_enemy(f->array_for_field[x][y].get_enemy());
				f->array_for_field[x][y].set_enemy(nullptr);
			}
		}

		key = rand() % 4;
	}
	return;
}


Pair CreateField::move_player(Pair p1, Pair p2) {
	if (p2.x < f->field_width && p2.x < f->field_height && p2.x >= 0 && p2.y >= 0 && f->array_for_field[p2.x][p2.y].get_condition() != CLOSE) {
		f->array_for_field[p2.x][p2.y].set_player(f->array_for_field[p1.x][p1.y].get_player());
		f->array_for_field[p1.x][p1.y].set_player(nullptr);
		p1 = p2;
	}
	std::cout << "Move player" << std::endl;
	return p1;
}
/*Pair CreateField::move_player(int x1, int y1, int x2, int y2) {
	f->array_for_field[x2][y2].set_player(f->array_for_field[x1][y1].get_player());
	f->array_for_field[x1][y1].set_player(nullptr);
	Pair p;
	p.x = x2;
	p.y = y2;
	return p;
}*/



/*void CreateField::move_enemy2() {
	srand(time(NULL));
	int x = f.enemy2.get_xCoord();
	int y = f.enemy2.get_yCoord();
	int key = rand() % 4;
	bool flag = true;
	while (flag) {
		if (key == 0) {
			if ((x + 1) >= 0 && (x + 1) < f.field_width && y >= 0 && y < f.field_height &&
				f.array_for_field[x + 1][y].get_condition() == OPEN && f.array_for_field[x + 1][y].get_enemy() == nullptr &&
				f.array_for_field[x + 1][y].get_player() == nullptr && f.array_for_field[x + 1][y].get_stuff() == nullptr) {
				flag = false;
				f.array_for_field[x + 1][y].set_enemy(f.array_for_field[x][y].get_enemy());
				f.array_for_field[x][y].set_enemy(nullptr);
			}
		}
		if (key == 1) {
			if ((x - 1) >= 0 && (x - 1) < f.field_width && y >= 0 && y < f.field_height &&
				f.array_for_field[x - 1][y].get_condition() == OPEN && f.array_for_field[x - 1][y].get_enemy() == nullptr &&
				f.array_for_field[x - 1][y].get_player() == nullptr && f.array_for_field[x - 1][y].get_stuff() == nullptr) {
				flag = false;
				f.array_for_field[x - 1][y].set_enemy(f.array_for_field[x][y].get_enemy());
				f.array_for_field[x][y].set_enemy(nullptr);
			}
		}
		if (key == 2) {
			if (x >= 0 && x < f.field_width && (y + 1) >= 0 && (y + 1) < f.field_height &&
				f.array_for_field[x][y + 1].get_condition() == OPEN && f.array_for_field[x][y + 1].get_enemy() == nullptr &&
				f.array_for_field[x][y + 1].get_player() == nullptr && f.array_for_field[x][y + 1].get_stuff() == nullptr) {
				flag = false;
				f.array_for_field[x][y + 1].set_enemy(f.array_for_field[x][y].get_enemy());
				f.array_for_field[x][y].set_enemy(nullptr);
			}
		}
		if (key == 3) {
			if (x >= 0 && x < f.field_width && (y - 1) >= 0 && (y - 1) < f.field_height &&
				f.array_for_field[x][y - 1].get_condition() == OPEN && f.array_for_field[x][y = 1].get_enemy() == nullptr &&
				f.array_for_field[x][y - 1].get_player() == nullptr && f.array_for_field[x][y - 1].get_stuff() == nullptr) {
				flag = false;
				f.array_for_field[x][y - 1].set_enemy(f.array_for_field[x][y].get_enemy());
				f.array_for_field[x][y].set_enemy(nullptr);
			}
		}
	}
}

void CreateField::move_enemy3() {
	srand(time(NULL));
	int x = f.enemy3.get_xCoord();
	int y = f.enemy3.get_yCoord();
	int key = rand() % 4;
	bool flag = true;
	while (flag) {
		if (key == 0) {
			if ((x + 1) >= 0 && (x + 1) < f.field_width && y >= 0 && y < f.field_height &&
				f.array_for_field[x + 1][y].get_condition() == OPEN && f.array_for_field[x + 1][y].get_enemy() == nullptr &&
				f.array_for_field[x + 1][y].get_player() == nullptr && f.array_for_field[x + 1][y].get_stuff() == nullptr) {
				flag = false;
				f.array_for_field[x + 1][y].set_enemy(f.array_for_field[x][y].get_enemy());
				f.array_for_field[x][y].set_enemy(nullptr);
			}
		}
		if (key == 1) {
			if ((x - 1) >= 0 && (x - 1) < f.field_width && y >= 0 && y < f.field_height &&
				f.array_for_field[x - 1][y].get_condition() == OPEN && f.array_for_field[x - 1][y].get_enemy() == nullptr &&
				f.array_for_field[x - 1][y].get_player() == nullptr && f.array_for_field[x - 1][y].get_stuff() == nullptr) {
				flag = false;
				f.array_for_field[x - 1][y].set_enemy(f.array_for_field[x][y].get_enemy());
				f.array_for_field[x][y].set_enemy(nullptr);
			}
		}
		if (key == 2) {
			if (x >= 0 && x < f.field_width && (y + 1) >= 0 && (y + 1) < f.field_height &&
				f.array_for_field[x][y + 1].get_condition() == OPEN && f.array_for_field[x][y + 1].get_enemy() == nullptr &&
				f.array_for_field[x][y + 1].get_player() == nullptr && f.array_for_field[x][y + 1].get_stuff() == nullptr) {
				flag = false;
				f.array_for_field[x][y + 1].set_enemy(f.array_for_field[x][y].get_enemy());
				f.array_for_field[x][y].set_enemy(nullptr);
			}
		}
		if (key == 3) {
			if (x >= 0 && x < f.field_width && (y - 1) >= 0 && (y - 1) < f.field_height &&
				f.array_for_field[x][y - 1].get_condition() == OPEN && f.array_for_field[x][y = 1].get_enemy() == nullptr &&
				f.array_for_field[x][y - 1].get_player() == nullptr && f.array_for_field[x][y - 1].get_stuff() == nullptr) {
				flag = false;
				f.array_for_field[x][y - 1].set_enemy(f.array_for_field[x][y].get_enemy());
				f.array_for_field[x][y].set_enemy(nullptr);
			}
		}
	}
}*/

CreateField::~CreateField() {
	delete player;
	delete enemy1;
	delete enemy2;
	delete enemy3;
	delete point;
	delete live;
	delete armor;
	delete logger;
}



