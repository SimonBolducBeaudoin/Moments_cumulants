#pragma once

// #include "../../includes/header_common.h" 
#include <omp_extra.h>
#include <math_extra.h>

/*
moment( histogram , bins , n_bins , exp_x , ... , n_total )
	- returns  the moment <X^exp_x Y^exp_y ...> 
		of the histogram defined by histogram, bins and  n_bins.
		It is only valid for squared histogram (same number of bin in each dimension)
		And for efficiency reasons n_total must be precalculated
	
	Variables :
	- histogram : a pointer to the histogram data linearly arranged in memory (C style)
	- bins : a pointer to the set of centered abscisse for each bin.
		bins are not necceraly evenly spaced.
	- n_bins : the length of the length of bins.
	- exp_x : the first exponent that defines the moment to calculate
	- exp_y : the 2nd exponent ...
	- ... 
	
	*/

/*
	Cannot do partial template specialization for function, see : https://en.wikipedia.org/wiki/Partial_template_specialization
	
	Can only do full specialization
	I could use macro instead
*/

template <class BinType,class AbscisseType>
double moment(BinType* histogram , AbscisseType* bins , uint n_bins , uint exp , uint64_t n_total , int n_threads );

template <class BinType,class AbscisseType>
double moment(BinType* histogram , AbscisseType* bins , uint n_bins , uint exp_x , uint exp_y , uint64_t n_total , int n_threads );

template <class BinType,class AbscisseType>
double moment_no_clip(BinType* histogram , AbscisseType* bins , uint n_bins , uint exp , uint64_t n_total , int n_threads );

template <class BinType,class AbscisseType>
double moment_no_clip(BinType* histogram , AbscisseType* bins , uint n_bins , uint exp_x , uint exp_y , uint64_t n_total , int n_threads );


/*
Ref:
http://www.stat.uchicago.edu/~pmcc/courses/stat306/2017/cumulants.pdf
https://link.springer.com/content/pdf/10.1007/s11004-009-9258-9.pdf
*/

#include "../src/moments_cumulants.tpp"








