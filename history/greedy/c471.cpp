#include <bits/stdc++.h>
using namespace std;

struct item{
	long long w, f;
};

bool cmp(item a, item b){
	return a.w*b.f < b.w*a.f;
}

int main(){
	int n;
	while(cin >> n){
		vector<item> v(n);
		for(int i = 0;i < n;i++) cin >> v[i].w;
		for(int i = 0;i < n;i++) cin >> v[i].f;
		
		sort(v.begin(), v.end(), cmp);
		
		long long sum_w = 0, e = 0;
		for(int i = 0;i < n-1;i++){
			sum_w += v[i].w;
			e += sum_w * v[i+1].f;
		}
		
		cout << e;
	}
}
