#include<cstdio>
#include<cstdlib>
#include<vector>


using namespace std;


typedef long long ll;


int n;
vector<int> a;

int sign(int v)
{
	if(v<0) return -1;
	return v>0;
}


ll solve(int chk_sign)
{
	ll count=0;
	int sum=0, add, prev_sum;

	prev_sum=chk_sign;
	for(int i=0;i<n;i++)
	{
		sum+=a[i];
		if(prev_sum<0 && sum<=0)
		{
			add=-sum+1;
			sum+=add;
			count+=llabs(add);
		}
		if(prev_sum>0 && sum>=0)
		{
			add=-sum-1;
			sum+=add;
			count+=llabs(add);
		}
		prev_sum=sum;
	}
	return count;
}


ll min(ll a, ll b)
{
	if(a<b) return a;
	return b;
}


int main(void)
{
	while(scanf("%d", &n)==1)
	{
		a.resize(n);
		for(int i=0;i<n;i++)
		{
			scanf("%d", &a[i]);
		}
		printf("%lld\n", min(solve(1), solve(-1)));
	}
	return 0;
}
