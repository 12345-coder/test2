#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
int n;
typedef struct Node
{int x;
struct Node *next; 
}LNode;
struct Node *Create() {//��ʼ��		
		n=1;
		struct Node *head,*p1,*p2;
		head=NULL;
		p1=(struct Node*)malloc(sizeof(struct Node));
		scanf("%d",&p1->x);
		while(p1->x)
		{if(n==1)head=p1;
		else p2->next=p1;
		p2=p1;
		p1=(struct Node*)malloc(sizeof(struct Node));
		scanf("%d",&p1->x);
		n++;}
		p2->next=NULL;
		return(head);		
 } 
void swap(struct Node *L) {//������ż	
		struct Node *p=L;
		int t;
		while(p&&p->next){
		if((p->x+p->next->x)%2!=0){ //�����ǰ�����һ������ͬ��ż 
			
		t=p->x;p->x=p->next->x;p->next->x=t;//���� 
		p=p->next->next; 
		}
		else p=p->next;
		}//�����ͬ����������ͬ����һ�� 
}
LNode *FindMidNode(LNode *L) {//Ѱ���е� 
		struct Node *p1,*p2;
		p2=p1=L;
		while(p2&&p2->next){
		p1=p1->next;
		p2=p2->next->next;
		}
		return p1;

}
void TraverseList(LNode *L) {//���� 
		LNode *p=L;
		while(p){
		printf("%d ",p->x);
		p=p->next;
		}
}
int IsLoopList(LNode *L) {//�ж�ѭ������ 
		struct Node *p=L;
		while(1){//��p��������ȥ 
		p=p->next;
		if(p==L||p==NULL)break;//���p�ߵ���NULL,���Ƿ�ѭ�� 
		}	
		return p==L?1:0;//����ߵ���ԭ��L���ڵĽ�㣬����ѭ��
						//���û��ѭ���Ĳ��ԣ����Ӧ�ÿ��� 

}
LNode *ReverseList(LNode *L) {//��ת 
		struct Node *p=NULL,*q=L;
		while(L){
		L=L->next;//������ָ����е���ʵ�� 
		q->next=p;
		p=q;
		q=L;
		}
		return p;
}	
LNode *SearchList(LNode *L,int e) {//����Ԫ�� 
		LNode *p=L;
		int n=1;
		while(p&&p->x!=e){
		p=p->next;
		n++; 
		}
		if(p==NULL)printf("\nû�������ҵĽ�㣡");
		else printf("��Ҫ�ҵĽ����ڣ��ǵ�%d�����",n);
		if(p->next)printf(",��һ������ŵ�����%d\n",p->next->x);
		else printf("\n�ý��Ϊβ�ڵ㣬û����һ��Ԫ��\n"); 
		return p;
} 
LNode *fun(LNode *L,int e) {//���ⶨ��ĺ�����
							//�������صڼ����ڵ��ָ��		
		LNode *p=L;			//�����õ����뺯����ɾ��������Ҫ�� 
		int i;				//ָ����� 
		for(i=1;i<e;i++)
		{
			p=p->next;
		}
		return p;
}
void DeleteList(LNode *p,int *e) {//ɾ��������eָ�뷵��ɾ������ 
		LNode *q;
		q=p->next;
		p->next=q->next;
		*e=q->x;
		free(q);		
}
void InsertList(LNode *p, LNode *q) {//����,����qָ��ָ���´����� 
		q->next=p->next;			// �ս��(����������ʵ��) 
		p->next=q;
}
LNode *DestroyList(LNode *L) {//���� 
		LNode *p=L;
		while(L){
		L=L->next;
		free(p);
		p=L; 
		}
		return L;
}	
int main()
{		struct Node *p,*L;
		int i,j;
		printf("�봴������(��������0��ʾ����):");
		L=Create();
		swap(L);printf("������:");
		TraverseList(L);
		printf("\n������������м��������м���:%d",FindMidNode(L)->x);
		printf("\n�ж��Ƿ�ѭ������:"); 
		if(IsLoopList(L))
		printf("��\n");
		else printf("����\n");
		printf("�����������ת��:\n");
		L=ReverseList(L);
		TraverseList(L);
		printf("\n����Ԫ�ر���ҵ����:"); 
		scanf("%d",&i);
		SearchList(L,i);
		printf("\n����ɾ�����ǵڼ������������:");
		scanf("%d",&i);	
		DeleteList(fun(L,i),&j);
		printf("��ɾ����Ԫ����%d\n",j);
		printf("����������:\n");
		TraverseList(L);
		printf("\n���������ǵڼ���������:");
		scanf("%d",&i);
		p=(struct Node*)malloc(sizeof(struct Node));	
		printf("��������Ԫ����");
		scanf("%d",&p->x);
		InsertList(fun(L,i),p);
		printf("����������:\n");
		TraverseList(L); 
		printf("�����������֣����������������");
		scanf("%d",&i);	
		for(i=1;i<=5;i++)
		{	
			system("cls");
			printf("%d",i);
			Sleep(1000);
		 } 
		TraverseList(DestroyList(L));
		free(L); 
		return 0;
		 
}

