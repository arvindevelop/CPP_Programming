#include<bits/stdc++.h>
using namespace std;

int main()
{
	int r,c,r1,c1;
	cout<<"Enter the no. of row and column for matrix A and B"<<"\n";
	cin>>r>>c>>r1>>c1;
	int a[r][c],b[r1][c1],mul[r][c1];
	//checking whether matrix multiplication is possible or not
	if(c != r1)
	{
		cout<<"Matrix multiplication is not possible"<<"\n";
	}
	
	//if matrix multiplication 
	else
	{
		//taking values of Matrix A and Matix B
		
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				cout<<"a["<<i<<"]["<<j<<"] : ";
				cin>>a[i][j];
			}
		}
		for(int i=0;i<r1;i++)
		{
			for(int j=0;j<c1;j++)
			{
				cout<<"b["<<i<<"]["<<j<<"] : ";
				cin>>b[i][j];
			}
		}
		
		//display the elements of matrix A and B 
		cout<<"Matrix A"<<"\n";
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				cout<<a[i][j]<<" ";
			}
			cout<<"\n";
		}
		cout<<"\n";
		cout<<"Matrix B"<<"\n";
		for(int i=0;i<r1;i++)
		{
			for(int j=0;j<c1;j++)
			{
				cout<<b[i][j]<<" ";
			}
			cout<<"\n";
		}
		
		//logic for matrix multiplication
		
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
			{
				mul[i][j] = 0;
				for(int k = 0;k<c;k++)
				{
					mul[i][j] += a[i][k]*b[k][j];
				}
			}
		}
		cout<<"After multiplication"<<"\n";
		for(int i=0;i<r;i++)
		{
			for(int j=0;j<c1;j++)
			{
				cout<<mul[i][j]<<" ";
			}
			cout<<"\n";
		}
		
		
	}
	return 0;
}
