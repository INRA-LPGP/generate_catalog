#pragma once

#include <sstream>
#include <vector>
#include <iostream>
#include <fstream>

// SFB1 sequences
const std::string sbf1_forward = "CCTGCAGG";
const std::string sbf1_reverse = "GGACGTCC";

const uint chunk_size = 100;

void extract_sbf1(std::string& sequence, std::string& contig, std::ofstream& output_file, uint& count);
