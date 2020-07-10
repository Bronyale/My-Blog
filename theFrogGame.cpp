#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, L;
vector<int> v;

int judge(int n) {
	int pos = 0, cnt, tmp = 1;
	for(cnt = 0; cnt < m; cnt ++) {
		while(v[tmp] - v[pos] <= n){
			//cout << v[tmp] << " - " << v[pos] << endl;
			if(v[tmp] == L){
				tmp ++;
				break;
			}
			tmp ++;
		}
		pos = tmp - 1;
		//cout << tmp << " " << pos << " " << cnt << endl;
		if(v[pos] == L) {
			break;
		}
	}
	if(v[pos] == L) {
		return 1;
	} else {
		return 0;
	}
}

int dichotomy(int l, int r) {
	if(l == r) {
		return l;
	}
	int mid = (l + r) >> 1;
	if(judge(mid)){ 
		//cout << mid << " yes" << endl;
		return dichotomy(l, mid);
	}else{
		//cout << mid << " no" << endl;
		return dichotomy(mid + 1, r);
	}
}

int main(){
	while(cin >> L >> n >> m && L) {
		v.clear();
		v.push_back(0);
		for(int i = 0; i < n; i ++) {
			int tmp;
			cin >> tmp;
			v.push_back(tmp);
		}
		v.push_back(L);
		sort(v.begin(), v.end());
		//for(int i = 0; i < n + 2; i ++){
		//	cout << v[i] << " ";
		//}
		//cout << endl;
		int res = dichotomy(0, L);
		cout << res << endl;
		//cout << judge(9) << endl;
	}
	return 0;
}
