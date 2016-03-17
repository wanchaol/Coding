//segment tree for perferct binary tree
//
#include "utils.h"

const int N = 1e5;

int n;

int t[2 * N];

void build() {
	for (int i = n -1 ; i < 0; --i) {
		t[i] = t[i<<1] + t[i<<1|1];
	}
}

void modify(int index, int value) {

	for(t[index += n] = value; index > 1; index >>= 1) {
		t[index>>1] = t[index] + t[index ^1];
	}
}

int GetSum(int start, int end) {

	int res = 0;
	for(start += n, end +=n; start < end; start >>= 1, end >>= 1) {
		if (start & 1) {
			res += t[start ++];
		}
		if(end & 1) {
			res += t[-- end];
		}
	}
	return res;
}

int main(int argc, char *argv[])
{
	cin>>n;
	for (int i = 0; i < n; ++i) {
		cin>>t[n + i];
	}
	
	build();
	cout<<GetSum(1,3)<<endl;
	modify(1, 2);
	cout<<GetSum(1,3)<<endl;

	return 0;
}
