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

    Node* insertI(int k){
        Node* current=this;
        Node* parent=nullptr;
        while(current!=nullptr){
            parent=current;
            if(k==current->data){
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

    Node* insertR(int k){
        if(this==nullptr){
            return new Node(k);
        }
        if(k==this->data){
            this->weight++;
        }
        else if(k<this->data){
            if(this->lchild==nullptr){
                this->lchild=new Node(k);
            }
            else{
                this->lchild->insertR(k);
            }
        }
        else{
            if(this->rchild==nullptr){
                this->rchild=new Node(k);
            }
            else{
                this->rchild->insertR(k);
            }
        }
        return this;
    }

    bool searchR(int k){
        if(this==nullptr){
            cout<<"non trovato"<<endl;
            return false;
        }
        if(this->data==k){
            cout<<"trovato"<<endl;
            return true;
        }
        if(k<this->data){
            return this->lchild->searchR(k);
        }
        else{
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

    void inOrder(){
        if(this->lchild!=nullptr){
            this->lchild->inOrder();
        }
        cout<<this->data<<" ";
        if(this->rchild!=nullptr){
            this->rchild->inOrder();
        }
    }

    void preOrder(){
        cout<<this->data<<" ";
        if(this->lchild!=nullptr){
            this->lchild->preOrder();
        }
        if(this->rchild!=nullptr){
            this->rchild->preOrder();
        }
    }

    void postOrder(){
        if(this->lchild!=nullptr){
            this->lchild->postOrder();
        }
        if(this->rchild!=nullptr){
            this->rchild->postOrder();
        }
        cout<<this->data<<" ";
    }

    int height(){
        if(this==nullptr) return 0;
        int leftHeight=(this->lchild)?this->lchild->height():0;
        int rightHeight=(this->rchild)?this->rchild->height():0;
        return max(leftHeight,rightHeight)+1;
    }

    int depth(Node* node){
        int d=0;
        Node* current=this;
        while(current!=nullptr){
            if(current==node) return d;
            else if(node->data<current->data){
                current=current->lchild;
            }
            else{
                current=current->rchild;
            }
            d++;
        }
        return -1;
    }
    friend ostream& operator<<(ostream& os, const Node& node) {
    os<<node.data;
        return os;
    }

    friend istream& operator>>(istream& is, Node*& node) {
        int value;
        is>>value;
    node=new Node(value);
    root->rchild=nullptr;
    root->lchild=nullptr;
    
    
        return is;
    }
    Node* deleteNodeR(int k) {
        if(this==nullptr){return nullptr};

        if(k<this->data){
            this->lchild=this->lchild->deleteNode(k);
        } 
        elseif
        (k>this->data){
            this->rchild=this->rchild->deleteNode(k);
        }
        else
        {
 if (this->lchild==nullptr) {
                Node* temp=this->rchild;
                delete this;
                return temp;
            }
            else if(this->rchild==nullptr){
                Node* temp=this->lchild;
                delete this;
                return temp;
            }

           
            Node* temp=this->rchild;
            while(temp && temp->lchild!=nullptr) {
                temp=temp->lchild;
            }
            this->data=temp->data;
            this->rchild=this->rchild->deleteNode(temp->data);
        }
        return this;
    }
    bool isBst(node* root){
    if (root->l_child !=nullptr && root->l_child->data>=root->data) {
        return false;
    }
    if (root->r_child!=nullptr && root->r_child->data<=root->data){
        return false;
    }


    bool leftIsBst=isBst(root->l_child);
    bool rightIsBst=isBst(root->r_child);


    return leftIsBst && rightIsBst;
}bool isBst(node* root){
    if (root->l_child !=nullptr && root->l_child->data>=root->data) {
        return false;
    }
    if (root->r_child!=nullptr && root->r_child->data<=root->data){
        return false;
    }


    bool leftIsBst=isBst(root->l_child);
    bool rightIsBst=isBst(root->r_child);


    return leftIsBst && rightIsBst;
}
};
