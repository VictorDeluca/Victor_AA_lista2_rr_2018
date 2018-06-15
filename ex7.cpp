#include <bits/stdc++.h>
#define INF 99999999
using namespace std;

int v,e; int graph[10][10]; vector<int> empty;
int from,to;

pair<int,vector<int> > solve(int mask, int prev){
	if(prev==to) return make_pair(0,empty);

	int i,j; pair<int,vector<int> > ans = make_pair(INF,empty);
	for(i=0;i<v;i++){
		if(!(mask&(1<<i)) && graph[prev][i]!=INF){
			pair<int,vector<int> > helper = solve(mask|(1<<i),i);
			helper.first += graph[prev][i];
			if(helper.first < ans.first){
				ans = helper;
				ans.second.push_back(i);
			}
		}
	}

	return ans;
}


int main(){
	int i,j; empty.clear();
	for(i=0;i<10;i++) for(j=0;j<10;j++) graph[i][j] = INF;
	scanf("%d%d",&v,&e);
	for(i=0;i<e;i++){
		int x,y,z; scanf("%d%d%d",&x,&y,&z); x--; y--;
		graph[x][y] = z;
	}
	scanf("%d%d",&from,&to); from--; to--;

	pair<int,vector<int> > ans = solve((1<<from),from);
	ans.second.push_back(from);

	if(ans.first == INF){
		printf("Caminho inexistente\n");
	} else{
		printf("Custo: %d\nCaminho: ",ans.first);
		for(i=0;i<ans.second.size() - 1;i++){
			printf("%d <- ",ans.second[i]+1);
		}
		printf("%d\n",ans.second[i]+1);
	}

	return 0;
}
