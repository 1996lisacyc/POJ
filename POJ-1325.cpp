#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
using namespace std;

vector<int>edge[105];
int visit[105],llink[105],rlink[105];
bool used[105];

bool DFS(int now){

    for(int i=0; i<(int)edge[now].size();i++){

        int next=edge[now][i];

        if(!used[next]){
            used[next]=true;
            if(!rlink[next]||DFS(rlink[next])){

                llink[now]=next;
                rlink[next]=now;
                return 1;
            }
        }
    }

    return 0;
}

int Bip(int nl,int nr){

    int ans=0;

    memset(llink,0,(nl+1)*sizeof(int));
    memset(rlink,0,(nr+1)*sizeof(int));

    for(int i=1; i<nl+1; i++){
        memset(used,0,(nr+1)*sizeof(bool));
        if(DFS(i)) ++ans;
    }
    return ans;
}

int main(){

    int n;
    while(scanf("%d",&n)&&n){

        int m,k,a,b,c,ans=0;
        memset(used,0,sizeof(used));
        memset(visit,0,sizeof(used));
        scanf("%d %d",&m,&k);

        for(int i=0; i<105; i++) edge[i].clear();

        for(int i=0; i<k; i++){
            scanf("%d %d %d",&a,&b,&c);
            if(b!=0&&c!=0)edge[b].push_back(c);
        }

        ans=Bip(n,m);
        printf("%d\n",ans);
    }
    return 0;
}
