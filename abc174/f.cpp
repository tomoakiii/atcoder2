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


int op(int a, int b) { return a+b; }
int e() { return -1; }
int target;
bool f(int v) { return v < target; }


int main(){
    ll N, Q;
    cin >> N >> Q;
    vector<ll> C(N);
    rep(i,N) {
        cin>>C[i];
        C[i]--;
    }
    vector<ll> col(N, -1);
    vector<ll> nx(N, -1);
    for(int i=N-1; i>=0; i--) {
        if(col[C[i]] != -1) nx[i] = col[C[i]];
        col[C[i]] = i;        
    }
    vector<bool> visit(N, 0);
    vector<int> sm(N);
    rep(i,N) {
        if(!visit[C[i]]) sm[i]++;
        visit[C[i]] = true;
    }

    segtree<int, op, e> seg(sm);    
    vector<pair<int,int>> que;
    while(Q--){
        int l,r; cin>>l>>r; l--; r--;
        que.push_back({l,r});
    }
    sort(que.begin(), que.end());

    int cur = 0;
    for(auto [l,r]: que) {
        while(cur < l) {
            if(seg.get(cur) == 1) {
                seg.set(cur, 0);
                if(nx[cur] != -1) seg.set(nx[cur], 1);
            }
            cur++;
        }
        cout << seg.prod(l, r+1) << endl;
    }
    return 0;
}