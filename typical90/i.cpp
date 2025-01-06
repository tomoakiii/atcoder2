#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;
typedef modint1000000007 mint;
int main(){
    int N;
    cin >> N;
    vector<double> X(N), Y(N);
    auto dist = [](double x1, double y1, double x2, double y2)->double{
        return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
    };
    rep(i,N) cin>>X[i]>>Y[i];
    double ans = M_PI;
    rep(i,N) {
        vector<double> theta{};
        vector<double> theta2{};
        
        rep(j,N) {
            if(i == j) continue;
            double x = X[j] - X[i];
            double y = Y[j] - Y[i];
            
            double t;
            if (X[j] == X[i]) {
                if (y > 0) t = M_PI/2;
                else t = -M_PI/2;
            } else if (Y[j] == Y[i]) t = (x > 0) ? 0 : M_PI; 
            else {
                t = atan(y/x);
                if(x > 0 && y < 0) t+=2*M_PI;
                else if(x < 0 && y > 0) t+=M_PI;
                else if(x < 0 && y < 0) t+=M_PI;
            }
            theta.emplace_back(t);
            theta2.emplace_back(t);
            theta2.emplace_back(t + 2*M_PI);   
        }
        sort(theta2.begin(), theta2.end());
        for(auto j: theta) {
            if(i == j) continue;
            auto id = lower_bound(theta2.begin(), theta2.end(), j + M_PI);
            double t = ((*id) - j) - M_PI;
            chmin(ans, abs(t));
            id--;
            t = M_PI - ((*id) - j);
            chmin(ans, abs(t));
        }
    }
    printf("%.10f\n", (M_PI-ans) * 180 / M_PI);
    return 0;
}