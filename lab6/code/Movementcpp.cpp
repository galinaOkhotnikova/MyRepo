#include "Movement.h"

bool Movement::result(Pair p, bool flag) {
    if (f->get_field()->array_for_field[p.x][p.y].get_condition() == EXIT) {
        std::cout << "GAME OVER" << std::endl;
        flag = false;
    }

    else {
        if (f->get_field()->array_for_field[p.x][p.y].get_player() != nullptr && f->get_field()->array_for_field[p.x][p.y].get_enemy() != nullptr) {
            IEnemy* ptr = el->attack(f->get_field()->array_for_field[p.x][p.y].get_player(), f->get_field()->array_for_field[p.x][p.y].get_enemy());
            if (f->get_field()->array_for_field[p.x][p.y].get_player()->get_lives() <= 0) {
                std::cout << "YOU LOOSE, GAME OVER" << std::endl;
                flag = false;
            }
            if (ptr == nullptr) {
                f->get_field()->array_for_field[p.x][p.y].set_enemy(ptr);
            }
            else {
                f->move_enemy(p.x, p.y );
            }
        }
        else {
            if (f->get_field()->array_for_field[p.x][p.y].get_player() != nullptr && f->get_field()->array_for_field[p.x][p.y].get_stuff() != nullptr) {
                f->get_field()->array_for_field[p.x][p.y].set_stuff(el->take(f->get_field()->array_for_field[p.x][p.y].get_player(), f->get_field()->array_for_field[p.x][p.y].get_stuff()));
            }
        }
    }
    return flag;
}

Pair Movement::movement_player(Pair p1, Pair p2) {
    Pair res = f->move_player({ p1.x, p1.y }, { p2.x, p2.y });
    return res;
}

