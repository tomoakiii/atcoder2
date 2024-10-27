#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N, 0);
    rep(i, N) {
        cin >> A[i];
    }
    vector P(N, vector<pair<int, ll>>{});
    rep(i, M){
        int u, v;
        ll b;
        cin >> u >> v >> b;
        u--;
        v--;
        P[u].push_back(make_pair(v, b));
        P[v].push_back(make_pair(u, b));
    }
    
    struct str{
        int from;
        int to;
        ll val;
    };
    //auto comp = [](str &a, str &b){return a.val > b.val;}; // > (<) is smallest (largest) first
    //priority_queue<str, vector<str>, decltype(comp)> que(comp);
    queue<str> que;
    str tr;
    rep(i, P[0].size()){
        tr.from = 0;
        tr.to = P[0][i].first;
        tr.val = P[0][i].second;
        que.push(tr);
    }
    
    vector<ll> D(N, INF);
    D[0] = A[0];
    while(!que.empty()) {
        //auto q = que.top();
        auto q = que.front();
        que.pop();
        if( D[q.to] > (D[q.from] + q.val + A[q.to]) ){
            D[q.to] = D[q.from] + q.val + A[q.to];
            rep(i, P[q.to].size()){
                tr.from = q.to;
                tr.to = P[q.to][i].first;
                tr.val = P[q.to][i].second;
                que.push(tr);
            }
        }
    }
    for(int i=1; i<N; i++) cout << D[i] << " ";
    cout << endl;
    return 0;
}