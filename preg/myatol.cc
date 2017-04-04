#include "../utils.h"
#define CATCH_CONFIG_MAIN
#include "../catch.hpp"

signed long long parseLong(string str) {
    int i = 0;

    unsigned long long res = 0;
    int sign = 1;

    if (str[i] == '-') {
        sign = -1;
        ++i;
    } else if (str[i] == '+') {
        ++i;
    }

    while (i < str.size()) {
        if (!isdigit(str[i])) {
            throw exception();
        }

        res = 10 * res + (str[i++] - '0');
        if (res > LLONG_MAX) {
            throw exception();
        }
    }

    cout << sign << " " << res << endl;
    return sign * res;
}

long StringToLong(string s) {
    long res = 0;
    int sign = 1;

    int i = 0;

    if (s[i] == '-') {
        sign = -1;
        ++i;
    } else if (s[i] == '+') {
        ++i;
    }
    while (isdigit(s[i])) {
        res = 10 * res + (s[i++] - '0');
        if (sign * res >= INT_MAX) {
            return INT_MAX;
        } else if (sign * res <= INT_MIN) {
            return INT_MIN;
        }
    }

    return sign * res;
}

TEST_CASE("normal", "[StringToLong]") {
    string s = "12345";
    REQUIRE(StringToLong(s) == 12345);
}

TEST_CASE("empty space", "[StringToLong]") {
    string s = "12345";
    REQUIRE(StringToLong(s) == 12345);
}
