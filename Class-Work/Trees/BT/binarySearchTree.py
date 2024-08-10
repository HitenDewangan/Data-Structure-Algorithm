class Node:
    def __init__(self, data, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right

    def __str__(self):
        return str(self.data)
        
class BST(Node):
    def __init__(self):
        self.root = None
        self.size = 0

    def __str__(self):
        return str(self.root)
    
    # ============================= T R A V E R S A L =============================

    # ============== printing ==============
    def printTree(self):  
        self.inorder(self.root)

    # ============== inorder traversal ==============
    def inorder(self, node):
        if node is None:
            return
        if node.left:
            self.inorder(node.left)
        print(node.data, end=" ")
        if node.right:
            self.inorder(node.right)
    
    # ============================================================================

    # ================== I N S E R T I N G =================
    # helper function
    def insert2(self, root, data):
        if root is None:    # if root is None
            # root = Node(data)    # return Node(data)
            self.size += 1
            return Node(data)
        if(data == root.data):
            return root
        else:
            if data < root.data:
                root.left = self.insert2(root.left, data)
            else:
                root.right = self.insert2(root.right, data)
            return root
        # self.size += 1

    # main function
    def insert(self, data):
        self.root = self.insert2(self.root, data)

    # ================== R E M O V I N G =================
    # main function
    def remove(self, data):
        self.root = self.remove2(self.root, data)
    
    # helper function
    def remove2(self, root, data):
        if root is None:
            return root

        if data == root.data:
            if root.left is None and root.right is None:   # if have no child
                root = None
                # update size
                root.size = self.size-1
                return root
            
            # if have only one child
            if root.left is None:
                temp = root.right    # store the right node
                root = None
                root.size = self.size-1
                return temp    # return the right node

            if root.right is None:
                temp = root.left    # store the left node
                root = None
                self.size = self.size-1
                return temp    # return the left node
            
        
        if data < root.data:
            root.left = self.remove2(root.left, data)
            return root
        elif data > root.data:
            root.right = self.remove2(root.right, data)
            return root
        else:                            # if have both left and right node
            succ = root.left
            while(succ.right is not None):
                succ = succ.right
            root.data = succ.data
            root.left = self.remove2(root.left, succ.data)
            return root

    # ================== F I N D I N G =================
    def tofind(self,data):
        return self.find(data,self.root)

    def find(self, value, node ):
        if node is None:
            return False
        if node.data == value:
            return True
        if value < node.data:
            return self.find(value, node.left)
        else:
            return self.find(value, node.right)

# =========================================== M A I N ===========================================
new_node = Node(13)
print(new_node, new_node.left, new_node.right)

# ============== BST ==============
root = BST()
root.insert(13)
root.printTree()
root.insert(12)  # Call the BST's insert method
root.insert(14)
root.insert(10)
root.insert(11)

print("Tree after insertion:")
root.printTree() # Print the tree using the in-order traversal

print()
print("Size of the tree: ", root.size)

root.remove(12)
print("Tree after deletion:")
root.printTree() # Print the tree using the in-order traversal

print()
print("Finding 11 in BST: ",root.tofind(12))