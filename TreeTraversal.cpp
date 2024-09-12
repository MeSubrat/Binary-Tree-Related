#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x)
    {
        data=x;
        left=right=NULL;
    }
};

void preOrder(Node* root)
{
    if(root==NULL)return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root)
{
    if(root==NULL)return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void postOrder(Node* root){
    if(root==NULL)return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

//ITERATIVE PREORDER TRAVERSAL
vector<int> preOrderIterative(Node* root)
{
    vector<int> preOrder;
    if(root==NULL)return preOrder;
    stack<Node*> st;
    st.push(root);
    while(!st.empty())
    {
        root=st.top();
        st.pop();
        preOrder.push_back(root->data);
        if(root->right!=NULL)st.push(root->right);
        if(root->left!=NULL)st.push(root->left);
    }
    return preOrder;
}

//ITERATIVE POST ORDER TRAVERSAL
vector<int> postOrderIterative(Node* root)
{
    vector<int> postOrder;
    stack<Node*> st1,st2;
    st1.push(root);
    if(root==NULL)return postOrder;
    while(!st1.empty())
    {
        Node* root=st1.top();
        st1.pop();
        st2.push(root);
        if(root->left!=NULL) st1.push(root->left);
        if(root->right!=NULL) st1.push(root->right);
    }
    while(!st2.empty())
    {
        postOrder.push_back(st2.top()->data);
        st2.pop();
    }
    return postOrder;
}//TC : O(Nodes) SC:O(2Nodes)//As we are using two stacks here

//ITERATIVE INORDER TRAVERSAL
vector<int> inOrderIterative(Node* root)
{
    vector<int> inOrder;
    stack<Node*> st;
    Node* node= root;
    if(root==NULL)return inOrder;
    while(true)
    {
        if(node!=NULL)
        {
            st.push(node);
            node=node->left;
        }
        else{
            if(st.empty()) break;
            node=st.top();
            inOrder.push_back(node->data);
            node=node->right;
        }
    }
    return inOrder;
}
//ITERATIVE POSTORDE ORDER TRAVERSAL USING ONE STACK
/*
    {

    }
*/

//PRE,POST,INORDER TRAVERSAL IN ONE TRAVERSAL
vector<vector<int>> preInPostTraversal(Node* root)
{
    stack<pair<Node*,int>>st;
    vector<int> pre,in,post;
    st.push({root,1});

    while(!st.empty())
    {
        auto it=st.top();
        st.pop();
        if(it.second==1){
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->left!=NULL)
            {
                st.push({it.first->left,1});
            }
        }
        else if(it.second==2){
            in.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->right!=NULL){
                st.push({it.first->right,1});
            }
        }
        else{
            post.push_back(it.first->data);
        }
    }
    return {pre,in,post};
}

void print(vector<int> &nums){
    for(int i=0;i<nums.size();i++)
    {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    struct Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    // preOrder(root);
    // inOrder(root);
    // postOrder(root);
    // vector<int> preOrder=preOrderIterative(root);
    // for(int i=0;i<preOrder.size();i++)
    // {
    //     cout<<preOrder[i]<<" ";
    // }
    cout<<endl;
    // vector<int> postOrder=postOrderIterative(root);
    // for(int i=0;i<postOrder.size();i++)
    // {
    //     cout<<postOrder[i]<<" ";
    // }
    // vector<int> inOrder=inOrderIterative(root);
    // for(int i=0;inOrder.size();i++)
    // {
    //     cout<<inOrder[i]<<" ";
    // }
    vector<vector<int>> result;
    result=preInPostTraversal(root);
    print(result[0]);
    print(result[1]);
    print(result[2]);

}