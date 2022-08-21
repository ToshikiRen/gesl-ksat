<h3> Running the tests and the main files </h3>

</br>From the root file -> problem folder run make build, then from src run make run in order to run the contents of the main.c file. If you want to run the tests for the 1st and 3rd problem from the problem folder directily run make test. </br> 
Another way to run the main.c files is to simply use make single-run in the problem folder.


<h3> Fun Time Sorting </h3>

Used algorithm: heapsort </br>
Complexity for both time and space: O(NlogN), where N is the number of elements in the array.

<h3> Happy Print </h3>

Prints a binary tree in a nice way:

Example:
![Tree format](image.png)

<h3> Next Permutation </h3>

0. At each step we start from the last element and work our way to the first
1. Find firstIndex such that array[i] < array[i+1]
2. Find the secondIndex such that array[firstIndex] < array[i]
3. Swap elements on position firstIndex and secondIndex
4. Reverse all the elements to the right of firstIndex
