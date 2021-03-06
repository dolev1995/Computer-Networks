
#include <iostream>
#include <deque>
#include <string>
using namespace std;
namespace ex2{
class edf_packet{
	public:
	int slack=0,value=0;
	edf_packet(){
		slack=value=0;	};
	edf_packet(int slack,int value)
	{
		this->slack = slack;
		this->value = value;
	} 
};
class packet_deq{		//תור של פקטות
	public:
	int size=0,countOfPacket=0,dropp=0,transmitted=0,transmitted_value=0;
	bool isPass = false;
	deque<edf_packet> packs;
	packet_deq(int size)
	{
		this->size=size;
		packs[this->size];
	}

	void Push(edf_packet packet){
		countOfPacket++;
		if(packs.size()==size){       //התור מלא
				int min_slack=packet.slack, location;
				for(int i=0;i<packs.size();i++){
					if(packs.at(i).slack<min_slack){
						location=i;
						min_slack=packs.at(i).slack;
					}
				}
				if(min_slack==packet.slack)     //הפרמטר שקיבלנו הוא צריך להישלח כי הסלאק שלו הכי קטן
					dropp++;
				else{
					dropp++;
					packs.erase(packs.begin()+location);
					packs.push_back(packet);
				}
		}
		else           //אם התור לא מלא פשוט נדחוף
			packs.push_back(packet);
	}


	void transmit(){
		if(packs.size()==size || isPass)
		{
			for(int i=0;i<packs.size();i++){  //מורידים את הסלאק של כולם באחד
				packs.at(i).slack--;
				if(packs.at(i).slack==0) //ומוציאים מהתור כל מי שהסלק שלו 0
					packs.erase(packs.begin()+i);
			}
			edf_packet p=packs.front();
			packs.pop_front();        //מוחקים אלמנט ראשון
			transmitted++;
			transmitted_value+=p.value;
		}
	}


	void total_transmit(){
			isPass = true;
		while(packs.size()>1){
			transmit();

		}
		isPass = false;
		packs.pop_front();
		dropp++;
	}
	void _toString(){
		cout<<"Total arrived packets:"<<this->countOfPacket<<" total dropped packets:"<<this->dropp;
		cout<<" total transmitted packets:"<<this->transmitted<<" total transmitted value:"<<this->transmitted_value<<endl;
	}


};
}





