#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{    
    int N;
    cin >> N;
    struct xyst{
        int x;
        int y;
    };
    vector<xyst> xy(N);
    for(int i=0; i<N; i++){
        cin >> xy[i].x >> xy[i].y;        
    }
    double dist = 0;
    
    auto fdist = [&](int i, int j)->double {
        double dx = (xy[i].x - xy[j].x);
        double dy = (xy[i].y - xy[j].y);
        return sqrt(dx*dx + dy*dy);        
    };

    for(int i=1; i<N; i++){        
        dist += fdist(i, i-1);
    }
    double x=1;
    int M=0;
    while(x <= 2*dist){
        x*=2;
        M++;
    }

    vector<double> penalty(M+1);
    penalty[0] = 0;
    double p=1;
    for(int i=1; i<=M; i++){
        penalty[i] = (1<<(i-1));
    }

    vector dp(N, vector<double>(M+1, N*dist)); // dp[i][j]: 最後にiを通って、j個パスした
    dp[0][0] = 0;    
    for(int i=0; i<N-1; i++){        
        for(int j=0; j<=M; j++){ // 今までいくつスキップしてきたか
            double d = dp[i][j] - penalty[j];
            for (int nx=i+1; nx<N && j+nx-i-1<=M ; nx++){ // 次どこにいくか                
                int step = nx-i-1; // 追加スキップ回数
                dp[nx][j+step] = min(dp[nx][j+step], d + fdist(nx, i) + penalty[j+step]);
            }            
        }
    }
    
    double ans = INF;
    for(auto d: dp[N-1]){
        ans = min(d, ans);
    }

    std::cout << std::setprecision(24) <<  ans << endl;
    return 0;
}