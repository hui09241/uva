#include<iostream>
#include<sstream>
#include<algorithm>
#include<cstring>
using namespace std;
struct Team
{
    bool join;
    int num;
    int score;
    int pro;
    int error[100];
};
bool compares(Team a,Team b)
{
    if(a.pro>b.pro)
        return true;
    if(a.pro<b.pro)
        return false;
    if(a.score<b.score)
        return true;
    if(a.score>b.score)
        return false;
    if(a.num<b.num)
        return true;
    return false;
}
int main()
{
    int n;
    Team teams[110];
    string test;
    stringstream ss;
    int tnum,pro,time;
    char L;
    cin>>n;
    cin.get();
    cin.get();
    while(n>0)
    {
        for( int j = 0 ; j < 110 ; j++ ){
        teams[j].join = false;
        teams[j].num = j;
        teams[j].score = 0;
        teams[j].pro = 0;
        memset( teams[j].error, 0, sizeof(teams[j].error) );
      }

        while(getline(cin,test)&&test!="")
        {
            ss.clear();
            ss<<test;
            ss>>tnum>>pro>>time>>L;
            teams[tnum].join=true;
            if(teams[tnum].error[pro]==-99)
            continue;
            if(L=='C')
            {
                teams[tnum].score+=time+teams[tnum].error[pro]*20;
                teams[tnum].pro++;
                teams[tnum].error[pro]=-99;

            }
            else if (L=='I')
            {
                teams[tnum].error[pro]++;
            }

        }
        sort(teams,teams+105,compares);
        for(int i=0;i<110;i++)
        {
            if(teams[i].join==true)
                cout<<teams[i].num<<" "<<teams[i].pro<<" "<<teams[i].score<<endl;
        }

        if(n!=1)
        cout<<endl;
        n--;
    }
}
