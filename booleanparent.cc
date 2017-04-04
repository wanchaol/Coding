#include "utils.h"

class Solution {
   public:
    int countParenth(char symb[], char oper[], int n) {
        vector<vector<int>> T(n, vector<int>(n, 0));
        vector<vector<int>> F(n, vector<int>(n, 0));

        for (int i = 0; i < n; ++i) {
            T[i][i] = (symb[i] == 'T') ? 1 : 0;
            F[i][i] = (symb[i] == 'F') ? 1 : 0;
        }

        for (int gap = 1; gap < n; ++gap) {
            for (int i = 0, j = gap; j < n; ++i, ++j) {
                for (int k = i; k < i + gap; ++k) {
                    if (oper[k] == '&') {
                        T[i][j] += T[i][k] * T[k + 1][j];
                        F[i][j] += F[i][k] * F[k + 1][j] +
                                   T[i][k] * F[k + 1][j] +
                                   F[i][k] * T[k + 1][j];

                    } else if (oper[k] == '|') {
                        T[i][j] += T[i][k] * T[k + 1][j] +
                                   T[i][k] * F[k + 1][j] +
                                   F[i][k] * T[k + 1][j];
                        F[i][j] += F[i][k] * F[k + 1][j];
                    } else if (oper[k] == '^') {
                        T[i][j] +=
                            T[i][k] * F[k + 1][j] + F[i][k] * T[k + 1][j];
                        F[i][j] +=
                            T[i][k] * T[k + 1][j] + F[i][k] * F[k + 1][j];
                    }
                }
            }
        }
        return T[0][n - 1];
    }

   private:
    /* data */
};

int main(int argc, char *argv[]) {
    char symbols[] = "TTFT";
    char operators[] = "|&^";
    int n = strlen(symbols);

    Solution sol;

    // There are 4 ways
    // ((T|T)&(F^T)), (T|(T&(F^T))), (((T|T)&F)^T) and (T|((T&F)^T))
    cout << sol.countParenth(symbols, operators, n);
    return 0;
}
