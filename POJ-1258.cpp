#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

struct Edge{
	int a;
	int b;
	int len;
}edge[100*100];

int p[105];

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
	
    for (int i=0,j=0; i<n-1&&j<E; i++){

        while (Find(edge[j].a)==Find(edge[j].b)) j++;
        Union(edge[j].a, edge[j].b);
        ans+=edge[j].len;
        j++;
    }
    printf("%d\n",ans);
}

int main(){
	
	int n;
	while(scanf("%d",&n)!=EOF){
		
		int x,counter=0;
		
		for(int i=0; i<n; i++){
			p[i]=i;
		}
		
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				scanf("%d",&x);
				edge[counter].a=i;
				edge[counter].b=j;
				edge[counter++].len=x;
			}
		}
		
		Kruskal(n,counter);
	}
	return 0;
}


