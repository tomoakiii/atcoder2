// https://atcoder.jp/contests/abc442/tasks/abc442_e
// 時計回りに(x,y)座標の群をソートする。
// 角度が完全に同一になるものはcross関数の返り値が0になることで判定する
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using ld = long double;
struct V {
  ll x, y; int i;
  V(ll x=0, ll y=0, int i=-1): x(x), y(y), i(i) {}
  ll cross(const V& a) const { return x*a.y - y*a.x;}
  bool up() const { return y > 0 || (y == 0 && x > 0);}
  bool operator<(const V& a) const {
    if (up() != a.up()) return up();
    return cross(a) > 0;
  }
  ll dot(const V& a) const {return x*a.x+y*a.y};
};

int main() {
    ll N; cin>>N;
    vector<ll> X(N),Y(N);
    rep(i,N) {
        cin>>X[i]>>Y[i];
    }
    rep(i,N) {
        vector<V> ang(N-1);
        int id=0;
        rep(j,N) if(i!=j) {
            ld x = X[j]-X[i];
            ld y = Y[j]-Y[i];
            ang[id++] = V(x,y);
        }
        sort(ang.begin(), ang.end());
        int l=0, r=1;
        rep(l,N-1) {
            ll c = ang[r]-ang[l];
            if(c>=91) continue;
            X
        }
        ll sm = 0;

    }


  int n, q;
  cin >> n >> q;
  vector<V> ps(n);
  rep(i,n) cin >> ps[i].x >> ps[i].y, ps[i].i = i;

  sort(ps.begin(), ps.end());
  vector<int> idx(n);
  rep(i,n) idx[ps[i].i] = i;

  vector<int> l(n), r(n,n-1);
  rep(i,n-1) if (ps[i] < ps[i+1]) l[i+1] = i+1; else  l[i+1] = l[i];
  for (int i = n-2; i >= 0; i--) {
    if (ps[i] < ps[i+1]) r[i] = i; else r[i] = r[i+1];
  }

  rep(qi,q) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    swap(a,b);
    a = l[idx[a]];
    b = r[idx[b]];
    if (a > b) b += n;
    cout << (b-a+1) << endl;
  }
  return 0;
}