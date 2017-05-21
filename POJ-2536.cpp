#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
using namespace std;

struct Node{
    double x;
    double y;
};

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

    int n,m,s,v;
    while(scanf("%d %d %d %d",&n,&m,&s,&v)!=EOF){

        Node node1[105],node2[105];
        int ans=0;
        memset(used,0,sizeof(used));
        memset(visit,0,sizeof(used));

        for(int i=0; i<105; i++) edge[i].clear();

        for(int i=1; i<n+1; i++){
            scanf("%lf %lf",&node1[i].x,&node1[i].y);
        }

        for(int i=1; i<m+1; i++){
            scanf("%lf %lf",&node2[i].x,&node2[i].y);
        }

        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                double len=sqrt((pow(node1[i].x-node2[j].x,2)+pow(node1[i].y-node2[j].y,2)));
                if(len/v<=s) edge[i].push_back(j);
            }
        }
        ans=Bip(n,m);
        printf("%d\n",n-ans);
    }
    return 0;
}
