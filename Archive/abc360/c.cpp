#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N, 0), W(N, 0);
    vector AW(N, vector<ll>{}); // abject arrays in N th box included
    rep(i, N) {
        cin >> A[i];
        A[i]--;
    }
    rep(i, N) cin >> W[i];
    rep(i, N) AW[A[i]].push_back(W[i]);
    rep(i, N) sort(AW[i].begin(), AW[i].end());
    ll sm = 0;
    rep(i, N) {
        if(AW[i].size() <= 1) continue;
        for(int j = AW[i].size()-2; j >= 0; j--) {
            sm += AW[i][j];
        }
    }
    
    cout << sm << endl;
    return 0;
}