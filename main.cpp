#include <iostream>
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
	Word(string _theWord, string _theDef. string _theOrigin = "Unknown"){
		theWord = _theWord;
		theDef = _theDef;
		theOrigin = _theOrigin;
		wordLength = length(theWord); // Idk what the actual function call is.
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
		string partOfSpeech = "Adjective";
		string partOfSpeechShort = "Adj";
	public:
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
	string partOfSpeech = "Noun";
	string partOfSpeechShort -  "n";

public:
	string getPartOfSpeech(){
		return partOfSpeech;
	}
	string getShortPartOfSpeech(){
		return partOfSpeechShort;
	}
};

class Verb: virtual public Word{
private:
	string partOfSpeech = "Verb";
	string partOfSpeechShort -  "v";

public:
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
	Adjective *myAdjectives;
	Verb *myVerbs;
	Noun *myNouns;
	int totalWords = 0 , totalAdjectives = 0, totalVerbs = 0, totalNouns = 0;
public:

	/*
	* Loads word library from file and populates Adjectives, nouns, and verbs stack
	*/

	WordLibrary(){

		while(/* File has another line */){
			push(_partOfSpeech, _theWord, _theDef, _theOrigin);
			totalWords++;
		}
		

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