//
//  funcs.hpp
//  CppTrain
//
//  Created by Wanchao Liang on 1/27/16.
//  Copyright © 2016 Wanchao Liang. All rights reserved.
//

#ifndef funcs_h
#define funcs_h

int frogjump(vector<int> &A, int X, int D) {
    // write your code in C++11 (g++ 4.8.2)
    if(X <= D)
        return 0;
    
    int nranges = (X/D) + 1;
    
    vector<int> maxrange(nranges, INT_MIN);
    vector<int> minrange(nranges, INT_MAX);
    
    maxrange[0] = 0;
    minrange[0] = 0;
    maxrange[nranges - 1] = X;
    minrange[nranges - 1] = X;
    
    int needconnect = nranges - 1;
    
    for(int i = 0; i < (int)A.size(); ++ i) {
        
        int ind = A[i]/nranges;
        
        if(A[i] <= maxrange[ind] && A[i] >= minrange[ind])
            continue;
        
        int nextmin = 0;
        
        if(ind == nranges -1)
            nextmin = INT_MAX;
        else
            nextmin = minrange[ind + 1];
        
        int prevmax = 0;
        
        if(ind == 0)
            prevmax = INT_MIN;
        else
            prevmax = maxrange[ind - 1];
        
        bool failnext = (minrange[ind] > maxrange[ind])? true: minrange[ind] - prevmax > D;
        bool failprev = (minrange[ind] > maxrange[ind])? true: nextmin - maxrange[ind] > D;
        
        if(A[i] - prevmax <= D && failnext) {
            -- needconnect;
        }
        
        if(nextmin - A[i] <= D && failprev) {
            -- needconnect;
        }
        
        
        if(A[i] > maxrange[ind])
            maxrange[ind] = A[i];
        if(A[i] < minrange[ind])
            minrange[ind] = A[i];
        
        if(needconnect == 0)
            return i;
        
    }
    
    return -1;
    
}

int maxDiff(vector<int> &A) {
    
    int minEle = INT_MAX;
    int maxDiff = 0;
    
    for (int i = 0; i < A.size(); ++ i) {
        minEle = min(minEle, A[i]);
        maxDiff = max(maxDiff, A[i] - minEle);
    }
    
    if (maxDiff == 0) {
        return -1;
    }
    
    return maxDiff;
}





string leavecomments(string prog) {
    string res;
    
    bool singlecomment = false;
    bool multicomment = false;
    
    
    for(int i = 0; i < prog.size(); ++i) {
        
        if (singlecomment && prog[i] == '\n') {
            res += prog[i];
            singlecomment = false;
        }
        else if(multicomment && prog[i] == '/' && prog[i+1] == '*') {
            res += prog[i];
            res += prog[i+1];
            ++i;
        }
        else if(singlecomment || multicomment) {
            res += prog[i];
        }
        else if(prog[i] == '/' && prog[i+1] == '/') {
            res += prog[i];
            res += prog[i+1];
            singlecomment = true;
            ++ i;
        }
        else if(prog[i] == '/' && prog[i+1] == '*') {
            res += prog[i];
            res += prog[i+1];
            multicomment = true;
            ++ i;
        }
        
        
    }
    
    
    return res;
}

int ksub(vector<int> &A, int n, int k) {
    
    if(n == 0)
        return 0;
    
    sort(A.begin(), A.end());
    
    int sum = A[0];
    int len = 1;
    int count = 0;
    
    for (int i = 1; i < A.size(); ++ i) {
        
        if(A[i] - A[i-1] == 1) {
            sum+= A[i];
            len ++;
            
            if (sum %k == 0) {
                ++ count;
            }
            
            continue;
        }
        else if(A[i] == A[i-1]) {
            continue;
        }
        else {

            sum = A[i];
            len = 1;
            
        }
    }
    
    return count;
}


bool findpath(TreeNode *root, TreeNode *p, vector<TreeNode *> &path) {
    if (root == nullptr) {
        return false;
    }
    
    path.push_back(root);
    
    if (root == p) {
        return true;
    }
    
    // Check if p is found in left or right sub-tree
    if ((root->left && findpath(root->left, p, path))||(root->right && findpath(root->right, p, path)) ) {
        return true;
    }
    
    // If not present in subtree rooted with root, remove root from
    // path[] and return false
    path.pop_back();
    return false;
}

TreeNode *findLCA(TreeNode *root, TreeNode *p, TreeNode *q) {
    vector<TreeNode *> ppath, qpath;
    
    if ((!findpath(root, p, ppath)) || (!findpath(root, q, qpath))) {
        return nullptr;
    }
    
    int i;
    
    for (i = 0; i < ppath.size() && i < qpath.size(); i++) {
        if(ppath[i] != qpath[i])
            break;
    }
    
    return ppath[i-1];
}


string permuteseq(int n, long long m) {
    string res;
    vector<int> seq;
    vector<int> factors(n, 1);
    
    for (int i = 0; i < n; ++i) {
        seq.push_back(i);
        
        if(i == 0) {
            factors[0] = 1;
        }
        else {
            factors[i] = i * factors[i - 1];
        }
    
    }
    
    for (int i = n; i > 0; -- i) {
        
        ssize_t ind = m/factors[i-1];
        m = m%factors[i-1];
        res += to_string(seq[ind]) + " ";
        seq.erase(seq.begin() + ind);
    }
    
    return res;
    
}

TreeNode* recursivebuild(vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd, int inStart, int inEnd) {
    if(preStart>preEnd || inStart > inEnd) {
        return nullptr;
    }
    
    int val = preorder[preStart];
    TreeNode *root = new TreeNode(val);
    
    int k = 0;
    for(int i = inStart; i <= inEnd; i++) {
        if(inorder[i] == val) {
            k = i;
            break;
        }
    }
    
    
    root->left = recursivebuild(preorder, inorder, preStart+1, preStart + (k-inStart), inStart, k-1);
    root->right = recursivebuild(preorder, inorder, preStart + (k-inStart) + 1, preEnd, k+1, inEnd);
    
    return root;
}

void postdfs(TreeNode *root, vector<int> &postorder) {
    
    if(root == nullptr)
        return;
    
    postdfs(root->left, postorder);
    postdfs(root->right, postorder);
    postorder.push_back(root->val);
    
}

vector<int> BSTpreTopost(vector<int>& preorder) {
    vector<int> postorder;
    
    vector<int> inorder(preorder);
    
    sort(inorder.begin(), inorder.end());
    
    int prestart = 0;
    int preend = (int)preorder.size() - 1;
    int instart = 0;
    int inend = (int)inorder.size() - 1;
    
    TreeNode *bst = recursivebuild(preorder, inorder, prestart, preend, instart, inend);
    
    postdfs(bst, postorder);
    
    return postorder;
}

int knightadv(size_t m, size_t n, Point start, Point end, vector<Point> obstacles) {
    
//    size_t m = board.size();
//    size_t n = board[0].size();
    
    int minsteps = 0;
    
    vector<Point> dirs {{2,1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {-1, 2}, {1, -2}, {-1, -2}};
    
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    queue<Point> q;
    
    for(auto obs: obstacles) {
        visited[obs.x][obs.y] = true;
    }
    
    visited[start.x][start.y] = true;
//    visited[end.x][end.y] = true;

    q.push(start);
    
    while(!q.empty()) {
        ++ minsteps;
        size_t level = q.size();
        
        for(int i = 0; i < level; ++i) {
            Point p = q.front();
            q.pop();
            
            for(auto dir: dirs)  {
                Point new_p(p.x + dir.x, p.y + dir.y);
                
                if(new_p.x < 0 || new_p.y < 0 || new_p.x >= m || new_p.y >= n)
                    continue;
                else if(visited[new_p.x][new_p.y])
                    continue;
                else if(new_p.x == end.x && new_p.y == end.y){
                    return minsteps;
                }
                else {
                    visited[new_p.x][new_p.y] = true;
                    q.push(new_p);
                }
                
            }
            
        }
        
    }
    
    return minsteps;
}


TreeNode *randomnode(TreeNode *root) {
    TreeNode *selectnode = root;
    queue<TreeNode*> q;
    q.push(root);
    int count = 1;
    
    while (!q.empty()) {
        TreeNode *node = q.front();
        q.pop();
        
        if (rand() <  1.0/count) {
            selectnode = node;
        }
        
        if(node->left) {
            q.push(node->left);
        }
        if(node->right) {
            q.push(node->right);
        }
        count ++;
    }
    return selectnode;
}


int maxdigitproduct(vector<int> &nums) {
    
    int maxproduct = INT_MIN;
    int maxposele = nums[nums.size()-1];
    int minnegele = nums[nums.size()-1];
    
    for (ssize_t i = nums.size() - 1; i >= 0; -- i) {
        int cur = nums[i];
        
        if (cur > maxposele) {
            maxposele = cur;
            continue;
        }
        if (cur <= maxposele){
            if (cur * maxposele > maxproduct) {
                maxproduct = cur * maxposele;
            }
        }
        if(cur < minnegele) {
            if(cur * minnegele > maxproduct) {
                maxproduct = cur * minnegele;
            }
            minnegele = cur;
        }
        
    }
    
    return maxproduct;
}




bool ifupper(vector<vector<char>> &board, int i, int j) {
    
    if(i == 0)
        return true;
    
    if(board[i-1][j] == 'O') {
        if(ifupper(board, i-1, j))
            return true;
    }
    
    if(j > 0 && board[i-1][j-1] == 'X') {

        if(ifupper(board, i - 1, j - 1))
            return true;
    }
    
    if(j < board[i-1].size()-1 && board[i-1][j-1] == 'X') {
        
        if (ifupper(board, i - 1, j + 1))
            return true;
    }
        
   
    return false;
    
}

bool knight2(vector<vector<char>> &board) {
    
    size_t numcols = board[0].size();
    
    for (int j = 0; j < numcols; ++ j) {
        if(ifupper(board, (int)board.size(), j))
            return true;
    }
    return false;
    
}


#endif /* funcs_h */
