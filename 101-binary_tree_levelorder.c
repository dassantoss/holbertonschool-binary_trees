#include "binary_trees.h"
#include <stdlib.h>

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
	const binary_tree_t *node = NULL;

	if (tree == NULL || func == NULL)
		return;

	queue = malloc(sizeof(queue_t));
	if (queue == NULL)
		return;

	queue->node = tree;
	queue->next = NULL;

	while (queue != NULL)
	{
		node = queue->node;
		func(node->n);

		if (node->left != NULL)
			enqueue(&queue, node->left);
		if (node->right != NULL)
			enqueue(&queue, node->right);

		dequeue(&queue);
	}

	free(queue);
}

/**
 * enqueue - Enqueues a node in the queue
 * @queue: Double pointer to the queue
 * @node: Pointer to the node to enqueue
 */
void enqueue(queue_t **queue, const binary_tree_t *node)
{
	queue_t *new_node = malloc(sizeof(queue_t));
	queue_t *last = *queue;

	if (new_node == NULL)
		return;

	new_node->node = node;
	new_node->next = NULL;

	if (*queue == NULL)
	{
		*queue = new_node;
		return;
	}

	while (last->next != NULL)
		last = last->next;

	last->next = new_node;
}

/**
 * dequeue - Dequeues the front node from the queue
 * @queue: Double pointer to the queue
 */
void dequeue(queue_t **queue)
{
	queue_t *temp = *queue;

	if (*queue == NULL)
		return;

	*queue = (*queue)->next;
	free(temp);
}
