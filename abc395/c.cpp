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
    ll N;
    cin >> N;
    vector<ll> A(N);
    map<int, vector<int>> mp;
    rep(i,N) {
        cin>>A[i];
        mp[A[i]].push_back(i);
    }
    int MN = INFi;
    for(auto m:mp) {
        if(m.second.size() == 1) continue;
        rep(i, m.second.size()-1) {
            int d = m.second[i+1] - m.second[i];
            chmin(MN, d);
        }
    }
    if(MN == INFi) {
        MN = -2;
    }
    cout << MN+1 << endl;
    return 0;
}