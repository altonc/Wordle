#ifndef WORDLE_H
#define WORDLE_H
#define GREEN "\033[32m"
#define RESET "\033[0m"
#define GRAY "\033[090m"
#define WHITE "\033[37m"
#define YELLOW "\033[33m"
#define BOLD "\033[1m"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "menu.h"


void print_box(std::vector <char> color, std::string display, int size){
    int word_size = size;
    for (int x = 0; x < word_size; x++){
        if (color[x] == 'g'){
            std::cout<<GREEN<<" --- "<<RESET;
        }
        
        else if (color[x] == 'r'){
            std::cout<<GRAY<<" --- "<<RESET;
        }
        else if (color[x] == 'y'){
            std::cout<<YELLOW<<" --- "<<RESET;
        }
        else if (color[x] == 'w'){
            std::cout<<WHITE<<" --- "<<RESET;
        }
    }
    std::cout<<"\n";
    for (int x = 0; x < word_size; x++){
        if (color[x] == 'g'){
            std::cout<<GREEN<<"| "<< display[x] <<GREEN<<" |"<<RESET;
        }
        else if (color[x] == 'y'){
            std::cout<<YELLOW<<"| "<< display[x] <<YELLOW<<" |"<<RESET;
        }
        else if (color[x] == 'r'){
            std::cout<<GRAY<<"| "<< display[x] <<GRAY<<" |"<<RESET;
        }
        else if (color[x] == 'w'){
            std::cout<<WHITE<<"| "<< display[x] <<WHITE<<" |"<<RESET;
        }
    }      
    std::cout<<"\n";
    for (int x = 0; x < word_size; x++){
        if (color[x] == 'g'){
            std::cout<<GREEN<<" --- "<<RESET;
        }
        else if (color[x] == 'y'){
            std::cout<<YELLOW<<" --- "<<RESET;
        }
        else if (color[x] == 'r'){
            std::cout<<GRAY<<" --- "<<RESET;
        }
        else if (color[x] == 'w'){
            std::cout<<WHITE<<" --- "<<RESET;
        }
        
    }
}


std::vector<char> testing(std::string word_, std::string guess_, int size){
    
    
    int word_size = size;
    std::vector<std::string> arr(word_size);
    std::vector<std::string> nocolor(word_size);
    std::vector<char> green;
    std::vector<char> colors(word_size);
    std::vector<char> input(word_size);
    std::vector<char> guessed(word_size);
    int b = 0;
    std::stringstream box;
    std::string s;

    for (int lo = 0; lo < word_size; lo++){
            guessed[lo] = tolower(guess_[lo]);
            
        }
    for (int ip = 0; ip < word_size; ip++){
        input[ip] = word_[ip];
    }
    for (int x = 0; x < word_size; x++){        //goes through each "word" letter
        if (input[x] == guessed[b]){
            box.str("");
            box<<GREEN<<guess_[b]<<RESET;
            colors[x] = 'g';
            s = "";
            s = box.str();
            arr[x] = s;
            nocolor[x] = guess_[b];
            
            input[x] = '_';
            guessed[x] = '/';
            
            b++;
        }
        else{
            box.str("");
            box<<guess_[b]<<RESET;
            colors[x] = 'r';
            s = "";
            s = box.str();
            
            arr[x] = s;
            nocolor[x] = guess_[b];
            b++;
        } 
    }
    
    b = 0;
    
    for (int k = 0; k < word_size; k++){
        for(int gr = 0; gr < guessed.size(); gr++){
        
        if(input[k] == guessed[gr]){
            
            guessed[gr] = ',';
            input[k] = '%';
            colors[gr] = 'y';
            
        }
    
    }
        b++;
            
    }
    return colors;
  
}



int play_wordle(int size, std::string infile, std::string alwfile){
    
    int word_size = (size);
    std::string wordfile = infile;
    std::string alw = alwfile;
    system("clear");
    std::ifstream file;
    std::ifstream filecount;
    std::string word = "";
    std::string guess = "";
    //std::cout<<size<<wordlist<<alw;
    std::vector<std::string> arr(word_size);
    std::vector<std::string> nocolor(word_size);
    std::vector<char> green;
    std::vector<char> colors(word_size);
    std::vector<char> input(word_size);
    std::vector<char> guessed(word_size);
    std::vector<char> yellow;
    std::vector<char> gray;
    std::vector<char> seen;
    bool stop = false;
    
    int line_count = 0;
    int random_num = 0;
    
    file.open(wordfile, std::ios::in);
    if (file.is_open()){
        filecount.open(wordfile, std::ios::in);
        int wordcount = 0;
        std::string tmp;
        while(!filecount.eof()){
            getline(filecount, tmp);
            wordcount++;
        }
        filecount.close();
        std::string possible_word;
        srand(time(NULL));                        //random seed
        random_num = rand()%wordcount;                 //random number mod max line count to get random word
        while(getline(file, possible_word)){

            if (line_count == random_num){
                word = possible_word;
                //std::cout<<word;
                break;
            }
            line_count++;
        }
        file.close();
    }
    std::string tmp = "";
    std::string valid_guess;
    std::string no_yellow;
    int i = 0;
    for (int ip = 0; ip < word_size; ip++){
        input[ip] = word[ip];
    }
    
    while(i < 6){
        
        bool go = false;
        bool in_words = false;
        bool next = false;
        if (stop == false){
            file.open(alw, std::ios::in);
            std::cout << "Enter guess: ";
            std::cin >> guess;
            std::cout<<"\033[1A";
            std::cout<<"\033[2K";
            std::cout<<"\033[0G";
        }

        for (int lo = 0; lo < word_size; lo++){
            guess[lo] = tolower(guess[lo]);
            //std::cout<<guess[lo];
        }
        std::fstream wordlist;
        std::string accepted;
        if (file.is_open()){
            //std::cout<<guess<<std::endl;
        while(getline(file, valid_guess)){
            if (valid_guess == guess){
                go = true;
                i++;          
                break;
            }
            else{
                go = false;
                next = true;
            }
        }
        file.close();
        if (next == true){
        wordlist.open(wordfile, std::ios::in);
        if(wordlist.is_open()){
            while(getline(wordlist, accepted)){
                if (accepted == guess){
                    go = true;
                    i++;
                    break;
                }
            }
        }
        wordlist.close();
        }
        for (int g = 0; g < word_size; g++){
            guessed[g] = guess[g];
        }
        bool green = false;
        if (go == true){
            int b = 0;
            std::stringstream box;
            std::string s;
            for (int x = 0; x < word_size; x++){        //goes through each "word" letter
                if (input[x] == guessed[b]){
                    box.str("");
                    box<<GREEN<<guess[b]<<RESET;
                    colors[x] = 'g';
                    s = "";
                    s = box.str();
                    arr[x] = s;
                    nocolor[x] = guess[b];
                   
                    input[x] = '_';
                    guessed[x] = '/';
                    
                    b++;
                    green = true;
                }
                else{
                    box.str("");
                    box<<guess[b]<<RESET;
                    colors[x] = 'r';
                    s = "";
                    s = box.str();
                  
                    arr[x] = s;
                    nocolor[x] = guess[b];
                    b++;
                } 
            }
            
            b = 0;
            
            for (int k = 0; k < word_size; k++){

                for(int gr = 0; gr < word_size; gr++){
                   //std::cout<<input[k]<<guessed[gr]<<std::endl;
                if(input[k] == guessed[gr]){
                  
                    guessed[gr] = ',';
                    input[k] = '%';
                    colors[gr] = 'y';
                   
                }
                }
            }
            //std::cout<<std::endl;
            for (int res1 = 0; res1 < word_size; res1++){
                input[res1] = word[res1];
            }
                b++;
                    
            }

            }     

            if(go == true){
            for (int x = 0; x < word_size; x++){
                if (colors[x] == 'g'){
                    std::cout<<GREEN<<" --- "<<RESET;
                }
                else if (colors[x] == 'r'){
                    std::cout<<GRAY<<" --- "<<RESET;
                }
                else if (colors[x] == 'y'){
                    std::cout<<YELLOW<<" --- "<<RESET;
                }
    
            }
            std::cout<<"\n";
            for (int x = 0; x < word_size; x++){
                if (colors[x] == 'g'){
                    std::cout<<GREEN<<"| "<< arr[x] <<GREEN<<" |"<<RESET;
                }
                else if (colors[x] == 'y'){
                    std::cout<<YELLOW<<"| "<< arr[x] <<YELLOW<<" |"<<RESET;
                }
                else if (colors[x] == 'r'){
                    std::cout<<GRAY<<"| "<< arr[x] <<GRAY<<" |"<<RESET;
                }
        
            }      
            std::cout<<"\n";
            for (int x = 0; x < word_size; x++){
                if (colors[x] == 'g'){
                    std::cout<<GREEN<<" --- "<<RESET;
                }
                else if (colors[x] == 'y'){
                    std::cout<<YELLOW<<" --- "<<RESET;
                }
                else if (colors[x] == 'r'){
                    std::cout<<GRAY<<" --- "<<RESET;
                }
        
            }
            std::string upper = "";
            for (int up = 0; up < word_size; up++){
                upper += toupper(input[up]);
            }
            std::fstream keyboard;
            keyboard.open("keyboard.txt", std::ios::app);
            if (keyboard.is_open()){
                for (int col = 0; col < word_size; col++){
                    keyboard<<nocolor[col];
                    keyboard<<colors[col];
                }
            }
            keyboard.close();
            
            std::fstream key_start;
            key_start.open("key.txt", std::ios::out);
            if (key_start.is_open()){
                key_start<<"go";
            }
            key_start.close();

            std::cout<<"\n";
            
            std::vector<std::string> temp; 
            file.open("statistics.txt", std::ios::out);
            if (file.is_open()){
                std::string num;
                while(file >> num){
                    temp.push_back(num);
                }
            }
            file.close();

            std::cout<<std::endl;
            int times_played = stoi(temp[0]);
            int attempts = stoi(temp[1]);
            int streak = stoi(temp[2]);
            int win_count = stoi(temp[3]);
            int longest_streak = stoi(temp[4]);
            bool win;

            //if (go == true){
            std::fstream file;

            int win_counter = 0;
            for (int win = 0; win < word_size; win++){
                
                if (colors[win] == 'g'){
                    //std::cout<<"here";
                    win_counter++;
                    //std::cout<<win_counter;
                
                }
                
            }
            if(win_counter == word_size){

                stop = true;
                win = true;
                times_played++;
                win_count++;
                streak++;
                attempts = attempts + i;
                if (streak > longest_streak){
                    longest_streak = streak;
                }
                file.open("statistics.txt", std::ios::out);
                if (file.is_open()){
                    file<< times_played << std::endl;
                    file<< attempts << std::endl;
                    file<< streak << std::endl;
                    file<< win_count << std::endl;
                    file<< longest_streak << std::endl;
                }
                file.close();

                file.open("word_stats.txt", std::ios::app);
                if (file.is_open()){
                    file<< word << std::endl;
                    file<< i << std::endl;
                    file<< win << std::endl;
                    
                }
                file.close();

                std::fstream closing;
                closing.open("keyboard.txt", std::ios::out);
                if(closing.is_open()){
                    closing<<"";
                }
                closing.close();

                std::string exit = " ";
                do{
                    std::cout<<"Splendid! Press [enter] to continue"<<std::endl;
                    std::cout<<"\n";
                    std::cin.ignore();
                } while (std::cin.get() != '\n');
                stop = false;
                std::fstream key_done;
                key_done.open("key.txt", std::ios::out);
                if (key_done.is_open()){
                    key_done<<"done";
                }
                key_done.close();
                
                break;
                

            }
            
            if (i == 6){       //LOSS
                if (streak > longest_streak){
                    longest_streak = streak;
                }
                win = false;
                times_played++;
                attempts = attempts + i;
                streak = 0;
                //std::cout<<"done"<<std::endl;
                file.open("statistics.txt", std::ios::out);
                if (file.is_open()){
                    file<< times_played << std::endl;
                    file<< attempts << std::endl;
                    file<< streak << std::endl;
                    file<< win_count << std::endl;
                    file<< longest_streak << std::endl;
                }
                file.close();
                file.open("word_stats.txt", std::ios::app);
                if (file.is_open()){
                    file<< word << std::endl;
                    file<< i << std::endl;
                    file<< win << std::endl;
                    
                }
                file.close();
            std::fstream closing;
            closing.open("keyboard.txt", std::ios::out);
            if(closing.is_open()){
                closing<<"";
            }
            closing.close();

                std::string exit = " ";
                do{
                    
                    std::cout<<"The word was: "<< upper<<"\n\n";
                    std::cout<<"Better luck next time!\n\nPress [enter] to continue";
                    std::cout<<"\n";
                    std::cin.ignore();
                } while (std::cin.get() != '\n');
                stop = false;
                std::fstream key_done;
                key_done.open("key.txt", std::ios::out);
                if (key_done.is_open()){
                    key_done<<"done";
                }
                key_done.close();
                
            }
            }

        } 
        return 0;
}
    
int howtoplay(){
    system("clear");
    std::cout<<"============================================="<<std::endl;
    std::cout<<"                 HOW TO PLAY                 "<<std::endl;
    std::cout<<"============================================="<<std::endl;
    std::cout<<"Guess the Wordle in 6 tries.\n\n\n";
    std::cout<<"HOW TO PLAY:"<<std::endl;
    std::cout<<"- Each guess must be a valid word of the length the user inputted."<<std::endl;
    std::cout<<"- The color of the tiles will change to show\n  you how close your guess was to the word.\n\n";
    std::vector <char> first = {'g','w','w','w','w'};
    std::string first_w = "WEARY";
    print_box(first, first_w, 5);
    std::cout<<std::endl;
    std::cout<<BOLD<<GREEN<<"W "<<RESET<<"is in the word and in the correct spot.\n";
    std::cout<<std::endl;
    std::vector <char> second = {'w','y','w','w','w'};
    std::string second_w = "PILLS";
    print_box(second, second_w, 5);
    std::cout<<std::endl;
    std::cout<<BOLD<<YELLOW<<"I "<<RESET<<"is in the word but in the wrong spot.\n";
    std::cout<<std::endl;
    std::vector <char> third = {'w','w','w','r','w'};
    std::string third_w = "VAGUE";
    print_box(third, third_w, 5);
    std::cout<<std::endl;
    std::cout<<BOLD<<GRAY<<"U "<<RESET<<"is not in the word in any spot.\n";
    std::cout<<"\n\n";
    
    std::string exit = " ";
    do{
        std::cout<<"Press [enter] to continue"<<std::endl;
        std::cout<<std::endl;
        std::cin.ignore();
    } while (std::cin.get() != '\n');
    std::cout<<std::endl;
    return 0;
}

#endif