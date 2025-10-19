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
struct abc{
    ll a,b,c;
};
int main(){
    ll N;
    cin >> N;
    vector<ll> X(N), Y(N);
    rep(i,N) cin>>X[i]>>Y[i];
    std::random_device rd;
    
    rep(k, 10) {        
        rd();
        std::uniform_int_distribution<int> dist(0,N-1);
        int p0 = dist(rd);
        rd();
        int p1 = dist(rd);
            
        auto make_ab = [&X, &Y](int p0, int p1)-> abc{
            // return abc for a*x + b*y + c = 0
            ll dX = X[p0] - X[p1];
            ll dY = Y[p0] - Y[p1];
            abc out;
            if(dX == 0) { // X = X[p0]
                out.a = 1;
                out.b = 0;
                out.c = -1 * X[p0];
                return out;
            } else if (dY == 0) { // Y = Y[p0];
                out.a = 0;
                out.b = 1;
                out.c = -1 * Y[p0];
                return out;
            }
            ll g = gcd(dX, dY);
            dX /= g, dY /= g;
            if(dX < 0) {
                dX*=-1;
                dY*=-1;
            }
            // y = dY/dX * x + c / dX;
            // dY * x - dX * U + c = 0
            out.a = dY, out.b = -1*dX, out.c = dX*Y[p0] - dY*X[p0];;
            return out; 
        };

        auto ab = make_ab(p0, p1);
        int cnt = 0;
        rep(i,N) {
            if(i==p0) {
                cnt++;
                continue;
            }
            auto ab2 = make_ab(i, p0);
            if (ab.a == ab2.a && ab.b == ab2.b && ab.c == ab2.c) cnt++;
        }
        if(cnt > N/2) {
            cout << "Yes" << endl;
            cout << ab.a << " " << ab.b << " " << ab.c << endl;
            return 0;
        }        
    }
    cout << "No" << endl;

    return 0;
}