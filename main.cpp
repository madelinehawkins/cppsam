#include <stdio.h>
#include <iostream> 
#include <string.h> 
#include "BamHandler.h"
int main(int argc, char **argv)
{
	printf("hello world\n");
	string region = "1"; 
	BamHandler bam_handle("example.bam");
	bam_handle.get_reads(region, 22466865, 22468000);
	
	return 0;
}
