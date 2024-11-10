#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;


int main(){
    double X, Y;    
    ll N, A;
    cin >> N >> A >> X >> Y;    
    map<ll, double> dp;

    auto func = [&](auto func, ll n) -> double {
        if (n == 0) return 0;
        double p1, p2=0;
        if (dp.find(n/A) == dp.end()){
            dp[n/A] = func(func, n/A);  
        }
        p1 = X + dp[n/A];
        
        for (int k=2; k<=6; k++){
            if (dp.find(n/k) == dp.end()){
                dp[n/k] = func(func, n/k);
            }
            p2 += (Y + dp[n/k])/5;            
        }
        p2 += Y/5;        
        return min(p1, p2);
    };
    dp[N] = func(func, N);
    cout << std::setprecision(24) << dp[N] << endl;

    
    return 0;
}