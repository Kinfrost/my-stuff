#include <iostream>

int main() {
  int score;
  double distance;
  char playAgain;
  bool shieldsUp;
  short lives, aliensKilled;
  score = 0;
  distance = 1200.76;
  playAgain = 'y';
  shieldsUp = true;
  lives = 3;
  aliensKilled = 10;
  double engineTemp = 6572.82;
  std::cout << "score " << score << std::endl;
  std::cout << "distance " << distance << std::endl;
  std::cout << "playAgain " << playAgain << std::endl;
  std::cout << "lives " << lives << std::endl;
  std::cout << "aliensKilled " << aliensKilled << std::endl;
  std::cout << "engineTemp " << aliensKilled << std::endl;
  int fuel;
  std::cout << "\nHow much fuel left? ";
  std::cin >> fuel;
  std::cout << "Amount of Fuel in tank " << fuel << std::endl;
  typedef unsigned short int ushort;
  ushort bonus = 10;
  std::cout << "\nBonus " << bonus << std::endl;
  return 0;
}