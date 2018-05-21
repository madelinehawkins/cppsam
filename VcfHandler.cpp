#include "VcfHandler.h"

VariantRecord::VariantRecord(mq, gq, dp, pos, ref, qual, genotype_class, len, alt) {
	var_rec->mq = mq; 
	var_rec->gq = gq; 
	var_rec->dp = dp; 
	var_rec->pos = pos; 
	var_rec->ref = ref; 
	var_rec->qual = qual; 
	var_rec->genotype_class = genotype_class; 
	var_rec->len = len; 
	var_rec->alt = alt; 
}

variant_record * VariantRecord::get_record() {
	return var_rec; 
}


VcfHandler::VcfHandler(string file_path)
{
	this->total_het = 0;
	this->total_hom = 0; 
	this->total_hom_alt = 0; 
	
	htsFile * vcf = 
	
}

void VcfHandler::populate_record() {
	
}

void VcfHandler::populate_dictionary(string contig, int start, int stop, bool hom_filters=False) {
	
}

VcfHandler::~VcfHandler()
{
}

