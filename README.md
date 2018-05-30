# fake-fermat
This program generates "fake" solutions of integral exponents of the equation A^N + B^N = C^N where N > 2, seemingly in violation of the famous Fermat's Last Theorem. 

## Background
Fermat's Last Theorem famously states that A^N + B^N = C^N has no solutions for any positive integers A, B, and C, where N is greater than 2. For example, you will never have positive integer solutions for A^3 + B^3 = C^3. This is famous because it became one of the hardest and most complex proofs in all of mathematics. It was originally conjectured by Fermat in 1637 and wasn't proven until fairly recently in 1994 by Andrew Wiles. 

However, if you were to pick up a calculator right this moment and plug in 4528^3 + 3753^3 to your calculator and then evaluate 5262^3, they would appear identical, implying that 4528^3 + 3753^3 = 5262^3 -- and you might even believe for a second that you disproved 300 years of rigorous mathematics! Sadly, or happily (depending on your perspective!) there's more going on than meets the eye. Most calculators will only display about 10 digits, and this is their downfall that my program takes advantage of. If you were to expand your numbers a bit, you can see that they differ on the tail end. Interestingly, this concept has found its way into pop-culture, and you'll see "Fermat near-misses" in places like a chalk board in the back of a frame of The Simpson's. 

## How It Works
I thought it was an interesting problem to identify some of these near miss solutions, so I wrote a program that uses a comparison algorithm within nested for loops to find the best fake-fermat (the one with the most matching digits) for a given boundary on your ABC integers and N. These boundaries are given in the command line, as well as a debug option to evaluate the program's steps throughout its loop. The bounds are exclusive. 

To use, run with the following command line arguments: 
ABC bound, N bound, debug

A few examples of command line arguments would be:

5000, 12

8032, 9, debug 

500, 3, debug

You will get an output in the command line that displays the best nearest match within your givin bounds, as well as where the typical cutoff is for most calculators and the iOS calculator when put into landscape mode. 

# To Do 
Integrate with some sort of math library for numerical data types larger than unsigned long long int
