#include <stdio.h>

int partition(int s[], int low, int high){
	int left = low, right = high, base;
	base = s[low];
	while(left < right){
		while(left < right && s[right] >= base)
                	right--;
        	if(left < right)
                	s[left++] = s[right];
		else
			break;

        	while(left < right && s[left] <= base)
                	left++;

        	if(left < right)
                	s[right--] = s[left];
		else
			break;
	}

				
	s[left] = base;
	
	return left;
}


void quickSort(int s[], int low, int high){
	int baseIdx;
	if(low < high){
		baseIdx = partition(s, low, high);
		quickSort(s, low, baseIdx-1);
		quickSort(s, baseIdx+1, high);
	}
}
int main(){
	int arrary[] = {10,20,30,11,3,3,2,4,1,6,8,32};
	int num = sizeof(arrary)/sizeof(int);
	int i;
	quickSort(arrary, 0, num-1);

	for(i = 0; i < num-1; i++)
		printf("%d%s", arrary[i], i == num-1?"\n":" ");
	return 0;
}
