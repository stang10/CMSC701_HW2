#ifndef RANK_H
#define RANK_H
#include <sdsl/bit_vectors.hpp>
#include <sdsl/int_vector.hpp>
#include <bit>
#include <iostream>
#include <fstream>

using namespace std;
using namespace sdsl; 

class rank_supp {
    public: 
        rank_supp(){
            
        }
        rank_supp(bit_vector* bv){
            b = bv; 
            // n = (*b).size();
            // clen = ceil(pow(log2(double(n)),2));
            // ccount = ceil(double(n)/pow(log2(double(n)),2));
            // slen = ceil(0.5*log2(double(n)));
            // scount = ceil(double(clen)/double(slen));
            // cbits = ceil(log2(n));
            // sbits = ceil(log2(pow(log2(n),2)));
            compute_counts();
            chunks = int_vector<>(ccount, 0, cbits);
            subchunks = int_vector<>((scount*ccount), 0, sbits); 

            int sub = 0; 
            for (int i = 0; i < ccount; i++){
                int ctrack = 0;
                int cstart = i*clen; 
                int strack = 0; 
                for (int j = 0; j < clen; j = (j + slen)){
                    int sstart = cstart + j;
                    for (int k = 0; k < slen; k++){
                        if (sstart+k < n) {
                            if ((*b)[sstart+k] == 1){
                                strack++;
                            }
                        }
                    }
                    subchunks[sub] = strack;
                    sub++;
                }
                if ((i+1) < ccount) {
                    chunks[i+1] = strack;
                }
            }

            // for (int i = 0; i < chunks.size(); i++){
            //     std::cout << "chunks i: " << i << " " << chunks[i] << "\n";
            // }
            // for (int i = 0; i < subchunks.size(); i++){
            //     std::cout << "subchunks i: " << i << " " << subchunks[i] << "\n";
            // }
        }
        uint64_t rank1(uint64_t i) {
            uint64_t chunk = floor(double(i)/pow(log2(double(n)),2));
            uint64_t subchunk = ((i-(chunk*clen))/slen);
            uint64_t idx = (chunk*clen) + (subchunk*slen);
            uint64_t rank = chunks[chunk];
            if (subchunk != 0){
                rank = rank + subchunks[chunk*scount + (subchunk-1)];
                //cout << " Rank subchunk: " << rank;
            }
            rank = rank + std::popcount((*b).get_int(idx, (i-idx)));
            return rank; 
        }
        uint64_t overhead(){
            std::cout << "chunk: " << ccount << " " << cbits << std::endl;
            std::cout << "subchunk: " << scount*ccount << " " << sbits << std::endl;
            std::cout << "chunk bytes " << size_in_bytes(chunks) << std::endl;
            std::cout << "subchunk bytes " << size_in_bytes(subchunks) << std::endl;
            return (size_in_bytes(chunks) + size_in_bytes(subchunks))*8; 
        }
        void save(string& fname) {
            std::ofstream OutputFile(fname, std::ios::out);
            OutputFile << (int)(*b).width() << "\n";
            OutputFile << (*b).size() << "\n";
            for (size_t i = 0; i < (*b).size(); ++i) {
                OutputFile << (*b)[i] << "\n";
            }
            OutputFile << (int)chunks.width() << "\n";
            OutputFile << chunks.size() << "\n";
            for (size_t i = 0; i < chunks.size(); ++i) {
                OutputFile << chunks[i] << "\n";
            }
            OutputFile << (int)subchunks.width() << "\n";
            OutputFile << subchunks.size() << "\n";
            for (size_t i = 0; i < subchunks.size(); ++i) {
                OutputFile << subchunks[i] << "\n";
            }
            OutputFile.close();
        }
        void load(string& fname) {
            std::ifstream InputFile(fname, std::ios::in);
            uint64_t bbits, blen, cb, cl, sb, sl;
            string tmp;
            getline(InputFile,tmp);
            bbits = stoll(tmp);
            // if (bbits != (*bitvector).bits()){
            //     std::cout << "Cannot load, bitvector bits is wrong" << std::endl;
            //     InputFile.close();
            //     return;
            // }
            getline(InputFile,tmp);
            blen = stoll(tmp);
            bit_vector bv(blen, 0);
            //compact::vector<uint64_t> bv(bbits, blen);
            for (size_t i = 0; i < blen; ++i) {
                getline(InputFile,tmp);
                bv[i] = stoll(tmp);
            }
            swap(*b, bv);

            getline(InputFile,tmp);
            cb = stoll(tmp);
            // if (cbits != chunks.bits()){
            //     std::cout << "Cannot load, chunk bits is wrong" << std::endl;
            //     InputFile.close();
            //     return;
            // }
            getline(InputFile,tmp);
            cl = stoll(tmp);
            //compact::vector<uint64_t> cv(cbits, clen);
            chunks = int_vector<>(cl, 0, cb);
            for (size_t i = 0; i < cl; ++i) {
                getline(InputFile,tmp);
                chunks[i] = stoll(tmp);
            }

            getline(InputFile,tmp);
            sb = stoll(tmp);
            // if (sbits != subchunks.bits()){
            //     std::cout << "Cannot load, subchunk bits is wrong" << std::endl;
            //     InputFile.close();
            //     return;
            // }
            getline(InputFile,tmp);
            sl = stoll(tmp);
            //compact::vector<uint64_t> sv(sbits, slen);
            subchunks = int_vector<>(sl, 0, sb);
            for (size_t i = 0; i < sl; ++i) {
                getline(InputFile,tmp);
                subchunks[i] = stoll(tmp);
            }
              
            // for (size_t i = 0; i < (*b).size(); ++i) {
            //     std::cout << "bi: " << i << " " << (*b)[i] << "\n";
            // }
            // //std::swap(chunks, cv);
            // for (size_t i = 0; i < chunks.size(); ++i) {
            //     std::cout << "ci: " << i << " " << chunks[i] << "\n";
            // }
            // //std::swap(subchunks, sv);
            // for (size_t i = 0; i < subchunks.size(); ++i) {
            //     std::cout << "si: " << i << " " << subchunks[i] << "\n";
            // }
            compute_counts(); 
            InputFile.close();
        }
        void compute_counts(){
            n = (*b).size();
            clen = ceil(pow(log2(double(n)),2));
            ccount = ceil(double(n)/pow(log2(double(n)),2));
            slen = ceil(0.5*log2(double(n)));
            scount = ceil(double(clen)/double(slen));
            cbits = ceil(log2(n));
            sbits = ceil(log2(pow(log2(n),2)));
        }
        bit_vector* get_bv(){
            return b; 
        }
    private:
        bit_vector* b;
        int_vector<> chunks;
        int_vector<> subchunks;
        uint64_t n, clen, ccount, slen, scount, cbits, sbits;

};

#endif