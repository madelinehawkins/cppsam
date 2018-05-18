# cppsam

### Using the BamHandler class 
*BamHandler bam_handle("example.bam");* 
Must have a valid path to a bam file. Creates a BamHandler object
* bam_reads = get_reads(string region, int start, int stop)* 
This gets a vector of reads that contain the following information: 
  1. Sequence 
  2. Mapping Quality
  3. CIGAR String
 TODO: Get CIGAR Tuple and Base Quality 
You can treat the vector of reads like a normal vector for iteration. 
