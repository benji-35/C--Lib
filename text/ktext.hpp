/*
** EPITECH PROJECT, 2022
** C++-Lib
** File description:
** ktext
*/

#ifndef KTEXT_HPP_
#define KTEXT_HPP_


// #include "kstring.hpp"
#include <iostream>
#include "klist.hpp"
#include "kstring.hpp"

namespace kap35 {
    class string;
}

namespace kap35
{
    class text {
        public:
            text() {
                _text.pushBack("");
            }
            text(string const& str) {
                _text.pushBack(str);
            }
            text(string const& str, string splitter, int nb = -1) {
                string _str = str;
                _text = _str.split(splitter, nb);
            }
            text(text const& txt) {
                *this = txt;
            }
            text(list<string> const& l) {
                *this = l;
            }

            ~text() {}

            size_t size() const {
                return _text.size();
            }

            string &get(size_t index) {
                if (index >= size())
                    throw Exception::TextError(string("index out of range").toCharArray());
                return _text.at(index);
            }

            string &getC(size_t index) const {
                if (index >= size())
                    throw Exception::TextError(string("index out of range").toCharArray());
                return _text.at(index);
            }

            string toString(string separator = "") const {
                string res;

                for (size_t i = 0; i < size(); i++) {
                    if (i == 0) {
                        res += _text.at(i);
                    } else {
                        res += separator + _text.at(i);
                    }
                }

                return res;
            }

            text &operator=(text const& t) {
                _text = t._text;
                return *this;
            }

            text operator+(text const&t) {
                text txt(*this);

                for (size_t i = 0; i < t.size(); i++) {
                    txt._text.pushBack(t.getC(i));
                }
                return txt;
            }

            text &operator+=(text const& t) {
                *this = *this + t;
                return *this;
            }

            text &operator=(string const& t) {
                _text.clear();
                _text.pushBack(t);
                return *this;
            }

            text operator+(string const& t) {
                text txt(*this);

                txt._text.pushBack(t);
                return txt;
            }

            text &operator+=(string const& t) {
                *this = *this + t;
                return *this;
            }

            text &operator=(list<string> const& l) {
                _text.clear();
                _text = l;
                return *this;
            }

            string &operator [](size_t index) const {
                return getC(index);
            }

            void add(string const& str) {
                *this + str;
            }

            void addBack(string const& str) {
                add(str);
            }

            void addFront(string const& str) {
                _text.pushFront(str);
            }

            void insert(string str, size_t line = 0, size_t posInLine = 0) {
                size_t _size = size();
                if (line >= _size)
                    line = _size - 1;
                string &_str = get(line);
                _str.insert(str, posInLine);
            }

            void remove(size_t index) {
                if (index >= size())
                    index = size();
                _text.popAt(index);
            }

            void dump(string splitter = "\n") {
                for (size_t i = 0; i < _text.size(); i++) {
                    try {
                        std::cout << get(i).toCharArray();
                        std::cout << splitter.toCharArray();
                    } catch(...) {}
                }
            }

            void clear() {
                _text.clear();
            }

            void removeEmptyLines() {
                bool back = false;
                for (size_t i = 0; i < size(); i++) {
                    if (back) {
                        i--;
                        back = false;
                    }
                    if (get(i) == "") {
                        remove(i);
                        back = true;
                    }
                }
            }

            friend std::ostream &operator<<(std::ostream & os, text const& str) {
                for (unsigned int i = 0; i < str.size(); i++) {
                    os << str.getC(i);
                    if (i < str.size() - 1)
                        os << '\n';
                }
                return os;
            }

        private:
            list<string> _text;
    };

}

#endif /* !KTEXT_HPP_ */
