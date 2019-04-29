#ifndef LIST_H
#define LIST_H

#include "node.h"
#include <algorithm>
#include <iostream>

template <typename Tr>
class List {     
    public:
        typedef typename Tr::T T;
        typedef typename Tr::Operation Operation;
      
    private:
        Node<T>* head;
        Operation cmp;
              
    public:
        List() : head(nullptr) {};

        bool find(T search, Node<T> **&pointer) {
            // TODO
            if (this->head == nullptr)
                return false;

            Node<T> *ptr = this->head;
            
            pointer = &(this->head);
            
            // El bucle no es necesario de manejar de esta manera
            while(cmp(ptr->data, search)) {
                // Para qué sirve este if?
                if (ptr != this->head)
                    pointer = &((*pointer)->next);
                
                ptr = ptr->next;
                if (ptr == nullptr)
                    return (*pointer)->data == search;
            }

            // Aquí estás agregando código de más
            if (*pointer)
                return (*pointer)->data == search;
            else
                return false;
        }
             
        bool insert(T data) {
            // TODO
            Node<T> **ptr;
            
            if(find(data, ptr))
                return false;

            Node<T> *temp = new Node<T>(data);

            // El código abajo debería poder simplificarse bastante
            if (this->head == nullptr) {
                this->head = temp;
                return true;
            }

            if (*ptr == nullptr) {
                temp->next = this->head;
                this->head = temp;
                return true;
            }

            temp->next = (*ptr)->next;           
            (*ptr)->next = temp;

            return true;
        }
             
        bool remove(T item) {
            // TODO
            Node<T> **ptr;
            if(!find(item, ptr))
                return false;
            
            // Lo mismo que el insert
            if (*ptr == nullptr) {
                ptr = &(this->head);
                this->head = (*ptr)->next;
                delete *ptr;
                return true;
            }
            
            Node<T> *ptr_1 = (*ptr);
            *ptr = (*ptr)->next;

            delete ptr_1;
            return true;
        }  
             
        int size() {
            // TODO
            int count = 0;
            
            for (Node<T> *ptr = this->head; ptr != nullptr; ptr = ptr->next) {
                count++;
            }
            return count;
        }

        T operator[](int index) {
            // TODO            
            Node<T> *ptr = this->head;
            
            while(index--) {
                ptr = ptr->next;
            }

            return ptr->data;
        }

        ~List() {
            // Falta controlar cuando head es null cuando la lista esta vacía
            this->head->killSelf();
        }         
};

#endif
