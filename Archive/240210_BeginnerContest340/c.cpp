#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;

int main(){
    ll N;
    cin >> N;
    priority_queue<ll> qq;
    qq.push(N);
    map<ll, ll> mp;
    long long sum = 0;
    mp[N]=1;
    while (!qq.empty()){
        ll q=qq.top();
        ll q1 = q/2, q2 = (q+1)/2;
        qq.pop();
        if(mp.find(q1)==mp.end() && q1>1){
            qq.push(q1);
        }
        mp[q1]+=mp[q];
        if(mp.find(q2)==mp.end() && q2>1){
            qq.push(q2);
        }
        mp[q2]+=mp[q];
        sum+=q*mp[q];
    }

    cout<<sum<<endl;
    return 0;
}

