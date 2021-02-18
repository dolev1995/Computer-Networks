#include <iostream>
#include <fstream>
#include <string.h>
#include "edf.hpp"
using namespace std;
using namespace ex2;



int main(int argc, char *argv[]){
	int size = (int)(*argv[1]-'0');
	packet_deq Packets(size);
	fstream myfile;
	string filename=argv[2];
	myfile.open(filename);
	string str="";
	while(getline(myfile,str)){
		int length=str.length();
		char s[length+1];
		strcpy(s,str.c_str());       //transpose string to char* 	-> s = str
		string pack="";
		for(int i=0;i<length;i++)
		{
			if(s[i]=='('){
				pack = pack + s[i];
				while(s[i] != ')' ){
					i++;
					pack = pack + s[i];

				}
				int n=pack.length();
				char packet[n+1];
				strcpy(packet,pack.c_str());
				for(int i=0;i<(int)(packet[1]-'0');i++){
					Packets.Push(edf_packet((int)(packet[3]-'0'),(int)(packet[5]-'0')));
				}
				Packets.transmit();
				pack="";
			}
		}
	}

	Packets.total_transmit();
	Packets._toString();
	myfile.close();
	return 0;
}