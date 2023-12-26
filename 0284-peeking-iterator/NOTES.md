Reviewing classes and derived classes in C++ as well as design questions<br><br>
​
Got this problem in January 2023, Apple interview<br><br>
​
Key point is that you have to advance the pointer to peek. BUT, you have to maintain an appearance that you have not done so until next() is called again, in which case you "reset"<br><br>
​
Ex) **peek()**, hasNext()...peek()...peek()...hasNext(), **next()**<br><br>
​
We have to ensure that we: <br><br>
​
* set a flag, *bool flag* during the nonbolded states, indicating we *use cached states instead of manipulating the pointer*.
* store the expected hasNext() value in *bool expected* before advancing the pointer in peek()
* And once we have called next() in peek we have to store this next value in *int val* to refer to in nonbolded peek() and the bolded next() <br><br>
​
​
All operations run in **O(1)** time.
​
​