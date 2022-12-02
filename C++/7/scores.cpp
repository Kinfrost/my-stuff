#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
sstd::vector<int>::const_iterator iter;
std::vector<int> scores;


void out_scores()
{
  std::cout<<"Рекорды:"<< std::endl;
    for(iter =scores.begin(); iter!= scores.end(); ++iter)
    {
        std::cout <<*iter<<std::endl;
    }    
}

void in_score(int i)
{
  int in;
  std::cout<<"Рекорд "<< i+1<<":";
  std::cin>>in;
  scores.push_back(in);
}

void init()
{
  int count;
  std::cout<<"Сколько рекордов?"<< std::endl;
  std::cin>>count;
  for(int i=0; i<count; i++)
    {
       in_score(i);
    }
  out_scores();
}

int max()
{
  iter=scores.begin();
  int res=*iter;
      for(iter =scores.begin(); iter!= scores.end(); ++iter)
    {
       if (res<*iter)res=*iter;
    }  
  return res;
}


bool search(int score)
{
iter = find(scores.begin(), scores.end(), score);
if (iter!= scores.end())
return true;
else
return false;
}

void shuffle()
{
  srand(static_cast<unsigned int>(time(0)));
  random_shuffle(scores.begin(),scores.end());
}

int main()
{
    init();
  int choice;
  
  do{
    std::cout<<"1- Найти рекорд"<<std::endl;
    std::cout<<"2- Сортировать рекорды"<<std::endl;
    std::cout<<"3- Вывести самый большой рекорд"<<std::endl;
    std::cout<<"4- Вывести все рекорды"<<std::endl;
    std::cout<<"5- Перемешать все рекорды"<<std::endl;
    std::cout<<"6- Добавить новый рекорд"<<std::endl;
    std::cout<<"0- Выйти из программы"<<std::endl;
    std::cout<<">";
    std::cin>>choice;
    std::cout<<"\n";
  switch (choice)
  {
  case 1:
    std::cout<<"Введите рекорд который вы хотите найти"<<std::endl;
    std::cin>>choice;
    if (search(choice))
    {
      std::cout<<"Такой рекорд есть"<<std::endl;
    }
    else
    {
      std::cout<<"Такого рекорда нет"<<std::endl;
    }
    std::cout<<"\n";
    break;
  case 2:
    std::sort(scores.begin(),scores.end());
    out_scores();
    std::cout<<"\n";
    break; 
  case 3:
      std::cout<<"Самый большой рекорд: "<<max()<<std::endl;
    std::cout<<"\n";
    break;
  case 4:
    out_scores();
    std::cout<<"\n";
    break;
  case 5:
    shuffle();
    out_scores();
    std::cout<<"\n";
    break;
  case 6: 
    in_score(scores.size());
    break;
  case 0:
    return 0;
    break;
  default:
    break;
  }
  }while (choice!=0);
  return 0;
}

