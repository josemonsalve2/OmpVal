#include <stdlib.h>
#include <numeric>
#include <math.h>
#include <cassert>
#include <iostream>
#include <cmath>

void test_target_parallel(){

    // Declare Size of Loop
    

    // Initialize array
    int A = 0;

    // Computation
    
            
                #pragma omp target parallel  map(tofrom: A) 
            {
            

            
            {
        
        #pragma omp atomic update
        A++;
        
        
            
            }
            
            }
    

    // Validation
    
    assert( A >= 0 );
    

    std::cout << "OK" << std::endl ;
}   

int main()
{
    test_target_parallel();
}
