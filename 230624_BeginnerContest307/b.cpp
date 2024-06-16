#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N;
    cin >> N;
    vector<string> S(N);
    rep(i, N){
        cin >> S[i];
    }

    rep(i, N) rep(j, N) {
        if (i != j){
            string SS = S[i] + S[j];
            int l=0, r=SS.size()-1;
            bool flg = true;            
            while (l <= r){
                if (SS[l++] != SS[r--]){
                    flg = false;
                    break;
                }
            }
            if (flg) {                
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    
    cout << "No" << endl;
    return 0;
}