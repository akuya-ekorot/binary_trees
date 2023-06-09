#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 *
 * Return: return pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root;

	if (tree->right)
	{
		new_root = tree->right;

		if (new_root->left)
		{
			tree->right = new_root->left;
			tree->right->parent = tree->left;
		}
		else
		{
			tree->right = NULL;
		}

		new_root->left = tree;
		new_root->left->parent = new_root;
	}

	return (new_root);
}
