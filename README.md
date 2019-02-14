# Balls into Bins Simulator

## Dependencies

+ [fmt](https://github.com/fmtlib/fmt)
    ```bash
    # Install fmt
    git clone https://github.com/fmtlib/fmt
    cd fmt
    mkdir build && cd build
    cmake ..
    make && sudo make install
    ```



## Usage

```bash
git clone https://github.gatech.edu/Network-Theory-Group/BallsIntoBins.git
cd BallsIntoBins
mkdir build && cd build
cmake ..
make
./BallsIntoBins
```

Here is a sample output, which shows the sizes of the top 10 heaviest buckets for 
the simulation results for simulate 1 million balls into 1 million bins. 
The kth column is the size of kth heaviest bucket. As we can see the sizes of the top 10 
buckets are actually very similar (i.e., gap between them is very very small).

```csv
     9     9     8     8     8     8     8     8     8     8
     9     8     8     8     8     7     7     7     7     7
     9     8     8     8     8     8     8     8     8     8
     8     8     8     8     8     8     8     8     8     8
     9     9     8     8     8     8     8     8     8     8
     9     8     8     8     8     8     8     8     7     7
     8     8     8     8     8     8     8     8     8     8
    10     9     8     8     8     8     8     8     8     8
     9     8     8     7     7     7     7     7     7     7
     9     8     8     8     8     8     8     8     8     8
     9     8     8     8     8     8     8     8     7     7
     9     8     8     8     8     8     7     7     7     7
     9     8     8     8     8     8     7     7     7     7
     8     8     8     8     8     8     8     8     7     7
     8     8     8     8     8     8     8     8     7     7
    10     9     8     8     8     8     8     8     8     7
     9     9     8     8     8     8     8     8     8     8
     8     8     8     8     8     8     8     7     7     7
     9     9     8     8     8     8     8     8     8     8
     8     8     8     8     8     7     7     7     7     7
!!Finished!!
```

## TODO

+ [ ] Add command line options