# Moser Circle Problem
- This program was written with [Jaxen Roden](https://github.com/jaxenroden).
- It was inspired by 3B1B's [video](https://www.youtube.com/watch?v=YtkIWDE36qU) on the [Moser Circle pattern](https://en.wikipedia.org/wiki/Dividing_a_circle_into_areas) (or lack thereof).
---
### The Question
Moser's Circle problem asks how many _r_ regions a circle will be divided into if it is intersected by _n_ lines. For the first few _n_, _r_ is a power of two:
- With **0** lines, there is **1** region.
- With **1** line, there are **2** regions.
- With **2** lines, there are **4** regions.
- With **3** lines, there are **8** regions.
- With **4** lines, there are **16** regions.
  
But then the pattern breaks at _n = 5_:
- With **5** lines, there are **31** regions (while 2<sup>5</sup> is 32).
- How they fool ya.

But then at _n = 10_, the pattern returns:
- With **10** lines, there are **256** regions.<br>
### This C++ program seeks to check if there are any more powers of two by brute force.
For any _n_ lines, the number of _r_ regions can be determined as follows:
<br><br>
![Formula](https://latex.codecogs.com/svg.latex?\binom{n}{4}%20+%20\binom{n}{2}%20+%201)
<br><br>
However, writing a program to evaluate that formula for even moderately large _n's_ is not trivial. Numbers quickly get far too large to be represented by any number primitive in C++.

To get around this limitation, the program uses vectors to represent numbers in the following format: {ones, tens, hundreds, thousands, ...}. With this approach, the size of numbers is only limited by the number of values a single vector can hold.

But this approach required writing custom arithmetic operations for adding, subtracting, multiplying, and dividing, each of which essentially follows the algorithms learned in elementary school, which we found to be more efficient than simpler implementations. The benefit of this approach is most obvious in the division function.

We also had to write a factorial function, but we took advantage of the fact that the factorials in the formula will always simplify, drastically reducing the size of the factorials.

With these basic operators in place, the rest of the program was relatively straightforward. A simple loop just evaluates the formula for ever-increasing values of _n_. The program can perform around 1,000 evaluations every 1-2 seconds.

The program could certainly be made more efficient. One way to speed it up would be to move away from the straightforward vector representation where each element represents a decimal place. Intead, each element of the vector could hold the largest number possible, then the next element would just hold the overflow. This approach would significantly reduce the size of the vectors — and therefore the overhead.

### Findings
We ran the program through _n = 10,000,000 (10M)_, and we found no additional powers of two.
