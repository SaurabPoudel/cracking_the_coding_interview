
### Binary Tree Traversal

## BFS and DFS

Inorder to solve a binary trees question, we first need to traverse them. We have two technique of traversal in binary tree viz. Breadth-First Search technique and Depth-First Search technique.

First of all lets first understand the concept of Depth-First search for this tree. And at last, we will also solve a traversal challenge.

![binary tree](binarytree.png)

## DFS - (Depth First Search)

There are basically three types of depth first search technique. 

- Inorder Traversal (Left-Root-Right)
  
  Order for the traversal: 5 2 6 4 9 3 11 

- Preorder Traversal (Root-Left-Right)
  
  Order of the traversal: 4 2 5 6 3 9 11

- Postorder Traversal (Left-Right-Root)
  
  Order of the traversal: 5 6  2 9 11 3 4 

### How to remember DFS traversal sequence ?

To remember dfs sequence we have a little trick. 
> In (root in the middle )
> Pre (root in the beginning)
  >Post (root at the last)
>and left always comes before right

## BFS

Breadth First Search sequence is easy to remember.

For the given binary tree the sequence is :

4 2 3 5 6 9 11

> left->right

