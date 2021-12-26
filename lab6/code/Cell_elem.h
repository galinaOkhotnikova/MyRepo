#ifndef _CELL_ELEM_H_
#define _CELL_ELEM_H_
#include "Observable.h"
#include <iostream>

class Cell_elem: public Observable {
public:
	void set_lives(int val);
	void set_health(int val);
	int get_lives();
	int get_health();
	bool get_changes();
	void set_changes(bool num);
	virtual ~Cell_elem() = default;
	virtual std::ostream& print(std::ostream& out) const = 0;
	friend::std::ostream& operator <<(std::ostream& out, const Cell_elem& el);


protected:
	int lives, health;
	bool changes;

};


#endif
