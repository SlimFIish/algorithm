#include <stdio.h>

void merge(int s[], int low, int mid, int high);
void mergeSort(int s[], int gap, int num);
void sort(int s[], int num);

void printAll(int s[], int num){
	int i;
	for(i = 0; i <= num-1; i++)
		printf("%d%s", s[i], i==num-1?"\n":" ");
}

int main(){
	int a[] = {0, 10, 6, 12, 4, 3, 56, 12};
	int num = sizeof(a)/sizeof(int);

	sort(a, num);
	printAll(a, num);
	return 0;
}

void merge(int s[], int low, int mid, int high){
	int i=low, j=mid+1, k =0;
	int tmp[high-low+1];
//	tmp = (int *)malloc((high-low+1)*sizeof(int));

	while(i <= mid && j <= high){
		if(s[i] <= s[j]){
			tmp[k++] = s[i++];
		}else{
			tmp[k++] = s[j++];

		}
	}

	while(i <= mid){
		tmp[k++] = s[i++];
	}

	while(j <= high){
		tmp[k++] = s[j++];
	}

	for(i = low, k = 0; i <= high; i++, k++){
		s[i] = tmp[k];
	}
//	free(tmp);
}


void mergeSort(int s[], int gap, int num){
	int i;
	for(i = 0; i+2*gap-1 < num; i += 2*gap){
		merge(s, i, i+gap-1, i+2*gap-1);
	}
	
	if(i+gap-1 < num)
		merge(s, i, i+gap-1, num-1);
}

void sort(int s[], int num){
	int i, gap;
	for(gap = 1; gap < num; gap = 2*gap){
		mergeSort(s, gap, num);
	}

}
