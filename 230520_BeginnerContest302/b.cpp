#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll H,W;
    cin >> H >> W;

    vector<string> S(H);
    int ansx[5], ansy[5];

    rep(i,H) cin>>S[i];
    int dy[] = {1, -1, 0,  0, 1, -1,  1, -1};
    int dx[] = {0,  0, 1, -1, 1, -1, -1,  1};
    rep(i,H) rep(j,W){       
        rep(k, 8) {
            int x=j, y=i; 
            string s = "";
            rep(p, 5){
                if (x<0 || x>=W || y<0 || y>=H) break;
                s += S[y][x];
                ansy[p] = y;
                ansx[p] = x;
                x += dx[k];
                y += dy[k];
            }
            if(s == "snuke"){
                rep(i,5) {
                    cout << ansy[i]+1 << " " << ansx[i]+1 << endl;
                }
            }
        }        
    }
    return 0;
}