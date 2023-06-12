#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::string reserved[] = {"cin>>", "for", "int", "while"};
  std::string op[] = {"+", "-", "*", "/", "++", "--"};
  std::string special[] = {">", "=", ";", "(", ")", ">=", ","};


  std::string word{};

  std::string userInput{};
  std::string yn{};
  do {
    std::vector<std::string> lexeme{};  // vector of all lexemes scanned
    std::cout << "Enter a statement: ";
    std::getline(std::cin, userInput);

    char buffer = userInput[1];

    for (auto ch : userInput) {
      switch (ch) {
        case ' ': 
          lexeme.push_back(word);
          word = "";
          break;
        default:
          word += ch;
          break;
      }
    }
    if (word != "") {
      lexeme.push_back(word);
      word = "";
    }



    for (auto str : lexeme) {
        std::cout << str << '\t';

        bool found = false;

        for (auto i : reserved) {

          std::string strlower = str;

          for (auto j = str.begin(); j != str.end(); ++j) {
            switch (*j) {
              case 'A':
                *j = 'a'; break;
              case 'B':
                *j = 'b'; break;
              case 'C':
                *j = 'c'; break;
              case 'D':
                *j = 'd'; break;
              case 'E':
                *j = 'e'; break;
              case 'F':
                *j = 'f'; break;
              case 'G':
                *j = 'g'; break;
              case 'H':
                *j = 'h'; break;
              case 'I':
                *j = 'i'; break;
              case 'J':
                *j = 'j'; break;
              case 'K':
                *j = 'k'; break;
              case 'L':
                *j = 'l'; break;
              case 'M':
                *j = 'm'; break;
              case 'N':
                *j = 'n'; break;
              case 'O':
                *j = 'o'; break;
              case 'P':
                *j = 'p'; break;
              case 'Q':
                *j = 'q'; break;
              case 'R':
                *j = 'r'; break;
              case 'S':
                *j = 's'; break;
              case 'T':
                *j = 't'; break;
              case 'U':
                *j = 'u'; break;
              case 'V':
                *j = 'v'; break;
              case 'W':
                *j = 'w'; break;
              case 'X':
                *j = 'x'; break;
              case 'Y':
                *j = 'y'; break;
              case 'Z':
                *j = 'z'; break;
            }
          }
        
          if (strlower == i) {
            
            std::cout << "reserved word\n";
            found = true;
          }
        }

        if (found == false) {
          for (auto i : special) {
            if (str == i) {
              std::cout << "special symbol\n";
              found = true;
            }
          }
        }

        if (found == false) {
          for (auto i : op) {
            if (str == i) {
              std::cout << "operator\n";
              found = true;
            }
          }
        }

        if (found == false) {
          char state = 'A';
          for (auto i : str) {
            switch (i) {
              case '+': case '-':
                if (state == 'A') {
                  state = 'B';
                }
                else if (state == 'B') {
                  state = 'C'; //too many +- signs
                }
                break;
              case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
                if (state == 'A' || state == 'B') {
                  state = 'B';
                }
                break;
              default:
                state = 'C'; //nan
                break;
            }
            if (state == 'C') {
              break;
            }
            

            
          }
          if (state == 'B') {
              std::cout << "number\n";
              found = true;
          }
          
        }


        if (found == false) {
          char state = 'A';
          for (auto i : str) {

            switch (i) {
              case 'a': case 'b': case 'c': case 'd': case 'e': case 'f': case 'g': case 'h': case 'i': case 'j': case 'k': case 'l': case 'm': case 'n': case 'o': case 'p': case 'q': case 'r': case 's': case 't': case 'u': case 'v': case 'w': case 'x': case 'y': case 'z':
              case 'A': case 'B': case 'C': case 'D': case 'E': case 'F': case 'G': case 'H': case 'I': case 'J': case 'K': case 'L': case 'M': case 'N': case 'O': case 'P': case 'Q': case 'R': case 'S': case 'T': case 'U': case 'V': case 'W': case 'X': case 'Y': case 'Z':
                if (state == 'A') {
                  state = 'B';
                }
                break;

              case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
                if (state == 'A') {
                  state = 'C';
                }
                break;


              default:
                state = 'C';
                break;
            }
            if (state == 'C') {
              break;
            }
          }
          if (state == 'B') {
            std::cout << "identifier\n";
          }
          else if (state == 'C') {
            std::cout << "invalid\n";
          }
        }


    }







    std::cout << "CONTINUE(y/n)? ";
    std::cin >> yn;
    ++buffer;
    std::cin.ignore(256,'\n');
  } while (yn == "y" || yn == "Y");





  return 0;
}