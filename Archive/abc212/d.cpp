#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 
const ll INF = 0x0F0F0F0F0F0F0F0F;
int main(){
    int Q;
    cin >> Q;
    ll sumQ = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    int x;
    ll y;
    while(Q--){
        cin >> x;
        if (x==1){
            cin >> y;
            q.push({y - sumQ, sumQ});
        } else if (x==2) {
            cin >> y;
            sumQ += y;
        } else {
            auto [a, b] = q.top();
            cout << a + sumQ << endl;
            q.pop();
            
        }
    }
    return 0;
}

