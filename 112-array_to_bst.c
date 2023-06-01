#include "binary_trees.h"

static bst_t *insert(bst_t *root, bst_t *node)
{
	if (node->n > root->n)
	{
		if (!root->right)
		{
			root->right = node;
			root->right->parent = root;
			return (node);
		}

		return (insert(root->right, node));
	}
	else if (node->n < root->n)
	{
		if (!root->left)
		{
			root->left = node;
			root->left->parent = root;
			return (node);
		}

		return (insert(root->left, node));
	}

	return (NULL);
}

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *node, *root;

	node = binary_tree_node(*tree, value);
	if (!node)
		return (NULL);

	if (!*tree)
		*tree = node;
	else
	{
		root = *tree;
		node = insert(root, node);
	}

	return (node);
}

/**
 * array_to_bst - builds a bst from an array
 * if the value of the array is already present, ignore the value
 * @array: array to build bst from
 * @size: the size of the array
 *
 * Return: pointer to the root node of the created bst, or NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t i = 0;
	bst_t *tree;

	tree = NULL;

	while (i < size)
		bst_insert(&tree, array[i++]);

	return (tree);
}
