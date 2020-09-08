#include<iostream>
using namespace std;
int main()
{
    int count1=1,ques,record[1000],total=0,ans=0;
    for(int i=1; i<=1000; i++)
        {
            total=0;
            for(int j=1; j<=i; j++)
            {
                if(i%j==0)
                    total+=j;
            }
            record[i-1]=total;
        }

    while(cin>>ques&&ques!=0)
    {
        total=0;
        ans=00;

        for(int i=999; i>=0; i--)
        {
            if(record[i]==ques)
            {
                ans=i+1;
                break;
            }
        }
        if(ans==0)
            cout<<"Case "<<count1<<": "<<"-1"<<endl;
        else
            cout<<"Case "<<count1<<": "<<ans<<endl;
        count1++;
    }
}
