#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/*
 * Complete the function below.
 */

bool isComplex(string word, set<string> dict) {
    queue<int> Q;
    set<int> visited;

    Q.push(0);

    while (!Q.empty()) {
        int sind = Q.front();
        Q.pop();

        if (visited.count(sind)) {
            visited.insert(sind);
            for (int i = sind; i < word.size(); ++i) {
                string sub(word, sind, i - sind + 1);
                if (dict.count(sub)) {
                    Q.push(i + 1);

                    if (i + 1 == word.size()) return true;
                }
            }
        }
    }

    return false;
}

vector<string> simpleWords(vector<string> words) {
    vector<string> res;

    set<string> dict;

    for (auto word : words) {
        dict.insert(word);
    }

    for (auto word : words) {
        if (!isComplex(word, dict)) {
            res.push_back(word);
        }
    }

    return res;
}

int main() {
    ofstream fout("");
    vector<string> res;

    int _words_size = 0;
    cin >> _words_size;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    vector<string> _words;
    string _words_item;
    for (int _words_i = 0; _words_i < _words_size; _words_i++) {
        getline(cin, _words_item);
        _words.push_back(_words_item);
    }

    res = simpleWords(_words);
    for (int res_i = 0; res_i < res.size(); res_i++) {
        fout << res[res_i] << endl;
        ;
    }

    fout.close();
    return 0;
}
