#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;
typedef pair<int,int> pii;
int main(){
    int N;
    cin >> N;
    vector A(N, vector<int>(N-1));
    map<pair<int,int>, int> mp;

    int ind = 0;
    auto meet = [&](int i, int j)->pair<int,int> {
        return {min(i,j), max(i,j)};
    };

    vector<pair<int,int>> dict(N*N);
    rep(i,N) rep(j,N-1) {
        ll a; cin>>a; a--;
        A[i][j] = a;
        auto mt = meet(i,a);
        if(!mp.contains(mt)) {
            mp[mt] = ind;
            dict[ind] = mt;
            ind++;
        }
    }

    scc_graph G(N*(N-1)/2);
    rep(i,N) rep(j,N-2) {
        auto mt = meet(i,A[i][j]);
        auto mt2 = meet(i,A[i][j+1]);
        G.add_edge(mp[mt], mp[mt2]);
    }

    vector<int> days(N);
    int mx = 1;
    for(auto gg: G.scc()) {
        if(gg.size() > 1) {
            cout << -1 << endl;
            return 0;
        }
        auto [i,j] = dict[gg[0]];
        chmax(mx, days[i]+1);
        chmax(mx, days[j]+1);
        days[i] = mx;
        days[j] = mx;
    }
    cout<<mx<<endl;
    return 0;
}