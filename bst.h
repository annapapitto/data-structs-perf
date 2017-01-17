struct Node;

/* Binary Search Tree storing (key, value) pairs. */
class BST
{
 public:
  void put(int, int);
  int get(int);
  void del(int);
  BST ();
  ~BST ();

 private:
  Node *root;
};
