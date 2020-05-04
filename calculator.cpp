#include <stdlib.h>
#include <stdio.h>
typedef enum Status 
{
    ERROR = 0, 
	SUCCESS = 1
} Status;

typedef  struct StackNode
{
	double data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef  struct  LinkStack
{
	LinkStackPtr top;//指向栈顶 ，可以利用StackNode类型指针的性质 
	int count;//统计数目 
}LinkStack;

Status initLStack(LinkStack *s) {//初始化 
		s->top=(LinkStackPtr)malloc(sizeof(StackNode));//改变了原来NULL 
		if(s->top==NULL)							  //指向 
		return ERROR;
		else 
		{
			s->top->next=NULL;
			s->count=0;
			return SUCCESS;
		}
		
}
Status isEmptyLStack(LinkStack *s) {//判断为空 
		if(s->top->next==NULL)
		return SUCCESS;
		else return ERROR;
}
double getTopLStack(LinkStack *s) {	//栈顶元素 
		if(isEmptyLStack(s))
		return ERROR;
		else 
		{
			return s->top->data;
		}
}
Status clearLStack(LinkStack *s) {//清空 
		LinkStackPtr p;
		if(isEmptyLStack(s))
		return ERROR;
		else
		{	
			while(s->top->next)//类似链表的清空 
			{
					p=s->top;
					s->top=s->top->next;
					free(p);	
			}
			s->count=0;//注意 
			return SUCCESS;
		}
}
Status destroyLStack(LinkStack *s) {//销毁 
		free(s->top);
		s->top=NULL;
}
Status LStackLength(LinkStack *s,int *length) {//长度 
		*length=s->count;
}
Status pushLStack(LinkStack *s,double e) {//压栈 
		LinkStackPtr p;				 
		p=(LinkStackPtr)malloc(sizeof(StackNode));
		if(p==NULL)
		return ERROR;
		else 
		{
		    p->data=e;
			p->next=s->top;
			s->top=p;
			s->count++;
			return SUCCESS;
		}
}
double popLStack(LinkStack *s) {//出栈 
		LinkStackPtr p;
		double e;
		if(s->top==NULL||isEmptyLStack(s))
		return ERROR;
		else
		{	p=s->top;
			e=p->data;
			s->top=s->top->next;
			s->count--;
			free(p);
			return e;
		}
}
int priority(char s) {//判断优先级 
	switch (s)
	{
		case '(':
		case ')':
			return 3;
		case '*':
		case '/':
			return 2;
		case '+':
		case '-':
			return 1;
		default:
			return 0;
	}
}
void compute(LinkStack *s_num,LinkStack *s_op) {//用符号栈和数字栈实现 
	char c[100]={0};
	int i,j;
	double temp=0.0,times=1.0,k;
	printf("请输入表达式(输入负数时加括号):");
	scanf("%s",c);
	while (c[i]!='\0'||isEmptyLStack(s_op)!=1)//必须是'\0' 
	{	
		if(c[i]>='0'&&c[i]<='9')//遇到数字 
		{
			while((c[i]>='0'&&c[i]<='9')||c[i]=='.')
			{
				temp=temp*10.0+c[i]-'0';//调整为实数 
				i++;
				if(c[i]=='.')
				{	
					i++; 
					while(c[i]>='0'&&c[i]<='9')
					{
						temp=temp*10.0+c[i]-'0';
						times*=10.0;i++;
					}
					temp=temp/times*1.0;
					times=1.0;
				}
			} 	
			pushLStack(s_num,temp);
			temp=0.0;
		}
		else//遇到符号(大前提) 
		{	
			j=i+1;//解决负数的情况,用j可以避免对i的影响 
			if(c[i]=='('&&c[j]=='-')
			{	
				i=i+2;
				while(c[i]>='0'&&c[i]<='9')//c[i]<'0'||c[i]>'9'
				{
					temp=temp*10.0+c[i]-'0';//调整为实数 
					i++;
				} 
				pushLStack(s_num,-temp);i++;
				temp=0.0;
			} 
			//压栈 
			if(isEmptyLStack(s_op)==1//符号栈为空---优先级原则 
				||(c[i]!=')'&&priority(c[i])>priority(getTopLStack(s_op)))//优先级原则且不为')'	
			 	||(getTopLStack(s_op)=='('&&c[i]!=')'))//特殊情况 
			{ 
			 	pushLStack(s_op,c[i]);
			 	i++;
				continue;
			}
			//出栈
			if(priority(c[i])<=priority(getTopLStack(s_op))//优先级原则 
				||c[i]=='0'//表达式为空但(符号栈不为空)----已在while括号内默认 
				||c[i]==')')//特殊情况 
				{
					switch ((int)popLStack(s_op))//弹出时顺便计算											
					{
						case '+':
							pushLStack(s_num,popLStack(s_num)+popLStack(s_num));
							break;
						case '-':
							k=popLStack(s_num);
							pushLStack(s_num,popLStack(s_num)-k);
							break;
						case '*':
							pushLStack(s_num,popLStack(s_num)*popLStack(s_num));
							break;
						case '/':
							k=popLStack(s_num);
							pushLStack(s_num,popLStack(s_num)/k);
							break;
						case '('://恰好组成括号 
							i++; 
							break;	
					}											
				}	
		}
	}					
		printf("计算结果：%f",popLStack(s_num));
}
int main(){
		void compute(LinkStack *s_num,LinkStack *s_op);
		LinkStack s_num,s_op;
		if(initLStack(&s_num)&&initLStack(&s_op))
		printf("初始化成功\n");
		else printf("初始化失败\n"); 
		compute(&s_num,&s_op);
		return 0; 
}