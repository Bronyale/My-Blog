#include <iostream>

using namespace std;

#define mod 10

int quickPow(int bas, int pow) {
	int res = 1;
	while(pow > 0) {
		if(pow & 1) {
			res = bas * res % mod;
		}
		pow = pow >> 1;
		bas = bas * bas;
	}
	return res;
}

int main(){
	int n;
	while(cin >> n && n != 0) {
		cout << quickPow(n, n) << endl;
	}
	return 0;
}
