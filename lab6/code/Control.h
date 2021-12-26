#ifndef _CONTROL_H_
#define _CONTROL_H_
#include "CreateField.h"
#include "Enemy1.h"
#include "Enemy2.h"
#include "Enemy3.h"
#include "Player.h"
#include "IStuff.h"
#include "ICell.h"
#include "Movement.h"
#include "Set_log.h"
#include <iostream>
#include <conio.h>
#include <string>

class Control {
public:
    Control(CreateField* val1, Movement* val2, Set_log* val3) : f(val1), movement(val2), log(val3) {}
    void choose_log();
    Pair press_button(Pair p, char button);
private:
    CreateField* f;
    Movement* movement;
    Set_log* log;

};
#endif
