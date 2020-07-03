/*
	Cannot do partial template specialization for function, see : https://en.wikipedia.org/wiki/Partial_template_specialization
	
	Can only do full specialization
	Therefore I'll be doing full specialisation using macros for compactness
*/

template <class BinType,class AbscisseType>
double moment(BinType* histogram, AbscisseType* bins , uint n_bins , uint exp , uint64_t n_total , int n_threads )
{
	omp_set_num_threads(n_threads);
    double val = 0;
	#pragma omp parallel
	{
		manage_thread_affinity();
		double val_local = 0 ;
		#pragma omp for
		for (uint i=0; i<n_bins; i++)
		{
			val_local += histogram[i] * pow(bins[i], exp);
		}
	#pragma omp atomic update
	val += val_local;
	}
    return val/n_total;
}

template <class BinType,class AbscisseType>
double moment(BinType* histogram , AbscisseType* bins , uint n_bins , uint exp_x , uint exp_y , uint64_t n_total , int n_threads )
{
	omp_set_num_threads(n_threads);
	double val = 0;
	#pragma omp parallel
	{
		manage_thread_affinity();
		double val_local = 0 ;
		double y_power = 0;
		#pragma omp for
		for (uint j=0; j<n_bins; j++)
		{
			y_power = pow(bins[j], exp_y);
			for (uint i=0; i<n_bins; i++)
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
double moment_no_clip(BinType* histogram, AbscisseType* bins , uint n_bins , uint exp , uint64_t n_total , int n_threads )
{
	omp_set_num_threads(n_threads);
    double val = 0;
	#pragma omp parallel
	{
		manage_thread_affinity();
		double val_local = 0 ;
		#pragma omp for
		for (uint i=1; i<n_bins-1; i++)
		{
			val_local += histogram[i] * pow(bins[i], exp);
		}
	#pragma omp atomic update
	val += val_local;
	}
    return val/n_total;
}

template <class BinType,class AbscisseType>
double moment_no_clip(BinType* histogram , AbscisseType* bins , uint n_bins , uint exp_x , uint exp_y , uint64_t n_total , int n_threads )
{
	omp_set_num_threads(n_threads);
	double val = 0;
	#pragma omp parallel
	{
		manage_thread_affinity();
		double val_local = 0 ;
		double y_power = 0;
		#pragma omp for
		for (uint j=1; j<n_bins-1; j++)
		{
			y_power = pow(bins[j], exp_y);
			for (uint i=1; i<n_bins-1; i++)
			{
				val_local += histogram[n_bins*j + i] * pow(bins[i], exp_x) * y_power;
			}
		}
	#pragma omp atomic update
	val += val_local;
	}
    return val/n_total;
}










