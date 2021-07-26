# Hashing implementation using c++ STL

- Hashing in C++ can be implemented using different containers present in STL as per the requirement. Usually, STL offers the below-mentioned containers for implementing hashing:
1. set
1. unordered_set
1. map
1. unordered_map

## Set
- Some basic functions associated with Set: 
begin() – Returns an iterator to the first element in the set.

end() – Returns an iterator to the theoretical element that follows last element in the set.
<br />
size() – Returns the number of elements in the set.
insert(val) – Inserts a new element val in the Set.
<br />
find(val) - Returns an iterator pointing to the element val in the set if it is present.
<br />
empty() – Returns whether the set is empty.

## set vs unordered_set

- Set is an ordered sequence of unique keys whereas unordered_set is a set in which key can be stored in any order, so unordered.
- Set is implemented as a balanced tree      structure that is why it is possible to maintain order between the elements (by specific tree traversal). 
- The time complexity of set operations is O(Log n) while for unordered_set, it is O(1).