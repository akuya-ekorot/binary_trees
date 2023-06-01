#include "../binary_trees.h"

bst_t *bst_search(bst_t *tree, int value)
{
	/* when you arrive to a null, no value was found, return null */
	if (!tree)
		return (NULL);

	/* when the value equals the node's value, return the node */
	if (tree->n == value)
		return (tree);

	/* if the value is less than node's value, recurse left */
	if (value < tree->n)
		return (bst_search(tree->left, value));

	/* if the value is greater than node's value, recurse right */
	return (bst_search(tree->right, value));
}
