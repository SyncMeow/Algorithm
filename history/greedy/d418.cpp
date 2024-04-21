#include <bits/stdc++.h>
#define cock ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main(){
    cock;
    int t; cin >> t;
    while(t--){
        int n, output = 1; cin >> n;
        multiset<int> st;
        if (n == 1){
            cout << 1 << '\n';
            continue;
        }
        for(int i = 9;i > 1&& n != 1;){
            if (!(n%i)){
                st.insert(i);
                n /= i;
            }else{
                if(i==2){
                    cout << -1 << '\n';
                    output = 0;
                    break;
                }else i--;
            }
        }
        if (output){
            for(auto it: st) cout << it;
            cout << '\n';
        }
    }
}