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
	int m_value;
	ListNode* m_next;
}
/*O(1)删除节点 */
void DeleteNode(ListNode** plist,ListNode* pdelete)
{
	if(!plist||!pdelete) //如果传入的指向头指针的指针不存在 或 指向要被删除节点的指针不存在
		return;
	if(p->m_next!=NULL)//要被删的节点后还有节点
	{
		ListNode* s=p->m_next;

		p->m_value=s->m_value;//完全拷贝下一个节点的数据和指针
		p->m_next=s->m_next;

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
		while(p->m_next!=pdelete)
			p=p->m_next;
		p->m_next=pdelete->m_next;
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
	for(int i=1;i<k;i++)
	{
		if(pAhead!=NULL)
			pAhead=pAhead->m_next;
		else
			return NULL;
	}
	while(pAhead->m_next)
	{
		pAhead=pAhead->m_next;
		pBebind=pBebind->m_next;
	}
	return pBebind;
}
/* 反转链表 */
void ReverseList(ListNode* phead)//假设头节点存在
{
	ListNode* pthis,*pafter,*temp;
	pthis=phead->m_next;
	if(pthis==NULL)
		return;
	pafter=pthis->m_next;
	temp=pthis;
	while(pafter)
	{
		pthis=pafter;
		pafter=pafter->m_next;
		pthis->m_next=temp;
		temp=pthis;
	}
	phead->m_next->m_next=NULL;
	phead->m_next=phead;
}


