#include "binary_trees.h"

/**
 * height - calculate the height of a tree
 * @node: node to calculate the height for
 *
 * Return: the height of the tree
 */
static int height(const binary_tree_t *node)
{
	int left, right;

	if (!node)
		return (0);

	left = height(node->left);
	right = height(node->right);

	return ((left > right) ? (left + 1) : (right + 1));
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 *
 * Return: balance factor, if tree is NULL return 0
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (height(tree->left) - height(tree->right));
}
