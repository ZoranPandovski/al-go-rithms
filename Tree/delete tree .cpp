void _deleteTree(struct node* node)
{
    if (node == NULL) return;
    _deleteTree(node->left);
    _deleteTree(node->right);
    free(node);
}

void deleteTree(struct node* *node_ref)
{
  _deleteTree(*node_ref);
  *node_ref = NULL;
}
