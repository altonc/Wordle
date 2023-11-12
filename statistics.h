#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "wordle.h"


int add_statistics(){
    std::vector<std::string> info;
    std::fstream file;
    std::vector<std::string> wstats;
    file.open("statistics.txt", std::ios::in);
    if(file.is_open()){
        std::string num;
        while(file>>num){
            info.push_back(num);
        }
    }
    std::fstream wdata;
    wdata.open("word_stats.txt", std::ios::in);
    if(wdata.is_open()){
        std::string num;
        while(wdata>>num){
            wstats.push_back(num);
        }
    }
    float times_played = stoi(info[0]);
    float attempts = stoi(info[1]);
    int streak = stoi(info[2]);
    int win_count = stoi(info[3]);
    int longest_streak = stoi(info[4]);
    float win_per = 0;
    float avg_attempts = 0;
if (win_count != 0 || times_played != 0){
    win_per = (win_count/times_played)*100;
}
if (attempts != 0 || times_played != 0){
    avg_attempts = attempts/times_played;
}

    
     //std::cout<< win_per;
 
std::cout<<"=========================="<<std::endl;
std::cout<<"    STATISTICS SUMMARY    "<<std::endl;
std::cout<<"=========================="<<std::endl; //26
std::cout<< "Times Played:" <<std::setw(13) << std::setprecision(3) << times_played <<std::endl;
std::cout<< "Average Attempts:" << std::setw(9) << std::setprecision(3) << avg_attempts <<std::endl;
std::cout<< "Win Percentage:" << std::setw(10) << std::setprecision(3) <<win_per<< "%" <<std::endl;
std::cout<< "Current Streak:" << std::setw(11) << std::setprecision(3) <<streak <<std::endl;
std::cout<< "Longest Streak:" << std::setw(11) << std::setprecision(3) << longest_streak <<std::endl;
std::cout<<std::endl;
std::string exit = " ";

std::cout<<"--------------------------"<<std::endl;
std::cout<<"WORD     ATTEMPTS      WIN"<<std::endl;
std::cout<<"--------------------------"<<std::endl; //26
for (int i = 0; i < wstats.size(); i++){
    if (i%3 == 0){
        for (int x = 0; x < wstats[i].size(); x++){
            //char tmp;
            //tmp = wstats[i][x];
            std::cout<<char(toupper(wstats[i][x]));
        }
        // std::cout<<(wstats[i])<<" ";
        std::cout<<std::setw(12);  // 12 +5
    }
    else if (i%3 == 1){
        std::cout<<wstats[i]<<std::right;
    }
    else if (i%3 == 2){
        if (stoi(wstats[i]) == 1){
            std::cout<<std::setw(9);
            std::cout<<"Yes"<<std::right<<std::endl;
        }
        else if (stoi(wstats[i]) == 0){
            std::cout<<std::setw(9);
            std::cout<<"No"<<std::right<<std::endl;
        }
        //std::cout<<wstats[i]<<std::endl;
    }
    //std::cout<<wstats[i]<<i<<std::endl;
    //std::cout<<std::endl;
}
std::cout<<"\n";
     do{
         std::cout<<"Press [enter] to continue"<<std::endl;
    std::cout<<"\n";
         std::cin.ignore();
     } while (std::cin.get() != '\n');
     
    return 0;
}