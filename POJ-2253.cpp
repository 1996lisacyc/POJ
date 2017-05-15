#include <cstdio>
#include <algorithm>
#include <cmath>
#define Max 1005
using namespace std;

double dis[Max][Max];

double calculate(int n){
	for (int k=1; k <n+1; k++)
        for (int i=1; i<n+1; i++)
            for (int j=1; j<n+1; j++)
               dis[i][j] = min(dis[i][j], max(dis[i][k], dis[k][j]));
               
    return dis[1][2];
}

int main(){
	
	int n,Case=1;
	while(scanf("%d",&n)){

		if(n==0) break;
		int x[n+1],y[n+1];
		for(int i=1; i<n+1; i++) scanf("%d %d",&x[i],&y[i]);
		
		for(int i=1; i<n+1; i++){
			for(int j=0; j<n+1; j++){
				dis[i][j]=dis[j][i]=sqrt(pow(x[i]-x[j], 2) + pow(y[i]-y[j], 2));				
			} 
		} 
		
		double ans=calculate(n);
		printf("Scenario #%d\n", Case++);
        printf("Frog Distance = %.3f\n\n",ans);
	}
	return 0;
}
