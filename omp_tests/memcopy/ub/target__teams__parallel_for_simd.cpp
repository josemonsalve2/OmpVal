#include <stdlib.h>
#include <numeric>
#include <math.h>
#include <cassert>
#include <iostream>
#include <cmath>

void test_target__teams__parallel_for_simd(){

    // Declare Size of array
    
    const int L = 10;

    // Initialize array
    double A[L];
    double B[L] = { 0,1,2,3,4,5,6,7,8,9 };

    // Computation
    
        
           #pragma omp target  map(from: A[0:L]) map(to: B[0:L]) 
            {
        
           #pragma omp teams 
            {
        

        
            #pragma omp parallel for simd 
            for (int i = 0 ; i < L ; i++ )
        
        {
    
        
    A[i] = B[i];

    
        
        }
        
        }
        
        }
    

    // Validation
    
        
        for (int i = 0 ; i < L ; i++ )
        
        {
    
    assert( std::fabs( A[i] - B[i]) < 1E-9 );
        }
    std::cout << "OK" << std::endl ;
}

int main()
{
    test_target__teams__parallel_for_simd();
}
