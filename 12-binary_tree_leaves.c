#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree: pointer to the root node of the tree
 *
 * Return: number of leaves, if tree is NULL return 0
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t right = 0, left = 0;

	/* base case: if tree is NULL return 0 */
	if (!tree)
		return (0);

	/* base case: if tree has no children, it's a leaf. Return 1 */
	if (!(tree->left || tree->right))
		return (1);

	/* recurse if left */
	if (tree->left)
		left += binary_tree_leaves(tree->left);

	/* recurse if right */
	if (tree->right)
		right += binary_tree_leaves(tree->right);

	return (left + right);
}
