#include "../tools/indexy.h"
#include "../structures/mappy.h"

int main()
{
    Indexy idx;
    Mappy index;
    std::string path = "../books";

    // Iterate through files in the specified directory and add them to the index
    for (const auto &entry : fs::directory_iterator(path))
    {
        idx.addFiley(entry.path().string(), index);
    }
    // Export the index to CSV files
    idx.toCsv(index);

    return 0;
}