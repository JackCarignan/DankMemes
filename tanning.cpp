#include <iostream>

int main(){

  while(true){
    std::cout << std::endl; // separates each session so output isn't cluttered

    char customers[52] {};    // creates an array to hold all daily customers
    int customerData[26] {};    // creates an array to hold each customer's status
    int maxCustomers {1};    // total number of beds per salon
    int currentCustomers {};    // current number of unavailable beds
    int customersWalked {};   // total number of customers who left before using a bed

    std::cin >> maxCustomers;
    if (maxCustomers == 0){break;} // This works if each line is input by itself
    std::cin >> customers;

    for (int i = 0; customers[i] != 0; i++){
      if (customerData[customers[i] - 'A'] == 1){
        customerData[customers[i] - 'A'] = 0;
        currentCustomers--;
      }
      else if (currentCustomers < maxCustomers && customerData[customers[i] - 'A'] == 0){
        customerData[customers[i] - 'A'] = 1;
        currentCustomers++;
      }
      else if (currentCustomers == maxCustomers && customerData[customers[i] - 'A'] == 0){
        customerData[customers[i] - 'A'] = 2;   
      }
      else if (currentCustomers < maxCustomers && customerData[customers[i] - 'A'] == 2){
        customerData[customers[i] - 'A'] = 1;
        currentCustomers++;
      }
      else if (currentCustomers == maxCustomers && customerData[customers[i] - 'A'] == 2){
        customerData[customers[i] - 'A'] = 0;
        customersWalked++;
      }
    }

    if (customersWalked == 0) {
      std::cout << "All customers tanned successfully.";
    }
    else if (customersWalked == 1) {
      std::cout << "1 customer walked away.";
    }
    else {
      std::cout << customersWalked << " customers walked away.";
    }
  }
  return 0;
}
