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
    int H, W, N;
    cin >> H >> W >> N;
    vector<pair<int, int>> RC(N);
    rep(i,N) cin >> RC[i].first >> RC[i].second;
    sort(RC.begin(), RC.end());
    RC.push_back({H,W});
    N++;
    vector<int> d(N, INFi), ind(N, -1), pre(N, -1);
    
    int mxp = 0;
    for(int i=0; i<N; i++){
        ll p = RC[i].second;
        auto it = upper_bound(d.begin(), d.begin()+mxp+1, p);
        int k = it - d.begin();
        d[k] = p;
        chmax(mxp, k);
        ind[k] = i;
        if (k>0) pre[i] = ind[k-1];
    }
    vector<int> ord(mxp+1, -1);    
    int p = ind[mxp];
    int i=0;
    while(p>-1){
        ord[i++] = p;
        p = pre[p];
    }
    cout << (mxp) << endl;
    pair<int, int> cur = {1, 1};
    for(i=mxp; i>=0; i--){
        rep(j, RC[ord[i]].first - cur.first) cout << 'D';
        rep(j, RC[ord[i]].second - cur.second) cout << 'R';
        cur = RC[ord[i]];
    }
    cout << endl;
    return 0;
}