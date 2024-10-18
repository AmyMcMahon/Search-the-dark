#include <iostream>
#include <string>
using namespace std;

class Nodey{
public:
    Nodey* childrens[26];
    bool endofWord;
};

class Triey{
    public:
    Nodey* root;

    Triey(){
        root = new Nodey();
    }

    void populateTriey(string books_temp[10]){
        Nodey* current = root;

        for(int j = 0; j < 10; j++){
            string word = books_temp[j];
            for(int i = 0; i < word.size(); i++){
                int index = word[i] - 'a';
                if(current->childrens[index] == NULL){
                    current->childrens[index] = new Nodey();
                }
                current = current->childrens[index];
            }
            current->endofWord = true;
        }

    }

    void print(Nodey* node, string prefix) const
    {
        for (int i = 0; i < 26; i++) {
            if (node->childrens[i]) {
                print(node->childrens[i],
                      prefix + char('a' + i));
            }
        }
    }

    void print() const { print(root, ""); }

};