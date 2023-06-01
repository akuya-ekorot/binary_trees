#include "binary_trees.h"

/**
 * is_bst - recursively check if t is bst
 * @r: value of root node
 * @t: tree to check
 *
 * Return: 1 if bst, 0 otherwise
 */
static int is_bst(int r, const binary_tree_t *t)
{
	int left = 0, right = 0;

	if (!t || !(t->left && t->right))
		return (1);
	if (t->n > r)
	{
		if (t->left && t->left->n <= t->n && t->left->n > r)
			left = 1 && is_bst(r, t->left);
		if (t->right && t->right->n > t->n)
			right = 1 && is_bst(r, t->right);
	}
	else
	{
		if (t->left && t->left->n <= t->n)
			left = 1 && is_bst(r, t->left);
		if (t->right && t->right->n > t->n && t->right->n <= r)
			right = 1 && is_bst(r, t->right);
	}
	return (left && right);
}

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
 * is_balanced - recursively checks if t is balanced
 * @t: the tree to check
 *
 * Return: 1 if balanced, 0 otherwise
 */
static int is_balanced(const binary_tree_t *t)
{
	int h;

	if (!t)
		return (1);

	h = height(t->left) - height(t->right);

	if (h < -1 || h > 1)
		return (0);

	return (is_balanced(t->left) && is_balanced(t->right));
}

/**
 * binary_tree_is_avl - checks if a binary tree is an avl tree
 * @tree: the tree to check
 *
 * Return: 1 if avl, 0 otherwise, if tree is NULL return 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int bst = 0, avl = 0;

	if (!tree)
		return (0);

	if (tree->left->n <= tree->n && tree->right->n > tree->n)
		bst = is_bst(tree->n, tree->left) && is_bst(tree->n, tree->right);

	avl = is_balanced(tree);

	return (bst && avl);
}
