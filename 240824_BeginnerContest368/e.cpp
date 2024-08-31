#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N, M, X1;
    cin >> N >> M >> X1;
    vector<ll> A(M),  B(M),  S(M),  T(M);
    rep(i,M) {
        cin >> A[i] >> B[i] >> S[i] >> T[i];
        A[i]--, B[i]--;
    }
    priority_queue<part<ll, int>> que;
    que.push({X1, 0});

    vector Time(N, vector<tuple<ll, ll, int>>{});
    rep(i,M){
        Time[A[i]].push_back({S[i], T[i], B[i]});
    }
    rep(i,N) {
        sort(Time[i].begin(), Time[i].end());
    }
    while(!que.empty()){
        auto [s, t, b] = que.top();
        que.pop();
        int it = (int)(upper_bound(Time[b], s) - Time[b].begin());
        rep(){
        }
    }

    }

    ll sm=0;
    auto f = [&](auto f, int cur)->void{
        Time[cur]
    };
    cout << sm << endl;
    return 0;
}