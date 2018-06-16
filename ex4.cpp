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
		int start = clock();
		for(i=0;i<n;i++) hashenc[i] = NULL;

		for(i=0;i<n;i++){
			int val; scanf("%d",&val);
			node* t = (node*)malloc(sizeof(node));
			t->next = hashenc[val%mod];
			t->val = val;
			hashenc[val%mod] = t;
		}

		int end = clock();
		double dif = (end - start)*1000; dif/=CLOCKS_PER_SEC;
		printf("%6lf\n",dif);
	} else {
		int start = clock();
		for(i=0;i<n;i++){
			int val; scanf("%d",&val);
			hashrb[val%mod].insert(val);
		}

		int end = clock();
		double dif = (end - start)*1000; dif/=CLOCKS_PER_SEC;
		printf("%6lf\n",dif);
	}

	return 0;
}
