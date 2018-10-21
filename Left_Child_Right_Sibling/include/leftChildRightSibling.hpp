/**
 * @file lefChildRightSibling.hpp
 * @version 1.0
 * @since Out, 19. 
 * @date Out, 20.
 * @author Oziel Alves (ozielalves@ufrn.edu.br)
 * @title Left Child Right Sibling Tree 
 */

#ifndef _LEFT_CHILD_RIGHT_SIBLING_HPP_
#define _LEFT_CHILD_RIGHT_SIBLING_HPP_
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include "node.hpp"

using namespace std;

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
            auto * daddy = search(dad); // Verifies if dad exists.
            if (!daddy){
              std::cout << "\n>> The chosen dad was not founded.";
              return false;
            }
            auto * son = createNewNode(value); 
            auto * p = daddy->child;
            if (!p) {
              daddy->child = son;
            } else {
                daddy->cota = 1;
                while (p->sibling){
                  daddy->cota += 1; 
                  p = p->sibling;
                }
                if (daddy->cota == 3) {
                  std::cout << "\n>> 'Children' limit exceeded to the node " << dad <<", impossible to insert.";
                  daddy->cota = 0;
                  return false;
                } else {
                  daddy->cota = 0;
                  p->sibling = son;
                }
            }
            std::cout<< "\n>> The element was inserted.";
            return true;
        }

        /**
         * @brief Prints an tree representation.
         * @param *root The tree to be printed.
         */
        void show(Node<T> *root /*= NULL*/){
            if (root == NULL) return;
            printf("%d(",root->value);
            auto * p = root->child;
            while (p) {
                show(p);
                p = p->sibling;
            }
            printf(" )"); 
        }

        void print(){
          std::cout << "\n\n";
          show(this->root);
        }      

        /**
         * @brief Search for an element in the tree.
         * @param value The element to be searched.
         * @return The element if it was founded and NULL otherwise.
         */
        Node<T> * busca(T value, Node<T> * node){
            if (this->root == NULL) return NULL;
            if (this->root->value == value) return root;
            if (node->value == value) return node; 
            auto * p = node->child;
            while (p) {
                auto * prox = busca(value, p);
                if (prox) return (prox);
                p = p->sibling;
            }
            return NULL;
        }

        Node<T> * search(T value){
            return busca(value, this->root);
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

        ~Tree(){
          delete this->root;
        }

        /**
         * @brief Calculate the tree height in a Binary vision.
         * @param *n The tree.
         * @return The tree height
         */
        int height(Node<T> *n = NULL) { 
          if(n == NULL){
            if(this->root == NULL) return 0; 
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


        // int diameter(Node<T> *root = NULL) { 
        //   // Base case 
        //   if (!root) return 0; 
        //   // Find top two highest children 
        //   int max1 = 0, max2 = 0; 
        //   for (vector<Node*>::iterator it = root->child.begin(); 
        //                   it != root->child.end(); it++){ 
        //     int h = depthOfTree(*it); 
        //     if (h > max1) 
        //     max2 = max1, max1 = h; 
        //     else if (h > max2) 
        //     max2 = h; 
        //   } 
        //   // Iterate over each child for diameter 
        //   int maxChildDia = 0; 
        //   for (vector<Node*>::iterator it = root->child.begin(); 
        //                    it != root->child.end(); it++) 
        //     maxChildDia = max(maxChildDia, diameter(*it)); 
  
        //   return max(maxChildDia, max1 + max2 + 1); 
        // } 

        /**
         * @brief Removes an element from the tree.
         * @param value The element to be removed.
         */
		    void remove(T value){
          auto *node = search(value);

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
