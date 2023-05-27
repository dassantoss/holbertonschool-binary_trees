#include "binary_trees.h"
#include "queue.h"

/**
 * binary_tree_levelorder - Traverses a binary tree using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 *
 * Description: This function traverses the binary tree in level-order,
 * visiting each node at each level from left to right.
 * The `func` function is called for each visited node, passing the value
 * of the node as a parameter.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	queue_t *queue = NULL;

	if (tree == NULL || func == NULL)
		return;

	queue = queue_create();
	if (queue == NULL)
		return;

	queue_push(queue, (void *)tree);

	while (!queue_is_empty(queue))
	{
		const binary_tree_t *node = (binary_tree_t *)queue_pop(queue);

		func(node->n);

		if (node->left != NULL)
			queue_push(queue, (void *)node->left);
		if (node->right != NULL)
			queue_push(queue, (void *)node->right);
	}

	queue_delete(queue);
}
