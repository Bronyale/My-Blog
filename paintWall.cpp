/*************************************************************************
    > File Name: paintWall.cpp
    > Author: Bronyale
    > Mail: bronyale@outlook.com 
    > Created Time: 2020年03月04日 星期三 14时51分01秒
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

#define N 1005
#define ll long long
#define INF 0x3f3f3f3f
#define mod 1000000007

int n;
ll sum;
ll a[N], b[N];

int main(){
	int i;
	while(cin >> n){
		sum = 0;
		//起始位置和结束位置在同一列的情况数存在b[N]
		b[1] = 1;
		for(i = 2; i <= n; i ++){
			b[i] = b[i - 1] * 2;
			b[i] %= mod;
		}
		//起始位置和结束位置不在同一列的情况数存在a[N]
		a[1] = 1;
		a[2] = 6;
		for(i = 3; i <= N; i ++){
			a[i] = b[i] + a[i - 2] * 4 + a[i - 1] * 2;
			a[i] %= mod;
		}
		//起始位置为4个角的情况
		sum += 4 * a[n];
		//起始位置在中间(从第二列开始)
		for(i = 2; i < n; i ++){
			sum += 2 * b[i] * 2 * a[n - i] + 2 * a[i - 1] * 2 * b[n - i + 1];
			sum %= mod;
		}
		if(n == 1){
			sum = 2;
		}
		cout << sum << endl;
	}
    return 0;
}
