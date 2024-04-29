#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;


int main(){
    int N;
    cin >> N;
    vector<ll> A(N);
    stack<ll> A2;
    for(int i=0; i<N; i++) {        
        cin >> A[i];
    }
    for(int i=0; i<N; i++){
        ll a = A[i];
        if (A2.empty()) {
            A2.push(a);
            continue;
        }
        ll m = a;
        while(!A2.empty()){            
            if (A2.top() != m){                
                break;
            } else {
                A2.pop();
                m++;
            }
        }
        A2.push(m);
    }

    cout << A2.size() << endl;
    return 0;
}