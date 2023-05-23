#include "binary_trees.h"

/**
 * binary_tree_depth - function that measures the deph
 * of a node in a binary tree
 * @tree:  is a pointer to the node to measure the depth
 * Return: Deph of the node or If tree is NULL return 0
*/
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (tree == NULL)
		return (0);

	while (tree->parent != NULL)
	{
		depth++;
		tree = tree->parent;
	}

	return (depth);
}
