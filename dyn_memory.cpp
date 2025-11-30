/*
1. C functions: malloc, calloc, realloc, free.
2. C++ operators: new, delete

*/

#include "include.h"

// C
void malloc_fun(){
    // total size of memory specifed
    int *p = (int*)malloc(2*sizeof(int)); //explict type cast required if used in C++
    if(p==nullptr){
        //mem alloc can fail, so check
    }
    free(p);
    p=nullptr; // important otherwise p points to invalid memory address
    free(p); // does nothing
}

void calloc_fun(){
    // args = number of elements, size of each element
    int *p = (int*)calloc(2, sizeof(int)); //explict type case required if used in C++
    if(p==nullptr){
        //mem alloc can fail, so check
    }
    free(p);
    p=nullptr; // important otherwise p points to invalid memory address
    free(p); // does nothing
}

void realloc_fun(){
    //void *realloc(void *ptr, size_t size) attempts to resize the memory block pointed to by ptr 
    //that was previously allocated with a call to malloc or calloc.
    //size is the final size
    char *str = (char *) malloc(15);
    strcpy(str, "tutorialspoint"); //also copies the null character
    printf("String = %s,  Address = %u\n", str, str);

    str = (char *) realloc(str, 25);
    strcat(str, ".com");
    printf("String = %s,  Address = %u\n", str, str);

    free(str);
}

// C++
void new_del(){
    int *p = new int(5);
    *p=3;
    delete p;
    p=nullptr;

    //allocate 1D array on heap
    int *a = new int[5]{1,2,3,4,5}; //can be directly initialized
    delete []a;

    //allocate 2D array of size 2 rows, 3 cols on heap
    int *p1 = new int[3]{1,2,3}; //row1
    int *p2 = new int[3]{4,5,6}; //row2

    int **pData = new int*[2]{p1,p2}; //array of pointers
    std::cout<<pData[0][0];


    delete []p1;
    delete []p2;
    delete []pData;

    //delete p: deletes underlying memory stored at address p,i.e., if *p was 100, now it becomes *p=0. But p still holds the address e.g. p=0xab2f.
    // So it is good practice to set p=nullptr
}
int main(){
   new_del();
}

/*
1. Different types of memory: stack, heap, data section.
2. Stack and data section is managed by the runtime, heap is managed by programmer.
3. C provides various functions for allocating dynamic memory.
malloc(raw memory), calloc(initializes to 0), realloc(allocates larger chunk of memory for existing allocation), free.

| malloc                                           | new                                   |
|--------------------------------------------------|---------------------------------------|
| Function                                         | Operator                              |
| Requires size during allocation                  | Size is ascertained from the types    |
| Cannot initialize memory                         | Can initialize memory                 |
| Cannot call constructors                         | Can call constructors                 |
| Returns void pointer that needs to be typecasted | Returns correct pointer type          |
| Cannot be customized                             | Can be customized through overloading |
| malloc, calloc, realloc                          | Has different forms                   |
| returns NULL on failure                           | throws exception on failure           |
*/