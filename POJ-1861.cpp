#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct Edge{
	int a;
	int b;
	int len;
}edge[15005];

int p[15005];

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
	
	sort(edge,edge+E,cmp);
	vector<Edge> record;
	
    for (int i=0,j=0; i<n-1&&j<E; i++){

        while (Find(edge[j].a)==Find(edge[j].b)) j++;
        Union(edge[j].a, edge[j].b);
        record.push_back(edge[j]);
        j++;
    }
    
    printf("%d\n", (record.end()-1)->len);
	printf("%d\n", record.size());
	for(int i=0; i<record.size(); i++){
		printf("%d %d\n", record[i].a, record[i].b);
	}
    
}

int main(){
	
	int n,m;
	while(scanf("%d %d",&n,&m)==2){

		for(int i=0; i<n+1; i++){
			p[i]=i;
		}
		
		for(int i=0; i<m; i++){
			scanf("%d %d %d",&edge[i].a,&edge[i].b,&edge[i].len);
		}
		
		Kruskal(n,m);
	}
	return 0;
}
