/*BHEADER**********************************************************************
 * Copyright (c) 2008,  Lawrence Livermore National Security, LLC.
 * Produced at the Lawrence Livermore National Laboratory.
 * This file is part of HYPRE.  See file COPYRIGHT for details.
 *
 * HYPRE is free software; you can redistribute it and/or modify it under the
 * terms of the GNU Lesser General Public License (as published by the Free
 * Software Foundation) version 2.1 dated February 1999.
 *
 * $Revision: 2.7 $
 ***********************************************************************EHEADER*/




/******************************************************************************
 *
 * Header info for the Maxwell solver
 *
 *****************************************************************************/

#ifndef hypre_MAXWELL_HEADER
#define hypre_MAXWELL_HEADER

/*--------------------------------------------------------------------------
 * hypre_MaxwellData:
 *--------------------------------------------------------------------------*/

typedef struct
{
   MPI_Comm                comm;
                      
   double                  tol;
   HYPRE_Int               max_iter;
   HYPRE_Int               rel_change;
   HYPRE_Int               zero_guess;
   HYPRE_Int               ndim;
                      
   HYPRE_Int               num_pre_relax;  /* number of pre relaxation sweeps */
   HYPRE_Int               num_post_relax; /* number of post relaxation sweeps */

   HYPRE_Int               constant_coef;
   
   hypre_Index            *rfactor;

   hypre_SStructGrid     **egrid_l;
                    
   HYPRE_IJMatrix          Aen;
   hypre_ParCSRMatrix    **Aen_l;

   /* these will be extracted from the amg_data structure. Note that there is no grid
      underlying these matrices and vectors if they are generated by the amg_setup.
      So, will be stored as Parcsr_matrices and Par_vectors. */
   hypre_SStructMatrix    *Ann;
   hypre_SStructVector    *bn;
   hypre_SStructVector    *xn;

   void                   *amg_vdata;
   hypre_ParCSRMatrix    **Ann_l;
   hypre_SStructStencil  **Ann_stencils;
   hypre_ParCSRMatrix    **Pn_l;
   hypre_ParCSRMatrix    **RnT_l;
   hypre_ParVector       **bn_l;
   hypre_ParVector       **xn_l;
   hypre_ParVector       **resn_l;
   hypre_ParVector       **en_l;
   hypre_ParVector       **nVtemp_l;
   hypre_ParVector       **nVtemp2_l;
   HYPRE_Int             **nCF_marker_l;
   double                 *nrelax_weight;
   double                 *nomega;
   HYPRE_Int               nrelax_type;
   HYPRE_Int               node_numlevels;

   hypre_ParCSRMatrix     *Tgrad;
   hypre_ParCSRMatrix     *T_transpose;

   /* edge data structure. These will have grids. */
   HYPRE_Int               edge_maxlevels;  
   HYPRE_Int               edge_numlevels;  
   hypre_ParCSRMatrix    **Aee_l;
   hypre_ParVector       **be_l;
   hypre_ParVector       **xe_l;
   hypre_ParVector       **rese_l;
   hypre_ParVector       **ee_l;
   hypre_ParVector       **eVtemp_l;
   hypre_ParVector       **eVtemp2_l;
   HYPRE_Int             **eCF_marker_l;
   double                 *erelax_weight;
   double                 *eomega;
   HYPRE_Int               erelax_type;

   /* edge data structure. These will have no grid. */
   hypre_IJMatrix        **Pe_l;
   hypre_IJMatrix        **ReT_l;
   HYPRE_Int             **BdryRanks_l;
   HYPRE_Int              *BdryRanksCnts_l;

   /* edge-node data structure. These will have grids. */
   HYPRE_Int               en_numlevels;

   /* log info (always logged) */
   HYPRE_Int               num_iterations;
   HYPRE_Int               time_index;

   /* additional log info (logged when `logging' > 0) */
   HYPRE_Int               print_level;
   HYPRE_Int               logging;
   double                 *norms;
   double                 *rel_norms;

} hypre_MaxwellData;

#endif
