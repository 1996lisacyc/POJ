#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 1000000000
using namespace std;

int s[1000005];

struct Node{
    int valmax,valmin;
    Node *l,*r;

    void update(int v){
        valmin=v;
        valmax=v;
    }

    void pull(){
        valmax=max(l->valmax, r->valmax);
        valmin=min(l->valmin,r->valmin);
    }
};

Node* build(int L,int R){

    Node* now=new Node();

    if(L==R){
        now->update(s[L]);
        return now;
    }

    int mid=(L+R)>>1;
    now->l=build(L,mid);
    now->r=build(mid+1,R);
    now->pull();
    return now;
}

int querymax(Node* now, bool range, int L, int R, int x, int y){

    if(x>R||y<L){
        if(range) return -INF;
        else return INF;
    }

    if(x<=L&&y>=R){
        if(range) return now->valmax;
        else return now->valmin;
    }

    int mid=(L+R)>>1;

    if (range) return max(querymax(now->l, 1, L, mid, x, y), querymax(now->r, 1, mid+1, R, x, y));
    else  return min(querymax(now->l, 0, L, mid, x, y), querymax(now->r, 0, mid+1, R, x, y));
}

int main(){

    int n,q;
    while(scanf("%d%d",&n,&q)!=EOF){

        memset(s,0,sizeof(s));
        int x,y,Max,Min;

        for(int i=0; i<n; i++){
            scanf("%d",&s[i]);
        }

        Node *now=build(0,n-1);
        for(int i=0; i<q; i++){

            scanf("%d%d",&x,&y);
            if(x==y){
                printf("0\n");
            }else{
                Max=querymax(now, 1, 0, n-1, x-1, y-1);
                Min=querymax(now, 0, 0, n-1, x-1, y-1);
                printf("%d\n", Max-Min);
            }
        }
    }
    return 0;
}
