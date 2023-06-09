#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: tree to be measured
 * Return: size of the tree, 0 is tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (!tree)
		return (0);
	if (tree)
	{
		size += binary_tree_size(tree->left);
		size += binary_tree_size(tree->right);
	}
	return (size + 1);
}
