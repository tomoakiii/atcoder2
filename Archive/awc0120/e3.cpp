/* -*- coding: utf-8 -*-
 *
 * e.cc: E - Pattern Search in DNA Sequences
 */

#include<cstdio>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<algorithm>

using namespace std;

/* constant */

const int MAX_N = 100000;
const int MAX_QN = 200000;
const int MAX_L = 500000;
const int P0 = 4073;
const int P1 = 5011;
const int MOD = 2147483629;

/* typedef */

using ll = long long;
using vi = vector<int>;
using sl = set<ll>;
using mli = map<ll,int>;

/* typedef */

template<const int MOD>
struct MI {
  int v;
  MI(): v() {}
  MI(int _v): v(_v % MOD) { if (v < 0) v += MOD; }
  MI(long long _v): v(_v % MOD) { if (v < 0) v += MOD; }

  explicit operator int() const { return v; }
  
  MI operator+(const MI m) const { return MI((long long)v + m.v); }
  MI operator-(const MI m) const { return MI((long long)v + (MOD - m.v)); }
  MI operator-() const { return MI(MOD - v); }
  MI operator*(const MI m) const { return MI((long long)v * m.v); }

  MI &operator+=(const MI m) { return (*this = *this + m); }
  MI &operator-=(const MI m) { return (*this = *this - m); }
  MI &operator*=(const MI m) { return (*this = *this * m); }

  bool operator==(const MI m) const { return v == m.v; }
  bool operator!=(const MI m) const { return v != m.v; }

  MI pow(int n) const {  // a^n % MOD
    MI pm = 1, a = *this;
    while (n > 0) {
      if (n & 1) pm *= a;
      a *= a;
      n >>= 1;
    }
    return pm;
  }

  MI inv() const { return pow(MOD - 2); }
  MI operator/(const MI m) const { return *this * m.inv(); }
  MI &operator/=(const MI m) { return (*this = *this / m); }
};

using mi = MI<MOD>;
using vmi = vector<mi>;

/* global variables */

vmi pes0, invpes0, pes1, invpes1;
int cmap[128];
char s[MAX_L + 4];
string ss[MAX_N];
ll phs[MAX_QN];
int ops[MAX_QN], res[MAX_QN];
sl shs[MAX_N];
vi qvs[MAX_N];

/* subroutines */

inline void prep_rhash(int n, int p, vmi &pes, vmi &invpes) {
  pes.resize(n + 1), invpes.resize(n + 1);
  pes[0] = invpes[0] = 1;
  pes[1] = p;
  invpes[1] = pes[1].inv();
  for (int i = 2; i <= n; i++) {
    pes[i] = pes[i - 1] * p;
    invpes[i] = invpes[i - 1] * invpes[1];
  }
}

inline vmi s2rh(vmi &pes, vmi &invpes, const string &s) {
  int n = s.size();
  vmi rh(n + 1, 0);
  for (int k = 0; k < n; k++) {
    rh[k + 1] = rh[k] + pes[k] * cmap[s[k]];
  }
  return rh;
}

inline mi rhash(vmi &pes, vmi &invpes, vmi &rh, int i, int j) {
  return (rh[j] - rh[i]) * invpes[i];
}

ll llrhash(vmi &pes0, vmi &invpes0, vmi &rh0,
	   vmi &pes1, vmi &invpes1, vmi &rh1, int i, int j) {
  auto h0 = (int)rhash(pes0, invpes0, rh0, i, j);
  auto h1 = (int)rhash(pes1, invpes1, rh1, i, j);
  return ((ll)h0 << 32) | h1;
}

mi revsub(vmi &pes, vmi &invpes, vmi &prh, vmi &rprh, int l, int r) {
  int m = prh.size() - 1;
  return
    rhash(pes, invpes, prh, 0, l) +
    rhash(pes, invpes, rprh, m - r, m - l) * pes[l] +
    rhash(pes, invpes, prh, r, m) * pes[r];
}

ll llrevsub(vmi &pes0, vmi &invpes0, vmi &prh0, vmi &rprh0,
	    vmi &pes1, vmi &invpes1, vmi &prh1, vmi &rprh1,
	    int l, int r) {
  auto h0 = (int)revsub(pes0, invpes0, prh0, rprh0, l, r);
  auto h1 = (int)revsub(pes1, invpes1, prh1, rprh1, l, r);
  return ((ll)h0 << 32) | h1;
}

/* main */

int main() {
  prep_rhash(MAX_L, P0, pes0, invpes0);
  prep_rhash(MAX_L, P1, pes1, invpes1);
  cmap['H'] = 3, cmap['M'] = 5, cmap['L'] = 7;
  
  int n, qn;
  scanf("%d%d%s", &n, &qn, s);

  string p(s);
  int m = p.size();
  auto prh0 = s2rh(pes0, invpes0, p);
  auto prh1 = s2rh(pes1, invpes1, p);
  reverse(p.begin(), p.end());
  auto rprh0 = s2rh(pes0, invpes0, p);
  auto rprh1 = s2rh(pes1, invpes1, p);
  
  for (int i = 0; i < n; i++) {
    scanf("%s", s);
    ss[i] = string(s);
  }

  for (int i = 0; i < qn; i++) {
    int j, l, r;
    scanf("%d%d%d", &j, &l, &r);
    j--, l--;

    ops[i] = j;
    phs[i] = llrevsub(pes0, invpes0, prh0, rprh0,
		      pes1, invpes1, prh1, rprh1, l, r);
    shs[j].insert(phs[i]);
    qvs[j].push_back(i);
  }

  for (int k = 0; k < n; k++) {
    if (! qvs[k].empty()) {
      auto srh0 = s2rh(pes0, invpes0, ss[k]);
      auto srh1 = s2rh(pes1, invpes1, ss[k]);
      int l = ss[k].size();
      mli hcs;
      for (int i = 0, j = m; j <= l; i++, j++) {
	ll h = llrhash(pes0, invpes0, srh0,
		       pes1, invpes1, srh1, i, j);
	if (shs[k].count(h)) hcs[h]++;
      }
      for (auto i: qvs[k]) res[i] = hcs[phs[i]];
    }
  }

  for (int i = 0; i < qn; i++) printf("%d\n", res[i]);
  
  return 0;
}

