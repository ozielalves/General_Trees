
# coding: utf-8

# In[6]:


class Node:
    def __init__(self,value):
        self.left = None
        self.right = None
        self.data = value
        self.daddy = None


# In[7]:


class Node:
    def __init__(self,value):
        self.Child = None # Left Child
        self.Sibling = None # Right Sibling
        self.data = value # Key


# In[14]:


class Tree:
    root = None
    
    def createNode(self, data):
        return Node(data)
    
    def LCRS(value):
        self.root = self.createNode(value)
        self.root.Sibling = self.root.Child = None
    
    def pushChild(self, value): # Self should be setted as None
        if(self == None):
            if(self.root == None):
                return None
            self = root
        if(self.Child):
            return pushSibling(self.Child, value)
        return self.Child.createNode(value)
    
    def pushSibling(self, value):
        if(self == None):
            return None
        while(self.Sibling):
            self = self.Sibling
        return(self.Sibling.createNode(value))
    
    def print(self):
        if(self == None):
            if(self.root == None):
                return
            self = root
        while(self):
            print(" ",self.value)
            if(self.Child):
                print(self.Child)
            self = self.Sibling
    
    def height(self):
        if(self == None)


# In[2]:


class Tree:
    def createNode(self, data):
        return Node(data)
    
    def insert(self, node, data): # DUPLICATE keys are not allowed
        if node is None: # If tree is empty, return a root node
            return self.createNode(data)
        if data < node.data:
            node.left = self.insert(node.left, data)
        elif data > node.data:
            node.right = self.insert(node.right, data)
            
        return node
    
    def search(self, node, data):
        if node is Node or node.data == data:
            return  node
        if node.data < data:
            return self.search(node.right, data)
        else: 
            return self.search(node.left, data)
    
    def deleteNode(self, node, data):
        
        if node is None:
            return None
        if data < node.data:
            node.left = self.deleteNode(node.left, data)
        elif data >node.data:
            node.right = self = self.deleteNode(node.right, data)
        else:
            if node.left is None and node.right is None:
                del node
            if node.left == None:
                temp = node.right
                del node
                return temp
            elif node.right == None:
                temp = node.left
                del node
                return temp
        
        return node
    
    def traverse_in_order(self, root): # Prints all the nodes in the tree
        if root is not None:
            self.traverse_in_order(root.left)
            print(root.data)
            self.traverse_in_order(root.right)
    
    def traverse_pre_order(self, root): # Prints all the nodes in the tree
        if root is not None:
            print(root.data)
            self.traverse_pre_order(root.left)
            self.traverse_pre_order(root.right)
            
    def traverse_post_order(self, root): # Prints all the nodes in the tree
        if root is not None:
            self.traverse_post_order(root.left)
            self.traverse_post_order(root.right)
            print(root.data)


# In[25]:


def main():
    root = None
    tree = Tree()
    root = tree.insert(root, 10)
    print(root)
    tree.insert(root, 20)
    tree.insert(root, 30)
    tree.insert(root, 40)
    tree.insert(root, 70)
    tree.insert(root, 60)
    tree.insert(root, 80)

    print("Traverse Inorder")
    tree.traverse_in_order(root)

    print("Traverse Preorder")
    tree.traverse_pre_order(root)

    print("Traverse Postorder")
    tree.traverse_post_order(root)

if __name__ == "__main__":
    main()

