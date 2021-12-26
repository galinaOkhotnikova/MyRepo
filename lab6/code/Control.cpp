#include "Control.h"


void Control::choose_log() {
	char command;
	std::cout << "If you want to see state's changes of the player or enemies in console, press y" << std::endl <<
		"If you don't, press n" << std::endl;
	std::cin >> command;
	if (command == 'y') {
		f->logger->set_cons(true);
	}
	std::cout << "If you want to see state's changes of the player or enemies in file, press y" << std::endl <<
		"If you don't, press n" << std::endl;
	std::cin >> command;
	if (command == 'y') {
		f->logger->set_file(true);
	}
}

Pair Control::press_button(Pair p, char button) {
    switch (button) {
    case 'd':
        p = { p.x, p.y + 1 };
        break;
    case 's':
        p = { p.x + 1, p.y };
        break;
    case 'a':
        p = { p.x, p.y - 1 };
        break;
    case 'w':
        p = { p.x - 1, p.y };
        break;
    default:
        break;
    }
    return p;
}

