#include <iostream>
using namespace std;

class Node {
private:
    int data;
    int weight;
    Node* lchild;
    Node* rchild;

public:

    Node(int v) {
        data=v;
        weight=1;
        lchild=nullptr;
        rchild=nullptr;
    }


    void insertR(int k){
        if(this->data==k) {
            this->weight++;
            return;
        }

        if(k>this->data){
            
            if (this->rchild==nullptr)
                this->rchild=new Node(k);
            else{
                this->rchild->insertR(k);}
        } 
        else{

            if(this->lchild==nullptr)
                this->lchild=new Node(k);
            else{
                this->lchild->insertR(k);
        }
    }
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
};

int main() {
    Node* root=new Node(10);

    root->insertR(5);
    root->insertR(15);
    root->insertR(3);
    root->insertR(7);
    root->insertR(12);
    root->insertR(17);

    root->inOrder();


    return 0;
}
