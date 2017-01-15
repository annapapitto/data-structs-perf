struct Node;

class BST
{
 public:
  void put(int, int);
  int get(int);
  void del(int);
  BST () : root(new Node) { }
  ~BST () { delete(root) };

 private:
  Node *root;
  void put_in(Node*, int, int);
  int get_from(Node*, int);
  void del_from(Node*, int);
  Node *redraw(Node*);
};
