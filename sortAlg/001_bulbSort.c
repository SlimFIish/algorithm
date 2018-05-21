#include <stdio.h>
void bulb(int s[], int sSize){
	int i, j, tmp, exChange = 0;
	for(i = 0; i < sSize-1; i++){
		for(j = sSize-1; j > i; j--){
			if(s[j] < s[j-1]){
				tmp = s[j-1];
				s[j-1] = s[j];
				s[j] = tmp;
				exChange = 1;
			}
		}
		if(!exChange)
			return;
	}
	
}

int main(){
	int arrary[] = {10, 20, 6, 4, 5, 4, 3, 43, 7};
	int num = sizeof(arrary)/sizeof(int);
	int i;

	bulb(arrary, num);
	
	for(i = 0; i < num; i++)
		printf("%d%s", arrary[i], (i==num-1) ? "\n":" ");	

	return 0;
}
