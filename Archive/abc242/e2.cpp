#include<iostream>
#include<algorithm>
#include<atcoder/modint>
using namespace std;
using mint=atcoder::modint998244353;
int T,N;
string S;
mint p26[1<<20];
int main()
{
	p26[0]=1;
	for(int i=1;i<1<<20;i++)p26[i]=p26[i-1]*26;
	cin>>T;
	for(;T--;)
	{
		cin>>N>>S;
		mint ans=0;
		for(int i=0;i<(N+1)/2;i++)
		{
			int len=(N+1)/2-i-1;
			ans+=(S[i]-'A')*p26[len];
		}
		string L=S.substr(0,N/2);
		string R=L;
		reverse(R.begin(),R.end());
		if(N%2==1)L+=S[N/2];
		L+=R;
		if(L<=S)ans++;
		cout<<ans.val()<<"\n";
	}
    return 0;
}
