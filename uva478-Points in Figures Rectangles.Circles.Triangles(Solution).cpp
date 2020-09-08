#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
class Shape

{

public:
    virtual bool in_area(double ,double ) = 0;

};

class Rectangle : public Shape
{
private:

    double x1,y1,x2,y2;

public:

    Rectangle(double,double,double,double);

    bool in_area(double,double);

};
Rectangle::Rectangle(double a1,double b1,double a2,double b2)
{
    x1=a1;
    y1=b1;
    x2=a2;
    y2=b2;
}
bool Rectangle::in_area(double ins1,double ins2)
{
    if (ins1>x1&&ins1<x2&&ins2<y1&&ins2>y2)
        return true;
    else
        return false;
}

class Circle : public Shape

{

private:

    double x,y,r;

public:

    Circle(double,double,double);

    bool in_area(double,double);

};
Circle::Circle(double a1,double b1,double c)
{
    x=a1;
    y=b1;
    r=c;
}
bool Circle::in_area(double ins1,double ins2)
{
    double check;
    check =(ins1-x)*(ins1-x)+(ins2-y)*(ins2-y);
    if(check>=r*r)
        return false;
    else
    return true;
}
class Triangle : public Shape

{

private:

    double x1,y1,x2,y2,x3,y3;

public:

    Triangle(double,double,double,double,double,double);

    bool in_area(double,double);

};
Triangle::Triangle(double a1,double b1,double a2,double b2,double a3,double b3)
{
    x1=a1;
    y1=b1;
    x2=a2;
    y2=b2;
    x3=a3;
    y3=b3;
}
bool Triangle::in_area(double ins1,double ins2)
{
    double ABC,DAB,DBC,DAC;
    ABC=(x2-x1)*(y3-y1)-((x3-x1)*(y2-y1));
    ABC=abs(ABC)/2;
    DAB=(x1-ins1)*(y2-ins2)-((x2-ins1)*(y1-ins2));
    DAB=abs(DAB)/2;
    DAC=(x1-ins1)*(y3-ins2)-((x3-ins1)*(y1-ins2));
    DAC=abs(DAC)/2;
    DBC=(x2-ins1)*(y3-ins2)-((x3-ins1)*(y2-ins2));
    DBC=abs(DBC)/2;
    if(abs(DAB+DBC+DAC-ABC)<0.000001)
    {
        if(DAB>0&&DBC>0&&DAC>0)
          return true;
        else
            return false;
    }
    else
        return false;

}
int main()
{
    char shape;
    double a1,b1,a2,b2,a3,b3,c,x,y;
    bool flag=true;
    vector <Shape*> v;
    while(cin>>shape)
    {
        if(shape=='r')
        {
            cin>>a1>>b1>>a2>>b2;
            Shape*s=new Rectangle(a1,b1,a2,b2);
            v.push_back(s);

        }
        else if (shape=='c')
        {
            cin>>a1>>b1>>c;
            Shape*s=new Circle(a1,b1,c);
            v.push_back(s);
        }
        else if (shape=='t')
        {
            cin>>a1>>b1>>a2>>b2>>a3>>b3;
            Shape*s=new Triangle(a1,b1,a2,b2,a3,b3);
            v.push_back(s);
        }
        if(shape=='*')
        {
            int count1=1;
            while(cin>>x>>y)
            {
                bool flag1=false;
                if (x==9999.9&&y==9999.9)
                {
                    flag=false;
                    break;
                }
                else
                {
                    for(int i=0;i<v.size();i++)
                        if(v[i]->in_area(x,y))
                    {
                        cout<<"Point "<<count1<<" is contained in figure "<<i+1<<endl;
                        flag1=true;
                    }
                    if(flag1==false)
                        cout<<"Point "<<count1<<" is not contained in any figure"<<endl;
                }
                count1++;
            }

        }
        if(flag==false)
            break;
    }
}
