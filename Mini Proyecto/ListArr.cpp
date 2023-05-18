#include "ListArr.h"
#include <iostream>

using namespace std;

ListArr::ListArr(int capact){ 
	
	this->arsize = capact;
  this->tam = capact*2;

  Node* aux = new Node(capact);
  Node* aux2 = new Node(capact);
  
  aux->next = aux2;
  
  this->root = new Node(aux, aux2);
  this->head = aux;
  
}

ListArr::~ListArr(){
  delete root;
}

int ListArr::size(){
  return(root->space);
}

void ListArr::insert_left(int value){
  this->insert(value,0);
  
}

void ListArr::insert_right(int value){
  this->insert(value,this->ocupado);
}

void ListArr::insert(int v, int i){
  try {
  if( i < 0 || i > ocupado ) throw "fuera de limites del vector!";
    int original = i;
    Node* parent = root;
    //si no hay espacio, duplicamos el nodo raiz(root) en un nodo de igual dimencion, 
    //luego los ponemos como hijos de un nuevo nodo resumen , convertimos este nuevo resumen
    //en la nueva raiz del arbol binario y llamamos a insert otra vez,
    // pero ahora deberia de haber espacio suficiente
    if(this->ocupado==this->tam){
      Node* dup = this->root->duplicate();
      Node* newROOT = new Node(root,dup);
      this->root->exchange(this->root,newROOT);
      root->link(root->left, root->right);
      root->updateSpace();
      this->tam = root->tam;
      this->ocupado = root->space;
      insert(v, original); 
      //this->print();
      
    } 
    //Caso en que si haya espacio
    else{
    //Este while llega hasta el nodo e indice en donde se debe insertar el nuevo valor
    while(parent->left != nullptr && parent->right != nullptr){
      if( i >= parent->left->tam){
        i = i-parent->left->space;
        parent = parent->right;
      }
      else{
        parent = parent->left;
      }
    }
    //si el nodo tiene espacio, desplaza todos los elementos necesarios una posicion hacia adelante
    //e inserta el nuevo elemento en el indice adecuado
    if(parent->space < arsize){
			for (int j = 0; j < parent->space -i ; j++){
				parent->data[parent->space-j] = parent->data[parent->space-j-1];
			}
      
      parent->data[i] = v;
			parent->space++;
      root->updateSpace();
      this->ocupado = root->space;
      this->tam = root->tam; 
      
    }
    //esto es para el caso en que el nodo en que queremos insertar no tenga espacio suficiente para hacer la insercion;
    else {
      int isThereSpace = 0;
      Node* searchSpace = parent;
    
      while(searchSpace!=nullptr){
        if(searchSpace->next->space < searchSpace->next->tam ){
         isThereSpace = 1;
         break;
           }
        else{
          isThereSpace = 0;
          }
        searchSpace = searchSpace->next;
      }
      

      //Si hay espacio, guardamos el ultimo valor del array de nuestro nodo objetivo
      //desplazamos un espacio los int correspondientes e insertamos el nuevo valor en el indice adecuado
      //luego insertamos el valor que guardamos en el primer indice del nodo siguiente, si ese tambien esta
      //lleno procederia de forma recursiva;
      if(isThereSpace == 1){
         int aux = parent->data[parent->tam-1];

         for (int j = 0; j < arsize -i ; j++){
				  parent->data[parent->tam-j] = parent->data[parent->tam-j-1];
			    }
         parent->data[i] = v;
         root->updateSpace();
         this->ocupado = root->space;
         this->tam = root->tam;
         original = original-i+arsize;
         insert(aux , original);
      }
          
  }
    

    }

  }catch(const char* message){
        std::cerr << message << std::endl;
        exit(EXIT_FAILURE);
}
}





void ListArr::print(){

  Node *aux = head;
  while(aux->next != nullptr) {
    for(int i = 0; i<aux->space;++i){
      cout << " "  << aux->data[i];
    }
    aux = aux->next;
  } 
}

bool ListArr::find(int v){
  Node *aux = head;

  while(aux != nullptr) {
    for(int i = 0; i<aux->space;++i){
      if(aux->data[i]==v){
        return true;
       }
      }
      aux = aux->next;

    }
  return false;
 }