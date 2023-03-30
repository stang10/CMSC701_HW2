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


