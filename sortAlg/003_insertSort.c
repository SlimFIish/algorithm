#include <stdio.h>
void insertSort(int s[], int num){
	int i, j, tmp;
	for(i = 1; i <= num-1; i++){
		tmp = s[i];
		for(j = i-1; j >= 0 && s[j] > tmp; j--)
			s[j+1] = s[j];
		s[j+1] = tmp;
	}
}

int main(){
	int a[] = {10, 1, 3, 5, 6, 16, 7, 22, 38, 8};
	int num = sizeof(a)/sizeof(int);
	int i;
	insertSort(a, num);
	for(i = 0; i <= num-1; i++)
		printf("%d%s", a[i], i==num-1?"\n":" ");
	return 0;
}
