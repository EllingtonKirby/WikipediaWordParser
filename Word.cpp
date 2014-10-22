#include "Word.h"
using namespace std;

Word::Word(string name){
	this->name = name;
	totOccur = 0;
}
string Word::getName(){
	return name;
}
void Word::incrementTitle(string title){
	if(titles.count(title) == 0){
		titles[title] = 1;
		totOccur++;
	}
	else{
		titles[title]++;
		totOccur++;
	}
}
int Word::getTot(){
	return totOccur;
}
string Word::getMaxTitle(){
	int max = 0;
	string maxname;
	for( auto iter = titles.begin(); iter!=titles.end(); iter++){
		if(iter->second > max){	
			max = iter->second;
			maxname = iter->first;
		} 
	}
	return maxname;
}	
