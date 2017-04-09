#include <cstdio>
#include <algorithm> 
using namespace std;

const int N=3410, W=13000;
struct Item{
	int cost;
	int weight;
}items[N];
int c[W + 1];
 
void knapsack(int n, int w){
 
    for (int i = 0; i < n; ++i){
        for (int j = w; j -items[i].weight>= 0; --j){
        	c[j] = max(c[j], c[j -items[i].weight] + items[i].cost);
		}
    }
}

int main(){
	int w,num;
	while(scanf("%d%d",&num,&w)!=EOF){
		
		for(int i=0; i<13000; i++) c[i]=0;
		for(int i=0; i<num; i++) scanf("%d%d",&items[i].weight,&items[i].cost);
		knapsack(num,w); 
		
		printf("%d\n",c[w]);
	}
	return 0;
}
