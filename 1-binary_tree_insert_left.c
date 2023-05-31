#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a left node to the parent node
 * @parent: parent node
 * @value: value of the left node
 *
 * Return: a pointer to the created node, or NULL on
 * failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *left;

	if (!parent)
		return (NULL);

	left = binary_tree_node(parent, value);
	if (!left)
		return (NULL);

	if (!parent->left)
	{
		parent->left = left;
	}
	else
	{
		left->left = parent->left;
		parent->left = left;
		left->left->parent = left;
	}

	return (left);
}
