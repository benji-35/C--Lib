/*
** EPITECH PROJECT, 2022
** C++-Lib
** File description:
** kymlfile
*/

#ifndef KYMLFILE_HPP_
#define KYMLFILE_HPP_

#include "kstring.hpp"
#include "ktext.hpp"
#include "kfile.hpp"

namespace kap35 {
    class text;
    class string;
    class file;
}

namespace kap35 {

    class ymlFile : public file {
        public:
            ymlFile(string const& path, bool autoCreate = false) : file(path, autoCreate) {
            }
            ~ymlFile() {

            }

            string get(string const& pathValue) {
                string strPath = pathValue;
                text txtPath(strPath.split("."));
                unsigned int curr = 0;

                if (!exists() || !pathValueExeists(pathValue))
                    throw exception("value does not exist");

                txtPath = string(pathValue).split(".");
                text txt;
                txt = openT();

                for (unsigned int i = 0; i < txt.size(); i++) {
                    string tryStr;

                    for (unsigned int x = 0; x < curr; x++)
                        tryStr += "  ";
                    tryStr += txtPath.get(curr) + ":";
                    if (txt.get(i).startWith(tryStr)) {
                        if (curr == pathValue.size()) {
                            text values;
                            values = txt.get(i).split((tryStr + " "), 2);
                            return values[1].copy();
                        }
                        curr++;
                    }
                }

                throw exception("value does not exist");
            }

            bool getBool(string const& pathValue) {
                string strRes;

                try {
                    strRes = get(pathValue);
                } catch(exception e) {
                    throw exception(e.what());
                }

                strRes.toLower();
                if (strRes == "1" || strRes == "true")
                    return true;
                return false;
            }

            int getInt(string const& pathValue) {
                string strRes;

                try {
                    strRes = get(pathValue);
                } catch(exception e) {
                    throw exception(e.what());
                }

                return strRes.toInt();
            }

            bool pathValueExeists(string const& pathValue) {
                string strPath = pathValue;
                text txtPath(strPath.split("."));

                if (!exists())
                    return false;

                text content(openT());

                for (unsigned int i = 0; i < content.size(); i++) {
                    
                }

                return false;
            }

            list<string> getArray(string const& pathValue) {
                list<string> res;

                return res;
            }

        private:
    };

}

#endif /* !KYMLFILE_HPP_ */
