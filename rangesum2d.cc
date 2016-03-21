#include "utils.h"

class NumMatrix {
	private:
		int row, col;
		vector<vector<int>> sums;
	public:
		NumMatrix(vector<vector<int>> &matrix) {
			row = matrix.size();
			col = row>0 ? matrix[0].size() : 0;
			sums = vector<vector<int>>(row+1, vector<int>(col+1, 0));
			for(int i=1; i<=row; i++) {
				for(int j=1; j<=col; j++) {
					sums[i][j] = matrix[i-1][j-1] + 
						sums[i-1][j] + sums[i][j-1] - sums[i-1][j-1] ;
				}
			}
		}

		int sumRegion(int row1, int col1, int row2, int col2) {
			return sums[row2+1][col2+1] - sums[row2+1][col1] - sums[row1][col2+1] + sums[row1][col1];
		}
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);
//class NumMatrix {
//vector<vector<int>> sums;

//public:

//NumMatrix(vector<vector<int>> &matrix) {

//int m = matrix.size();
//if(m == 0 || matrix[0].size() == 0)
//return;
//int n = matrix[0].size();

//sums.resize(m);
//for (int i = 0; i < m; ++i) {
//sums[i].resize(n);
//}

//sums[0][0] = matrix[0][0];

//for(int i = 1; i < m; ++ i) {
//sums[0][i] += sums[0][i-1] + matrix[0][i];
//sums[i][0] += sums[i-1][0] + matrix[i][0];
//}

//for(int i = 1; i < m ; ++ i) {
//for(int j = 1; j < n; ++ j) {
//sums[i][j] = sums[i][j - 1] + sums[i - 1][j] - sums[i-1][j-1] + matrix[i][j];
//}

//}

//}

//int sumRegion(int row1, int col1, int row2, int col2) {
//if(sums.size() == 0)
//return 0;

//if(row1 == 0 && col1 == 0) {
//return sums[row2][col2];
//}
//else if(row1 == 0) {
//return sums[row2][col2] - sums[row2][col1-1];
//}
//else if(col1 == 0) {
//return sums[row2][col2] - sums[row1 - 1][col2];
//}
//else {
//return sums[row2][col2] + sums[row1 - 1][col1 - 1] - sums[row1-1][col2] - sums[row2][col1 - 1]; 
//}
//}

//void printsums() {
//for (auto item : sums) {
//cout<<item<<endl;
//}

//}
//};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);
int main(int argc, char *argv[])
{

	//vector<vector<int>> matrix;

	vector<vector<int>> matrix = {
		{3, 0, 1, 4, 2},
		{5, 6, 3, 2, 1},
		{1, 2, 0, 1, 5},
		{4, 1, 0, 1, 7},
		{1, 0, 3, 0, 5}
	};

	NumMatrix numMatrix(matrix);
	//numMatrix.printsums();
	//cout<< numMatrix.sumRegion(0, 1, 2, 3) <<endl;

	cout<< numMatrix.sumRegion(2, 1, 4, 3) <<endl;
	cout<< numMatrix.sumRegion(1, 1, 2, 2) <<endl;
	cout<< numMatrix.sumRegion(1, 2, 2, 4) <<endl;

	return 0;
}
