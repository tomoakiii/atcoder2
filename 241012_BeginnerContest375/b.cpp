#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (ll i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(void){
    int N;
    double ans = 0;
    cin >> N;
    double x=0, y=0;
    rep(i,N) {
        double nx, ny;
        cin >> nx >> ny;
        double dx = nx - x, dy = ny - y;
        x = nx, y = ny;
        ans += sqrt((dx*dx) + (dy*dy));
    }
    ans += sqrt(x*x + y*y);
    std::cout << std::setprecision(24) <<  ans << endl;
    return 0;
}