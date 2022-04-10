#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertIntoBst(Node* root, int data)
{
    if(root == NULL)
    {
        root = new Node(data);
        return root;
    }

    if(data > root->data){
        root->right =insertIntoBst(root->right, data);
    }

    else {
        root->left = insertIntoBst(root->left, data);
    }

    return root;


}

void levelOrderTraversal(Node* root)
{
    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        int size = q.size();

        for(int i=0; i<size; i++)
        {
            Node* cur = q.front();
            q.pop();

            cout<<cur->data<<" ";
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
        cout<<endl;


    }
}

void preorder(Node* root)
{
    if(root == NULL)return;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root)
{
    if(root == NULL) return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(Node* root)
{
    if(root == NULL)return;

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<< " ";
}


void takeInput(Node* &root)
{
    int data;
    cin >> data;

    while(data != -1){
        root = insertIntoBst(root, data);
        cin >> data;
    }
}

bool searchInBst(Node* root, int x)
{
    if(root == NULL){
        return false;
    }
    if(root->data == x){
        return true;
    }

    if(root->data < x){
        return searchInBst(root->right, x);
    }
    else{
        return searchInBst(root->left, x);
    }
}

int getMinElement(Node* root)
{
    Node* temp = root;
    while(temp->left != 0){
        temp = temp->left;
    }

    return temp->data;
}

int getMaxElement(Node* root)
{
    Node* temp = root;
    while(temp->right != 0){
        temp = temp->right;
    }

    return temp->data;
}

Node* deleteInBst(Node* root, int key)
{
    if(root == NULL) return NULL;

    if(root->data == key){
        //0 childern
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        //1 children

        //if it is left child
        if(root->left !=0 && root->right == 0){
            Node* temp = root->left;
            delete root;
            return temp;

        }

        //if it is right child
        if(root->right != 0 && root->left == 0){
            Node* temp = root->right;
            delete root;
            return temp;

        }


        //two children
        if(root->left != 0 && root->right != 0){
            //there are two options here either take max value from the left or take min value from the right
            //i am tKING MIN VALUE FROM THE RIGHT
            int mini = getMinElement(root->right);

            //copy mini value into root->data;
            root->data = mini;

            //after that we need to delete the mini element node;
            //simply call the recursion
            root->right = deleteInBst(root->right, mini);
            return root;
        }
    }

    else if(root->data > key){
        root->left = deleteInBst(root->left, key);
      
    }
    else{
        root->right = deleteInBst(root->right, key);
        
    }
    return root;
}


int main()
{

    Node* root = NULL;

    cout<<"enter data to create bst"<<endl;
    takeInput(root);

    // cout<<"levelorder traversal for the bst"<<endl;
    // levelOrderTraversal(root);

    // cout<<"preorder traversal of the bst"<<endl;
    // preorder(root);
    // cout<<endl;

    // cout<<"postorder traversal of the bst"<<endl;
    // postorder(root);
    // cout<<endl;
    

    cout<<"inorder traversal of the bst"<<endl;
    inorder(root);

    // int target;
    // cin>>target;
    // cout << searchInBst(root, target);
    
    // cout<<getMinElement(root)<<endl;
    // cout<<getMaxElement(root)<<endl;

    root = deleteInBst(root, 30);

    cout<<"levelorder traversal for the bst"<<endl;
    levelOrderTraversal(root);

    cout<<"inorder traversal of the bst"<<endl;
    inorder(root);


    return 0;
}