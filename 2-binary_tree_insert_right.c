#include "binary_trees.h"

/**
 * binary_tree_insert_right - function that inserts a node as
 * right-child of another node
 * @parent: is a pointer to the node to insert the right-child in
 * @value: is the value to store in the new node
 * Return: a pointer to the created node, or NULL on failure
 * or if parent is NULL
*/
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node, *old_right_child;

	if (parent == NULL)
		return (NULL);

	old_right_child = parent->right;

	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);

	parent->right = new_node;
	new_node->right = old_right_child;

	if (old_right_child != NULL)
		old_right_child->parent = new_node;

	return (new_node);
}
