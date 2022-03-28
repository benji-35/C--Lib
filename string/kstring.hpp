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
                _chars = new char[_size + 1]();
                for (unsigned int i = 0; i < _size; i++)
                    _chars[i] = str[i];
            }

            string(string const& str) {
                clear();
                *this = str;
            }

            string(char const c) {
                __realloc(1);
                _chars[0] = c;
                _chars[1] = 0;
            }

            ~string() {
                if (_chars != nullptr)
                    delete _chars;
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
                delete _chars;
                _chars = new char[1]();
                _chars[0] = 0;
            }

            unsigned int find(string str, unsigned int pos = 0, unsigned int end = -1) {
                if (end == -1)
                    end = size();
                for (unsigned int i = pos; i < end; i++) {
                    unsigned int x = 0;
                    for (; x < str.size(); x++) {
                        if (str[x] != (*this)[i + x])
                            break;
                    }
                    if (x >= str.size()) {
                        return i;
                    }
                }
                return size();
            }

            unsigned int find(char const& c, unsigned int pos = 0, unsigned int end = -1) {
                string str(c);

                return find(str, pos, end);
            }

            list<string> split(string splitter, int nbSplits = -1) {
                list<string> _ltext;

                unsigned int curr = 0;
                unsigned int found = 0;
                unsigned int sizeSplitter = splitter.size();
                while (curr < size()) {
                    if (nbSplits == 0)
                        break;
                    found = find(splitter, curr);
                    if (found != 0 && found != size()) {
                        _ltext.push_back(copy(curr, found - 1));
                    }
                    curr += sizeSplitter;
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

            void insert(char const& c, unsigned int pos = 0) {
                insert(string(c), pos);
            }

            char &at(unsigned int index) const {
                unsigned int _size = size();
                if (index >= _size)
                    return _chars[_size - 1];
                return _chars[index];
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

            string &operator<<(string const& str) {
                *this = *this + str;
                return *this;
            }

            string &operator<<(char const& c) {
                *this = *this + c;
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

            string &operator+=(string const& str) {
                return *this << str;
            }

            string &operator+=(char const& c) {
                return *this << c;
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
                char *_nchars = new char[_size + 1]();

                for (unsigned int i = 0; i < size(); i++) {
                    if (i >= _size)
                        break;
                    _nchars[i] = _chars[i];
                }
                _nchars[_size] = 0;
                delete _chars;
                _chars = _nchars;
            }

            char *_chars = nullptr;
    };

}

#endif /* !KSTRING_HPP_ */
