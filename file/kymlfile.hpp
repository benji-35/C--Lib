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
#include "kmap.hpp"

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
                string path = pathValue;
                text txt = path.split(".");
                string key = txt[txt.size() - 1];

                txt.remove(txt.size() - 1);

                string gPath = txt.toString(".");
                
                map<string, string> got = getContentOfPath(gPath);

                if (!got.keyExists(key)) {
                    throw exception("no key found");
                } else {
                    return got.get(key);
                }
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

            map<string, string>getContentOfPath(string const& pathValue) {
                text txt = openT();
                map<string, string> res;

                if (txt.size() == 0)
                    return res;
                
            }

        private:
    };
}

#endif /* !KYMLFILE_HPP_ */
