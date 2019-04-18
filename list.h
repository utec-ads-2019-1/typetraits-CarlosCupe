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

            while(ptr) {
                if(ptr->data == search)
                    break;

                ptr = ptr->next;
            }

            pointer = &ptr;
            return ptr != nullptr;
        }
             
        bool insert(T data) {
            // TODO
            Node<T> **ptr;
            if(find(data, ptr))
                return;
            
            ptr = &head;

            Node<T> *temp = new Node<T>;
            temp->data = data;

            while(!cmp((*ptr)->data, (*ptr)->next->data)) {
                if((*ptr)->next == nullptr)
                    break;

                ptr = &(*ptr)->next;
            }
            temp->prev = (*ptr);
            temp->next = (*ptr)->next;
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