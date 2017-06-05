#include <cstdio>
#include <cstring>
using namespace std;

struct Node{
    int x,y;
}node[10005];

int arr[10005];

void check(int x1,int y1,int k,int k1, int n){

    while(k<=n&&(y1<node[k].x||x1>node[k].y))k++;

    if(k>=n+1){
        arr[k1]+=(y1-x1+1);
        return;
    }
    if(x1<node[k].x){
        check(x1, node[k].x-1, k+1, k1, n);
    }
    if(y1>node[k].y){
        check(node[k].y+1, y1, k+1, k1, n);
    }
}

int main(){

    int t;
    scanf("%d",&t);
    while(t--){

        int n,ans=0;
        memset(arr,0,sizeof(arr));
        scanf("%d",&n);

        for(int i=1; i<n+1; i++){
            scanf("%d%d",&node[i].x,&node[i].y);
        }

        for(int i=n; i>0; i--){
            check(node[i].x, node[i].y, i+1, i,n);
        }

        for(int i=1; i<n+1; i++){
            if(arr[i]) ans++;
        }

        printf("%d\n", ans);
    }
    return 0;
}
