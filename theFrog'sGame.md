# Constructing Roads In JGShining's Kingdom
##### algorithm: dichotomy on answer
##### author：bronyale
##### date：1月23日

## Promblem:   
The annual Games in frogs' kingdom started again. The most famous game is the Ironfrog Triathlon. One test in the Ironfrog Triathlon is jumping. This project requires the frog athletes to jump over the river.     
The width of the river is L (1<= L <= 1000000000). There are n (0<= n <= 500000) stones lined up in a straight line from one side to the other side of the river.    
The frogs can only jump through the river, but they can land on the stones. If they fall into the river, they
are out.The frogs was asked to jump at most m (1<= m <= n+1) times.   
 Now the frogs want to know if they want to jump across the river, at least what ability should they have. (That is the frog's longest jump distance). 

 ## Input:   
 The input contains several cases. The first line of each case contains three positive integer L, n, and m.
Then n lines follow. Each stands for the distance from the starting banks to the nth stone, two stone appear in one place is impossible. 

## Output:   
For each case, output a integer standing for the frog's ability at least they should have. 

## Algorithm:   
二分答案，最核心的是judge()函数的编写。   
本题中有一个技巧：在search()之前找到一个min的值，即任一两块石头之间的最长距离，或者说青蛙的对端弹跳距离。找到这个距离之后，judge()中就不用考虑能不能跳过去的问题，只需考虑次数是否超出规定次数。

## Code:   
~~~
//dichotomy on answer
#include <iostream>
#include <algorithm>

using namespace std;

#define N 500003

int L, n, m;
int ans;
int a[N];

int judge(int x){
    int ans = 0;
    int pos = 0;
    for(int i = 1;i <= n;i ++){
        if(a[i] - a[pos] <=x && a[i+1] - a[pos] > x){  //to find the farrest stone that the frog can jump to
            ans ++;
            pos = i;  //update the position
        }
    }
    ans ++;  //to jump to the paradise
    if(ans <= m){
        return 1;
    }else{
         return 0;
    }
}

int search(int l, int r){
    if(l == r){
        return l;
    }
    int mid = (l + r) >> 1;
    // cout << l << " " << r << " " << mid  << endl;
    if(judge(mid)){
        // cout << "Yes" << endl;
        return search(l , mid);
    }else{
        // cout << "No" << endl;
        return search(mid + 1, r);
    }
}

int main(){
    int i, j;
    while(cin >> L >> n >> m){
        a[0] = 0;
        for(i = 1; i <= n; i ++){
            cin >> a[i];
        }
        a[n + 1] = L;  //the destinition is the paradise
        sort(a, a + n);
        // for(j = 0; j <= n + 1; j ++){
        //     cout << a[j] << endl;
        // }

        int min;  //the 'min' stands for the shortest distence to jump,as to say it's the longest distence between any two stones
        for(int i=1;i<=n+1;i++){
            if(a[i]-a[i-1] > min)
                min = a[i] - a[i-1];
        }
        ans = search(min, L);
        cout << ans << endl;
    }
    return 0;
}
~~~