#include "Node.hpp"
#include <fstream>
#include <string.h> 
#include <iostream>
//
using namespace std;
static int numNodes=0;
class prefix_table_opt
{
   public:
    Node* root;
    //static int numNodes;
    prefix_table_opt()
    {
        root = new Node();
        numNodes = 0;
    }
    ~prefix_table_opt()
    {
    //למחוק ברקורסיה את כל העץ.
    delete root;
    }


    void add(Node* root,string ip_src,string ip,char result);
    Node* remove(Node* current,string ip_src ,string ip,char result,int depth);
    void find(Node* root,string ip_src,string ip);
    bool isEmpty(Node* root);

    void read_line(string line);
    void read_from_file(string file_name);
    string transpose(string ip);
};
//int Trie:: numNodes = 0;