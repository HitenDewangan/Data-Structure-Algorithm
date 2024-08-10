class Node:
    def __init__(self, data, left=None, right=None, parent=None):
        self.data = data
        self.left = None
        self.right = None
        self.parent = None

    def __str__(self):
            return str(self.data)
    
    #======== P R I N T  T R E E ========
    def printTree(node):
        if(node is None):
            return

        print(node.data, end=" ")
        if node.left:
            node.left.printTree()
        if node.right:
            node.right.printTree()


    #======== I N S E R T I O N ========
    def insertNode(root, data):
        if root.left is None:
            root.left = Node(data)
            return
        elif root.right is None:
            root.right = Node(data)
            return
        else:
            if root.getTreeSize(root.left) <= root.getTreeSize(root.right):
                root.left.insertNode(data)
            else:
                root.right.insertNode(data)
    
    #======== G E T  T R E E  S I Z E ========
    def getTreeSize(self, node):
        if node is None:
            return 0
        return 1 + root.getTreeSize(node.left) + root.getTreeSize(node.right)

#===================================== T R A V E R S A L ====================================
    # ======== P R E O R D E R ======== node - left - right
    def preorder(node):
        if node is None:
            return
        print(node.data, end=" ")
        if node.left:
            node.left.preorder()
        if node.right:
            node.right.preorder()

    # ======== I N O R D E R ======== left - node - right
    def inorder(node):
        if node is None:
            return
        if node.left:
            node.left.inorder()
        print(node.data, end=" ")
        if node.right:
            node.right.inorder()

    # ======== P O S T O R D E R ======== left - right - node
    def postorder(node):
        if node is None:
            return
        if node.left:
            node.left.postorder()
        if node.right:
            node.right.postorder()
        print(node.data, end=" ")
    
    # =========================================================================================

    #==================== S E A R C H =====================
    def search(self, node, data):
        if node is None:
            return False
        if node.data == data:
            return True
        elif node.data > data:
            return self.search(node.left, data)
        else:
            return self.search(node.right, data)

    # ================ H E I G H T ==============
    def getHeight(self, node):
        # if node is None:
        #     return 0
        # return 1 + max(self.getHeight(node.left), self.getHeight(node.right))
        if node is None :
            return -1
        
        if(node.left is None and node.right is None):
            return 0
        
        left, right = 0, 0
        if(node.left != None):
            left = self.getHeight(node.left)

        if(node.right != None):
            right = self.getHeight(node.right)

        return 1 + max(left, right) 
    
    # ================ Diameter ============== max distance between any 2 nodes -----(leaf, leaf) or (leaf, root)
    def getDiameter(self, node):
       
        dia = 0
        if node is None:
            return 0
        # print("The dia node is : ", node)
        l,r = 0, 0
        if node.left is not None :
            l = self.getHeight(node.left)
        if node.right is not None :
            r= self.getHeight(node.right)
        
        if l!=0 and r!=0 :
            # print("asdfa")
            dia =  max(dia, l+r+2)
        elif l!=0 or r!=0 :
            dia  = max(dia, l+r+1)



        # print("node = {node}, dia = {dia}, leftHeight = {l}, righrtHeight = {r}".format(node=node, dia=dia, l = l, r = r))
        # return dia+2
        return max(max(self.getDiameter(node.left), self.getDiameter(node.right)), dia)
    




# =================================== M Y  T R E E ===================================
root = Node(1)
# childs of root
node1 = Node(2, parent=root)
root.left = node1
node2 = Node(3, parent=root)
root.right = node2
# childs of node 1
node3 = Node(4, parent=node1)
node1.left = node3
node4 = Node(5, parent=node1)
node1.right = node4
# childs of node 2
node5 = Node(6, parent=node2)
node2.left = node5
node6 = Node(7, parent=node2)
node2.right = node6

print(root.left, root.right)
print(node1.data)
print(node1.left.data, node1.right.data)

print(root)
print(node1)
print(node6, node6.left, node6.right)

root.printTree()
print()
# node1.printTree()
# node6.printTree()

root.preorder()
print()
root.inorder()
print()
root.postorder()

root.insertNode(11)
print()
root.printTree()

root.insertNode(12)
root.insertNode(13)
root.insertNode(14)
print()
root.printTree()

print()
print("Height of the tree is: ", root.getHeight(root))
print("Diameter of the tree is: ", root.getDiameter(root))

root.insertNode(15)
print()
root.printTree()
print()
print("Height of the tree is: ", root.getHeight(root))
print("Diameter of the tree is: ", root.getDiameter(root))