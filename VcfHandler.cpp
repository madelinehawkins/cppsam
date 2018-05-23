#include "VcfHandler.h"
#include <stdexcept>

VariantRecord::VariantRecord(variant_record* rec) {
	
}

VcfHandler::VcfHandler(string file_path)
{
	this->total_het = 0;
	this->total_hom = 0; 
	this->total_hom_alt = 0; 
	
	// Opening the VCF file
	this->hts_file = bcf_open(file_path.c_str(), "r");  
	if(this->hts_file == NULL) {
		throw runtime_error("Unable to open file.");
	}
	this->header = bcf_hdr_read(hts_file);
	if(this->header == NULL) {
		throw runtime_error("Unable to read header.");
	}
	this->record = bcf_init();
	cout << "chromosome\tposition\tnum_alleles" << endl;
	while(bcf_read(hts_file, header, record) == 0) {
		populated_record(record, header); 
	}
}

int VcfHandler::get_total_hom() {
	return this->total_hom; 
}
int VcfHandler::get_total_het() {
	return this->total_het; 
} 
int VcfHandler::get_total_hom_alt() {
	return this->total_hom_alt; 
}

map<int, vector<variant_record> > VcfHandler::get_variant_map() {
	return this->genotype_map; 
}


variant_record*  VcfHandler::populated_record(bcf1_t * rec, bcf_hdr_t * hdr) {
	bcf_unpack(record, BCF_UN_ALL);
	
	
	
	variant_record tmp_rec; 
	tmp_rec.pos = rec->pos; 
	tmp_rec.qual = rec->qual;
	tmp_rec.ref = string(rec->d.allele[0]);
	tmp_rec.alt = string(rec->d.als); 
	tmp_rec.len = rec->rlen; 
	
	cout << rec->d.n_var << endl; 
	
//	cout << bcf_hdr_id2name(hdr, record->rid) << "\t" <<
//						rec->pos << "\t" <<
//						rec->n_allele << "\t" <<
//						rec->qual << "\t" <<
//						rec->rlen << "\t" <<
//						bcf_get_variant_types(rec) << "\t" << 
//						rec->d.als << "\t" << 
//						endl;
}

void VcfHandler::populate_dictionary(string contig, int start, int stop, bool hom_filters) {
	
}

VcfHandler::~VcfHandler()
{
}

