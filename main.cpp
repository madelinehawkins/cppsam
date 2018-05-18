#include <stdio.h>
#include <iostream> 
#include <string.h> 
#include <vector>   
#include "BamHandler.h"

# define my_sizeof(type) ((char *)(&type+1)-(char*)(&type))

int main(int argc, char **argv)
{
	printf("hello world\n");
	string region = "1"; 
	BamHandler bam_handle("example.bam");
	bam_handle.get_reads(region);
	int n = bam_handle.reads.size(); //sizeof(bam_handle.reads) / sizeof(bam_handle.reads[0]);
	cout << n << endl; 
	for (int i = 0; i < n; i++) {
		cout << bam_handle.reads[i].sequence << endl;
		cout << bam_handle.reads[i].cigar << endl; 
	}
	return 0;
}
