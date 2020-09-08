#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
    string str1,str2;

    while(getline(cin,str1))
   {
       getline(cin,str2);
       int str1l,str2l,max1,min1;
       string ans="",nstr1="",nstr2="";
    sort(str1.begin(),str1.end());
    sort(str2.begin(),str2.end());
    str1l=str1.size();
    str2l=str2.size();
    max1=max(str1l,str2l);
    min1=min(str1l,str2l);
    if(str1l>=str2l)
    {
        nstr1=str1;
        nstr2=str2;
    }
    else
    {
        nstr1=str2;//ªøªº
        nstr2=str1;
    }
    for(int i=0;i<min1;i++)
        for(int j=0;j<max1;j++)
    {
        if(nstr2[i]==nstr1[j])
        {
            ans+=nstr2[i];
            nstr2[i]='\0';
            nstr1[j]='\0';
            break;
        }
    }
    cout<<ans<<endl;

   }
}

