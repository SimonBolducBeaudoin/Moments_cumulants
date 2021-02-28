/*
	Cannot do partial template specialization for function, see : https://en.wikipedia.org/wiki/Partial_template_specialization
	
	Can only do full specialization
	Therefore I'll be doing full specialisation using macros for compactness
*/

template <class BinType,class AbscisseType>
double moment(BinType* histogram, AbscisseType* bins , uint n_bins , uint exp , uint64_t n_total , int n_threads , bool no_clip )
{
	omp_set_num_threads(n_threads);
    double val = 0;
    uint first_bin  = no_clip ? 1         : 0       ;
    uint last_bin   = no_clip ? n_bins -1 : n_bins  ;
	#pragma omp parallel
	{
		manage_thread_affinity();
		double val_local = 0 ;
		#pragma omp for
		for (uint i=first_bin; i<last_bin; i++)
		{
			val_local += histogram[i] * pow(bins[i], exp);
		}
	#pragma omp atomic update
	val += val_local;
	}
    return val/n_total;
}

template <class BinType,class AbscisseType>
double centered_moment(BinType* histogram, AbscisseType* bins , uint n_bins , uint exp , uint64_t n_total , int n_threads , bool no_clip )
{
	omp_set_num_threads(n_threads);
    double val = 0;
    uint first_bin  = no_clip ? 1         : 0       ;
    uint last_bin   = no_clip ? n_bins -1 : n_bins  ;
    AbscisseType x_bar = moment(histogram,bins,n_bins,1,n_total,n_threads,no_clip) ;
	#pragma omp parallel
	{
		manage_thread_affinity();
		double val_local = 0 ;
		#pragma omp for
		for (uint i=first_bin; i<last_bin; i++)
		{
			val_local += histogram[i] * pow(bins[i]-x_bar, exp);
		}
	#pragma omp atomic update
	val += val_local;
	}
    return val/n_total;
}

template <class BinType,class AbscisseType>
double moment(BinType* histogram , AbscisseType* bins , uint n_bins , uint exp_x , uint exp_y , uint64_t n_total , int n_threads , bool no_clip )
{
	omp_set_num_threads(n_threads);
	double val = 0;
    uint first_bin  = no_clip ? 1         : 0       ;
    uint last_bin   = no_clip ? n_bins -1 : n_bins  ;
	#pragma omp parallel
	{
		manage_thread_affinity();
		double val_local = 0 ;
		double y_power = 0;
		#pragma omp for
		for (uint j=first_bin; j<last_bin; j++)
		{
			y_power = pow(bins[j], exp_y);
			for (uint i=first_bin; i<last_bin; i++)
			{
				val_local += histogram[n_bins*j + i] * pow(bins[i], exp_x) * y_power;
			}
		}
	#pragma omp atomic update
	val += val_local;
	}
    return val/n_total;
}

template <class BinType,class AbscisseType>
double centered_moment(BinType* histogram , AbscisseType* bins , uint n_bins , uint exp_x , uint exp_y , uint64_t n_total , int n_threads , bool no_clip )
{
	omp_set_num_threads(n_threads);
	double val = 0;
    uint first_bin  = no_clip ? 1         : 0       ;
    uint last_bin   = no_clip ? n_bins -1 : n_bins  ;
    AbscisseType x_bar = moment(histogram,bins,n_bins,1,0,n_total,n_threads,no_clip) ;
    AbscisseType y_bar = moment(histogram,bins,n_bins,0,1,n_total,n_threads,no_clip) ;
	#pragma omp parallel
	{
		manage_thread_affinity();
		double val_local = 0 ;
		double y_power = 0;
		#pragma omp for
		for (uint j=first_bin; j<last_bin; j++)
		{
			y_power = pow(bins[j]-y_bar, exp_y);
			for (uint i=first_bin; i<last_bin; i++)
			{
				val_local += histogram[n_bins*j + i] * pow(bins[i]- x_bar, exp_x) * y_power;
			}
		}
	#pragma omp atomic update
	val += val_local;
	}
    return val/n_total;
}










