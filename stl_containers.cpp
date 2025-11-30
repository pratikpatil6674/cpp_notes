#include "include.h"
#include <array>
#include <deque>
#include <list>
#include <forward_list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
void Array(){
    // static array
    std::array<int, 5> arr{1,2,3,4,5};

    for(int i=0; i<arr.size(); i++){
        println(arr[i]);
    }

    for(auto itr = arr.begin(); itr!=arr.end(); itr++){
        println(*itr);
    }

    for(auto x: arr){
        println(x);
    }

}

void Vector(){
    // dynamic array
    // efficient for addition/removal at the end
    // not good for insertion/deletion
    std::vector<int> vec{1,2,3,4,5};
    for(int i=0; i<vec.size(); i++){
        print(vec[i]);
    }
    println();
    vec.push_back(6);
    vec.insert(vec.end()-2, -3); // (position, value)
    for(auto itr = vec.begin(); itr!=vec.end(); itr++){
        print(*itr);
    }
    println();

    vec.erase(vec.end()-1); // erase based on position.
    std::erase(vec, -3); // erase based on value, added in C++20 for any sequence container
    for(auto x: vec){
        print(x);
    }
    println();
    println("Vector capacity before shrink to fit", vec.capacity());
    vec.shrink_to_fit(); // make capacity same as size to save memory
    println("Vector capacity after shrink to fit", vec.capacity());

    vec.resize(100); // change size of the buffer
    println("Vector size and capacity after resize()", vec.size(), vec.capacity());

    // access underlying buffer vec.data();
}

void Deque(){
    // Double ended queue
    // efficient for addition/removal at BOTH ends
    // not good for insertion/deletion
    std::deque<int> deq{1,2,3,4,5};
    for(int i=0; i<deq.size(); i++){
        println(deq[i]);
    }

    deq.push_back(6);
    deq.push_front(-9);
    deq.insert(deq.end()-2, -3); // (position, value)
    for(auto itr = deq.begin(); itr!=deq.end(); itr++){
        println(*itr);
    }

    deq.erase(deq.end()-1); // (position)
    for(auto x: deq){
        println(x);
    }

}

void List(){
    // implemented as doubly linked list
    // good for insertion deletion
    // allows traversal in both direction
    std::list<int> ls{1,2,3,4,5};
  
    ls.push_back(6);
    ls.insert(ls.end(), -3); // (position, value)
    for(auto itr = ls.begin(); itr!=ls.end(); itr++){
        println(*itr);
    }
    auto it = ls.end(); // ls.end()-1 is not possible
    ls.erase(--it); // (position)
    for(auto x: ls){
        println(x);
    }
}

void Forward_List(){
    // implemented as singly linked list
    // good for insertion deletion
    // small memory footprint
    // elements are added at the front, results in reversed list
    std::forward_list<int> ls{1,2,3,4,5};
  
    ls.push_front(6); // no push_back, 6 1 2 3 4 5
    ls.insert_after(ls.begin(), -3); // (position, value),  6 -3 1 2 3 4 5
    for(auto itr = ls.begin(); itr!=ls.end(); itr++){
        print(*itr);
    }
    println();
    auto it = ls.begin();
    ls.erase_after(it); // (position) 6 1 2 3 4 5
    for(auto x: ls){
        print(x);
    }
}

void OrderedSet(){
    /* implemented as binary tree
    stores only unique elements
    elements are stored in sorted order(< (default) or  >)
    value acts as key, fast search
    no random access
    elements cannot be modified directly
    associative containers have const iterators
    */
   std::set<int> s{4,7,3,3,9,0};
   auto printSet = [&](){for(auto itr = s.begin(); itr!=s.end(); itr++){print(*itr);}println();};
   printSet();
   s.insert(1);
   printSet();
   s.erase(4);
   s.erase(s.begin());
   printSet();
   auto itr = s.find(9);
   if (itr != s.end()){
    print("Element found");
   }

}
void OrderedMultiSet(){
    /* implemented as binary tree
    store non-unique elements as well
    elements are stored in sorted order(< (default) or  >)
    value acts as key, fast search
    no random access
    elements cannot be modified directly
    associative containers have const iterators
    */
   std::multiset<int> s{4,7,3,3,9,0};
   auto printSet = [&](){for(auto itr = s.begin(); itr!=s.end(); itr++){print(*itr);}println();};
   printSet();
   s.insert(1);
   s.insert(1);
   s.insert(1);
   s.insert(1);
   printSet();
   s.erase(4); //using key
   s.erase(s.begin()); // using iterator
   printSet();
   auto itr = s.find(9);
   if (itr != s.end()){
    println("Element found");
   }
   // multiple 1s are present, returns pair
   auto found = s.equal_range(1);
   // found.first = iterator to first occurence of the key specified
   // found.second = iterator to first element greater than the key 
   while(found.first != found.second){
    print(*found.first++);
   }
}

void OrderedMap(){
    /* implemented as binary tree
    stores a pair that comtains a key and a pair
    elements are stored in sorted order based on key
    fast search
    no random access
    keys cannot be modified directly, values can be modified
    associative containers have const iterators
    Duplicates are allowed in multimap
    */
   std::map<int,std::string> m{
    {1, "Batman"},
    {2, "Superman"},
    {3, "Wonder Woman"}
   };
   auto printMap = [&](){for(auto itr = m.begin(); itr!=m.end(); itr++){print(itr->first, ":", itr->second);}println();};
   printMap();
   m[0]="Flash";
   printMap();

   m.erase(3); // (key)
   printMap();

    std::multimap<int, std::string> mm{
        {3, "Captian America"},
        {6, "Flash"},
        {6, "Flash"},
        {6, "Flash"},
    };
   // multiple 6s are present, returns pair
   auto found = mm.equal_range(6);
   // found.first = iterator to first occurence of the key specified
   // found.second = iterator to first element greater than the key 
   while(found.first != found.second){
    print(found.first->first, ":", found.first->second);
    found.first++;
   }


}

void UnorderedMap(){
    // stores pair object
    // uses hash table
    // no duplicates allowed
    std::unordered_map<std::string, std::string> um;
    um["k1"] = "v1";
    um["k2"] = "v2";
    um["k3"] = "v3";

    for(const auto &x : um){
        println("Bucket #:", um.bucket(x.first), ":", x.second );
    }
    
}

void UnorderedMultiMap(){
    // stores pair object
    // uses hash table
    // no subscript operator, use insert function
    std::unordered_multimap<std::string, std::string> um;
    um.insert(std::make_pair("k1","v1"));
    um.insert(std::make_pair("k1","v1"));
    um.insert(std::make_pair("k2","v2"));
    um.insert(std::make_pair("k3","v3"));

    for(const auto &x : um){
        println("Bucket #:", um.bucket(x.first), ":", x.second );
    }
    
}
void UnorderedSet(){
    // hashtable is used to implement this datatype
    // does not allow duplicates
    // datatype should have hash function.
    // custom datatypes must implement their own hash functions and equality operators. Use hash combine library from boost

    std::unordered_set<std::string> us;
    us.insert("s1");
    us.insert("s2");
    us.insert("s3");
    us.insert("s4");
    us.insert("s5");
    us.insert("s6");
    for(const auto x : us){
        println("Bucket #:", us.bucket(x), "contains : ", x);
    }
    println("Bucket count :", us.bucket_count());
    println("Number of elements:", us.size());
    println("Load factor", us.load_factor()); // entries/capacity
}

void UnorderedMultiSet(){

    // hashtable is used to implement this datatype
    // Allows duplicates

    std::unordered_multiset<std::string> ums;
    ums.insert("s1");
    ums.insert("s2");
    ums.insert("s3");
    ums.insert("s3");
    ums.insert("s3");
    ums.insert("s3");
    for(const auto x : ums){
        println("Bucket #:", ums.bucket(x), "contains : ", x);
    }
    println("Bucket count :", ums.bucket_count());
    println("Number of elements:", ums.size());
    println("Load factor", ums.load_factor());
}


int main(){
  Vector();
}


/*
Function objects vs function pointers. Former can save state
Containers will prefer move over copy.
Learn about emplace functions
If you want to store custom objects in containers and use move semantics, your move overloads must me marked with noexcept.

*/

