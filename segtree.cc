#include "utils.h"

// segment tree for sum of given range
class SegTree {
   public:
    SegTree(int inputvec[], int n);
    SegTree() = default;
    ~SegTree();

    int GetSum(int, int);
    void update(int[], int, int);

   private:
    int *vals;
    int n;

    int RecursiveBuild(int[], int, int, int);
    int RecursiveFind(int, int, int, int, int);
    void RecursiveUpdate(int, int, int, int, int);
};

SegTree::SegTree(int inputvec[], int n) {
    this->n = n;

    int x = (int)(ceil(log(n) / log(2)));
    int max_size = 2 * (int)pow(2, x) - 1;

    vals = new int[max_size];

    RecursiveBuild(inputvec, 0, n - 1, 0);
}

SegTree::~SegTree() { delete[] vals; }

int SegTree::RecursiveBuild(int input[], int start, int end, int index) {
    if (start == end) {
        vals[index] = input[end];
        return vals[index];
    }

    int mid = start + (end - start) / 2;

    vals[index] = RecursiveBuild(input, start, mid, 2 * index + 1) +
                  RecursiveBuild(input, mid + 1, end, 2 * index + 2);
    return vals[index];
}

int SegTree::RecursiveFind(int s, int e, int start, int end, int index) {
    if (s >= start && e <= end) {
        return vals[index];
    }

    if (start > e || end < s) return 0;

    int mid = s + (e - s) / 2;

    return RecursiveFind(s, mid, start, end, 2 * index + 1) +
           RecursiveFind(mid + 1, end, start, end, 2 * index + 2);
}

int SegTree::GetSum(int start, int end) {
    if (start < 0 || end > n - 1 || start > end) {
        return -1;
    }

    return RecursiveFind(0, n - 1, start, end, 0);
}

void SegTree::RecursiveUpdate(int start, int end, int i, int diff, int index) {
    if (i < start || i > end) {
        return;
    }

    vals[index] += diff;

    if (end != start) {
        int mid = start + (end - start) / 2;
        RecursiveUpdate(start, mid, i, diff, 2 * index + 1);
        RecursiveUpdate(mid + 1, end, i, diff, 2 * index + 2);
    }
}

void SegTree::update(int arr[], int index, int val) {
    if (index < 0 || index > n - 1) {
        cout << "invalid input" << endl;
        return;
    }

    int diff = val - arr[index];
    arr[index] = val;

    RecursiveUpdate(0, n - 1, index, diff, 0);
}

int main(int argc, char *argv[]) {
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Build segment tree from given array
    SegTree segtree(arr, n);

    // Print sum of values in array from index 1 to 3
    printf("Sum of values in given range = %d\n", segtree.GetSum(1, 3));

    // Update: set arr[1] = 10 and update corresponding
    // segment tree nodes
    segtree.update(arr, 1, 10);

    // Find sum after the value is updated
    printf("Updated sum of values in given range = %d\n", segtree.GetSum(1, 3));
    return 0;
}
