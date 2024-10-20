#include <iostream>
#include <string>
#include "structures/vectory.h"
using namespace std;

class Inputy {
public:
    Inputy(){};
    
    string autocomplete(Vectory<string> words){
        cout << "Is this what you meant? \n";

        for (int i = 0; i < words.size(); i++) {
            cout << i+1 << ". " << words[i] << endl;
        }

        int bookNum;
        cin >> bookNum;

        while (bookNum < 1 || bookNum >= words.size()+1) {
            cout << "Invalid book number\n";
            cin >> bookNum;
        }
        cout << "You have selected: " << words[bookNum-1] << endl;
        return words[bookNum-1];
    }

    Vectory<string> break_input(string input){
        Vectory<string> words;
        string word = "";
        cout << input;
        for (int i = 0; i < input.size(); i++) {
            if (input[i] == ' ') {
                words.push_back(word);
                word = "";
            } else {
                word += input[i];
            }
        }
        words.push_back(word);
        return words;
    }


};