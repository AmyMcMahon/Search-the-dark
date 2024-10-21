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
        index.addWord(word.c_str(), name.c_str());
    }
    file.close();
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

void Indexy::createIndex()
{
    Mappy index;
    std::string path = "./books";
    // Iterate through files in the specified directory and add them to the index
    for (const auto &entry : fs::directory_iterator(path))
    {
        addFiley(entry.path().string(), index);
    }
    // Export the index to CSV files
    toCsv(index);
}

Vectory<Result> Indexy::getBooks(const std::string &searchStr)
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

Vectory<Result> Indexy::sortResultsByRelevance(const Vectory<DocCount> &books)
{
    Vectory<Result> results;
    for (const auto &book : books)
    {
        Result result;
        std::string title = book.docName.substr(book.docName.find_last_of("\\") + 1, book.docName.find_last_of(".") - book.docName.find_last_of("\\") - 1);
        result.title = title; // Can modify to get actual title if needed
        result.relevance = book.count;
        result.filePath = book.docName; // You might want to use the actual path or a more meaningful identifier
        results.push_back(result);
    }
    // Sort by relevance (count)
    std::sort(results.begin(), results.end(), [](const Result &a, const Result &b)
              {
                  return a.relevance > b.relevance; // Sort in descending order
              });
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
        std::string fileName = "../index/" + std::string(1, firstLetter) + ".csv";
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