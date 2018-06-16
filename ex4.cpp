#include <bits/stdc++.h>
#define mod 1224031
using namespace std;

typedef struct node{
	node* next;
	int val;
} node;

node* hashenc[mod]; set<int> hashrb[mod];

int main(){
	int n,mode,i;
	scanf("%d%d",&n,&mode);
	if(mode==1){
		for(i=0;i<n;i++){
			int val; scanf("%d",&val);
			node* t = hashenc[val%mod];
			hashenc[val%mod]->val = val;
			hashenc[val%mod]->next = t;
		}
	} else {
		for(i=0;i<n;i++){
			int val; scanf("%d",&val);
			hashrb[val%mod].insert(val);
		}
	}

	return 0;
}