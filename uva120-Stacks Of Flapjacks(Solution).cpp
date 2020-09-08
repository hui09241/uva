#include<iostream>
#include<sstream>
#include<algorithm>
using namespace std;
int num[100],ans[100],p,total,max1;
void change(int x)
{
    int i, j, k;
    for(i=0,j=x; j>i; j--,i++)
    {
        k = num[i];
        num[i] = num[j];
        num[j] = k;
    }
}
int main()
{
    string ss;
    while(getline(cin,ss))
    {
        int numi=0;
        cout<<ss<<endl;
        stringstream s;
        s<<ss;
        while(s>>num[numi])
        {
            numi++;
        }
        total=0;
        for(int i=0;i<numi;i++)
        {
            max1=0;
            for(int j=numi-i-1;j>=0;j--)
                if(max1<num[j])
                {
                    max1=num[j];
                    p=j;
                }
                if(p!=numi-i-1)
                {
                    if(p!=0)
                    {
                        change(p);
                        ans[total++]=numi-p;
                    }
                    change(numi-i-1);
                    ans[total++]=i+1;
                }

        }
            if(total==0)
                cout<<0<<endl;
            else
            {
                for(int i=0;i<total;i++)
                    cout<<ans[i]<<" ";
                cout<<0<<endl;
            }

    }

    return 0;
}

