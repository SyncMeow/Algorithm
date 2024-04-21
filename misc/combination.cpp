#include <bits/stdc++.h>
using namespace std;

string s = "";
int n, k;
vector<char> ele;

void print_ele(){
    for (int i = 0;i < n;i++){
        if (s[i] == '1'){
            cout << ele[i] << ' ';
        }
    }
    cout << '\n';
}

void func(int cur, int select){
    if (n - cur + 1 < k - select + 1){return;}

    if (cur == n){
        print_ele();
        //cout << s << '\n';
    }
    else if (select == k){
        for (int i = 0;i < n - cur + 1;i++){
            s[cur + i] = '0';
        }
        print_ele();
        //cout << s << '\n';
    }
    else{
        s[cur] = '0';
        func(cur+1, select);
        s[cur] = '1';
        func(cur+1, select+1);
    }
}

int main(){
    cin >> n >> k;
    for (int i = 0;i < n;i++){
        char t; cin >> t;
        ele.push_back(t);
    }
    s.resize(n);
    func(0, 0);
    system("pause");
}