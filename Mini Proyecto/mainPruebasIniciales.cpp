/*#include <iostream>
#include <algorithm>
#include "ListArr.h"
#include <chrono>
#include <fstream>
using namespace std;
int main() {

ListArr test(4);
for(int i = 0; i<20 ; i++){
  test.insert_left(i);
    cout << "inserted "  << test.head->data[0] <<endl;
  //cout << "total "  << test.size() <<endl;
  
}


//cout << "total "  << test.size() <<endl;
test.print();


//ESTO ES PARA PROBAR SI EL METODO duplicar() DE LOS NODOS FUNCIONA
/*
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
      }
      else{
          left->updateSpace();
          right->updateSpace();
          space = left->space + right->space;
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

void exchange(Node** tree, Node* newer){
   *tree = newer;

}
};


Node*aux1 = new Node(5);
Node* aux2 = new Node(5);
aux1->data[0]= 9;
Node* testp1 = new Node(aux1, aux2);

Node*aux3 = new Node(6);
Node* aux4 = new Node(6);
aux3->data[0]=10;
Node* testp2 = new Node(aux3,aux4);

cout << " "  << testp1->left->data[0]<<  endl;
testp2->exchange(&testp1,testp2);
cout << " "  << testp1->left->data[0]<<  endl;
*/
/*Funcionalidad de funcion link
ultimate->left->right->data[0]=72;
ultimate->left->right->next->data[0]=27;
ultimate->left->next->right->data[0]=711;
cout << " "  << ultimate->left->right->data[0]<<  endl;
cout << " "  << ultimate->right->left->data[0]<<  endl;
cout << " "  << ultimate->right->right->data[0]<<  endl;
*/

/*
for(int i = 0; i<5; i++){
    testp1->left->left->data[i]=i;
  }

  for(int i = 0; i<5; i++){
    testp1->left->left->next->data[i]=i;
  }
  for(int i = 0; i<5; i++){
    testp1->left->left->next->next->data[i]=i;
  }
  for(int i = 0; i<5; i++){
    testp1->left->left->next->next->next->data[i]=i;
  }

Node* potter2 = aux1;
while(potter2->next != nullptr) {
    for(int i = 0; i< 5;++i){
      cout << " "  << potter2->data[i]<<  endl;
    }
    potter2 = potter2->next;
  } 
  return(0);
}*/