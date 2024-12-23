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

int main(){
    int N;
    ll K;
    cin >> N >> K;
    map<ll, int> mpX;
    map<ll, int> mpY;
    for (int i = 0; i < N; i++) {
        ll x, y;
        cin >> x >> y;
        mpX[x]++;
        mpY[y]++;
    }
    while(true) {
        if(mpX.size() == 1 && mpY.size() == 1) {
            cout << 0 << endl;
            return 0;
        }
        auto f = [](map<ll, int> &m)-> pair<pair<ll, int>,pair<ll, int>>{
            pair<ll,int> n1, n2;
            auto it = m.begin();
            n1 = {it->first, it->second};
            it++;
            if(it != m.end()) n2 = {it->first, it->second};
            else n2 = n1;
            return {n1,n2};
        };

        auto f2 = [](map<ll, int> &m)-> pair<pair<ll, int>,pair<ll, int>>{
            pair<ll,int> n1, n2;
            auto it = m.end();
            it--;
            n1 = {it->first, it->second};
            if(m.size()>1) {
                it--;
                n2 = {it->first, it->second};
            } else {
                n2 = n1;
            }
            return {n1,n2};
        };
        auto [n1x, n2x] = f(mpX);
        auto [n1y, n2y] = f(mpY);
        auto [m1x, m2x] = f2(mpX);
        auto [m1y, m2y] = f2(mpY);
        ll ans = max(m1x.first - n1x.first, m1y.first - n1y.first);
        ll tgt = ans - min(m1x.first - n1x.first, m1y.first - n1y.first);
        int flg = -1; // -1: same x-y, 0:nx, 1:mx, 2:ny, 3:my;
        if (tgt == 0) {
            
        } else if(m1x.first - n1x.first > m1y.first - n1y.first) {
            if(m1x.second > n1x.second) {
                flg = 0;
            } else {
                flg = 1;
            }
        } else if(m1x.first - n1x.first < m1y.first - n1y.first){
            if(m1y.second > n1y.second) {
                flg = 2;
            } else {
                flg = 3;
            }
        } else {
            if (n1x.second < m1x.second) {
                if (n1y.second < m1y.second) {
                    if (n1x.second < n1y.second) flg = 0;
                    else flg = 2;
                } else {
                    if (n1x.second < m1y.second) flg = 0;
                    else flg = 3;
                }
            } else {
                if (n1y.second < m1y.second) {
                    if (m1x.second < n1y.second) flg = 1;
                    else flg = 2;
                } else {
                    if (m1x.second < m1y.second) flg = 1;
                    else flg = 3;
                }
            }
        }
        if (flg == -1) {
            ll dst;
            ll pop = 0;
            if (n1x.second < m1x.second) {
                dst = n2x.first - n1x.first;
                pop += n1x.second;
            } else {
                dst = m1x.first - m2x.first;
                pop += m1x.second;
            }
            if (n1y.second < m1y.second) {
                chmin(dst, n2y.first - n1y.first);
                pop += n1y.second;
            } else {
                chmin(dst, m1y.first - m2y.first);
                pop += m1y.second;
            }
            ll cnt = dst * pop;
            if(cnt > K) {
                cout << ans - (K/pop) << endl;
                return 0;
            } else {
                K -= cnt;
                if (n1x.second < m1x.second) {
                    mpX.erase(n1x.first);
                    mpX[n1x.first + dst] += n1x.second;
                } else {
                    mpX.erase(m1x.first);
                    mpX[m1x.first - dst] += m1x.second;
                }
                if (n1y.second < m1y.second) {
                    mpY.erase(n1y.first);
                    mpY[n1y.first + dst] += n1y.second;
                } else {
                    mpY.erase(m1y.first);
                    mpY[m1y.first - dst] += m1y.second;
                }

            }
        } if (flg==0) {
            tgt = min(tgt, n2x. first - n1x.first);
            if (K < n1x.second * tgt) {
                ll k = K / n1x.second;
                cout << ans - k << endl;
                return 0;
            } else {
                K -= n1x.second * tgt;
                mpX.erase(n1x.first);
                mpX[n1x.first + tgt] += n1x.second;
            }
        } else if (flg == 1) {
            tgt = min(tgt, m1x.first - m2x.first);
            if (K < m1x.second * tgt) {
                ll k = K / m1x.second;
                cout << ans - k << endl;
                return 0;
            } else {
                K -= m1x.second * tgt;
                mpX.erase(m1x.first);
                mpX[m1x.first - tgt] += m1x.second;
            }
        } else if (flg==2) {
            tgt = min(tgt, n2y.first - n1y.first);
            if (K < n1y.second * tgt) {
                ll k = K / n1y.second;
                cout << ans - k << endl;
                return 0;
            } else {
                K -= n1y.second * tgt;
                mpY.erase(n1y.first);
                mpY[n1y.first + tgt] += n1y.second;
            }
        } else if (flg == 3) {
            tgt = min(tgt, m1y.first - m2y.first);
            if (K < m1y.second * tgt) {
                ll k = K / m1y.second;
                cout << ans - k << endl;
                return 0;
            } else {
                K -= m1y.second * tgt;
                mpY.erase(m1y.first);
                mpY[m1y.first - tgt] += m1y.second;
            }
        }
    }
    return 0;
}