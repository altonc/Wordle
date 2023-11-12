#include <iostream>
#include <fstream>
//#include "central.h"
#include "menu.h"
#include "wordle.h"
#include "statistics.h"
#include "reset.h"
//std::string path = "/home/me/workspace/assignments/programming-project-1/exercise-1/keyboard";
using namespace std;

int main(int argc, char* argv[]) {
    
    std::fstream data;
    data.open("statistics.txt", std::ios::in);
    if (data.is_open()){
    }
    else{
    std::fstream file;
        file.open("statistics.txt", std::ios::out);
        file<< 0 << std::endl;
        file<< 0 << std::endl;
        file<< 0 << std::endl;
        file<< 0 << std::endl;
        file<< 0 << std::endl;
        file.close();
    }
    data.close();
    
    // if (file.is_open()){
        
    
        std::fstream startup;
        startup.open("key.txt", std::ios::out);
        if (startup.is_open()){
            startup<<"started";
        }
        startup.close();
        //}
    //}
    //run_game();
    bool go = true;
    int choice = 0;
    
    int counter = 0;
    while (go){

        choice = int(print_menu());
        if (choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5){
            if (choice == 1){
                if (counter == 0){
                    std::fstream game_start;
                    game_start.open("key.txt", std::ios::out);
                    if(game_start.is_open()){
                        game_start<<"game_start";
                    }
                    game_start.close();
                }
                counter++;
                play_wordle();
            }
            else if (choice ==2){
                howtoplay();
            }
            else if (choice == 3){
                add_statistics();
            }
            else if (choice == 4){
                reset();
            }
            else if (choice == 5){
                std::fstream key_stop;
                key_stop.open("key.txt", std::ios::out);
                if (key_stop.is_open()){
                    key_stop<<"stop";
                }
                key_stop.close();
                go = false;
            }
        }
        else{
            std::cout<<"Please enter a choice between 1-5"<<std::endl;
            std::cout<<std::endl;
            break;
        }
        //std::cout<<choice;
        
        
        
        
    }
    
    return 0;
}