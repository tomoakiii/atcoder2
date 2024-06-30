#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    string S, T;
    cin >> S >> T;
    for(int w=1; w<S.size(); w++){        
        for(int c=0; c<w; c++){
            string T2 = "";
            for(int i=c; i<S.size(); i+=w){
                T2 += S[i];
            }
            if (T==T2) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }    
    cout << "No" << endl;
    return 0;
}