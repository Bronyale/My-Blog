#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int L, N;
int a[1000];

int main(){
	while(cin >> L >> N && L * N != 0){
		int i;
		int len = 0;
		for(i = 0; i < N; i ++){
			cin >> a[i];
			++ len;
		}
		sort(a, a + len, greater<int>());
		int sum = 0;
		int cnt = 0;
		int flag = 0;
		for(i = 0; i < len; i ++){
			sum += a[i];
			++ cnt;
			if(sum >= L){
				cout << cnt << endl;
				flag = 1;
				break;
			}
		}
		if(!flag){
			cout << "impossible" << endl;
		}
	}
	
	return 0;
}
