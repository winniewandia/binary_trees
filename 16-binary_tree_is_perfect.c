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
 * height - measures the height of a binary tree
 * @tree: a pointer to the root node of the tree to measure the height
 *
 * Return: height of some node in a tree otherwise NULL if tree is NULL
 */
int height(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (-1);
	left_height = height(tree->left);
	right_height = height(tree->right);
	if (left_height > right_height)
	{
		return (left_height + 1);
	}
	else
	{
		return (right_height + 1);
	}
}
/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is perfect and 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (height(tree->left) == height(tree->right))
	{
		if (height(tree->left) == -1)
			return (1);
		if (tree_is_leaf(tree->left) && tree_is_leaf(tree->right))
			return (1);
		if (parent_is_full(tree))
			return (binary_tree_is_perfect(tree->left) &&
				binary_tree_is_perfect(tree->right));
	}
	return (0);
}
