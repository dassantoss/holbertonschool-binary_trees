#include "binary_trees.h"
#include "stdbool.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: A pointer to the root node of the tree to measure the size of
 *
 * Return: The size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: A pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (binary_tree_size(tree->left) == binary_tree_size(tree->right))
	{
		if (binary_tree_is_complete(tree->left) &&
			binary_tree_is_complete(tree->right))
			return (1);
		else if (binary_tree_is_complete(tree->left) &&
			!binary_tree_is_complete(tree->right))
			return (0);
	}
	else if (binary_tree_size(tree->left) == binary_tree_size(tree->right) + 1)
	{
		if (binary_tree_is_complete(tree->left) &&
			binary_tree_is_complete(tree->right))
			return (1);
	}

	return (0);
}
