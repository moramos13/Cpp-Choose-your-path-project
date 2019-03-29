#include <stdio.h>
#include <iostream>
#include "Paths.h"

int key1;
int key2;
int key3;
std::string name; 

void beginning() //The beginning path should start the game and lead to the seperate files with their own paths but lead back to home hopefully after finding the key.
{
    	int path;
    	std::cout << "\nHere are your paths to find the keys, what will you choose, where could they be?\n\n";
	std::cout << "1) Cave \n"; // Path for Myles
	std::cout << "2) Fabian path \n"; // Path Fabian
	std::cout << "3) Marcos path \n"; // Path for Marcos
	std::cin >> path;
			
	if (path == 1) {
		std::cout << "Entered Cave\n";
				
	} else if (path == 2) {
		std::cout << "Entered Fabian path\n";
				
	} else if (path == 3) {
		std::cout << "Entered Marcos path\n";
				
	} else {
		std::cin.clear();
      		std::cin.ignore();
      		std::cout << "Invalid try again.\n";
		beginning();
	}		
}

//Checks the value of the keys, if the three are right return true
bool checkKeys()
{
	std::cout << "Key 1: \n";
	std::cin >> key1;
	std::cout << "Key 2: \n";
	std::cin >> key2;
	std::cout << "Key 3: \n";
	std::cin >> key3;

	if (key1 == 3016 && key2 == 6271 && key3 == 4001) //If all the keys are found run the End game
	{
      		std::cout << "You have opened the chest!\n";
      		std::cout << "Inside there is another key with a letter.\n";
		std::cout << "=========================\n";
		std::cout << "It reads...\n";
		std::cout << "Congratulations! You have completed the Quest and opened the chest.\n";
		std::cout << "You are truly magnificent!\n";
		std::cout << "Inside this chest is a key, a key to a kingdom that belongs to you\n";
		std::cout << "All hail " + name + " the Magnificent you are truly great\n";
		std::cout << "End of letter\n";
		std::cout << "=========================\n";
		std::cout << "Here is your Kingdom rule with great Authority!\n\n\n\n";
		std::cout << ""; //Temporary will put a kingdom of characters
		return true;
	} else { //If the correct keys weren't found they need to keep looking
		std::cout << "\nThats not it keep looking.\n";
      		return false;
	}
}

int home() //Home function. Every path that ends should lead here
{
	std::cout << "\n\nYou are Home.\n";
	std::cout << "=======================\n";
    	std::cout << "Do you have the 3 keys? [y/n]\n";
	std::cout << "=======================\n";

	std::string ans;
	std::cin >> ans;

	//If already have the keys proceed to check else go to path choise
	if (ans == "y"){
		bool open = checkKeys();
		//If inserted keys are correct the game ends otherwise go to path choise
		if (open){
			return 0;
		}
		else{
			return -1;
		}
	}
	else if (ans == "n"){
		beginning();
	}
	else{
		std::cout << "Bad answer. Try again\n";
		return -1;
	}
  }

//Only ask the name
void get_name(){
	std::cout << "\n\nWhat is your name? ";
	std::cin >> name;
	
	if(name == ""){
		name = "User1";
	}
}

//The main function plays everything out
int main()
{
	get_name();
 	std::cout << "Hello, " + name + "\n";
  	std::cout << "This is a choose your own adventure game.\n";
  	std::cout << "If you want to win, you must find all three keys and come back here to the beginning\n";
 	std::cout << "Once you have all the keys you can unlock this chest.\n";
  	std::cout << "Good luck and be safe!\n\n";

	//infinity loop until the player wins or type "exit"
	while (true){
		std::cout << "\nType a key to continue, EXIT to close. ";
		std::string close;
		std::cin >> close;
		std::cout << "\n\n";
		if(close == "exit"){
			break;
		}
		int open = home();
			if(open == 0){
			break;
			}		
	}
  
	return 0;
}
