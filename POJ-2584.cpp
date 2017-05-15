#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define INF 100000000
using namespace std;

int visit[105],pa[105];
int cap[105][105],flow[105][105];
int n=0;

int findFlow(int s, int t) {
    int f = INF;
    for (int i = t, pre; i != s; i = pre) {
        pre = pa[i];
        if (cap[pre][i] - flow[pre][i] > 0)
            f = min(f, cap[pre][i] - flow[pre][i]);
        else
            f = min(f, flow[i][pre]);
    }
    for (int i = t, pre; i != s; i = pre) {
        pre = pa[i];
        if (cap[pre][i] - flow[pre][i] > 0)
            flow[pre][i] += f;
        else
            flow[i][pre] -= f;
    }
    return f;
}

bool DFS(int k, int t) {
    visit[k] = 1;
    if (k == t) return 1;
    for (int i = 0; i < n+1; ++i ) {
        if (visit[i]) continue;
        if (cap[k][i]-flow[k][i]>0 || flow[i][k]>0) {
            pa[i] = k;
            if (DFS(i, t)) return 1;
        }
    }
    return 0;
}

int FF(int s, int t){

    int ret = 0;
    while (1){
        memset(visit, 0, sizeof(visit));
        if (!DFS(s, t)) break;
        ret += findFlow(s, t);
    }
    return ret;
}

int findnum(char c){
    switch(c){
        case 'S': return n;
        case 'M': return n+1;
        case 'L': return n+2;
        case 'X': return n+3;
        case 'T': return n+4;
        default: return 0;
    }
}

int main(){

    string s1;
	while(cin>>s1&&s1!="ENDOFINPUT"){

		memset(cap,0,sizeof(cap));
		memset(visit,0,sizeof(visit));
		memset(pa,0,sizeof(pa));
		memset(flow,0,sizeof(flow));

        scanf("%d\n",&n);
        int S=n+5, T=n+6,tem1,tem2,ans=0;
        string s2;

        for(int i=0; i<n; i++){
            cin>>s2;
            tem1=findnum(s2[0]);
            tem2=findnum(s2[1]);
            for(int j=tem1; j<tem2+1; j++){
                cap[i][j]=1;
            }
            cap[S][i]=1;
        }

        for(int i=n; i<n+5; i++){
            scanf("%d",&tem1);
            cap[i][T]=tem1;
        }

        n+=6;
        cin>>s2;
		ans=FF(S,T);
        if (ans==n-6) printf("T-shirts rock!\n");
        else printf("I'd rather not wear a shirt anyway...\n");
	}
	return 0;
}
