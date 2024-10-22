#include "triey.h"

Triey::Triey()
{
    root = new Nodey();
}

// fill triey with words and popularity count - inserted char by char
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

// serches for index in triey and returns top 5 matches
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
    Vectory<DocCount> all_matches;
    lookForWords(current, input, all_matches);
    top_matches = rank(all_matches);
    // traverse rest of trie for works?
    // rank based on popular
    return top_matches;
}

// ranks the matches based on popularity
Vectory<string> Triey::rank(Vectory<DocCount> &all_matches)
{
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