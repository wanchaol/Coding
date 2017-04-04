#include <atomic>
#include <thread>
#include "../utils.h"

void dot_product(vector<int> &v1, vector<int> &v2, atomic<int> &result, int L,
                 int R) {
    int partial_sum = 0;

    for (int i = L; i < R; ++i) {
        partial_sum += v1[i] * v2[i];
    }
    result += partial_sum;
}

vector<int> bounds(int parts, int range) {
    vector<int> res;

    int num_in_parts = range / parts;

    for (int i = 0; i <= range; i += num_in_parts) {
        res.push_back(i);
    }

    return res;
}

int main(void) {
    int nr_elements = 100000;
    int nr_threads = 4;

    atomic<int> result(0);

    vector<thread> threads;

    vector<int> v1(nr_elements, 1), v2(nr_elements, 2);

    vector<int> limits = bounds(nr_threads, nr_elements);

    for (int i = 0; i < nr_threads; ++i) {
        threads.push_back(thread(dot_product, ref(v1), ref(v2), ref(result),
                                 limits[i], limits[i + 1]));
    }

    for (auto &t : threads) {
        t.join();
    }

    cout << result << endl;

    return 0;
}
