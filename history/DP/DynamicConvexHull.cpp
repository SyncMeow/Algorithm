#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct line{
    ll m, k;
    ll f(ll x){return m*x + k;}
};

int n, a, b, c, t;
vector<ll> prefix(1000005), dp(1000005);
vector<line> lines;
line tmp;

bool CanRemove(line l1, line l2, line l3){return (l3.k-l1.k)*(l2.m-l1.m) > (l2.k-l1.k)*(l3.m-l1.m);}

void AddNewLine(line l){
    lines.push_back(l);
    while(lines.size()>=3 && CanRemove(lines[lines.size()-3], lines[lines.size()-2], lines[lines.size()-1])) lines.erase(lines.end()-2);
}

ll MaxVal(ll x){
    if (!(t < lines.size())) t = lines.size()-1;
    while(t < lines.size()-1 && lines[t].f(x) < lines[t+1].f(x)) t++;
    return lines[t].f(x);
}

ll func(ll score){return a*score*score + b*score + c;}

int main(){ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> a >> b >> c;
    
    for(int i = 0, score;i < n;i++){
        cin >> score; 
        prefix[i] = (i==0)? score: prefix[i-1] + score;
    }
    
    for(int i = 0, score;i < n;i++){
        dp[i] = (i==0)? func(prefix[i]): max(func(prefix[i]), func(prefix[i]) + MaxVal(prefix[i])); 
        tmp = {-2*a*prefix[i], dp[i] + a*prefix[i]*prefix[i] - b*prefix[i]};
        AddNewLine(tmp);
        
    }
    cout << dp[n-1] << '\n';
}
