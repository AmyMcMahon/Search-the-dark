# Search the Dark - Report

## Group Members
| Name | Student ID |
| --- | --- |
| Dervla Gargan | 22346279 |
| Amy McMahon | 22346619 |

## Contributions
| Feaure | Contributior | Percentage |
| --- | --- | ---|
| Console | Dervla | 100% |
| Search Syntax | Dervla | 100% |
| Trie | Dervla | 100% |
| Make Files | Dervla | 100% |
| Map | Amy | 100% |
| Indexer | Amy | 100% |
| Vector | Amy and Dervla | 60% 40% |
| Quicksort | Amy and Dervla | 60% 40%|

## Git Commits
| Name | Commits | LoC |
| --- | --- | --- |
| Dervla Gargan | | |
| Amy McMahon | | |

**Note:** Amy's github is broken

## Analysis
- ### Quicksort
  - ##### Big O Notation
      - O(n log n) - On average, the pivot divides the array into two parts, but not necessarily equal.
  - ##### Justification for design decisions
      - divide-and-conquer algorithm with a low overhead. It is easy to avoid the worst case time complexity O(n^2) by selecting an appropriate pivot value
- ### Vector
  - ##### Big O Notation
  - ##### Justification for design decisions
- ### Trie
  - ##### Big O Notation
  - Justification for design decisions
- ### Inverted Index
  - ##### Big O Notation
  - ##### Justification for design decisions
- ### Map (using AVL tree)
  - ##### Big O Notation
      - Balancing  = O(log n)
      - Insert = O(log n)
      - Delete = O(log n)
  - ##### Justification for design decisions
      -  The tree structure ensures that operations like insertion, deletion, and searching take O(log n) time. By balancing the tree after each modification, the implementation avoids the worst-case O(n) time complexity that can occur in unbalanced binary trees. Our map often involves frequent insertion of new keys and modification of existing ones as the files are read in. AVL trees handle these dynamic updates efficiently by automatically balancing the tree through rotations 


## References
- Sources
### AI Usage Explanations
We used chatgpt to generate the books we used for indexing. 
We used chat gpt for debugging code
