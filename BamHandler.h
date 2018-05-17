#ifndef BAMHANDLER_H
#define BAMHANDLER_H

#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring> 
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
	read_t* reads; 
public:
	BamHandler(string path); 
	// Sets up read struct for use 
	void get_reads(string region, int start, int stop); 
	~BamHandler();
private: 
	htsFile* hts_file; 
	bam_hdr_t* header; 
	hts_itr_t* iter; 
	hts_idx_t* idx; 
	bam1_t* b; 
};

#endif // BAMHANDLER_H
