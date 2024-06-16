#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;

int main(){
    ll N;
    cin >> N;
    map<ll, ll> mp;
    ll sum = 0;
    auto func = [&](auto func, ll n) -> ll {
        if (n < 2) return 0;
        ll a = (n+1)/2, b=n/2;
        if (mp.find(a) == mp.end()) mp[a] = func(func, a);
        if (mp.find(b) == mp.end()) mp[b] = func(func, b);        
        return (n + mp[a] + mp[b]);
    };
    cout << func(func, N) << endl;
    return 0;
}

