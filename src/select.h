#ifndef SELECT_H
#define SELECT_H
#include <sdsl/bit_vectors.hpp>
#include <sdsl/int_vector.hpp>
#include <bit>
#include <iostream>
#include <fstream>
#include "./rank.h"

using namespace std;
using namespace sdsl; 

class select_supp {
    public: 
        select_supp() {
            
        }
        select_supp(rank_supp* r) {
            rank_ptr = r;
        }
        uint64_t binary_rank(uint64_t x, uint64_t left, uint64_t right){
            if (left > right) {
                return -1; 
            } 
            else {
                uint64_t mid = (left + right) / 2;
                uint64_t tmp = rank_ptr->rank1(mid);
                if (tmp == x){
                    uint64_t smaller = binary_rank(x, left, mid - 1);
                    if (smaller == -1){
                        return mid; 
                    } else {
                        return smaller; 
                    }
                } else {
                    if (x > tmp){
                        return binary_rank(x, mid + 1, right);
                    } else {
                        return binary_rank(x, left, mid - 1);
                    }
                }
            }
        }
        uint64_t select1(uint64_t i) {
            uint64_t idx = binary_rank(i, 0, (*rank_ptr).get_bv()->size()-1);
            //cout << idx << endl;
            uint64_t store = idx;
            return store;
        }
        uint64_t overhead() {
            return rank_ptr->overhead();
        }
        void save(string& fname) {
            rank_ptr->save(fname); 
        }
        void load(string& fname) {
            rank_ptr->load(fname);
        }
    private:
        rank_supp* rank_ptr;
};

#endif