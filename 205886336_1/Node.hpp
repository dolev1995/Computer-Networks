

class Node
{
    public:
    Node *children[2];
    //Node *left;
    //Node *right;
    //Node *parent;
    bool isEnd;
    char result;
    Node ()
    {
        //left=right=parent=null;
        isEnd = false;
        result='~';
    }
     Node (const Node& p)
     {
        //left=right=null;
        //parent=p;
         result='~';
     }
    // Node (const &Node p)
    // {
      //left = p.left;
      //right = p.right;
     // parent = p.parent;
    //   result = p.result; 
    // }
    //  Node (Node p,char a)
    // {
    //     left=right=null;
    //     parent=p;
    //     result=a;
    // }
};















