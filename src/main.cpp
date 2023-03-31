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
    // bit_vector b(32, 0);
    // b[1] = 1;
    // b[3] = 1;
    // b[4] = 1;
    // b[5] = 1;
    // b[6] = 1;
    // b[7] = 1;
    // b[9] = 1;
    // b[11] = 1;
    // b[15] = 1;
    // b[28] = 1;
    // b[30] = 1;
    // cout << "b[8]: " << b[8] << endl;
    // cout << "size " << b.size() << endl;
    // int_vector<> v(100, 5, 7);
    // uint8_t test = v.width();
    // cout << v.empty() << endl;
    // cout << (int)test << endl;
    // v = int_vector<>(10,3,9);
    // cout << (int)v.width() << endl;
    // cout << v[9] << endl;

    // rank_supp r(&b);
    // for (int i = 0; i < b.size(); i++){
    //     std::cout << "rank i: " << i << " " << r.rank1(i) << "\n";
    // }
    // cout << r.overhead() << endl;

    // string f = "./output/test.txt";
    // r.save(f);
    // bit_vector b2(16, 0);
    // b2[3] = 1;
    // rank_supp r2(&b2);
    // for (int i = 0; i < b2.size(); i++){
    //     std::cout << "rank i: " << i << " " << r2.rank1(i) << "\n";
    // } 
    // r2 = r;
    // for (int i = 0; i < b.size(); i++){
    //     std::cout << "rank2 i: " << i << " " << r2.rank1(i) << "\n";
    // }  
    // cout << "Select" << endl;
    // select_supp s(&r);
    // cout << s.select1(32) << endl;
    // cout << s.select1(8) << endl;
    // cout << s.select1(3) << endl;
    // cout << s.select1(9) << endl;
    // cout << s.select1(11) << endl;
    // s.save(f);
    // bit_vector b3(16, 0);
    // rank_supp r3(&b3);
    // select_supp s2(&r3);
    // cout << s2.select1(32) << endl;
    // cout << s2.select1(8) << endl;
    // cout << s2.select1(3) << endl;
    // cout << s2.select1(9) << endl;
    // cout << s2.select1(11) << endl;
    // s2.load(f);
    // cout << s2.select1(32) << endl;
    // cout << s2.select1(8) << endl;
    // cout << s2.select1(3) << endl;
    // cout << s2.select1(9) << endl;
    // cout << s2.select1(11) << endl;
    // bit_vector b4(16, 0);
    // rank_supp r4(&b4);
    // select_supp s3(&r4);
    // cout << "Select Reassign" << endl;
    // cout << s3.select1(32) << endl;
    // cout << s3.select1(8) << endl;
    // cout << s3.select1(3) << endl;
    // cout << s3.select1(9) << endl;
    // cout << s3.select1(11) << endl;
    // s3 = s2;
    // cout << s3.select1(32) << endl;
    // cout << s3.select1(8) << endl;
    // cout << s3.select1(3) << endl;
    // cout << s3.select1(9) << endl;
    // cout << s3.select1(11) << endl;
    // sparse_array sa = sparse_array(); 
    // sa.create(32);
    // sa.append("test1", 4);
    // sa.append("test2", 7);
    // sa.append("test3", 11);
    // sa.append("test4", 15);
    // sa.finalize(); 
    // cout << "Created" << endl; 
    // string x = "none";
    // sa.get_at_rank(0, x);
    // cout << x << endl;
    // sa.get_at_rank(2, x);
    // cout << x << endl; 
    // x = "none2";
    // sa.get_at_index(0, x);
    // cout << x << endl; 
    // sa.get_at_index(15,x);
    // cout << x << endl; 
    // cout << sa.get_index_of(2) << endl;
    // cout << sa.get_index_of(4) << endl;
    // cout << sa.get_index_of(5) << endl;
    // cout << sa.get_index_of(0) << endl;
    // cout << sa.num_elem_at(14) << endl;
    // cout << sa.num_elem_at(15) << endl;
    // cout << sa.num_elem_at(16) << endl;
    // sa.save(f); 
    // sparse_array sa2 = sparse_array(); 
    // sa2.create(32);
    // sa2.append("test1", 4);
    // sa2.append("test2", 7);
    // sa2.load(f);
    // x = "none3";
    // sa.get_at_rank(0, x);
    // cout << x << endl;
    // sa.get_at_rank(4, x);
    // cout << x << endl; 
    // cout << sa.num_elem_at(16) << endl;

    cout << "-----Testing for Task 1-----" << endl;
    cout << "Bitvector size: 32" << endl;
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
    rank_supp r(&b);
    auto begin = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 10; i++){
        //cout << "test idx: " << i*32/10 << endl;
        r.rank1(i*32/10);
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin);
    cout << "Time taken for 10 rank lookups: " << duration.count() << " nanoseconds" << endl;
    cout << "Overhead: " << r.overhead() << " bits\n" << endl;
    
    cout << "Bitvector size: 100" << endl;
    b = bit_vector(100, 0);
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
    b[50] = 1; 
    b[73] = 1;
    r = rank_supp(&b);
    begin = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 10; i++){
        //cout << "test idx: " << i*100/10 << endl;
        r.rank1(i*100/10);
    }
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin);
    cout << "Time taken for 10 rank lookups: " << duration.count() << " nanoseconds" << endl;
    cout << "Overhead: " << r.overhead() << " bits\n" << endl;

    cout << "Bitvector size: 500" << endl;
    b = bit_vector(500, 0);
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
    b[50] = 1; 
    b[73] = 1;
    b[113] = 1;
    r = rank_supp(&b);
    begin = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 10; i++){
        //cout << "test idx: " << i*100/10 << endl;
        r.rank1(i*500/10);
    }
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin);
    cout << "Time taken for 10 rank lookups: " << duration.count() << " nanoseconds" << endl;
    cout << "Overhead: " << r.overhead() << " bits\n" << endl;

    cout << "Bitvector size: 1000" << endl;
    b = bit_vector(1000, 0);
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
    b[50] = 1; 
    b[73] = 1;
    b[850] = 1;
    r = rank_supp(&b);
    begin = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 10; i++){
        //cout << "test idx: " << i*1000/10 << endl;
        r.rank1(i*1000/10);
    }
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin);
    cout << "Time taken for 10 rank lookups: " << duration.count() << " nanoseconds" << endl;
    cout << "Overhead: " << r.overhead() << " bits\n" << endl;

    cout << "Bitvector size: 10000" << endl;
    b = bit_vector(10000, 0);
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
    b[50] = 1; 
    b[73] = 1;
    b[850] = 1;
    b[8990] = 1;
    r = rank_supp(&b);
    begin = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 10; i++){
        //cout << "test idx: " << i*10000/10 << endl;
        r.rank1(i*10000/10);
    }
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin);
    cout << "Time taken for 10 rank lookups: " << duration.count() << " nanoseconds" << endl;
    cout << "Overhead: " << r.overhead() << " bits\n" << endl;


    cout << "Bitvector size: 100000" << endl;
    b = bit_vector(100000, 0);
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
    b[50] = 1; 
    b[73] = 1;
    b[850] = 1;
    b[8990] = 1;
    b[89090] = 1;
    r = rank_supp(&b);
    begin = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 10; i++){
        //cout << "test idx: " << i*100000/10 << endl;
        r.rank1(i*100000/10);
    }
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin);
    cout << "Time taken for 10 rank lookups: " << duration.count() << " nanoseconds" << endl;
    cout << "Overhead: " << r.overhead() << " bits\n" << endl;

    cout << "Bitvector size: 500000" << endl;
    b = bit_vector(500000, 0);
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
    b[50] = 1; 
    b[73] = 1;
    b[850] = 1;
    b[8990] = 1;
    b[89090] = 1;
    b[489090] = 1;
    r = rank_supp(&b);
    begin = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 10; i++){
        //cout << "test idx: " << i*100000/10 << endl;
        r.rank1(i*500000/10);
    }
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin);
    cout << "Time taken for 10 rank lookups: " << duration.count() << " nanoseconds" << endl;
    cout << "Overhead: " << r.overhead() << " bits\n" << endl;

    cout << "Bitvector size: 1000000" << endl;
    b = bit_vector(1000000, 0);
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
    b[50] = 1; 
    b[73] = 1;
    b[850] = 1;
    b[8990] = 1;
    b[89090] = 1;
    b[890790] = 1;
    r = rank_supp(&b);
    begin = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 10; i++){
        //cout << "test idx: " << i*1000000/10 << endl;
        r.rank1(i*1000000/10);
    }
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin);
    cout << "Time taken for 10 rank lookups: " << duration.count() << " nanoseconds" << endl;
    cout << "Overhead: " << r.overhead() << " bits\n" << endl;

    cout << "-----Testing for Task 2-----" << endl;
    cout << "Bitvector size: 32" << endl;
    b = bit_vector(32, 0);
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
    r = rank_supp(&b);
    select_supp s(&r);
    begin = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 4; i++){
        //cout << "test idx: " << i*32/10 << endl;
        s.select1(i*2);
    }
    s.select1(11);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin);
    cout << "Time taken for 5 select lookups: " << duration.count() << " nanoseconds" << endl;
    cout << "Overhead: " << r.overhead() << " bits\n" << endl;
    
    cout << "Bitvector size: 100" << endl;
    b = bit_vector(100, 0);
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
    b[50] = 1; 
    b[73] = 1;
    r = rank_supp(&b);
    s = select_supp(&r);
    begin = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 4; i++){
        //cout << "test idx: " << i*32/10 << endl;
        s.select1(i*2);
    }
    s.select1(13);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin);
    cout << "Time taken for 5 select lookups: " << duration.count() << " nanoseconds" << endl;
    cout << "Overhead: " << r.overhead() << " bits\n" << endl;

    cout << "Bitvector size: 500" << endl;
    b = bit_vector(500, 0);
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
    b[50] = 1; 
    b[73] = 1;
    b[113] = 1;
    r = rank_supp(&b);
    s = select_supp(&r);
    begin = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 4; i++){
        //cout << "test idx: " << i*32/10 << endl;
        s.select1(i*2);
    }
    s.select1(14);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin);
    cout << "Time taken for 5 select lookups: " << duration.count() << " nanoseconds" << endl;
    cout << "Overhead: " << r.overhead() << " bits\n" << endl;

    cout << "Bitvector size: 1000" << endl;
    b = bit_vector(1000, 0);
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
    b[50] = 1; 
    b[73] = 1;
    b[850] = 1;
    r = rank_supp(&b);
    s = select_supp(&r);
    begin = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 4; i++){
        //cout << "test idx: " << i*32/10 << endl;
        s.select1(i*2);
    }
    s.select1(14);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin);
    cout << "Time taken for 5 select lookups: " << duration.count() << " nanoseconds" << endl;
    cout << "Overhead: " << r.overhead() << " bits\n" << endl;

    cout << "Bitvector size: 10000" << endl;
    b = bit_vector(10000, 0);
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
    b[50] = 1; 
    b[73] = 1;
    b[850] = 1;
    b[8990] = 1;
    r = rank_supp(&b);
    s = select_supp(&r);
    begin = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 4; i++){
        //cout << "test idx: " << i*32/10 << endl;
        s.select1(i*2);
    }
    s.select1(15);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin);
    cout << "Time taken for 5 select lookups: " << duration.count() << " nanoseconds" << endl;
    cout << "Overhead: " << r.overhead() << " bits\n" << endl;


    cout << "Bitvector size: 100000" << endl;
    b = bit_vector(100000, 0);
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
    b[50] = 1; 
    b[73] = 1;
    b[850] = 1;
    b[8990] = 1;
    b[89090] = 1;
    r = rank_supp(&b);
    s = select_supp(&r);
    begin = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 4; i++){
        //cout << "test idx: " << i*32/10 << endl;
        s.select1(i*2);
    }
    s.select1(16);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin);
    cout << "Time taken for 5 select lookups: " << duration.count() << " nanoseconds" << endl;
    cout << "Overhead: " << r.overhead() << " bits\n" << endl;

    cout << "Bitvector size: 500000" << endl;
    b = bit_vector(500000, 0);
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
    b[50] = 1; 
    b[73] = 1;
    b[850] = 1;
    b[8990] = 1;
    b[89090] = 1;
    b[489090] = 1;
    r = rank_supp(&b);
    s = select_supp(&r);
    begin = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 4; i++){
        //cout << "test idx: " << i*32/10 << endl;
        s.select1(i*2);
    }
    s.select1(17);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin);
    cout << "Time taken for 5 select lookups: " << duration.count() << " nanoseconds" << endl;
    cout << "Overhead: " << r.overhead() << " bits\n" << endl;

    cout << "Bitvector size: 1000000" << endl;
    b = bit_vector(1000000, 0);
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
    b[50] = 1; 
    b[73] = 1;
    b[850] = 1;
    b[8990] = 1;
    b[89090] = 1;
    b[890790] = 1;
    r = rank_supp(&b);
    s = select_supp(&r);
    begin = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 4; i++){
        //cout << "test idx: " << i*32/10 << endl;
        s.select1(i*2);
    }
    s.select1(17);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin);
    cout << "Time taken for 5 select lookups: " << duration.count() << " nanoseconds" << endl;
    cout << "Overhead: " << r.overhead() << " bits\n" << endl;

    cout << "-----Testing for Task 3-----" << endl;
    cout << "Sparse Array Size: 1000" << endl;
    bit_vector t1(1000, 0);
    cout << "Bitvector Size 1000 byte size: " << size_in_bytes(t1) << endl;
    sparse_array sa = sparse_array();
    cout << "1%" << endl;
    sa.create(1000);
    for (int i = 0; i < 10; i++){
        string x = "test" + to_string(i);
        sa.append(x, i*100);
    }
    sa.finalize();
    begin = std::chrono::high_resolution_clock::now();
    string p = "placeholder";
    sa.get_at_rank(2, p);
    sa.get_at_index(10, p);
    sa.get_index_of(3);
    sa.num_elem_at(100);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin);
    cout << "Time taken for .get_at_rank(), .get_at_index(), .get_index_of(), .num_elem_at(): " << duration.count() << " nanoseconds" << endl;
    cout << "Overhead: " << sa.overhead() << " bits\n" << endl;
    cout << "5%" << endl;
    sparse_array sa2 = sparse_array();
    sa2.create(1000);
    for (int i = 0; i < 50; i++){
        string x = "test" + to_string(i);
        sa2.append(x, i*20);
    }
    sa2.finalize();
    begin = std::chrono::high_resolution_clock::now();
    p = "placeholder";
    sa2.get_at_rank(2, p);
    sa2.get_at_index(10, p);
    sa2.get_index_of(3);
    sa2.num_elem_at(100);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin);
    cout << "Time taken for .get_at_rank(), .get_at_index(), .get_index_of(), .num_elem_at(): " << duration.count() << " nanoseconds" << endl;
    cout << "Overhead: " << sa2.overhead() << " bits\n" << endl;
    cout << "10%" << endl;
    sparse_array sa3 = sparse_array();
    sa3.create(1000);
    for (int i = 0; i < 100; i++){
        string x = "test" + to_string(i);
        sa3.append(x, i*10);
    }
    sa3.finalize();
    begin = std::chrono::high_resolution_clock::now();
    p = "placeholder";
    sa3.get_at_rank(2, p);
    sa3.get_at_index(10, p);
    sa3.get_index_of(3);
    sa3.num_elem_at(100);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin);
    cout << "Time taken for .get_at_rank(), .get_at_index(), .get_index_of(), .num_elem_at(): " << duration.count() << " nanoseconds" << endl;
    cout << "Overhead: " << sa3.overhead() << " bits\n" << endl;

    cout << "Sparse Array Size: 10000" << endl;
    t1 = bit_vector(10000, 0);
    cout << "Bitvector Size 10000 byte size: " << size_in_bytes(t1) << endl;
    sparse_array sa4 = sparse_array();
    cout << "1%" << endl;
    sa4.create(10000);
    for (int i = 0; i < 100; i++){
        string x = "test" + to_string(i);
        sa4.append(x, i*100);
    }
    sa4.finalize();
    begin = std::chrono::high_resolution_clock::now();
    p = "placeholder";
    sa4.get_at_rank(2, p);
    sa4.get_at_index(10, p);
    sa4.get_index_of(3);
    sa4.num_elem_at(100);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin);
    cout << "Time taken for .get_at_rank(), .get_at_index(), .get_index_of(), .num_elem_at(): " << duration.count() << " nanoseconds" << endl;
    cout << "Overhead: " << sa4.overhead() << " bits\n" << endl;
    cout << "5%" << endl;
    sparse_array sa5 = sparse_array();
    sa5.create(10000);
    for (int i = 0; i < 500; i++){
        string x = "test" + to_string(i);
        sa5.append(x, i*20);
    }
    sa5.finalize();
    begin = std::chrono::high_resolution_clock::now();
    p = "placeholder";
    sa5.get_at_rank(2, p);
    sa5.get_at_index(10, p);
    sa5.get_index_of(3);
    sa5.num_elem_at(100);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin);
    cout << "Time taken for .get_at_rank(), .get_at_index(), .get_index_of(), .num_elem_at(): " << duration.count() << " nanoseconds" << endl;
    cout << "Overhead: " << sa5.overhead() << " bits\n" << endl;
    cout << "10%" << endl;
    sparse_array sa6 = sparse_array();
    sa6.create(10000);
    for (int i = 0; i < 1000; i++){
        string x = "test" + to_string(i);
        sa6.append(x, i*10);
    }
    sa6.finalize();
    begin = std::chrono::high_resolution_clock::now();
    p = "placeholder";
    sa6.get_at_rank(2, p);
    sa6.get_at_index(10, p);
    sa6.get_index_of(3);
    sa6.num_elem_at(100);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin);
    cout << "Time taken for .get_at_rank(), .get_at_index(), .get_index_of(), .num_elem_at(): " << duration.count() << " nanoseconds" << endl;
    cout << "Overhead: " << sa6.overhead() << " bits\n" << endl;

    cout << "Sparse Array Size: 100000" << endl;
    t1 = bit_vector(100000, 0);
    cout << "Bitvector Size 100000 byte size: " << size_in_bytes(t1) << endl;
    sparse_array sa7 = sparse_array();
    cout << "1%" << endl;
    sa7.create(100000);
    for (int i = 0; i < 1000; i++){
        string x = "test" + to_string(i);
        sa7.append(x, i*100);
    }
    sa7.finalize();
    begin = std::chrono::high_resolution_clock::now();
    p = "placeholder";
    sa7.get_at_rank(2, p);
    sa7.get_at_index(10, p);
    sa7.get_index_of(3);
    sa7.num_elem_at(100);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin);
    cout << "Time taken for .get_at_rank(), .get_at_index(), .get_index_of(), .num_elem_at(): " << duration.count() << " nanoseconds" << endl;
    cout << "Overhead: " << sa7.overhead() << " bits\n" << endl;
    cout << "5%" << endl;
    sparse_array sa8 = sparse_array();
    sa8.create(100000);
    for (int i = 0; i < 5000; i++){
        string x = "test" + to_string(i);
        sa8.append(x, i*20);
    }
    sa8.finalize();
    begin = std::chrono::high_resolution_clock::now();
    p = "placeholder";
    sa8.get_at_rank(2, p);
    sa8.get_at_index(10, p);
    sa8.get_index_of(3);
    sa8.num_elem_at(100);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin);
    cout << "Time taken for .get_at_rank(), .get_at_index(), .get_index_of(), .num_elem_at(): " << duration.count() << " nanoseconds" << endl;
    cout << "Overhead: " << sa8.overhead() << " bits\n" << endl;
    cout << "10%" << endl;
    sparse_array sa9 = sparse_array();
    sa9.create(100000);
    for (int i = 0; i < 10000; i++){
        string x = "test" + to_string(i);
        sa9.append(x, i*10);
    }
    sa9.finalize();
    begin = std::chrono::high_resolution_clock::now();
    p = "placeholder";
    sa9.get_at_rank(2, p);
    sa9.get_at_index(10, p);
    sa9.get_index_of(3);
    sa9.num_elem_at(100);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin);
    cout << "Time taken for .get_at_rank(), .get_at_index(), .get_index_of(), .num_elem_at(): " << duration.count() << " nanoseconds" << endl;
    cout << "Overhead: " << sa9.overhead() << " bits\n" << endl;

    cout << "Sparse Array Size: 1000000" << endl;
    t1 = bit_vector(1000000, 0);
    cout << "Bitvector Size 1000000 byte size: " << size_in_bytes(t1) << endl;
    sparse_array sa10 = sparse_array();
    cout << "1%" << endl;
    sa10.create(1000000);
    for (int i = 0; i < 10000; i++){
        string x = "test" + to_string(i);
        sa10.append(x, i*100);
    }
    sa10.finalize();
    begin = std::chrono::high_resolution_clock::now();
    p = "placeholder";
    sa10.get_at_rank(2, p);
    sa10.get_at_index(10, p);
    sa10.get_index_of(3);
    sa10.num_elem_at(100);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin);
    cout << "Time taken for .get_at_rank(), .get_at_index(), .get_index_of(), .num_elem_at(): " << duration.count() << " nanoseconds" << endl;
    cout << "Overhead: " << sa10.overhead() << " bits\n" << endl;
    cout << "5%" << endl;
    sparse_array sa11 = sparse_array();
    sa11.create(1000000);
    for (int i = 0; i < 50000; i++){
        string x = "test" + to_string(i);
        sa11.append(x, i*20);
    }
    sa11.finalize();
    begin = std::chrono::high_resolution_clock::now();
    p = "placeholder";
    sa11.get_at_rank(2, p);
    sa11.get_at_index(10, p);
    sa11.get_index_of(3);
    sa11.num_elem_at(100);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin);
    cout << "Time taken for .get_at_rank(), .get_at_index(), .get_index_of(), .num_elem_at(): " << duration.count() << " nanoseconds" << endl;
    cout << "Overhead: " << sa11.overhead() << " bits\n" << endl;
    cout << "10%" << endl;
    sparse_array sa12 = sparse_array();
    sa12.create(1000000);
    for (int i = 0; i < 100000; i++){
        string x = "test" + to_string(i);
        sa12.append(x, i*10);
    }
    sa12.finalize();
    begin = std::chrono::high_resolution_clock::now();
    p = "placeholder";
    sa12.get_at_rank(2, p);
    sa12.get_at_index(10, p);
    sa12.get_index_of(3);
    sa12.num_elem_at(100);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin);
    cout << "Time taken for .get_at_rank(), .get_at_index(), .get_index_of(), .num_elem_at(): " << duration.count() << " nanoseconds" << endl;
    cout << "Overhead: " << sa12.overhead() << " bits\n" << endl;
    return 0; 
}