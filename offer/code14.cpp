/*
 * =====================================================================================
 *
 *       Filename:  code14.cpp
 *    Description:  调整数组顺序使奇数位于偶数前面
 *        Created:  2015年05月09日 18时57分54秒
 *         Author:  hudmok (HangDian), hdumok@qq.com
 *
 * =====================================================================================
 */
void Reorder(int num[],int length)
{
	int pBegin=num;
	int pEnd=num+length-1;
	int tmp;
	while(pBegin<pEnd)
	{
		while(pBegin<pEnd&&(*pBegin&0x01)!=0)
			pBegin++;
		while(pBegin<pEnd&&(*pBegin&0x01)==0)
			pEnd--;
		if(pBegin<pEnd)
		{
			tmp=*pBegin;
			*pBegin=*pEnd;
			*pEnd=*pBegin;
		}
	}
}

/*复习 快速排序 */
void QuickSort(int num[],int begin,int end)//快排需要 开始数和结束数在数组中的偏移量
{
	if(begin>=end)
		return;
	int i=begin;
	int j=end;
	int key=num[i];
	while(i<j)
	{
		while(i<j&&num[j]>=key)//先后往前
			j--;
		num[i]=num[j];//因为num[i]数值已经保存在key里中，所以可以用num[j]覆盖
		while(i<j&&num[i]<=key)//再前往后
			i++;
		num[j]=num[i];//因为原来的num[j]已经保存在原来的num[i]里面了，所以可以用新的num[i]覆盖
	}
	num[i]=key;
	QuickSort(num,begin,i-1);
	QuickSort(num,i+1,end);
}
