#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: a pointer to the node to measure depth
 *
 * Return: depth of the tree, if tree is NULL, return 0
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	/* base case: if tree is NULL or has no parent, return 0 */
	if (tree && tree->parent)
		depth = 1 + binary_tree_depth(tree->parent);

	return (depth);
}
