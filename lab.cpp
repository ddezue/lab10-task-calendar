/*************************
 * Автор: Бакланова Ляна *
 *************************/
 
#include <iostream>
using namespace std;

int main() {
  int inputYear;
  cout << "Enter year: ";
  cin >> inputYear;
  
  string monthNames[] = {"January", "February", "March", "April", "May", "June", 
                        "July", "August", "September", "October", "November", "December"};
  int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  
  if ((inputYear % 4 == 0 && inputYear % 100 != 0) || (inputYear % 400 == 0)) {
    daysInMonth[1] = 29;
  }
  
  int firstDayOfYear = (inputYear + (inputYear - 1) / 4 - (inputYear - 1) / 100 + (inputYear - 1) / 400) % 7;
  int currentStartDay = (firstDayOfYear + 6) % 7;
  
  for (int currentMonth = 0; currentMonth < 12; ++currentMonth) {
    cout << "\n" << monthNames[currentMonth] << " " << inputYear << "\n";
    cout << "Mo Tu We Th Fr Sa Su\n";
    
    for (int spaceCount = 0; spaceCount < currentStartDay; ++spaceCount) {
      cout << "   ";
    }
    
    for (int currentDay = 1; currentDay <= daysInMonth[currentMonth]; ++currentDay) {
      if (currentDay < 10) cout << " ";
      cout << currentDay << " ";
      
      if ((currentStartDay + currentDay) % 7 == 0) {
        cout << "\n";
      }
    }
    
    currentStartDay = (currentStartDay + daysInMonth[currentMonth]) % 7;
    cout << "\n";
  }
  
  return 0;
}
