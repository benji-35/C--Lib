/*
** EPITECH PROJECT, 2022
** C++-Lib
** File description:
** kfile
*/

#ifndef KFILE_HPP_
#define KFILE_HPP_

#include "kstring.hpp"
#include "ktext.hpp"

#include <string>
#include <fstream>

namespace kap35 {
    class string;
    class text;
}

namespace kap35 {
    class file
    {
        public:
            file () {
                _path = "";
            }
            file(string const& path) {
                _path = path;
            }
            ~file() {}

            bool exists() {
                std::ifstream f(_path.toCharArray());
                return f.good();
            }

            text openT() {
                string str = openS();

                return str.split("\n");
            }

            string openS() {
                string res = "";
                if (!exists()) {
                    std::cerr << "the file " << _path.toCharArray() << " doesn't exists" << std::endl;
                    return res;
                }
                std::string line;
                std::ifstream myfile (_path.toCharArray());

                if (myfile.is_open())
                {
                    while ( getline (myfile,line) )
                    {
                        res += line.c_str();
                        res += "\n";
                    }
                    myfile.close();
                }
                return res;
            }

            void write(text const& txt) {
                write(txt.toString("\n"));
            }

            void write(string const& str) {
                if (!exists()) {
                    std::cerr << "the file " << _path.toCharArray() << " doesn't exists" << std::endl;
                    return;
                }
                std::ofstream myfile (_path.toCharArray());
                if (myfile.is_open())
                {
                    myfile << str.toCharArray();
                    myfile.close();
                }
            }

            void append(text const& txt) {
                append(txt.toString("\n"));
            }

            void append(string const& str) {
                if (!exists()) {
                    std::cerr << "the file " << _path.toCharArray() << " doesn't exists" << std::endl;
                    return;
                }
                text cTxt = openT();
                if (cTxt.size() == 1 && cTxt.get(0) == "") {
                    cTxt.clear();
                }
                cTxt += str;
                write(cTxt);
            }

            void insert(text const& txt, unsigned int pos) {
                if (!exists()) {
                    std::cerr << "the file " << _path.toCharArray() << " doesn't exists" << std::endl;
                    return;
                }
                text _cText = openT();
                if (_cText.size() == 0)
                    return write(txt);
                if (pos >= _cText.size()) {
                    pos = _cText.size() - 1;
                }
                text finalTxt;

                for (unsigned int i = 0; i < pos; i++) {
                    finalTxt += _cText.get(i);
                }

                finalTxt += txt;

                write(finalTxt);
            }

            void insert(string const& str, unsigned int pos) {
                string tmp = str;
                insert(tmp.split("\n"), pos);
            }

            void remove() {

            }

            void create() {

            }

        private:
            string _path;
    };

}

#endif /* !KFILE_HPP_ */
