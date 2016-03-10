//
//  test.hpp
//  CppTrain
//
//  Created by Wanchao Liang on 2/20/16.
//  Copyright © 2016 Wanchao Liang. All rights reserved.
//

#include "funcs.inc"

#ifndef test_h
#define test_h


void knighadv_test() {
    
    int len = 0, width = 0;
    cin >>len >> width;
    
    vector<Point> obstacles;
    int startx = 0, starty = 0;
    int endx = 0, endy = 0;
    cin>>startx>>starty;
    cin>>endx>>endy;
    Point start(startx, starty);
    Point end(endx, endy);
    
    int nblock = 0;
    cin >> nblock;
    
    for (int i = 0; i < nblock; ++ i) {
        int x = 0, y = 0;
        cin>>x>>y;
        Point obs(x,y);
        obstacles.push_back(obs);
    }
        
    cout<<knightadv(len, width, start, end, obstacles);

}


void maxdigitproduct_test() {

    vector<int> vec {-4, 1, 2, 5, -3};
                             
    cout << maxdigitproduct(vec)<<endl;

}

void knight2_test() {
    
    vector<vector<char>> board1 {{'X', 'X', 'O', 'O'}, {'X', 'O', 'X', 'O'}, {'O', 'X', 'O', 'X'}, {'O', 'O', 'O', 'O'}};
    
     vector<vector<char>> board2 {{'X'}, {'O'}};
    
    cout << knight2(board2);
    
}

void findleast2power_test() {
	cout<<"find least 2 power test"<<endl;
	cout<<findleast2power(5)<<endl;

}

#endif /* test_h */
