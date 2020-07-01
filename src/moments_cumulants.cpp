#include <moments_cumulants.h>

#define MOMENT(BIN_TYPE,ABSCISSE_TYPE)\
template double moment( BIN_TYPE* histogram , ABSCISSE_TYPE* bins , uint n_bins , uint exp , uint64_t n_total , int n_threads ); \
template double moment( BIN_TYPE* histogram , ABSCISSE_TYPE* bins , uint n_bins , uint exp_x , uint exp_y , uint64_t n_total , int n_threads );

MOMENT(uint64_t,double);
MOMENT(uint,double);

#undef MOMENT 

// Explicit instantiation
// see: https://en.cppreference.com/w/cpp/language/function_template

//////////////////////////////////
// Monovariate
//////////////////////////////////
// template double moment_k(uint64_t* histogram, uint64_t nofbins, uint k, double first_bin_center , double bin_width );
// template double moment_k(uint32_t* histogram, uint64_t nofbins, uint k, double first_bin_center , double bin_width );
// template double moment_k(uint16_t* histogram, uint64_t nofbins, uint k, double first_bin_center , double bin_width );
// template double moment_k(uint8_t* histogram, uint64_t nofbins, uint k, double first_bin_center , double bin_width );

// template double centered_moment_k(uint64_t* histogram, uint64_t nofbins, uint k, double first_bin_center , double bin_width );
// template double centered_moment_k(uint32_t* histogram, uint64_t nofbins, uint k, double first_bin_center , double bin_width );
// template double centered_moment_k(uint16_t* histogram, uint64_t nofbins, uint k,double first_bin_center , double bin_width );
// template double centered_moment_k(uint8_t* histogram, uint64_t nofbins, uint k, double first_bin_center , double bin_width );

// template double cumulant_k(uint64_t* histogram, uint64_t nofbins, uint k, double first_bin_center , double bin_width);
// template double cumulant_k(uint32_t* histogram, uint64_t nofbins, uint k, double first_bin_center , double bin_width);
// template double cumulant_k(uint16_t* histogram, uint64_t nofbins, uint k, double first_bin_center , double bin_width);
// template double cumulant_k(uint8_t* histogram, uint64_t nofbins, uint k, double first_bin_center , double bin_width);

//////////////////////////////////
// Multivariate 
//////////////////////////////////

// template double moment2D(uint64_t* histogram, uint64_t nofbins, uint exp_x , uint exp_y , double first_bin_center , double bin_width );
// template double moment2D(uint32_t* histogram, uint64_t nofbins, uint exp_x , uint exp_y , double first_bin_center , double bin_width );
// template double moment2D(uint16_t* histogram, uint64_t nofbins, uint exp_x , uint exp_y , double first_bin_center , double bin_width );
// template double moment2D(uint8_t* histogram, uint64_t nofbins, uint exp_x , uint exp_y , double first_bin_center , double bin_width );

// template double cumulant_ii(uint64_t* histogram, uint64_t nofbins, double first_bin_center , double bin_width );
// template double cumulant_ii(uint32_t* histogram, uint64_t nofbins, double first_bin_center , double bin_width );
// template double cumulant_ii(uint16_t* histogram, uint64_t nofbins, double first_bin_center , double bin_width );
// template double cumulant_ii(uint8_t* histogram, uint64_t nofbins, double first_bin_center , double bin_width );

// template double cumulant_jj(uint64_t* histogram, uint64_t nofbins, double first_bin_center , double bin_width );
// template double cumulant_jj(uint32_t* histogram, uint64_t nofbins, double first_bin_center , double bin_width );
// template double cumulant_jj(uint16_t* histogram, uint64_t nofbins, double first_bin_center , double bin_width );
// template double cumulant_jj(uint8_t* histogram, uint64_t nofbins, double first_bin_center , double bin_width );

// template double cumulant_iijj(uint64_t* histogram, uint64_t nofbins, double first_bin_center , double bin_width );
// template double cumulant_iijj(uint32_t* histogram, uint64_t nofbins, double first_bin_center , double bin_width );
// template double cumulant_iijj(uint16_t* histogram, uint64_t nofbins, double first_bin_center , double bin_width );
// template double cumulant_iijj(uint8_t* histogram, uint64_t nofbins, double first_bin_center , double bin_width );



