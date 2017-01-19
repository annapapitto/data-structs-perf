#include "bst.h"
#include <iostream>
using namespace std;

#define NOT_FOUND INT_MIN

struct Node
{
  int key;
  int val;
  Node *left;
  Node *right;
  Node (int key, int val) :
    key(key), val(val),
    left(nullptr), right(nullptr) {
  }
  ~Node () {
    delete(left);
    delete(right);
  }
  void put_in(int, int);
  int get_from(int);
  void del_from(int);
  bool is_leaf();
  void replace_myself();
  void append_leftmost(Node*);
};


BST::BST() : root(nullptr) { }

BST::~BST() { delete(root); }

void BST::put(int key, int val)
{
  if (root)
    {
      root->put_in(key, val);
    }
  else
    {
      root = new Node(key, val);
    }
}

int BST::get(int key)
{
  return root->get_from(key);
}

void BST::del(int k)
{
  if (root)
    {
      if (root->key == k)
        {
          if (root->is_leaf())
            {
              root = nullptr;
              delete root;
            }
          else
            {
              root->replace_myself();
            }
        }
      else
        {
          root->del_from(k);
        }
    }
}


void Node::put_in(int k, int v)
{
  if (key == k)
    {
      val = v;
    }
  else if (key > k)
    {
      if (left)
        {
          left->put_in(k, v);
        }
      else
        {
          left = new Node(k, v);
        }
    }
  else
    {
      if (right)
        {
          right->put_in(k, v);
        }
      else
        {
          right = new Node(k, v);
        }
    }
}

int Node::get_from(int k)
{
  if (key == k)
    {
      return val;
    }
  else if (key > k && left)
    {
      return left->get_from(k);
    }
  else if (key < k && right)
    {
      return right->get_from(k);
    }
  else
    {
      return NOT_FOUND;
    }
}

void Node::replace_myself()
{
  Node *new_self;
  if (left && right)
    {
      right->append_leftmost(left);
      new_self = right;
    }
  else if (left)
    {
      new_self = left;
    }
  else
    {
      new_self = right;
    }
  key = new_self->key;
  val = new_self->val;
  left = new_self->left;
  right = new_self->right;

  new_self->left = nullptr;
  new_self->right = nullptr;
  delete(new_self);
}

void Node::del_from(int k)
{
  if (key == k)
    {
      replace_myself();
    }
  if (key > k)
    {
      if (left)
        {
          if (left->key == k && left->is_leaf())
            {
              left = nullptr;
            }
          else
            {
              left->del_from(k);
            }
        }
    }
  else
    {
      if (right)
        {
          if (right->key == k && right->is_leaf())
            {
              right = nullptr;
            }
          else
            {
              right->del_from(k);
            }
        }
    }
}

void Node::append_leftmost(Node *extra)
{
  if (left)
    {
      left->append_leftmost(extra);
    }
  else
    {
      left = extra;
    }
}

bool Node::is_leaf()
{
  return not (left || right);
}

void assert(int guess, int correct)
{
  if (correct != guess)
    {
      cout << "got" << guess << "should be" << correct << endl;
    }
}

int main()
{
  //Some testing of put, get, del.
  BST b;
  b.put(5, 50);
  assert(b.get(5), 50);

  b.put(2, 20);
  b.put(7, 70);
  assert(b.get(2), 20);
  assert(b.get(7), 70);

  b.put(10, 100);
  b.del(7);
  assert(b.get(10), 100);
  assert(b.get(7), NOT_FOUND);

  b.del(10);
  assert(b.get(10), NOT_FOUND);

  b.put(1, 10);
  b.put(4, 40);
  b.del(5);
  assert(b.get(5), NOT_FOUND);
  assert(b.get(2), 20);

  assert(b.get(1), 10);
  assert(b.get(4), 40);

  b.put(6, 60);
  b.del(4);
  assert(b.get(4), NOT_FOUND);
  assert(b.get(6), 60);
  assert(b.get(2), 20);

  b.put(0, 0);
  b.del(1);
  assert(b.get(1), NOT_FOUND);
  assert(b.get(0), 0);
  assert(b.get(2), 20);

  b.put(4, 40);
  b.put(10, 100);
  b.put(3, 30);
  b.put(5, 50);
  b.put(8, 80);
  b.del(6);
  assert(b.get(6), NOT_FOUND);
  assert(b.get(10), 100);
  assert(b.get(4), 40);
  assert(b.get(5), 50);
  assert(b.get(8), 80);

  cout << "end" << endl;
  return 0;
}
