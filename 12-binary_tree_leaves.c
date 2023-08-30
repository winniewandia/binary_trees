#include "binary_trees.h"

int tree_is_leaf(const binary_tree_t *node)
{
	int count = 0;

	if (node && !(node->left) && !(node->right))
		count = 1;
	return (count);
}
/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree: pointer to the root node of the tree to count the number of leaves
 *
 * Return: number of leaves and 0 if tree is NULL
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree_is_leaf(tree))
		return (1);
	return (binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right));
}
