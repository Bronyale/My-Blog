#include <iostream>

using namespace std;

#define N 1000
#define MAX(a, b) a > b ? a : b

int a[N];
int n, dp[N];

int goDP(){
	dp[0] = a[0];
	dp[1] = MAX(a[0], a[1]);
	int i;
	for(i = 2; i < n; i ++){
		dp[i] = MAX(dp[i - 1], dp[i - 2] + a[i]);
	}
	return dp[n - 1];
}

int main(){
	while(cin >> n && n){
		int i;
		for(i = 0; i < n; i ++){
			cin >> a[i];
		}
		cout << goDP() << endl;
	}
	return 0;
}
