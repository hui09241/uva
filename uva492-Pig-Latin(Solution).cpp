#include<iostream>
#include<vector>
#include<sstream>
#include<cctype>
using namespace std;
int main()
{
    string cins,temps;
    while(getline(cin,cins))
    {
        bool flag=true;
        stringstream ss;
        for(int i=0;i<cins.size();i++)
        {
            if((cins[i]>='A'&&cins[i]<='Z')||(cins[i]>='a'&&cins[i]<='z'))
            {
                if(i==cins.size()-1)
                {
                    ss<<cins[i];
                    ss>>temps;
                    if(temps[0]=='a'||temps[0]=='A'||temps[0]=='e'||temps[0]=='E'||temps[0]=='i'||temps[0]=='I'||temps[0]=='o'||temps[0]=='O'||temps[0]=='u'||temps[0]=='U')
                        cout<<temps<<"ay";
                    else
                    {
                        for(int j=1;j<temps.size();j++)
                        {
                            cout<<temps[j];
                        }
                        cout<<temps[0]<<"ay";
                    }
                    temps.clear();
                    ss.str(" ");
                    flag=true;
                }
                else
                {
                    ss<<cins[i];
                    flag=false;
                }
            }
            else
            {
                if(flag==false)
                {
                    ss>>temps;
                   if(temps[0]=='a'||temps[0]=='A'||temps[0]=='e'||temps[0]=='E'||temps[0]=='i'||temps[0]=='I'||temps[0]=='o'||temps[0]=='O'||temps[0]=='u'||temps[0]=='U')
                   {
                       cout<<temps<<"ay"<<cins[i];
                   }
                   else
                   {
                       for(int j=1;j<temps.size();j++)
                       {
                           cout<<temps[j];
                       }
                       cout<<temps[0]<<"ay"<<cins[i];
                   }
                   ss.clear();
                   ss.str(" ");
                   flag=true;
                }
                else
                {
                    cout<<cins[i];
                }
            }
        }
        cout<<endl;

    }
}
