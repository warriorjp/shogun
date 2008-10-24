/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * Written (W) 1999-2008 Soeren Sonnenburg
 * Copyright (C) 1999-2008 Fraunhofer Institute FIRST and Max-Planck-Society
 */

#ifndef _LINEARBYTEKERNEL_H___
#define _LINEARBYTEKERNEL_H___

#include "lib/common.h"
#include "kernel/SimpleKernel.h"
#include "features/ByteFeatures.h"

/** Computes the standard linear kernel on dense byte valued features
 * \f[
 * k({\bf x},{\bf x'})= {\bf x}\cdot {\bf x'}
 * \f]
 */
class CLinearByteKernel: public CSimpleKernel<uint8_t>
{
	public:
		/** constructor
		 */
		CLinearByteKernel();

		/** constructor
		 *
		 * @param l features of left-hand side
		 * @param r features of right-hand side
		 */
		CLinearByteKernel(CByteFeatures* l, CByteFeatures *r);

		virtual ~CLinearByteKernel();

		/** initialize kernel
		 *
		 * @param l features of left-hand side
		 * @param r features of right-hand side
		 * @return if initializing was successful
		 */
		virtual bool init(CFeatures* l, CFeatures* r);

		/** clean up kernel */
		virtual void cleanup();

		/** load kernel init_data
		 *
		 * @param src file to load from
		 * @return if loading was successful
		 */
		virtual bool load_init(FILE* src);

		/** save kernel init_data
		 *
		 * @param dest file to save to
		 * @return if saving was successful
		 */
		virtual bool save_init(FILE* dest);

		/** return what type of kernel we are
		 *
		 * @return kernel type LINEAR
		 */
		virtual EKernelType get_kernel_type() { return K_LINEAR; }

		/** return the kernel's name
		 *
		 * @return name FixedDegree
		 */
		virtual const char* get_name() { return "Linear"; }

		/** optimizable kernel, i.e. precompute normal vector and as
		 * phi(x) = x do scalar product in input space
		 *
		 * @param num_suppvec number of support vectors
		 * @param sv_idx support vector index
		 * @param alphas alphas
		 * @return if optimization was successful
		 */
		virtual bool init_optimization(INT num_suppvec, INT* sv_idx, DREAL* alphas);

		/** delete optimization
		 *
		 * @return if deleting was successful
		 */
		virtual bool delete_optimization();

		/** compute optimized
	 	*
	 	* @param idx index to compute
	 	* @return optimized value at given index
	 	*/
		virtual DREAL compute_optimized(INT idx);

		/** clear normal vector */
		virtual void clear_normal();

		/** add to normal vector
		 *
		 * @param idx where to add
		 * @param weight what to add
		 */
		virtual void add_to_normal(INT idx, DREAL weight);

	protected:
		/** compute kernel function for features a and b
		 * idx_{a,b} denote the index of the feature vectors
		 * in the corresponding feature object
		 *
		 * @param idx_a index a
		 * @param idx_b index b
		 * @return computed kernel function at indices a,b
		 */
		virtual DREAL compute(INT idx_a, INT idx_b);

	protected:
		/** normal vector (used in case of optimized kernel) */
		double* normal;
};

#endif /* _LINEARBYTEKERNEL_H__ */
