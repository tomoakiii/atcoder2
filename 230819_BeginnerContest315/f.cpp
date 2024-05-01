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
    for(int i=1; i<N; i++){
        dist += sqrt((xy[i].x)*(xy[i-1].x) + (xy[i].y)*(xy[i-1].y));        
    }
    double x=1;
    int M=0;
    while(x < dist){
        x*=2;
        M++;
    }
    vector dp(N, vector<double>(M)); // dp[i][j]: 最後にiを通って、j個パスした
    dp[0][0] = dist;
    dp[1][0] = dist;
    for(int i=2; i<N; i++){
        for(int j=0; j<min(M, i-1); j++){
            dp[i][j] = min()
        }
    }
    
    cout << endl;
    return 0;
}