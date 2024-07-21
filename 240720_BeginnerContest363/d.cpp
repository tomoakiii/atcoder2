#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N, N2;
    cin >> N;    
    ll p = 1;
    ll j;
    if (N==1) {
        cout << 0 << endl;
        return 0;
    }
    N--;

    for(int i=1; i<INF; i++) {        
        ll mp = 9 * p;
        if (N > mp) N-=mp;
        else {
            N2 = p+N-1;            
            vector<char> s{};  
            while(N2){
                s.push_back('0' + (N2%10));
                N2/=10;
            }    
            reverse(s.begin(), s.end());   
            int ind;    
            if(i % 2){
                ind = s.size() - 2;
            } else {
                ind = s.size() - 1;
            }
            rep(i, s.size()) {
                cout << s[i];
            }
            for (int i = ind; i >= 0; i--){
                cout << s[i];
            }
            cout << endl;
            return 0;
        }
        if (i%2 == 0){
            p *= 10;
        }        
    }

    


    return 0;
}