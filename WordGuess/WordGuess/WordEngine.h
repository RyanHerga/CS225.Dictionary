#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <time.h>  
#include <fstream>
#include <sstream>
#include <Windows.h>
#include <vector>
#include <utility>

#define MAX_COUNT_ADJ 50
#define MAX_COUNT_VERB 50
#define MAX_COUNT_NOUN 50

using namespace std;
/*
* Template for what a word would normally have in a dictionary
*/
class Word {
private:
	string theWord;
	string theDef;
	string theOrigin;
	int wordLength;
protected:
	string partOfSpeech;
	string partOfSpeechShort;
public:
	Word(string _theWord, string _theDef, string _theOrigin = "Unknown") {
		theWord = _theWord;
		theDef = _theDef;
		theOrigin = _theOrigin;
		wordLength = theWord.length();
		// Idk what the actual function call is.
	}

	Word() {
		theOrigin = "Unknown";
		theWord = "Null";
		theDef = "Null";
		wordLength = 0;
		// Blank Constructor
	}

	void setWord(string _theWord) {
		theWord = _theWord;
		wordLength = theWord.length();
	}
	void setDef(string _theDef) {
		theDef = _theDef;
	}
	void setOrigin(string _theOrigin) {
		theOrigin = _theOrigin;
	}

	string getWord() {
		return theWord;
	}

	int getLength() {
		return wordLength;
	}

	string getDef() {
		return theDef;
	}

	string getOrigin() {
		return theOrigin;
	}

	string getPartOfSpeech() {
		return partOfSpeech;
	}

	string getShortPartOfSpeech() {
		return partOfSpeechShort;
	}
};

/*
* Inherit from word, and adds partOfSpeech variable
*/

class Adjective : virtual public Word {
public:
	Adjective(){}
	Adjective(string _theWord, string _theDef, string _theOrigin = "Unknown") : Word(_theWord, _theDef, _theOrigin) {
		partOfSpeech = "Adjective";
		partOfSpeechShort = "Adj";
	}
};

/*
* Inherit from word, and adds partOfSpeech variable
*/

class Noun : virtual public Word {
public:
	Noun(){}
	Noun(string _theWord, string _theDef, string _theOrigin = "Unknown") : Word(_theWord,  _theDef,  _theOrigin) {
		partOfSpeech = "Noun";
		partOfSpeechShort = "n";
	}
};

class Verb : virtual public Word {
public:
	Verb() {}
	Verb(string _theWord, string _theDef, string _theOrigin = "Unknown") :Word(_theWord, _theDef, _theOrigin) {
		partOfSpeech = "Verb";
		partOfSpeechShort = "v";
	}
};

/*
* Collection of nouns, verbs & adjectives
*/

class WordLibrary {
private:
	Adjective * myAdjectives;
	Verb * myVerbs;
	Noun * myNouns;
	int totalWords, totalAdjectives, totalVerbs, totalNouns;
public:

	WordLibrary(void) {
	
	}

	const vector<string> explode(const string& s, const char& c)
	{
		string buff{ "" };
		vector<string> v;

		for (auto n : s)
		{
			if (n != c) buff += n; else
				if (n == c && buff != "") { v.push_back(buff); buff = ""; }
		}
		if (buff != "") v.push_back(buff);

		return v;
	}


	/*
	* Loads word library from file and populates Adjectives, nouns, and verbs stack
	*/

	void init(string fLocation, interior_ptr<System::Windows::Forms::Label^> theLabel) {
		delete[] myAdjectives;
		delete[] myVerbs;
		delete[] myNouns;

		totalWords = 0;
		totalAdjectives = 0;
		totalVerbs = 0;
		totalNouns = 0;

		myAdjectives = new Adjective[MAX_COUNT_ADJ];
		myVerbs = new Verb[MAX_COUNT_VERB];
		myNouns = new Noun[MAX_COUNT_NOUN];

		//Open fileStream
		ifstream infile(fLocation);

		//Count and total the data we have.

		string theWord, theDef, theSpeech;
		
		string theLine;

		while (getline(infile, theLine)) {

			auto v = explode(theLine, ',');
				theWord = v[0];
				theDef = v[1];
				theSpeech = v[2];
			//OutputDebugStringA(theWord.c_str());

			totalWords++;
			OutputDebugStringA(theSpeech.c_str());

			if (theSpeech == "adj") {
				totalAdjectives++;
				//exit(1);
				string msgToPrint = "Adjective Added" + theWord;
				OutputDebugStringA(msgToPrint.c_str());
			}
			else if (theSpeech == "noun") {
				totalNouns++;
				string msgToPrint = "Noun Added: " + theWord;
				OutputDebugStringA(msgToPrint.c_str());
				//exit(1);
			}
			else if (theSpeech == "verb") {
				string msgToPrint = "Verb Added: " + theWord;
				OutputDebugStringA(msgToPrint.c_str());
				totalVerbs++;
				
				//exit(1);
			}

			push(theSpeech, theWord, theDef);
			//(*theLabel)->Text = mySpeech;
		}
		if (totalWords > 0)
			(*theLabel)->Text = "" + (totalAdjectives + totalVerbs + totalNouns) + " Words Loaded";
		else
			(*theLabel)->Text = "File Empty!";
	}

	/*
	* Pushes word onto a particular stack. Returns -1 if partOfSpeech invalid, returns 1 if valid and worked;
	*/

	int push(string _partOfSpeech, string _theWord, string _theDef, string _theOrigin = "Unknown") {
		if (_partOfSpeech == "adj") {
			//add to adjective stack
			Adjective myAdj(_theWord, _theDef, _theOrigin);
			myAdjectives[totalAdjectives-1] = myAdj;

		}
		else if (_partOfSpeech == "noun") {
			//Add to noun stack
			Noun myNoun(_theWord, _theDef, _theOrigin);
			myNouns[totalNouns-1] = myNoun;

		}
		else{
			//Add to verb stack
			Verb myVerb(_theWord, _theDef, _theOrigin);
			myVerbs[totalVerbs-1] = myVerb;
		}

		return 1;
	}

	/*
	* Gets a random word from the list
	* Executes only if part of speech is NOT given
	*/

	Word getRandomWord() {
		string _partOfSpeech;
		srand(time(0));
		
		int randomNumber = rand() % 3;
	

		if (randomNumber == 1) {
			_partOfSpeech = "noun";
		}
		else if (randomNumber == 2) {
			_partOfSpeech = "verb";
		}
		else {
			_partOfSpeech = "adj";
		}

		return getRandomWord(_partOfSpeech);

	}

	/*
	* Gets a random word from the list
	* Execute only if part of speech is given
	*/

	Word getRandomWord(string _partOfSpeech) {
		int randomNum;
		if (_partOfSpeech == "noun") {
			randomNum = rand() % (totalNouns - 1); //Set this to random number between 0 and (totalNouns - 1)
			return myNouns[randomNum];
		}
		else if (_partOfSpeech == "verb") {
			randomNum = rand() % (totalVerbs - 1);  //Set this to random number between 0 and (totalVerbs - 1)
			return myVerbs[randomNum];
		}
		else if (_partOfSpeech == "adj") {
			randomNum = rand() % (totalAdjectives - 1); //Set this to random number between 0 and (totalAdjectives - 1)
			return myAdjectives[randomNum];
		}
	}

	
};