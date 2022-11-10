#include <iostream>
#include "Utilities.h"
#include <string.h>
#include "sstream"

using namespace std;

namespace sdds {

  char Utilities::m_delimiter = ' ';

  std::string Utilities::trim(std::string &str){
    int start = str.find_first_not_of(' ');
    int end = str.find_last_not_of(' ');
    return str.substr(start, end-start+1);
  }

  void Utilities::setFieldWidth(size_t newWidth) {
    m_widthField = newWidth;
  }

  size_t Utilities::getFieldWidth() const {
    return m_widthField;
  }

  std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
    if(more) {
      string token;
      string stringAtPos = str.substr(next_pos);
      stringstream s(stringAtPos);
      if(stringAtPos[0] == m_delimiter) {
        more = false;
        throw "Delimiter Found!";
      }
      if(getline(s, token, m_delimiter)) {
        token = trim(token);
        size_t currPos = str.find(token);
        next_pos = str.find(m_delimiter, currPos);
        more = true;
        if(next_pos == string::npos) {
          more= false;
        }
        else {
          next_pos++;
        }
        if(m_widthField < token.length()) m_widthField= token.length();
        return token;
      }
      more = false;
    }
    return "NULL";
  }

  void Utilities::setDelimiter(char newDelimiter) {
    m_delimiter = newDelimiter;
  }

  char Utilities::getDelimiter() {
    return m_delimiter;
  }

}