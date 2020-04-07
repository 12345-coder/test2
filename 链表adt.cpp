#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
int n;
typedef struct Node
{int x;
struct Node *next; 
}LNode;
struct Node *Create() {//初始化		
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
void swap(struct Node *L) {//交换奇偶	
		struct Node *p=L;
		int t;
		while(p&&p->next){
		if((p->x+p->next->x)%2!=0){ //如果当前数与后一个数不同奇偶 
			
		t=p->x;p->x=p->next->x;p->next->x=t;//交换 
		p=p->next->next; 
		}
		else p=p->next;
		}//如果不同就走两步，同就走一步 
}
LNode *FindMidNode(LNode *L) {//寻找中点 
		struct Node *p1,*p2;
		p2=p1=L;
		while(p2&&p2->next){
		p1=p1->next;
		p2=p2->next->next;
		}
		return p1;

}
void TraverseList(LNode *L) {//遍历 
		LNode *p=L;
		while(p){
		printf("%d ",p->x);
		p=p->next;
		}
}
int IsLoopList(LNode *L) {//判断循环链表 
		struct Node *p=L;
		while(1){//让p持续走下去 
		p=p->next;
		if(p==L||p==NULL)break;//如果p走到了NULL,则是非循环 
		}	
		return p==L?1:0;//如果走到了原来L所在的结点，则是循环
						//这个没做循环的测试，大概应该可以 

}
LNode *ReverseList(LNode *L) {//反转 
		struct Node *p=NULL,*q=L;
		while(L){
		L=L->next;//用三个指针进行迭代实现 
		q->next=p;
		p=q;
		q=L;
		}
		return p;
}	
LNode *SearchList(LNode *L,int e) {//搜索元素 
		LNode *p=L;
		int n=1;
		while(p&&p->x!=e){
		p=p->next;
		n++; 
		}
		if(p==NULL)printf("\n没有你想找的结点！");
		else printf("你要找的结点存在，是第%d个结点",n);
		if(p->next)printf(",下一个结点存放的数是%d\n",p->next->x);
		else printf("\n该结点为尾节点，没有下一个元素\n"); 
		return p;
} 
LNode *fun(LNode *L,int e) {//额外定义的函数，
							//用来返回第几个节点的指针		
		LNode *p=L;			//用来得到插入函数和删除函数所要的 
		int i;				//指针参数 
		for(i=1;i<e;i++)
		{
			p=p->next;
		}
		return p;
}
void DeleteList(LNode *p,int *e) {//删除，并用e指针返回删除的数 
		LNode *q;
		q=p->next;
		p->next=q->next;
		*e=q->x;
		free(q);		
}
void InsertList(LNode *p, LNode *q) {//插入,其中q指针指向新创建的 
		q->next=p->next;			// 空结点(在主函数中实现) 
		p->next=q;
}
LNode *DestroyList(LNode *L) {//销毁 
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
		printf("请创建链表(输入数字0表示结束):");
		L=Create();
		swap(L);printf("交换后:");
		TraverseList(L);
		printf("\n交换后的链表中间数或右中间数:%d",FindMidNode(L)->x);
		printf("\n判断是否循环链表:"); 
		if(IsLoopList(L))
		printf("是\n");
		else printf("不是\n");
		printf("交换后链表的转置:\n");
		L=ReverseList(L);
		TraverseList(L);
		printf("\n输入元素便可找到结点:"); 
		scanf("%d",&i);
		SearchList(L,i);
		printf("\n你想删除的是第几个结点后面的数:");
		scanf("%d",&i);	
		DeleteList(fun(L,i),&j);
		printf("你删除的元素是%d\n",j);
		printf("链表变成如下:\n");
		TraverseList(L);
		printf("\n你想插入的是第几个结点后面:");
		scanf("%d",&i);
		p=(struct Node*)malloc(sizeof(struct Node));	
		printf("你想插入的元素是");
		scanf("%d",&p->x);
		InsertList(fun(L,i),p);
		printf("链表变成如下:\n");
		TraverseList(L); 
		printf("输入任意数字，链表将在五秒后被销毁");
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

