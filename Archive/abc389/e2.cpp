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
typedef pair<ll, int> pli;
int main(){
    ll N, M;
    cin >> N >> M;
    vector<ll> P(N);
    rep(i,N) cin>>P[i];
    vector<ll> Num(N, 0);
    priority_queue<pli, vector<pli>, greater<pli>> que;
    rep(i,N) que.push({P[i], i});

    ll sm = 0;
    ll ans = 0;
    while(!que.empty()) {
        auto [q, i] = que.top();
        que.pop();
        if(sm + q > M) {
            break;
        }
        sm += q;        
        Num[i]++;
        ans ++;
        ll nN = ( (Num[i]+1)*(Num[i]+1) - Num[i]*Num[i] ) * P[i];
        que.push({nN, i});        
    }

    ll tsm = 0;
    rep(i,N) {
        printf("%ld JPY * %ld = %ld\n", P[i], Num[i], Num[i]*Num[i]*P[i]);
        tsm += Num[i]*Num[i]*P[i];
        
    }
    printf("sm = %ld\n", tsm);
    cout << ans << endl;

    return 0;
}