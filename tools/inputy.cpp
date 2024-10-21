#include "inputy.h"

Inputy::Inputy(){};
    
string Inputy::autocomplete(Vectory<string> &words){
    cout << "Is this what you meant? \n";

    for (int i = 0; i < words.size(); i++) {
        cout << i+1 << ". " << words[i] << endl;
    }

    int wordNum;
    cin >> wordNum;
    while (wordNum < 1 || wordNum >= words.size()+1) {
        cout << "Invalid word number\n";
        cin >> wordNum;
    }
    cout << "You have selected: " << words[wordNum-1] << endl;
    return words[wordNum-1];
}
Vectory<string> Inputy::break_input(string input){
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

string Inputy::chooseBook(Vectory<Result> books){
    cout << "Choose a book: \n";
    cout << "Results: " << books.size() << endl;
    cout << "Type 0 to see more results\n";
    for (int i = 0; i < 10; i++) {
        cout << i+1 << ". " << books[i].title << " ( relavance: " << books[i].relevance << ")\n";
    }

    int bookNum;
    cin >> bookNum;

    if (bookNum == 0 and books.size() > 10) {
        for (int i = 10; i < books.size(); i++) {
            cout << i+1 << ". " << books[i].title << " ( relavance: " << books[i].relevance << ")\n";
        }
    }

    while (bookNum < 1 || bookNum >= books.size()+1) {
        cout << "Invalid book number\n";
        cin >> bookNum;
    }

    cout << "You have selected: " << books[bookNum-1].title << endl;
    return books[bookNum-1].filePath;
}
