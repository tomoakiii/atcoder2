#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;

ll gcd(ll a, ll b){
  if(a%b == 0){
    return b;
  }else{
    return gcd(b, a%b);
  }
}

ll lcm(ll a, ll b){
  return a*b / gcd(a, b);
}

int main(){
    ll N, M, K;
    cin >> N >> M >> K;
    if (N > M) swap(N, M);
    ll l = lcm(N, M);
    ll nc = l/N, mc = l/M;
    ll p = (nc - 1) + (mc - 1);
    K += (K-1)/p;
    p++;
    ll Kp = K / p, rem = K % p;
    ll stt = l * Kp;
    ll nn=1, mm=0;
    ll ad = N*nn;
    rem--;
    while ((rem--)>0){
        if (N*(nn+1) > M*(mm+1)){
            mm++;
            ad = M*mm;
        } else {
            nn++;
            ad = N*nn;
        }
    }
    cout << stt+ad << endl;
    return 0;
}

