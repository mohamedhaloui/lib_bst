#include <iostream>
using namespace std;

class Node{
private:
    int data;
    int weight;
    Node* lchild;
    Node* rchild;

public:
    Node(int v){
        data=v;
        weight=1;
        lchild=nullptr;
        rchild=nullptr;
    }
   
   
    Node* insertI(int k) {
        Node* current=this;
        Node* parent=nullptr;

        while (current!=nullptr){
            parent=current;
            if (k==current->data) {
                current->weight++;
                return this;
            }
        else if(k<current->data){
                current=current->lchild;
            }
            else{
                current=current->rchild;
            }
        }

        if(k<parent->data){
            parent->lchild=new Node(k);
        }
        else{
            parent->rchild=new Node(k);
        }
        return this;
   
}

bool searchR(int k){
        if(this==nullptr){
            cout<<"non trovato "<<endl;
            return false;
        }
        if(this->data==k){
            cout<<"trovato "<<endl;
            return true;
        }
        if(k<this->data){
                return this->lchild->searchR(k);
            }
        else if (k>this->data){
                return this->rchild->searchR(k);
            }
        }
   
   
bool searchI(int k){
        Node* current=this;
        while(current!=nullptr){
            if(current->data==k){
                return true;
            }
            else if(k<current->data){
                current=current->lchild;
            }
            else{
                current=current->rchild;
            }
        }
        return false;
    }
   
       void inOrder() {
        if (this->lchild!=nullptr){
            this->lchild->inOrder();
           
        }
        cout<<this->data<<endl;
        if(this->rchild!=nullptr){
            this->rchild->inOrder();
           
        }
    }
   
friend ostream& operator<<(ostream& os, const Node& node) {
    os<<node.data;
        return os;
    }

    friend istream& operator>>(istream& is, Node*& node) {
        int value;
        is>>value;
    node=new Node(value);
        return is;
    }

};



