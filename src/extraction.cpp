#include "extraction.h"

void extract_sbf1(std::string& sequence, std::string& contig, std::ofstream& output_file){

    size_t pos_f = sequence.find(sbf1_forward, 0);
    size_t pos_r = sequence.find(sbf1_reverse, 0);

    std::string sbf1_chunk = "";

    while(pos_f != std::string::npos){

        if (pos_f > chunk_size - 1){

            sbf1_chunk = sequence.substr(pos_f - chunk_size, 2*chunk_size+8); // Take 100 bp on each side of sbf1 site (sbf1 is 8 bp long)

        } else {

            sbf1_chunk = sequence.substr(0, 2*chunk_size+8); // In this case, we start where we can, at position 0
        }

        output_file << contig << "_" << pos_f << "\n" << sbf1_chunk << "\n";
        pos_f = sequence.find(sbf1_forward, pos_f+1);
    }

    while(pos_r != std::string::npos){

        if (pos_r > chunk_size - 1){

            sbf1_chunk = sequence.substr(pos_r - chunk_size, 2*chunk_size+8); // Take 100 bp on each side of sbf1 site (sbf1 is 8 bp long)

        } else {

            sbf1_chunk = sequence.substr(0, 2*chunk_size+8); // In this case, we start where we can, at position 0
        }

        output_file << contig << "_" << pos_r << "\n" << sbf1_chunk << "\n";
        pos_r = sequence.find(sbf1_reverse, pos_r+1);

    }
}
