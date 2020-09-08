#include <iostream>
using namespace std;
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int m,n,ans=0;
       cin>>m>>n;
       ans=(m/3)*(n/3);
       cout<<ans<<endl;
   }
}

