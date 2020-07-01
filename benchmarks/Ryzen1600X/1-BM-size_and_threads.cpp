#include <moments_cumulants.h>
#include <benchmark/benchmark.h>

uint64_t* make_histogram2D( uint size)
{
	uint64_t* h = (uint64_t*) malloc(size*size*sizeof(uint64_t));
	for(uint i = 0 ; i < size*size ; i++)
	{
		h[i] = 1;
	}
	return h ;
}

uint64_t* make_histogram1D( uint size)
{
	uint64_t* h = (uint64_t*) malloc(size*sizeof(uint64_t));
	for(uint i = 0 ; i < size ; i++)
	{
		h[i] = 1;
	}
	return h ;
}

double* make_abcsisse( uint size )
{
	double* x = (double*) malloc(size*sizeof(double));
	for(uint i = 0 ; i < size ; i++)
	{
		x[i] = i;
	}
	return x ;
}

static void MOMENT_1D_OF_SIZE(benchmark::State& state)
{
	uint size = state.range(0) ;
	uint64_t* h = make_histogram1D(size) ;
	double* x = make_abcsisse( size );
	
	for (auto _ : state)
	{
		moment( h , x , size , 2 , size , 6 ) ;
	}
	state.SetComplexityN(state.range(0));
	free(h) ; free(x) ;
}
BENCHMARK(MOMENT_1D_OF_SIZE)->UseRealTime()->RangeMultiplier(2)->Range(2<<5, 2<<14)->Complexity(benchmark::oN) ;

static void MOMENT_2D_OF_SIZE(benchmark::State& state)
{
	uint size = state.range(0) ;
	uint64_t* h = make_histogram2D(size) ;
	double* x = make_abcsisse( size );
	
	for (auto _ : state)
	{
		moment( h , x , size , 2 , 2 , size , 6 ) ;
	}
	state.SetComplexityN(state.range(0));	
	free(h) ; free(x) ;
}
BENCHMARK(MOMENT_2D_OF_SIZE)->UseRealTime()->RangeMultiplier(2)->Range(2<<5, 2<<12)->Complexity(benchmark::oN) ;

static void MOMENT_1D_OF_NTHREADS(benchmark::State& state)
{
	uint size = 1<<16 ;
	uint64_t* h = make_histogram1D(size) ;
	double* x = make_abcsisse( size );
	
	for (auto _ : state)
	{
		moment( h , x , size , 2 , size , state.range(0) ) ;
	}
	state.SetComplexityN(state.range(0));
	free(h) ; free(x) ;
}
BENCHMARK(MOMENT_1D_OF_NTHREADS)->UseRealTime()->DenseRange(1, 12, 1)->Complexity(benchmark::oN);

static void MOMENT_2D_OF_NTHREADS(benchmark::State& state)
{
	uint size = 1024 ;
	uint64_t* h = make_histogram2D( size ) ;
	double* x = make_abcsisse( size );
	
	for (auto _ : state)
	{
		moment( h , x , size , 2 , 2 , size , state.range(0) ) ;
	}
	state.SetComplexityN(state.range(0));
	free(h) ; free(x) ;
}
BENCHMARK(MOMENT_2D_OF_NTHREADS)->UseRealTime()->DenseRange(1, 12, 1)->Complexity(benchmark::oN);

BENCHMARK_MAIN();
