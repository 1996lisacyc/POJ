#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

struct Edge{
	int a;
	int b;
	int len;
}edge[100000];

int p[1005];

bool cmp(const Edge& edge1, const Edge& edge2){
	return 	 edge1.len> edge2.len;
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
	
	int ans=0,check=0;
	sort(edge,edge+E,cmp);
	
    for (int i=0,j=0; i<n-1&&j<E; i++){

        while (Find(edge[j].a)==Find(edge[j].b)) j++;
        Union(edge[j].a, edge[j].b);
        ans+=edge[j].len;
        j++;
    }
    
    for(int i=1; i<n; i++){
    	if(Find(i)!=Find(i+1)){
    		check=1;
    		break;
		}
	}
    if(check) printf("-1\n");
    else printf("%d\n",ans);
}

int main(){
	
	int n,m;
	while(scanf("%d %d",&n,&m)!=EOF){
		
		int x,y,z,counter=0;
		
		for(int i=1; i<n+1; i++){
			p[i]=i;
		}
		
		for(int i=0; i<m; i++){
			scanf("%d %d %d",&x,&y,&z);
			edge[counter].a=x;
			edge[counter].b=y;
			edge[counter++].len=z;
		}
		
		Kruskal(n,counter);
	}
	return 0;
}


