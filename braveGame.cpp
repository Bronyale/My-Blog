#include <iostream>

using namespace std;

int t, n, m;

int main(){
	cin >> t;
	while(t --){
		cin >> n >> m;
		if(m > n){
			cout << "first" << endl;
			continue;
		}
		if(!(n % (m + 1))){
			cout << "second" << endl;
			continue;
		}
		cout << "first" << endl;
	}
	return 0;
}
