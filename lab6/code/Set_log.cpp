#include "Set_log.h"

void Set_log::console(bool val) {
    f->logger->set_cons(val);
}

void Set_log::file(bool val) {
    f->logger->set_file(val);
}
