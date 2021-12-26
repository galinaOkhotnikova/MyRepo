#include "Logger.h"
#include <stdio.h>
#include <iostream>


Logger::Logger(std::vector <Cell_elem*> el) {
	cons = false;
	file = false;
	this->el = el;
	for (int i = 0; i < el.size(); i++) {
		el[i]->set_obs(this);
	}
}

void Logger::renew() {
	for (int i = 0; i < el.size(); i++) {
		if (el[i]->get_changes()) {
			if (cons) {
				std::cout << *el[i] << std::endl;
			}
			if (file) {
				std::ofstream fout("C:/Users/Okhot/OneDrive/Рабочий стол/С and C++/lab_game/logger.txt", std::ios::app);
				if (fout.is_open()) {
					fout << *el[i] << std::endl;
				}
				fout.close();
			}
			el[i]->set_changes(false);
		}
	}
}
void Logger::set_cons(bool num) {
	cons = num;
}
void Logger::set_file(bool num) {
	file = num;
}