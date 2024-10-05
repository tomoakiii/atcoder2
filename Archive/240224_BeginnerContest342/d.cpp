#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;

int main(){
    int N, M;
    cin >> N >> M;
    struct node{
        ll l;
        ll d;
        ll k;
        ll c;
        int a;
    };
    vector<vector<node>> v(N);
    vector<ll> dp(N, -1);
    node tmp;
    int a, b;
    for(int i=0; i<M; i++){
        cin >> tmp.l >> tmp.d >> tmp.k >> tmp.c >> tmp.a >> b;
        tmp.a--; b--;
        v[b].push_back(tmp);
    }

    priority_queue<pair<ll, int>> que;
    que.push({INF, N-1});
    vector<bool> visit(N, false);
    while (!que.empty()){
        auto q = que.top();
        que.pop();
        if (dp[q.second] != -1) continue;
        dp[q.second] = q.first;
        ll time = q.first;
        for (auto x: v[q.second]){
            ll depttime;
            if (time - x.c > x.l + x.d * (x.k-1)){
                depttime = x.l + x.d * (x.k-1);
            } else if (time - x.c < x.l) {
                depttime = -1;
            } else {
                depttime = x.l + x.d * ((time - x.c - x.l)/x.d);
            }
            que.push({depttime, x.a});
        }
    }
    for (int i=0; i<N-1; i++) {
        if (dp[i] == -1) cout << "Unreachable" << endl;
        else cout << dp[i] << endl;
    }
    return 0;
}

