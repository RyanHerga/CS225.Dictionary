#include <iostream>
#include <string.h>

using namespace std;

/*
* Template for what a word would normally have in a dictionary
*/
class Word{
private:
	string theWord;
	string theDef;
	string theOrigin;
	int wordLength;
public:
	Word(string _theWord, string _theDef, string _theOrigin = "Unknown"){
		theWord = _theWord;
		theDef = _theDef;
		theOrigin = _theOrigin;
		wordLength = theWord.length();
		 // Idk what the actual function call is.
	}

	Word(){
		theOrigin = "Unknown";
		theWord = "Null";
		theDef = "Null";
		wordLength = 0;
		// Blank Constructor
	}

	void setWord(string _theWord){
		theWord = _theWord;
		wordLength = theWord.length();
	}
	void setDef(string _theDef){
		theDef = _theDef;
	}
	void setOrigin(string _theOrigin){
		theOrigin = _theOrigin;
	}

	string getWord(){
		return theWord;
	}

	int getLength(){
		return wordLength;
	}

	string getDef(){
		return theDef;
	}

	string getOrigin(){
		return theOrigin;
	}
};

/*
* Inherit from word, and adds partOfSpeech variable
*/

class Adjective : virtual public Word{
	private:
		string partOfSpeech;
		string partOfSpeechShort;
	public:
		Adjective() : Word(){
			partOfSpeech = "Adjective";
			partOfSpeechShort = "Adj";
		}

		string getPartOfSpeech(){		
			return partOfSpeech;
		}

		string getShortPartOfSpeech(){		
			return partOfSpeechShort;
		}
};

/*
* Inherit from word, and adds partOfSpeech variable
*/

class Noun: virtual public Word{
private:
	string partOfSpeech;
	string partOfSpeechShort;

public:
	Noun() : Word(){
		partOfSpeech = "Noun";
		partOfSpeechShort = "n";
	}
	string getPartOfSpeech(){	
		return partOfSpeech;
	}
	string getShortPartOfSpeech(){	
		return partOfSpeechShort;
	}
};

class Verb: virtual public Word{
private:
	string partOfSpeech;
	string partOfSpeechShort;

public:

	Verb():Word(){
		partOfSpeech = "Verb";
		partOfSpeechShort =  "v";
	}
	string getPartOfSpeech(){
		return partOfSpeech;
	}

	string getShortPartOfSpeech(){
		return partOfSpeechShort;
	}
};

/*
* Collection of nouns, verbs & adjectives
*/

class WordLibrary{
private:
	Adjective * myAdjectives;
	Verb * myVerbs;
	Noun * myNouns;
	int totalWords, totalAdjectives, totalVerbs, totalNouns;
public:

	/*
	* Loads word library from file and populates Adjectives, nouns, and verbs stack
	*/

	WordLibrary(){
		totalWords = 0;
		totalAdjectives = 0;
		totalVerbs = 0;
		totalNouns = 0;
		//Open ioStream

		//First, let's do a count of the data we have.

		while(/* File has another line */){
			totalWords++;
			if(/* Word is an Adjective*/){
				totalAdjectives++;
			}else if(/* Word is a Noun */){
				totalNouns++;
			}else if(/* Word is a Verb */){
				totalVerbs++;
			}
		}

		//Now we can initiate lists

		myAdjectives = new Adjective[totalAdjectives];
		myVerbs = new Verb[totalVerbs];
		myNouns = new Noun[totalNouns];

		//Okay, now let's populate by pushing.

		while(/*file has another line */){
			string _partOfSpeech, _theWord, _theDef, _theOrigin;
			push(_partOfSpeech, _theWord, _theDef, _theOrigin);
		}

		//Close ioStream
	}

	/*
	* Pushes word onto a particular stack. Returns -1 if partOfSpeech invalid, returns 1 if valid and worked;
	*/

	int push(string _partOfSpeech, string _theWord, string _theDef, string _theOrigin = "Unknown"){
		if(_partOfSpeech == "adj"){
			//create new adjective
			//add to adjective stack
			totalAdjectives++;
		}else if(_partOfSpeech == "noun"){
			//Create new noun
			//Add to noun stack
			totalNouns++;
		}else if(_partOfSpeech == "verb"){
			//Create new verb
			//Add to verb stack
			totalVerbs++;
		}else{
			return -1; 
		}
		return 1;
	}

	/* 
	* Gets a random word from the list
	* Executes only if part of speech is NOT given 
	*/

	Word getRandomWord(){
		string _partOfSpeech;
		int randomNumber;
		if(randomNumber == 1){
			_partOfSpeech = "noun";
		}else if(randomNumber == 2){
			_partOfSpeech = "verb";
		}else{
			_partOfSpeech = "adj";
		}

		return getRandomWord(_partOfSpeech);
		
	}

	/* 
	* Gets a random word from the list
	* Execute only if part of speech is given
	*/

	Word getRandomWord(string _partOfSpeech){
		if(_partOfSpeech == "noun"){
			int randomNum; //Set this to random number between 0 and (totalNouns - 1)
			return myNouns[randomNum];
		}else if(_partOfSpeech == "verb"){
			int randomNum; //Set this to random number between 0 and (totalVerbs - 1)
			return myVerbs[randomNum];
		}else if(_partOfSpeech == "adj"){
			int randomNum; //Set this to random number between 0 and (totalAdjectives - 1)
			return myAdjectives[randomNum];
		}
	}
};


int main(){
	return 0;
}