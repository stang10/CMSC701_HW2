# CMSC701_HW2

This project was written in the C++ programming language. 

For this project, I have made use of the Succinct Data Structure Library 2.0 (sdsl-lite) found [here](https://github.com/simongog/sdsl-lite). Since there is already a github repository for the sdsl-lite library, I was unable to add it to my own repository. As such, you will need download the sdsl-lite library for yourself. 

Please follow these steps to download my code and be able to have it run. 

```git clone git@github.com:stang10/CMSC701_HW2.git
cd CMSC701_HW2
git clone https://github.com/simongog/sdsl-lite.git
cd sdsl-lite
./install.sh
cd ../
cmake . 
make
```

At this time, I believe I have properly removed the CMakeCache.txt file associated with the project before uploading it to my github. However, if you attempt to run the `cmake .` command as above with the existing CMakeCache.txt you may receive an error. At which point, simply delete the CMakeCache.txt file from the directory and rerun the command. 

If the previous commands are completed successfully, the executable "main" will be created which can be used to interact with and run the testing on my project files. 

To run this executeable, in the CMSC701_HW2 directory, run: 
```
./main
```

## Rank Support (Found in ./src/rank.h)
In order to avoid confusion with the rank_support class created by the sdsl library, I created a rank support class titled rank_supp to carry out the specified functions from task 1. A rank_supp object can be initialized using `rank_supp r(&bitvector)` or `rank_supp r = rank_supp(&bitvector)` where bitvector is a previously defined bit_vector object from the SDSL library. Initilization of this structure stores a pointer to this specified bit_vector object and creates two int_vector objects from the SDSL library to hold the relative cummulative ranks for the chunks and subchunks as specified by Jacobson's rank. 

## Select Support (Found in ./src/select.h)
In order to avoid confusion with the select_support class created by the sdsl library, I created a select support class titled select_supp to carry out the specified functions from task 2. A select_supp object can be initialized using `select_supp s(&rankSupport)` or `select_supp s = select_supp(&rankSupport)` where rankSupport is a previously defined rank_supp object as defined above. Initilization of this structure stores a pointer to this specified rank_supp object. 

## Sparse Array (Found in ./src/sparse.h)
I created the sparse_array class to carry out the specified functions from task 3. A sparse_array object can be initialized using `sparse_array sa = sparse_array()`. Initialization of this structure creates a dummy bit_vector object from the SDSL library to be stored as a local variable, creates a rank_supp object to be stored as a local variable from the dummy bit_vector object, creates a select_supp object to be stored as a local variable from the stored ranl_supp object, and sets a local boolean variable marking whether the sparse_array is finalized or not to false. 
