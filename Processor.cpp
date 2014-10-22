#include "Processor.h"

/** Strips punctuations off from the beginning and
 *  end of strings. Punctuations are considered to be
 *  non-alphnumeric characters of any kind. The function
 *  changes the original string to fit the criteria.
 *  
 *  Parameters: The string to be stripped from punctuations.
 */
void Processor::strip(std::string &word){
	bool found = false;
	int count = 0;
	for(int i = 0; i < (int)word.length() && !found; i++){
		if(!isalnum(word[i])){
			count++;
		}
		else{
			found = true;
		}
	}
	word.erase(0, count);
	
	found = false;
	count = 0;
	for(int i = (int) word.length() - 1; i >= 0 && !found; i--){
		if(!isalnum(word[i])){
			count++;
		}
		else{
			found = true;
		}
	}
	word.erase(word.length() - count);
}

/** Initializes the set of stop words obtained from a file.
 *  Changes all words obtained from the stop words text
 *  file to lower case to process words in a case insensitive
 *  manner.
 *
 *  Parameters: Name of the file containing stop words.
 */
void Processor::initStopWords(std::string filename){
	std::ifstream inFile(filename);
	if(inFile.is_open()){
		std::string word;
		while(getline(inFile, word)){
			std::transform(word.begin(), word.end(), word.begin(), ::tolower);
			stopWords.insert(word);	
		}
	}
	inFile.close();
}

/** Checks to see if the word of interest in the file is 
 *  a stop word.
 *
 *  Parameters: The word of interest.
 */
bool Processor::isStopWord(std::string &word){
	if(stopWords.find(word) != stopWords.end()){
		return true;
	}
	return false;
}

/** Checks to see if the string is a title.
 * 
 *  Parameters: The word of interest.
 */
bool Processor::isTitle(std::string &word){
	if(word.find("<TITLE>") != std::string::npos && word.find("</TITLE>") != std::string::npos){
		return true;
	}
	return false;
}

/** Strips the string from its title tags to obtain the
 *  title of the article.
 * 
 *  Parameters: The string containing the article title.
 */
std::string Processor::getTitle(std::string &word){
	word.erase(word.find("<TITLE>"), 7);
	word.erase(word.find("</TITLE>"));
	return word;
}
