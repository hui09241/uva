#include<iostream>
using namespace std;
int main()
{
    int T;
    string ss;
    cin>>T;
    while(T--)
    {
        cin>>ss;
        int s;
        s=ss[ss.size()-1]-'0';
        if(ss=="0")
            cout << '1' << endl;
        else if(ss=="1")
            cout << "66" << endl;
        else if(s%5==0)
            cout << "76" << endl;
        else if(s%5==1)
            cout << "16" << endl;
        else if(s%5==2)
            cout << "56" << endl;
        else if(s%5==3)
            cout << "96" << endl;
        else if(s%5==4)
            cout << "36" << endl;
    }
}
