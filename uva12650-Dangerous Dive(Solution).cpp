#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
    int R,N;
    while(cin>>N>>R)
    {
        int num[10000]={0},check[10000]={0},count1=0;
        for(int i=0;i<R;i++)
        {
            cin>>check[i];
        }
        sort(check,check+R);
        for(int i=0;i<N;i++)
        {
            num[i]=i+1;
        }
        for(int i=0;i<R;i++)
        {
            if(check[i]==num[check[i]-1])
            {
                num[check[i]-1]=0;
                count1++;
            }
        }
        for(int i=0;i<N;i++)
        {
            if(count1==N)
                {cout<<'*';
                break;}
            else if(num[i]!=0)
            {
                cout<<num[i]<<" ";

            }

        }
        cout<<endl;
    }

}
