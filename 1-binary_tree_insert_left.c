#include <stdio.h>
#include "binary_tree.h"

/**
 * binary_tree_insert_left - inserts a left node to the parent node
 * @parent: parent node
 * @value: value of the left node
 * 
 * Return: a pointer to the created node, or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
    if (!parent)
        return (NULL);
    
    new_node = malloc(sizeof binary_tree_t);
    if (!new_node)
        return (NULL);
    
    new_node->n = value;
    new_node->parent = parent;
    new_node->left = NULL;
    new_node->right = NULL;
    parent->left = new_node;

    return (new_node);
}