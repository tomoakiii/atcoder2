#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N, M;
    cin >> N >> M;
    vector<ll> P(M);
    vector<pair<ll, ll>> LD(M);
    rep(i, M) cin >> P[i];
    rep(i, M) cin >> LD[i].first;
    rep(i, M) cin >> LD[i].second;
    auto func = [&](int l, int r){        
        if(LD[l].first == LD[r].first) {
            return (LD[l].second < LD[r].second); // 割引額大を使うのが正解
        } else {
            return (LD[l].first < LD[r].first); // lftの方が大きいのが正解
        }                
    };
    sort(ord.begin(), ord.end(), func);
    return 0;
}