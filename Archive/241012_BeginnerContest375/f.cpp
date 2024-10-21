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
    ll N, M, Q;
    cin >> N >> M >> Q;
    struct abcst{
        int a, b;
        ll c;
    };
    vector<abcst> abc(M);
    rep(i, M) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--, b--;
        abc[i].a = a, abc[i].b = b, abc[i].c = c;
    }
    struct qst{
        int q;
        int x, y;
    };
    vector<qst> question(Q);
    set<int> st;
    rep(i, Q) {
        cin >> question[i].q >> question[i].x;
        question[i].x--;
        if (question[i].q==2) {
            cin >> question[i].y;
            question[i].y--;
        }
        if (question[i].q==1) st.insert(question[i].x); 
    }
    vector dist(N, vector<ll>(N, INF));
    rep(i,N) dist[i][i]=0;
    rep(i, M) {
        if(st.count(i)) continue;
        abcst ab = abc[i];
        dist[ab.a][ab.b] = dist[ab.b][ab.a] = ab.c;
    }
    rep(k, N) rep(i, N) rep(j, N) chmin(dist[i][j], dist[i][k] + dist[k][j]);
    vector<ll> ans{};
    reverse(question.begin(), question.end());
    rep(x, Q) {
        qst q = question[x];
        if (q.q == 1) {
            abcst ab = abc[q.x];            
            rep(i, N) rep(j, N) {
                chmin(dist[i][j], dist[i][ab.a] + ab.c + dist[ab.b][j]);
                chmin(dist[i][j], dist[i][ab.b] + ab.c + dist[ab.a][j]);
            }
        } else {
            ans.emplace_back(dist[q.x][q.y]);
        }
    }
    reverse(ans.begin(), ans.end());
    for(auto as: ans) {
        if (as >= INF) as = -1;
        cout << as << endl;
    }
    return 0;
}