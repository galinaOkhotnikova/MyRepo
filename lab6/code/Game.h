#ifndef _GAME_H_
#define _GAME_H_
#include "CreateField.h"
#include "Enemy1.h"
#include "Enemy2.h"
#include "Enemy3.h"
#include "Player.h"
#include "IStuff.h"
#include "ICell.h"
#include "Control.h"
#include "MyException.h"
#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <string>


template<typename T1, typename T2>
class Game {
public:
    Game(T1 val1, T2 val2) {
        f = new CreateField();
        blocks_num = val1;
        point_num = val2;
    }

    void play_game() {
        f->generate(blocks_num, point_num);
        Set_log* log = new Set_log(f);
        Movement* movement = new Movement(f);
        Control* control = new Control(f, movement, log);
        control->choose_log();
        char button;
        int x = 0;
        int y = 0;
        Pair move;
        bool flag = true;
        while (flag) {
            f->show_field();

            std::cin >>button;
            move = control->press_button({ x, y }, button);
            if (move.x == x && move.y == y) {

                if (button == 'v') {
                    this->save();
                }

                if (button == 'l') {

                    try {
                        move = this->upload();
                        log = new Set_log(f);
                        movement = new Movement(f);
                        control = new Control(f, movement, log);
                        x = move.x;
                        y = move.y;
                    }

                    catch (MyException& exception) {
                        std::cerr << exception.Message();
                    };

                }
            }
            else {
                move = movement->movement_player({ x, y }, move);
                x = move.x;
                y = move.y;
                flag = movement->result({ x, y }, flag);
            }

        }
    }

    void save() {
        std::string name;
        std::cout << "Please, name file for saving\n";
        std::cin >> name;

        std::ofstream fout("C:/Users/Okhot/OneDrive/Рабочий стол/С and C++/lab_game/logger.txt/" + name + ".txt", std::ios_base::out);
        fout << f->get_field()->field_height << ' ' << f->get_field()->field_width << std::endl;;
        Pair player = { -1, -1 };
        Pair e1 = { -1, -1 };
        Pair e2 = { -1, -1 };
        Pair e3 = { -1, -1 };
        Pair ar = { -1, -1 };
        Pair l = { -1, -1 };
        for (int i = 0; i < f->get_field()->field_width; i++) {
            for (int j = 0; j < f->get_field()->field_height; j++) {
                if (f->get_field()->array_for_field[i][j].get_player() != nullptr) {
                    player = { i, j };
                }

                if (f->get_field()->array_for_field[i][j].get_enemy() != nullptr) {
                    Cell_elem* en = f->get_field()->array_for_field[i][j].get_enemy();
                    std::string str;
                    str = typeid(*en).name();
                    if (str == typeid(Enemy1).name()) {
                        e1 = { i, j };
                    }

                    if (str == typeid(Enemy2).name()) {
                        e2 = { i, j };
                    }

                    if (str == typeid(Enemy3).name()) {
                        e3 = { i, j };
                    }
                }

                if (f->get_field()->array_for_field[i][j].get_stuff() != nullptr) {
                    IStuff* obj = f->get_field()->array_for_field[i][j].get_stuff();
                    std::string str;
                    str = typeid(*obj).name();
                    if (str == typeid(Armor).name()) {
                        ar = { i, j };
                    }
                    if (str == typeid(Live).name()) {
                        l = { i, j };
                    }

                }
                fout << i << ' ' << j << ' ' << f->get_field()->array_for_field[i][j].get_condition() << std::endl;
            }
        }
     
        if (player.x != -1 && player.y != -1) {

            fout << player.x << ' ' << player.y << ' ' << f->get_field()->array_for_field[player.x][player.y].get_player()->get_health() <<
                ' ' << f->get_field()->array_for_field[player.x][player.y].get_player()->get_lives() << ' '
                << f->get_field()->array_for_field[player.x][player.y].get_player()->get_point()
                << ' ' << f->get_field()->array_for_field[player.x][player.y].get_player()->is_armor() << std::endl;

        }

        else {
            fout << -1 << std::endl;
        }

        if (e1.x != -1 && e1.y != -1) {
            fout << e1.x << ' ' << e1.y << ' ' << f->get_field()->array_for_field[e1.x][e1.y].get_enemy()->get_lives() << ' '
                << f->get_field()->array_for_field[e1.x][e1.y].get_enemy()->get_health() << std::endl;
        }

        else {
            fout << -1 << std::endl;
        }

        if (e2.x != -1 && e2.y != -1) {
            fout << e2.x << ' ' << e2.y << ' ' << f->get_field()->array_for_field[e2.x][e2.y].get_enemy()->get_lives() << ' '
                << f->get_field()->array_for_field[e2.x][e2.y].get_enemy()->get_health() << std::endl;
        }

        else {
            fout << -1 << std::endl;
        }

        if (e3.x != -1 && e3.y != -1) {
            fout << e3.x << ' ' << e3.y << ' ' << f->get_field()->array_for_field[e3.x][e3.y].get_enemy()->get_lives() << ' '
                << f->get_field()->array_for_field[e3.x][e3.y].get_enemy()->get_health() << std::endl;
        }

        else {
            fout << -1 << std::endl;
        }

        if (ar.x != -1 && ar.y != -1) {
            fout << ar.x << ' ' << ar.y << std::endl;
        }

        else {
            fout << -1 << std::endl;
        }

        if (l.x != -1 && l.y != -1) {
            fout << l.x << ' ' << l.y << std::endl;
        }

        else {
            fout << -1 << std::endl;
        }
      
        for (int i = 0; i < f->get_field()->field_width; i++) {
            for (int j = 0; j < f->get_field()->field_height; j++) {
                if (f->get_field()->array_for_field[i][j].get_stuff() != nullptr) {
                    IStuff* s = f->get_field()->array_for_field[i][j].get_stuff();
                    std::string str;
                    str = typeid(*s).name();
                    if (str == typeid(Point).name()) {
                        fout << i << ' ' << j << std::endl;
                    }
                }
            }
        }

        fout.close();
    }

    Pair upload() {
        std::cout << "Please, name file for uploading\n";
        std::string name;
        std::cin >> name;
        std::ifstream fin("C:/Users/Okhot/OneDrive/Рабочий стол/С and C++/lab_game/logger.txt/" + name + ".txt", std::ios_base::in);
        if (!fin.is_open())
            throw MyException(FileError);
        int h, w;
        fin >> h >> w;
        Field* new_field = new Field(h, w);
        int width, height, cond;
        for (int i = 0; i < new_field->field_width * new_field->field_height; i++) {
            fin >> width >> height >> cond;
            if (width >= w || height >= h || cond >= 4) {
                delete new_field;
                throw MyException(ValueError);
            }
            new_field->array_for_field[width][height].choose_condition((Condition)cond);
        }

        int health, lives, armor, points;
        Player* player = nullptr;
        Pair coords;
        fin >> width;
        if (width != -1) {
            fin >> height >> health >> lives >> armor >> points;
            player = new Player(health, points, lives, (bool)armor);
            new_field->array_for_field[width][height].set_player(player);
            coords.x = width;
            coords.y = height;
        }

        Enemy1* e1 = nullptr;
        fin >> width;
        if (width != -1) {
            fin >> height >> lives >> health;
            e1 = new Enemy1(lives, health);
            new_field->array_for_field[width][height].set_enemy(e1);
        }

        Enemy2* e2 = nullptr;
        fin >> width;
        if (width != -1) {
            fin >> height >> lives >> health;
            e2 = new Enemy2(lives, health);
            new_field->array_for_field[width][height].set_enemy(e2);
        }

        Enemy3* e3 = nullptr;
        fin >> width;
        if (width != -1) {
            fin >> height >> lives >> health;
            e3 = new Enemy3(lives, health);
            new_field->array_for_field[width][height].set_enemy(e3);
        }

        Armor* ar = nullptr;
        fin >> width;
        if (width != -1) {
            fin >> height;
            ar = new Armor;
            new_field->array_for_field[width][height].set_stuff(ar);
        }

        Live* l = nullptr;
        fin >> width;
        if (width != -1) {
            fin >> height;
            l = new Live;
            new_field->array_for_field[width][height].set_stuff(l);
        }

        Point* p_g = nullptr;
        if (!fin.eof()) {
            p_g = new Point();
        }
        while (!fin.eof()) {
            fin >> width >> height;
            new_field->array_for_field[width][height].set_stuff(p_g);
        }
        fin.close();
        CreateField* newnew_f = new CreateField(new_field, player, e1, e2, e3, p_g, ar, l);
        f = newnew_f;
        return coords;
    }

private:
    CreateField* f;
    T1 blocks_num;
    T2 point_num;
};


#endif