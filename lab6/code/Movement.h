#ifndef _MOVEMENT_H_
#define _MOVEMENT_H_

#include "CreateField.h"
#include "ICell.h"

class Movement {
public:
    Movement(CreateField* val) : f(val) {};
    bool result(Pair p, bool flag);
    Pair movement_player(Pair p1, Pair p2);

private:
    CreateField* f;
    ICell* el;
};


#endif