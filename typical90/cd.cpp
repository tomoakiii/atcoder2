#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef unsigned long long ll;
typedef modint1000000007 mint;

int main(){
    ll l, r;
    cin >> l >> r;
    ll p = 1, q = 1;
    mint ans = 0;
    ll k = 1;    
    while(p < l) {
        p *= 10;
        k++;
    } 
    while(q <= r) {
        q *= 10;        
    }
    if(q > p) {    
        mint t = p;
        t *= (p-1);     
        mint t2 = (l-1);
        t2 *= l;
        t -= t2;
        t *= k-1;
        t /= 2;
        ans += t;
    } else {
        mint t = r;
        t *= (r+1);     
        mint t2 = (l-1);
        t2 *= l;
        t -= t2;
        t *= k-1;
        t /= 2;
        ans += t;        
        cout << ans.val() << endl;
        return 0;
    }

    while(p < q/10) {        
        mint t = 10*p-1;
        t *= 10*p;
        mint t2 = p-1;
        t2 *= p;  
        t -= t2;
        t *= k;
        t /= 2;
        ans += t;
        k++;
        p *= 10;       
    }
    mint t = r;
    t *= (r+1);
    mint t2 = (p-1);
    t2 *= p;
    t -= t2;
    t *= k;
    t /= 2;
    ans += t;    
    cout << ans.val() << endl;
    return 0;
}