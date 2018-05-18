#ifndef BAMHANDLER_H
#define BAMHANDLER_H

#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring> 
#include <vector>
#include <htslib/sam.h> 

using namespace std; 

typedef struct {
	string sequence;
	string cigar; 
	int mapping_quality; 
	int * base_quality; 
} read_t; 

class BamHandler
{
public:
	// Vector of read structs that hold the information about the read 
	vector<read_t> reads; 
	
	BamHandler(string path); 
	// Sets up read struct for use 
	void get_reads(string region, int start=0, int stop=0); 
	~BamHandler();
private: 
	htsFile* hts_file; 
	bam_hdr_t* header; 
	hts_itr_t* iter; 
	hts_idx_t* idx; 
	bam1_t* b; 
};

#endif // BAMHANDLER_H
