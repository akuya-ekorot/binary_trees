#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_height - finds the height of a binary tree
 * @tree: the tree to find the height
 *
 * Return: the height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left = 0, right = 0;

	/* if tree is NULL return 0 */
	if (!tree)
		return (0);

	/* if left recurse */
	if (tree->left)
		left = 1 + binary_tree_height(tree->left);

	/* if right recurse */
	if (tree->right)
		right = 1 + binary_tree_height(tree->right);

	return (left > right ? left : right);
}

/**
 * perfect - checks if a binary tree is perfect
 * @tree: the tree to check
 * @depth: the height of the full tree
 * @level: current leve of the tree
 *
 * Return: 0 if imperfect, 1 if perfect
 */
int perfect(const binary_tree_t *tree, size_t depth, size_t level)
{
	/* if you've reached a NULL node, it's perfect */
	if (!tree)
		return (1);

	/* check if tree has both children */
	if (tree->left && tree->right)
		return (
			perfect(tree->left, depth, level + 1) *
			perfect(tree->right, depth, level + 1)
		);

	/* if it's a leaf node, check if level == depth */
	if (!tree->left && !tree->right)
		return (depth == level);

	return (0);
}

/**
 * binary_tree_is_perfect - driver function to check if a tree is perfect
 * @tree: the tree to check if perfect
 *
 * Return: return 1 if perfect, 0 if imperfect and if tree is NULL, 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int height;

	/* if tree is NULL return 0 */
	if(!tree)
		return (0);

	/* find the height of the tree */
	height = binary_tree_height(tree);

	/* check if perfect */
	return (perfect(tree, height, 0));
}
