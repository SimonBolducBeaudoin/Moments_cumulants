#include <moments_cumulants.h>

// Explicit instantiation
// see: https://en.cppreference.com/w/cpp/language/function_template

#define MOMENT(BIN_TYPE,ABSCISSE_TYPE)\
template double moment( BIN_TYPE* histogram , ABSCISSE_TYPE* bins , uint n_bins , uint exp , uint64_t n_total , int n_threads ); \
template double moment( BIN_TYPE* histogram , ABSCISSE_TYPE* bins , uint n_bins , uint exp_x , uint exp_y , uint64_t n_total , int n_threads ); \
template double moment_no_clip( BIN_TYPE* histogram , ABSCISSE_TYPE* bins , uint n_bins , uint exp , uint64_t n_total , int n_threads ); \
template double moment_no_clip( BIN_TYPE* histogram , ABSCISSE_TYPE* bins , uint n_bins , uint exp_x , uint exp_y , uint64_t n_total , int n_threads ); 

MOMENT(uint64_t,double);
MOMENT(uint,double);

#undef MOMENT 



