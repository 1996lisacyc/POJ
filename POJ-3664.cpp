#include<cstdio>
#include <algorithm>
using namespace std;

struct cows{
	int id;
	int vt1;
	int vt2;
}cow[50000];

bool cmp1(const cows &a, const cows &b){
	return a.vt1>b.vt1;
}

bool cmp2(const cows &a, const cows &b){
	return a.vt2>b.vt2;
}

int main(){

	int n,k;
	while(scanf("%d%d",&n,&k)!=EOF){
 		int i;
 		for(i=0; i<n; i++){
 			scanf("%d%d",&cow[i].vt1,&cow[i].vt2);
 			cow[i].id=i;
		}
 		sort(cow,cow+n,cmp1);
 		sort(cow,cow+k,cmp2);
 		printf("%d\n",cow[0].id+1);
	}
    return 0;
}

