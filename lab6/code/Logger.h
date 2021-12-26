#ifndef _LOGGER_H_
#define _LOGGER_H_
#include "Observer.h"
#include "Observable.h"
#include "Cell_elem.h"
#include <vector>
#include <fstream>
#include <ctime>

class Logger : public Observer {
	std::vector <Cell_elem*> el;
public:
	Logger(std::vector <Cell_elem*> el);
	void renew();
	void set_cons(bool num);
	void set_file(bool num);

private:
	bool cons, file;
};



#endif
