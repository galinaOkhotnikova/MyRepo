#ifndef _RULEEND_H_
#define _RULEEND_H_

template<typename T>
class RuleEnd {
public:
    RuleEnd(T val) : value(val), result(false) {};
    bool done(T val) {
        if (val == value) {
            result = true;
        }
        return result;
    }

private:
    T value;
    bool result;
};

#endif
