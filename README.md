# push_swap

Sorting with 2 stacks

## About this project
- This is an individual project at [School 42](https://42.fr/en/homepage/).
- The goal of this project is to sort a stack A in ascending order using another stack B.
- Only specific operations are allowed:

    * **sa (swap a)**: Swap the first 2 elements at the top of stack A.
    * **sb (swap b)**: Swap the first 2 elements at the top of stack B.
    * **ss**: Executes sa and sb simultaneously.
    * **pa (push a)**: Take the first element at the top of B and put it at the top of a.
    * **pb (push b)**: Take the first element at the top of A and put it at the top of b.
    * **ra (rotate a)**: Shift up all elements of stack A by 1. The first element becomes the last one.
    * **rb (rotate b)**: Shift up all elements of stack B by 1. The first element becomes the last one.
    * **rr**: Executes ra and rb simultaneously.
    * **rra (reverse rotate a)**: Shift down all elements of stack a by 1. The last element becomes the first one.
    * **rrb (reverse rotate b)**: Shift down all elements of stack b by 1. The last element becomes the first one.
    * **rrr**: Executes rra and rrb simultaneously.

- There are 2 programs in this project:

    * **push_swap**: this program will take the numbers, sort them and output the used operations.
    * **checker**: this program will take the numbers, read the operations and check if the numbers are sorted or not.


![Alt Text](./readme/push_swap.gif)
Visualizer by @o-reo [here](https://github.com/o-reo/push_swap_visualizer)

## Usage (linux)
### Compilation
```console
make
```
### Usage
```console
./push_swap [numbers...]
```
##### Arguments
* `[numbers...]`: One or more integers to be sorted.

##### Examples:
```console
./push_swap 5 27 12  
ra
sa
rra
```
This command gives the set of instruction to sort the integers 5, 27 and 12.

To launch push_swap with 100 arguments:
```console
./push_swap `echo $(shuf -i 1-100 -n 100)`
```


To run the checker,
```console
./checker [numbers]
```
Then, you have to input operations. One operation each time then press Enter. After finished, press command + D or CTRL + D. For example:
```console
$>./checker 3 2 1
sa
ra
OK
$> ./checker 3 2 1
ra
sa
KO
```

You can run push_swap and then send the result to the checker to check it.
```console
ARG="3 2 1"; ./push_swap $ARG | ./checker $ARG
```

## Implementation of Data Structure
To implement the two stacks, I opted for utilizing a circular doubly linked list. This choice enables me to perform rotation operations quite effortlessly.
``` C
typedef struct s_node {
	struct s_node	*next;
	struct s_node	*prev;
	int				value;
	int				pos;
	int				grp_size;
	int				median;
}				t_node;

typedef struct s_pile {
	struct s_node	*begin;
}				t_pile;

```

## My algorithm

To solve this problem, conventional algorithms are not applicable due to our constraints: the utilization of two stacks and the limitations of accessible operations. However, the general principles of algorithms remain applicable.

### Complexity
The time complexity of my program is **O(N²)**, but the complexity of the number of instructions is **O(Nlog(N))**. This result is justified by the fact that the subject specifically requires optimizing the number of instructions rather than execution time.

### Step 1 : Pre-sort from Stack A to Stack B
- The first step of my algorithm is to push to stack B every element superior to the median of stack A. If an element is pushed, I calculate the new median of the stack B and I rotate B if the number is superior to the new median.
- So I get the 50% smallest number in stack A, the 50% biggest number in stack B. The 50% biggest numbers of stack B are at the bottom of stack B.
- Then I recalculate the median of stack A and I push every element superior to this median. I do this until stack A is empty.

### Step 2 : Insertion sort with cost calculation
- On this step, I will calculate how many steps I need to insert, at the right place, every element of Stack B.
- Then I insert the element that takes the least amount of steps to insert.
- I do this until Stack B is empty.

## Results

The evaluation criteria to get the max score : 
* 3 numbers: <= 3 operations to pass the project
* 5 numbers: <= 12 operations to pass the project
* 100 numbers: <= 700 operations to get the full bonus
* 500 numbers: <= 5500 operations to get the full bonus

My result :
* For 3 numbers : max 3 instructions
* For 4 numbers : max 8 instructions
* For 5 numbers : max 11 instructions
* For 100 numbers : about 600 instructions, never over 640
* For 500 numbers : about 4400 instructions, never over 4600

[Here](https://github.com/lanzaj/tester_pushswap) is a link to simple scripts I made to test this project.