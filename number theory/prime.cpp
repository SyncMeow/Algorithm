#include <bits/stdc++.h>
using namespace std;

bool isPrime(long long int n){
    if (n == 1)return false;
    
    for (long long int i = 2;i*i <= n;i++){
        if (n%i == 0) return false;
    }

    return true;
}



int main(){
    long long int k; cin >> k;

    if (isPrime(k)) {
        cout << k << " is a prime\n";
    }else {
        cout << k << " is not a prime\n";
    }
}