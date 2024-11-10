#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;


int main(){
    int N;
    cin >> N;
    vector X(2, vector<ll>{});
    vector Y(2, vector<ll>{});
    ll x, y;
    for (int i=0; i<N; i++){
        cin >> x >> y;
        int k = (x+y)%2;
        X[k].push_back(x+y);
        Y[k].push_back(y-x);
    }

    ll ans = 0;
    for(int k=0; k<2; k++){
        int s = (int)X[k].size();
        sort(X[k].begin(), X[k].end());
        sort(Y[k].begin(), Y[k].end());
        ll Xsum = 0, Ysum = 0;
        ll a=1, b=s-1;
        for(int i=1; i<s; i++){
            Xsum += a * b * (X[k][i] - X[k][i-1]);
            Ysum += a * b * (Y[k][i] - Y[k][i-1]);
            a++, b--;
        }
        ans += (Xsum + Ysum)/2;
    }
    cout << ans << endl;
    return 0;
}