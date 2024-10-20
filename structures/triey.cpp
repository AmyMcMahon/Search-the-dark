#include "triey.h"

Triey::Triey(){
    root = new Nodey();
}

void Triey::populateTriey(Vectory<trieData> words){
    for(int j = 0; j < words.size(); j++){
        string word = words[j].word;
        Nodey* current = root;
        for(int i = 0; i < word.size(); i++){
            int index = word[i] - 'a';
            if(current->childrens[index] == NULL){
                current->childrens[index] = new Nodey();
            }
            current = current->childrens[index];
        }
        current->endofWord = true;
        //add implementation for popularity
        current->popularity = 0;
    }
}

//needs to return top 5 words that match input
//pointer to array
Vectory<string> Triey::search(string input){
    Vectory<string> top_matches;
    Nodey* current = root;
    for (char c:input){
        int index = c - 'a';
        if (!current->childrens[index]) {
            top_matches.push_back("No matches found");
            return top_matches;
        }
        current = current->childrens[index];
    }
    //if (current->endofWord && current->childrens == nullptr){
    //    string only_word = "word";
    //    return only_word;
    //}
    Vectory<pair<string, int> > all_matches;
    lookForWords(current, input, all_matches);
    top_matches = rank(all_matches);
    //traverse rest of trie for works?
    //rank based on popular
    return top_matches;
}

Vectory<string> Triey::rank(Vectory<pair<string, int> >& all_matches) {
    //make better sorting
    sort(all_matches.begin(), all_matches.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.second > b.second;  // Sort by popularity, highest first
    });
    Vectory<string> top_matches;
    for (int i = 0; i < min(5, (int)all_matches.size()); i++) {
        top_matches.push_back(all_matches[i].first);
    }
    return top_matches;
}

void Triey::lookForWords(Nodey* current, string input, Vectory<pair<string, int> > & all_matches){
    //to make into vector or smt (linked list??)
   // cout << "looking for : " << current << endl;
    if (current->endofWord == true){
        all_matches.push_back({input, current->popularity}); 
    }
    for (int i = 0; i < 26; i++){
    if (current->childrens[i]) {
        char child = 'a' + i;
        lookForWords(current->childrens[i],
                       input + child, all_matches);
    }
    }
}

bool Triey::lookForWord(string word){
    Nodey* current = root;
    for (char c:word){
        int index = c - 'a';
        if (!current->childrens[index]) {
            return false;
        }
        current = current->childrens[index];
    }
    return current->endofWord;
}

void Triey::print(Nodey* node, string prefix) const
{
    if (node->endofWord) {
        cout << prefix << endl;
    }
    for (int i = 0; i < 26; i++) {
        if (node->childrens[i]) {
            print(node->childrens[i],
                  prefix + char('a' + i));
        }
    }
}

void Triey::print() const { print(root, ""); }