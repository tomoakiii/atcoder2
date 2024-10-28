#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N;
    cin >> N;
    string S;
    cin >> S;
    set<char> s;
    for(int i=0; i<N;i++) {
        s.insert(S[i]);
        if (s.size() == 3){
            cout << i+1 << endl;
            return 0;
        }
    }    
    return 0;
}