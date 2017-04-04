#include "utils.h"

using namespace std;

int solution(vector<int> &A, int X, int D) {
    // write your code in C++11 (g++ 4.8.2)
    if (X <= D) return 0;

    int nranges = (X / D) + 1;

    vector<int> maxrange(nranges, INT_MIN);
    vector<int> minrange(nranges, INT_MAX);

    maxrange[0] = 0;
    minrange[0] = 0;
    maxrange[nranges - 1] = X;
    minrange[nranges - 1] = X;

    int needconnect = nranges - 1;

    for (int i = 0; i < (int)A.size(); ++i) {
        int ind = A[i] / nranges;

        if (A[i] <= maxrange[ind] && A[i] >= minrange[ind]) continue;

        int nextmin = 0;

        if (ind == nranges - 1)
            nextmin = INT_MAX;
        else
            nextmin = minrange[ind + 1];

        int prevmax = 0;

        if (ind == 0)
            prevmax = INT_MIN;
        else
            prevmax = maxrange[ind - 1];

        bool failnext = (minrange[ind] > maxrange[ind])
                            ? true
                            : minrange[ind] - prevmax > D;
        bool failprev = (minrange[ind] > maxrange[ind])
                            ? true
                            : nextmin - maxrange[ind] > D;

        if (A[i] - prevmax <= D && failnext) {
            --needconnect;
        }

        if (nextmin - A[i] <= D && failprev) {
            --needconnect;
        }

        if (A[i] > maxrange[ind]) maxrange[ind] = A[i];
        if (A[i] < minrange[ind]) minrange[ind] = A[i];

        if (needconnect == 0) return i;
    }

    return -1;
}

int main(int argc, char *argv[]) {
    // cout<<sizeof(int)<<endl;
    vector<int> A{1, 3, 1, 4, 2, 5};
    cout << solution(A, 5, 3);

    return 0;
}
