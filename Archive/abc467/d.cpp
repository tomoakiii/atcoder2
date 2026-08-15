//https://atcoder.jp/contests/abc467/submissions/me

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

struct Point{
    ll x,y;
    Point(ll x = 0, ll y = 0): x(x), y(y) {}
    Point operator +(Point p) {
        return Point(x + p.x, y + p.y);
    }
    Point operator -(Point p) {
        return Point(x - p.x, y - p.y);
    }
    Point operator *(ll k) const{
        return Point(k * x, k * y);
    }
    Point &operator*=(ll k)
    {
        x *= k; y *= k;
        return *this;
    }
    Point operator /(ll k) const{
        return Point(x/k, y/k);
    }
    Point &operator/=(ll k)
    {
        x /= k; y /= k;
        return *this;
    }
};
// ベクトルの単位化
Point normalize(Point ret){
    ll g = gcd(ret.y, ret.x);
    if(g==0) return ret;
    ret.y /= g;
    ret.x /= g;
    if(ret.x < 0) {
        ret *= -1;
    }
    return ret;
}

// 内積
// 内積がゼロだと直交。同一方向ベクトルだと長さ同士の積
// dot(a,b) = abs(a) * abs(b) * cos(theta)
ll dot(Point P, Point P2){
    return P.x * P2.x + P.y * P2.y;
}

// 外積
// 用途：平行を判定  if (cross(a,b)　== 0)
// 　　dy/dx = dy'/dx' ← 二つのベクトルの傾きが同じ＝外積がゼロ。
// 用途：面積を計算
// 　　abs(cross(a,b))は、ベクトルaとbが形成する平行四辺形の面積。
// 　　これを半分にすると、ベクトルaとbがなす三角形の面積
ll cross(Point P, Point P2){
    return P.x * P2.y - P.y * P2.x;
}

// PとP2の中点を返す
Point med(Point P, Point P2){
    return (P+P2)/2;
}



bool solve(){
    Point P,Q,R,S;
    cin>>P.x>>P.y>>Q.x>>Q.y>>R.x>>R.y>>S.x>>S.y;
    P*=2, Q*=2, R*=2, S*=2;
    Point a1 = normalize(P-Q);
    Point a2 = normalize(R-S);
    if(cross(a1, a2) != 0) return true;

    auto D = med(P,Q);
    auto E = med(R,S);
    Point a3 = D-E;

    if(dot(a1, a3) == 0) return true;
    return false;
}

int main(){
    ll T; cin>>T;
    while(T--){
        if(solve()) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}