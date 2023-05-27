#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

#include <stdlib.h>
#include <stdio.h>

/**
 * struct binary_tree_s - Binary tree node
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
*/

typedef struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
} binary_tree_t;

/**
 * struct queue_s - Queue node structure
 * @node: Pointer to the binary tree node
 * @next: Pointer to the next node in the queue
 */
typedef struct queue_s
{
    const binary_tree_t *node;
    struct queue_s *next;
} queue_t;


/*Binary Search Tree*/
typedef struct binary_tree_s bst_t;

/*AVL Tree*/
typedef struct binary_tree_s avl_t;

/*Max Binary Heap*/
typedef struct binary_tree_s heap_t;

/*Print function*/
void binary_tree_print(const binary_tree_t *);

/*Mandatory*/
/*0. Function that creates a binary tree node*/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);

/*1. function that inserts a node as the left-child of another node*/
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);

/*2. function that inserts a node as right-child of another node*/
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);

/*3. Function that deletes an entire binary tree*/
void binary_tree_delete(binary_tree_t *tree);

/*4. Function that checks if a node is leaf*/
int binary_tree_is_leaf(const binary_tree_t *node);

/*5. Function that checks if a given node is root*/
int binary_tree_is_root(const binary_tree_t *node);

/*6. Function that goes through a binary tree using pre order traversal*/
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));

/*7. function that goes through a binary tree using in-order traversal*/
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));

/*8. function that goes through a binary tree using post-order traversal*/
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));

/*9. function that measures the height of a binary tree*/
size_t binary_tree_height(const binary_tree_t *tree);

/*10. function that measures the depth of a node in a binary tree*/
size_t binary_tree_depth(const binary_tree_t *tree);

/*11. function that measures the size of a binary tree*/
size_t binary_tree_size(const binary_tree_t *tree);

/*12. function that counts the leaves in a binary tree*/
size_t binary_tree_leaves(const binary_tree_t *tree);

/*13. function that counts the nodes with at least 1 child in a binary tree*/
size_t binary_tree_nodes(const binary_tree_t *tree);

/*14. function that measures the balance factor of a binary tree*/
int binary_tree_balance(const binary_tree_t *tree);

/*15. function that checks if a binary tree is full*/
int binary_tree_is_full(const binary_tree_t *tree);

/*16. function that checks if a binary tree is perfect*/
int binary_tree_is_perfect(const binary_tree_t *tree);

/*17. function that finds the sibling of a node*/
binary_tree_t *binary_tree_sibling(binary_tree_t *node);

/*function that finds the uncle of a node*/
binary_tree_t *binary_tree_uncle(binary_tree_t *node);

/* Prototypes advanced */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second);
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));
int binary_tree_is_complete(const binary_tree_t *tree);
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);
int binary_tree_is_bst(const binary_tree_t *tree);
bst_t *bst_insert(bst_t **tree, int value);
bst_t *array_to_bst(int *array, size_t size);
bst_t *bst_search(const bst_t *tree, int value);
bst_t *bst_remove(bst_t *root, int value);
int binary_tree_is_avl(const binary_tree_t *tree);
avl_t *avl_insert(avl_t **tree, int value);

/*Others*/
void enqueue(queue_t **queue, const binary_tree_t *node);
void dequeue(queue_t **queue);

#endif
