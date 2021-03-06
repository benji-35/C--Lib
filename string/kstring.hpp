/*
** EPITECH PROJECT, 2022
** C++-Lib
** File description:
** kstring
*/

#ifndef KSTRING_HPP_
#define KSTRING_HPP_

#include "klist.hpp"
#include <iostream>
#include <unistd.h>
#include "kutils.hpp"

namespace kap35 {

    class string
    {
        public:
        
            string() {
                _chars = new char[1]();
                _chars[0] = 0;
            }

            string (char const*str) {
                unsigned int _size = 0;

                if (_chars != nullptr)
                    delete _chars;
                while (str[_size])
                    _size++;
                __realloc(_size);
                for (unsigned int i = 0; i < _size; i++)
                    _chars[i] = str[i];
            }

            string(string const& str) {
                clear();
                *this = str;
            }

            string(char const& c) {
                __realloc(1);
                _chars[0] = c;
                _chars[1] = 0;
            }

            string(int const& i) {
                _chars = new char[1]();
                _chars[0] = 0;
                *this = i;
            }

            string(size_t const& i) {
                _chars = new char[1]();
                _chars[0] = 0;
                *this = i;
            }

            string(float const& f) {
                _chars = new char[1]();
                _chars[0] = 0;
                *this = f;
            }

            ~string() {
                if (_chars != nullptr) {
                    delete [] _chars;
                }
            }

            string copy(size_t from = 0, size_t to = 0) {
                string res;

                if (from >= size())
                    return res;
                if (to >= size() || to == 0)
                    to = size() - 1;

                for (size_t i = from; i <= to; i++) {
                    res += (*this)[i];
                }

                return res;
            }

            char *toCharArray() const {
                return _chars;
            }

            size_t size() const {
                unsigned res = 0;

                if (_chars == nullptr)
                    return res;
                while (_chars[res] != 0)
                    res++;
                return res;
            }

            void clear() {
                if (_chars != nullptr) {
                    delete [] _chars;
                }
                _chars = new char[1]();
                _chars[0] = 0;
            }

            void __clearNoAllocs() {
                delete _chars;
                _chars = nullptr;
            }

            size_t find(string const& str, size_t pos = 0, size_t end = 0) const {
                if (end == 0)
                    end = size();
                for (size_t i = pos; i < end; i++) {
                    size_t x = 0;
                    for (; x < str.size(); x++) {
                        if (str.at(x) != (*this).at(i + x))
                            break;
                    }
                    if (x >= str.size()) {
                        return i;
                    }
                }
                return size();
            }

            size_t find(char const& c, size_t pos = 0, size_t end = 0) const {
                string str(c);

                return find(str, pos, end);
            }

            list<string> split(string splitter, int nbSplits = -1) {
                list<string> _ltext;
                size_t curr = 0;
                size_t found = 0;
                size_t sizeSplitter = splitter.size();

                while (curr <= size()) {
                    if (nbSplits == 0) {
                        _ltext.pushBack(copy(curr - 1, size()));
                        break;
                    }
                    found = find(splitter, curr);
                    if (found != 0 && found != size()) {
                        _ltext.pushBack(copy(curr, found - 1));
                    } else {
                        _ltext.pushBack(copy(curr, size()));
                    }
                    curr += _ltext.at(_ltext.size() - 1).size() + sizeSplitter;
                    nbSplits--;
                }
                return _ltext;
            }

            list<string> ssplit(list<string> const& _splitters, int nbSplits = -1) {
                list<string> _ltext;
                list<string> splitters;
                size_t curr = 0;
                size_t found = 0;

                int indexLower = 0;

                splitters = _splitters;

                if (splitters.size() == 0) {
                    _ltext.pushBack(*this);
                    return _ltext;
                }

                while (curr < size()) {
                    if (nbSplits == 0) {
                        _ltext.at(_ltext.size() - 1) += copy(curr - 1, size());
                        break;
                    }
                    indexLower = 0;
                    for (size_t i = 0; i < splitters.size(); i++) {
                        if (i > 0) {
                            size_t tmpFound = find(splitters.at(i), curr);
                            if (tmpFound < found) {
                                found = tmpFound;
                                indexLower = i;
                            }
                        } else {
                            found = find(splitters.at(i), curr);
                        }
                    }
                    if (found != 0 && found != size()) {
                        _ltext.pushBack(copy(curr, found - 1));
                    } else {
                        _ltext.pushBack(copy(curr, size()));
                    }
                    curr += _ltext.at(_ltext.size() - 1).size() + splitters.at(indexLower).size();
                    nbSplits--;
                }
                return _ltext;
            }

            list<string> divide(size_t nbCharInLine) {
                list<string> res;
                size_t currChars = 0;

                string tmp = "";
                for (size_t i = 0; i < size(); i++) {
                    tmp += (*this)[i];
                    currChars++;
                    if (currChars >= nbCharInLine) {
                        res.pushBack(tmp);
                        tmp = "";
                        currChars = 0;
                    }
                }
                return res;
            }

            void insert(string const& str, size_t pos = 0) {
                int _size = size();
                if (pos >= _size)
                    pos = _size - 1;
                if (pos == 0) {
                    *this = str;
                    return;
                }
                size_t nsize = _size + str.size() + 1;

                char *nstr = new char[nsize];
                for (size_t i = 0; i < pos; i++) {
                    nstr[i] = _chars[i];
                }
                for (size_t i = 0; i < str.size(); i++) {
                    nstr[i + pos] = str.at(i);
                }
                for (size_t i = pos; i < size(); i++) {
                    nstr[i + str.size()] = _chars[i];
                }
            }

            list<string> getWords() {
                list<string> seperators;

                seperators.pushBack(" ");
                seperators.pushBack("\t");
                seperators.pushBack("\n");
                seperators.pushBack("\r");
                seperators.pushBack("\a");
                seperators.pushBack("\b");
                seperators.pushBack("\v");
                seperators.pushBack("\f");

                return ssplit(seperators);
            }

            void insert(char const& c, size_t pos = 0) {
                insert(string(c), pos);
            }

            char &at(size_t index) const {
                size_t _size = size();
                if (index >= _size)
                    return _chars[_size - 1];
                return _chars[index];
            }

            void toUpper() {
                for (size_t i = 0; i < size(); i++) {
                    if (_chars[i] >= 'a' && _chars[i] <= 'z') {
                        _chars[i] -= 32;
                    }
                }
            }

            void toLower() {
                for (size_t i = 0; i < size(); i++) {
                    if (_chars[i] >= 'A' && _chars[i] <= 'Z') {
                        _chars[i] += 32;
                    }
                }
            }

            string getUpper() {
                string res = *this;
                res.toUpper();

                return res;
            }

            string getLower() {
                string res = *this;
                res.toLower();

                return res;
            }

            bool isInstring(string toFind) const {
                if (find(toFind, 0, size()) == size())
                    return false;
                return true;
            }

            size_t nbOcurrenceOf(string str) {
                size_t curr = 0;
                size_t res = 0;

                while (curr < size()) {
                    curr += find(str, curr, 0);
                    if (curr >= size())
                        break;
                    res++;
                }

                return res;
            }

            bool startWith(string const& str) {
                if (size() < str.size())
                    return false;
                for (size_t i = 0; i < str.size(); i++) {
                    if ((*this)[i] != str[i])
                        return false;
                }
                return true;
            }

            bool endWith(string const& str) {
                size_t strSize = str.size();
                size_t thisSize = size();

                if (strSize > thisSize)
                    return false;
                for (size_t i = (thisSize - strSize); i < thisSize; i++) {
                    if ((*this)[i] != str[i + thisSize])
                        return false;
                }
                return true;
            }

            void remove(size_t pos) {
                string tmp = copy(0, pos - 1);
                string tmp2 = "";

                if (pos < size() - 1)
                    tmp2 = copy(pos + 1, size());
                tmp += tmp2;
                *this = tmp2;
            }

            //change string
            void advance(size_t ad) {
                if (ad >= size()) {
                    clear();
                    return;
                }
                string str = "";

                for (size_t i = ad; i < size(); i++) {
                    str += (*this)[i];
                }
                *this = str;
            }

            void inverse() {
                for (size_t i = 0; i < size() / 2; i++) {
                    char c = _chars[i];
                    size_t mirrorChar = size() - (1 + i);
                    _chars[i] = _chars[mirrorChar];
                    _chars[mirrorChar] = c;
                }
            }

            //function toSomething

            int toInt(size_t pos = 0) {
                int res = 0;
                bool neg = false;
                string curr(*this);

                if (curr.size() == 0 || curr.size() <= pos) {
                    return res;
                }
                size_t startPos = pos;
                if (curr.size() >= pos + 2 && curr[pos] == '-') {
                    neg = true;
                    startPos = pos + 1;
                }
                for (; startPos < curr.size(); startPos++) {
                    if (curr[startPos] < '0' || curr[startPos] > '9')
                        break;
                    res *= 10;
                    res += curr[startPos] - 48;
                }
                if (neg)
                    res *= -1;
                return res;
            }

            size_t toUInt(size_t pos = 0) {
                size_t res = 0;
                string curr(*this);

                if (curr.size() == 0 || curr.size() <= pos) {
                    return res;
                }
                size_t startPos = pos;
                for (; startPos < curr.size(); startPos++) {
                    if (curr[startPos] < '0' || curr[startPos] > '9')
                        break;
                    res *= 10;
                    res += curr[startPos] - 48;
                }
                return res;
            }

            float toFloat(size_t pos = 0) {
                float res = 0;
                bool neg = false;
                bool coma = false;
                int comaId = 0;
                if (_chars[pos] == '-') {
                    neg = true;
                    pos++;
                }
                for (size_t i = pos; i < size(); i++) {
                    if (_chars[i] >= '0' && _chars[i] <= '9') {
                        if (coma) {
                            res *= 10;
                            for (int x = 0; x < comaId; x++)
                                res *= 10;
                            res += _chars[i] - 48;
                            res /= 10;
                            for (int x = 0; x < comaId; x++)
                                res /= 10;
                            comaId++;
                        } else {
                            res *= 10;
                            res += _chars[i] - 48;
                        }
                    } else if (_chars[i] == '.' && coma == false) {
                        coma = true;
                    } else {
                        break;
                    }
                }
                if (neg)
                    res *= -1;
                return res;
            }

            //operators

            string operator+(string const& str) {
                string nstr(*this);
                unsigned int nsize = nstr.size() + str.size();
                unsigned int lastSize = nstr.size();

                nstr.__realloc(nsize);
                for (unsigned int i = lastSize; i < nsize; i++) {
                    nstr._chars[i] = str._chars[i - lastSize];
                }
                nstr._chars[nstr.size()] = 0;
                return nstr;

            }

            string operator+(char const& c) {
                return *this + string(c);
            }

            string operator+(char const* c) {
                string _ctmp(c);
                string res = *this + _ctmp;

                return res;
            }

            string operator+(int const& i) {
                string intStr;
                bool negative = false;
                int value = i;

                if (value < 0) {
                    negative = true;
                    value *= -1;
                    intStr = "-";
                }
                if (value == 0) {
                    intStr += '0';
                    return intStr;
                }
                while (value > 0) {
                    intStr += (char)((value % 10) + 48);
                    value /= 10;
                }
                intStr.inverse();
                return intStr;
            }

            string operator+(size_t const& i) {
                string intStr;
                int value = i;

                if (i == 0)
                    return "0";

                while (value > 0) {
                    intStr += (char)((value % 10) + 48);
                    value /= 10;
                }
                intStr.inverse();

                string tmp = *this;
                tmp += intStr;
                return tmp;
            }

            string operator+(float const& f) {
                int beforeComa = (int)f;
                float _f = f;
                string intStr(beforeComa);

                _f -= (float)beforeComa;
                for (size_t i = 0; i < 6; i++)
                    _f *= 10;
                int afterComa = (int)_f;
                string afterComaStr(afterComa);
                string result = intStr + "." + afterComaStr;
                return result;
            }

            string &operator<<(string const& str) {
                *this = *this + str;
                return *this;
            }

            string &operator<<(char const& c) {
                *this = *this + c;
                return *this;
            }

            string &operator<<(int const& i) {
                *this = *this + i;
                return *this;
            }

            string &operator<<(size_t const& i) {
                *this = *this + i;
                return *this;
            }

            string &operator<<(float const& f) {
                *this = *this + f;
                return *this;
            }

            char &operator[](size_t index) const {
                if (index >= size()) {
                    throw Exception::StringError(string("index out of range").toCharArray());
                }
                return _chars[index];
            }

            string &operator=(string const& str) {
                clear();
                __realloc(str.size());
                for (size_t i = 0; i < str.size(); i++) {
                    _chars[i] = str._chars[i];
                }
                _chars[str.size()] = 0;
                return *this;
            }

            string &operator=(char const& c) {
                clear();
                __realloc(1);
                _chars[0] = c;
                _chars[1] = 0;
                return *this;
            }

            string &operator=(char const c) {
                clear();
                __realloc(1);
                _chars[0] = c;
                _chars[1] = 0;
                return *this;
            }

            string &operator=(char const* str) {
                string _str(str);
                *this = _str;
                return *this;
            }

            string &operator=(int const& i) {
                string intStr;

                intStr += i;
                *this = intStr;
                return *this;
            }

            string &operator=(size_t const& i) {
                string intStr;

                intStr += i;
                *this = intStr;
                return *this;
            }

            string &operator=(float const& f) {
                string fStr;

                fStr += f;
                *this = fStr;
                return *this;
            }

            string &operator+=(string const& str) {
                return *this << str;
            }

            string &operator+=(char const& c) {
                return *this << c;
            }

            string &operator+=(int const& i) {
                return *this << i;
            }

            string &operator+=(size_t const& i) {
                return *this << i;
            }

            string &operator+=(float const& f) {
                *this = *this + f;
                return *this;
            }

            bool operator==(string const& str) {
                for (size_t i = 0; i < size(); i++) {
                    if ((*this)[i] != str._chars[i])
                        return false;
                }
                return true;
            }

            bool operator!=(string const& str) {
                return !(*this == str);
            }

            bool operator==(char const* cstr) {
                string str(str);
                return (*this == str);
            }

            bool operator!=(char const* cstr) {
                return !(*this == cstr);
            }

            friend std::ostream &operator<<(std::ostream & os, string const& str) {
                if (str.toCharArray() == nullptr)
                    return os;
                os << str.toCharArray();
                return os;
            }

            static string readFd(int fd = 1, char endChar = '\n') {
                string res = "";
                while (1) {
                    char *c = nullptr;
                    if (read(fd, c, 1) == -1)
                        break;
                    if (c == nullptr)
                        break;
                    res += c;
                }
                return res;
            }

        private:
            void __realloc(unsigned int _size) {
                char *_nchars = new char[_size + 1];

                for (unsigned int i = 0; i < size(); i++) {
                    if (i >= _size)
                        break;
                    _nchars[i] = _chars[i];
                }
                _nchars[_size] = 0;
                if (_chars != nullptr)
                    delete [] _chars;
                _chars = _nchars;
            }

            char *_chars = nullptr;
    };

}

#endif /* !KSTRING_HPP_ */
