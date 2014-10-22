#include <map>
#include <set>
#include <string>
#include <utility>
using namespace std;

class Word{
	private:
		string name;
		int totOccur;
		map<string, int> titles;
	public:
		Word(string name);
		string getName();
		int getTot();
		string getMaxTitle();
		void incrementTitle(string title);
};	
