#include<bits/stdc++.h>
#include<climits>
#include<iostream>
using namespace std;

void swap(int* x,int* y)
{
	/**x = *x + *y;
	*y = *x - *y;
	*x = *x - *y;*/
	int temp = *x;
	*x = *y;
	*y = temp;
}

int partition(int a[],int lb,int ub)
{
	int pivot = a[ub],i=lb;
	for(int j=lb;j<=ub-1;j++)
	{
		if(a[j] <= pivot)
		{
			swap(&a[j],&a[i]);
			i++;
		}
	}
	swap(&a[i],&a[ub]);
	return i;
}

int KthSmall(int a[],int lb,int ub,int k)
{
	if(k > 0 && k <= ub - lb + 1)         //(k > 0 && k <= r - l + 1)
	{
		int pos = partition(a,lb,ub);
		if(pos - lb == k-1)
		{
			return a[pos];
		}
		if(pos - lb > k-1)
		{
			return KthSmall(a,lb,pos-1,k);
		}
		return KthSmall(a,pos+1,ub,k-pos+lb-1);
	}
	return INT_MAX;
}

int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int k;
	cin>>k;
	//int KthSmallest = KthSmall(a,0,n-1,k);
	cout <<k<<"th smallest element in given array is "<<KthSmall(a,0,n-1,k)<<"\n";
	return 0;
}
