#include "triey.h"

Triey::Triey()
{
    root = new Nodey();
}

void Triey::populateTriey(Vectory<trieData> words)
{
    for (int j = 0; j < words.size(); j++)
    {
        string word = words[j].word;
        Nodey *current = root;
        for (int i = 0; i < word.size(); i++)
        {
            int index = word[i] - 'a';
            if (current->childrens[index] == NULL)
            {
                current->childrens[index] = new Nodey();
            }
            current = current->childrens[index];
        }
        current->endofWord = true;
        current->popularity = words[j].count;
    }
    
}

Vectory<string> Triey::search(string input)
{
    Vectory<string> top_matches;
    Nodey *current = root;
    for (char c : input)
    {
        int index = c - 'a';
        if (!current->childrens[index])
        {
            top_matches.push_back("No matches found");
            return top_matches;
        }
        current = current->childrens[index];
    }
    // if (current->endofWord && current->childrens == nullptr){
    //     string only_word = "word";
    //     return only_word;
    // }
    Vectory<DocCount> all_matches;
    lookForWords(current, input, all_matches);
    top_matches = rank(all_matches);
    // traverse rest of trie for works?
    // rank based on popular
    return top_matches;
}

Vectory<string> Triey::rank(Vectory<DocCount> &all_matches)
{
    // make better sorting
    bubblySort sorter;
    sorter.quickSort(all_matches, 0, all_matches.size() - 1);
    Vectory<string> top_matches;
    for (int i = 0; i < min(5, (int)all_matches.size()); i++)
    {
        top_matches.push_back(all_matches[i].docName);
    }
    return top_matches;
}

void Triey::lookForWords(Nodey *current, string input, Vectory<DocCount> &all_matches)
{
    // to make into vector or smt (linked list??)
    // cout << "looking for : " << current << endl;
    if (current->endofWord == true)
    {
        DocCount doc;
        doc.docName = input;
        doc.count = current->popularity;
        all_matches.push_back(doc);
    }
    for (int i = 0; i < 26; i++)
    {
        if (current->childrens[i])
        {
            char child = 'a' + i;
            lookForWords(current->childrens[i],
                         input + child, all_matches);
        }
    }
}

bool Triey::lookForWord(string word)
{
    Nodey *current = root;
    for (char c : word)
    {
        int index = c - 'a';
        if (!current->childrens[index])
        {
            return false;
        }
        current = current->childrens[index];
    }
    return current->endofWord;
}

void Triey::print(Nodey *node, string prefix) const
{
    if (node->endofWord)
    {
        cout << prefix << ", pop:" << node->popularity << endl;
    }
    for (int i = 0; i < 26; i++)
    {
        if (node->childrens[i])
        {
            print(node->childrens[i],
                  prefix + char('a' + i));
        }
    }
}

void Triey::print() const { print(root, ""); }