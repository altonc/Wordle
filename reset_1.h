#ifndef RESET_H
#define RESET_H

#include <iostream>
#include <fstream>

int reset(){
    system("clear");
    //std::cout<<"Reset Statistics!"<<std::endl;
    std::fstream file;
    file.open("statistics.txt", std::ios::out);
    file<< 0 << std::endl;
    file<< 0 << std::endl;
    file<< 0 << std::endl;
    file<< 0 << std::endl;
    file<< 0 << std::endl;
    file.close();

    std::fstream word_stat;
    word_stat.open("word_stats.txt", std::ios::out);
    
    word_stat.close();

    // std::cout<<"\n";
    //  do{
    //      std::cout<<"Press [enter] to continue"<<std::endl;
    // std::cout<<"\n";
    //      std::cin.ignore();
    //  } while (std::cin.get() != '\n');




    
    return 0;
}

#endif