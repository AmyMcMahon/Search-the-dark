#include <iostream>
using namespace std;

#include "structures/triey.h"
#include "structures/vectory.h"
#include "tools/inputy.h"
#include "tools/indexy.h"
#include "tools/syntaxy.h"

void printGarth()
{
    cout << "\u001b[32m";
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#*+=--==+*###%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@+-:.         ..:-=+#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%=:..                .-+*#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@+:..                   .:=+*%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#+:..                    ..:-+*%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%+:..                   ..::-=+#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#-....                ...:--=+#%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#=:...                ....::-=*%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*-::..                    ..-=+#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@+-:::.                     .:-=*%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@+-:::.                     .:-=*%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%=-:..                ....:-=+*#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@+----=======--:....::---=+*#%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%*#%@@@@@@@@@@@@@@@@@%#%%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@**@*+%@@%==*#*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*-+=-=+%@@@@@@@@@%++@*+=#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#-+-----+#%%%%#*+-=@@*:-*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%==+-----==+++=---=%=..-*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@+-++-::::--:::--*@-...-*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%=-=+===-::-=++=#=:...:+%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*=--:::--==-:.-: .:..:+%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=--:::....::.:=*%%**#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#=--::::::.    +%%%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*=--::::.....::--=*#%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%*+==---=++++=---=*++%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#*+===+#@@@%%%@@@%%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%#**+*#*--=+*++#%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%#**+----=*%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%#*+=====+**#%%%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%*++=-::..:-=*%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%#*+====+*#%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%##%%%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "@@@@@#.   :%@@@@@@@@@@@@@@@@###%*  -@@@@@@@%-   +#   .#%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@-  =@@@@#. .%  %@@@@@@@@@\n";
    cout << "@@@%   .   #%*:..-#%*-:====   =-   -.-#%%%#     =    +#+:..:*%#::==*%*:..-#%#-:=-.:#%*::--:-#.   :.-#*: :%  %#=::-%@@@@\n";
    cout << "@@@#   +.  #-      +-    .=   =-   :   #%%#     .    +:  :   +=    -:      +=       #       *.      -=   #+##   .  #@@@\n";
    cout << "@@@#   :...#=...   +-   =**   *-   +   ###*          +=. -   -=   -*       -=  .:   #   :   *.  ::  :=   ####   .=#@@@@\n";
    cout << "@@@#   :   #+      =-   ##*   *-   +   ###*   .      +=      -=  .*#   .-..+=  .:   #   :   *.  ::  :=   #####=    #@@@\n";
    cout << "@@@#   -   #.  :   =-   ##*   *=   +   ###*   +   .  +.  +   -=  .##.  --  -=  .:   #       *.  ::  :=   ###*  .=  -@@@\n";
    cout << "@@@@-      #+      +-   ###    .   *   ###*   #  -.  +=      -=  .##*     :#=  .:   #-  :   *.  ::  -=   ####=     %@@@\n";
    cout << "@@@@@%###############################################################################=     +##################%%%@@@@@@\n";
    cout << "@@@@++=====================================================---==================================================+++%@@@\n";
    cout << "@@@@@%%%###################################################################%%%%%%%%###########################%%%@@@@@@\n";
    cout << "@@@%.        .+#####*    -####=          +#*    =##*  -##:         .*#    -%%%%%%%%%#.   :######:       **         %@@@\n";
    cout << "@@@%           +####-     ####=           +*    *##. :###:           #    :%%@@@@@%%#     +####         +#         *@@@\n";
    cout << "@@@%    +##    :###*      -###+    ###    =*    *#. :####:    ##+    #    -%@@@@@@%%:     :###*    *######    +%%@@@@@@\n";
    cout << "@@@%    +##    :###: -     ###+    ###    =*    *.  =####:    ##+    #    -%%@@@@%%#  :    *##*    *######    +%%@@@@@@\n";
    cout << "@@@%    +##    :##*  *-    +##+           =*         *###:    ##=    #    -%%%%%%%%. -*    -##*    *######         %@@@\n";
    cout << "@@@%    +##    :##: :**    .##+           **         :###:          .#    -%%%%%%%#  **.    *#*    *######         %@@@\n";
    cout << "@@@%    +##    :#*          *#+    #-    *#*     -    +##:    .....-##    -%%%%%%%          +#*    *######    +%@@@@@@@\n";
    cout << "@@@@    +##    :#-  ----    :#=    ##    -#*    *#     *#:    %%%%%%%%    -%%%%%%*  ---:     #*    *#%%%%#    +@@@@@@@@\n";
    cout << "@@@@    .-:    -*  *%%%%-    *+    ##-    **    *#+    -#:    %@@@@@@@     --=-+%  *%%%%+    *#     ---:+%    .====*@@@\n";
    cout << "@@@@          .#: :%@@@@#    --    #%#    :+    +%#-    *.    @@@@@@@@         =-  @@@@@#     %+        +#         +@@@\n";
    cout << "@@@@@@@%%%%%%@@@%%@@@@@@@%%%%%%%%%%@@@%%%%%%%%%%%@@@%%%%%%%%@@@@@@@@@@@@@@%%%%%@@%@@@@@@@%%%%%@@@%%%%%%%@@%%%%%@@@@@@@@\n";
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "\u001b[37m";
};

// Driver Code
int main()
{
    printGarth();
    cout << "\nWelcome to Search the Dark\n";
    cout << "The one stop shop to find all Garth Marenghi's Books\n";
    cout << "Please enter the name of the book you are looking for: \n";
    // make search index
    // make trie
    string searchStr = "";

    Triey bookTriey = Triey();
    Indexy idx;
    Inputy inputy = Inputy();
    Syntaxy syntaxy = Syntaxy();

    Vectory<trieData> words_index;

    while (searchStr != "exit")
    {
        searchStr = "";

        getline(cin, searchStr);

        if (searchStr == "exit")
        {
            break;
        }

        Vectory<string> words = inputy.break_input(searchStr);
        cout << "Words: " << words.size() << endl;

        if (words.size() == 1)
        {
            // populates trie with words from file with starting letter
            words_index = idx.readFileTrie(searchStr[0]);
            bookTriey.populateTriey(words_index);
            Vectory<string> results = bookTriey.search(searchStr);

            string search_term = inputy.autocomplete(results);

            cout << "You are searching for: " << search_term << endl;

            Vectory<Result> books = idx.getBooks(search_term);
            string bookPath = inputy.chooseBook(books);
            cout << "You have selected: " << bookPath << endl;
        }
        else if (words.size() == 2)
        {
            if (words[0] == "NOT")
            {
                words_index = idx.readFileTrie(words[1][0]);
                bookTriey.populateTriey(words_index);

                bool results_not = bookTriey.lookForWord(words[1]);
                if (results_not)
                {
                    cout << "Word found\n";
                    // run search for NOT
                }
                else
                {
                    cout << "Word not found\n";
                }
            }
            else
            {
                cout << "Invalid search term\n";
                break;
            }
        }
        else if (words.size() == 3)
        {
            if (words[1] == "AND")
            {
                words_index = idx.readFileTrie(words[0][0]);
                bookTriey.populateTriey(words_index);
                bool results_and1 = bookTriey.lookForWord(words[0]);

                words_index = idx.readFileTrie(words[2][0]);
                bookTriey.populateTriey(words_index);
                bool results_and2 = bookTriey.lookForWord(words[2]);

                if (results_and1 && results_and2)
                {
                    cout << "Both words found\n";

                    Vectory<Result> word1 = idx.getBooks(words[0]);
                    Vectory<Result> word2 = idx.getBooks(words[2]);
                    Vectory<Result> books = syntaxy.and_search(word1, word2);

                    string bookPath = inputy.chooseBook(books);
                }
                else
                {
                    cout << "One or both words not found\n";
                }
            }
            else if (words[1] == "OR")
            {
                words_index = idx.readFileTrie(words[0][0]);
                bookTriey.populateTriey(words_index);
                bool results_or1 = bookTriey.lookForWord(words[0]);

                words_index = idx.readFileTrie(words[2][0]);
                bookTriey.populateTriey(words_index);
                bool results_or2 = bookTriey.lookForWord(words[2]);

                if (results_or1 && results_or2)
                {
                    cout << "Both words found\n";
                    Vectory<Result> word1 = idx.getBooks(words[0]);
                    Vectory<Result> word2 = idx.getBooks(words[2]);

                    for (int i = 0; i < word1.size(); i++)
                    {
                        cout << word1[i].title << endl;
                    }

                    for (int i = 0; i < word2.size(); i++)
                    {
                        cout << word2[i].title << endl;
                    }

                    Vectory<Result> books = syntaxy.or_search(word1, word2);

                    string bookPath = inputy.chooseBook(books);
                }
                else
                {
                    cout << words[0] << ", " << results_or1 << ", " << words[2] << results_or2 << endl;
                    cout << "One or both words not found\n";
                }
            }
            else
            {
                cout << "Invalid search term\n";
                break;
            }
        }
        else
        {
            cout << "Invalid search term" << endl;
            cout << "Format: \n word1 \n NOT word1 \n word1 OR/AND word2" << endl;

            break;
        }

        // vector<string> results = bookTriey.search(searchStr);
        // string books[10] = trie.search(searchStr);
        // string search_term = autocomplete(results);
        // cout << "You are searching for: " << search_term << endl;
        // search for book
        cout << "Give us another book (or use exit to quit)\n";
        cin.clear();
        cin.ignore(INT_MAX, '\n');
    }
    return 0;
}