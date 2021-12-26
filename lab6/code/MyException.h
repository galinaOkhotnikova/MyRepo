#ifndef _MYEXCEPTION_H_
#define _MYEXCEPTION_H_
#include "iostream"

enum ERROR { FileError, ValueError };

class MyException {

public:
    MyException(ERROR t1) :error(t1) {
        switch (error) {
        case FileError:
            mess = "ERROR: There are some problems with file\n";
            break;
        case ValueError:
            mess = "ERROR: There are some problems with values\n";
            break;
        }
    };
    std::string Message() {
        return mess;
    }

private:
    ERROR error;
    std::string mess;
};

#endif

