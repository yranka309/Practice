#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define pr pair<int,int>
#define mod 1000000007
#define endl "\n"
int T=1;
int v[4000];
set<int> s;

void solve()
{
	int n,sum=0,mini=200,maxi=-200;
	cin>>n;
	int a[n],i,j,ans=0;
	unordered_map<int,int>  mp;
	for(i=0;i<n;i++)
	{
	    cin>>a[i];
	    sum+=a[i];
	    mini=min(mini,sum);
	    if(s.count(sum))	ans++;
	    for(j=0;j<4000;j++)
	    {
	        int x=sum-v[j];
	        if(x<mini)    break;
	        //if(mp.find(x)!=mp.end())
	        ans+=mp[x];
	    }
	    mp[sum]++;
	}
	cout<<ans<<endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	int t=1;cin>>t;
	for(int i=0;i<4000;i++) v[i]=(i*i),s.insert(i*i);
	while(t--)
	{
		cout<<"Case #"<<T++<<": ";
		solve();
	}
	return 0;
}