#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int N,Q;
    int count1=1;
    while(cin>>N>>Q&&N!=0&&Q!=0)
    {
        int total[10000]= {0};
        int check[10000]= {0};
        int ans[10000]= {-1};
        for(int i=0; i<N; i++)
        {
            cin>>total[i];
        }
        for(int i=0; i<Q; i++)
        {
            cin>>check[i];
        }
        for(int i=0; i<Q; i++)
        {
            ans[i]=-1;
        }
        cout<<"CASE# "<<count1<<":"<<endl;
        count1++;
        sort(total,total+N);
        for(int i=0; i<Q; i++)
        {
            for(int j=0; j<N; j++)
            {
                if(check[i]==total[j])
                {
                    ans[i]=j;
                    break;
                }
            }
        }

        for(int i=0; i<Q; i++)
            {
                if(ans[i]==-1)
                    cout<<check[i]<<" not found"<<endl;
                else
                    cout<<check[i]<<" found at "<<ans[i]+1<<endl;
            }
    }
}

