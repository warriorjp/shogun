/*
 * This software is distributed under BSD 3-clause license (see LICENSE file).
 *
 * Authors: Thoralf Klein, Soeren Sonnenburg, Bjoern Esser, Chiyuan Zhang
 */

#include "MKLMulticlassOptimizationBase.h"
#include <shogun/io/SGIO.h>

using namespace shogun;

MKLMulticlassOptimizationBase::MKLMulticlassOptimizationBase()
{

}
MKLMulticlassOptimizationBase::~MKLMulticlassOptimizationBase()
{

}



void MKLMulticlassOptimizationBase::setup(const int32_t numkernels2)
{
	error("class MKLMultiOptimizationBase, method not implemented in derivedclass");

}

void MKLMulticlassOptimizationBase::set_mkl_norm(float64_t norm)
{
	//deliberately no error here
	io::warn("class MKLMultiOptimizationBase, method set_mkl_norm() not implemented in derived class, has no effect");
}

void MKLMulticlassOptimizationBase::addconstraint(const ::std::vector<float64_t> & normw2,
		const float64_t sumofpositivealphas)
{
	error("class MKLMultiOptimizationBase, method not implemented in derivedclass");

}



void MKLMulticlassOptimizationBase::computeweights(std::vector<float64_t> & weights2)
{
	error("class MKLMultiOptimizationBase, method not implemented in derivedclass");
}
