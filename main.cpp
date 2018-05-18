#include <stdio.h>
#include <iostream> 
#include <string.h> 
#include <vector>   
#include "BamHandler.h"
#include "FastaHandler.h"

int main(int argc, char **argv)
{
	printf("hello world\n");
	string region = "chr1"; 
	string what; 
	int size; 
	FastaHandler fasta_file = FastaHandler("chr1.fa"); 
	what = fasta_file.get_sequence(region); 
	size = fasta_file.get_chr_sequence_length(region); 
	cout << what << endl; 
	cout << size << endl; 
	return 0;
}
