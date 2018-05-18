#ifndef BAMHANDLER_H
#define BAMHANDLER_H

#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring> 
#include <vector>
#include <htslib/sam.h> 

using namespace std; 

/* ! @typedef
 * @abstract Structure containing the information about the read 
 * @field sequence			The Sequence of nucleotides written as a string
 * @field cigar				The CIGAR string of the current sequence
 * @field mapping_quality	The mapping quality of the sequence to the reference
 * @field base_quality		An array of all the bases and their quality 
 */
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
	/* ! @function 
	* Gets the reads that map to a specific position that is given 
	* 
	* @param self: a pointer to the struct
	* @param region: which chromosome you are interested in 
	* @param start: start position of the specific site you're looking at
	* @param stop: stop position of the specific site you're looking at 
	* @returns: Reads that map to a specific site 
	*/
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
