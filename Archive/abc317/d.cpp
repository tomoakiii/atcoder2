#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;

int main()
{    
    ll N;
    cin >> N;
    vector<ll> XY, Za;
    ll sm = 0;
    ll gt = 0;
    ll X, Y, Z;
    for(int i=0; i<N; i++){
        cin >> X >> Y >>Z;
        sm += Z;
        if (X > Y) gt+=Z;
        else {
            XY.push_back((Y-X+1)/2);
            Za.push_back(Z);
        }
    }
    sm = (sm+1)/2;
    gt = sm - gt;
    if (gt <= 0) {
        cout << 0 << endl;
        return 0;
    }
    vector<ll> dp(gt + 1, INF);
    dp[0] = 0;
    for (int j=0; j<Za.size(); j++){
        for (int i=gt-1; i>=0; i--){
            ll nx = min(gt, i + Za[j]);
            dp[nx] = min(dp[nx], dp[i] + XY[j]);
        }
    }
    cout << dp[gt] << endl;
    return 0;
}