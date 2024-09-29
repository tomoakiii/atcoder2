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
    int N, M;
    cin >> N >> M;
    vector<ll> X1, X2, X3;
    rep(i, N){
        int t;
        cin >> t;
        ll x;
        cin >> x;
        if (t == 0) X1.push_back(x);
        if (t == 1) X2.push_back(x);
        if (t == 2) X3.push_back(x);
    }
    sort(X1.rbegin(), X1.rend());
    sort(X2.rbegin(), X2.rend());
    sort(X3.rbegin(), X3.rend());
    ll st = 0;
    int pkd = 0;
    int k1 = 0, k2 = 0, k3 = 0;
    rep(i, (int)X1.size()) {
        st += X1[i];
        pkd++;
        k1 = i;
        if (i == M - 1){
            break;
        }
    } 
    int kgl = 0;
    ll ct = 0;
    ll mx = st;
    while(k1 >= 0 && k2 < (int)X2.size()) {
        if (ct == 0 && k3 < (int)X3.size()) {
            if (pkd < M){
                pkd++;
            } else {
                st -= X1[k1--];
            }
            ct += X3[k3++];
        }
        while(pkd < M && ct > 0 && k2 < (int)X2.size()) {
            st += X2[k2++];
            ct--;
            pkd++;
        }
        chmax(mx, st);
        if (ct == 0) break;
        if (k1 < 0) break;
        st -= X1[k1--];
        st += X2[k2++];
        ct--;
        chmax(mx, st);
    }
    cout << mx << endl;
    return 0;
}