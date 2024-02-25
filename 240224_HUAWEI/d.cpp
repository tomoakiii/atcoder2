#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;

int main(){
    int N, M;
    struct node{
        ll l;
        ll d;
        ll k;
        ll c;
        int a;
    };
    vector<vector<node>> v(N);
    vector<ll> dp(N, INF);
    dp[N-1] = 0;
    node tmp;
    int a, b;
    for(int i=0; i<M; i++){
        cin >> tmp.l >> tmp.d >> tmp.k >> tmp.c >> tmp.a >> b;
        v[b].push_back(tmp);
    }
    queue<int> que;
    que.push(N-1);
    vector<bool> visit(N, false);
    while (!que.empty()){
        auto q = que.front();
        que.pop();

        dp[v[q].a] = dp[q]+v[q].
    }

}

