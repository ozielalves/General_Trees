# Left Child Right Sibling - C++/Python Representation

The current representation is about an general tree based on the use of nodes. The relation between the nodes is simple and the references are just two, each node can only refers to an "child" and an "sibling". In this especific case the tree will only insert an element as a sibling if the current "dad" have no more than 3 childs. More information over general tree implementations techniques can be founded [here](https://pdfs.semanticscholar.org/ba06/7c2a0efbe81c4f887d2a2d129e4dae9ede2a.pdf).

## How to compile

First of all, obviously this repository is needed to work as desired, so we must to download this repo. As we know that `git` is a tremendous tool for any programmer, then we must have git installed.

It is also expected for user to have installed [doxygen](https://en.wikipedia.org/wiki/Doxygen) program. This will automatically generate documentation for code. Not a necessary package to compile and run program, but it is a tool to guide user through code functions. To install `doxygen` on UBUNTU, for example:

```bash
$ sudo apt-get install doxygen
```
To compile we will use a makefile, so compilations may be more dynamic and automatic.
```bash
# Using 'git clone' to clone this repo into desired directory:
$ git clone https://github.com/ozielalves/General_Trees.git

# Enter repo:
$ cd General_Trees/LeftChildRightSibling

# To compile the whole project, insert 'make' inside of path's root:
$ make

# To generate file documentation, insert 'make docs' inside of path's root:
$ make docs

# To clean up all remaining trash data and files, such as the binary ones, insert 'make clean':
$ make clean
```

## How to execute

Now, we show how to run the program. 
```bash
# To execute program:
$ ./lcrs
```

### Example

```bash
$ ./lcrs
```
## GitHub Repository:

*https://github.com/ozielalves/General_Trees*



## Benefits

- This representation uses less memory, since it limits the number of references to at most two per node.

- Easy to code.

## Disadvantages

- Basic operations such as searching / inserting / deleting tend to take more time to find the appropriate element, because in the worst case it would be necessary to go through all the siblings of the node to apply some of these functions.


## Authorship

Program developed by [_Oziel Alves_](https://github.com/ozielalves) (*ozielalves@ufrn.edu.br*), 2018.2

&copy; IMD/UFRN 2018.
