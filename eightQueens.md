# Eight Queens Problem
##### algorithm: trace_back
##### author：bronyale
##### date：1月12日   
## Problem:
The eight queens problem was proposed by gauss, a famous 19th-century mathematician, in 1850. The problem: put eight queens on an 8-by-8 board so they can't attack each other. That is, no two queens can be in the same row, column, or slash.   
It is possible to extend the eight queens problem to the n queens problem by placing n queens on an n by n chessboard so that no two queens can attack each other   
## Input:
The input file only contains one row including the number of the rows of the checkbroad
## Output:
The output only needs to give the number of the possoble probilities of the example
## Algorithm:
典型的八皇后问题，使用回溯法直接解决   
当确定了当前行的放置位置，调用check函数判断当前放置是否满足条件，若满足，则继续下一行的操作，否则更改当前位置   
当结束深搜时，返回当前行的上一行，更改其位置，并继续深搜   
每一次深搜结束时，若当前行数等于棋盘行数，即每一行都放置了一个皇后，ans + 1，最后的ans就是所有可能性的总个数   
至于check()函数，在我看来是回溯的核心，需要因情况而定，对本题来说就是让当前行的皇后和之前行的不冲突，即不能同行，同列，同斜线 &nbsp; ~~呵，女人!~~
## Code:
~~~
//trace_back
//classical problem 'eight_queens' 
#include <iostream>
#include <cmath>

using namespace std;

#define N 100

int n;
int c[N];
int ans = 0;

bool check(int curRow){
    for(int preRow = 0; preRow < curRow; preRow ++){
        if(c[preRow] == c[curRow] || curRow - c[curRow] == preRow - c[preRow] ||curRow + c[curRow] == preRow + c[preRow]){
            return false;
        }
    }
    return true;
}

void queen(int row){
    if(row == n){
            ans ++;
    }else{
        for(int col = 1; col <= n; col ++){
                c[row] = col;
                if(check(row)){
                        queen(row + 1);
                }
        }
    }
}

int main(){
    cin >> n;
    queen(0);
    cout << ans << endl;
    return 0;
}
~~~