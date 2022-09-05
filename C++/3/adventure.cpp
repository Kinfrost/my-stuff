#include <iostream>
#include <string>

int main()
{
const int GOLD_PIECES = 900;
int adventurers, killed, survivors;
std::string leader;
std::cout <<"Добро пожаловать в потеряный форт\n\n";
std::cout <<"Пожалуйста введите ответы на вопросы для вашего персонального приключения\n";
do {
std::cout <<"Введите не отрицательное число: ";
std::cin >> adventurers;
}while (adventurers<0);
std::cout <<"Введите число меньше прошлого но не отрицательное: ";   
std::cin >> killed;
survivors=adventurers-killed;
std::cout <<"Введите ваше имя: "; 
std::cin >> leader;
std::cout <<"\nБравая группа из " << adventurers << " приключенцев вышла на задание ";
std::cout <<"-- в поисках потеряного сокровища древних дварфов. ";
std::cout <<"\nГруппу возглавлял легедарный расхититель гробниц "<<leader<<".\n";
if (survivors>adventurers)
{
std::cout <<"\nНа пути к сокровищам, приключенцы наткнулись на таких же приключенцев.\n";
std::cout <<"Приключенцы присоединились к группе и отправились вместе искать сокровища.\n";
std::cout <<"Группа начала насчитывать "<<survivors<<" приключенцев. \n\n";
std::cout <<"Оказавшись перед заброшенной крепостью приключенцы решили зайти внутрь.\n";
std::cout <<"Внутри они нашли "<< GOLD_PIECES <<" золотых самородков.\n";
std::cout <<"Каждому приключенцу досталось по "<<(GOLD_PIECES/survivors)<<"\n";
if(GOLD_PIECES%survivors!=0)
{
std::cout <<"А лидеру "<< leader <<" полагались дополнительные "<< GOLD_PIECES%survivors <<" самородка.";
}
}
else if(survivors==adventurers)
{
std::cout <<"\nНа пути к сокровищам, приключенцы никого не встретили.\n";
std::cout <<"Группа точно также насчитывала "<<survivors<<" приключенцев. \n\n";
std::cout <<"Оказавшись перед заброшенной крепостью приключенцы решили зайти внутрь.\n";
std::cout <<"Внутри они нашли "<< GOLD_PIECES <<" золотых самородков.\n";
std::cout <<"Каждому приключенцу досталось по "<<(GOLD_PIECES/survivors)<<"\n";
if(GOLD_PIECES%survivors!=0)
{
std::cout <<"А лидеру "<< leader <<" полагались дополнительные "<< GOLD_PIECES%survivors <<" самородка.";
}
}
else if(survivors<=0)
{
std::cout <<"\nНа пути к сокровищам, приключенцы встретили дракона.\n";
std::cout <<"Никто не выжил, все приключенцы погибли как герои сражаясь с драконом.\n";
}
else
{
std::cout <<"\nНа пути к сокровищам, приключенцы наткнулись на бандитов.\n";
std::cout <<"Приключенцы сражались как герои но не всем удалось выжить после битвы.\n";
std::cout <<"Группа начала насчитывать "<<survivors<<" приключенцев. \n\n";
std::cout <<"Оказавшись перед заброшенной крепостью приключенцы решили зайти внутрь.\n";
std::cout <<"Внутри они нашли "<< GOLD_PIECES <<" золотых самородков.\n";
std::cout <<"Каждому выжившему приключенцу досталось по "<<(GOLD_PIECES/survivors)<<"\n";
if(GOLD_PIECES%survivors!=0)
{
std::cout <<"А лидеру "<< leader <<" полагались дополнительные "<< GOLD_PIECES%survivors <<" самородка.";
}
}
 return 0;
}