#include <bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
        string data;
        TreeNode* leftNode, *rightNode;

        TreeNode( string value ){
            data = value;
            leftNode = NULL;
            rightNode = NULL;
        }
};

void preOrderTraversalTCO( stack<TreeNode*>& st ){
    if( st.empty() )
        return;

    if( !st.empty() ){
        TreeNode* temp = st.top();
        cout << temp->data << endl;
        st.pop();
        
        if( temp->rightNode != NULL )
            st.push( temp->rightNode );
        if( temp->leftNode != NULL )
            st.push( temp->leftNode );
        
    }
    preOrderTraversalTCO( st );
}
void preOrderTraversal( TreeNode* rootNode ){
    stack< TreeNode* > st;
    st.push( rootNode );

    preOrderTraversalTCO( st );
}
int main(){

    TreeNode* rootNode = new TreeNode("Menu");
    TreeNode* drinks = new TreeNode("Drinks");
    TreeNode* tea = new TreeNode("Tea");
    TreeNode* coffee = new TreeNode("Coffee");
    TreeNode* food = new TreeNode("Food");
    TreeNode* rice = new TreeNode("Rice");
    TreeNode* dal = new TreeNode("Dal");

    rootNode->leftNode = drinks;
    rootNode->rightNode = food;

    drinks->leftNode = tea;
    drinks->rightNode = coffee;

    food->leftNode = rice;
    food->rightNode = dal;

    preOrderTraversal( rootNode );
    return 0;
}

/*
                    Menu
                    /  \
                   /    \
                  /      \
                 /        \
              Drinks     Food
               /  \       / \ 
              /    \   Rice Dal
            Tea   Coffee
*/
