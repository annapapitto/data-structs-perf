#include "bst.h"

struct Node
{
  int key;
  int val;
  Node *left;
  Node *right;
  Node (int key, int val) {
    this->key = key;
    this->val = val;
  }
  ~Node () {
    delete(left);
    delete(right);
  }
};

void BST::put(int key, int val)
{
  if (root)
    {
      put_in(root, key, val);
    }
  else
    {
      root = new Node(key, val);
    }
}

int BST::get(int key)
{
  return get_from(root, key);
}

void BST::del(int key)
{
  del_from(root, key);
}

void BST::put_in(Node *node, int key, int val)
{
  if (node->key > key)
    {
      if (node->left)
        {
          put_in(node->left, key, val);
        }
      else
        {
          node->left = new Node(key, val);
        }
    }
  else
    {
      if (node->right)
        {
          put_in(node->right, key, val);
        }
      else
        {
          node->right = new Node(key, val);
        }
    }
}

int BST::get_from(Node *node, int key)
{
  if (! node)
    {
      return -1;
    }
  if (node->key == key)
    {
      return node->val;
    }
  else if (node->key > key)
    {
      return get_from(node->left, key);
    }
  else
    {
      return get_from(node->right, key);
    }
}

void BST::del_from(Node *node, int key)
{
  if (! node)
    {
      // key not in tree
    }
  else if (node->key == key)
    {
      *node = *redraw(node); //replace the node pointer with pointer to redrawn right child
    }
  else if (node->key > key)
    {
      del_from(node->left, key);
    }
  else
    {
      del_from(node->right, key);
    }
}

Node* BST::redraw(Node *node)
{
  if (node->left && node->right)
    {
      redraw(node->right);
      node->right->left = node->left;
    }
  else if (node->left)
    {
      node->right = node->left;
    }
    return node->right;
}

int main()
{
  BST b;

  return 0;
}
