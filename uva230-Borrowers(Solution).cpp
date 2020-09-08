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
        T+=c;//�]���Ochar��istrin,string ���� = char ���O�i�H +cha
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
        book temp(A,T);//book�O�ܼƴN��int temp(T,A)�@��
        shelve.push_back(temp);//��ѩ�i���d
    }
    sort(shelve.begin(),shelve.begin()+shelve.size(),rule);//����Ѱ��s��
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

            int prev=-1;//�e�@���ѡA�w�]���S��
            for(int i=0;i<shelve.size();i++)
            {
                if(!shelve[i].borrowed()&&!shelve[i].returned())//�b�Ѭ[�W
                {
                    prev=i;//�e�@���Ѧs�b
                }
                if(shelve[i].returned())//�k�٤W���k������
                {
                    if(prev==-1)//�S���e�@����
                    {
                        cout<<"Put "<<shelve[i].title()<<" first"<<endl;
                    }
                    else
                    {
                        cout<<"Put "<<shelve[i].title()<<" after "<<shelve[prev].title()<<endl;
                    }
                    shelve[i].Placed();//�k��
                    prev=i;//�����U�@���Ѫ��e�@����
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
