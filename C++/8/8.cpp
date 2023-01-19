#include <iostream>
#include <vector>

int square_digits(int num) {
  std::vector<int> numbers;
  int size=1;
  while (num!=0)
  {
    int buff =num%10;
    numbers.push_back(buff);
    num=num/10;
  }
  num=0;
   for(int i=0; i< numbers.size(); i++)
    {
        
       numbers[i]*=numbers[i];
       if(numbers[i]!=0)
       num+=numbers[i]*size;
       else
       size*=10;
       int buff =1;
       int size_buff=numbers[i];
        while (size_buff!=0)
          {
            buff*=10;
            size_buff/=buff;
          }
        size*=buff;
    }   
 return num;
}
int main()
{
    int a;
    std::cin>>a;
    std::cout<<square_digits(a)<<std::endl;
    return 0;
}
