#include "utils.h"

class MinStack {
    vector<int> stack;
    vector<int> minEle;

   public:
    void push(int x) {
        stack.push_back(x);

        if (minEle.empty())
            minEle.push_back(x);
        else if (x < minEle.back())
            minEle.push_back(x);
        else {
            minEle.push_back(minEle.back());
        }
    }

    void pop() {
        stack.pop_back();
        minEle.pop_back();
    }

    int top() { return stack.back(); }

    int getMin() { return minEle.back(); }
};
