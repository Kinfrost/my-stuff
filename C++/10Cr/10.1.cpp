#include <iostream>
#include <vector>
#include <cmath>

float first(float x){
return x*x;
}
float second(float x){
return cos(x+1);
}
float third(float x){
float b = pow(tan(2*pow(M_E,x)),2);
return b;
}


int main()
{
    float x,a;
    std::cout<<"Введите x"<<std::endl;
    std::cin>>x;
    if(x<=-1)
    {
        a=first(x);
    }
    else if( -1<x && x<=3)
    {
        a=second(x);
    }
    else 
    {
        a=third(x);
    }
   float y=1.5*a+0.6*pow(sin(x),2)-3.4;
    std::cout<<"Ответ: "<<y<<std::endl;
    return 0;
}