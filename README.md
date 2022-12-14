# philosophers.
The dining philosophers is a problem formulated in 1965 by Edsger Dijkstra. This example is often used to illustrate synchronization issues in "concurrency algorithms".

The problem is formulated like this:

Some philosophers dine together at the same table. Each philosopher has their own place at the table. There is a fork between each plate. The dish served is a kind of spaghetti which has to be eaten with two forks. Each philosopher can only alternately think eat and sleep. Moreover, a philosopher can only eat their spaghetti when they have both a left and right fork. Thus two forks will only be available when their two nearest neighbors are not eating. After an individual philosopher finishes eating, they will put down both forks. The problem is how to design an algorithm (a concurrent algorithm) such that no philosopher will starve; So that each can forever continue to alternate between eating thinking and sleeping, assuming that Philosophers don’t speak with each other (an issue of incomplete information). 

Peterson's Algorithm:
https://en.wikipedia.org/wiki/Peterson%27s_algorithm
