#include <bits/stdc++.h>
using namespace std;

int main(){
    const long long INF = 0x0f7f7f7f7f7f7f7f;
    int N, M;
    cin >> N >> M;
    vector<vector<long long>> w(N, vector<long long>(N, INF));
    int x1, x2, w0;
    for (int i=0;i<M;i++) {
        cin >> x1 >> x2 >> w0;
        x1--; x2--;
        w[x1][x2] = w0;
    }
    for (int k=0;k<N;k++) {
        for (int i=0;i<N;i++) {
            w[i][i] = 0;
            for (int j=0;j<N;j++) {
                w[i][j] = min(w[i][k]+w[k][j], w[i][j]);
            }
        }
    }
    int sn = 1<<N;
    vector<vector<long long>> dp(sn, vector<long long>(N, INF));
    for (int i=0;i<N;i++) {
        dp[1<<i][i] = 0;
    }

    for (int s=0; s<sn; s++) {
        for (int i=0;i<N;i++) {
            if ((s>>i) & 1){
                for (int j=0;j<N;j++) {
                    int s2 = s | (1<<j);
                    dp[s2][j] = min(dp[s2][j], dp[s][i] + w[i][j]);
                }
            }
        }
    }
    long long mi=INF;
    for(int i=0; i<N; i++){
        mi = min(dp[sn-1][i], mi);
    }
    if (mi > INF/2){
        cout << "No" << endl;
    } else {
        cout << mi << endl;
    }
    return 0;
}

