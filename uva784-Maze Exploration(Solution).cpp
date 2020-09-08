#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
char maze[100][100];
void cram(int x,int y)
{
    if(maze[x][y]!=' ')
        return;
    maze[x][y]='#';
    cram(x+1,y);
    cram(x-1,y);
    cram(x,y+1);
    cram(x,y-1);

}
int main()
{
    int N;
    char a;

    cin>>N;
    cin.get();
    while(N--)
    {
        string underline;
        string temp;
        int q=0,w=0,length1[100]= {};
        while(getline(cin,temp))
        {
            if(temp=="")
                break;
            if(temp[0]=='_')
            {
                underline=temp;
                break;
            }
            length1[w]=temp.size();
            for(int i=0; i<temp.size(); i++)
            {
                maze[q][i]=temp[i];

            }
            q++;
            w++;
        }

        for(int i=0; i<q; i++)
            for(int j=0; j<length1[i]; j++)
            {
                if(maze[i][j]=='*')
                {
                    maze[i][j]=' ';
                    cram(i,j);
                }
            }
        for(int i=0; i<q; i++)
        {
            for(int j=0; j<length1[i]; j++)
            {
                cout<<maze[i][j];
            }
            cout<<endl;
        }
        for(int i=0; i<underline.size(); i++)
            cout<<underline[i];
        cout<<endl;



    }
}
