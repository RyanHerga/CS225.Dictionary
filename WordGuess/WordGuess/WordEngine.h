#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>

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
	Adjective() : Word() {
		partOfSpeech = "Adjective";
		partOfSpeechShort = "Adj";
	}
};

/*
* Inherit from word, and adds partOfSpeech variable
*/

class Noun : virtual public Word {
public:
	Noun() : Word() {
		partOfSpeech = "Noun";
		partOfSpeechShort = "n";
	}
};

class Verb : virtual public Word {
public:
	Verb() :Word() {
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
	/*
	* Loads word library from file and populates Adjectives, nouns, and verbs stack
	*/

	void init(string fLocation, interior_ptr<System::Windows::Forms::Label^> theLabel) {
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

		while (getline(infile, theWord, ',')) {
			getline(infile, theDef, ',');
			getline(infile, theSpeech);

			totalWords++;

			if (theSpeech == "adj") {
				totalAdjectives++;
			}
			else if (theSpeech == "noun") {
				totalNouns++;
			}
			else if (theSpeech == "verb") {
				totalVerbs++;
			}
			push(theSpeech, theWord, theDef);
		}
		if (totalWords > 0)
			(*theLabel)->Text = "" + totalWords + " Words Loaded";
		else
			(*theLabel)->Text = "File Empty!";
	}

	/*
	* Pushes word onto a particular stack. Returns -1 if partOfSpeech invalid, returns 1 if valid and worked;
	*/

	int push(string _partOfSpeech, string _theWord, string _theDef, string _theOrigin = "Unknown") {
		if (_partOfSpeech == "adj") {
			//create new adjective
			//add to adjective stack
			totalAdjectives++;
		}
		else if (_partOfSpeech == "noun") {
			//Create new noun
			//Add to noun stack
			totalNouns++;
		}
		else if (_partOfSpeech == "verb") {
			//Create new verb
			//Add to verb stack
			totalVerbs++;
		}
		else {
			return -1;
		}
		return 1;
	}

	/*
	* Gets a random word from the list
	* Executes only if part of speech is NOT given
	*/

	Word getRandomWord() {
		string _partOfSpeech;
		int randomNumber;
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
		if (_partOfSpeech == "noun") {
			int randomNum; //Set this to random number between 0 and (totalNouns - 1)
			return myNouns[randomNum];
		}
		else if (_partOfSpeech == "verb") {
			int randomNum; //Set this to random number between 0 and (totalVerbs - 1)
			return myVerbs[randomNum];
		}
		else if (_partOfSpeech == "adj") {
			int randomNum; //Set this to random number between 0 and (totalAdjectives - 1)
			return myAdjectives[randomNum];
		}
	}
};