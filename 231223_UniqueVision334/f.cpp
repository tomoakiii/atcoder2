#include <bits/stdc++.h>
using namespace std;

double distance(double x1, double y1, double x2, double y2){
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int main(){
    int N, K;
    double sx, sy;
    cin >> N >> K >> sx >> sy;
    vector<vector<double>> dp(2, vector<double>(K, 0));
    // dp[b][a]; Min total distance that Santa has qty=a gifts after visiting kid #b
    // dp[b][a] = dp[b-1][a+1] + dist(#b - #b-1) (when a+1>0)
    // dp[b][a] = dp[b-1][a+1] + dist(#b) - dist(#b-1) (when a+1>0)
    vector<double> X(N+1, 0), Y(N+1, 0);
    for (int i=1; i<=N; i++){
        cin >> X[i] >> Y[i];
        X[i] -= sx;
        Y[i] -= sy;
    }
    vector<double> tmpmin(N+1);
    vector<double> dist2home(N+1, 0);
    
    tmpmin[0] = 0;
    int dpind = 0, dpindinv = 1;
    for (int i=1; i<=N; i++){
        dist2home[i] = distance(X[i], Y[i], 0, 0);
        dp[dpind][K-1] = tmpmin[i-1] + dist2home[i-1] + dist2home[i];
        tmpmin[i] = dp[dpind][K-1];
        double dist2next = distance(X[i], Y[i], X[i-1], Y[i-1]);
        for (int j=0; j<K-1; j++){
            dp[dpind][j] = min(dp[dpindinv][j+1] + dist2next, dp[dpind][K-1]);
            tmpmin[i] = min(tmpmin[i], dp[dpind][j]);
        }
        dpind = (dpind==1)?0:1;
        dpindinv = (dpindinv==1)?0:1;
    }
    std::cout << std::setprecision(24) << tmpmin[N] + distance(X[N], Y[N], 0, 0) << endl;
    return 0;
}