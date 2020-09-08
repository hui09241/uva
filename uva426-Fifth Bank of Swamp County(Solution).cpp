#include<iostream>
#include<vector>
#include<iomanip>
#include<cmath>
#include<algorithm>
#include<sstream>
using namespace std;
class History
{

private:
    string date;
    int check_number;
    double dollar;
    bool star; //用來判斷輸出時是否要加星號

public:

    History(string d,int c,double dol);
    void print_history();
    void set_star(bool star1);
    int get_check_number();


};
History::History(string d,int c,double dol)
{
    date=d;
    check_number=c;
    dollar=dol;
    star=true;
}
void History::set_star(bool star1)
{
    star=star1;
}
int History::get_check_number()
{
    return check_number;
}
bool rule(History A,History B)
{
    return A.get_check_number()<B.get_check_number();
}
void History::print_history()
{

    if(star==false)
        cout<<setw(4)<<check_number<<"* "<<setw(9)<<fixed<<setprecision(2)<<dollar<<" "<<date;

    else
        cout<<setw(4)<<check_number<<"  "<<setw(9)<<fixed<<setprecision(2)<<dollar<<" "<<date;

}
int main()
{

    int N;
    char a;
    string d="";
    int c;
    double dol;
    cin>>N;
    cin.get();
    cin.get();
    while(N--)
    {
        vector<History> summary;
        string temp1;

        while(getline(cin,temp1))
        {

            if(temp1=="")
                break;
            stringstream ntemp(temp1);
            ntemp>>d;
            ntemp>>c;
            ntemp>>dol;
            History temp(d,c,dol);
            summary.push_back(temp);
        }
        sort(summary.begin(),summary.begin()+summary.size(),rule);
        bool star1=true;
        for(int i=1; i<summary.size(); i++)
        {
            if(summary[i].get_check_number()!=summary[i-1].get_check_number()+1)
            {
                summary[i].set_star(false);
            }

        }
        int x=ceil(summary.size()/3.0);
        for(int i=0;i<x;i++)
        {
            for(int j=0;j<3;j++)
            {
                if((j*x+i)>=summary.size())
                    break;
                if(j!=0)
                    cout<<"   ";
                summary[j*x+i].print_history();

            }
            cout<<endl;
        }
        if(N!=0)
            cout<<endl;
    }


}

