#include <iostream> 
using namespace std; 

#include "structures/triey.h"
#include "structures/vectory.h"
#include "tools/inputy.h"
#include "tools/indexy.h"

void printGarth() {
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
};

// Driver Code 
int main() 
{ 
    //printGarth();      put garth back in after testing
    cout << "\nWelcome to Search the Dark\n";
    cout << "The one stop shop to find all Garth Marenghi's Books\n";
    cout << "Please enter the name of the book you are looking for: \n";
    //make search index
    //make trie
    string searchStr = "";
    string books_temp[10] = {"theoeuvre", "blackfang", "catacombsofthedamned", "afterbirth", "arachnobilia", "thediaryofannefrankenstein"};

    Triey bookTriey = Triey();
    bookTriey.populateTriey(books_temp);
    bookTriey.print();

    Indexy idx;
    Inputy inputy = Inputy();

    while (searchStr != "exit") {

        getline(cin, searchStr);
        if (searchStr == "exit"){
            break;
        }
        Vectory<string> words = inputy.break_input(searchStr);
 
        cout << "Words: " << words.size() << endl;

        if (words.size() == 1) {
            Vectory<string> results = bookTriey.search(searchStr);
            string search_term = inputy.autocomplete(results);
        }else if (words.size() == 2) {
            if (words[0] == "NOT") {
                bool results_not = bookTriey.lookForWord(words[0]);
                if (results_not) {
                    cout << "Word found\n";
                    //run search for NOT
                }else{
                    cout << "Word not found\n";
                }
            }else{
                cout << "Invalid search term\n";
                break;
            }
        }else if (words.size() == 3) {
            if (words[1] == "AND") {
                bool results_and1 = bookTriey.lookForWord(words[0]);
                bool results_and2 = bookTriey.lookForWord(words[2]);
                if (results_and1 && results_and2) {
                    cout << "Both words found\n";
                    //run search for AND
                }else{
                    cout << "One or both words not found\n";
                }
            }else if (words[1] == "OR") {
                bool results_or1 = bookTriey.lookForWord(words[0]);
                bool results_or2 = bookTriey.lookForWord(words[2]);
                if (results_or1 && results_or2) {
                    cout << "Both words found\n";
                    //run search for or
                }else{
                    cout << "One or both words not found\n";
                }
            }else{
                cout << "Invalid search term\n";
                break;
            }
        }else{
            cout << "Invalid search term" << endl;
            cout << "Format: word1 \n NOT word1 \n word1 OR/AND word2" << endl;
            
            break;
        }

        //vector<string> results = bookTriey.search(searchStr);
        //string books[10] = trie.search(searchStr);
        //string search_term = autocomplete(results);
        //cout << "You are searching for: " << search_term << endl;
        //search for book
        cout << "Please select the book you are looking for: \n";

     
        cout << "Give us another book\n";
    }
    return 0; 
}