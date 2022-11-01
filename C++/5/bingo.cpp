#include <cstdio>
#include <cstdlib>
#include <iostream>
const int maxvalue = 90, ballcount = 75;
const int side = 5;
int bingo_card[side][side];
int balls[2][maxvalue];
int win_balls[2][ballcount];
int roundd = 1;

int megarand() {
  static unsigned seed = rand();
  seed = (seed * 73129 + 95121) % 100000;
  srand(seed);
  int randomNum = rand();
  return randomNum;
}

int num_ball() { return (megarand() % maxvalue) + 1; }
int letter_ball() { return (megarand() % side); }

void shuffle_balls() {
  for (int i = 0; i < maxvalue; i++) {

    balls[1][i] = i + 1;
    balls[0][i] = letter_ball();
  }
  for (int i = 0; i < maxvalue; ++i) {
    int sw = num_ball();
    std::swap(balls[0][i], balls[0][sw]);

    std::swap(balls[1][i], balls[1][sw]);
  }
}

void create_card() {
  for (int i = 0; i < side; i++) {
    for (int j = 0; j < side; j++) {
      if (i == (side / 2 + side % 2) - 1 && j == (side / 2 + side % 2) - 1)
        bingo_card[i][j] = 0;
      else
        bingo_card[i][j] = num_ball();
    }
  }
}

void out_card() {
  std::cout << "B\tI\tN\tG\tO!\n";
  for (int i = 0; i < side; i++) {
    for (int j = 0; j < side; j++) {
      std::cout << bingo_card[i][j] << "\t";
    }
    std::cout << "\n";
  }
}

char letter_conv(int lball) {
  char letter = '0';
  switch (lball) {
  case 0:
    letter = 'B';
    break;
  case 1:
    letter = 'I';
    break;
  case 2:
    letter = 'N';
    break;
  case 3:
    letter = 'G';
    break;
  case 4:
    letter = 'O';
    break;
  }
  return letter;
}

void find_coincidence() {
  int f = 0;
  std::cout << "Шары на этот раунд\n";
  for (int i = 0; i < ballcount; i++) {
    std::cout << letter_conv(balls[0][i]) << balls[1][i] << "\t";
    int col = balls[0][i];
    if ((i + 1) % 5 == 0)
      std::cout << "\n";
    for (int j = 0; j < side; j++) {
      if (balls[1][i] == bingo_card[j][col]) {
        win_balls[0][f] = balls[0][i];
        win_balls[1][f] = balls[1][i];

        bingo_card[j][col] = 0;
        f++;
      }
    }
  }
  std::cout << "\n";
  if (f != 0) {
    std::cout << "\nСовпадения: ";
    for (int i = 0; i < f; i++) {
      if (win_balls[1][i] != 0) {
        std::cout << "\t" << letter_conv(win_balls[0][i]) << win_balls[1][i];
      }
    }
  } else {
    std::cout << "\nСовпадений нет";
  }
  std::cout << "\n\n";
}

int find_win() {
  int win = 0;
  int sum1 = 0, sum2 = 0;
  int win_card[side][side];
  for (int i = 0; i < side; i++) {
    for (int j = 0; j < side; j++) {
      if (bingo_card[i][j] != 0)
        win_card[i][j] = 0;
      else
        win_card[i][j] = 1;
    }
  }
  for (int i = 0; i < side; i++) {
    for (int j = 0; j < side; j++) {
      sum1 += win_card[i][j];
    }
    if (sum1 == 5)
      win++;
    sum1 = 0;
  }
  for (int i = 0; i < side; i++) {
    sum1 += win_card[i][i];
    sum2 += win_card[i][side - 1 - i];
  }
  if (sum1 == 5)
    win++;
  if (sum2 == 5)
    win++;
  return win;
}

void game_result() {
  std::cout << "\n";
  int win = find_win();
  if (win != 0) {
    std::cout << "Бинго! " << std::endl;
    std::cout << "У вас " << win << " собранных слов Bingo за " << roundd
              << " раунда";
  } else {
    std::cout << "Вам неповезло у вас ни одной выигрышной комбинации в "
              << roundd << " раунде";
  }
}

void game() {
  shuffle_balls();
  find_coincidence();
  out_card();
  game_result();
  roundd++;
}

int main() {
  int menu_choice;
  std::cout << "\n";
  create_card();
  std::cout << "Ваша карточка бинго на эту игру" << std::endl;
  out_card();
  std::cout << "\nХотите начать игру с этой карточкой?";
  do {
    std::cout << "\n\n1-Начать игру\n";
    std::cout << "2-Пересоздать карточку\n";
    std::cout << "0-Выйти из игры\n";
    std::cout << "> ";
    std::cin >> menu_choice;
    switch (menu_choice) {
    case 1:
      game();
      break;
    case 2:
      create_card();
      std::cout << "Ваша новая карточка бинго на эту игру" << std::endl;
      out_card();
      break;
    case 0:
      return 0;
      break;
    default:
      std::cout << "\nВыберите пункт меню\n";
      break;
    }
  } while (menu_choice != 0);
  return 0;
}