#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    unsigned long long int n,m2,m3,m5,m7,mmin;
    unsigned long long int a2=0,a3=0,a5=0,a7=0,ans[5843]= {1};
    for(int i=1; i<=5842; i++)
    {
        m2=ans[a2]*2;
        m3=ans[a3]*3;
        m5=ans[a5]*5;
        m7=ans[a7]*7;
        mmin=min(min(m2,m3),min(m5,m7));
        if(mmin==m2)
        {
            a2++;
        }
        if(mmin==m3)
        {
            a3++;
        }
        if(mmin==m5)
        {
            a5++;
        }
        if(mmin==m7)
         {
             a7++;
         }

        ans[i]=mmin;
    }

    while(cin>>n&&n!=0)
    {
        if(n%10==1&&n%100!=11)
            cout<<"The"<<" "<<n<<"st"<<" "<<"humble number is "<<ans[n-1]<<"."<<endl;
        else if (n%10==2&&n%100!=12)
            cout<<"The"<<" "<<n<<"nd"<<" "<<"humble number is "<<ans[n-1]<<"."<<endl;
        else if (n%10==3&&n%100!=13)
            cout<<"The"<<" "<<n<<"rd"<<" "<<"humble number is "<<ans[n-1]<<"."<<endl;
        else
            cout<<"The"<<" "<<n<<"th"<<" "<<"humble number is "<<ans[n-1]<<"."<<endl;
    }
}

