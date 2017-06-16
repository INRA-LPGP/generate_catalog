#include "extraction.h"

void extract_sbf1(std::string& sequence, uint& count){

    size_t pos = std::string::npos;

    for (auto s: sites) {

        pos = sequence.find(s, 0);

        while(pos != std::string::npos){
            pos = sequence.find(s, pos+1);
            ++count;
        }
    }
}
