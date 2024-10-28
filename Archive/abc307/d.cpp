#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    int N;
    cin >> N;
    string S;
    cin >> S;
    vector<int> v(N, 0);
    vector<int> Ind(N);
    
    vector<bool> Go(N, false);
    int lv = 0, cnt = 0;
    bool ref = false;
    rep(i, N){        
        if (S[i] == '('){
            lv++;
            Ind[lv] = i;
        }
        if (S[i] == ')'){            
            if (lv > 0){
                v[Ind[lv]] = i;
                lv--;                
            }             
        }
    }
    int ind=0;
    while(ind < N){
        if(v[ind] == 0){
            cout << S[ind];
            ind++;
        } else {
            ind = v[ind] + 1;
        }
    }
    cout << endl;
    return 0;
}