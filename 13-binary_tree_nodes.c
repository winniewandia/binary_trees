#include "binary_trees.h"

/**
 * node_is_parent - Checks if a node is a parent
 * @node: node to be checked
 *
 * Return: 1 if node is parent otherwise 0
 */
int node_is_parent(const binary_tree_t *node)
{
	int count = 0;

	if (node && (node->left || node->right))
		count = 1;
	return (count);
}
/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
 * @tree: pointer to the root node of the tree to count the number of nodes
 *
 * Return: number of nodes with atleast 1 child and 0 if treenis NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (node_is_parent(tree))
		return (binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right) + 1);
	return (0);
}
