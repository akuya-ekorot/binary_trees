#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_levelorder - goes through the binary tree using level-order
 * traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	const binary_tree_t **q, *current;
	int front = 0, rear = 0;

	if (tree && func)
	{
		q = (const binary_tree_t **)malloc(sizeof(binary_tree_t *) * 1024);
		q[rear++] = tree;

		while (front < rear)
		{
			current = q[front++];
			func(current->n);

			if (current->left)
				q[rear++] = current->left;

			if (current->right)
				q[rear++] = current->right;
		}

		free(q);
	}
}
