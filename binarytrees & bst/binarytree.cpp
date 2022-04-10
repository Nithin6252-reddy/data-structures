#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildTree(node *root)
{
    int data;
    cout << "enter the data" << endl;
    cin >> data;

    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "enter the data to insert into left of the" << data << endl;

    root->left = buildTree(root->left);

    cout << "enter the data to insert into right of the " << data << endl;

    root->right = buildTree(root->right);

    return root;
}

void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();

        for (int i = 0; i < size; i++)
        {
            node *cur = q.front();
            q.pop();

            cout << cur->data << " ";
            if (cur->left)
                q.push(cur->left);
            if (cur->right)
                q.push(cur->right);
        }
        cout << endl;
        cout << endl;
    }
}

void preorderTraversal(node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postOrderTraversal(node *root)
{
    if (root == NULL)
        return;

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

void inorderTraversal(node* root)
{
    if(root==NULL) return;

    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}

void buildTreeFromLevelOrder(node* &root)
{
    queue<node*> q;
    int data;
    cout<<"enter the data"<<endl;
    cin>>data;
    root = new node(data);

    q.push(root);

    while(!q.empty())
    {
        node* cur = q.front();
        q.pop();

        cout<<"enter left node for: "<<cur->data<<endl;
        int leftData;
        cin>>leftData;

        if(leftData != -1){
            cur->left = new node(leftData);
            q.push(cur->left);
        }

        cout<<"enter right node for: "<<cur->data<<endl;
        int rightData;
        cin>>rightData;

        if(rightData != -1){
            cur->right = new node(rightData);
            q.push(cur->right);
        }

    }
}

int heightOfBinaryTree(node* root)
{
    if(root == NULL)return 0;

    int left = heightOfBinaryTree(root->left);
    int right =  heightOfBinaryTree(root->right);

    return max(left, right) + 1;
}

int main()
{

    node* root = NULL;
    buildTreeFromLevelOrder(root);
    // levelOrderTraversal(root);

    cout<<heightOfBinaryTree(root)<<endl;

    
    /*
    node *root = NULL;
    root = buildTree(root);

    levelOrderTraversal(root);
    cout << endl;

    preorderTraversal(root);
    cout << endl;

    postOrderTraversal(root);
    cout << endl;

    inorderTraversal(root);
    */




    return 0;
}