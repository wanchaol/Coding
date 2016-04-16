#include "utils.h"

double median(double *p, int n) {

	std::sort(p, p+ n);

	if(n % 2 != 0) {
		int index = (n + 1)/2 -1; 
		return *(p + index);

	}
	else {
		int index1 = (n/2)-1;
		int index2 = n/2;
		return (*(p+ index1) + *(p + index2))/2;
	}

}
