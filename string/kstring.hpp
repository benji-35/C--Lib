/*
** EPITECH PROJECT, 2022
** C++-Lib
** File description:
** kstring
*/

#ifndef KSTRING_HPP_
#define KSTRING_HPP_

#include "klist.hpp"
#include "kexceptions.hpp"
#include <iostream>

namespace kap35 {
    class exception;
}

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

            string(unsigned int const& i) {
                _chars = new char[1]();
                _chars[0] = 0;
                *this = i;
            }

            ~string() {
                if (_chars != nullptr) {
                    delete [] _chars;
                }
            }

            string copy(unsigned int from, unsigned int to) {
                string res;

                if (from >= size())
                    return res;
                if (to >= size())
                    to = size() - 1;

                for (unsigned int i = from; i <= to; i++) {
                    res += (*this)[i];
                }

                return res;
            }

            char *toCharArray() const {
                return _chars;
            }

            unsigned int size() const {
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

            unsigned int find(string const& str, unsigned int pos = 0, unsigned int end = 0) const {
                if (end == 0)
                    end = size();
                for (unsigned int i = pos; i < end; i++) {
                    unsigned int x = 0;
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

            unsigned int find(char const& c, unsigned int pos = 0, unsigned int end = 0) const {
                string str(c);

                return find(str, pos, end);
            }

            list<string> split(string splitter, int nbSplits = -1) {
                list<string> _ltext;
                unsigned int curr = 0;
                unsigned int found = 0;
                unsigned int sizeSplitter = splitter.size();

                while (curr < size()) {
                    if (nbSplits == 0) {
                        _ltext.at(_ltext.size() - 1) += copy(curr - 1, size());
                        break;
                    }
                    found = find(splitter, curr);
                    if (found != 0 && found != size()) {
                        _ltext.push_back(copy(curr, found - 1));
                    } else {
                        _ltext.push_back(copy(curr, size()));
                    }
                    curr += _ltext.at(_ltext.size() - 1).size() + sizeSplitter;
                    nbSplits--;
                }
                return _ltext;
            }

            list<string> ssplit(list<string> const& _splitters, int nbSplits = -1) {
                list<string> _ltext;
                list<string> splitters;
                unsigned int curr = 0;
                unsigned int found = 0;

                int indexLower = 0;

                splitters = _splitters;

                if (splitters.size() == 0) {
                    _ltext.push_back(*this);
                    return _ltext;
                }

                while (curr < size()) {
                    if (nbSplits == 0) {
                        _ltext.at(_ltext.size() - 1) += copy(curr - 1, size());
                        break;
                    }
                    indexLower = 0;
                    for (unsigned int i = 0; i < splitters.size(); i++) {
                        if (i > 0) {
                            unsigned int tmpFound = find(splitters.at(i), curr);
                            if (tmpFound < found) {
                                found = tmpFound;
                                indexLower = i;
                            }
                        } else {
                            found = find(splitters.at(i), curr);
                        }
                    }
                    if (found != 0 && found != size()) {
                        _ltext.push_back(copy(curr, found - 1));
                    } else {
                        _ltext.push_back(copy(curr, size()));
                    }
                    curr += _ltext.at(_ltext.size() - 1).size() + splitters.at(indexLower).size();
                    nbSplits--;
                }
                return _ltext;
            }

            void insert(string const& str, unsigned int pos = 0) {
                int _size = size();
                if (pos >= _size)
                    pos = _size - 1;
                if (pos == 0) {
                    *this = str;
                    return;
                }
                unsigned int nsize = _size + str.size() + 1;

                char *nstr = new char[nsize];
                for (unsigned int i = 0; i < pos; i++) {
                    nstr[i] = _chars[i];
                }
                for (unsigned int i = 0; i < str.size(); i++) {
                    nstr[i + pos] = str.at(i);
                }
                for (unsigned int i = pos; i < size(); i++) {
                    nstr[i + str.size()] = _chars[i];
                }
            }

            list<string> getWords() {
                list<string> seperators;

                seperators.push_back(" ");
                seperators.push_back("\t");
                seperators.push_back("\n");
                seperators.push_back("\r");
                seperators.push_back("\a");
                seperators.push_back("\b");
                seperators.push_back("\v");
                seperators.push_back("\f");

                return ssplit(seperators);
            }

            void insert(char const& c, unsigned int pos = 0) {
                insert(string(c), pos);
            }

            char &at(unsigned int index) const {
                unsigned int _size = size();
                if (index >= _size)
                    return _chars[_size - 1];
                return _chars[index];
            }

            void toUpper() {
                for (unsigned int i = 0; i < size(); i++) {
                    if (_chars[i] >= 'a' && _chars[i] <= 'z') {
                        _chars[i] -= 32;
                    }
                }
            }

            void toLower() {
                for (unsigned int i = 0; i < size(); i++) {
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

            bool isInString(string toFind) const {
                if (find(toFind, 0, size()) == size())
                    return false;
                return true;
            }

            unsigned int nbOcurrenceOf(string str) {
                unsigned int curr = 0;
                unsigned int res = 0;

                while (curr < size()) {
                    curr += find(str, curr, 0);
                    if (curr >= size())
                        break;
                    res++;
                }

                return res;
            }

            //change string
            void advance(unsigned int ad) {
                if (ad >= size()) {
                    clear();
                    return;
                }
                unsigned int nSize = size() - ad;
                char *nStr = new char[nSize + 1]();

                for (unsigned int i = 0; i < nSize; i++) {
                    nStr[i] = _chars[i + ad];
                }
                nStr[nSize] = 0;
                
            }

            //function toSomething

            int toInt(unsigned int pos = 0) {
                int res = 0;
                bool neg = false;
                string curr(*this);

                if (curr.size() == 0 || curr.size() <= pos) {
                    return res;
                }
                unsigned int startPos = pos;
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

            unsigned int toUInt(unsigned int pos = 0) {
                unsigned int res = 0;
                string curr(*this);

                if (curr.size() == 0 || curr.size() <= pos) {
                    return res;
                }
                unsigned int startPos = pos;
                for (; startPos < curr.size(); startPos++) {
                    if (curr[startPos] < '0' || curr[startPos] > '9')
                        break;
                    res *= 10;
                    res += curr[startPos] - 48;
                }
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
                return intStr;
            }

            string operator+(unsigned int const& i) {
                string intStr;
                int value = i;

                while (value >= 0) {
                    intStr += (char)((value % 10) + 48);
                }
                return intStr;
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

            string &operator<<(unsigned int const& i) {
                *this = *this + i;
                return *this;
            }

            char &operator[](unsigned int index) {
                if (index >= size()) {
                    throw exception("index out of range");
                }
                return _chars[index];
            }

            string &operator=(string const& str) {
                clear();
                __realloc(str.size());
                for (unsigned int i = 0; i < str.size(); i++) {
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

            string &operator=(unsigned int const& i) {
                string intStr;

                intStr += i;
                *this = intStr;
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

            string &operator+=(unsigned int const& i) {
                return *this << i;
            }

            bool operator==(string const& str) {
                for (unsigned int i = 0; i < size(); i++) {
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
