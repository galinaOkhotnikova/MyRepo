#include "Field.h"
#include <ctime>

Field::Field(int width, int height) {
	field_width = width;
	field_height = height;
	array_for_field = new Cell * [field_width];
	for (int i = 0; i < field_width; i++) {
		array_for_field[i] = new Cell[field_height];
	}
}

//конструктор копирования
Field::Field(const Field& obj) {
	field_width = obj.field_width;
	field_height = obj.field_height;
	this->array_for_field = new Cell * [obj.field_width];
	for (int i = 0; i < field_width; i++) {
		this->array_for_field[i] = new Cell[field_height];
		for (int j = 0; j < field_height; j++) {
			this->array_for_field[i][j] = obj.array_for_field[i][j]; 
		}
	}
	entry = obj.entry;
	exit = obj.exit;
	enemy1 = obj.enemy1;
	enemy2 = obj.enemy2;
	enemy1 = obj.enemy1;
}

Field &Field::operator = (const Field& obj) {
	if (this != &obj) {
		for (int i = 0; i < field_width; i++) {
			delete[] array_for_field[i];
		}
		delete[] array_for_field;
		field_width = obj.field_width;
		field_height = obj.field_height;
		this->array_for_field = new Cell * [field_width];
		for (int i = 0; i < field_width; i++) {
			this->array_for_field[i] = new Cell [field_height];
			for (int j = 0; j < field_height; j++) {
				this->array_for_field[i][j] = obj.array_for_field[i][j];
			}
		}
		entry = obj.entry;
		exit = obj.exit;
		enemy1 = obj.enemy1;
		enemy2 = obj.enemy2;
		enemy1 = obj.enemy1;
	}
	return *this;
}

//конструктор перемещения
Field::Field(Field&& obj) {
	std::swap(field_width, obj.field_width);
	std::swap(field_height, obj.field_height);
	std::swap(array_for_field, obj.array_for_field);
	std::swap(entry, obj.entry);
	std::swap(exit, obj.exit);
	std::swap(enemy1, obj.enemy1);
	std::swap(enemy2, obj.enemy2);
	std::swap(enemy1, obj.enemy1);
}

Field &Field:: operator = (Field&& obj) {
	if (this != &obj) {
		std::swap(field_width, obj.field_width);
		std::swap(field_height, obj.field_height);
		std::swap(array_for_field, obj.array_for_field);
		std::swap(entry, obj.entry);
		std::swap(exit, obj.exit);
		std::swap(enemy1, obj.enemy1);
		std::swap(enemy2, obj.enemy2);
		std::swap(enemy1, obj.enemy1);
	}
	return *this;
}


void Field::field_generation(int C) {
	int count = 0;
	srand(time(NULL));
	if (rand() % 2 == 0) {
		for (int i = 0; i < field_width; i += 2) {
			if (count < C) {
				array_for_field[i][rand() % field_height].choose_condition(CLOSE);
				count++;
			}
		}
		for (int j = 0; j < field_height; j++) {
			if (count < C) {
				array_for_field[rand() % field_width][j].choose_condition(CLOSE);
				count++;
			}
		}
	}
	else {
		for (int i = 0; i < field_width; i++) {
			if (count < C) {
				array_for_field[i][rand() % field_height].choose_condition(CLOSE);
				count++;
			}
		}
		for (int j = 0; j < field_height; j += 2) {
			if (count < C) {
				array_for_field[rand() % field_width][j].choose_condition(CLOSE);
				count++;
			}
		}
	}
}

void Field::entry_and_exit() {
	srand(time(NULL));
	int tmp1, tmp2;
	if (rand() % 2 == 0) {
		tmp1 = rand() % field_height;
		array_for_field[0][tmp1].choose_condition(ENTRY);
		entry = array_for_field[0][tmp1];
		entry.coordinates(0, tmp1);
		tmp2 = rand() % field_height;
		array_for_field[field_width - 1][tmp2].choose_condition(EXIT);
		exit = array_for_field[field_width - 1][tmp2];
		exit.coordinates((field_width - 1), tmp2);


	}
	else if (rand() % 2 == 1) {
		tmp1 = rand() % field_width;
		array_for_field[tmp1][0].choose_condition(ENTRY);
		entry = array_for_field[tmp1][0];
		entry.coordinates(tmp1, 0);
		tmp2 = rand() % field_width;
		array_for_field[tmp2][field_height - 1].choose_condition(EXIT);
		exit = array_for_field[tmp2][field_height - 1];
		exit.coordinates(tmp2, (field_height - 1));
	} 
}

void Field::generate_enemy(IEnemy* enemy) {
	srand(time(NULL));
	int tmp1 = rand() % field_width;
	int tmp2 = rand() % field_height;
	bool flag = true;
	while (flag) {
		if (array_for_field[tmp1][tmp2].get_condition() == OPEN &&
			array_for_field[tmp1][tmp2].get_player() == nullptr &&
			array_for_field[tmp1][tmp2].get_enemy() == nullptr) {
			array_for_field[tmp1][tmp2].set_enemy(enemy);
			flag = false;
		}
		tmp1 = rand() % field_width;
		tmp2 = rand() % field_height;
	}
	std::cout << "Generation works!" << std::endl;
}

void Field::generate_stuff(IStuff* stuff) {
	srand(time(NULL));
	int tmp1 = rand() % field_width;
	int tmp2 = rand() % field_height;
	bool flag = true;
	while (flag == true) {
		if (array_for_field[tmp1][tmp2].get_condition() == OPEN &&
			array_for_field[tmp1][tmp2].get_player() == nullptr &&
			array_for_field[tmp1][tmp2].get_enemy() == nullptr &&
			array_for_field[tmp1][tmp2].get_stuff() == nullptr) {
			array_for_field[tmp1][tmp2].set_stuff(stuff);
			flag = false;

		}
		tmp1 = rand() % field_width;
		tmp2 = rand() % field_height;
	}
}

Field::~Field() {
	for (int j = 0; j < field_width; j++) {
		delete[] array_for_field[j];
	}
	delete[] array_for_field;
}