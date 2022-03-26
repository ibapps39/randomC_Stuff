#include <stdlib.h>
#include <stdio.h>
#include <memory.h>



int main(void) {
    int a = 0;
    float b = 0.0;
    double c = 0.000;
    char d = 'a';
    char* e = "abc";
    long f = 10000000L;
    short g = -100; //or positive
    unsigned int h = -100; //cant be negative. UnSigned == not signed == no +/- only positve.
    {
        /*
        printf("%i \n", *h);
        Generates an error but just unsigned h = -1 compiles with no error. 
        However printf("%i", h) does work with no warning nor error generated from VSCode or GCC.
        To generate an error, I instead created a pointer, int* ptr = &h; , which gave the expected error messaging.
        */
    }
    signed int i; //redundant. All numbers are signed unless specified by default
    int j[5]; //declared but not allocated 
    void* k;
    const size_t l = 0; /* == size_t is the return type of sizeof(). 
    sizeof() returns the size of a type in bytes. 
    sizeof(dataType) ==> size_t #ofBytesInType. Here we are  saying that l is the return of sizeOf, is constant, and is 0 bytes. */
    {
        const size_t l = 256; // const size_t l is assigned a value of (int)256. Which becomes 256UL. l = 256UL
        int aa;
        printf("%i \n", l == sizeof(aa)); // 0 = false. [int(0) when hovering is the result of the == being casted to int] 256UL == (unsigned long)4UL
        aa = 55;
        printf("%i \n", l == sizeof(aa)); // 0 = false       
        int aaa = 0;
        printf("%i \n", l == sizeof(aaa)); // 0 = false
        // but ..
        const size_t ll = sizeof(a); // works, no error(s) nor warning(s) generated. ll is 4UL being assinged to (size_t)4L. Otherwise 4UL = (size_t)4UL = 4UL
        printf("%i \n", ll == sizeof(a)); // 1  = true 
        printf("%i \n", ll == sizeof(aa)); // 1 = true
        printf("%zu \n", ll); // prints "4"
        printf("%zu \n", sizeof(ll)); // prints "8"
        printf("%zu \n", sizeof(0)); // prints "4"
        printf("%zu \n", sizeof(a)); // prints "4"
        printf("%zu \n", sizeof(256UL)); // prints "8"
        printf("%i \n", 256UL == 4UL); // prints "8"
        printf("%i \n", 0 == 4UL); // prints "0"
        printf("%i \n", 0 == 4UL); // "0" false
        printf("%i \n", d == 4UL); // "0" false
        printf("%i \n", *e == 4UL); // "0" false
        /*
            printf("%zu\n", x);  // prints as unsigned decimal
            printf("%zx\n", x);  // prints as hex
            printf("%zd\n", y);  // prints as signed decimal
            from https://stackoverflow.com/questions/2524611/how-can-one-print-a-size-t-variable-portably-using-the-printf-family
        */ 
    }
    int* o = malloc(sizeof(a)); //Declares a pointer, that points to some int, as 'o' AND allocates size_t bytes. 
    {
        /*
        In C, malloc returns a type of void* which is IMPLICITLY converted to the type of the delcared variable the pointer is declared as.
        Technically, malloc returns a void* can be converted into anything (void*) malloc(size_t size) ~~ malloc(sizeof(type)) where (void*) is implicit
        */
    }
    free(o);

    int arr[1]; //delcare an int array of capcaity 1
    arr[0] = 1;
    int* arrPtr = arr; //pointer that points to an arrayzz
    struct customType
    {
        /* data */
        int someIntVar;
        char someChar;
        char* someString;
        struct customType* someCustomPointer;
    };
    
    struct customeBluePrint
    {
        /* data */
        int abc;
    } structAsVar;
    
    typedef struct structAsType
    {
        /* data */
        int* a;
        char b;
        char* c;
        struct structAsType* ptr;
    } customTypeStruct;

    struct customType object;
    object.someChar = 'a';
    struct customType* ptrA = &object;
    structAsVar.abc = 0;
    struct customeBluePrint* ptrB = &structAsVar;
    customTypeStruct object2;
    object2.ptr = &object2;
    customTypeStruct* ptrC = &object2;

    int arrArith[3] = {1,22,3};
    int* arrOfPtr = arrArith; //Pointers and arrays are quite similar, hence why no & needed.
    int** ptrArith = &arrOfPtr;
    printf("%i\n", arrArith[1]); // prints 22
    printf("%i\n", *arrOfPtr+1); // prints 22
    printf("%i\n", **ptrArith+1); // prints 22
    void* somePtrToMem = malloc(sizeof(int));
    printf("%p\n", somePtrToMem); // prints addr
    printf("%p\n", somePtrToMem+1); // prints next addr in mem
    free(somePtrToMem);
    int* somePtrToArr = arrArith;
    printf("%i\n", *(somePtrToArr+1)); // prints 22
    return 0;
}
