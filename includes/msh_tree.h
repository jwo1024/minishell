#ifndef MSH_TREE_H
# define MSH_TREE_H

/*
enum e_ttype
{
	T_NULL = 0,
	T_WORD = 1,
	T_REDIR = 2,
	T_PIPE = 3,
	T_DOUBLE_QUOTES = 4,
	T_SINGLE_QUOTES = 5
};
*/

enum e_ttype
{
	T_NULL = 0,
	T_WORD = 1,
	T_REDIR = 2,
	T_PIPE = 3,
	T_DOUBLE_QUOTES = 4,
	T_SINGLE_QUOTES = 5,
	T_REDIRECT_HEAD = 6,
	T_REDIRECT_LEAF = 7,
	T_CMD = 8,
	T_SIMP_CMD = 9,
	T_AND = 10,
	T_OR = 11
};


typedef struct s_node{
	enum e_ttype	type;
	char			*str1;
	char			*str2; 
	struct s_node	*left;
	struct s_node	*right;
	struct s_node	*parent;
}	t_node;

typedef struct s_tree
{
	t_node	*top;
	int		node_count;
}	t_tree;

t_tree *msh_tree_create_tree();
t_node *msh_tree_create_node(enum e_ttype type, char *str);
int		msh_tree_add_node_left(t_tree *tree, t_node *cur_node, t_node *new_node);
int		msh_tree_add_node_right(t_tree *tree, t_node *cur_node, t_node *new_node);
int		msh_tree_add_edge_right(t_tree *tree, t_node *new_node);


#endif