#include <cstddef>
#include <fstream>
#include <ios>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

std::vector<std::string> inventory;

std::ofstream fout;
std::ifstream fin;

void del(int ind) {
  for (ind; ind < inventory.size(); ind++) {
    inventory[ind - 1] = inventory[ind];
  }
  inventory.pop_back();
}

void in() {
  fin.open("inventory.txt");
  if (fin) {
    bool over = 0;
    while (!fin.eof()) {
      std::string buff;
      getline(fin, buff);
      if (buff[0] != '\0')
        inventory.push_back(buff);
    }
  } else {
    fout.open("inventory.txt");
    fout.close();
    std::cout << "Файл инвентаря не найден или повреждён создан новый файл.\n"
              << std::endl;
  }
  fin.close();
}

void updatef() {
  std::vector<std::string>::const_iterator iter;
  fout.open("inventory.txt", std::ios_base::trunc);
  for (iter = inventory.begin(); iter != inventory.end(); ++iter) {

    fout << *iter;
    if (iter != inventory.end() - 1)
      fout << "\n";
  }
  fout.close();
}

void out() {
  fin.open("inventory.txt");
  if (fin) {
    if (inventory.empty()) {
      std::cout << "\nУ вас ничего нет\n" << std::endl;
    } else {
      int i = 0;
      while (!fin.eof()) {
        std::string buff;
        getline(fin, buff);
        std::cout << "№" << i + 1 << " " << buff << std::endl;
        i++;
      }
    }
  } else {
    fout.open("inventory.txt");
    fout.close();
    std::cout << "Файл инвентаря не найден или повреждён создан новый файл.\n";
  }
  fin.close();
}

int main() {
  in();
  updatef();
  std::cout << "Добро пожаловать в инвентарь" << std::endl;
  for (;;) {
    int vibor;
    std::cout << "Список действий\n";
    std::cout << "1- Вывести содержимое инвентаря\n";
    std::cout << "2- Добавить предмет в инвентарь\n";
    std::cout << "3- Выкинуть предмет из инвентаря\n";
    std::cout << "4- Очистить инвентарь\n";
    std::cout << ">";
    std::cin >> vibor;
    switch (vibor) {
    case 1: {
      std::cout << "Ваш инвентарь\n";
      out();
      break;
    }
    case 2: {
      std::cout << "У вас появился: ";
      std::string buff;
      std::cin >> buff;
      inventory.push_back(buff);
      updatef();
      break;
    }
    case 3: {
      std::cout << "Введите номер предмета который вы хотите удалить\n";
      out();
      std::cout << ">";
      std::cin >> vibor;
      del(vibor);
      updatef();
      break;
    }
    case 4: {
      inventory.clear();
      updatef();
      break;
    }
    case 0: {
      return 0;
    }
    default:
      std::cout << "Выберите действие из списка" << std::endl;
    }
  }
}