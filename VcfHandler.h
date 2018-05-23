#ifndef VCFHANDLER_H
#define VCFHANDLER_H

#include <htslib/vcf.h> 
#include <string> 
#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring> 
#include <vector>
#include <map> 

using namespace std; 


// Mimicing the VariantRecord class
typedef struct {
	// Mapping Quality
	int mq; 
	// Genotype Quality
	int gq; 
	// Depth
	int dp;
	// Position in the Chromosome 
	int pos;  // Done 
	// Reference Base in that position
	string ref; 
	// Quality of the record
	int qual; 
	// Class of the Genotype ('SNP', 'IN', 'DEL')
	string genotype_class;
	// length of the record
	int len; 
	// Alternate allele of the record
	string alt; 
	// 
} variant_record; 

// Populates the variant_record struct and has a function to allow for printing
class VariantRecord
{
public: 
	variant_record* var_rec; 
	VariantRecord(int mq, int gq, int dp, int pos, string ref, int qual, string genotype_class, int len, string alt);
	// Allows use to get the populated record 
	variant_record * get_record(); 
	void print_record(); 
	~VariantRecord(); 
};

class VcfHandler
{
public:
	VcfHandler(string file_path);
	void populate_dictionary(string contig, int start, int stop, bool hom_filters=false); 
	// Returns the genotype_map of variant records with key values based on position 
	map<int, variant_record> get_variant_map(); 
	int get_total_hom(); 
	int get_total_het(); 
	int get_total_hom_alt(); 
	~VcfHandler();
private: 
	variant_record* populated_record(bcf1_t * rec, bcf_hdr_t * hdr);
	htsFile * hts_file; 
	bcf_hdr_t * header; 
	bcf1_t * record; 
	hts_itr_t * iter; 
	hts_idx_t * idx; 
	
	// Vector of records in the region
	vector<variant_record> vcf_records; 
	// Mimicing the genotype_dict in the python code 
	map<int, variant_record> genotype_map;
	int total_hom;
	int total_het;
	int total_hom_alt;
	

};
#endif // VCFHANDLER_H
