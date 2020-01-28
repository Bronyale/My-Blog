# Combination Problem
##### algorithm: trace_back
##### author：bronyale
##### date：1月28日   
## Problem:   
List all kinds of combinations constructed of 3 of the 5 digits 
## Input:    
NULL
## Output:
each line consists a kind of possible combination
## Algorithm:
全排列问题是回溯法的另一个应用，与八皇后问题类似但不完全相同，全排列的算法思想也是先处理当前位置，之后以此为基准，往下处理   
当所有深度处理结束，溯回当前深度，并更改当前深度的值，然后继续深搜   
所以与其说是回溯，它更是接近于标准的深搜   
~~所以我但现在还是不知道为什么老师当时把它归为回溯法的例题~~   
我下面的代码中包含两种组合：无重组合和有重组合，但其实两种组合的算法大同小异，只有细微的区别
~~~
//trace_back
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

#define N 1000
#define ll long long
#define INF 0x3f3f3f3f

int a[N];
int n = 5, k = 3;  //make an example:combinations of three of five digits of numbers

// regular combinations
//as to say the combinations not allowed the exisitence of dupications
void dfs1(int sta, int dep){
    int i;
    //if the strength of the sequence has been equal to the 'k', print the sequence of this combination
    if(dep >= k){
        for(i = 0; i < k; i ++){
            cout << a[i] << " ";
        }
        cout << endl;
        return;
    }
    //build a loop to set a[dep] to a digit from 1 to 'n' 
    //and then operate the next 'dep' untill the dep reach 'k'
    for(i = sta + 1; i <= n; i ++){
        a[dep] = i;
        dfs1(i, dep + 1);
    }
}

//duplicate combinations
void dfs2(int sta, int dep){
    int i;
    if(dep >= k){
        for(i = 0; i < k; i ++){
            cout << a[i] << " ";
        }
        cout << endl;
        return;
    }
    //int each loop, the new 'sta' is equal to the prior one
    //as the result, duplication could exsists
    for(i = sta; i <= n; i ++){
        a[dep] = i;
        dfs2(i, dep + 1);;
    }
}

int main(){
    cout << "regular combination : " << endl;
    dfs1(0, 0);
    memset(a, 0, sizeof(a));
    cout << "duplicate combinatio : " << endl;
    dfs2(1, 0);

    return 0;
}
~~~