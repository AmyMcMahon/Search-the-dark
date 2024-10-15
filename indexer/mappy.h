#include <iostream>
using namespace std;

class Mappy
{
private:
    const int search(int first) const
    {
        const Mappy *temp = root;
        while (temp != nullptr && temp->first != first)
        {
            if (first < temp->first)
                temp = temp->left;
            else
                temp = temp->right;
        }
        if (temp != nullptr)
        {
            return temp->second;
        }
        return 0;
    }

    Mappy *create(int first)
    {
        Mappy *newNode = new Mappy();
        newNode->first = first;
        newNode->second = 0;
        newNode->left = nullptr;
        newNode->right = nullptr;
        newNode->par = nullptr;
        newNode->depth = 1;

        return newNode;
    }

    void rightRotate(Mappy *x)
    {
        Mappy *y = x->left;
        x->left = y->right;
        if (y->right != nullptr)
        {
            y->right->par = x;
        }
        if (x->par != nullptr && x->par->right == x)
        {
            x->par->right = y;
        }
        else if (x->par != nullptr && x->par->left == x)
        {
            x->par->left = y;
        }
        y->par = x->par;
        y->right = x;
        x->par = y;
    }

    void leftRotate(Mappy *x)
    {
        Mappy *y = x->right;
        x->right = y->left;
        if (y->left != nullptr)
        {
            y->left->par = x;
        }
        if (x->par != nullptr && x->par->right == x)
        {
            x->par->right = y;
        }
        else if (x->par != nullptr && x->par->left == x)
        {
            x->par->left = y;
        }
        y->par = x->par;
        y->left = x;
        x->par = y;
    }

    void helpy(Mappy *x)
    {
        // LL rotation
        if (depthy(x->right) - depthy(x->left) < -1)
        {
            if (depthy(x->left->left) > depthy(x->left->right))
            {
                x->depth = max(depthy(x->right) + 1, depthy(x->left->right) + 1);
                x->left->depth = max(depthy(x->left->left) + 1, depthy(x) + 1);
                rightRotate(x);
            }
            else
            {
                x->left->depth = max(depthy(x->left->left) + 1, depthy(x->left->right->left) + 1);
                x->depth = max(depthy(x->right) + 1, depthy(x->left->right->right) + 1);
                x->left->right->depth = max(depthy(x) + 1, depthy(x->left) + 1);
                leftRotate(x->left);
                rightRotate(x);
            }
        }
        // RR rotation
        else if (depthy(x->right) - depthy(x->left) > 1)
        {
            if (depthy(x->right->right) > depthy(x->right->left))
            {
                x->depth = max(depthy(x->left) + 1, depthy(x->right->left) + 1);
                x->right->depth = max(depthy(x->right->right) + 1, depthy(x) + 1);
                leftRotate(x);
            }
            else
            {
                x->right->depth = max(depthy(x->right->right) + 1, depthy(x->right->left->right) + 1);
                x->depth = max(depthy(x->left) + 1, depthy(x->right->left->left) + 1);
                x->right->left->depth = max(depthy(x) + 1, depthy(x->right) + 1);
                rightRotate(x->right);
                leftRotate(x);
            }
        }
    }

    void balance(Mappy *node)
    {
        while (node != root)
        {
            int d = node->depth;
            node = node->par;
            if (node->depth < d + 1)
            {
                node->depth = d + 1;
            }
            if (node == root && depthy(node->left) - depthy(node->right) > 1)
            {
                if (depthy(node->left->left) > depthy(node->left->right))
                {
                    root = node->left;
                }
                else
                {
                    root = node->left->right;
                }
                helpy(node);
                break;
            }
            else if (node == root && depthy(node->left) - depthy(node->right) < -1)
            {
                if (depthy(node->right->right) > depthy(node->right->left))
                {
                    root = node->right;
                }
                else
                {
                    root = node->right->left;
                }
                helpy(node);
                break;
            }
            helpy(node);
        }
    }

    int depthy(Mappy *node)
    {
        if (node == nullptr)
            return 0;
        return node->depth;
    }

    Mappy *insert(int first)
    {
        Mappy *newnode = create(first);

        if (root == nullptr)
        {
            root = newnode;
            return root;
        }
        Mappy *temp = root, *prev = nullptr;
        while (temp != nullptr)
        {
            prev = temp;
            if (first < temp->first)
            {
                temp = temp->left;
            }
            else if (first > temp->first)
            {
                temp = temp->right;
            }
            else
            {
                free(newnode);
                return temp;
            }
        }
        if (first < prev->first)
        {
            prev->left = newnode;
        }
        else
        {
            prev->right = newnode;
        }
        newnode->par = prev;

        balance(newnode);

        return newnode;
    }

public:
    static class Mappy *root;
    static int cnt;

    Mappy *left, *right, *par;
    int first, second, depth;

    int &operator[](int key) { return insert(key)->second; }
    const int operator[](int key) const
    {
        return search(key);
    }
};

Mappy *Mappy::root = nullptr;
