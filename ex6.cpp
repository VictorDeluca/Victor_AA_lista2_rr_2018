#include <bits/stdc++.h>
#define INF 99999999
using namespace std;

pair<int,int> matrizes[1000];
int adapted[1001];
int dp[1001][1001];

int solve(int l, int r){
	if(l==r) return 0;
	if(dp[l][r]!=-1) return dp[l][r]; 

	int i, ans = INF;
	for(i=l;i<r;i++){
		int cost = solve(l,i) + solve(i+1,r) + adapted[l-1]*adapted[i]*adapted[r];
		if(cost < ans) ans = cost;
	}

	return dp[l][r] = ans;
}



int main(){
	int n,i,j;
	memset(dp,-1,sizeof(dp));

	scanf("%d",&n);
	for(i=0;i<n;i++){
		int h,v; scanf("%d%d",&h,&v);
		matrizes[i] = make_pair(h,v);
	}

	adapted[0] = matrizes[0].first;
	for(i=1;i<n;i++){
		if(matrizes[i].first != matrizes[i-1].second) break;
		else adapted[i] = matrizes[i].first;
	}

	if(i!=n){
		printf("Impossivel realizar multiplicacoes\n");
	}else {
		adapted[i] = matrizes[i-1].second;
		int ans = solve(1,n);
		printf("%d\n",ans);
	}

	return 0;
}