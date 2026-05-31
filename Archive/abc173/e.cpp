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
typedef modint1000000007 mint;
int main(){
    int N,K;
    cin >> N >> K;
    deque<ll> Pos, Neg, Zer;
    vector<ll> A(N);
    rep(i,N) {
        ll a; cin>>a;
        A[i] = a;
        if(a > 0) Pos.push_back(a);
        else if(a < 0) Neg.push_back(-a);
        else Zer.push_back(a);
    }
    sort(Pos.rbegin(), Pos.rend());
    sort(Neg.rbegin(), Neg.rend());
    int ps = Pos.size();
    int ns = Neg.size();
    int zs = Zer.size();
    
    if(ps + ns < K) {
        cout << 0 << endl;
        return 0;
    }
    if(K == N) {
        mint ans = 1;
        rep(i,N) ans *= A[i];
        cout << ans.val() << endl;  
        return 0;      
    }
    if(ps == 0 && zs == 0) {
        if(K % 2 == 1) {
            reverse(Neg.begin(), Neg.end());
        }
        mint ans = 1;
        rep(i,K) ans *= -Neg[i];
        cout << ans.val() << endl;
        return 0;
    }
    mint ans = 1;
    if(K%2 == 1) {
        ans *= Pos[0];
        Pos.pop_front();
    }
    while(K > 1) {
        if(ns > 1 && ps > 1) {
            ll n1 = Neg[0] * Neg[1];
            ll p1 = Pos[0] * Pos[1];
            if(n1 > p1) {
                ans *= n1;
                Neg.pop_front(); Neg.pop_front();
            } else {
                ans *= p1;
                Pos.pop_front(); Pos.pop_front();
            }
        } else if(ps > 1) {
            ll p1 = Pos[0] * Pos[1];
            ans *= p1;
            Pos.pop_front(); Pos.pop_front();
        } else {
            ll n1 = Neg[0] * Neg[1];
            ans *= n1;
            Neg.pop_front(); Neg.pop_front();
        }
        K -= 2;
    }
    cout << ans.val() << endl;
    return 0;
}