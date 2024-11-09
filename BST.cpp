
#include<iostream>

using namespace std;

#include "functions.h"



int main() {
node* root=new node(49);
    root=insert_recursive(root,56);
    root=insert_recursive(root,45);
    root=insert_recursive(root,67);
    root=insert_recursive(root,59);
    root=insert_recursive(root,47);
    visit_preOrder(root);
    cout<<endl;
    
    cout<<"elimino il nodo numero 67"<<endl;
    delete_recursive(root,67);
    
    visit_preOrder(root);
    cout<<endl;
    
    
    int cc=66;
    cout<<"nodo "<<cc<<" ";
    search_recursive(root,cc);
    cout<<endl;
    int ccc=47;
    cout<<"nodo "<<ccc<<" ";
    search_iterative(root,ccc);
    cout<<endl;
    

    
    if (verify_bst(root)==true) {
        cout<<"E' UN BST"<<endl;
    } 
    else{
        cout <<"NON E' UN BST"<<endl;
    }
    
    cout<<"con altezza"<<endl;
    cout<<height(root);
    
            
return 0;}



