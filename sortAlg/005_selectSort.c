#include <stdio.h>

void selectSort(int s[], int num){
	int i, j, tmp, min, minIdx;
	for(i = 0; i <= num-2; i++){
		min = s[i];
		minIdx = i;
		for(j = i+1; j <= num-1; j++){
			if(s[j] < min){
				min = s[j];
				minIdx = j;
			}
		}
		if(minIdx != i){
			tmp = s[i];
			s[i] = min;
			s[minIdx] =tmp;
		}
	}
}

int main(){
	int a[] = {10, 4, 2, 1, 12, 34, 4, 2, 6, 7, 15};
	int num = sizeof(a)/sizeof(int);
	int i;
	selectSort(a, num);
	for(i = 0; i <= num-1; i++)
		printf("%d%s", a[i], i == num-1?"\n":" ");
	
	return 0;
}
