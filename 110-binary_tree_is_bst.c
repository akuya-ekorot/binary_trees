#include "binary_trees.h"

/**
 * is_bst - recursively check if t is bst
 * @r: value of root node
 * @t: tree to check
 *
 * Return: 1 if bst, 0 otherwise
 */
int is_bst(int r, const binary_tree_t *t)
{
	int left = 0, right = 0;

	if (!t || !(t->left && t->right))
		return (1);

	/* figure out whether we're on the right side or left side of the root */
	if (t->n > r)
	{
		if (t->left && t->left->n <= t->n && t->left->n > r)
			left = 1 && binary_tree_is_bst(t->left);

		if (t->right && t->right->n > t->n)
			right = 1 && binary_tree_is_bst(t->right);
	}
	else
	{
		if (t->left && t->left->n <= t->n)
			left = 1 && binary_tree_is_bst(t->left);

		if (t->right && t->right->n > t->n && t->right->n <= r)
			right = 1 && binary_tree_is_bst(t->right);
	}

	return (left && right);
}

/**
 * binary_tree_is_bst - checks if a binary tree is a bst
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is valid bst, 0 otherwise. 0 if tree is NULL
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (is_bst(tree->n, tree->left) && is_bst(tree->n, tree->right));
}
