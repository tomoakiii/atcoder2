#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll W, H;
    cin >> W >> H;
    ll N;
    cin >> N;
    vector<pair<ll, ll>> pq(N, {0,0}), pq2(N, {0,0});
    rep(i,N){
        cin >> pq[i].first >> pq[i].second;        
    }
    sort(pq.begin(), pq.end()); // x
    rep(i,N){
        pq2[i].first = pq[i].second;
        pq2[i].second = pq[i].first;
    }    
    ll A, B;
    cin >> A;
    vector<ll> a(A+2, 0);
    for(int i=1; i<=A; i++) cin >> a[i];
    a[A+1] = W;
    cin >> B;
    vector<ll> b(B+2, 0);
    for(int i=1; i<=B; i++) cin >> b[i];
    b[B+1] = H;

    ll mx=0, mn=INF, cnt=0;
    set<pair<ll,ll>> st;
    ll lx1=-1, lx2=-1, ly1=-1, ly2=-1;
    int indx, indy;
    int ind1, ind2;            
    rep(i, N) {
        if (lx1 <= pq[i].first && pq[i].first <= lx2) {
        } else {
            ly1=-1, ly2=-1;
            auto itx = lower_bound(a.begin(), a.end(), pq[i].first);
            indx = distance(a.begin(), itx);

            auto f = [&](ll key)->int{
                int ok, ng;
                ok = N-1;
                ng = 0;
                while(ok-ng > 1) {
                    int mid = (ok+ng)/2;
                    if (pq[mid].first > key) ok = mid;
                    else ng = mid;
                }
                return ok;
            };
            lx1 = a[indx-1];
            lx2 = a[indx];
            if (pq[0].first > lx1) {
                ind1 = 0;
            } else {
                ind1 = f(lx1);
            }            
            if (lx2 > pq[N-1].first) {
                ind2 = N;
            } else {
                ind2 = f(lx2);
            }
            sort(pq2.begin()+ind1, pq2.begin()+ind2);
        }

        if (ly1 <= pq[i].second && pq[i].second <= ly2) {
        } else {
            cnt++;
            auto ity = lower_bound(b.begin(), b.end(), pq[i].second);
            indy = distance(b.begin(), ity);
            ly1 = b[indy-1];
            ly2 = b[indy];

            auto f2 = [&](ll key)->int{
                int ok, ng;
                ok = ind2;
                ng = ind1;
                while(ok-ng > 1) {
                    int mid = (ok+ng)/2;
                    if (pq2[mid].first > key) ok = mid;
                    else ng = mid;
                }
                return ok;
            };
            
            int ind3, ind4;
            if (pq2[ind1].first > ly1) {
                ind3 = ind1;
            } else {
                ind3 = f2(ly1);
            } 

            if (ly2 > pq2[ind2-1].first) {
                ind4 = ind2;
            } else {
                ind4 = f2(ly2);
            }
            ll x = ind4 - ind3;
            mx = max(x, mx);
            mn = min(x, mn);
        }
    }
    if (cnt < (A+1)*(B+1)) {
        mn = 0;
    }    
    cout << mn << " " << mx << endl;
    return 0;
}