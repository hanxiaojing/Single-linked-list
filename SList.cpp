#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
//单链表
#include<assert.h>

typedef int DataType;

typedef struct SListNode
{
	DataType _data;
	struct SListNode* _next;
}SListNode;


SListNode* _CreateNode(DataType x)
{
	SListNode* head = (SListNode*)malloc(sizeof(SListNode));
	head->_data = x;
	head->_next = NULL;
	return head;
}


void PushBack(SListNode*& head, DataType x)
{
	if (head == NULL)
	{
		head = _CreateNode(x);
		head->_next = NULL;
	}
	else
	{
		SListNode* cur = head;
		while (cur->_next != NULL)
		{
			cur = cur->_next;
		}
		cur->_next = _CreateNode(x);
	}
	
}


void PopBack(SListNode*& head)
{
	if (head == NULL)
	{
		return;
	} 
	else if (head->_next == NULL)
	{
		free(head);
		head = NULL;
	}
	else
	{
		SListNode* cur = head;
		SListNode* next = head;

		while (cur)
		{
			next = cur->_next;
			if (next != NULL && next->_next == NULL)
			{
				free(next);
				cur->_next = NULL;
				return;
			}

			cur = cur->_next;
		}
	}
	
}


void PushFront(SListNode*& head,DataType x)
{
	if (head == NULL)
	{
		head = _CreateNode(x);
	}
	else
	{
		SListNode* pcur = _CreateNode(x);
		pcur->_next = head;
		head = pcur;
	}
}


void PopFront(SListNode*& head)
{
	if (head == NULL)
	{
		return;
	}
	else if (head->_next == NULL)
	{
		free(head);
		head = NULL;
	}
	else
	{
		SListNode* del = head;
		SListNode* next = head->_next;
		free(del);
		del = NULL;
		head = next;
	}
}


void Insert(SListNode* head,int pos,DataType x)
{
	assert(pos >= 0);
	SListNode* cur = head;
	while (--pos && cur)
	{			
		cur = cur->_next;		
	}
	if (pos > 0)
	{
		printf("pos位置大于链表长度!\n");
		return;
	}
	SListNode* newcur = _CreateNode(x);
	if (cur->_next)
	{
		SListNode* next = cur->_next;
	
		cur->_next = newcur;
		newcur->_next = next;
	}
	else if (cur->_next == NULL)
	{
		cur->_next = newcur;
	}
}


size_t Length(SListNode*& head)
{
	size_t count = 0;
	SListNode* cur = head;
	while (cur)
	{
		count++;
		cur = cur->_next;
	}
	return count;
}


void PrintSList(SListNode*& head)
{
	SListNode* cur = head;
	while (cur)
	{
		printf("%d->", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}


void Test()
{
	SListNode* sList =NULL;
	PushBack(sList, 1);
	PushBack(sList, 2);
	PushBack(sList, 3);
	PushBack(sList, 4);
	PushBack(sList, 5);
	PrintSList(sList);

	PopBack(sList);
	PrintSList(sList);

	PushFront(sList, 0);
	PrintSList(sList);

	PopFront(sList);
	PrintSList(sList);

	Insert(sList, 3, 10);
	PrintSList(sList);

	int ret = Length(sList);
	printf("单链表长度为：%d\n", ret);
}


int main()
{
	Test();
	system("pause");
	return 0;
}