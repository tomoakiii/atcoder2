// https://atcoder.jp/contests/abc412/tasks/abc412_e
//
// Ex. エラトステネスの区間篩
// https://algo-method.com/tasks/332/editorial
//
// A以上B以下で素数のべき乗になっている要素数を数える（Aが素数べき乗ではないのなら+1）

#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll L,R;
    cin>>L>>R;
    
    ll ans = 0;
    vector<bool> isPrime(2E7, true);
    vector<bool> prime_1(R-L+1, true);
    
    for(ll e = 2; e*e <= R+10; e++){
        // すでに合成数であるものはスキップする
        if(!isPrime[e]) continue;

        // p 以外の p の倍数から素数ラベルを剥奪
        for(ll x = 2*e; x*x <= R+10; x += e) {
            isPrime[x] = false;            
        }

        // st: A 以上の最小のpの倍数。ここを起点にpの倍数をふるう
        ll st = (L-1+e)/e;

        // コーナーケース：stがpそのものになる場合はふるってはいけない
        if(st==1) {
            st = 2*e;
        } else {
            st *= e;
        }

        // L 以上 R 以下の整数のうち、p の倍数をふるう
        for(ll x = st; x <= R; x += e) {
            prime_1[x - L] = false;
        }
    }
    for(auto e: prime_1) if(e) ans++;

    if(!prime_1[0]) {
        ans++;
        prime_1[0] = true;
    }
    for(ll i=2; i<isPrime.size(); i++) {
        if(!isPrime[i]) continue;
        ll x = i*i;
        while(x <= R) {
            if(x >= L && !prime_1[x-L]) ans++;
            x *= i;
        }
    }

    cout<<ans<<endl;
    return 0;
}