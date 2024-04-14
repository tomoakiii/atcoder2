#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;


int main(){
    ll l, r, nxt;
    cin >> l >> r;
    nxt=l;
    vector<pair<ll, ll>> ans;
    
    // r = 2^i*j;        

    while (r>=l){
        ll i=0, j=r, p2=1, k;
        while(j>0){
            if(j%2==0) {
                j/=2;
                i++;
                p2*=2;
            }else{
                break;
            }
        }
        nxt = p2 * (j-1);
        while (nxt < l){
            p2/=2;
            j*=2;
            nxt = p2 * (j-1);
        }        
        ans.push_back({nxt, r});
        if (nxt == l) {
            break;
        }            
        r = nxt;        
    }
    cout << ans.size() << endl;
    for( int i=ans.size()-1; i>=0; i--) {
        auto a = ans[i];
        cout << a.first << " " << a.second << endl;
    }
    return 0;
}
