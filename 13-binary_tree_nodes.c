#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
 * @tree: pointer to the tree to count from
 * Return: count or 0 if tree is null
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t count = 0;

	if (tree && (tree->left || tree->right))
	{
		if (!tree->parent)
			count = 1;
		count += binary_tree_nodes(tree->left ? tree->left : tree->right);
		return (count + 1);
	}
	return (0);
}
