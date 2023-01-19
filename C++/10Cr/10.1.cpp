#include <iostream>
#include <vector>
#include <cmath>

float firstRoute(float x){
return x*x;
}

float secondRoute(float x){
return cos(x+1);
}

float thirdRoute(float x){
float b = pow(tan(2*pow(M_E,x)),2);
return b;
}

void result(float x)
{
    float a;
   if(x<=-1)
    {
        a=firstRoute(x);
    }
    else if( -1<x && x<=3)
    {
        a=secondRoute(x);
    }
    else 
    {
        a=thirdRoute(x);
    }
   float y=1.5*a+0.6*pow(sin(x),2)-3.4;
    std::cout<<"Ответ: "<<y<<" для x="<<x+1<<std::endl;
}

int main()
{
    float x,xstart,xend,period;
    std::cout<<"Введите x начало"<<std::endl;
    std::cin>>xstart;
    std::cout<<"Введите x конец"<<std::endl;
    std::cin>>xend;
    std::cout<<"Введите интервал"<<std::endl;
    std::cin>>period;
    for(float i=xstart;i<xend;i+=period)
    {
        result(i);
    }
    return 0;
}