#4
q.b
Run the program and describe what happens. Why do you think the program crashes on ascending and/or descending data for the basic quicksort, once the data set gets to a basic size?
Because we are always partitioning into two subsets where one is the max size and the other is the min size,
we overflow the memory storage with partitions based on the worst-case number of recursive calls and the worst-case ratio of elements in each partition.
