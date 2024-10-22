# Search the Dark - Report

## Group Members
| Name | Student ID |
| --- | --- |
| Dervla Gargan | 22346279 |
| Amy McMahon | 22346619 |

## Contributions
Overall: 50% 50% contribution
| Feaure | Contributior | Percentage |
| --- | --- | ---|
| Console | Dervla | 100% |
| Search Syntax | Dervla | 100% |
| Trie | Dervla | 100% |
| Make Files | Dervla | 100% |
| Map | Amy | 100% |
| Indexer | Amy | 100% |
| Vector | Amy and Dervla | 70% 30% |
| Quicksort | Amy and Dervla | 60% 40%|
| Report | Amy and Dervla |90% 10% |

## Git Commits
| Name | Commits | LoC |
| --- | --- | --- |
| Dervla Gargan | 28 | 2,804 |
| Amy McMahon | 26 | ??? - github wasnt logged in correctly |

**Note:** Amy's github is broken

## Analysis
- ### Quicksort
  - ##### Big O Notation
      - O(n log n) - On average, the pivot divides the array into two parts, but not necessarily equal.
  - ##### Justification for design decisions
      - divide-and-conquer algorithm with a low overhead. It is easy to avoid the worst case time complexity O(n^2) by selecting an appropriate pivot value
- ### Vector
  - ##### Big O Notation
      - Insert = O(1) - (O(n) when resizing needed)
      - Erase = O(n)
      - Search = 0(n)
  - ##### Justification for design decisions
      - Insertion into our data structure was important and vector has O(1) compared to other structures. Vector provides an optimal balance of time complexity, memory management, and simplicity.
- ### Trie
  - ##### Big O Notation
      - Insert = O(m *n) (m=num of words, n = num of chars)
      - Search = O(m *n) (m=num of words, n = num of chars)
  - ##### Justification for design decisions
      - The Trie structure is particularly suited for autocomplete functionality because it allows for fast prefix searches. Each character in a query can be processed sequentially, making it efficient for retrieving potential matches. The structure supports operations such as insertion, search, and deletion of keys, making it a valuable tool for info retrieval. The ranking mechanism based on popularity ensures that the most relevant results are presented first. This is important for user experience in autocomplete scenarios.
- ### Inverted Index
  - ##### Big O Notation
    - Adding files = O(m * n) (m=num of words)
    - Deleting files = O(m * n) (m=num of words)
    - read in Index  = O(n)
  - ##### Justification for design decisions
      - Inverted Index is a data structure used in information retrieval systems to efficiently retrieve documents or web pages containing a specific term or set of terms. This is why we decided to use it for our project. By indexing every term in every document, the index can quickly identify all documents that contain a given search term or phrase, significantly reducing search time.
- ### Map (using AVL tree)
  - ##### Big O Notation
      - Balancing  = O(log n)
      - Insert = O(log n)
      - Delete = O(log n)
  - ##### Justification for design decisions
      -  The tree structure ensures that operations like insertion, deletion, and searching take O(log n) time. By balancing the tree after each modification, the implementation avoids the worst-case O(n) time complexity that can occur in unbalanced binary trees. Our map often involves frequent insertion of new keys and modification of existing ones as the files are read in. AVL trees handle these dynamic updates efficiently by automatically balancing the tree through rotations 


## References
## References
- [Trie Data Strucuture](https://www.geeksforgeeks.org/trie-data-structure-in-cpp/)
- [Auto-Complete Trie](https://www.geeksforgeeks.org/auto-complete-feature-using-trie/)
- [Inverted Index](https://www.geeksforgeeks.org/inverted-index/)
- [Map](https://medium.com/@abhishekjr/c-program-to-implement-map-class-2c5138165452)
- [Vector](https://www.geeksforgeeks.org/how-to-implement-our-own-vector-class-in-c/)
- Syntax Functions
  - [AND](https://en.cppreference.com/w/cpp/algorithm/set_intersection)
  - [OR](https://en.cppreference.com/w/cpp/algorithm/set_union)
  - [NOT](https://en.cppreference.com/w/cpp/algorithm/set_difference#Version_1)
### AI Usage Explanations
We used chatgpt to generate the books we used for indexing. 
We used chat gpt for debugging code
