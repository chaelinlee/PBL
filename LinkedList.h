typedef struct linkedList{
	int count;
	struct _node *head;
}linkedList;

void insertNode(linkedList *L,int key,char *value);
void delete(linkedList *L,int key);
linkedList* createNode();
void printNode(linkedList *L);
