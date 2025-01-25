#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef unsigned long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;
typedef pair<ll, int> pli;
int main(){
    ll N, M;
    cin >> N >> M;
    vector<ll> P(N);
    rep(i,N) cin>>P[i];
    // sort(P.begin(), P.end());

    vector<ll> Num(N, 0);
    auto judge = [&](ll c)-> pair<bool, ll> {
        ll sm = 0;
        ll total = 0;
        rep(i,N) {            
            ll n = (c+P[i])/(2*P[i]);
            // if( (2*(n+1)-1)*P[i] <= c ) n++;
            if(n > 0 && M / P[i] / n / n == 0) return {false, total};
            sm += n * n * P[i];
            total += n;
            Num[i] = n;
            if(sm > M) return {false, total};
        }
        return {true, total};
    };

    ll l = 0, r = M+1;
    while(r - l > 1){
        ll c = (r + l)/2;
        auto [j, t] = judge(c);
        if(j) {
            l = c;
        } else {
            r = c;
        }
    }

    auto [j, t] = judge(l);
    priority_queue<pli, vector<pli>, greater<pli>> que;
    ll sm = 0;
    rep(i,N) {
        sm += Num[i] * Num[i] * P[i];
        que.push({(2*Num[i]+1)*P[i], i});
    }

    while(!que.empty()) {
        auto [q, i] = que.top();
        if(sm + q > M) {
            break;
        } else {
            t++;
            sm += q;
            Num[i]++;
            que.push({(2*Num[i]+1)*P[i], i});
        }
    }
    cout << t << endl;

    return 0;
}