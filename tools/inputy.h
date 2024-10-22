#include <iostream>
#include <string>
#include "../structures/vectory.h"
#include "indexy.h"

using namespace std;

class Inputy {
public:
    Inputy();
    string autocomplete(Vectory<string> &words);
    Vectory<string> break_input(string input);
    string chooseBook(Vectory<Result> books);
};