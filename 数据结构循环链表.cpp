#include<stdio.h>
#include<stdlib.h>

typedef struct Clinklist{
	int data;
	struct Clinklist* next;
}node;

//��ʼ����ѭ������ 
void da_init(node**pNode)//����**pNode��������*pNode�ĵ�ַ���Ͳ��÷���ֵ�� 
{
	int item;
	node*temp;
	node*target;
	printf("����ڵ��ֵ������0��ɳ�ʼ��\n");
	while(1)
	{
		scanf("%d",&item);
		fflush(stdin);
		
		if(item==0)//����0��ɳ�ʼ��
		{
			return;
		}
		
		if((*pNode)==NULL)
		{
			//ѭ��������ֻ��һ����㼴pNode 
			*pNode=(node*)malloc(sizeof(node));
			if(!(pNode))
				exit(0);
				
			(*pNode)->data=item;
			(*pNode)->next=*pNode;//�γ�ѭ�� 
			 
		}
		else//�����������Ѿ���Ԫ�أ�������ĩβ�����µ�Ԫ�� 
		{
			//�ҵ�nextָ���һ�����Ľ��
			for(target=(*pNode);target->next!=(*pNode);target=target->next) ;//���� 
			
			//����һ���½��
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
/*������*/
//����������ĵ�һ����㣬�����λ�� 
void da_insert(node **pNode,int i)
{
	node*temp;
	node*target;
	node*p;
	int item;
	int j=1;
	
	printf("����Ҫ�������ֵ��");
	scanf("%d",&item);
	
	if(i==1)
	{
		//�²���Ľ����Ϊ��һ�����
		temp=(node*)malloc(sizeof(node));
		
		if(!temp)
			exit(0);
		
		temp->data=item;
		//Ѱ�����һ�����
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

//���ؽ������λ�� 
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
		return 0;//���в����ڸ�Ԫ�� 
	}
	else
	{
	return i;
	}
}

//����
void da_traverse(node*pNode)
{
	node*temp;
	temp=pNode;
	printf("-----�����е�Ԫ��--------\n");
	
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
	printf("1��ʼ������\n\n 2������\n\n 3ɾ�����\n\n 4���ؽ��λ��\n\n 5��������\n\n 0�˳�\n\n"); 
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
				printf("����Ҫ����Ľ��λ��\n");
				scanf("%d",&find);
				da_insert(&pHead,find);
				printf("��λ��%d������ֵ��\n",find);
				da_traverse(pHead);
				printf("\n"); 
				break;
			case '3':
				break;
			case '4':
				printf("��Ҫ���ҵ����ڼ�������ֵ\n");
				scanf("%d",&find);
				printf("Ԫ��%d���ڵ�λ�ã�%d\n",find,da_search(pHead,find));
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



