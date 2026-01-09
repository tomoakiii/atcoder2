// https://atcoder.jp/contests/abc016/tasks/abc016_4

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

struct Point {
    ll x, y;
    Point(ll x = 0, ll y = 0): x(x), y(y) {}
    Point operator +(Point p) {
        return Point(x + p.x, y + p.y);
    }
    Point operator -(Point p) {
        return Point(x - p.x, y - p.y);
    }
    ll abs() {
        return sqrt(x * x + y * y);
    }
    ll dot(Point p) {
        return x * p.x + y * p.y;
    }
    ll cross(Point p) {
        return x * p.y - y * p.x;
    }
};

int main(){
    ll Ax,Ay,Bx,By;
    cin >> Ax >> Ay >> Bx >> By;
    ll N; cin>>N;
    vector<ll> X(N),Y(N);
    rep(i,N) cin>>X[i]>>Y[i];
    X.push_back(X[0]);
    Y.push_back(Y[0]);
    int cnt = 0;
    Point a(Ax, Ay);
    Point b(Bx, By);
    Point ab = b-a;
    rep(i,N) {
        Point c(X[i],Y[i]);
        Point d(X[i+1],Y[i+1]);
        Point ac = c-a, ad = d-a, ca = a-c, cd = d-c, cb = b-c;
        if(ab.cross(ac) * ab.cross(ad) < 0 && cd.cross(ca) * cd.cross(cb) < 0) cnt++;
    }
    cout << cnt/2 + 1 << endl;

    return 0;
}