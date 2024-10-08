#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;
using mint = modint998244353;
using P = pair<ll, int>;
using PQ = priority_queue<P, vector<P>, greater<P>>;
struct Train{
    int from;
    int to;
    ll dpt;
    ll arv;
    int idx;
    bool operator<(const Train &x){
        return dpt < x.dpt;
    };
};


int main(){
    ll N,M,X1;
    cin >> N >> M >> X1;
    vector<Train> trains(M);
    int i=0;
    for(auto &t: trains){
        cin >> t.from >> t.to >> t.dpt >> t.arv;
        t.from--; t.to--;
        t.idx = i++;
    }
<<<<<<< HEAD
    sort(trains.begin(), trains.end());
    vector<PQ> station(N);
    rep(i,M){
        auto t = trains[i];
        P p = {t.arv, t.idx};
        station[t.to].push(p);
    }
    vector<ll> latest(N);
    vector<ll> ans(M);
    for(auto t: trains){
        ll time = t.dpt;
        int st = t.from;
        while(!station[st].empty()){
            auto tp = station[st].top();
            if (tp.first > time) break;
            station[st].pop();
            latest[st] = max(latest[st], trains[tp.second].arv);
        }
        if (latest[st] <= time) continue;
        ans[tp.second] += latest[st] - time;
    }

    for (auto t: ans) cout << t << " ";
=======
    vector dp(N, vector<vector<mint>>(N, vector<mint>(N+1, 0)));
    rep(i,N) {
        for(int j=i+1; j<N; j++) {
            dp[i][j][2] = 1;
        }
    }

    rep(i,N) rep(j,N) for(int k=2; k<N; k++) {
        int nk=k+1;
        int ni=j;
        ll tgt = A[j]+(A[j]-A[i]);
        for(int x=j+1; x<N; x++){
            if (A[x] == tgt) {
                dp[ni][x][nk] += dp[i][j][k];
            }
        }
    }

    cout << N << " ";
    for(int k=2; k<=N; k++) {
        mint sm = 0;
        rep(i, N) for(int j=i+1; j<N; j++) {
            sm += dp[i][j][k];
        }
        cout << sm.val() << " ";
    }
>>>>>>> ed69aec9ce59af355a2a749389207fd99e3e4f60
    cout << endl;
    return 0;
}