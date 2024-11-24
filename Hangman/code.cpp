#include <iostream>
#include <ctime>
using namespace std;

const string movies[] = {
    "Waar", "Load Wedding", "Jawani Phir Nahi Ani", "Punjab Nahi Jaungi", "Cake",
    "Teefa in Trouble", "Bol", "Manto", "Bin Roye", "Moor",
    "Dangal", "PK", "Bajrangi Bhaijaan", "3 Idiots", "Lagaan",
    "Kabhi Khushi Kabhie Gham", "Dil Chahta Hai",
    "The Shawshank Redemption", "Inception", "The Dark Knight", "Pulp Fiction", "Forrest Gump",
    "The Godfather", "Titanic", "Avatar"
};

const string food[] = { 
    "Biryani", "Nihari", "Haleem", "Karahi", "Chapli Kebab", 
    "Saag", "Aloo Keema", "Seekh Kebab", "Paya", "Hareesa", 
    "Chana Chaat", "Dahi Puri", "Samosa", "Pakora", "Korma", 
    "Paratha", "Naan", "Roti", "Aloo Gosht", "Chicken Karahi", 
    "Kofta", "Halwa Puri", "Bhindi Masala", "Jalebi", "Sheer Khurma"
};

const string animals[] = { 
    "Lion", "Tiger", "Elephant", "Giraffe", "Zebra", 
    "Kangaroo", "Penguin", "Dolphin", "Koala", "Panda", 
    "Monkey", "Gorilla", "Hippopotamus", "Crocodile", "Sloth", 
    "Cheetah", "Polar Bear", "Octopus", "Eagle", "Ostrich", 
    "Rhinoceros", "Flamingo", "Kangaroo", "Pangolin", "Peacock"
};

const string countries[] = {
    "United States", "China", "India", "Russia", "Brazil",
    "United Kingdom", "France", "Germany", "Italy", "Japan",
    "Canada", "Australia", "South Korea", "Mexico", "South Africa",
    "Saudi Arabia", "United Arab Emirates", "Egypt", "Nigeria", "Kenya",
    "Argentina", "Spain", "Turkey", "Indonesia", "Pakistan", "Thailand"
};

const string sports[] = {
    "Soccer", "Basketball", "Cricket", "Tennis", "Golf",
    "Baseball", "American Football", "Rugby", "Hockey", "Table Tennis",
    "Swimming", "Athletics", "Boxing", "Martial Arts", "Cycling",
    "Badminton", "Volleyball", "Ice Hockey", "Skiing", "Snowboarding",
    "Formula 1", "Gymnastics", "Wrestling", "Surfing", "Chess"
};


void greet(string name);
int getChoice();
int getRandomNumber(int range);
string getWord(string category);
string selectCategory(int choice);
void displayDashes(char dashes[], int length);
void displayGuessCount(int guesses);
void playGame();

int main()
{
  srand(time(0));
  string name;
  cout << "Enter you name: ";
  cin >> name;
  greet(name);
  playGame();
  return 0;
}

void playGame() {
  int choice = getChoice();
  if ((choice < 1) || (choice > 5)) {
    cout << "Invalid Choice!\n";
    cout << "Choose from number 1-5.";
    cout << endl;
    return;
  }
  string category = selectCategory(choice);
  string word = getWord(category);
  int wordSize = word.length();
  char dashes[wordSize];
  int spaces = 0;
  for (int i = 0; i < wordSize; i++) {
    if (word[i] == ' ') {
      spaces++;
      dashes[i] = ' ';
    }
    else {
      dashes[i] = '_';
    }
  }

  cout << "\nSelected: " << category << "\n\n";

  int guesses = 7;
  int guessed = 0;
  while (guesses) {
    char guess;
    bool found = false;

    displayGuessCount(guesses);
    cout << "Enter letter: ";
    displayDashes(dashes, wordSize);
    cin >> guess;

    for (int i = 0; i < wordSize; i++) {
      if (tolower(word[i]) == tolower(guess) && dashes[i] == '_') {
        dashes[i] = guess;
        guessed++;
        found = true;
      }
    }

    if (!found) {
      guesses--;
    }

    if (guessed == (wordSize - spaces)) {
      cout << "word: ";
      displayDashes(dashes, wordSize);
      cout << "Congratulations! You won the game..." << endl;
      break;
    }
  }

  if (!guesses) {
    cout << "\nYou lost the game :(" << endl;
    cout << "Correct word was: " << word << endl;
  }

}

void greet(string name) {
  cout << "------------------------------------------------\n";
  cout << "Welcome to the world of guessing, Dear " << name << "!" << endl;
  cout << "------------------------------------------------\n\n";
}

int getChoice() {
  int choice = 1;
  cout << "1. Movies\n2. Food\n3. Animals\n4. Countries\n5. Sports\n\n";
  cout << "Choose a category number to play from: ";
  cin >> choice;
  return choice;
}

string selectCategory(int choice) {
  string category;
  switch (choice) {
  case 1:
    category = "Movies";
    break;
  case 2:
    category = "Food";
    break;
  case 3:
    category = "Animals";
    break;
  case 4:
    category = "Countries";
    break;
  case 5:
    category = "Sports";
    break;
  }
  return category;
}

void displayDashes(char dashes[], int length) {
  for (int i = 0; i < length; i++) {
    cout << dashes[i];
  }
  cout << endl;
}

string getWord(string category) {
  int length = 0;
  string word = "";

  if (category == "Movies") {
    length = sizeof(movies) / sizeof(string);
    word = movies[getRandomNumber(length)];
  }
  else if (category == "Food") {
    length = sizeof(food) / sizeof(string);
    word = food[getRandomNumber(length)];
  }
  else if (category == "Animals") {
    length = sizeof(animals) / sizeof(string);
    word = animals[getRandomNumber(length)];
  }
  else if (category == "Countries")
  {
    length = sizeof(countries) / sizeof(string);
    word = countries[getRandomNumber(length)];
  }
  else if (category == "Sports")
  {
    length = sizeof(sports) / sizeof(string);
    word = sports[getRandomNumber(length)];
  }
  return word;
}

int getRandomNumber(int range) {
  return (rand() % range);
}

void displayGuessCount(int guesses) {
  cout << "Guesses Left: " << guesses << "/" << 7 << endl;
}