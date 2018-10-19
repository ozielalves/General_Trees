/**
 * @file lefChildRightSibling.hpp
 * @version 1.0
 * @since Out, 19. 
 * @date Out, 19.
 * @author Oziel Alves (ozielalves@ufrn.edu.br)
 * @title Left Child Right Sibling Tree 
 */

#ifndef _LEFT_CHILD_RIGHT_SIBLING_HPP_
#define _LEFT_CHILD_RIGHT_SIBLING_HPP_
#include <iostream>
#include "node.hpp"

/**
 * @brief The Tree class prototype.
 */

template <typename T>
class Tree{
    public:
        T value;
        Node<T> * root;

        /**
         * @brief Node's Tree initilizer.
         * @param value Node's data.
         * @return The initialized Node.
         */
        Node<T> * initialize(T value){
            return(createNewNode(value));
        }

        /**
         * @brief New node's instaciation.
         * @param value New node's data.
         * @return The new Node
         */
        Node<T> * createNewNode(T value){
            auto * now = new Node<T>(value);
            now->sibling = now->child = NULL;
            now->value = value;

            return now;
       }

        /**
         * @brief Inserts an element into the tree based on an dad node.
         * @param value Value to be inserted.
         * @param dad  Dad node's data.
         * @return True if the insertion was successful and False otherwise.
         */
        bool insert(T value, T dad){
            int cotas = 0;
            auto * daddy = busca(dad); // Verifies if dad exists
            if (!daddy) return false;
            auto * son = createNewNode(value);
            auto * p = daddy->child;
            if (!p) daddy->child = son;
            else{
                while (p->sibling){
                    if (cotas == 3) {
                        std::cout << "\nChild limit exceeded to node" << dad<<", impossible to insert.";
                        return false;
                    } 
                    p = p->sibling;
                    cotas += 1;
                }
                p->sibling = son;
            }
            return true;
        }

        /**
         * @brief Prints an tree representation.
         * @param *root The tree to be printed.
         */
        void show(Node<T> *root = NULL){
            if (root == NULL) return;
            printf("%d (",root->value);
            auto * p = root->child;
            while (p) {
                show(p);
                p = p->child;
            }
            printf(" )"); 
        }       

        /**
         * @brief Search for an element in the tree.
         * @param value The element to be searched.
         * @return The element if it was founded and NULL otherwise.
         */
        Node<T> * busca(T value){
            if (this->root == NULL) return NULL;
            if (this->root->value == value) return root;
            auto * p = this->root->child;
            while (p) {
                auto * prox = busca(value);
                if (prox) return (prox);
                p = p->sibling;
            }
            return NULL;
        }

        //adoptive_remove

        /**
         * @brief Tree constructor.
         * @param value The new tree root.
         */
        Tree(T value){
            this->root = new Node<T>(value);
            this->root->sibling = this->root->child = NULL;
            this->root->value = value;
        }

        /**
         * @brief Calculate the tree height.
         * @param *n The tree.
         * @return The tree height
         */
        int height(Node<T> *n = NULL) { 
			if(n == NULL){
                if(this->root == NULL){ return 0; }

                n = root;
            }
 
            int h, t;

            if (n == NULL) return -1; 

            h = 0; //height
            n = n->child; 

            while (n!= NULL) {
                t = height(n); 
                if (t > h)  
                    h = t; 
                n = n->sibling; 
            } 

            return h+1; 
        }

        /**
         * @brief Removes an element from the tree.
         * @param value The element to be removed.
         */
		    void remove(T value){
          auto *node = this->busca(value);

          if(node == NULL){
            std::cout << "\nValor nao esta na Arvore\n";
          } else if(node == this->root) {
            this->root = NULL;
          } else {
            if(node->sibling == NULL) {
              *node = NULL;
				    } else {
            *node = *node->sibling;
				    }
          }
		    }
};

#endif
