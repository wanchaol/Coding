#include "utils.h"

//my solution, a bit long to debug the correct orz...
//
string fractionToDecimal(int numerator, int denominator) {
	long num = static_cast<long>(numerator);
	long denom = static_cast<long>(denominator);
	unordered_map<long, int> umap;
	string res;
	bool rep = false;
	int insertpos = 0;

	long firstdiv = num/denom;

	if((num > 0 && denom < 0) || (num < 0 && denom > 0)) {
		res += "-" + to_string(abs(firstdiv));
	}
	else {
		res += to_string(abs(firstdiv));
	}

	long rem = num%denom;

	if(rem != 0) {
		insertpos = res.size();
		res += ".";
	}
	// else if(res < 0) {
	//     res = -res;
	// }

	int pos = insertpos;
	while(rem != 0) {

		long div = (rem * 10) / denom;

		if(umap.count(rem)) {
			rep = true;
			res += ")";
			insertpos = umap[rem];
			break;
		}
		else {
			umap[rem] = pos;
			res += to_string(abs(div));
		}
		rem = (rem * 10) % denom;
		pos ++;

	}

	if(rep)
		res.insert(insertpos + 1, "(");

	return res;

}


//elegant solution! should learn how to write in this way!!!
//
string fractionToDecimal(int64_t n, int64_t d) {
	// zero numerator
	if (n == 0) return "0";

	string res;
	// determine the sign
	if (n < 0 ^ d < 0) res += '-';

	// remove sign of operands
	n = abs(n), d = abs(d);

	// append integral part
	res += to_string(n / d);

	// in case no fractional part
	if (n % d == 0) return res;

	res += '.';

	unordered_map<int, int> map;

	// simulate the division process
	for (int64_t r = n % d; r; r %= d) {

		// meet a known remainder
		// so we reach the end of the repeating part
		if (map.count(r) > 0) {
			res.insert(map[r], 1, '(');
			res += ')';
			break;
		}

		// the remainder is first seen
		// remember the current position for it
		map[r] = res.size();

		r *= 10;

		// append the quotient digit
		res += to_string(r / d);
	}

	return res;
}


