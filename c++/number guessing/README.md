This is a program that guesses a number that you come up with.
The numbers that can guess are 1<=X>=100.

Commands:
yes -It chose the right number,
h -It chose too high number,
l - It choose too low number,

when you type yes it will say how many guesses it needed.

How it works:

it always chooses the middle of the known limits, so at the start it always chooses 50 as it is the middle of 100 and 0.
This gets repeated every time until it guesses the number. For better understanding read the code.

TESTS:
Tested the code with every possible number. The maximum number of guesses is 7 and minimum is 1. Average time of guesses is 5.8. most guesses take 7 guesses (37%), 6 guesses is 32%, 5 guesses is 16%, 4 guesses is 8%, 3 guesses is 4%, 2 guesses is 2% and 1 guess is 1%.
It is mostly linear by doubling every guess and rising by 5% from 6 to 7 guesses or 1.15 times more. It was not tested for speed as it is not meant for computing large amounts of numbers.
I included a excel spreadsheet with guesses in A row with a few graphs as well as average. The excel spreadsheet is not made professionaly as it is just to present simple data.