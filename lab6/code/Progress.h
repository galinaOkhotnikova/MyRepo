#ifndef _PROGRESS_H_
#define _PROGRESS_H_
#include "CreateField.h"
#include "Enemy1.h"
#include "Enemy2.h"
#include "Enemy3.h"
#include "Player.h"
#include "IStuff.h"
#include "ICell.h"
#include <conio.h>
#include <string>

class Progress {
public:
	Progress(CreateField* val) : f(val) {}
	void progress_player(int x1, int y1, int x2, int y2);

private:
	CreateField* f;
	ICell el;
};

#endif