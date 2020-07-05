# Constructing Roads In JGShining's Kingdom
##### algorithm: dichotomy + greedy + dp
##### author：bronyale
##### date：1月9日

## Promblem:
JGShining's kingdom consists of 2n(n is no more than 500,000) small cities which are located in two parallel lines.

Half of these cities are rich in resource (we call them rich cities) while the others are short of resource (we call them poor cities). Each poor city is short of exactly one kind of resource and also each rich city is rich in exactly one kind of resource. You may assume no two poor cities are short of one same kind of resource and no two rich cities are rich in one same kind of resource.

With the development of industry, poor cities wanna import resource from rich ones. The roads existed are so small that they're unable to ensure the heavy trucks, so new roads should be built. The poor cities strongly BS each other, so are the rich ones. Poor cities don't wanna build a road with other poor ones, and rich ones also can't abide sharing an end of road with other rich ones. Because of economic benefit, any rich city will be willing to export resource to any poor one.

Rich citis marked from 1 to n are located in Line I and poor ones marked from 1 to n are located in Line II.

The location of Rich City 1 is on the left of all other cities, Rich City 2 is on the left of all other cities excluding Rich City 1, Rich City 3 is on the right of Rich City 1 and Rich City 2 but on the left of all other cities ... And so as the poor ones.

But as you know, two crossed roads may cause a lot of traffic accident so JGShining has established a law to forbid constructing crossed roads.

In order to build as many roads as possible, the young and handsome king of the kingdom - JGShining needs your help, please help him.
 
## Input:
Each test case will begin with a line containing an integer n(1 ≤ n ≤ 500,000). Then n lines follis. Each line contains two integers p and r which represents that Poor City p needs to import resources from Rich City r. Process to the end of file.

## Output:
For each test case, output the result in the form of sample.
You should tell JGShining what's the maximal number of road(s) can be built. 

## Algorithsm:
道路的建设方法是每一个poor city连接一个rich city，并且input的内容中p（poor city 的序号）是从1到n，所以道路的是否相交取决于r（rich city的序号）   
将题目抽象化之后便是求解最小上升序列(longwst increasing subsquence)的长度   
LIS所属的原序列即由r的值构成的整型数组，~~至于为什么？只可意会,不可言传~~    

最小上升序列的求解方法有很多，最简单的是直接dp，但是复杂度是n^2。更优的算法是二分查找+贪心+动态规划   

新建一个 lis 数组，lis [ i ]表示长度为i的LIS结尾元素的最小值。对于一个上升子序列，显然其结尾元素越小，越有利于在后面接其他的元素，也就越可能变得更长。因此，我们只需要维护 lis 数组，对于每一个a[ i ]，如果a[ i ] > lis [当前最长的LIS长度]，就把 a [ i ]接到当前最长的LIS后面，即lis [++当前最长的LIS长度] = a [ i ]。    
那么，怎么维护 lis 数组呢？   
对于每一个a [ i ]，如果a [ i ]能接到 LIS 后面，就接上去；否则，就用 a [ i ] 取更新 lis 数组。   
具体方法是，在lis数组中找到第一个大于等于a [ i ]的元素lis [ j ]，用a [ i ]去更新 lis [ j ]。   
如果从头到尾扫一遍 lis 数组的话，时间复杂度仍是O(n^2)。我们注意到 lis 数组内部一定是单调不降的，所有我们可以二分 lis 数组，找出第一个大于等于a[ i ]的元素。二分一次 lis 数组的时间复杂度的O(lgn)，所以总的时间复杂度是O(nlogn)。   

但是值得注意的是：通过这种方法构建的lis并不是严格的最长上升序列，而是一种可变的可能情况。例如：对于序列A[ ] = 1 4 7 2 5 9 10 3来说，通过此算法得到的lis是：1 2 3 9 10，这明显不是正确的最长上升序列，但是如果元序列后面继续增加的话，我们得到的lis也会继续以最优的方式进行更新，这其中的缘由还需要仔细琢磨琢磨


## Code:
~~~ 
//Longest Increasing Sebsquence
#include <iostream>
#include <cmath>
#include <stack>

using namespace std;

#define N 1000
#define INF 0x3f3f3f3f

/*
//the basic algorithm with 'dichotomy and greedy method'
//the complexity of it is 'nlogn' 
int n = 8;
int a[] = {1, 4, 7, 2, 5, 9, 10, 3};
int  lis[N] = {-INF};  //to store the largest increasing subsquence

// to find the least one whitch is bigger than x with dichotomy
int search(int a[], int x, int l, int r){
    if(l >= r){
        return l;
    }
    int mid = (l + r) >> 1;
    if(a[mid] >= x){
        r = mid;
        return search(a, x, l, r)w;
    }else{
        l = mid +1;
        return search(a, x, l, r);
    }
}

//to build a longest increasing sebsquence with greedy method
//but it is not the strict longest increasing sebsquence but a fungible posibility
//or to say that it just presents the length of the real longest increasing sebsquence
int dp(int a[], int lis[]){
    int len = 0, i;
    lis[0] = a[0];
    for(i = 1; i < n; i ++){
        if(a[i] > lis[len]){
            lis[++ len] = a[i];
        }else{
            lis[search(lis, a[i], 0, len)] = a[i];
        }
    }
    return len + 1;
}

int main(){

    int ans = dp(a, lis);
    cout << ans << endl;

    return 0;
}*/

//the next is the answer to the problem
int n;
int ans = 0;
int a[N], lis[N];

int search(int a[], int x, int l, int r){
    if(l >= r){
        return l;
    }
    int mid = (l + r) >> 1;
    if(a[mid] >= x){
        r = mid;
        return search(a, x, l, r);
    }else{
        l = mid +1;
        return search(a, x, l, r);
    }
}

int dp(int a[], int lis[]){
    int len = 0, i;
    lis[0] = a[0];
    for(i = 1; i < n; i ++){
        if(a[i] > lis[len]){
            lis[++ len] = a[i];
        }else{
            lis[search(lis, a[i], 0, len)] = a[i];
        }
    }
    return len + 1;
}

int main(){

    int i, j;
    int x, y;
    int cnt = 1;
    //x is the sequence of the poor city and the y represents the rich city
    while(cin >> n){
        for(i = 0; i < n; i ++){
            cin >> x >> y;
            a[i] = y;  //considering that the x is from 1 to n, we only need to consider the y
        }
        ans = dp(a, lis);
        // cout << ans << endl;
        if(ans==1){
            cout << "My king, at most 1 road can be built." << endl;
        }   
        else {
            cout << "My king, at most" << ans <<  "roads can be built." << endl;
        }
    }

    return 0;
}
~~~

