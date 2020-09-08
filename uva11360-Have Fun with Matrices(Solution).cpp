#include<iostream>
using namespace std;
int main()
{
    int T,N,M,num=1,sor,A,B;

    cin>>T;
    while(T--)
    {
        char mar[50][50]= {},temp[50][50]= {};
        char oper[50][10000]= {};
        sor=0;
        cin>>N;
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
            {
                cin>>mar[i][j];
            }
        cin>>M;

        for(int i=0; i<M; i++)
        {
            cin>>oper[i];
            if(oper[i][0]=='r'&&oper[i][1]=='o'&&oper[i][2]=='w')
            {
                cin>>A>>B;
                for(int i=0; i<N; i++)
                    temp[0][i]=mar[A-1][i];
                for(int i=0; i<N; i++)
                    mar[A-1][i]=mar[B-1][i];
                for(int i=0; i<N; i++)
                    mar[B-1][i]=temp[0][i];

            }
            else if (oper[i][0]=='c'&&oper[i][1]=='o'&&oper[i][2]=='l')
            {
                cin>>A>>B;
                for(int i=0; i<N; i++)
                    temp[i][0]=mar[i][A-1];
                for(int i=0; i<N; i++)
                    mar[i][A-1]=mar[i][B-1];
                for(int i=0; i<N; i++)
                    mar[i][B-1]=temp[i][0];
            }
            else if (oper[i][0]=='i'&&oper[i][1]=='n'&&oper[i][2]=='c')
            {
                for(int i=0; i<N; i++)
                    for(int j=0; j<N; j++)
                    {
                        sor=((mar[i][j]-'0')+1);
                        if(sor==10)
                        {
                            sor=0;
                            mar[i][j]=sor+'0';
                        }
                        else
                        mar[i][j]=sor+'0';

                    }

            }
            else if(oper[i][0]=='d'&&oper[i][1]=='e'&&oper[i][2]=='c')
            {
                for(int i=0; i<N; i++)
                    {for(int j=0; j<N; j++)
                    {
                        if((mar[i][j]-'0')==0)
                        {
                            sor=9;
                            mar[i][j]=sor+'0';
                        }
                        else
                            {
                                sor=(mar[i][j]-'0')-1;
                                mar[i][j]=sor+'0';
                            }


                    }
                    }
            }
            else if (oper[i][0]=='t'&&oper[i][1]=='r'&&oper[i][2]=='a')
            {
                for(int i=0; i<N; i++)
                        for(int j=0; j<N; j++)
            {
                temp[i][j]=mar[i][j];
            }
                for(int i=0; i<N; i++)
                        for(int j=0; j<N; j++)
            {

                mar[i][j]=temp[j][i];

            }
            }
        }
        cout<<"Case #"<<num<<endl;
        num++;
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                cout<<mar[i][j];
            }
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}
