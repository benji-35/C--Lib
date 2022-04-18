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

                if (!exists() || !pathValueExeists(pathValue))
                    return "";

                txtPath = string(pathValue).split(".");

                return "";
            }

            bool getBool(string const& pathValue) {
                string strRes = get(pathValue);

                strRes.toLower();
                if (strRes == "1" || strRes == "true")
                    return true;
                return false;
            }

            int getInt(string const& pathValue) {
                string strRes = get(pathValue);

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
