#include <iostream>
#include <string.h>
#include <bitset>
פונקציה שממירה IP לבניארי!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1
using namespace std;

void transpose(string ip)
{
  int p1 = ip.find(".");
  string ip1 = ip.substr(0,p1-1);
  std::string binary = std::bitset<8>(stoi(ip1)).to_string();
  int p2 = ip.find(".",p1);
  string ip2 = ip.substr(p1+1,p2-1);
  binary += std::bitset<8>(stoi(ip2)).to_string();
  int p3 = ip.find(".",p2);
  string ip3 = ip.substr(p2+1,p3-1);
  binary += std::bitset<8>(stoi(ip3)).to_string();
  if(ip.find("/"))  //כלומר יש סלש במחרוזת
  {
    int p4 = ip.find("/",p3);
    string ip4 = ip.substr(p3+1,p4-1);
     binary += std::bitset<8>(stoi(ip4)).to_string();
  }
  else {
    string ip4 = ip.substr(p3+1);
     binary += std::bitset<8>(stoi(ip4)).to_string();
  }
  cout<<binary<<endl;

}
int main() {
  string ip = "255.255.255.0";
  transpose(ip);
  return 0;
}