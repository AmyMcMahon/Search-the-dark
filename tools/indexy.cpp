#include "indexy.h"

Indexy::Indexy() {};

void Indexy::addFiley(const std::string &name, Mappy &index)
{
    std::ifstream file(name);
    if (!file.is_open())
    {
        std::cerr << "Error opening the file!" << std::endl;
        return;
    }
    std::string word;
    while (file >> word)
    {
        // Convert to lowercase and remove punctuation
        for (int i = 0, len = word.size(); i < len; i++)
        {
            word[i] = tolower(word[i]);
            if (ispunct(word[i]))
            {
                word.erase(i--, 1);
                len = word.size();
            }
        }
        // Insert the word into the index with the document ID
        if (std::all_of(word.begin(), word.end(), [](char c)
                        { return std::isalpha(c); }))
        {
            index.addWord(word.c_str(), name.c_str());
        }
    }
    file.close();

    // Add the file to the list of indexed books
    std::ofstream indexedBooksFile("./indexer/indexedBooks.csv", std::ios::app);
    if (!indexedBooksFile.is_open())
    {
        std::cerr << "Error opening the file!" << std::endl;
        return;
    }
    indexedBooksFile << name << std::endl;
    indexedBooksFile.close();
}

void Indexy::removeFile(const std::string &name, Mappy &index)
{
    std::ifstream file(name);
    if (!file.is_open())
    {
        std::cerr << "Error opening the file!" << std::endl;
        return;
    }
    std::string word;
    while (file >> word)
    {
        // Convert to lowercase and remove punctuation
        for (int i = 0, len = word.size(); i < len; i++)
        {
            word[i] = tolower(word[i]);
            if (ispunct(word[i]))
            {
                word.erase(i--, 1);
                len = word.size();
            }
        }
        // Remove the word from the index with the document ID
        index.removeWord(word.c_str(), name.c_str());
    }
    file.close();
}

void Indexy::toCsv(Mappy &index)
{
    collectData(index.root); // Collect data from the index and write to CSV
}

Vectory<Result> Indexy::getBooks(std::string &searchStr)
{
    // Get the first letter of the search string to open CSV
    char firstLetter = tolower(searchStr[0]);
    std::string fileName = "./index/" + std::string(1, firstLetter) + ".csv";
    std::ifstream file(fileName);
    if (!file.is_open())
    {
        std::cerr << "Error opening the file: " << fileName << std::endl;
        return Vectory<Result>();
    }
    Vectory<DocCount> books;
    std::string line;
    // Read the file and find word and documents
    while (std::getline(file, line))
    {
        std::string word;
        std::istringstream ss(line);
        std::getline(ss, word, ',');
        if (word == searchStr)
        {
            std::string count;
            std::getline(ss, count, ',');
            std::string bookPath, bookCount;
            while (std::getline(ss, bookPath, ','))
            {
                if (std::getline(ss, bookCount, ','))
                {
                    DocCount doc;
                    int bookCountInt = std::stoi(bookCount);
                    doc.docName = bookPath;
                    doc.count = bookCountInt;
                    books.push_back(doc);
                }
            }
            break;
        }
    }
    file.close();
    return sortResultsByRelevance(books);
}

Vectory<Result> Indexy::sortResultsByRelevance(Vectory<DocCount> &books)
{
    Vectory<Result> results;
    sorter.quickSort(books, 0, books.size() - 1);
    for (const auto &book : books)
    {
        Result result;
#ifdef OS_Windows
        std::string title = book.docName.substr(book.docName.find_last_of("\\") + 1, book.docName.find_last_of(".") - book.docName.find_last_of("\\") - 1);
#else
        std::string title = book.docName.substr(book.docName.find_last_of("/") + 1, book.docName.find_last_of(".") - book.docName.find_last_of("/") - 1);
#endif
        result.title = title; // Can modify to get actual title if needed
        result.relevance = book.count;
        result.filePath = book.docName;
        results.push_back(result);
    }
    return results;
}

void Indexy::collectData(Mappy *node)
{
    if (node == nullptr)
        return;
    // In-order traversal to maintain order in the CSVs
    collectData(node->left);
    if (!node->first.empty())
    {
        char firstLetter = tolower(node->first[0]);
        std::string fileName = "./index/" + std::string(1, firstLetter) + ".csv";
        std::ofstream file(fileName, std::ios::app);
        if (!file.is_open())
        {
            std::cerr << "Error opening the file: " << fileName << std::endl;
            return;
        }
        // Write the word, its total count, and document counts to the file
        file << node->first << "," << node->second.count << ",";
        for (const DocCount &docCount : node->second.docCounts)
        {
            file << docCount.docName << "," << docCount.count << "," << "\t";
        }
        file << std::endl;
        file.close(); // Close the file after writing the data
    }
    collectData(node->right);
}

Vectory<trieData> Indexy::readFileTrie(char word)
{
    char firstLetter = tolower(word);
    std::string fileName = "./index/" + std::string(1, firstLetter) + ".csv";
    std::ifstream file(fileName);
    if (!file.is_open())
    {
        std::cerr << "Error opening the file: " << fileName << std::endl;
        return Vectory<trieData>();
    }
    Vectory<trieData> words;

    std::string line;

    while (std::getline(file, line))
    {
        std::string word;
        std::istringstream ss(line);
        std::getline(ss, word, ',');

        std::string count;
        std::getline(ss, count, ',');
        trieData data;
        data.word = word;
        data.count = std::stoi(count);
        words.push_back(data);
    }
    file.close();
    return words;
}
