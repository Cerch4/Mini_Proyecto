  #ifndef LISTARR_H_
#define LISTARR_H_

#include <iostream>
using namespace std;

class ListArr  {
private:

struct Node {
    int* data;
    int isRes = 0;
    int tam = 0; //tamaño del array
    int space = 0; //espacios ocupados del array
    Node* next; //puntero al elemento siguiente para usar en el linked list
    Node* left = nullptr; //punteros a elementos "hijos" para hacer el arbol
    Node* right = nullptr;

    Node(int tam, Node* next = nullptr){
      this->data = new int[tam];
      this->tam = tam;
        
    }
    
    Node(Node* izq, Node*der){
      this->isRes = 1;
      this->tam=  (izq->tam)+(der->tam);
      this->space = (izq->space)+(der->space);
      this->left = izq;
      this->right = der;
      this->left->next = this->right;
      this->link(this->left,this->right);
    }
    
    ~Node(){
      delete next;
      delete left;
      delete right;
    }

    void updateSpace(){
      if(left->isRes == 0){
        space = left->space + right->space;
        tam = left->tam + right->tam;
      }
      else{
          left->updateSpace();
          right->updateSpace();
          space = left->space + right->space;
          tam = left->tam + right->tam;
        }
      }

    void link(Node* a, Node* b){
      if(a->isRes == 0){
        a->next = b;
      }
      else{
          Node* union1 = a;
          Node* union2 = b;
            while(union1->right != nullptr && union2->left !=nullptr){
            union1 = union1->right;
            union2 = union2->left;
           }
          union1->next = union2;
        }
      }

    Node* duplicate(){
        if(this->left->isRes == 0){
           Node* aux1 = new Node(this->left->tam);
           Node* aux2 = new Node(this->left->tam);
           Node* dup = new Node(aux1,aux2);
           return(dup);
        }
        else{
           Node* source_leftcopy = this->left->duplicate();
           Node* source_rightcopy = this->right->duplicate();
           Node* dup = new Node(source_leftcopy,source_rightcopy);
           dup->link(dup->left,dup->right);
          return(dup);
        } 
}

void exchange(Node*& tree, Node* newer){
   tree = newer;
}

};


public:
  int arsize = 0;
  int tam = 0; //tamaño del list array
  int ocupado = 0; //cuantos elementos hay en el listArray
  Node *root; //puntero al nodo resumen que esta mas arriba
  Node *head; // puntero al primer nodo con Array 


  ListArr(int arraysize);
  ~ListArr();
  virtual int size();
  virtual void insert_left(int v);
  virtual void insert_right(int v);
  virtual void insert(int v, int i);
  virtual void print();
  virtual bool find(int v);
};
#endif