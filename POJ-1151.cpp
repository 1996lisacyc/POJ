#include <cstdio>
#include <cstring>
using namespace std;

struct Node{
    double x1,y1,x2,y2;
}node[10005];

int arr[10005];
double ans;

void check(double x1,double y1,double x2,double y2,int k,int k1, int n){


    while(k<=n&&(x1>node[k].x2||x2<node[k].x1||y1>node[k].y2||y2<node[k].y1))k++;

    if(k>=n+1){
        ans+=(x2-x1)*(y2-y1);
        return;
    }

    if(x1<node[k].x1){
        check(x1, y1, node[k].x1, y2, k+1, k1, n);
        x1=node[k].x1;
    }
    if(x2>node[k].x2){
        check(node[k].x2, y1, x2, y2, k+1, k1, n);
        x2=node[k].x2;
    }
    if(y1<node[k].y1){
        check(x1, y1, x2, node[k].y1, k+1, k1, n);
        y1=node[k].y1;
    }
    if(y2>node[k].y2){
        check(x1, node[k].y2, x2, y2, k+1, k1, n);
        y2=node[k].y2;
    }
}

int main(){

    int Case=1,n;
    while(scanf("%d",&n)&&n){

        ans=0;
        memset(arr,0,sizeof(arr));

        for(int i=1; i<n+1; i++){
            scanf("%lf%lf%lf%lf",&node[i].x1,&node[i].y1,&node[i].x2,&node[i].y2);
        }

        for(int i=n; i>-1; i--){
            check(node[i].x1, node[i].y1, node[i].x2, node[i].y2, i+1, i,n);
        }

        printf("Test case #%d\n",Case++);
        printf("Total explored area: %.2lf\n\n", ans);
    }
    return 0;
}
