#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: height of the tree, or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (!tree || (!tree->left && !tree->right))
		return (0);

	/* recursively calculate the height of the left subtree */
	left_height = binary_tree_height(tree->left);

	/* recursively calculate the height of the right subtree */
	right_height = binary_tree_height(tree->right);

	/**
	 * return the maximum height of the left and right subtrees,
	 * plus 1 for the root node
	 */
	return ((left_height > right_height ? left_height : right_height) + 1);
}
