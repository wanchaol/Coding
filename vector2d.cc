#include "utils.h"


class Vector2D {
    vector<vector<int>>::iterator iter, iend;
    int index = 0;
public:
    Vector2D(vector<vector<int>>& vec2d) {
        iter = vec2d.begin();
        iend = vec2d.end();
    }

    int next() {
        return (*iter)[index ++];
    }

    bool hasNext() {
        while(iter != iend && index == (*iter).size()) {
            ++ iter;
            index = 0;
        }
        return iter!= iend;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
