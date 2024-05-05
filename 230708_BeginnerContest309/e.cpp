#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    int N, M;
    cin >> N >> M;
    struct person{        
        vector<int> chd;
        int ans = -1;
    };
    vector<person> P(N);    
    rep(i, N-1){
        int p;
        cin >> p;
        p--;
        P[p].chd.push_back(i+1);
    }    
    ll sm = 0;
    rep(i, M){
        int x, y;
        cin >> x >> y;
        x--;
        P[x].ans = max(P[x].ans, y);
    }
    queue<int> que;
    que.push(0);

    while (!que.empty()){
        auto q = que.front();
        que.pop();
        for (auto t: P[q].chd){
            P[t].ans = max(P[t].ans, P[q].ans - 1);
            que.push(t);
        }
    }

    rep (i, N){
        if (P[i].ans != -1) sm++;
    }

    cout << sm << endl;
    return 0;
}