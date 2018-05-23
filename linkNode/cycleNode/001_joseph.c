#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;
}node_t, *node_p;

node_p createList(int n){
	node_p head, cur, tmp;
	int data = 0;
	head = (node_p)malloc(sizeof(node_t));
	head->data = data;
	head->next = head;
	cur = head;
	while(--n){
		tmp = (node_p)malloc(sizeof(node_t));
		tmp->data = ++data;
		tmp->next = cur->next;
		cur->next = tmp;
		cur = tmp;
	}
	return head;
}

/*共n个人，从编号为k的人开始报数，报到m，则淘汰，继续从下一个人开始报数，报到m，又淘汰，按此规律重复*/
void joseph(int n, int k, int m){
	node_p head, pre, first, curDel;
	int i;
	head = createList(n);
	pre = first = head;
	while(k--){
		pre = first; /* need backup the previous node in casethat m=1*/
		first = first->next;
	}
	
	while(n--){
		curDel = first;
		for(i = 0; i < m-1; i++){
			pre = curDel;
			curDel = curDel->next;
		}

		pre->next = curDel->next;
		printf("curDel=%d\n",curDel->data);
		free(curDel);
		first = pre->next;
	}
	
}

int main(){
	int n, k, m;
	scanf("%d %d %d", &n, &k, &m);
	joseph(n, k, m);	
	return 0;
}
