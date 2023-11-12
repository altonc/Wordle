#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <fstream>

int print_menu(){
    
    
    system("clear");
    std::string menu = "=========================\n    WELCOME TO WORDLE   \n=========================\n\n1. Play Wordle\n2. How to Play\n3. Statistics\n4. Reset Statistics\n5. Exit\n\n\nSelect an option:";

    std::cout << menu << std::endl;
    int choice;
    std::cin>>choice;
    

    return choice;

}

#endif