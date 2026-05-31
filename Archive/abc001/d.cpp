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
typedef pair<int,int> p;
int main(){
    ll N; cin>>N;
    vector<p> v;
    rep(i,N) {
        int S, E;
        scanf("%d-%d", &S, &E);
        S = S - S%5;
        if(S%100 == 60) {
            S = S / 100;
            S++;
            S *= 100;
        }

        if(E%5>0) E = E+(5-E%5);
        if(E%100 == 60) {
            E = E / 100;
            E++;
            E *= 100;
        }
        v.push_back({S,E});
    }
    sort(v.begin(), v.end());
    deque<p> dq;
    rep(i,N) {
        auto [S,E] = v[i];
        if(dq.empty()) dq.push_back({S,E});

        auto [S0, E0] = dq.back();
        // assert(S0<=S)
        if(E0 >= S) {
            dq.pop_back();
            dq.push_back({S0, max(E,E0)});
        } else {
            dq.push_back({S,E});
        }
    }
    for(auto [a,b]:dq) {
        printf("%4.4d-%4.4d\n",a,b);
    }
    return 0;
}

