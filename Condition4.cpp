#include <iostream>

int main() {

  float userInput {};
  std::cout << "Please enter a monetary amount in dollars and cents: ";
  std::cin >> userInput;

  int money = userInput * 100;
  int dollars {};
  int quarters {};
  int dimes {};
  int nickles {};
  int pennies {};
  int counter {};

  while (money >= 100){
    money -= 100;
    dollars++;
  }
  while (money >= 25){
    money -= 25;
    quarters++;
  }
  while (money >= 10){
    money -= 10;
    dimes++;
  }
  while (money >= 5){
    money -= 5;
    nickles++;
  }
  while (money >= 1){
    money -= 1;
    pennies++;
  }

  if (dollars == 1){
    std::cout << dollars << " dollar" << std::endl;
  } else {
      std::cout << dollars << " dollars" << std::endl;
  }

  if (quarters == 1){
    std::cout << quarters << " quarter" << std::endl;
  } else {
      std::cout << quarters << " quarters" << std::endl;
  }

  if (dimes == 1){
    std::cout << dimes << " dime" << std::endl;
  } else {
      std::cout << dimes << " dimes" << std::endl;
  }

  if (nickles == 1){
    std::cout << nickles << " nickle" << std::endl;
  } else {
      std::cout << nickles << " nickles" << std::endl;
  }

  if (pennies == 1){
    std::cout << pennies << " penny" << std::endl;
  } else {
      std::cout << pennies << " pennies" << std::endl;
  }

  return 0;
}
