#include "../include/leftChildRightSibling.hpp"
#include "../include/node.hpp"

int main( void ) {
    
    // Left child right sibling
    /*  10
    *    |
    *    2 -> 3 -> 4 -> 5
    *              |    |
    *              6    7 -> 8 -> 9  
    *
    * 10( 2( ) 3( ) 4( 6( )) 5( 7( ) 8( ) 9( )))%
    */

    Tree<int> *tree = new Tree<int>(10);

	tree->insert(2, 10);
	tree->insert(3, 10);
	tree->insert(4, 10);

	tree->insert(6, 4);
	tree->insert(12, 6);
	tree->insert(14, 12);

	tree->insert(5, 10);
	std::cout << " -- This Node should not be inserted.";

	tree->insert(7, 5);
	std::cout << " -- This Node should not be inserted.";
	tree->insert(8, 5);
	std::cout << " -- This Node should not be inserted.";
	tree->insert(9, 5);
	std::cout << " -- This Node should not be inserted.";

	tree->print();

	return 73120;
}
