# Capacitated Vehicle Routing Problem (CVRP) in C #

## Prerequisites ##

Before running this code, ensure you have the following :

- ***gcc*** compiler installed on your system.

## Input dataset ##

The input files have a specific arguments which can be formatted into simple
***txt*** files, where :
- The first line corresponds to the number of customers to be delivered.
- The second line corresponds to the maximum capacity in units of the vehicles.
- The third line corresponds to the delivery requests in units of each customer
which must be less than the maximum capacity of the vehicles.
- The last lines correspond to the symmetrical matrix of the various distances
between the depot and the different customer ; the first index corresponding to
the depot.

## Usage ##


1. Navigate to the **Code** directory containing the source code and the ***Makefile*** file.
```bash
cd Code
```
2. Compile the cvrp program by running ***make all***.
```bash
make all
```
3. The compiled program ***cvrp*** is now located in the parent repository.
```bash
cd ..
```
4. Execute the compiled program by running ***./cvrp Dataset/example.txt***, where ***Dataset/example.txt*** is the path to the ***txt*** file containing the input data.
```bash
./cvrp Dataset/example.txt
```
*(Optional)* 5. Clean the repository by running ***make clean*** in the **Code** directory.

```bash
cd Code
make clean
```

### Example ###

```bash
cd Code
make all
cd ..
./cvrp Dataset/small_example_int.txt
```

## Monitor ##

## Results ##

## To do list ##

- [ ] Add a summary in README.
- [ ] Check and rename dataset files. Adapt name in report.
- [ ] Correct segmentation fault error due to float distance in input file.
- [ ] Translate pseudo code in report in english.
- [ ] Define a metadata for input in README.
- [ ] Generate an ouput.txt file to stock the results.
