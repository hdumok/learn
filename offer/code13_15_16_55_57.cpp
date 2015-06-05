/*
 * =====================================================================================
 *
 *       Filename:  code13.cpp
 *    Description:  链表相关 
 *        Created:  2015年05月09日 18时20分54秒
 *         Author:  hudmok (HangDian), hdumok@qq.com
 *
 * =====================================================================================
 */

struct ListNode{
	int value;
	ListNode* next;
}
/*O(1)删除节点 */
void DeleteNode(ListNode** plist,ListNode* pdelete)
{
	if(!plist||!pdelete) //如果传入的指向头指针的指针不存在 或 指向要被删除节点的指针不存在
		return;
	if(p->next!=NULL)//要被删的节点后还有节点
	{
		ListNode* s=p->next;

		p->value=s->value;//完全拷贝下一个节点的数据和指针
		p->next=s->next;

		delete s;
		s=NULL;
	}
	else if(*plist=pdelete)//如果后面没有节点了，而这个又是头节点又是尾节点
	{
		delete pdelete;
		pdelete=NULL;
		*plist=NULL;
	}
	else//如果后面没有节点了，而这又不是唯一节点
	{
		ListNode* p=*plist;
		while(p->next!=pdelete)
			p=p->next;
		p->next=pdelete->next;
		delete pdelete;
		pdelete=NULL;
	}
}	
/*找出链表中倒数第K个节点 */
ListNode* FindTailK(ListNode* phead,unsigned int k)
{
	if(phead==NULL||k==0)
		return NULL;
	ListNode* pAhead=phead;
	ListNode* pBebind=phead;
	for(int i=1;i<k;i++)//执行了K-1次  从指向节点1变成指向节点K
	{
		if(pAhead!=NULL)
			pAhead=pAhead->next;
		else
			return NULL;
	}
	while(pAhead->next)
	{
		pAhead=pAhead->next;
		pBebind=pBebind->next;
	}
	return pBebind;
}
/* 反转链表 */
void ReverseList(ListNode* phead)//假设头节点存在
{
	ListNode* pthis,*pafter,*temp;
	pthis=phead->next;
	if(pthis==NULL)
		return;
	pafter=pthis->next;
	temp=pthis;
	while(pafter)
	{
		pthis=pafter;
		pafter=pafter->next;
		pthis->next=temp;
		temp=pthis;
	}
	phead->next->next=NULL;
	phead->next=pthis;
}
void ReverseList(ListNode** phead)//假设头节点不存在
{
	ListNode *pthis,*pafter,*temp;
	pthis=*phead;
	if(phead==NULL&&*phead)
		return;
	temp=pthis;
	pafter=pthis->next;
	while(pafter)
	{
		pthis=pafter;
		pafter=pafter->next;
		pthis->next=temp;
		temp=pthis;
	}
	(*phead)->next=NULL;
	*phead=pthis;
}
/*合并两个排好序的链表 */
ListNode* MergeList(ListNode* phead1,ListNode* phead2)
{
	if(phead1==NULL)
		return phead2;
	else if(phead2=NULL)
		return phead1;

	ListNode* pmerge=NULL;
	
	if(phead1->value<phead2->value)
	{
		pmerge=phead1;
		pmerge->next=MergeList(phead1->next,phead2);
	}
	else
	{
		pmerge=phead2;
		pmerge->next=MergeList(phead2->next,phead1);
	}
	return pmerge;
}
/*约瑟夫环 环形链表实现*/
int LastOne(ListNode* pHead,int length,int k)
{
	if (length<1||k<1)
		return -1;
	ListNode* p=pHead;
	ListNode* s;
	while(length>1)
	{
		for (int i = 1; i < k-1 ; ++i)
			p=p->next;
		s=p->next;
		p->next=s->next;
		delete s;
		p=p->next;//下一个开始
		length--;
	}
	return p->data;
}
/*删除有序链表里的重复节点*/
void Delete(ListNode** pHead)
{	//这个算法关键是，一旦遇到要删除的节点，则当前的pNode和下一个pNext都不在了
	//即要么不删，要么删俩，这导致判断退出的条件有两处，一个是pNext!=NULL 一个是pNode!=NULL
	if (pHead==NULL||*pHead==NULL)
		return;
	//第一步先设置三个工作指针
	ListNode* pPre=NULL;
	ListNode* pNode=*pHead;
	ListNode* pNext=pNode->next;
	while(pNext!=NULL)
	{
		if (pNext->data!=pNode->data)
		{//如果下一个节点存在且下一节点的值不等于当前节点
			pPre=pNode;
			pNode=pNext;
			pNext=pNext->next;
		}
		else
		{
			int val=pNode->data;
			ListNode* pDelete;
			while(pNode!=NULL&&pNode->data==val)
			{
				pDelete=pNode;
				pNode=pNode->next;
				delete pDelete;
			}
			if(pPre==NULL)//如果前一个节点不存在，也就是删的是第一个节点
				*pHead=pNode;//这里很关键，重新设置链表头
			else
				pPre->next=pNode;

			if(pNode==NULL)
				break;
			else
				pNext=pNode->next;
		}
	} 
}
/*删除有序链表里的重复节点 剩一个*/
void Unique(ListNode** pHead)
{
	if (pHead==NULL||*pHead==NULL)
		return;
	ListNode* pPre=NULL;
	ListNode* pNode=*pHead;
	ListNode* pNext=pNode->next;
	while(pNext!=NULL)
	{//比较当前节点pNode和下一个节点pNext的值，如果下一个节点不存在，那就结束了
		if (pNext->data!=pNode->data)
		{//如果下一个节点存在且下一节点的值不等于当前节点
			pPre=pNode;
			pNode=pNext;
			pNext=pNext->next;
		}
		else
		{
			pPre=pNode;
			pNode=pNext;
			int val=pNode->data;
			ListNode* pDelete;
			while(pNode!=NULL&&pNode->data==val)
			{
				pDelete=pNode;
				pNode=pNode->next;
				delete pDelete;
			}
			pPre->next=pNode;

			if(pNode==NULL)//如果当前节点都不存在，那就更要结束了
				break;
			else
				pNext=pNode->next;//如果当前节点存在，就设置下一个节点
		}
	} 
}
