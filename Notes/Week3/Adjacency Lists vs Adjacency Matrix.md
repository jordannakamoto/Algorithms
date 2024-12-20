Big O (min(v ,e )) whichever is the smaller constrains the size of the multiple of each term....


Adjacency List
- Advantage: **only actual edges stored**
- Disadvantage: often need linear search to find each edge in Adjacency List (linked list indexed within an array of adjacency linked list rows]

Adjacency Matrix
Advantages:
- fast look-up
- manipulation of Adjacency Matrix has important properties... based on linear algebra
- potential storage of lots of 0s makes this space complexity in worst case scenario On^2

Conclusion:

Choice of **internal representation** may depend upon nature of an application (**external representation**)