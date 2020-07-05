/*************************************************************************
    > File Name: plants.cpp
    > Author: Bronyale
    > Mail: bronyale@outlook.com 
    > Created Time: 2020年03月01日 星期日 14时32分02秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<string>
#include<stack>
#include<deque>
#include<map>

using namespace std;

#define N 1000000
#define ll lone long
#define INF 0x3f3f3f3f

struct node{
	int pa;
	int h;
	node() : pa(-1), h(1){

	}
}a[N];

int search(int x){
	if(a[x].pa == -1){
		return x;
	}
	a[x].pa = search(a[x].pa);
	return a[x].pa;
}

void merge(int n1, int n2){
	n1 = search(n1);
	n2 = search(n2);
	if(n1 != n2){
		if(a[n1].h >= a[n2].h){
			a[n2].pa = n1;
			if(a[n1].h == a[n2].h){
				++ a[n1].h;
			}
		}else{
			a[n1].pa = n2;
		}
	}
}

int main(){
	int m, n;
	int k;
	int x, y;
	int ret;
	cin >> m >> n;
	ret = m * n;
	cin >> k;
	while(k --){
		cin >> x >> y;
		if(search(x) == search(y)){
			continue;
		}
		merge(x, y);
		if(search(x) == search(y)){
			-- ret;
		}
	}
	cout << ret << endl;
    return 0;
}
