# Capacitated Vehicle Routing Problem (CVRP) #
> ### Language : C ###

This code involve the problem of cost in carrier deliveries : especially here, we only consider the costs associated with the distance covered.
We assume here that vehicles have identical storage capacity, and that they all start from the same depot to make their deliveries, and then return at this same depot at the end of their rounds.
Similarly, we assume that carriers cannot pass a customer without delivering, and that a customer
cannot be partially delivered by a truck.
Our program should therefore return the minimum cost of a delivery, as well as the order of customers for each delivery round. The resulting solution is not necessarily optimal because the proposed method is based here on heuristic methods.

## Prerequisites ##

Before running this code, ensure you have the following :

- ***gcc*** compiler installed on your system.

## Input dataset ##

The input files have specific arguments which can be formatted into simple
***txt*** files, where :
- The first line corresponds to the number of customers to be delivered.
- The second line corresponds to the maximum capacity in units of the vehicles.
- The third line corresponds to the delivery requests in units of each customer
which must be less than the maximum capacity of the vehicles.
- The last lines correspond to the symmetrical matrix of the various distances
between the depot and the different customer ; the first index corresponding to
the depot.

## Usage ##


1. Navigate to the **code** directory containing the source code and the ***Makefile*** file.
```bash
cd code
```
2. Compile the cvrp program by running ***make all***.
```bash
make all
```
3. The compiled program ***cvrp*** is now located in the parent repository.
```bash
cd ..
```
4. Execute the compiled program by running ***./cvrp dataset/example.txt***, where ***dataset/example.txt*** is the path to the ***txt*** file containing the input data.
```bash
./cvrp dataset/example.txt
```
*(Optional)* 5. Clean the repository by running ***make clean*** in the **code** directory.

```bash
cd code
make clean
```

### Example ###

```bash
cd code
make all
cd ..
./cvrp dataset/small_example_int.txt
```

## Monitor ##

To configure the heuristic algorithm used in this program, the user have to inform value during the execution of the program. The user have to provide :
- **First Customer** : Integer value between 0 and the total number of customers minus one, due to variable indexing. If the value informed is not available, the default value 0 is then used.

## Results ##

The program will saved the first customer to deliver, the minimum distance cost of the solution and each ordered round to complete the total delivery requests in the **output** directory in the file named ***output.txt***.

## To do list ##

- [ ] Adapt report with example names.
- [ ] Correct segmentation fault error due to double matrix distance in input file.
- [ ] Adapt maximum capacity vehicle from integer to double.
- [ ] Translate pseudo code in report in english.
- [ ] Rename variable T to better describe its containing.
