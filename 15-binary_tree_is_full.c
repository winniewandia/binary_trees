#include "binary_trees.h"
/**
 * tree_is_leaf - checks if a node is a leaf
 * @node: node to be checked
 *
 * Return: 1 if node is a leaf otherwise 0
 */
int tree_is_leaf(const binary_tree_t *node)
{
	int count = 0;

	if (node && !(node->left) && !(node->right))
		count = 1;
	return (count);
}

/**
 * parent_is_full - checks if a node has 2 children
 * @node: node to be checked
 *
 * Return: 1 if node is full, otherwise 0
 */
int parent_is_full(const binary_tree_t *node)
{
	if (node && (node->left) && (node->right))
		return (1);
	return (0);
}
/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is full, otherwise 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree_is_leaf(tree))
		return (1);
	if (parent_is_full(tree))
	{
		return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));
	}
	return (0);
}
