#include <stdio.h>
#include <iostream> 
#include <string.h> 
#include <vector>   
#include "BamHandler.h"
#include "FastaHandler.h"
#include "VcfHandler.h"

int main(int argc, char **argv)
{
	printf("hello world\n");
	string region = "chr1"; 
	string what; 
	int size; 
	VcfHandler vcf_file = VcfHandler("NA12878_S1.genome.vcf.gz"); 
	return 0;
}
