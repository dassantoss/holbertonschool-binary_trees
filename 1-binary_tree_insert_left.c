#include "binary_trees.h"

/**
 * binary_tree_insert_left - function that inserts a node as
 * the left-child of another node
 * @parent:  is a pointer to the node to insert the left-child in
 * @value: is the value to store in the new node
 * Return: a pointer to the created node, or NULL on failure
 * or if parent is NULL
*/

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node, *old_left_child;

	if (parent != NULL)
	{
		old_left_child = parent->left;
		new_node = binary_tree_node(parent, value);

		if (new_node == NULL)
			return (NULL);

		parent->left = new_node;
		new_node->left = old_left_child;

		if (old_left_child != NULL)
			old_left_child->parent = new_node;

		return (new_node);
	}
	else
	{
		return (NULL);
	}
}
