# Capacitated Vehicle Routing Problem (CVRP) in C #

## Prerequisites ##

Before running this code, ensure you have the following :

- ***gcc*** compiler installed on your system.

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
./cvrp Dataset/exemple3.dat
```

## Monitor ##

## Results ##

## To do list ##

- [ ] Add a summary in README.
- [ ] Check and rename dataset files. Adapt name in report.
- [ ] Translate pseudo code in report in english.
- [ ] Define a metadata for input in README.
- [ ] Generate an ouput.txt file to stock the results.
