#include<bits/stdc++.h>
using namespace std;
int doUnion(int a[], int n, int b[], int m);
int main()
{
	int n,m;
	cin>>n>>m;
	int a[n],b[m];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<m;i++)
	{
		cin>>b[i];
	}
	int count = doUnion(a, n, b,m);
	cout<<count<<"\n";
	return 0;
}

int doUnion(int a[], int n, int b[], int m)  {
    sort(a,a+n);
    sort(b,b+m);
    int i=0,j=0,count=0;
    if(a[0]==b[0])
    {
        count++;
        i++;j++;
    }
    else if(a[0]<b[0])
    {
        count = 2;
        i++;j++;
    }
    else
    {
        count=2;
        j++;i++;
    }
    while(i<n && j<m)
    {
        if(a[i]<b[j])
        {
            if((a[i] != a[i-1]) && (a[i]!=b[j-1]))
            {
                count++;
                i++;
            }
            else
            {
                i++;
            }
        }
        else if(b[j]<a[i])
        {
            if((b[j] != b[j-1]) && (b[j]!=a[i-1]))
            {
                count++;
                j++;
            }
            else
            {
                j++;
            }
        }
        else
        {
            if((a[i]!=a[i-1]) && (b[j]!=b[j-1]))
            {
                count++;i++;j++;
            }
            else
            {
                i++;j++;
            }
        }
    }
        while(i<n)
        {
            if(a[i]!=a[i-1])
            {
                count++;i++;
            }
            else
            {
                i++;
            }
        }
        while(j<m)
        {
            if(b[j]!=b[j-1])
            {
                count++;j++;
            }
            else
            {
                j++;
            }
        }
    return count;
}
