#include "binary_trees.h"

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 *
 * Return: balance factor, if tree is NULL return 0
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left = 0, right = 0;

	/* base case: if tree is NULL return 0 */
	if (!tree)
		return (0);

	/* base case: if tree has a left, add one to left */
	if (tree->left)
		left += 1 + binary_tree_balance(tree->left);

	/* base case: if tree has a right, add one to right */
	if (tree->right)
		right += 1 + binary_tree_balance(tree->right);

	return (left - right);
}
