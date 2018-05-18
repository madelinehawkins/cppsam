#ifndef FASTAHANDLER_H
#define FASTAHANDLER_H

#include <htslib/faidx.h> 
#include <string> 
#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring> 
#include <vector>

using namespace std; 

class FastaHandler
{
public:
	FastaHandler(string path);
	string get_sequence(string region, int start=0, int stop=0);
	int get_chr_sequence_length(string chr); 
	~FastaHandler();
private: 
	faidx_t* fasta; 
	const char * sequence;
};

#endif // FASTAHANDLER_H
