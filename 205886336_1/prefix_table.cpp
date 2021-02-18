 
#include "prefix_table.hpp"
#include <bitset>
#include <sstream> 



      //translate ip to binary
      //נחזיר רק את הסאבנט מאסק
 string prefix_table::transpose(string ip)        //return 32 bits of ip
{
  int x = 0;  //for subnet
  int p1 = ip.find(".");
  string ip1 = ip.substr(0,p1-1);
  std::string binary = std::bitset<8>(stoi(ip1)).to_string();
  int p2 = ip.find(".",p1);
  string ip2 = ip.substr(p1+1,p2-1);
  binary += std::bitset<8>(stoi(ip2)).to_string();
  int p3 = ip.find(".",p2);
  string ip3 = ip.substr(p2+1,p3-1);
  binary += std::bitset<8>(stoi(ip3)).to_string();
  if(ip.find("/"))  //כלומר יש סלאש במחרוזת
  {
    int p4 = ip.find("/",p3);   //מיקום הסלאש
    string ip4 = ip.substr(p3+1,p4-1);
     binary += std::bitset<8>(stoi(ip4)).to_string();
     string s = ip.substr(p4+1,ip.length());
     stringstream geek(s);  //translate string to int 
     geek>>x;
    // string ip_subnet = ip.substr(0,x);
     //return ip_subnet;              //מכיוון שיש סאבנט מאסק לא נחזיר 32 ביטים אלא נחזיר רק את הסאבנט מאסק
  }
  else {
    string ip4 = ip.substr(p3+1);
     binary += std::bitset<8>(stoi(ip4)).to_string();
  }
  if(ip.find("/"))
  {  
    string ip_subnet = binary.substr(0,x);
    return ip_subnet;
  }
  
  return binary;

}


   void prefix_table::read_line(string line)
   {
      string function = line.substr(0,line.find(" "));
      //string ip = line.substr(4,line.find(" ",4));
      //string ip_new = transpose(ip);
       char result;
        if(function == "ADD")
        {
          string ip = line.substr(4,line.find(" ",4));
          string ip_new = transpose(ip);
          result = line[line.find(" ",5)+1];
          add(prefix_table::root,ip,ip_new,result);
        }
        else if(function == "REMOVE")
        {
          string ip = line.substr(7,line.find(" ",7));
          string ip_new = transpose(ip);
          result = line[line.find(" ",8)+1];
          remove(prefix_table::root,ip,ip_new,result,0);
        }
        else if(function == "FIND")
        {
          string ip = line.substr(5,line.find(" ",5));
          string ip_new = transpose(ip);
          find(prefix_table::root,ip,ip_new);
        }

   }
  void prefix_table::read_from_file(string file_name)
{
    fstream myfile;
    myfile.open(file_name);
    string line;
    while(getline(myfile,line))
    {
        read_line(line);
    }


} 


void prefix_table::add(Node* root,string ip_src,string ip,char result)
{
  Node* p  = root;
  for(int i=0;i<ip.length();i++) {
    int bit = ip[i];
    if(!p->children[bit]) {
      p->children[bit] = new Node();
      numNodes++;
    }
    p = p->children[bit];
  }
  p->isEnd = true;
  p->result = result;
  cout<<"Added " <<ip_src<<endl;
  cout<< ",  at the depth "<<ip.length()<<", total nodes = "<<numNodes<<endl;
}


//בודק האם אין ילדים לצומת.יחזיר נכון אם אין ילדים לצומת
bool prefix_table::isEmpty(Node* root) 
{ 
    for (int i = 0; i < 2; i++) 
        if (root->children[i]) 
            return false; 
    return true; 
} 


Node* prefix_table::remove(Node* current,string ip_src ,string ip,char result, int depth)
{
     if(current == NULL)
        return NULL;
     if(depth == ip.length())
     {
       if(current->isEnd)
          current->isEnd = false;
       if (isEmpty(current)) { 
            delete (current); 
            current = NULL;
            numNodes--; 
        }cout<<"Removed "<<ip_src<<" at the depth"<<ip.length()<<"total nodes"<<numNodes<<endl;

    }
     else{
       int bit = ip[depth];
       current->children[bit] =  remove(current,ip_src,ip, result, depth + 1); 
       if (isEmpty(current) && current->isEnd == false) {   //לא סוף של מילה אחרת 
        delete (current); 
        current = NULL; 
        numNodes--;
    } 
     }
     }

 void prefix_table::find(Node* root,string ip_src,string ip)
{
  Node* p = root;
  for(int i=0;i<ip.length();i++)
   {
     int bit = ip[i];
      if(p->isEnd) {
        cout<<"Found "<<ip_src<<" "<<p->result<<" at the depth "<<i<<endl;
        return;
      }
      p = p->children[bit];
   }
   if(p != NULL && p->isEnd)
   {
     cout<<"Found "<<ip_src<<endl;
     cout<<" "<<p->result<<" at the depth "<<ip.length()<<endl;
   }
}




int main()
{
  prefix_table t;
    t.read_from_file("sample_input.txt");
}