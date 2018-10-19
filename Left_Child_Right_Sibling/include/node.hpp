/**
 * @file node.hpp
 * @version 1.0
 * @since Out, 19. 
 * @date Out, 19.
 * @author Oziel Alves (ozielalves@ufrn.edu.br)
 * @title Node Prototype 
 */

#ifndef _NODE_HPP_
#define _NODE_HPP_
#include <iostream>
#include "node.hpp"

template <typename T>
class Node{
    public:
        T value;
        Node<T> *child;
        Node<T> *sibling;

        /**
         * @brief Node Constructor
         * @param value Node data
         */       
        Node<T>(T value){
            this->value   = value;
            this->child   = NULL;
            this->sibling = NULL;
        }

        Node<T>(){}
};

#endif
