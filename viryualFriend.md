# Virtual Friend
##### algorithm: union-find + map
##### author：bronyale
##### date：1月11日

## Promblem:   
These days, you can do all sorts of things online. For example, you can use various websites to make virtual friends. For some people, growing their social network (their friends, their friends' friends, their friends' friends' friends, and so on), has become an addictive hobby. Just as some people collect stamps, other people collect virtual friends.   
Your task is to observe the interactions on such a website and keep track of the size of each person's network.   
Assume that every friendship is mutual. If Fred is Barney's friend, then Barney is also Fred's friend.    
## Input:   
Input file contains multiple test cases.
The first line of each case indicates the number of test friendship nest.
each friendship nest begins with a line containing an integer F, the number of friendships formed in this frindship nest, which is no more than 100 000. Each of the following F lines contains the names of two people who have just become friends, separated by a space. A name is a string of 1 to 20 letters (uppercase or lowercase).    
## Output:   
Whenever a friendship is formed, print a line containing one integer, the number of people in the social network of the two people who have just become friends.    
## Algorithsm:
这道题的核心思想就是并查集，而且解题思路和并查集的模板题差不多(并查集的模板请参考：[并查集](https://github.com/Bronyale/My-Blog/blob/master/%E5%B9%B6%E6%9F%A5%E9%9B%86.md))   
但由于输入格式不同，本体选用了map的方法存放每一节点的parent和和其对应的height(其实选择struct构造的方法也可以)   
##  Code:   
~~~
//union-find+Map
#include <iostream>
#include <cmath>
#include <map>

using namespace std;

#define N 10000

int pa[N], fri[N];
map<string, int> mark;

void init(){
    for(int i = 1; i <= N; i ++){
            pa[i] = i;
            fri[i] = 1;
    }
    mark.clear();
}

//to find the root with union-find
int search(int x){
    if(x != pa[x]){
        pa[x] = search(pa[x]);
    }
    return pa[x];
}

void merge(int x, int y){
    x = search(x);
    y = search(y);
    if(x == y){
        cout << fri[x] << endl;
    }else{
        if(fri[x] < fri[y]){
            pa[x] = y;
            fri[y] += fri[x];
            fri[x] = fri[y];
        }else{
            pa[y] = x;
            fri[x] += fri[y];
            fri[y] = fri[x];
        }
    }
}

int main(){
    int t, i;
    cin >> t;
    while(t --){
        int n, num = 1;
        string name1, name2;
        init();
        cin >> n;
        for(i = 1; i <= n; i ++){
                cin >> name1;
                cin.ignore();
                cin >> name2;
                if(!mark[name1]){
                    mark[name1]  = num ++;
                }
                if(!mark[name2]){
                    mark[name2]  = num ++;
                }
                merge(mark[name1], mark[name2]);
                cout << max(fri[mark[name1]], fri[mark[name2]]) << endl;
        }
    }
    return 0;
}
~~~

