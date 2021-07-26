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

## Map Container
- As a set, the Map container is also associative and stores elements in an ordered way but Maps store elements in a mapped fashion. Each element has a key value and a mapped value. No two mapped values can have the same key values.

- Some basic functions associated with Map:
- begin() – Returns an iterator to the first element in the map.
- end() – Returns an iterator to the theoretical element that follows last element in the map.
- size() – Returns the number of elements in the map.
- empty() – Returns whether the map is empty.
insert({keyvalue, mapvalue}) – Adds a new element to the map.
- erase(iterator position) – Removes the element at the position pointed by the iterator
- erase(const g)– Removes the key value ‘g’ from the map.
- clear() – Removes all the elements from the map.

## unordered_map Container
- The unordered_map is an associated container that stores elements formed by a combination of key value and a mapped value. 
- The key value is used to uniquely identify the element and mapped value is the content associated with the key. Both key and value can be of any type predefined or user-defined.
- Internally unordered_map is implemented using Hash Table, the key provided to map are hashed into indices of a hash table that is why the performance of data structure depends on hash function a lot but on an average, the cost of search, insert and delete from hash table is O(1).

## unordered_map vs unordered_set


- In unordered_set, we have only key, no value, these are mainly used to see presence/absence in a set. For example, consider the problem of counting frequencies of individual words. We can’t use unordered_set (or set) as we can’t store counts.

## unordered_map vs map

- map (like set) is an ordered sequence of unique keys whereas in the unordered_map key can be stored in any order, so unordered.
A map is implemented as a balanced tree structure that is why it is possible to maintain order between the elements (by specific tree traversal). The time complexity of map operations is O(Log n) while for unordered_set, it is O(1) on average.
