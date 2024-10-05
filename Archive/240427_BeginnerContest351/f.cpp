#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

template<typename T=int>
struct CC {
  bool initialized;
  vector<T> xs;
  CC(): initialized(false) {}
  void add(T x) { xs.push_back(x);}
  void init() {
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(),xs.end()),xs.end());
    initialized = true;
  }
  int operator()(T x) {
    if (!initialized) init();
    return upper_bound(xs.begin(), xs.end(), x) - xs.begin() - 1;
  }
  T operator[](int i) {
    if (!initialized) init();
    return xs[i];
  }
  int size() {
    if (!initialized) init();
    return xs.size();
  }
};


int main(){
    int N;
    cin >> N;
    vector<ll> A(N);
    CC cc;
    for (auto &a: A) {
        cin >> a;
        cc.add(a);
    }
    fenwick_tree<ll> ft(N);
    fenwick_tree<ll> ft2(N);
    ll sm = 0;
    for (int j = 0; j < N; j++){
        ll a = A[j];
        int cca = cc(a);
        ft.add(cca, a);
        ft2.add(cca, 1);
        sm += ft2.sum(0, cca) * a;
        sm -= ft.sum(0, cca);
    }
    cout << sm << endl;
    return 0;
}