#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct Edge{
	int a;
	int b;
	int len;
}edge[10005];

int p[10005];

bool cmp(const Edge& edge1, const Edge& edge2){
	return 	 edge1.len< edge2.len;
}

int Find(int x){

    if (x==p[x])
        return x;
    return p[x]=Find(p[x]);
}

void Union(int x, int y){

    x=Find(x);
    y=Find(y);

    if (x!=y) {
        p[x]=y;
    }
}

void Kruskal(int n,int E){
	
	int ans=0;
	sort(edge,edge+E,cmp);
    for (int j=0; j<E; j++){

        if(Find(edge[j].a)!=Find(edge[j].b)){
        	Union(edge[j].a, edge[j].b);
        	ans+=edge[j].len;
		}
    }
    
    printf("%d\n",ans);
}

int main(){
	
	int N;
	while(scanf("%d",&N)!=EOF){

		int M,x,y,counter=0;
		
		for(int i=0; i<N+1; i++){
			p[i]=i;
		}
		
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				scanf("%d",&x);
				edge[counter].a=i+1;
				edge[counter].b=j+1;
				edge[counter++].len=x;
			}
		}
		
		scanf("%d",&M);
		
		for(int i=0; i<M; i++){
			scanf("%d %d", &x, &y);
			Union(x, y);
		}
		
		Kruskal(N-M,counter);
	}
	return 0;
}
