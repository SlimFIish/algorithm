#include <stdio.h>

void bigHeapAdjust(int s[], int parent, int num);
void bigHeapSort(int s[], int num);
void littleHeapAdjust(int s[], int parent, int num);
void littleHeapSort(int s[], int num);

int main(){
	int a[] = {1,14,10,13,3,7,8,22,23};
	int b[] = {1,14,10,13,3,7,8,22,23,17};
	int num, i;
	
	num = sizeof(a)/sizeof(int);
	bigHeapSort(a, num);
	for(i = 0; i <= num-1; i++)
		printf("%d%s", a[i], i==num-1?"\n":" ");

	num = sizeof(b)/sizeof(int);
	littleHeapSort(b, num);
	for(i = 0; i <= num-1; i++)
		printf("%d%s", b[i], i==num-1?"\n":" ");

	return 0;
}

void bigHeapAdjust(int s[], int parent, int num){
	int child, tmp;
	tmp = s[parent];
	child = 2*parent+1;
	while(child < num){
		if( child + 1 < num && s[child+1] > s[child])
			child++;
		if( tmp >= s[child])
			break;
		s[parent] = s[child];
		parent = child;
		child = 2*child+1;
	}
	s[parent] = tmp;
}


void bigHeapSort(int s[], int num){
	int i, tmp;
	for(i = num/2; i >= 0; i--) /*Init heap tree*/
		bigHeapAdjust(s, i, num);

	for(i = num-1; i > 0; i--){
		tmp = s[i];
		s[i] = s[0];/*For s[0] has been set to biggest*/
		s[0] = tmp;
		bigHeapAdjust(s, 0, i);
	}


}
void littleHeapAdjust(int s[], int parent, int num){
        int child, tmp;
        tmp = s[parent];
        child = 2*parent+1;
        while(child < num){
                if( child + 1 < num && s[child+1] < s[child])
                        child++;
                if(tmp < s[child])
                        break;
                s[parent] = s[child];
                parent = child;
                child = 2*child+1;
        }
        s[parent] = tmp;
}


void littleHeapSort(int s[], int num){
        int i, tmp;
        for(i = num/2; i >= 0; i--) /*Init heap tree*/
                littleHeapAdjust(s ,i , num);

        for(i = num-1; i > 0; i--){
                tmp = s[i];
                s[i] = s[0];/*For s[0] has been set to biggest*/
                s[0] = tmp;
                littleHeapAdjust(s, 0, i);
        }


}

