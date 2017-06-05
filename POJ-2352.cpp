#include <cstdio>
#include <cstring>
using namespace std;

int s[32005],v[32005];

int lowbit(int b){
    return b&(-b);
}

void modify(int index, int delta){

    for(int i=index; i<32005; i+=lowbit(i)){
        s[i]+=delta;
    }
}

int getsum(int index){

    int ans=0;
    while(index>0){
        ans+=s[index];
        index-=lowbit(index);
    }
    return ans;
}

int main(){

    int n;
    while(scanf("%d",&n)!=EOF){

        memset(s,0,sizeof(s));
        memset(v,0,sizeof(v));

        int x,y;
        for(int i=0; i<n; i++){
            scanf("%d %d",&x,&y);
            v[getsum(++x)]++;
            modify(x,1);
        }

        for(int i=0; i<n; i++){
            printf("%d\n",v[i]);
        }
    }
    return 0;
}
