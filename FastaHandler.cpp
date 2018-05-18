#include "FastaHandler.h"

FastaHandler::FastaHandler(string path)
{
	this->fasta = fai_load(path.c_str()); 
	if (fasta == NULL) { fprintf(stderr, "No valid fasta file found"); }
}

FastaHandler::~FastaHandler()
{
}

string FastaHandler::get_sequence(string region, int start, int stop) {
	int len = 0; 
	// If specific start and stop regions are passed in 
	if (start == 0 || stop == 0) {
		sequence = fai_fetch(fasta, region.c_str(), &len); 
	}
	else {
		len = stop - start + 2;  
		sequence = faidx_fetch_seq(fasta, region.c_str(), start, stop, &len);
	}
	return sequence;  
}

int FastaHandler::get_chr_sequence_length(string chr){
	int len = 0; 
	const char * seq = fai_fetch(fasta, chr.c_str(), &len); 
	return strlen(seq); 
}
