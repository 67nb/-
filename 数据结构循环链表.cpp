#include<stdio.h>
#include<stdlib.h>

typedef struct Clinklist{
	int data;
	struct Clinklist* next;
}node;

//初始化单循环链表 
void da_init(node**pNode)//这里**pNode操作的是*pNode的地址，就不用返回值了 
{
	int item;
	node*temp;
	node*target;
	printf("输入节点的值，输入0完成初始化\n");
	while(1)
	{
		scanf("%d",&item);
		fflush(stdin);
		
		if(item==0)//输入0完成初始化
		{
			return;
		}
		
		if((*pNode)==NULL)
		{
			//循环链表中只有一个结点即pNode 
			*pNode=(node*)malloc(sizeof(node));
			if(!(pNode))
				exit(0);
				
			(*pNode)->data=item;
			(*pNode)->next=*pNode;//形成循环 
			 
		}
		else//这里是链表已经有元素，在链表末尾插入新的元素 
		{
			//找到next指向第一个结点的结点
			for(target=(*pNode);target->next!=(*pNode);target=target->next) ;//遍历 
			
			//生成一个新结点
			temp=(node*)malloc(sizeof(node));
			
			if(!temp)
			{
				exit(0);
			} 
			
			temp->data=item;
			temp->next=*pNode;
			target->next=temp; 
		}
		
	}
}
/*插入结点*/
//参数：链表的第一个结点，插入的位置 
void da_insert(node **pNode,int i)
{
	node*temp;
	node*target;
	node*p;
	int item;
	int j=1;
	
	printf("输入要插入结点的值：");
	scanf("%d",&item);
	
	if(i==1)
	{
		//新插入的结点作为第一个结点
		temp=(node*)malloc(sizeof(node));
		
		if(!temp)
			exit(0);
		
		temp->data=item;
		//寻找最后一个结点
		for(target=(*pNode);target->next!=(*pNode);target=target->next);
		
		temp->next=(*pNode);
		target->next=temp;
		*pNode=temp;
		 
	}
	else
	{
		target=*pNode;
		
		for(;j<(i-1);++j)
		{
			target=target->next;
		}	
		
		temp=(node*)malloc(sizeof(node));
		if(!temp)
		{
			exit(0);
		}
		temp->data=item;
		p=target->next;
		target->next=temp;
		temp->next=p;
		
	}
	
}

//返回结点所在位置 
int da_search(node*pNode,int elem)
{
	node*target;
	int i=1;
	for(target=pNode;target->data!=elem&&target->next!=pNode;++i)
	{
		target=target->next;
	}
	if(target->next==pNode)
	{
		return 0;//表中不存在该元素 
	}
	else
	{
	return i;
	}
}

//遍历
void da_traverse(node*pNode)
{
	node*temp;
	temp=pNode;
	printf("-----链表中的元素--------\n");
	
	do{
		printf("%4d",temp->data);
	}
	while((temp=temp->next)!=pNode);
	
	printf("\n");
	
 } 
int main()
{
	node*pHead=NULL;
	char opp;
	int find;
	printf("1初始化链表\n\n 2插入结点\n\n 3删除结点\n\n 4返回结点位置\n\n 5遍历链表\n\n 0退出\n\n"); 
	while(opp!='0')
	{
		scanf("%c",&opp);
		switch(opp)
		{
			case '1':
				da_init(&pHead);
				printf("\n");
				da_traverse(pHead);
				break;
			case '2':
				printf("输入要插入的结点位置\n");
				scanf("%d",&find);
				da_insert(&pHead,find);
				printf("在位置%d处插入值后：\n",find);
				da_traverse(pHead);
				printf("\n"); 
				break;
			case '3':
				break;
			case '4':
				printf("你要查找倒数第几个结点的值\n");
				scanf("%d",&find);
				printf("元素%d所在的位置：%d\n",find,da_search(pHead,find));
				printf("\n");
				break;
			case '5':
				da_traverse(pHead);
				break;
			case '0':
				exit(0);
		}
	}
	
}



