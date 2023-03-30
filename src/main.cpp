#include <sdsl/bit_vectors.hpp>
#include <sdsl/int_vector.hpp>
#include <iostream>
#include "./rank.h"
#include "./select.h"
#include "./sparse.h"

using namespace std;
using namespace sdsl;

int main()
{
    bit_vector b(32, 0);
    b[1] = 1;
    b[3] = 1;
    b[4] = 1;
    b[5] = 1;
    b[6] = 1;
    b[7] = 1;
    b[9] = 1;
    b[11] = 1;
    b[15] = 1;
    b[28] = 1;
    b[30] = 1;
    cout << "b[8]: " << b[8] << endl;
    cout << "size " << b.size() << endl;
    int_vector<> v(100, 5, 7);
    uint8_t test = v.width();
    cout << v.empty() << endl;
    cout << (int)test << endl;
    v = int_vector<>(10,3,9);
    cout << (int)v.width() << endl;
    cout << v[9] << endl;

    rank_supp r(&b);
    for (int i = 0; i < b.size(); i++){
        std::cout << "rank i: " << i << " " << r.rank1(i) << "\n";
    }
    cout << r.overhead() << endl;

    string f = "./output/test.txt";
    r.save(f);
    bit_vector b2(16, 0);
    b2[3] = 1;
    rank_supp r2(&b2);
    for (int i = 0; i < b2.size(); i++){
        std::cout << "rank i: " << i << " " << r2.rank1(i) << "\n";
    } 
    r2 = r;
    for (int i = 0; i < b.size(); i++){
        std::cout << "rank2 i: " << i << " " << r2.rank1(i) << "\n";
    }  
    cout << "Select" << endl;
    select_supp s(&r);
    cout << s.select1(32) << endl;
    cout << s.select1(8) << endl;
    cout << s.select1(3) << endl;
    cout << s.select1(9) << endl;
    cout << s.select1(11) << endl;
    s.save(f);
    bit_vector b3(16, 0);
    rank_supp r3(&b3);
    select_supp s2(&r3);
    cout << s2.select1(32) << endl;
    cout << s2.select1(8) << endl;
    cout << s2.select1(3) << endl;
    cout << s2.select1(9) << endl;
    cout << s2.select1(11) << endl;
    s2.load(f);
    cout << s2.select1(32) << endl;
    cout << s2.select1(8) << endl;
    cout << s2.select1(3) << endl;
    cout << s2.select1(9) << endl;
    cout << s2.select1(11) << endl;
    bit_vector b4(16, 0);
    rank_supp r4(&b4);
    select_supp s3(&r4);
    cout << "Select Reassign" << endl;
    cout << s3.select1(32) << endl;
    cout << s3.select1(8) << endl;
    cout << s3.select1(3) << endl;
    cout << s3.select1(9) << endl;
    cout << s3.select1(11) << endl;
    s3 = s2;
    cout << s3.select1(32) << endl;
    cout << s3.select1(8) << endl;
    cout << s3.select1(3) << endl;
    cout << s3.select1(9) << endl;
    cout << s3.select1(11) << endl;
    sparse_array sa = sparse_array(); 
    sa.create(32);
    sa.append("test1", 4);
    sa.append("test2", 7);
    sa.append("test3", 11);
    sa.append("test4", 15);
    sa.finalize(); 
    cout << "Created" << endl; 
    string x = "none";
    sa.get_at_rank(0, x);
    cout << x << endl;
    sa.get_at_rank(2, x);
    cout << x << endl; 
    x = "none2";
    sa.get_at_index(0, x);
    cout << x << endl; 
    sa.get_at_index(15,x);
    cout << x << endl; 
    cout << sa.get_index_of(2) << endl;
    cout << sa.get_index_of(4) << endl;
    cout << sa.get_index_of(5) << endl;
    cout << sa.get_index_of(0) << endl;
    cout << sa.num_elem_at(14) << endl;
    cout << sa.num_elem_at(15) << endl;
    cout << sa.num_elem_at(16) << endl;
    sa.save(f); 
    sparse_array sa2 = sparse_array(); 
    sa2.create(32);
    sa2.append("test1", 4);
    sa2.append("test2", 7);
    sa2.load(f);
    x = "none3";
    sa.get_at_rank(0, x);
    cout << x << endl;
    sa.get_at_rank(4, x);
    cout << x << endl; 
    cout << sa.num_elem_at(16) << endl;
    return 0; 
}