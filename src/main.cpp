#include "extraction.h"


/*
 * Generates a catalog from a reference genome by extracting sequences
 * around sfb1 sites. Input should be the reference genome in FASTA format
 * and output is the catalog of relevant sequences in FASTA format.
 */


// Load reads file in memory and quickly access a read via its ID
int main(int argc, char *argv[]) {

    if (argc < 2){

        std::cerr << "Error: not enough arguments. \n" << "(Usage: ./generate_catalog filename)." << std::endl << std::endl;

        return -1;

    } else {

        // Open file from arguments
        std::string file_name = argv[1];
        std::ifstream reference_file;
        reference_file.open(file_name.c_str());

        std::string catalog_name = file_name.substr(0, file_name.size()-6) + "_catalog" + ".fasta"; // Add a "catalog" at the end of the file name
        std::ofstream catalog_file;
        catalog_file.open(catalog_name.c_str());

        std::string line = "";
        std::string contig = "";
        std::string sequence = "";

        uint count = 0;

        if (reference_file.is_open()){

            while(getline(reference_file, line)){

                if (line[0] == '>'){

                    extract_sbf1(sequence, count);
                    contig = line;
                    sequence = "";

                } else {

                    sequence += line;
                }
            }

            std::cout << "Extraction finished. Found " << count << " sfb1 sites.\n";

        } else {

            std::cerr << "Error : can't open the file """ << file_name << """, please check your input." << std::endl;

            return -2;
        }
    }

    return 0;

}
