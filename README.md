ACM-ICPC 
===============

List of basic algorithms and data structures for algorithmic programming competitions (International Olympiad in Informatics (IOI),  ACM International Collegiate Programming Competition (ICPC), Google Code Jam, Facebook Hacker Cup, etc.).

In the past, this list has been quite useful for solving algorithmic programming challenges on online judges like the Sphere Online Judge (SPOJ) and competitions.

Most of this has been coded during high-school (2008-2010) while preparing for the IOI. Consider this a disclaimer about the coding style. I will try to improve the code whenever I have some free time. Bullet-points that are not highlighted below have not been added yet. If you see any errors or would like to make some improvements, please feel free to set an issue, or even better, make a pull request.

The code is licensed under the MIT License, free to use, have fun!

Algebra
--------------------------


* **[Bignum](https://github.com/ippeb/ACM-ICPC/tree/master/algebra/bignum)** (addition, subtraction, multiplication, division)
* **[Prime Factorization](https://github.com/ippeb/ACM-ICPC/tree/master/algebra/prime_factorization)** *O(sqrt(n))*
* **[Prime Number Generator](https://github.com/ippeb/ACM-ICPC/tree/master/algebra/prime_generator)** (Sieve of Eratosthenes)
* **[GCD](https://github.com/ippeb/ACM-ICPC/tree/master/algebra/gcd_lcm)** (Greatest Common Divisor)
* **[LCD](https://github.com/ippeb/ACM-ICPC/tree/master/algebra/gcd_lcm)** (Lowest Common Multiple)
* **[Linear Congruence](https://github.com/ippeb/ACM-ICPC/tree/master/algebra/linear_congruence)** (Extended GCD)
* **Miller-Rabin Primality Test**

Combinatorics
--------------------------

* **[All Permutation](https://github.com/ippeb/ACM-ICPC/tree/master/combinatorics/all_permutation)**
* **[All Subsets](https://github.com/ippeb/ACM-ICPC/tree/master/combinatorics/all_subsets)**
* **[Next Permutation](https://github.com/ippeb/ACM-ICPC/tree/master/combinatorics/next_permutation)** (alphabetically higher) 

Graph Theory
--------------------------

* **[DFS](https://github.com/ippeb/ACM-ICPC/tree/master/graph_theory/dfs)** (Depth-First Search)
* **[BFS](https://github.com/ippeb/ACM-ICPC/tree/master/graph_theory/bfs)** (Breadth-First Search)
* **[Connected Components](https://github.com/ippeb/ACM-ICPC/tree/master/graph_theory/connected_components)**
* **[Dijkstra's Algorithm](https://github.com/ippeb/ACM-ICPC/tree/master/graph_theory/dijkstra)** (One Way Shortest Path)
* **[Prim's Algorithm](https://github.com/ippeb/ACM-ICPC/tree/master/graph_theory/prim)** (Minimum Spanning Tree)
* **[Kruskal's Algorithm](https://github.com/ippeb/ACM-ICPC/tree/master/graph_theory/kruskal)** (Minimum Spanning Tree)
* **[Floyd-Warshall](https://github.com/ippeb/ACM-ICPC/tree/master/graph_theory/floyd)** (All Way Shortest Path)
* **[Toposort](https://github.com/ippeb/ACM-ICPC/tree/master/graph_theory/toposort)** (Topological Sort)
* **[ArticFind](https://github.com/ippeb/ACM-ICPC/tree/master/graph_theory/articfind)** (Find all Articulation Points), *O(E)*
* **[Ford-Fulkerson's Algorithm with Capacity Scaling](https://github.com/ippeb/ACM-ICPC/tree/master/graph_theory/ford_fulkerson)** (Maxflow/Mincut)
* **[Dinic's Algorithm](https://github.com/ippeb/ACM-ICPC/tree/master/graph_theory/dinic)** (Maxflow/Mincut)
* **[Edmonds-Karp's Algorithm](https://github.com/ippeb/ACM-ICPC/tree/master/graph_theory/edmonds_karp)** (Maxflow/Mincut)
* **[Hierholzer's Algorithm](https://github.com/ippeb/ACM-ICPC/tree/master/graph_theory/hierholzer)** (Euler Cycle detection)
* **Bellman Ford** (for negative weights)
* **Bipartite Matching**


Computational Geometry
--------------------------

* **[Graham's Scan Algorithm](https://github.com/ippeb/ACM-ICPC/tree/master/computational_geometry/convex_hull)** (Convex Hull)
* **[Closest Pair of Points](https://github.com/ippeb/ACM-ICPC/tree/master/computational_geometry/closest_pair)** (Sweep Line)
* **[Line-Line Intersection](https://github.com/ippeb/ACM-ICPC/tree/master/computational_geometry/line_line_intersection)**
* **Segment-Segment Intersection**
* **Area of Polygon**
* **Line-Point Distance**
* **Point-Segment Distance**
* **Circle from Three Points**
* **Reflection**
* **Rotation**
* **Area of a Triangle** (three points)
* **Bentley-Ottman's Algorithm** (Sweep Line, finding all intersections of multiple line segments)
* **Shamos-Hoey Algorithm** (checking if there is an intersection given multiple line segments)
* **Crossing Number** (resp. Winding Number, method to check whether a point is inside a simple polygon (resp. non-simple polygon))

Data Structures
--------------------------

* **[Queue](https://github.com/ippeb/ACM-ICPC/tree/master/data_structure/queue)**
* **[Stack](https://github.com/ippeb/ACM-ICPC/tree/master/data_structure/stack)**
* **[Singly Linked List](https://github.com/ippeb/ACM-ICPC/tree/master/data_structure/linked_list)**
* **[Binary Indexed Tree](https://github.com/ippeb/ACM-ICPC/tree/master/data_structure/binary_indexed_tree)** (BIT)
* **[2D Binary Indexed Tree](https://github.com/ippeb/ACM-ICPC/tree/master/data_structure/binary_indexed_tree)** (2D BIT)
* **[Binary Search Tree](https://github.com/ippeb/ACM-ICPC/tree/master/data_structure/binary_search_tree)** (BST)
* **[Priority-Queue](https://github.com/ippeb/ACM-ICPC/tree/master/data_structure/priority_queue)**
* **[Heap](https://github.com/ippeb/ACM-ICPC/tree/master/data_structure/heap)**
* **[Segment Tree](https://github.com/ippeb/ACM-ICPC/tree/master/data_structure/segment_tree)**
* **[Dictionary](https://github.com/ippeb/ACM-ICPC/tree/master/data_structure/dictionary)** (STL Map)
* **[Set](https://github.com/ippeb/ACM-ICPC/tree/master/data_structure/set)** (STL Set)
* **[Suffix Array](https://github.com/ippeb/ACM-ICPC/tree/master/data_structure/suffix_array)** (resp. Suffix Sorting, determine if string is a subseq. of another string)
* **[Union-Find](https://github.com/ippeb/ACM-ICPC/tree/master/data_structure/union_find)** (Disjoint-Set Data Structure)
* **Doubly Linked List**
* **STL Vector**
* **Trie**
* **Hash Table**
* **Suffix Tree**


Dynamic Programming
--------------------------

A selection of solutions to fairly standard DP problems.

* **[Edit Distance](https://github.com/ippeb/ACM-ICPC/tree/master/dynamic_programming/edit_distance)**
* **[Longest Common Subsequence](https://github.com/ippeb/ACM-ICPC/tree/master/dynamic_programming/LCS)** (LCS)
* **[Longest Increasing Subsequence](https://github.com/ippeb/ACM-ICPC/tree/master/dynamic_programming/LIS)** (LIS), *O(nlogn)*
* **[Matrix Chain Multiplication](https://github.com/ippeb/ACM-ICPC/tree/master/dynamic_programming/MCM)** (MCM)
* **[Maximum Empty Rectangle](https://github.com/ippeb/ACM-ICPC/tree/master/dynamic_programming/MER)** (MER)
* **[Range Minimum Query, Sparse Table](https://github.com/ippeb/ACM-ICPC/tree/master/dynamic_programming/RMQ)** (RMQ)
* **Stable Marriage Problem**
* **Binomial Coefficient Solver**


String Manipulation
--------------------------

* **[String Handling](https://github.com/ippeb/ACM-ICPC/tree/master/string_handling/c_string_functions)** (in general)
* **[Knuth Morris Pratt](https://github.com/ippeb/ACM-ICPC/tree/master/string_handling/kmp)** (String Search)


Sorting
--------------------------

* **[Mergesort](https://github.com/ippeb/ACM-ICPC/tree/master/sorting/mergesort)**
* **[Quicksort](https://github.com/ippeb/ACM-ICPC/tree/master/sorting/qsort)**
* **[Radixsort](https://github.com/ippeb/ACM-ICPC/tree/master/sorting/radixsort)**

Misc
--------------------------

* **Majority Vote**
* **Inclusion/Exclusion** (using bit tricks)


