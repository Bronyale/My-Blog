/*************************************************************************
    > File Name: recurringDecimal.cpp
    > Author: Bronyale
    > Mail: bronyale@outlook.com 
    > Created Time: 2020年03月03日 星期二 08时11分37秒
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

#define N 1000
#define ll lone long
#define INF 0x3f3f3f3f

int a, b, n;
int ret;

int main(){
	int i;
	cin >> a >> b >> n;
	ret = a % b;
	for(i = 1; i <= n; i ++){
		ret = ret % b * 10;
		if(ret % b == a % b){
			n %= i;
			i = 0;
		}
	}
	for(i = 1; i <= 3; i ++){
		cout << ret / b;
		ret = ret % b * 10;
	}

    return 0;
}
