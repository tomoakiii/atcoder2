#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N;
  cin >> N;
  N++;
  vector<int> digits;
  while(N>0){
    digits.push_back(N%10);
    N/=10;
  }
  reverse(digits.begin(), digits.end());
  int Nlen = digits.size();
  long long ans = 0;
  
  // dp [keeping same num] [digits length] [max dig sum + 1] [dig remain] 
  for (int dsum = 1; dsum <= Nlen*9; dsum++){
    vector<vector<vector<vector<long long>>>> dp;
    dp.resize(2, vector<vector<vector<long long>>>(Nlen+1, vector<vector<long long>>(dsum+1, vector<long long>(dsum, 0))));
    dp[0][0][0][0] = 1;
    for (int k = 0; k < Nlen; k++) for (int i = 0; i <= dsum; i++) for (int r = 0; r < dsum; r++){
        for (int d = 0; d <= 9; d++){
          if (i+d > dsum) continue;
          for (int flg = 0; flg <= 1; flg++){
            int nflg = flg;
            if (flg == 0){
              if (d > digits[k]) continue;
              if (d < digits[k]){
                nflg = 1;
              }
            }
            if (dp[flg][k][i][r] > 0) {
              int a;
              a=1;
            }
            dp[nflg][k+1][i+d][(10*r+d)%dsum] += dp[flg][k][i][r];
          }
        }
    }
    ans += dp[1][Nlen][dsum][0];
  }

  cout << ans << endl;
  return 0;
}