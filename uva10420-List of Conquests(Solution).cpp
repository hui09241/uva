#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    vector<string> A;
    cin>>n;
    cin.get();
    while(n--)
    {
        string ss,a="";
        getline(cin,ss);
        for(int i=0;i<ss.size();i++)
        {
            if(ss[i]==' ')
                break;
            else
                a+=ss[i];

        }
        A.push_back(a);
    }
    sort(A.begin(),A.end());
    int ans=1;
    A.push_back("");
    for(int i=0;i<A.size()-1;i++)
    {
        if(A[i]==A[i+1])
            ans++;
        else if(A[i]!=A[i+1])
        {
                cout<<A[i]<<" "<<ans<<endl;
                ans=1;
        }
    }



}
