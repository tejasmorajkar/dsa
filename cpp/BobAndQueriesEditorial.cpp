#include <bits/stdc++.h>
using namespace std;

const int N = 500003;
int a[N]={0};
int tree[4*N]={0};

void update1(int n, int st, int en, int x)
{
	if(st==en)
	{
		a[x]++;
		tree[n]++;
	}
	else
	{
		int mid = (st+en)/2;
		if(st<=x && x<=mid)
		{
			update1(2*n,st,mid,x);
		}
		else
		{
			update1(2*n+1,mid+1,en,x);
		}
		tree[n] = tree[2*n]+tree[2*n+1];
	}
}

void update2(int n, int st, int en, int x)
{
	if(st==en)
	{
		if(a[x]==0)
		return;
		a[x]--;
		tree[n]--;
	}
	else
	{
		int mid = (st+en)/2;
		if(st<=x && x<=mid)
		{
			update2(2*n,st,mid,x);
		}
		else
		{
			update2(2*n+1,mid+1,en,x);
		}
		tree[n] = tree[2*n]+tree[2*n+1];
	}
}

int query(int n, int st, int en, int l, int r)
{
	if(r<st || en<l)
	{
		return 0;
	}
	if(l<=st && en<=r)
	{
		return tree[n];
	}
	
	int mid = (st+en)/2;
	int p1,p2;
	p1 = query(2*n, st, mid, l, r);
	p2 = query(2*n+1, mid+1, en, l, r);
	return (p1+p2);
}
int main()
{
	int n, q;
	scanf("%d%d",&n,&q);
	int tp, x, l, r, ans;
	while(q--)
	{
		scanf("%d",&tp);
		if(tp==1)
		{
			scanf("%d",&x);
			update1(1, 1, n, x);
		}
		else if(tp==2)
		{
			scanf("%d",&x);
			update2(1 ,1 ,n ,x);
		}
		else
		{
			scanf("%d%d",&l,&r);
			ans = query(1, 1, n, l, r);
			printf("%d\n",ans);
		}
	}
	return 0;
}