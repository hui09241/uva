#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main()
{
    vector<vector<long long int> > number;
    long long int x;
    long long int y= pow(2,32)+1;
    for(int i=2; i<=65536; i++)
    {
        long long int temp=1;
        vector<long long int>tmp;
        while(temp<y)
        {
            tmp.push_back(temp);
            temp=temp*i;
        }
        number.push_back(tmp);

    }
    while(cin>>x&&x!=0)
    {
        bool flag=false;

        for(int i=0; i<65536; i++)
        {
            for(int j=0; j<number[i].size(); j++)
            {
                if(j%2==0)
                {
                    if(x==number[i][j])
                    {
                        cout<<j<<endl;
                        flag=true;
                        break;
                    }
                }
                else
                {
                    if(x<0)
                    {
                        if(abs(x)==number[i][j])
                        {
                            cout<<j<<endl;
                            flag=true;
                            break;
                        }
                    }
                    else
                    {
                        if(x==number[i][j])
                        {
                            cout<<j<<endl;
                            flag=true;
                            break;
                        }
                    }
                }
            }
            if(flag==true)
                break;
        }
        if (flag==false)
            cout<<1<<endl;
    }

}
