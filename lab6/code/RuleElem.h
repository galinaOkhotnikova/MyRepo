#ifndef _RULEELEM_H_
#define _RULEELEM_H_

template <typename T1, typename T2>
class RuleElem {
private:
    T1 cells;
    T2 points;
public:
    RuleElem(T1 num_cells, T2 num_points) {
        cells = num_cells;
        points = num_points;
    }

    T1 get_cells() {
        return cells;
    }

    T2 get_points() {
        return points;
    }
};

#endif
