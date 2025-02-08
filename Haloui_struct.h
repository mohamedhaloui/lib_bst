
using namespace std;

struct node{
int data;
node* l_child;
node* r_child;
int weight;
    node(int v){
       data=v;
l_child=nullptr;
r_child=nullptr; 
weight=1;
        }
};



node* insert_recursive(node* r, int k){ 
     if(r==NULL){
         return new node(k);
         }   
         if(r->data==k){
             r->weight++;
             return r;}
             if(r->data<k){
                 r->r_child=insert_recursive(r->r_child,k);
                 }
                 if(r->data>k){
                 r->l_child=insert_recursive(r->l_child,k);
                 }
    
        return r;}
        
        
        
        
        
node* insert_iterative(node* r, int k) {

    if (r==nullptr) {
        return new node(k);
    }

    node* current=r; 
    node* father{nullptr}; 

    while (current != nullptr) {
        father=current;

        if(k>current->data) {
            current=current->r_child;
        }
else if(k<current->data){
            current=current->l_child;
        }
    else{r->weight++;
           return r;
    
        }
    } node* new_node=new node(k);
    
    if(k>father->data){
        father->r_child=new_node;
    } 
    else{
        father->l_child=new_node; 
    }

    return r;
}

    
    
    
    
bool search_recursive(node* r, int k){
            if(r==nullptr){
                    cout<<"valore non disponibile nell'albero "<<endl;
                return false;
                    }
                    
                    
            if(r->data==k){
                cout<<"trovato con peso "<<r->weight<<endl;
                
               return true;
                }
                
            
            if(r->data<k){
                return search_recursive(r->r_child,k);
                 }
                 if(r->data>k){
               return  search_recursive(r->l_child,k);
                 }
            
        
           }
           
           
           
           
           
bool search_iterative(node* r, int k) {
    node* current = r; 
    while (current != nullptr) {
        if (k > current->data) {
            current = current->r_child; // Scendi a destra
        }
        else if (k < current->data) {
            current = current->l_child; // Scendi a sinistra
        }
        else {
            cout << "Trovato con peso " << current->weight << endl; // Usa current per il peso
            return true; // Valore trovato
        }
    }

    cout << "Valore non disponibile nell'albero" << endl; // Valore non trovato
    return false; // Non trovato
}
    
    
    
    
    
    int height(node* node) {

if (node == nullptr)
 return 0;


int l=height(node->l_child);
int r=height(node->r_child);
return max(l,r)+1;

}





void visit_preOrder(node* node) {

if (node == nullptr) return;

cout << node->data << " ";

visit_preOrder(node->l_child);

visit_preOrder(node->r_child);

}




node* delete_recursive(node* r, int k) {
    if (r==nullptr) {
        return r;
        }

    if (r->data==k) {
        
    
        if (r->l_child==nullptr && r->r_child==nullptr) {
            delete r;
            return nullptr;
        }

        if (r->l_child==nullptr) {

            node* temp= r->r_child;
            delete r;
            return temp;
        }

        if (r->r_child==nullptr) {

            node* temp=r->l_child;
            delete r;
            return temp;
        }

        if (r->l_child->l_child==nullptr && r->l_child->r_child==nullptr &&
            r->r_child->l_child==nullptr && r->r_child->r_child==nullptr){
            
                delete r; 
            node* new_root=new node(r->l_child->data);
            new_root->r_child=r->r_child;
            return new_root;
        }

    } 
    else if(r->data<k) {
        r->r_child=delete_recursive(r->r_child,k);
    }
    else{
        r->l_child=delete_recursive(r->l_child, k);
    }

    return r;
}






node* delete_iterative(node* root, int k) {
    node* parent{nullptr};
    node* current=root;

    while(current!=nullptr && current->data!=k) {
        parent=current;
        if (k<current->data) 
            {
            current=current->l_child;
        } 
        else{
            current=current->r_child;
        }
    }

    if(current==nullptr) {
        return root;
    }
    
    if (current->l_child==nullptr && current->r_child==nullptr) {
        if (current == root){
            delete current;
            return nullptr;
        }

        if (parent->l_child==current) {
            parent->l_child=nullptr;
        }
 else{
            parent->r_child=nullptr;
        }
        delete current;
    }
  
    else if(current->l_child==nullptr || current->r_child==nullptr) {
        node* child;

        if (current->l_child!=nullptr) {
            child=current->l_child; 
        }
        else {
            child=current->r_child;
        }

        if (current==root) {
            delete current;
            return child;
        }

        if (parent->l_child==current) {
            parent->l_child=child;
        }
        else{
            parent->r_child=child;
        }
        delete current;
    }

    else if (current->l_child->l_child==nullptr && current->l_child->r_child==nullptr &&
             current->r_child->l_child==nullptr && current->r_child->r_child==nullptr)
                 {

        node* new_root = new node(current->l_child->data);
        new_root->r_child=current->r_child;
        delete current;
        return new_root;
    }

    else{
        cout<<"Il nodo ha due figli, ma non entrambi sono foglie."<< endl;
    }

    return root;
}



bool verify_bst(node* root) {
    if (root==nullptr) return true;


    if (root->l_child!=nullptr && root->l_child->data>=root->data) {
        return false;
    }


    if (root->r_child!=nullptr && root->r_child->data<=root->data) {
        return false;
    }


    return verify_bst(root->l_child) && verify_bst(root->r_child);
}


