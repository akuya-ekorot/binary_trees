#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
 * @tree: pointer to the tree to count from
 * Return: count or 0 if tree is null
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t left = 0, right = 0;

	if (!tree)
		return (0);

	if (!(tree->left || tree->right))
		return (0);

	if (tree->left)
		left += binary_tree_nodes(tree->left);

	if (tree->right)
		right += binary_tree_nodes(tree->left);

	return (left + right + 1);
}
