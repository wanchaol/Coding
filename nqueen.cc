#include "utils.h"


class Solution {
private:
    int boardsize;

    bool IsSafe(int row, int col, vector<bool> &colempty, vector<bool> &updiagempty, vector<bool> &downdiagempty) {
        return colempty[col] && updiagempty[row + col] && downdiagempty[boardsize-1 + row - col];    
    }
    
    void PlaceQueen(vector<string> &queenOnBoard, int row, int col, vector<bool> &colempty, vector<bool> &updiagempty, vector<bool> &downdiagempty) {
        queenOnBoard[row][col] = 'Q';
        colempty[col] = false;
        updiagempty[row + col] = false;
        downdiagempty[boardsize - 1 + row - col] = false;
        
    }
    void RemoveQueen(vector<string> &queenOnBoard, int row, int col, vector<bool> &colempty, vector<bool> &updiagempty, vector<bool> &downdiagempty) {
        queenOnBoard[row][col] = '.';
        colempty[col] = true;
        updiagempty[row + col] = true;
        downdiagempty[boardsize - 1 + row - col] = true;
        
    }
    
    void Solver(vector<string> &queenOnBoard, vector<bool> &colempty, vector<bool> &updiagempty, vector<bool> &downdiagempty, int row, vector<vector<string>> &res) {
        
        if(row == boardsize) {
            res.push_back(queenOnBoard);
            return;
        }
        
        for(int col = 0; col < boardsize; ++ col) {
            
            if(IsSafe(row, col, colempty, updiagempty, downdiagempty)) {
                PlaceQueen(queenOnBoard, row, col, colempty, updiagempty, downdiagempty);
                Solver(queenOnBoard, colempty, updiagempty, downdiagempty, row + 1, res);
                RemoveQueen(queenOnBoard, row, col, colempty, updiagempty, downdiagempty);    
                    
            }
                
                
            
        }
    }
    
public:
    
    vector<vector<string>> solveNQueens(int n) {
        boardsize = n;
        
        vector<bool> colempty(n, true);
        vector<bool> updiagempty(2*n-1, true);
        vector<bool> downdiagempty(2*n-1, true); 
        vector<vector<bool>> queenOnSquare(n, vector<bool>(n, false));
        
        vector<vector<string>> res;
        vector<string> queenOnBoard(boardsize, string(boardsize, '.'));
        
        Solver(queenOnBoard, colempty, updiagempty, downdiagempty, 0, res);
        
        return res;
    }
};
