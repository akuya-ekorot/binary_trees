#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts node to the right of a parent node
 * @parent: the parent node
 * @value: the value for the n member of the node
 *
 * Return: pointer to the created node, or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *right;

	if (!parent)
		return (NULL);

	right = binary_tree_node(parent, value);
	if (!right)
		return (NULL);

	if (parent->right)
	{
		right->right = parent->right;
		right->right->parent = right;
		parent->right = right;
	}
	else
	{
		parent->right = right;
	}

	return (right);
}
