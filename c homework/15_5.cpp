#include <stdio.h>
#include <stdlib.h>
int nn,k,m,co=0,fi,se;
struct LinkList{
    int data;
    LinkList* next;
};
LinkList *last;
LinkList *creat(int n){
	LinkList *head, *node, *end;//定义头节点，普通节点，尾部节点；
	head = (LinkList*)malloc(sizeof(LinkList));//分配地址
	end = head;         //若是空链表则头尾节点一样
	for (int i = 0; i < n; i++) {
		node = (LinkList*)malloc(sizeof(LinkList));
        if (k+i>nn)
        {
            k=1-i;
        }
        node->data=k+i;
		end->next = node;
		end = node;
	}
	end->next = head->next;//结束创建
    last=end;
    free(head);
	return end->next;
}
void delet(LinkList *list, int n) {
    co++;
	LinkList *t = list, *in;
    if (co==nn-1)
    {
        se=t->data;
        t=t->next;
        fi=t->data;
        if (fi>se) printf("%d %d\n",se,fi);  
        else printf("%d %d\n",fi,se);
        return;
    }
	int i = 0;
	while (i < n && t != NULL) {
		in = t;
		t = t->next;
		i++;
	}
	in->next = t->next;
	free(t);
    delet(in,m);
}    
int main(){
    scanf("%d%d%d",&nn,&k,&m);
    LinkList *head=creat(nn);
    delet(last,m);
}
