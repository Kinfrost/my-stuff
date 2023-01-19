#include <iostream>
#include <vector>


    std::vector<int> numbers;

void Mput_in(int cho)
{
for (int i=0;i<cho;i++)
{
  int in;
  std::cin>>in;
  numbers.push_back(in);
}
}
void Aput_in(int cho)
{
    for (int i=0;i<cho;i++)
{
    numbers.push_back(rand()%1000);
}
}

int main()
{
    int cho,choo;
    std::cout<<"Сколько будет элементов"<<std::endl;
    std::cin>>cho;
    std::cout<<"1-автоматическое заполенение"<<std::endl;
    std::cout<<"2-ручное заполенение"<<std::endl;
    std::cin>>choo;
    switch (choo)
    {
        case 1:
        {
            Aput_in(cho);
            break;
        }
        case 2:
        {
            Mput_in(cho);
            break;
        }
    }

     for (int i=0;i<cho;i++) std::cout<<numbers[i]<<" ";
     std::cout<<std::endl;
    for (int i=0;i<cho;i++)
    {
        int buf;
        buf=(numbers[i]/2)%2;
        if (buf==1)
        { 
            std::cout<<"Число "<<numbers[i]<<" под индексом "<<i+1<<std::endl;
        }

    }
    return 0;
}