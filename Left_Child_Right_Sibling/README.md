# Left Child Right Sibling - C++/Python Representation

It is a different representation of an arity tree n that consists of using two references, one for the first child and one for the first brother on the right, instead of using an array to armezenar the references of all the nodes.

## Benefits

- This representation uses less memory, since it limits the number of references to at most two per node.

- Easy to code.

## Disadvantages

- Basic operations such as searching / inserting / deleting tend to take more time to find the appropriate element, because in the worst case it would be necessary to go through all the siblings of the node to apply some of these functions.




*Obs.: The python representation still have to be better adapted, since the code was first made in c++.*

## Authorship

Program developed by [_Oziel Alves_](https://github.com/ozielalves) (*ozielalves@ufrn.edu.br*), 2018.2

&copy; IMD/UFRN 2018.
