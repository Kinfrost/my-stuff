#include <iostream>
#include <string>

int main()
{
    std::string in;
    int a=0;
    std::cout<<"Введите строку"<<std::endl;
    std::cin>>in;
    int buff=0;
    for (int i=0;i<in.length();i++)
    {   
        if(isdigit(in[i]))
        {
            buff*=10;
            buff+=int(in[i])- 48;
        }
        else
        {
        a+=buff;
        buff=0;
        }
    }
    a+=buff;
    buff=0;
    std::cout<<"Сумма всех чисел из предложения "<<a<<std::endl;
    return 0;
}