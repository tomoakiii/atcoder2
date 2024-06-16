#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    int H, W;
    cin >> H >> W;
    string s;
    vector G(H, vector<bool>(W));
    vector<int> col(W), row(H);
    rep(i, H){
        cin >> s;
        rep(j, W){
            if(s[j]=='#'){
                G[i][j] = true;
                row[i]++;
                col[j]++;
            }
        }
    }
    
    int mnc=INFi, mnr=INFi, mnci, mnri;
    rep(i, H){
        if(row[i] == 0) continue;
        if(mnr > row[i]){
            mnr = row[i];
            mnri = i;
        }
    }
    rep(i, W){
        if(col[i] == 0) continue;
        if(mnc > col[i]){
            mnc = col[i];
            mnci = i;
        }
    }
    
    cout << mnri+1 << " " << mnci+1 << endl;
    return 0;
}