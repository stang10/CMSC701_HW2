#ifndef SPARSE_H
#define SPARSE_H
#include <sdsl/bit_vectors.hpp>
#include <sdsl/int_vector.hpp>
#include <bit>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "./rank.h"
#include "./select.h"

using namespace std;
using namespace sdsl; 

class sparse_array
{
    public: 
        sparse_array() {
            //apparently bitvectors must be larger than 1
            b = bit_vector(2);
            rs = rank_supp(&b);
            s = select_supp(&rs);
            finalized = false; 
        }
        void create(uint64_t size) {
            b = bit_vector(size); 
        }
        void append(string elem, uint64_t pos){
            if (!finalized && (pos < b.size())){
                strings.push_back(elem);
                b[pos] = 1;
            }
        }
        void finalize() {
            finalized = true; 
            rs = rank_supp(&b);
            s = select_supp(&rs);
        }
        bool get_at_rank(uint64_t r, std::string& elem) {
            if (finalized){
                if ((r > 0) && r <= strings.size()){
                    elem = strings[r-1];
                    return true; 
                } else {
                    return false;
                }
            } else {
                return false; 
            }
            
        }
        bool get_at_index(uint64_t r, std::string& elem) {
            if (finalized){
                if (b[r] == 1){
                    uint64_t rank = rs.rank1(r); 
                    elem = strings[rank];
                    return true;
                } else {
                    return false; 
                }
            } else {
                return false;
            }
        }
        uint64_t get_index_of(uint64_t r) {
            if (finalized){
                if ((r < 1) || (r > strings.size())){
                    return numeric_limits<uint64_t>::max(); 
                } else {
                    return (s.select1(r) - 1);
                }
            } else {
                return numeric_limits<uint64_t>::max(); 
            }
        }
        uint64_t num_elem_at(uint64_t r) {
            if (finalized) {
                return (rs.rank1(r) + b[r]); 
            } else {
                return  -1; 
            }
        }
        uint64_t size() {
            return b.size(); 
        }
        uint64_t num_elem() {
            return strings.size();
        }
        void save(string& fname){
            s.save(fname); 
            std::ofstream OutputFile(fname, std::ios::app);
            OutputFile << finalized; 
            OutputFile.close(); 
        }
        void load(string& fname){
            s.load(fname);
            uint64_t blen, cl, sb, sl;
            std::ifstream InputFile(fname, std::ios::in);
            string tmp;
            //bbits
            getline(InputFile,tmp);
            //blen 
            getline(InputFile,tmp);
            blen = stoll(tmp);
            for (size_t i = 0; i < blen; ++i) {
                getline(InputFile,tmp);
            }
            //cbits
            getline(InputFile,tmp);
            //clen
            getline(InputFile,tmp);
            cl = stoll(tmp);
            for (size_t i = 0; i < cl; ++i) {
                getline(InputFile,tmp);
            }
            //sbits
            getline(InputFile,tmp);
            //slen
            getline(InputFile,tmp);
            sl = stoll(tmp);
            for (size_t i = 0; i < sl; ++i) {
                getline(InputFile,tmp);
            }
            getline(InputFile,tmp);
            finalized = stoll(tmp);
            InputFile.close();
        }
        uint64_t overhead() {
            return s.overhead();
        }
    private: 
        bit_vector b;
        std::vector<string> strings;
        rank_supp rs; 
        select_supp s; 
        bool finalized; 

};

#endif