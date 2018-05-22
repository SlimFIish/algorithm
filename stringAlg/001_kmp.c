#include <stdio.h>
#include <string.h>

void getNext(char p[], int num, int next[]){
	int j=0, k=-1;
	next[0] = -1;

	while(j <= num-2){
		if(k == -1 || p[j] == p[k])
			next[++j] = ++k;
		else
			k = next[k];
	}
}

int kmp(char s[], int sNum, char p[], int pNum){
	int i=0, j=0;
	int next[pNum];

	getNext(p, pNum, next);
	while(j <= pNum-1 && i <= sNum-1){
		if(j == -1 || s[i] == p[j]){
			i++;
			j++;
		}else{
			j = next[j];
		}
	}
	if(j == pNum)
		return i-j;
	else
		return -1;
}

int main(){
	char s[] = "ABCAEFABCABDEFGABC";
	char p[] = "ABCABD";

	int sNum = strlen(s);
	int pNum = strlen(p);

	int idx = kmp(s, sNum, p, pNum);
	printf("idx=%d\n",idx);
	return 0;
}
