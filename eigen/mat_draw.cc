#include "../utils.h"

class MatrixDrawer {
   public:
    /*
      n=2:
      1 1
      1 1
      n=3
      1 1 1
      1 2 1
      1 1 1
      n=4
      1 1 1 1
      1 2 2 1
      1 2 2 1
      1 1 1 1
      n=5
      1 1 1 1 1
      1 2 2 2 1
      1 2 3 2 1
      1 2 2 2 1
      1 1 1 1 1
     */
    void PrintMatS2B(int n) {
        int pivot = (n + 1) / 2;
        int odd = n % 2;
        int i, j;

        for (i = 1; i <= pivot; ++i) {
            for (j = 1; j <= i; ++j) cout << j;
            for (j = 1; j < n - 2 * i + 1 + odd; ++j) cout << i;
            for (j = i - odd; j >= 1; --j) cout << j;
            cout << endl;
        }

        for (i = pivot - odd; i >= 1; --i) {
            for (j = 1; j <= i; ++j) cout << j;
            for (j = 1; j < n - 2 * i + 1 + odd; ++j) cout << i;
            for (j = i - odd; j >= 1; --j) cout << j;
            cout << endl;
        }
    }
    void PrintMatB2S(int n) {
        int pivot = (n + 1) / 2;
        int odd = n % 2;
        int i, j;

        for (i = pivot; i >= 1; --i) {
            for (j = pivot; j >= i; --j) cout << j;
            for (j = 1; j < 2 * i - 1; ++j) cout << i;
            for (j = i + odd; j <= pivot; ++j) cout << j;
            cout << endl;
        }
        for (i = 1 + odd; i <= pivot; ++i) {
            for (j = pivot; j >= i; --j) cout << j;
            for (j = 1; j < 2 * i - 1; ++j) cout << i;
            for (j = i + odd; j <= pivot; ++j) cout << j;
            cout << endl;
        }
    }
};

int main(int argc, char *argv[]) {
    MatrixDrawer drawer;
    drawer.PrintMatS2B(6);
    cout << endl;
    drawer.PrintMatS2B(7);
    cout << endl;
    drawer.PrintMatB2S(6);
    cout << endl;
    drawer.PrintMatB2S(7);
    cout << endl;
    drawer.PrintMatB2S(2);
    cout << endl;
    drawer.PrintMatB2S(3);
    cout << endl;
    drawer.PrintMatB2S(4);
    return 0;
}
