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
                _text.push_back("");
            }
            text(string const& str) {
                string _str = str;
                _text.push_back(_str);
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

            unsigned int size() const {
                return _text.size();
            }

            string &get(unsigned int index) {
                return _text.at(index);
            }

            string &getC(unsigned int index) const {
                return _text.get(index);
            }

            string toString(string separator = "") const {
                string res;

                for (unsigned int i = 0; i < size(); i++) {
                    if (i == 0) {
                        res += _text.get(i);
                    } else {
                        res += separator + _text.get(i);
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

                for (unsigned int i = 0; i < t.size(); i++) {
                    txt._text.push_back(t.getC(i));
                }
                return txt;
            }

            text &operator+=(text const& t) {
                *this = *this + t;
                return *this;
            }

            text &operator=(string const& t) {
                _text.clear();
                _text.push_back(t);
                return *this;
            }

            text operator+(string const& t) {
                text txt(*this);

                txt._text.push_back(t);
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

            void add(string const& str) {
                *this + str;
            }

            void addBack(string const& str) {
                add(str);
            }

            void addFront(string const& str) {
                _text.push_front(str);
            }

            void insert(string str, unsigned int line = 0, unsigned int posInLine = 0) {
                unsigned int _size = size();
                if (line >= _size)
                    line = _size - 1;
                string &_str = get(line);
                _str.insert(str, posInLine);
            }

            void remove(unsigned int index) {
                if (index >= size())
                    index = size();
                _text.pop_at(index);
            }

            void dump(string splitter = "\n") {
                for (unsigned int i = 0; i < _text.size(); i++) {
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
                for (unsigned int i = 0; i < size(); i++) {
                    if (back) {
                        i--;
                        back = false;
                    }
                    if (get(i) == "") {
                        std::cout << "remove line " << std::to_string(i) << std::endl;
                        remove(i);
                        back = true;
                    }
                }
            }

        private:
            list<string> _text;
    };

    std::ostream& operator<<(std::ostream& os, const text& dt) {
        for (unsigned int i = 0; i < dt.size(); i++) {
            os << dt.getC(i).toCharArray() << "\n";
        }
        return os;
    }

} // namespace kap35

#endif /* !KTEXT_HPP_ */
