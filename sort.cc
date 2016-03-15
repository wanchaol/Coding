#include "utils.h"

void quicksort(vector<int> &vec, int start, int end) {

	int i = start;
	int j = end;
	int pivot = vec[(start + end)/2];

	while (i <= j) {
		while (vec[i] < pivot) {
			++ i;
		}
		while (vec[j] > pivot) {
			-- j;
		}

		if (i <= j) {
			swap(vec[i], vec[j]);
			++ i;
			-- j;
		}
	}

	if (start < j) {
		quicksort(vec, start, j );
	}
	if (i < end) {
		quicksort(vec, i, end);
	}

}

void merge(vector<int> &vec, int start, int pivot, int end) {
	
	int sublen1 = pivot - start + 1;
	int sublen2 = end - pivot;

	vector<int> subvec1(sublen1);
	vector<int> subvec2(sublen2);

	copy(vec.begin() + start, vec.begin() + pivot  + 1, subvec1.begin());
	cout<<subvec1<<endl;

	copy(vec.begin() + pivot + 1, vec.begin() + end + 1, subvec2.begin());
	cout<<subvec2<<endl;


	int i = 0; 
	int j = 0;
	int k = start;

	while (i < sublen1 && j < sublen2) {

		if (subvec1[i] <  subvec2[j]) {
			vec[k] = subvec1[i];
			++ i;
			++ k;
		}
		else {
			vec[k] = subvec2[j];
			++ j;
			++ k;
			
		}
		
	}


	while (i < sublen1) {
		vec[k] = subvec1[i];
		++ i;
		++ k;
	}

	while (j < sublen2) {
		vec[k] = subvec2[j];
		++ j;
		++ k;
	}

}

void mergesort(vector<int> &vec, int start, int end) {

	if (start >= end) {
		return;
	}

	int pivot = start + (end - start)/2;

	mergesort(vec, start, pivot);
	mergesort(vec, pivot + 1, end);
	merge(vec, start, pivot, end);

}

int main(int argc, char *argv[])
{
	vector<int> vec{5,2,6,1};
	
	cout<<"before sort: " << vec<<endl;

	//quicksort(vec, 0, vec.size() - 1);
	mergesort(vec, 0, vec.size() - 1);
	cout<< "after sort: " << vec<<endl;

	return 0;
}
