#include<iostream>
#include<sstream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
    string ss;
    bool flag=true;
    while(cin>>ss&&ss[0]!='0')
    {
        int orin=atoi(ss.c_str());
        int count1=0,num[5000]={};
        cout<<"Original number was "<<orin<<endl;
        while(flag==true)
        {
            string big=ss;
            sort(big.begin(),big.end());
            string small=big;
            reverse(big.begin(),big.end());
            int b=atoi(big.c_str()),s=atoi(small.c_str());
            num[count1]=b-s;
            stringstream sss;
            sss<<num[count1];
            sss>>ss;
            cout<<b<<" - "<<s<<" = "<<num[count1]<<endl;

            for(int i=0;i<count1;i++)
            {
                if(num[i]==num[count1])
                {
                    flag=false;
                    break;
                }
            }
            count1++;
        }
            cout<<"Chain length "<<count1<<endl;
            flag=true;
            cout<<endl;
         }
}
