#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <string>
#include <set>
#include <fstream>
#include <algorithm>

class Processor{
	public:
		void strip(std::string &word);
		void initStopWords(std::string filename);
		bool isStopWord(std::string &word);
		bool isTitle(std::string &word);
		std::string getTitle(std::string &word);
	private:
		std::set<std::string> stopWords;	
};

#endif //PROCESSOR_H
