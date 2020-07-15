#include <iostream>
#include <string>

using namespace std;

#define N 1000

int dp[N][N];

int getLen(string s){
	int i, j;
	int res = 1;
	int len = s.length();
	for(i = 0; i < len - 1; i ++){
		dp[i][i] = 1;
		dp[i][i + 1] = (s[i] == s[i + 1]);
			res = 2;
	}
	for(i = 0; i < len - 1; i ++){
		for(j = i + 2; j < len; j ++){
			cout << i << " " << j << " ";
			dp[i][j] = (dp[i + 1][j - 1] && (s[i] == s[j]));
			cout << dp[i][j] << endl;
			if(dp[i][j]){
				res = res > (j - i + 1) ? res : (j - i + 1);
			}
		}
	}
	return res;
}

int main(){
	string s;
	while(cin >> s && s != "exit"){
		cout << getLen(s) << endl;
	}
	return 0;
}
