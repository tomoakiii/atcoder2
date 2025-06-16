#include <bits/stdc++.h>
using namespace std;
int main(){
 long long N;
 cin >> N;
 long long k = 1;
 int cnt = 0;
 while (true) {
   k *= 2;
   cnt ++ ;
   if (k > N) {
     cout << cnt-1 << endl;
     return 0;
   }
 }
 return 0;
}