#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
class book
{

public:

    book(string a, string t);
    string author();
    string title();
    bool borrowed();
    bool returned();
    void Borrow();
    void Return();
    void Placed();
private:

    string Author;
    string Title;
    bool Borrowed;
    bool Returned;

};

book::book(string a, string t)
{
    Author = a;
    Title = t;
    Returned=false;
    Borrowed=false;

}

string book::author()
{
    return Author;
}

string book::title()
{
    return Title;
}

bool book::borrowed()
{
    return Borrowed;
}

bool book::returned()
{
    return Returned;
}
void book::Borrow()
{
    Borrowed=true;
}
void book::Return()
{
    Borrowed=false;
    Returned=true;
}
void book::Placed()
{
    Returned=false;
}
bool rule(book A,book B)
{
    if(A.author()!=B.author())
        return A.author()<B.author();
    else
        A.title()<B.title();
    }
int main()
{

    vector<book> shelve;
    map<string,int> table;
    char c;
    while(cin.get(c)&&c=='"')
    {
        string T="";
        T+=c;//因為是char丟進strin,string 不能 = char 但是可以 +cha
        while(cin.get(c)&&c!='"')
        {
            T+=c;
        }
        T+=c;
        string by,A="";
        cin>>by;
        cin.get(c);
        while(cin.get(c)&&c!='\n')
        {
            A+=c;
        }
        book temp(A,T);//book是變數就跟int temp(T,A)一樣
        shelve.push_back(temp);//把書放進書櫃
    }
    sort(shelve.begin(),shelve.begin()+shelve.size(),rule);//先把書做編排
    for(int i=0;i<shelve.size();i++)
    {
        table[shelve[i].title()]=i;
    }
    string cmd;
    cin>>cmd;
    while(cin>>cmd&&cmd!="END")
    {
        if(cmd=="SHELVE")
        {

            int prev=-1;//前一本書，預設為沒有
            for(int i=0;i<shelve.size();i++)
            {
                if(!shelve[i].borrowed()&&!shelve[i].returned())//在書架上
                {
                    prev=i;//前一本書存在
                }
                if(shelve[i].returned())//歸還上未歸為的書
                {
                    if(prev==-1)//沒有前一本書
                    {
                        cout<<"Put "<<shelve[i].title()<<" first"<<endl;
                    }
                    else
                    {
                        cout<<"Put "<<shelve[i].title()<<" after "<<shelve[prev].title()<<endl;
                    }
                    shelve[i].Placed();//歸位
                    prev=i;//成為下一本書的前一本書
                }
            }
            cout<<"END"<<endl;
            continue;
        }
        string B="\"";
        cin.get(c);
        cin.get(c);
        while(cin.get(c)&&c!='"')
        {
            B+=c;
        }
        B+=c;
        if(cmd=="BORROW")
        {
            shelve[table[B]].Borrow();
        }
        else if (cmd=="RETURN")
        {
            shelve[table[B]].Return();
        }

    }
    return 0;
}
