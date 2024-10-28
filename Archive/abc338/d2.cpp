#include <bits/stdc++.h>
using namespace std;
#define INF 100000000000007;

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> X(M);
    vector<vector<int>> pr(N);
    for (int i=0;i<M;i++) {
        cin >> X[i];
        X[i]--;
    }
    long long dist=0;
    int s, g;
    for(int i = 1 ; i < M; i++){
        s = X[i-1]; g = X[i];
        if (s > g) swap(s, g);
        dist += g-s;
        pr[s].push_back(g);
    }
    int s2, g2;
    auto dist2=dist;
    for(int mb = 0 ; mb < N-1; mb++){
        for(int i = 0; i < pr[mb].size(); i++){
            s = mb; g = pr[mb][i];
            dist2 -= (g-s);
            s2=g; g2=s+N;
            if(s2<N) pr[s2].push_back(g2);
            dist2 += (g2-s2);
        }
        dist = min(dist, dist2);
    }
    cout << dist << endl;
    return 0;
}

