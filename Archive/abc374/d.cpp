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
typedef pair<double, double> pll;
typedef pair<pll, pll> ppll;
double dist(pll a, pll b){
    double d=(a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
    return sqrt(d);
}

int main(){
    ll N, S, T;
    cin >> N >> S >> T;
    vector<ppll> V(N);
    rep(i,N) {
        double a,b,c,d;
        cin>>a>>b>>c>>d;
        V[i].first = {a,b};
        V[i].second = {c,d};
    }
    vector<int> ord(N);
    iota(ord.begin(), ord.end(), 0);
    
    double mn = 10000000;
    do {
        rep(k, 1<<N){
            double time = 0;
            pll cur = {0,0};
            double distT;
            for(auto i: ord){
                if ((k>>i) & 1) {
                    time += dist(V[i].first, cur)/S;
                    cur = V[i].second;
                } else {
                    time += dist(V[i].second, cur)/S;
                    cur = V[i].first;
                }
                distT = dist(V[i].first, V[i].second);
                time += distT/T;
            }
            chmin(mn, time);
        }
	} while (next_permutation(ord.begin(), ord.end()));

    cout << setprecision(24) << mn << endl;
    return 0;
}