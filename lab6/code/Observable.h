#ifndef _OBSERVABLE_H_
#define _OBSERVABLE_H_
#include "Observer.h"

class Observable {
	Observer* obs;
public:
	void set_obs(Observer* obs) {
		this->obs = obs;
	}
	void provide() {
		obs->renew();
	}
};


#endif
