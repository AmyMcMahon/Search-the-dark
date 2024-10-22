#include "mappy.h"

// Method to create a new node
Mappy *Mappy::create(const char *first, std::string docName)
{
    Mappy *newNode = new Mappy();
    newNode->first = first;
    newNode->second.count = 1;
    newNode->second.docCounts.push_back({docName, 1});
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->par = nullptr;
    newNode->depth = 1;
    return newNode;
}
// Get the depth of a node
int Mappy::depthy(Mappy *node)
{
    if (node == nullptr)
        return 0;
    return node->depth;
}

// method to balance the tree
void Mappy::balance(Mappy *node)
{
    while (node != nullptr)
    {
        int balanceFactor = depthy(node->right) - depthy(node->left);
        // check if tree is left heavy or right heavy
        if (balanceFactor < -1)
        {
            if (depthy(node->left->left) >= depthy(node->left->right))
            {
                rightRotate(node); // LL Case
            }
            else
            {
                leftRotate(node->left); // LR Case
                rightRotate(node);      // Final rotation
            }
        }
        else if (balanceFactor > 1)
        {
            if (depthy(node->right->right) >= depthy(node->right->left))
            {
                leftRotate(node); // RR Case
            }
            else
            {
                rightRotate(node->right); // RL Case
                leftRotate(node);         // Final rotation
            }
        }
        // Update depth and move to parent node
        node->depth = max(depthy(node->left), depthy(node->right)) + 1;
        node = node->par;
    }
}

// function to rotate right around a node
void Mappy::rightRotate(Mappy *x)
{
    Mappy *y = x->left;
    x->left = y->right;
    if (y->right != nullptr)
    {
        y->right->par = x;
    }
    y->par = x->par;
    if (x->par == nullptr)
    {
        root = y;
    }
    else if (x == x->par->right)
    {
        x->par->right = y;
    }
    else
    {
        x->par->left = y;
    }
    y->right = x;
    x->par = y;
    // Update depth
    x->depth = max(depthy(x->left), depthy(x->right)) + 1;
    y->depth = max(depthy(y->left), depthy(y->right)) + 1;
}

// function to rotate left around a node
void Mappy::leftRotate(Mappy *x)
{
    Mappy *y = x->right;
    x->right = y->left;
    if (y->left != nullptr)
    {
        y->left->par = x;
    }
    y->par = x->par;
    if (x->par == nullptr)
    {
        root = y;
    }
    else if (x == x->par->left)
    {
        x->par->left = y;
    }
    else
    {
        x->par->right = y;
    }
    y->left = x;
    x->par = y;
    // Update depth
    x->depth = max(depthy(x->left), depthy(x->right)) + 1;
    y->depth = max(depthy(y->left), depthy(y->right)) + 1;
}

// function to remove a node from the tree - used for removing books from index
Mappy *Mappy::remove(const char *word, const std::string &docName)
{
    Mappy *temp = root;
    while (temp != nullptr)
    {
        if (std::string(word) < temp->first)
        {
            temp = temp->left;
        }
        else if (std::string(word) > temp->first)
        {
            temp = temp->right;
        }
        else
        {
            // Word found, look for the document
            bool docFound = false;
            for (auto it = temp->second.docCounts.begin(); it != temp->second.docCounts.end(); ++it)
            {
                if (it->docName == docName)
                {
                    // Reduce the overall count of this word from this document
                    temp->second.count -= it->count;
                    // Erase the document entry from the vector
                    int index = it - temp->second.docCounts.begin();
                    temp->second.docCounts.erase(index);
                    docFound = true;
                    break;
                }
            }
            if (!docFound)
            {
                std::cerr << "Document not found!" << std::endl;
                return nullptr; // Document not found
            }
            // If the word has no more occurrences, remove the word
            if (temp->second.docCounts.empty())
            {
                Mappy *parent = removeNode(temp);
                balance(parent);
                return parent;
            }
            return temp;
        }
    }
    std::cerr << "Word not found!" << std::endl;
    return nullptr;
}

// function to remove a node from the tree and rebalance
Mappy *Mappy::removeNode(Mappy *node)
{
    if (node->left == nullptr && node->right == nullptr)
    {
        // No children
        if (node->par == nullptr)
        {
            root = nullptr; // Removing root node
        }
        else if (node == node->par->left)
        {
            node->par->left = nullptr;
        }
        else
        {
            node->par->right = nullptr;
        }
        Mappy *parent = node->par;
        delete node;
        return parent;
    }
    else if (node->left == nullptr || node->right == nullptr)
    {
        // One child
        Mappy *child = (node->left != nullptr) ? node->left : node->right;
        if (node->par == nullptr)
        {
            root = child; // Node is root, update root
        }
        else if (node == node->par->left)
        {
            node->par->left = child;
        }
        else
        {
            node->par->right = child;
        }
        child->par = node->par;
        Mappy *parent = node->par;
        delete node;
        return parent;
    }
    else
    {
        // Two children, find in-order successor (smallest in right subtree)
        Mappy *successor = node->right;
        while (successor->left != nullptr)
        {
            successor = successor->left;
        }
        // Copy successor's data to node
        node->first = successor->first;
        node->second = successor->second;
        // Delete the successor node
        Mappy *parent = removeNode(successor);
        balance(parent);
        return parent;
    }
}
// Insert a new word or update the count for a word
Mappy *Mappy::insert(const char *first, const std::string &docName)
{
    Mappy *newNode = create(first, docName);
    if (root == nullptr)
    {
        root = newNode;
        return root;
    }
    Mappy *temp = root, *prev = nullptr;
    while (temp != nullptr)
    {
        prev = temp;
        if (newNode->first < temp->first)
        {
            temp = temp->left;
        }
        else if (newNode->first > temp->first)
        {
            temp = temp->right;
        }
        else
        {
            // Word already exists, update the count and document list
            temp->second.count++;
            bool docExists = false;
            for (auto &docCount : temp->second.docCounts)
            {
                if (docCount.docName == docName)
                {
                    docCount.count++;
                    docExists = true;
                    break;
                }
            }
            if (!docExists)
            {
                temp->second.docCounts.push_back({docName, 1});
            }
            delete newNode;
            return temp;
        }
    }
    if (newNode->first < prev->first)
    {
        prev->left = newNode;
    }
    else
    {
        prev->right = newNode;
    }
    newNode->par = prev;
    // Balance the tree after insertion
    balance(newNode);
    return newNode;
}

// Method to add a word to the index
void Mappy::addWord(const char *word, std::string docName)
{
    insert(word, docName);
}
// Method to remove a word from the index
void Mappy::removeWord(const char *word, std::string docName)
{
    remove(word, docName);
}
