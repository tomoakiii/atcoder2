#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INFi = 0x0F0F0F0F;


int main(){
    int H, W;
    cin >> H >> W;
    vector A(H, vector<ll>(W));
    vector B(H, vector<ll>(W));
    for(auto &aa:A) for(auto &a:aa) cin>>a;
    for(auto &aa:B) for(auto &a:aa) cin>>a;
    vector<int> p(H), q(W);
    for(int i=0; i<H; i++) p[i] = i;
    for(int i=0; i<W; i++) q[i] = i;
    int mn = INFi;
    do{
        do{
            bool flg = true;
            for(int i=0; i<H; i++) for(int j=0; j<W; j++) {
                if (A[p[i]][q[j]] != B[i][j]){
                    flg = false;
                }
            }
            if (flg) {
                int cnt = 0;
                for (int i=0; i<H-1; i++) for (int i2=i+1; i2<H; i2++) {
                    if (p[i] > p[i2]) cnt++;
                }
                for (int i=0; i<W-1; i++) for (int i2=i+1; i2<W; i2++) {
                    if (q[i] > q[i2]) cnt++;
                }
                mn = min(mn, cnt);
            }
        } while(next_permutation(q.begin(), q.end()));
    } while(next_permutation(p.begin(), p.end()));
    if (mn == INFi) mn = -1;
    cout << mn << endl;
    return 0;
}