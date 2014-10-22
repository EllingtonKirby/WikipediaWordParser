#include "Processor.h"
#include <Word.h>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
using namespace std;


void writeQ1(map<string, Word> mymap){
	ofstream q1Data;
	q1Data.open("q1.txt");
	vector<string> fullList;
	for(auto iter  = mymap.begin(); iter!=mymap.end();iter++){
		fullList.pushBack(iter->second);
	}
	sort(fullList.begin(), fullList.end(), [](const Word &w1, const Word &w2){
		return w1.getTot() > w2.getTot();
	});
	auto iter = fullList.begin();
	for(int i = 0; i < fullList.size() / 20; i++){
		q1Data << iter.getName() << ", " << iter.getTot() << ", " << iter.getMaxTitle();
		iter++;
	}
	q1Data.close();
}
int main(int argc, char* argv[]){
	if(argc != 2){
		cerr << "Invalid use." << endl;
		cerr << "Usage: ./wikiParse input_file_name" << endl;
	}
	else{
		ifstream inFile(argv[1]);
		if(inFile.is_open()){
			string line;
			string title;
			string word;
			Processor process;
			process.initStopWords("stop.txt");
			map<string, Word> q1Set;
			while(getline(inFile, line)){
				if(process.isTitle(line)){
					title = process.getTitle(line);
				}
				else{
					stringstream sstream(line);
					while(sstream >> word){
						process.strip(word);
						if(process.isStopWord(word)){
						}
						else{
							if(q1Set.count(word) == 0){
								q1Set[word] = Word(word);
								q1Set[word].incrementTitle(title);
							else{
								q1Set[word].incrementTitle(title);			
						}
					}
				}
			}
		}
	}
}
