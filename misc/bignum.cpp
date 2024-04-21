#include <bits/stdc++.h>
using namespace std;

void bsum(string n1, string n2){
    const int limit = 1000;
    int a[limit], b[limit], sum[limit+1], ln1 = n1.size(), ln2 = n2.size();
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(sum, 0, sizeof(sum));
    for(int i = 0;i < ln1;i++)a[ln1-1-i] = n1[i] - '0';
    for(int i = 0;i < ln2;i++)b[ln2-1-i] = n2[i] - '0';
    for(int i = 0;i < limit;i++){
        sum[i] += a[i] + b[i];
        if (sum[i] >= 10){
            sum[i]-=10;
            sum[i+1]+=1;
        }
    }
    int start = 0;
    for(int i = limit; i>=0;i--){
        if(sum[i] != 0){
            start = i;
            break;
        }
    }
    for(int i = start; i >= 0;i--)cout << sum[i];
}

void bpro(string n1, string n2){
    const int limit = 1000;
    int a[limit], b[limit], p[limit*2+1], ln1 = n1.size(), ln2 = n2.size();
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(p, 0, sizeof(p));
    for(int i = 0;i < ln1;i++)a[ln1-1-i] = n1[i] - '0';
    for(int i = 0;i < ln2;i++)b[ln2-1-i] = n2[i] - '0';

    for(int ia = 0;ia < limit;ia++){
        for(int ib = 0;ib < limit;ib++){
            p[ia+ib] += a[ia]*b[ib];
            if(p[ia+ib]>=10){
                p[ia+ib+1] += p[ia+ib]/10;
                p[ia+ib] %= 10;
            }
        }
    }

    int start = 0;
    for(int i = 2*limit; i>=0;i--){
        if(p[i] != 0){
            start = i;
            break;
        }
    }
    for(int i = start; i >= 0;i--)cout << p[i];
}

int main(){
    string a, b;
    cin >> a >> b;
    bpro(a, b);
}