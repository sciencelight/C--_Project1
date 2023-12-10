#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
struct node
{
    int data;
    node *left, *right;
    node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
void add_node(node *root, vector<int> &arr)
{
    arr.push_back(root->data);
    if (root->left)
        add_node(root->left, arr);
    if (root->right)
        add_node(root->right, arr);
}
int kmax(node *root, int k)
{
    if (!root)
        return -1;
    vector<int> arr;
    add_node(root, arr);
    sort(arr.begin(), arr.end(), greater<int>());
    return arr[k - 1];
}
int mlen(node *root)
{
    if (root == nullptr)
        return 0;
    int mleft = mlen(root->left);
    int mright = mlen(root->right);
    return root->data + max(mleft, mright);
}
int main()
{
    node *head = new node(4);
    node *n1, *n2, *n3, *n4;
    n1 = new node(2);
    n2 = new node(1);
    n3 = new node(3);
    n4 = new node(5);
    head->left = n1;
    head->right = n2;
    n1->left = n3;
    n1->right = n4;
    printf("%d\n%d\n", kmax(head, 3), mlen(head));
    return 0;
}
/*
7,0 7,1 6,1 5,0 5,2 4,4
7,0 6,1 7,1 5,0 5,2 4,4
5,0 7,0 6,1 7,1 5,2 4,4
5,0 7,0 5,2 6,1 7,1 4,4
5,0 7,0 5,2 6,1 4,4 7,1








4,4 5,0 5,2 6,1 7,0 7,1
5,0 5,2 6,1 7,0 4,4 7,1
5,0 6,1 5,2 7,0 4,4 7,1
5,0 5,2 7,0 4,4 6,1 7,1

 */
