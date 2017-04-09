#include <cstdio>
#include <iostream>
using namespace std;

int main(){

	int n;
	while(scanf("%d",&n)!=EOF){
		int arr[n],lis[n],tem=0;
		for(int i=0; i<n; i++) arr[i]=lis[i]=0;
		for(int i=0; i<n; i++) scanf("%d",&arr[i]);
		
		for(int i=0; i<n; i++){
			lis[i]=1;
			for(int j=0; j<i; j++){
				if(arr[j]<arr[i]&&lis[j]+1>lis[i]) lis[i]=lis[j]+1;
			}
		}
		tem=lis[0];
		for(int i=1; i<n; i++){
			if(tem<lis[i]) tem=lis[i];
		}
		printf("%d\n",tem);
	}
	return 0;
}
