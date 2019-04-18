#ifndef LIST_H
#define LIST_H

#include "node.h"
#include <algorithm>

template <typename Tr>
class List {     
    public:
        typedef typename Tr::T T;
        typedef typename Tr::Operation Operation;
      
    private:
        Node<T>* head;
        Operation cmp;
        int nodes;
              
    public:
        List() : head(nullptr) {};

        bool find(T search, Node<T> **&pointer) {
            // TODO
            Node<T> *ptr = this->head;

            while(!cmp(ptr->data, search) {
                ptr = ptr->next;
                
                if(ptr == nullptr)
                    break;
            }

            pointer = &(ptr->prev);
            return ptr->prev->data == data;
        }
             
        bool insert(T data) {
            // TODO
            Node<T> **ptr;
            if(find(data, ptr))
                return;
            
            Node<T> *temp = new Node<T>;
            temp->data = data;
            
            temp->prev = (*ptr);
            temp->next = (*ptr)->next;
            
            if ((*ptr)->next)
                (*ptr)->next->prev = temp;
            (*ptr)->next = temp;

            this->nodes++;
        }
             
        bool remove(T item) {
            // TODO

            Node<T> **ptr, *ptr_1;
            if(!find(data, ptr))
                return;
            
            ptr_1 = &(*ptr)->prev;
            ptr_1->next = &(*ptr)->next;
            ptr_1 = &(*ptr)->next;
            ptr_1->prev = &(*ptr)->prev;

            delete *ptr;
            this->nodes--;
        }  
             
        int size() {
            // TODO
            return this->nodes;
        }

        T operator[](int index) {
            // TODO
            Node<T> *ptr = this->head;

            while(ptr && index--) {
                ptr = ptr->next;
            }

            return ptr->data;
        }

        ~List() {
            // TODO
        }         
};

#endif