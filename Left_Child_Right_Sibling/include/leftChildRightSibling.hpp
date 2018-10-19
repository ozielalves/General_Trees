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

   //      Node<T> *pushSibling(Node<T> *n, T value){
   //          if(n == NULL) return NULL;
            
			// while(n->sibling)
   //              n = n->sibling;

   //          return (n->sibling = new Node<T>(value));
   //      }

   //      Node<T> *pushChild(T value, Node<T> *n = NULL){
   //          if(n == NULL){
   //              if(this->root == NULL) return NULL;

   //              n = root;
   //          }

   //          // Se o nó já tiver um filho então adicionamos um irmão
   //          if(n->child)
   //              return pushSibling(n->child, value);

   //          return (n->child = new Node<T>(value));
   //      }

   //      void print(Node<T> *n = NULL){
   //          if(n == NULL){
   //              if(this->root == NULL) return;

   //              n = root;
   //          }

   //          while(n){
   //              std::cout << " " << n->value;
                
   //              if(n->child)
   //                  print(n->child);

   //              n = n->sibling;
   //          }

   //      }

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

        

		// Node<T> * searchSibling_node(Node<T> *sibling, T value) {

		// 	if (sibling->value == value) return sibling;
		// 	}else if (sibling->child != NULL and sibling->sibling == NULL){ /*child:1 sibling:0*/
		// 	    return searchChild_node(sibling->child, value);
		// 	}else if (sibling->child == NULL and sibling->sibling != NULL){ /*child:0 sibling:1*/
		// 	    return searchSibling_node(sibling->sibling, value);
		// 	}else if (sibling->child != NULL and sibling->sibling != NULL){ /*child:1 sibling:1*/
			
		// 		// 1 ) Search starts for the Siblings
		// 		auto siblings = searchSibling_node(sibling->sibling, value);

		// 		if (siblings != NULL)
		// 		{
		// 			return siblings;
		// 		}

		// 		// 2 ) Didn't find on sibling, search on Childs
		// 		return searchChild_node(sibling->child, value);
		// 	}


  //       	return NULL;   // Not founded

		// }

		// Node<T> * search_node(T value) {
		//     return this->searchChild_node(this->root, value);
		// }

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
					//node = NULL; // Supostamente deveria funcionar mas ainda é impresso
					*node = NULL; // Funciona, porém atribui "0" a node->value
				} else {
					*node = *node->sibling;
				}
			}
		}
};

#endif
