#include "binary_trees.h"

/**
 * binary_tree_is_root - Function that checks if a given node is root
 * @node: is a pointer to the node to check
 * Return: 1 if node is a root, otherwise 0 If node is NULL, return 0
*/
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node != NULL)
	{
		if (node->parent == NULL)
			return (1);
		else
			return (0);
	}
	else
		return (0);
}
