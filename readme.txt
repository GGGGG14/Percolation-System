/******************************************************************************
 *  Describe how you implemented Percolation.cpp. How did you check
 *  whether the system percolates?
 *****************************************************************************/
I essentially created two data structures,
one of which was a union find structure, and the other was a 2D boolean
vector. I used PercolationTester.cpp to test my code system's percolation &
my own tester file to find out the info below on run time / formula!


/******************************************************************************
 *  Using Percolation with QuickFindUF,  fill in the table below such that
 *  the N values are multiples of each other.

 *  Give a formula (using tilde notation) for the running time (in seconds) of
 *  PercolationStats as a function of both N and T. Be sure to give both
 *  the coefficient and exponent of the leading term. Your coefficients should
 *  be based on empirical data and rounded to two significant digits, such as
 *  5.3*10^-8 * N^5.0 T^1.5.
 *****************************************************************************/

(keep T constant)

 N          time (seconds)
------------------------------
 4          8.00 x 10^-5
 16         1.42 x 10^-4
 64         1.26 x 10^-3
 256        7.01 x 10^-2
 1024       4.31 (woah!)


(keep N constant)

 T          time (seconds)
------------------------------
 4          1.59 x 10^-4
 16         2.52 x 10^-4
 64         2.03 x 10^-4
 256        5.24 x 10^-4
 1024       1.90 x 10^-3


running time as a function of N and T:  ~a*N^b; (3.74 x 10^-18 * N^6) & (1.73 x 10^-15 * T^4);


/******************************************************************************
 *  Repeat the previous question, but use WeightedQuickUnionUF.
 *****************************************************************************/

(keep T constant)

 N          time (seconds)
------------------------------
 4          1.07 x 10^-4
 16         1.62 x 10^-4
 64         1.24 x 10^-4
 256        5.31 x 10^-4
 1024       7.00 x 10^-3


(keep N constant)

 T          time (seconds)
------------------------------
 4          1.36 x 10^-4
 16         1.73 x 10^-4
 64         2.33 x 10^-4
 256        4.48 x 10^-4
 1024       1.93 x 10^-3


running time as a function of N and T:  ~a*N^b; (5.14 x 10^-42 * N^13) & (1.75 x 10^-15 * T^4);


/******************************************************************************
 *  Known bugs / limitations.
 *****************************************************************************/
None that I know of!


/******************************************************************************
 *  Describe whatever help (if any) that you received.
 *  Don't include readings, lectures, and exercises, but do
 *  include any help from people (including classmates and friends) and
 *  attribute them by name.
 *****************************************************************************/
I got help from Madi and Shane mostly. We discussed tactics to improve our codes etc.
Shane taught me about 'do {} while' loop syntax which helped in generating a random
row/col that was not already open in the system.

/******************************************************************************
 *  Describe any serious problems you encountered.
 *****************************************************************************/
Figuring out how to use vectors instead of 2D arrays was a little bit hard, but I finally got it!
I had a hard time finding the runtime equations using slides 16-18 in the analysis of algorithms slideshow. I don't think what I wrote was correct.


/******************************************************************************
 *  List any other comments here. Feel free to provide any feedback
 *  on how much you learned from doing the assignment, and whether
 *  you enjoyed doing it.
 *****************************************************************************/
I enjoyed this challenge and found the code quite challenging. I prefer building code
from the ground up and not using a ton of dependencies that I did not make, but it was fun!
