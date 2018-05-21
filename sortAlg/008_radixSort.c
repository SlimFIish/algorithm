#include <stdio.h>
#include <string.h>

int D[] = {1, 1, 10, 100};
int getRadix(int val, int d){
	return (val/D[d])%10;
}

void radixSort(int s[], int num){
	int i, d, r;
	int cnt[10];
	int bucket[num];

	for(d = 1; d <= 3; d++){
		memset(cnt, 0x00, sizeof(cnt));
		for(i = 0; i <= num-1; i++){
			r = getRadix(s[i], d);	
			cnt[r]++;//calculate the counts for each bits
		}

		for(i = 1; i <= 9; i++)
			cnt[i] = cnt[i-1] + cnt[i]; //the right idx of cnt[i]

		for(i = num-1; i >= 0; i--){
			r = getRadix(s[i],d);
			bucket[cnt[r]-1] = s[i];
			cnt[r]--;
		}

		for(i = 0, r = 0; i < num; i++, r++)
			s[i] = bucket[r];
	}
}

void printAll(int s[], int num){
	int i;
	for(i = 0; i <= num-1; i++){
		printf("%d%s", s[i], i==num-1?"\n":" ");
	}
}


int main(){
	int a[] = {4, 10, 34, 102, 33, 454, 23, 65, 8, 9};
	int num = sizeof(a)/sizeof(int);

	radixSort(a, num);
	printAll(a, num);

}
