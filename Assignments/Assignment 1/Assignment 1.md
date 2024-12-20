![[Pasted image 20240123175203.png]]

Within the code, adjust the variable NUMBER_REPETITIONS, so that the time reported for "method execution time" is about a minute or a little more.

Now review the code to answer the following:
a. Explain what is meant by the output line, "run repeated 800 squared times".
b. What is measured by the "looping time"?
c. Run the program several times with the same command-line parameters. To what extent does the "looping time" vary from run to tun?
d. Run the program several times with different values for the Exercise number (but keeping the value of n at 100 in each case. To what extent does the "looping
time" change with each experiment?
e. What is measured by the "method execution time"?
f. What is measured by the "loop execution time"?

Exercise 2
int run2(int n) {

  int sum = 0;

  for (int i=0 ; i < n ; i++)
    sum++;
  for (int j=0 ; j <= n ; j++)
    sum++;
  
  return sum;
}
A
A + B(n+1) + P(n+1)
P(n)
A + B(n+1) + P(n+1)
P(n)
= A + 2B(n+1) + 4P(n) + 2P

What are the Big-O, Big- Ω, and Big-Θ running times of run2?
O(n) Ω(n) Θ(n)
Run the code with several values of n.
n: runtime(rounded) | 100: .8, 200: 1.6, 300: 2.4, 400: 3.2
Compare your analysis with the actual running times. Do they agree?
Yes, the function runtime should be increasing linearly by roughly .80 seconds per increment of n+=100

Exercise 3
What value will result from n = 10? n = 20?
100, 400 ; nested loop with n/2 and n*2 repetitions
What are the Big-O, Big- Ω, and Big-Θ running times of run3?
n^2, n^2, n^2
Run the code with a several values of N.
n: runtime(rounded) | 100: 40.5, 200: 160.5, 300: 359.5
Compare your analysis with the actual running times. Do they agree?
Well for n = 100 I am getting 40 seconds of runtime. When I increase n by a factor of 2 at n = 200, I am getting 40 * 2^2 = 160. Increasing n by a factor of 3 at n = 300, I am getting 40 * 3^2 which is 360, so my analysis seems aligned.

Exercise 4
What are the Big-O, Big- Ω, and Big-Θ running times of run4?
n. The outerloop runs until i = n. The inner loop runs n * 4 times over the range i-2 and i+1
Run the code with several values of N.
n: runtime(rounded) | 200: 4.8, 300: 7.2, 400: 9.6
Compare your analysis with the actual running times. Do they agree?
The runtime increases linearly by a constant factor of about 2.4 seconds per 100 n.

Exercise 5
What value will result from n = 4? n = 5?
6, 10
Can you recall the closed-form for the value that will be returned?
Sum= 
2
n×(n−1)
What are the Big-O, Big- Ω, and Big-Θ running times of run5?
n^2 because n(n-1)
If you wish, you may run the algorithm for several values of N and compare your analysis with the actual running times.


Exercise 6
A closed form analysis of run6 is still possible, using the same formula as used in Exercise 5.b. Hazard a guess as to the formula and predict the result for n = 3 and n = 4.

Test your predictions.
Based on your formula, or your observations from the code, what are the Big-O, Big- Ω, and Big-Θ running times of run6?
Run the algorithm for a few more values of N and compare your analysis with the actual running times.

Exercise 7
What value will result from n = 4? n = 8? n = 16
What are the Big-O, Big- Ω, and Big-Θ running times of run7?
Run the algorithm for a few values of n and compare your analysis with the actual running times.

Exercise 8
What are the Big-O, Big- Ω, and Big-Θ running times of run8
Run the code with several values of n.
Compare your analysis with the actual running times. Do they agree?
Given the results from b, what would you say the running time seems closer to?
What is it about the innermost loop that causes the actual results to differ widely from the Big-O?