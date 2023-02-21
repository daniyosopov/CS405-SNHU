// BufferOverflow.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iomanip>
#include <iostream>
#include <cstring>

int main()
{
  std::cout << "Buffer Overflow Example" << std::endl;

  // TODO: The user can type more than 20 characters and overflow the buffer, resulting in account_number being replaced -
  //  even though it is a constant and the compiler buffer overflow checks are on.
  //  You need to modify this method to prevent buffer overflow without changing the account_order
  //  varaible, and its position in the declaration. It must always be directly before the variable used for input.

  const std::string account_number = "CharlieBrown42";
  char user_input[20];
  char buffer[20];
  std::cout << "Enter a value: ";
  std::cin >> buffer;
  for (int i = 0; i <= strlen(buffer); i++)
  {
	  user_input[i] = buffer[i];
	  if (i == 19)
		  break;

  }

  while(strncmp(user_input, buffer, 20) != 0 || strlen(buffer)>20 )
  {
	  std::cout << "Buffer Overflow Detected" << std::endl;
	  std::cin.clear();
	  std::cout << "Enter a value: ";
	  std::cin >> buffer;
	  for (int i = 0; i <= 19; i++)
	  {
		  user_input[i] = buffer[i];
		  if (i == 19)
			  break;

	  }
  }
	  std::cout << "You entered: " << buffer << std::endl;
	  std::cout << "Account Number = " << account_number << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
