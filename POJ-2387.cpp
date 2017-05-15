#include <cstdio>
#define INF 100000
using namespace std;

int dis[4005];

void relax(int u,int v,int w){

	if(dis[u]+w<dis[v]){
		dis[v]=dis[u]+w;
	}
}

int main(){
	
	int t,n;
	while(scanf("%d%d",&t,&n)!=EOF){
		
		int t1[t+1],t2[t+1],t3[t+1];
		for(int i=1; i<t+1; i++){
			scanf("%d%d%d",&t1[i],&t2[i],&t3[i]);
		}
		
		for(int i=1; i<n; i++) dis[i]=INF;
		dis[n]=0;
		
		for(int i=0; i<n-1; i++){	
			for(int j=1; j<t+1; j++){
				relax(t1[j],t2[j],t3[j]);
				relax(t2[j],t1[j],t3[j]);
			}
		}
		
		printf("%d\n",dis[1]);
	}
	return 0;
}
