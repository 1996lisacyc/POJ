#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

char s[1000005];
int pi[1000005];

int KMP(void){
	int len=strlen(s),cur_pos=-1;
	pi[0]=-1;
	for(int i=1; i<len; ++i) {
		while(~cur_pos && s[i]!=s[cur_pos+1])
			cur_pos = pi[cur_pos];
		if(s[i]==s[cur_pos+1]) ++cur_pos;
		pi[i]=cur_pos;
	}
	return cur_pos;
}

int main(){
	
	while(scanf("%s",s)!=EOF) {
		if(s[0] == '.'||s[0]=='\0') break;
		int len=strlen(s),cur_pos=KMP();
		int state=len-cur_pos-1;

		if(len%state==0)
			printf("%d\n", len/state);
		else
			printf("1\n");
	}
	return 0;
}
