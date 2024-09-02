#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;
using mint = modint998244353;

int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  rep(i,N) {
    cin>>A[i];
    A[i]--;
  }
  int ind;
  vector<bool> visit(N, false);
  auto f=[&](auto f, int cur)->void{
    if (visit[cur]) {
      ind = cur;
      return;
    }
    visit[cur] = true;
    int nx = A[cur];
    f(f, nx);
  };
  f(f, 0);
  int cnt = 0;
  vector<bool> visit2(N, false);
  auto f2=[&](auto f2, int cur)->void{
    cnt++;
    visit2[cur] = true;
    int nx = A[cur];
    if (nx == ind) {
      return;
    }
    f2(f2, nx);
  };
  f2(f2, ind);

  ll ans = cnt * cnt;
  rep(i,N) {
    if (visit2[i]) continue;
    int cnt2 = 0;
    auto f3=[&](auto f3, int cur)->void{
      cnt2++;
      if (visit2[cur]) {
        return;
      }
      int nx = A[cur];
      f3(f3, nx);
    };
    f3(f3, i);
  ans += (cnt2*cnt2-1);
  }
  cout << ans << endl;
  return 0;
}