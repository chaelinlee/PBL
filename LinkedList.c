# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "LinkedList.h"

typedef struct _node{
	int key;
	char value[50];
	struct _node *next;
}node;

linkedList* createNode(){
	linkedList *L = (linkedList *)malloc(sizeof(linkedList));
	L->head = NULL;
	L->count = 0;

	return L;
}
void insertNode(linkedList *L,int key,char *value){
	node *newNode = (node *)malloc(sizeof(node));
	newNode->key = key;

	strcpy(newNode->value,value); 
	newNode -> next = NULL;
	if(L->head == NULL){
		L->head = newNode;
		L->count += 1;
	}else{
		node *tmp = L->head;
		for(int i=1;i< L->count;i++){
			tmp = tmp->next;
			if(tmp->key == newNode->key){
			printf("이미 존재하는 키 값입니다. ");
			return;
			}
		}
		tmp->next = newNode;
		newNode->next = NULL;
		L->count+=1;
	}
}

char* search(linkedList *L,int key){
	node *tmp = L->head;
	while(tmp->next!=NULL){
		if(key == tmp->key){
			return tmp->value;
		}else{
			tmp = tmp->next;
		}
	}
	return NULL;
}

void delete(linkedList *L,int key){
	//node *tmp = L->head;
	if(L->head!=NULL){
		node *tmp = L->head;
		if(tmp->key == key){
			L->head = L->head->next;
			free(tmp);
			return;
		}

		while(tmp->next->next != NULL){
			if(tmp->next->key==key){
				node *delete = tmp->next;
				tmp->next = tmp ->next->next;
				free(delete);
				L->count-=1;
				return;
			}else{
				tmp = tmp->next;
			}
		}
		if(tmp->next->key == key){
			node *tmp2 = tmp->next;
			tmp->next = NULL;
			free(tmp2);
		}else{
			printf("찾을 수 없습니다. ");
			return;
		}
	}else{
		printf("비어있습니다. ");
		return;
	}
	
}
void printNode(linkedList *L){
	node *tmp = L->head;
	while(tmp->next!=NULL){
		printf("%s ",tmp->value);
		tmp = tmp->next;
	}
	printf("%s ",tmp->value);
}

// int main(){
	
// 	// insertNode(L,3,hello);
// 	// insertNode(L,4,"what");
// 	// insertNode(L,5,"your");
// 	// insertNode(L,6,"name");
// 	// printNode(L);
// 	// delete(L,5);
// 	// printNode(L);
// }

