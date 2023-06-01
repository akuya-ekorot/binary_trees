#include "binary_trees.h"

void one_or_none(bst_t *node, bst_t *root)
{
	if (node->left)
	{
		if (node->parent->left == node)
		{
			node->parent->left = node->left;
			node->left->parent = node->parent;
		}

		if (node->parent->right == node)
		{
			node->parent->right = node->left;
			node->left->parent = node->parent;
		}

		if (node == root)
			root = node->left;
	}

	if (node->right)
	{
		if (node->parent->left == node)
			node->parent->left = node->right;

		if (node->parent->right == node)
			node->parent->right = node->right;

		if (node == root)
			root = node->right;
	}
}

/**
 * both_children - removes node if node has two children
 */
void both_children(bst_t *node, bst_t *root)
{
	bst_t *left_most;

	left_most = node->right;

	while (left_most->left)
		left_most = left_most->left;

	left_most->parent->left = NULL;

	if (!node->parent)
		left_most->parent = NULL;
	else
	{
		left_most->parent = node->parent;

		if (node->parent->left == node)
			node->parent->left = left_most;

		if (node->parent->right == node)
			node->parent->right = left_most;
	}

	left_most->right = node->right;
	left_most->left = node->left;

	if (node == root)
		root = left_most;
}

/**
 * bst_remove - removes a node from a binary search tree
 * If the node to be delted has two children, it must be replaced with its
 * first in-order successor (not predecessor)
 * @root: pointer to the root node of the tree
 * @value: the value to remove in the tree
 *
 * Return: a pointer to the new root node of the tree
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node;

	node = bst_search(root, value);

	if ((node->left && node->right))
		both_children(node, root);
	else
		one_or_none(node, root);

	return (root);
}
