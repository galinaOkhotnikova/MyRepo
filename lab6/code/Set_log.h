#ifndef _SET_LOG_H_
#define _SET_LOG_H_

#include "CreateField.h"

class Set_log {
public:
    Set_log(CreateField* val) : f(val) {};
    void console(bool val);
    void file(bool val);
private:
    CreateField* f;
};


#endif
