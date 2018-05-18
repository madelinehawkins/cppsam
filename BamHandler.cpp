#include "BamHandler.h"
//#include <iostream>

//g++ -g -Wall -L/usr/local/lib -I/usr/local/lib -lhts main.cpp BamHandler.cpp -o main

BamHandler::BamHandler(string path)
{	
	this->iter = NULL; 
	this->hts_file = sam_open(path.c_str(), "r"); 
	// Setting up the header 
	this->header = sam_hdr_read(this->hts_file);  
	// Used to check if valid bam file
	if(this->hts_file == NULL || (this->header == 0)) fprintf(stderr, "Not a valid Bam File");
	
	// Setting up the indexing 
	this->idx = sam_index_load(this->hts_file, path.c_str()); 
	if(this->idx == NULL) fprintf(stderr, "No valid index file found"); 
	
	// Initialization of the bam 
	this->b = bam_init1();
}

BamHandler::~BamHandler()
{
}
void BamHandler::get_reads(string region, int start, int stop)
{
	//Switches the region name to an int for sam_itr_queryi function
	const int tid = bam_name2id(this->header, region.c_str());
	if (start == 0 && stop == 0) { 
		this->iter = sam_itr_querys(this->idx, this->header, region.c_str()); }
	else { 
		this->iter = sam_itr_queryi(this->idx, tid, start, stop); }
	int position = 0; 
	while(sam_itr_next(this->hts_file, this->iter, this->b) >= 0) { 
		string seq; 
		uint8_t *seqi = bam_get_seq(this->b);
		for (int i = 0; i < this->b->core.l_qseq; i++) {
			// seq_nt16_str grabs the letter since bam_seqi returns 4-bit representing the base
			seq.push_back(seq_nt16_str[bam_seqi(seqi, i)]);
		}
		// Getting the cigars
		uint32_t *cigar = bam_get_cigar(this->b); 
		string str_cigar; 
		for(int k = 0; k < this->b->core.n_cigar; k++) {
			const int op = bam_cigar_op(cigar[k]);
			const int ol = bam_cigar_oplen(cigar[k]);

			if (op == BAM_CMATCH || op == BAM_CINS || op == BAM_CDEL) {
			// your code, you have the length in ol (eg: 101M -> ol == 101
				str_cigar.append(to_string(ol)); 
				//The string version of it's a match/insert/deletion appended to the cigar
				str_cigar.push_back(bam_cigar_opchr(op)); 
			}
		}
		// Setting up the read_t struct with all the information from the read resizing the vector
		reads.resize(position + 1); 
		reads[position].sequence = seq; 
		reads[position].mapping_quality = b->core.qual; 
		reads[position].cigar = str_cigar; 
		position++; 
	}
}

