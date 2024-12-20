To fill in these tables, we first need to determine the hash values for each data item based on the first letter according to the given table. Then, we'll insert each item into the tables according to the specified collision resolution strategies: linear probing, quadratic probing, and chaining.

Given hash values for the first letters are:
- A: 15, B: 11, C: 6, D: 11, E: 13, F: 15, G: 4, H: 11, I: 12, J: 9, K: 7, L: 3, M: 4
- N: 11, O: 5, P: 13, Q: 6, R: 12, S: 15, T: 7, U: 3, V: 9, W: 10, X: 13, Y: 10, Z: 4

The sequence of 13 data items to hash:
- UQ: 3
- GR: 4
- GD: 4
- WZ: 10
- QS: 6
- NW: 11
- DT: 7
- AX: 15
- SL: 15
- CY: 10
- EM: 13
- MR: 4
- NZ: 11

### Closed, Unbucketed Hash Table Using Quadratic Probing

| Index | Item |
|-------|------|
| 0     |      |
| 1     | GD   |
| 2     |      |
| 3     | UQ   |
| 4     | GR   |
| 5     |      |
| 6     | QS   |
| 7     | DT   |
| 8     | MR   |
| 9     |      |
| 10    | WZ   |
| 11    | NW   |
| 12    | CY   |
| 13    | EM   |
| 14    |      |
| 15    | AX   |

### Closed, Unbucketed Hash Table Using Linear Probing

| Index | Item |
|-------|------|
| 0     | SL   |
| 1     |      |
| 2     |      |
| 3     | UQ   |
| 4     | GR   |
| 5     | GD   |
| 6     | QS   |
| 7     | DT   |
| 8     | MR   |
| 9     |      |
| 10    | WZ   |
| 11    | NW   |
| 12    | CY   |
| 13    | EM   |
| 14    | NZ   |
| 15    | AX   |



### Open, Bucketed Hash Table (With Chaining)

| Index | Items         |
|-------|---------------|
| 0     |               |
| 1     |               |
| 2     |               |
| 3     | UQ            |
| 4     | GR, GD, MR    |
| 5     |               |
| 6     | QS            |
| 7     | DT            |
| 8     |               |
| 9     |               |
| 10    | WZ, CY        |
| 11    | NW, NZ        |
| 12    |               |
| 13    | EM            |
| 14    |               |
| 15    | AX, SL        |

These tables demonstrate how each collision resolution strategy organizes the data items based on their hash values. The linear and quadratic probing strategies avoid collisions by finding the next available slot according to their respective algorithms, while the chaining strategy allows multiple items to exist at the same hash value by using a list.


0  
1  
2  
3  UQ CY
4  GR GD
5  
6  
7  
8  
9  
10 WZ
11 NW DT NZ
12 MR
13 EM
14  
15 QS AX SL


0  
1  
2  
3  UQ
4  GR
5  GD
6  CY
7  
8  
9  WZ
10 NW
11 DT
12 AX
13 QS
14 SL
15 NZ

0  ⇒  
1  ⇒  
2  ⇒  
3  ⇒  UQ -> CY
4  ⇒  GR -> GD
5  ⇒  
6  ⇒  
7  ⇒  
8  ⇒  
9  ⇒  
10 ⇒  WZ
11 ⇒  NW -> DT -> NZ
12 ⇒  MR
13 ⇒  EM
14 ⇒  
15 ⇒  QS -> AX -> SL
