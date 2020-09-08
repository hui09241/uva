#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int arr[1000]={},num=1,count1=0,t,num1;
    bool flag=true;
    while(cin>>t)
    {
        num=1;
        count1=0;
        flag=true;
        if (t==0)
        {
            break;
        }
        else
        {
            arr[0]=t;
            while (cin>>arr[num]&&arr[num]!=0)
            {
                num++;
            }
            num1=num;
            num1=(num1/2)-1;

            if ((num%2)==0)
                cout<<"NO"<<endl;
            else if((num%2)!=0)
            {
                sort(arr,arr+num);
                if (num==1)
                {
                    cout<<arr[0]<<endl;
                }
                else if (num!=1)
                {

                    for (int q=0; q<num-1; q+=2)
                    {
                        if(arr[q]!=arr[q+1])
                        {
                            flag=false;
                            break;
                        }
                    }
                    if(flag==false)
                    {
                        cout<<"NO"<<endl;
                    }
                    else
                    {
                        for(int i=0; i<num; i+=2)
                            cout<<arr[i]<<" ";
                        for(int i=num-2; i>0; i-=2)
                          {
                              cout<<arr[i];
                                if (num1!=0)
                                {
                                    cout<<" ";
                                    num1--;
                                }
                          }
                        cout<<endl;
                    }


                }
            }
        }

    }
    return 0;
}


