#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define pr pair<int,int>
#define mod 1000000007
#define endl "\n"
#define N 200005
int n;
vector<int> a(N);
vector<pr> seg(4*N);//,lazy(4*N);

pr add_pr(pr a,pr b)
{
	return {a.fi+b.fi,a.se+b.se};
}

void build(int pos=0,int l=0,int r=n-1)
{
	
	if(l==r)
	{
		if(l%2==0)	seg[pos]={a[l]*(l+1),a[l]};
		else		seg[pos]={-a[l]*(l+1),-a[l]};
		return;
	}
	int mid=(l+r)/2;
	build(2*pos+1,l,mid);
	build(2*pos+2,mid+1,r);
	seg[pos]=add_pr(seg[2*pos+1],seg[2*pos+2]);
}

/*
// PART OF LAZY PROPAGATION
void upd(int pos,int l, int r,int x)
{
	lazy[pos]+=x;
	seg[pos]+=(r-l+1)*x;
}

// PART OF LAZY PROPAGATION
void shift(int pos,int l,int r)
{
	int mid=(l+r)/2;
	upd(2*pos+1,l,mid,lazy[pos]);
	upd(2*pos+2,mid+1,r,lazy[pos]);
	lazy[pos]=0;
}
*/

void update(int x,int y,int v,int pos=0,int l=0,int r=n-1)
{
	if(x>r || y<l)
		return;
	if(x<=l && y>=r)
	{
		//upd(pos,l,r,v);
		if(l%2==0)	seg[pos]={v*(l+1),v};
		else	seg[pos]={-v*(l+1),-v};
		return;
	}
	//shift(pos,l,r);
	int mid=(l+r)/2;
	update(x,y,v,2*pos+1,l,mid);
	update(x,y,v,2*pos+2,mid+1,r);
	seg[pos]=add_pr(seg[2*pos+1],seg[2*pos+2]);
}

pr query(int x,int y,int pos=0,int l=0,int r=n-1)
{
	if(x>r || y<l)
		return {0,0};
	if(x<=l && y>=r)
		return seg[pos];
	//shift(pos,l,r);
	int mid=(l+r)/2;
	return add_pr(query(x,y,2*pos+1,l,mid),query(x,y,2*pos+2,mid+1,r));
}

void solve()
{
	int q,ans=0;
	cin>>n>>q;
	int i,x,y;
	char c;
	for(i=0;i<n;i++)
		cin>>a[i];
	build();
	while(q--)
	{
		cin>>c>>x>>y;
		x--;
		if(c=='Q')
		{
			y--;
			pr val=query(x,y);
			if(x%2)
				val={-val.fi,-val.se};
			int xx=val.fi-val.se*x;
			ans+=xx;
		}
		else
			update(x,x,y);
	}
	cout<<ans<<endl;
}
 
int32_t main()
{
	ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    int t=1,T=1;cin>>t;
	while(t--)
	{
		cout<<"Case #"<<T++<<": ";
		solve();
	}
	return 0;
}