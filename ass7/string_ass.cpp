#include <iostream>
#include <string>
#define SIZE 3
using namespace std;


string pig(string str);
string pig_word(string word);
void name_search(string people[], int size);

int main()
{
    string name = "Hola this is pig a latin";
    string people[SIZE] = {"Bob Palmer: 90210", "Billy Bob Thorton: 2225555", "Bilbo Baggins: 215"};

    cout << pig(name);
    name_search(people, SIZE);

}

string pig(string str)
{
    int i = 0;
    string word = "", ret_val = "";

    while(i < str.length()){
        if(str[i] != ' ')
          word += str[i];
        else{
          ret_val += pig_word(word) + " ";
          word = "";
        }
        i++;
    }

    return ret_val;
}

string pig_word(string word)
{
    string ret_val, vowels = "aeiouAEIOU";

    if(vowels.find(word[0]) != string::npos)
      ret_val = word + "yay"; //has a vowel
    else
      ret_val = word.substr(1) + word[0] + "ay";

    return ret_val;

}

void name_search(string people[], int size)
{
    string name;

    cout << "Please enter name: ";
    cin >> name;
    for(int i = 0; i < size; i++){
      if(people[i].find(name) != string::npos)
        cout << people[i] << endl;
    }
}
