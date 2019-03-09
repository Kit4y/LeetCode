#include<stdio.h>
#include<stdlib.h>
struct ListNode{
	int val;
	struct ListNode *next;
};
struct ListNode * addTwoNumbers(struct ListNode *l1,struct ListNode *l2) 
{
	if(l1==NULL)
	return l2;
	if(l2==NULL)
	return l1;
	struct ListNode *p1=l1,*p2=l2;
	struct ListNode *ans=(struct ListNode *)malloc(sizeof(struct ListNode));
	ans->next=NULL;
	struct ListNode *p=ans,*last=NULL,*t=NULL;
	int sum=0;
	while(1)
	{
		if(p1&&p2)
		{
			sum+=p1->val+p2->val;
			p1=p1->next;
			p2=p2->next;
		}
		else if(p1 &&(p2==NULL))
		{
			sum+=p1->val;
			p1=p1->next;
		}
		else if((p1==NULL)&&p2)
		{
			sum+=p2->val;
			p2=p2->next;
		}
		else {
			break;
		}
		p->val=sum%10;
		sum/=10;
		t=(struct ListNode*)malloc(sizeof(struct ListNode));
		t->next=NULL;
		p->next=t;
		last=p; //����������һ�� 
		p=t;
	}
	if(sum!=0){
		t->val=sum;
	} 
	else{
		free(t);
		last->next=NULL;
	}
	return ans;
};
int main(){
	ListNode *l1=(ListNode *)malloc(sizeof(ListNode));
	ListNode *l2=(ListNode *)malloc(sizeof(ListNode));
	ListNode *cur1=l1;
	cur1->val=2;
	
	ListNode *temp=(ListNode *)malloc(sizeof(ListNode));
	temp->val=4;
	temp->next=NULL;
	cur1->next=temp;
	cur1=temp;
	
	temp=(ListNode *)malloc(sizeof(ListNode));
	temp->val=3;
	temp->next=NULL;
	cur1->next=temp;
	
	ListNode *cur2=l2;
	cur2->val=5;
	
	temp=(ListNode *)malloc(sizeof(ListNode));
	temp->val=6;
	temp->next=NULL;
	cur2->next=temp;
	cur2=temp;
	
	temp=(ListNode *)malloc(sizeof(ListNode));
	temp->val=4;
	temp->next=NULL;
	cur2->next=temp;
	
	printf("���L1:\n");
	temp=l1;
	while(temp!=NULL)
	{
		printf("%d ",temp->val);
		temp=temp->next;
	}


	printf("\n���L2:\n");
	temp=l2;
	while(temp!=NULL)
	{
		printf("%d ",temp->val);
		temp=temp->next;
	}
	
	ListNode *l3= addTwoNumbers(l1,l2);
	
	printf("\n���L3:\n");
	temp=l3;
	while(temp!=NULL)
	{
		printf("%d ",temp->val);
		temp=temp->next;
	}
	return 0;
}

