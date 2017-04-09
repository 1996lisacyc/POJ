#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

char s[1000005];
int pi[1000005];
int n;

void KMP(void){
	
	int len=n,cur_pos=-1;
	pi[0]=-1;

	for (int i =1; i<len; i++) {
      	while(cur_pos>-1&&s[i]!=s[cur_pos+1]) {
         	cur_pos=pi[cur_pos];
      	}
      	if (s[i]==s[cur_pos+1]) cur_pos++;
      	pi[i]=cur_pos;
      
      	int state=i-cur_pos;
     	if(cur_pos>-1&&(i+1)%state==0){  
            printf("%d %d\n",i+1,(i+1)/state);  
        }  
    }
}

int main() {
	
  int Case=1;
  
  while(scanf("%d", &n)&&n) {
  	
    scanf("\n%s",s);
    printf("Test case #%d\n", Case++);
    KMP();
    printf("\n");
  }
  return 0;
}
