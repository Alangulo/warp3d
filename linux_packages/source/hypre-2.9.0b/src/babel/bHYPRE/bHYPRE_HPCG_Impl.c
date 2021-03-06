/*
 * File:          bHYPRE_HPCG_Impl.c
 * Symbol:        bHYPRE.HPCG-v1.0.0
 * Symbol Type:   class
 * Babel Version: 1.0.4
 * Description:   Server-side implementation for bHYPRE.HPCG
 * 
 * WARNING: Automatically generated; only changes within splicers preserved
 * 
 */

/*
 * DEVELOPERS ARE EXPECTED TO PROVIDE IMPLEMENTATIONS
 * FOR THE FOLLOWING METHODS BETWEEN SPLICER PAIRS.
 */

/*
 * Symbol "bHYPRE.HPCG" (version 1.0.0)
 * 
 * Objects of this type can be cast to PreconditionedSolver objects
 * using the {\tt \_\_cast} methods.
 * 
 * The regular PCG solver calls Babel-interface matrix and vector functions.
 * The HPCG solver calls HYPRE interface functions.
 * The regular solver will work with any consistent matrix, vector, and
 * preconditioner classes.  The HPCG solver will work with the more common ones.
 * 
 * The HPCG solver checks whether the matrix, vectors, and preconditioner
 * are of known types, and will not work with any other types.
 * Presently, the recognized data types are:
 * matrix, vector: IJParCSRMatrix, IJParCSRVector
 * matrix, vector: StructMatrix, StructVector
 * preconditioner: BoomerAMG, ParaSails, ParCSRDiagScale, IdentitySolver
 * preconditioner: StructSMG, StructPFMG
 */

#include "bHYPRE_HPCG_Impl.h"
#include "sidl_NotImplementedException.h"
#include "sidl_Exception.h"

/* DO-NOT-DELETE splicer.begin(bHYPRE.HPCG._includes) */
/* Insert-Code-Here {bHYPRE.HPCG._includes} (includes and arbitrary code) */


#include "bHYPRE_IJParCSRMatrix.h"
#include "bHYPRE_IJParCSRMatrix_Impl.h"
#include "bHYPRE_IJParCSRVector.h"
#include "bHYPRE_IJParCSRVector_Impl.h"
#include "bHYPRE_StructMatrix.h"
#include "bHYPRE_StructMatrix_Impl.h"
#include "bHYPRE_StructVector.h"
#include "bHYPRE_StructVector_Impl.h"
#include "bHYPRE_SStructMatrix.h"
#include "bHYPRE_SStructMatrix_Impl.h"
#include "bHYPRE_SStructVector.h"
#include "bHYPRE_SStructVector_Impl.h"
#include "bHYPRE_BoomerAMG.h"
#include "bHYPRE_BoomerAMG_Impl.h"
#include "bHYPRE_ParaSails.h"
#include "bHYPRE_ParaSails_Impl.h"
#include "bHYPRE_ParCSRDiagScale.h"
#include "bHYPRE_ParCSRDiagScale_Impl.h"
#include "bHYPRE_StructSMG.h"
#include "bHYPRE_StructSMG_Impl.h"
#include "bHYPRE_StructPFMG.h"
#include "bHYPRE_StructPFMG_Impl.h"
#include "bHYPRE_StructDiagScale.h"
#include "bHYPRE_SStructDiagScale.h"
#include "bHYPRE_IdentitySolver_Impl.h"
#include "_hypre_struct_ls.h"
#include "_hypre_sstruct_ls.h"

#include "hypre_babel_exception_handler.h"

#include "bHYPRE_MPICommunicator.h"
/* compiler bug workaround, this are just copied from bHYPRE_MPICommunicator.h...*/
struct bHYPRE_MPICommunicator__data { MPI_Comm mpi_comm; };
extern struct bHYPRE_MPICommunicator__data*
bHYPRE_MPICommunicator__get_data(bHYPRE_MPICommunicator);
/* ... end of compiler bug workaround */

/* This function should be used to initialize the parameter cache
 * in the bHYPRE_HPCG__data object. */
int impl_bHYPRE_HPCG_Copy_Parameters_from_HYPRE_struct( bHYPRE_HPCG self )
{
   /* Parameters are copied only if they have nonsense values which tell
      us that the user has not set them. */
   int ierr = 0;
   HYPRE_Solver solver;
   struct bHYPRE_HPCG__data * data;

   data = bHYPRE_HPCG__get_data( self );
   hypre_assert( data->solver != NULL );
   solver = data->solver;

   /* double parameters: */
   if ( data->tol == -1.234 )
      ierr += HYPRE_PCGGetTol( solver, &(data->tol) );
   if ( data->atolf == -1.234 )
      ierr += HYPRE_PCGGetAbsoluteTolFactor( solver, &(data->atolf) );
   if ( data->cf_tol == -1.234 )
      ierr += HYPRE_PCGGetConvergenceFactorTol( solver, &(data->cf_tol) );

   /* int parameters: */
   if ( data->maxiter == -1234 )
      ierr += HYPRE_PCGGetMaxIter( solver, &(data->maxiter) );
   if ( data->relchange == -1234 )
      ierr += HYPRE_PCGGetRelChange( solver, &(data->relchange) );
   if ( data->twonorm == -1234 )
      ierr += HYPRE_PCGGetTwoNorm( solver, &(data->twonorm) );
   if ( data->stop_crit == -1234 )
      ierr += HYPRE_PCGGetStopCrit( solver, &(data->stop_crit) );
   if ( data->printlevel == -1234)
      ierr += HYPRE_PCGGetPrintLevel( solver, &(data->printlevel) );
   if ( data->log_level == -1234 )
      ierr += HYPRE_PCGGetLogging( solver, &(data->log_level) );

   return ierr;
}

int impl_bHYPRE_HPCG_Copy_Parameters_to_HYPRE_struct( bHYPRE_HPCG self )
/* Copy parameter cache from the bHYPRE_HPCG__data object into the
 * HYPRE_Solver object */
{
   /* Parameters are left at their HYPRE defaults if they have bHYPRE nonsense
      values which tell us that the user has not set them. */
   int ierr = 0;
   HYPRE_Solver solver;
   struct bHYPRE_HPCG__data * data;

   data = bHYPRE_HPCG__get_data( self );
   hypre_assert( data->solver != NULL );
   solver = data->solver;

   /* double parameters: */
   if ( data->tol != -1.234 )
      ierr += HYPRE_PCGSetTol( solver, data->tol );
   if ( data->atolf != -1.234 )
      ierr += HYPRE_PCGSetAbsoluteTolFactor( solver, data->atolf );
   if ( data->cf_tol != -1.234 )
      ierr += HYPRE_PCGSetConvergenceFactorTol( solver, data->cf_tol );

   /* int parameters: */
   if ( data->maxiter != -1234 )
      ierr += HYPRE_PCGSetMaxIter( solver, data->maxiter );
   if ( data->relchange != -1234 )
      ierr += HYPRE_PCGSetRelChange( solver, data->relchange );
   if ( data->twonorm != -1234 )
      ierr += HYPRE_PCGSetTwoNorm( solver, data->twonorm );
   if ( data->stop_crit != -1234 )
      ierr += HYPRE_PCGSetStopCrit( solver, data->stop_crit );
   if ( data->printlevel != -1234 )
      ierr += HYPRE_PCGSetPrintLevel( solver, data->printlevel );
   if ( data->log_level != -1234 )
      ierr += HYPRE_PCGSetLogging( solver, data->log_level );

   return ierr;
}
/* DO-NOT-DELETE splicer.end(bHYPRE.HPCG._includes) */

#define SIDL_IOR_MAJOR_VERSION 1
#define SIDL_IOR_MINOR_VERSION 0
/*
 * Static class initializer called exactly once before any user-defined method is dispatched
 */

#undef __FUNC__
#define __FUNC__ "impl_bHYPRE_HPCG__load"

#ifdef __cplusplus
extern "C"
#endif
void
impl_bHYPRE_HPCG__load(
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(bHYPRE.HPCG._load) */
  /* Insert-Code-Here {bHYPRE.HPCG._load} (static class initializer method) */
    /* DO-NOT-DELETE splicer.end(bHYPRE.HPCG._load) */
  }
}
/*
 * Class constructor called when the class is created.
 */

#undef __FUNC__
#define __FUNC__ "impl_bHYPRE_HPCG__ctor"

#ifdef __cplusplus
extern "C"
#endif
void
impl_bHYPRE_HPCG__ctor(
  /* in */ bHYPRE_HPCG self,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(bHYPRE.HPCG._ctor) */
  /* Insert-Code-Here {bHYPRE.HPCG._ctor} (constructor method) */

   /* Note: user calls of __create() are DEPRECATED, _Create also calls this function */

   struct bHYPRE_HPCG__data * data;
   data = hypre_CTAlloc( struct bHYPRE_HPCG__data, 1 );
   data -> comm = MPI_COMM_NULL;
   data -> solver = NULL;
   data -> matrix = NULL;
   data -> vector_type = NULL;
   /* We would like to call HYPRE_<vector type>PCGCreate at this
    * point, but it's impossible until we know the vector type.
    * That's needed because the C-language Krylov solvers need to be
    * told exactly what functions to call.  If we were to switch to a
    * Babel-based PCG solver, we would be able to use generic function
    * names; hence we could really initialize PCG here. */

   /* default values (copied from pcg.c; better to get them by
    * function calls)...*/
/*
   data -> tol = 1.0e-6;
   data -> atolf = 0.0;
   data -> cf_tol = 0.0;
   data -> maxiter = 1000;
   data -> relchange = 0;
   data -> twonorm = 0;
   data ->log_level = 0;
   data -> printlevel = 0;
   data -> stop_crit = 0;
*/
   /* initial nonsense values, later we should get good values
    * either by user calls or out of the HYPRE object...*/
   data -> tol        = -1.234;
   data -> atolf      = -1.234;
   data -> cf_tol     = -1.234;
   data -> maxiter    = -1234;
   data -> relchange  = -1234;
   data -> twonorm    = -1234;
   data ->log_level   = -1234;
   data -> printlevel = -1234;
   data -> stop_crit  = -1234;

   data -> bprecond = (bHYPRE_Solver)NULL;

   /* set any other data components here */
   bHYPRE_HPCG__set_data( self, data );

    /* DO-NOT-DELETE splicer.end(bHYPRE.HPCG._ctor) */
  }
}

/*
 * Special Class constructor called when the user wants to wrap his own private data.
 */

#undef __FUNC__
#define __FUNC__ "impl_bHYPRE_HPCG__ctor2"

#ifdef __cplusplus
extern "C"
#endif
void
impl_bHYPRE_HPCG__ctor2(
  /* in */ bHYPRE_HPCG self,
  /* in */ void* private_data,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(bHYPRE.HPCG._ctor2) */
    /* Insert-Code-Here {bHYPRE.HPCG._ctor2} (special constructor method) */
    /*
     * This method has not been implemented
     */

    SIDL_THROW(*_ex, sidl_NotImplementedException,     "This method has not been implemented");
  EXIT:;
    /* DO-NOT-DELETE splicer.end(bHYPRE.HPCG._ctor2) */
  }
}
/*
 * Class destructor called when the class is deleted.
 */

#undef __FUNC__
#define __FUNC__ "impl_bHYPRE_HPCG__dtor"

#ifdef __cplusplus
extern "C"
#endif
void
impl_bHYPRE_HPCG__dtor(
  /* in */ bHYPRE_HPCG self,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(bHYPRE.HPCG._dtor) */
  /* Insert-Code-Here {bHYPRE.HPCG._dtor} (destructor method) */

   int ierr = 0;
   struct bHYPRE_HPCG__data * data;
   data = bHYPRE_HPCG__get_data( self );

   if ( data->vector_type == "ParVector" )
   {
      ierr += HYPRE_ParCSRPCGDestroy( data->solver );
   }
   else if ( data->vector_type == "StructVector" )
   {
      ierr += HYPRE_StructPCGDestroy( (HYPRE_StructSolver) data->solver );
   }
   else if ( data->vector_type == "SStructVector" )
   {
      ierr += HYPRE_SStructPCGDestroy( (HYPRE_SStructSolver) data->solver );
   }
   /* To Do: support more vector types */
   else
   {
      /* Unsupported vector type.  We're unlikely to reach this point. */
      ierr++;
   }
   bHYPRE_Operator_deleteRef( data->matrix, _ex ); SIDL_CHECK(*_ex);
   /* delete any nontrivial data components here */
   hypre_TFree( data );

   return; hypre_babel_exception_no_return(_ex);
    /* DO-NOT-DELETE splicer.end(bHYPRE.HPCG._dtor) */
  }
}

/*
 *  This function is the preferred way to create a HPCG solver. 
 */

#undef __FUNC__
#define __FUNC__ "impl_bHYPRE_HPCG_Create"

#ifdef __cplusplus
extern "C"
#endif
bHYPRE_HPCG
impl_bHYPRE_HPCG_Create(
  /* in */ bHYPRE_MPICommunicator mpi_comm,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(bHYPRE.HPCG.Create) */
  /* Insert-Code-Here {bHYPRE.HPCG.Create} (Create method) */

   /* HYPRE_ParCSRPCGCreate or HYPRE_StructPCGCreate or ... cannot be
      called until later because we don't know the vector type yet */

   bHYPRE_HPCG solver = bHYPRE_HPCG__create(_ex); SIDL_CHECK(*_ex);
   struct bHYPRE_HPCG__data * data;

   data = bHYPRE_HPCG__get_data( solver );
   data->comm = bHYPRE_MPICommunicator__get_data(mpi_comm)->mpi_comm;

   return solver;

   hypre_babel_exception_no_return(_ex);
    /* DO-NOT-DELETE splicer.end(bHYPRE.HPCG.Create) */
  }
}

/*
 * Set the preconditioner.
 */

#undef __FUNC__
#define __FUNC__ "impl_bHYPRE_HPCG_SetPreconditioner"

#ifdef __cplusplus
extern "C"
#endif
int32_t
impl_bHYPRE_HPCG_SetPreconditioner(
  /* in */ bHYPRE_HPCG self,
  /* in */ bHYPRE_Solver s,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(bHYPRE.HPCG.SetPreconditioner) */
  /* Insert-Code-Here {bHYPRE.HPCG.SetPreconditioner} (SetPreconditioner method) */

   /* PCG_Setup will not be called until _after_ this function is called,
      but the new preconditioner's setup function should have been called
      _before_ this point. */

   int ierr = 0;
   char * precond_name;
   HYPRE_Solver * solverprecond;
   struct bHYPRE_HPCG__data * dataself;
   struct bHYPRE_BoomerAMG__data * AMG_dataprecond;
   bHYPRE_BoomerAMG AMG_s;
   struct bHYPRE_ParaSails__data * PS_dataprecond;
   bHYPRE_ParaSails PS_s;
   bHYPRE_ParCSRDiagScale PCDS_s;
   bHYPRE_StructDiagScale SDS_s;
   bHYPRE_SStructDiagScale SSDS_s;
   struct bHYPRE_StructSMG__data * SMG_dataprecond;
   bHYPRE_StructSMG SMG_s;
   struct bHYPRE_StructPFMG__data * PFMG_dataprecond;
   bHYPRE_StructPFMG PFMG_s;
   struct bHYPRE_IdentitySolver__data * Id_dataprecond;
   bHYPRE_IdentitySolver Id_s;
   HYPRE_PtrToSolverFcn precond, precond_setup; /* functions */

   dataself = bHYPRE_HPCG__get_data( self );
   dataself -> bprecond = s;

   AMG_s = (bHYPRE_BoomerAMG) bHYPRE_Solver__cast2( s, "bHYPRE.BoomerAMG", _ex ); SIDL_CHECK(*_ex);
   PS_s = (bHYPRE_ParaSails) bHYPRE_Solver__cast2( s, "bHYPRE.ParaSails", _ex ); SIDL_CHECK(*_ex);
   PCDS_s = (bHYPRE_ParCSRDiagScale) bHYPRE_Solver__cast2( s, "bHYPRE.ParCSRDiagScale", _ex );
   SIDL_CHECK(*_ex);
   SDS_s = (bHYPRE_StructDiagScale) bHYPRE_Solver__cast2( s, "bHYPRE.StructDiagScale", _ex );
   SIDL_CHECK(*_ex);
   SSDS_s = (bHYPRE_SStructDiagScale) bHYPRE_Solver__cast2( s, "bHYPRE.SStructDiagScale", _ex );
   SIDL_CHECK(*_ex);
   SMG_s = (bHYPRE_StructSMG) bHYPRE_Solver__cast2( s, "bHYPRE.StructSMG", _ex ); SIDL_CHECK(*_ex);
   PFMG_s = (bHYPRE_StructPFMG) bHYPRE_Solver__cast2( s, "bHYPRE.StructPFMG", _ex ); SIDL_CHECK(*_ex);
   Id_s = (bHYPRE_IdentitySolver) bHYPRE_Solver__cast2( s, "bHYPRE.IdentitySolver", _ex ); SIDL_CHECK(*_ex);
   if ( AMG_s != NULL )
   {
      precond_name = "BoomerAMG";
      AMG_dataprecond = bHYPRE_BoomerAMG__get_data( AMG_s );
      solverprecond = &AMG_dataprecond->solver;
      hypre_assert( solverprecond != NULL );
      precond = (HYPRE_PtrToSolverFcn) HYPRE_BoomerAMGSolve;
      precond_setup = (HYPRE_PtrToSolverFcn) HYPRE_BoomerAMGSetup;
      bHYPRE_BoomerAMG_deleteRef( AMG_s, _ex ); SIDL_CHECK(*_ex);
   }
   else if ( PS_s != NULL )
   {
      precond_name = "ParaSails";
      PS_dataprecond = bHYPRE_ParaSails__get_data( PS_s );
      solverprecond = &PS_dataprecond->solver;
      hypre_assert( solverprecond != NULL );
      precond = (HYPRE_PtrToSolverFcn) HYPRE_ParaSailsSolve;
      precond_setup = (HYPRE_PtrToSolverFcn) HYPRE_ParaSailsSetup;
      bHYPRE_ParaSails_deleteRef( PS_s, _ex ); SIDL_CHECK(*_ex);
   }
   else if ( PCDS_s != NULL )
   {
      precond_name = "ParCSRDiagScale";
      bHYPRE_Solver_deleteRef( s, _ex ); SIDL_CHECK(*_ex);
      solverprecond = (HYPRE_Solver *) hypre_CTAlloc( double, 1 );
      /* ... HYPRE diagonal scaling needs no solver object, but we
       * must provide a HYPRE_Solver object.  It will be totally
       * ignored. */
      precond = (HYPRE_PtrToSolverFcn) HYPRE_ParCSRDiagScale;
      precond_setup = (HYPRE_PtrToSolverFcn) HYPRE_ParCSRDiagScaleSetup;
   }
   else if ( SDS_s != NULL )
   {
      precond_name = "StructDiagScale";
      bHYPRE_Solver_deleteRef( s, _ex ); SIDL_CHECK(*_ex);
      solverprecond = (HYPRE_Solver *) hypre_CTAlloc( double, 1 );
      /* ... HYPRE diagonal scaling needs no solver object, but we
       * must provide a HYPRE_Solver object.  It will be totally
       * ignored. */
      precond = (HYPRE_PtrToSolverFcn) HYPRE_StructDiagScale;
      precond_setup = (HYPRE_PtrToSolverFcn) HYPRE_StructDiagScaleSetup;
   }
   else if ( SSDS_s != NULL )
   {
      precond_name = "SStructDiagScale";
      bHYPRE_Solver_deleteRef( s, _ex ); SIDL_CHECK(*_ex);
      solverprecond = (HYPRE_Solver *) hypre_CTAlloc( double, 1 );
      /* ... HYPRE diagonal scaling needs no solver object, but we
       * must provide a HYPRE_Solver object.  It will be totally
       * ignored. */
      precond = (HYPRE_PtrToSolverFcn) HYPRE_SStructDiagScale;
      precond_setup = (HYPRE_PtrToSolverFcn) HYPRE_SStructDiagScaleSetup;
   }
   else if ( SMG_s != NULL )
   {
      precond_name = "StructSMG";
      SMG_dataprecond = bHYPRE_StructSMG__get_data( SMG_s );
      solverprecond = (HYPRE_Solver *) &SMG_dataprecond->solver;
      hypre_assert( solverprecond != NULL );
      precond = (HYPRE_PtrToSolverFcn) HYPRE_StructSMGSolve;
      precond_setup = (HYPRE_PtrToSolverFcn) HYPRE_StructSMGSetup;
      bHYPRE_StructSMG_deleteRef( SMG_s, _ex ); SIDL_CHECK(*_ex);
   }
   else if ( PFMG_s != NULL )
   {
      precond_name = "StructPFMG";
      PFMG_dataprecond = bHYPRE_StructPFMG__get_data( PFMG_s );
      solverprecond = (HYPRE_Solver *) &PFMG_dataprecond->solver;
      hypre_assert( solverprecond != NULL );
      precond = (HYPRE_PtrToSolverFcn) HYPRE_StructPFMGSolve;
      precond_setup = (HYPRE_PtrToSolverFcn) HYPRE_StructPFMGSetup;
      bHYPRE_StructPFMG_deleteRef( PFMG_s, _ex ); SIDL_CHECK(*_ex);
   }
   else if ( Id_s != NULL )
   {
      /* s is an IdentitySolver, a dummy which just "solves" the identity matrix */
      precond_name = "IdentitySolver";
      bHYPRE_Solver_deleteRef( s, _ex ); SIDL_CHECK(*_ex);
      solverprecond = (HYPRE_Solver *) hypre_CTAlloc( double, 1 );
      /* ... almost any garbage will do here, but we need something */
      Id_dataprecond = bHYPRE_IdentitySolver__get_data( Id_s );

      /* The right thing at this point is to check for vector type, then specify
         the right hypre identity solver (_really_ the right thing is to use the
         babel-level identity solver, but that requires PCG to be implemented at the
         babel level). */

      if ( strcmp(Id_dataprecond->vector_type,"ParVector")==0 )
      {
         precond = (HYPRE_PtrToSolverFcn) hypre_ParKrylovIdentity;
         precond_setup = (HYPRE_PtrToSolverFcn) hypre_ParKrylovIdentitySetup;
      }
      else if ( strcmp(Id_dataprecond->vector_type,"StructVector")==0 )
      {
         precond = (HYPRE_PtrToSolverFcn) hypre_StructKrylovIdentity;
         precond_setup = (HYPRE_PtrToSolverFcn) hypre_StructKrylovIdentitySetup;
      }
      else if ( strcmp(Id_dataprecond->vector_type,"SStructVector")==0 )
      {
         precond = (HYPRE_PtrToSolverFcn) hypre_SStructKrylovIdentity;
         precond_setup = (HYPRE_PtrToSolverFcn) hypre_SStructKrylovIdentitySetup;
      }
      else
      {
         hypre_assert( "unrecognized vector type, can't set up PCG as CG\n"==0 );
      }
   }
   /* put other preconditioner types here */
   else
   {
      hypre_assert( "PCG_SetPreconditioner cannot recognize preconditioner"==0 );
   }

   /* We can't actually set the HYPRE preconditioner, because that
    * requires knowing what the solver object is - but that requires
    * knowing its data type but _that_ requires knowing the kind of
    * matrix and vectors we'll need; not known until Apply is called.
    * So save the information in the bHYPRE data structure, and stick
    * it in HYPRE later... */
   dataself->precond_name = precond_name;
   dataself->precond = precond;
   dataself->precond_setup = precond_setup;
   dataself->solverprecond = solverprecond;
   /* For an example call, see test/IJ_linear_solvers.c, line 1686.
    * The four arguments are: self's (solver) data; and, for the
    * preconditioner: solver function, setup function, data */

   return ierr;

   hypre_babel_exception_return_error(_ex);
    /* DO-NOT-DELETE splicer.end(bHYPRE.HPCG.SetPreconditioner) */
  }
}

/*
 * Method:  GetPreconditioner[]
 */

#undef __FUNC__
#define __FUNC__ "impl_bHYPRE_HPCG_GetPreconditioner"

#ifdef __cplusplus
extern "C"
#endif
int32_t
impl_bHYPRE_HPCG_GetPreconditioner(
  /* in */ bHYPRE_HPCG self,
  /* out */ bHYPRE_Solver* s,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(bHYPRE.HPCG.GetPreconditioner) */
  /* Insert-Code-Here {bHYPRE.HPCG.GetPreconditioner} (GetPreconditioner method) */

   int ierr = 0;
   struct bHYPRE_HPCG__data * dataself = bHYPRE_HPCG__get_data( self );
   *s = dataself -> bprecond ;

   return ierr;

    /* DO-NOT-DELETE splicer.end(bHYPRE.HPCG.GetPreconditioner) */
  }
}

/*
 * Method:  Clone[]
 */

#undef __FUNC__
#define __FUNC__ "impl_bHYPRE_HPCG_Clone"

#ifdef __cplusplus
extern "C"
#endif
int32_t
impl_bHYPRE_HPCG_Clone(
  /* in */ bHYPRE_HPCG self,
  /* out */ bHYPRE_PreconditionedSolver* x,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(bHYPRE.HPCG.Clone) */
  /* Insert-Code-Here {bHYPRE.HPCG.Clone} (Clone method) */
   return 1;
    /* DO-NOT-DELETE splicer.end(bHYPRE.HPCG.Clone) */
  }
}

/*
 * Set the operator for the linear system being solved.
 * DEPRECATED.  use Create
 */

#undef __FUNC__
#define __FUNC__ "impl_bHYPRE_HPCG_SetOperator"

#ifdef __cplusplus
extern "C"
#endif
int32_t
impl_bHYPRE_HPCG_SetOperator(
  /* in */ bHYPRE_HPCG self,
  /* in */ bHYPRE_Operator A,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(bHYPRE.HPCG.SetOperator) */
  /* Insert-Code-Here {bHYPRE.HPCG.SetOperator} (SetOperator method) */

   int ierr = 0;
   struct bHYPRE_HPCG__data * data;

   data = bHYPRE_HPCG__get_data( self );
   data->matrix = A;
   bHYPRE_Operator_addRef( data->matrix, _ex ); SIDL_CHECK(*_ex);

   return ierr;

   hypre_babel_exception_return_error(_ex);
    /* DO-NOT-DELETE splicer.end(bHYPRE.HPCG.SetOperator) */
  }
}

/*
 * (Optional) Set the convergence tolerance.
 * DEPRECATED.  use SetDoubleParameter
 */

#undef __FUNC__
#define __FUNC__ "impl_bHYPRE_HPCG_SetTolerance"

#ifdef __cplusplus
extern "C"
#endif
int32_t
impl_bHYPRE_HPCG_SetTolerance(
  /* in */ bHYPRE_HPCG self,
  /* in */ double tolerance,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(bHYPRE.HPCG.SetTolerance) */
  /* Insert-Code-Here {bHYPRE.HPCG.SetTolerance} (SetTolerance method) */

   int ierr = 0;
   struct bHYPRE_HPCG__data * data;
   data = bHYPRE_HPCG__get_data( self );

   data -> tol = tolerance;

   return ierr;

    /* DO-NOT-DELETE splicer.end(bHYPRE.HPCG.SetTolerance) */
  }
}

/*
 * (Optional) Set maximum number of iterations.
 * DEPRECATED   use SetIntParameter
 */

#undef __FUNC__
#define __FUNC__ "impl_bHYPRE_HPCG_SetMaxIterations"

#ifdef __cplusplus
extern "C"
#endif
int32_t
impl_bHYPRE_HPCG_SetMaxIterations(
  /* in */ bHYPRE_HPCG self,
  /* in */ int32_t max_iterations,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(bHYPRE.HPCG.SetMaxIterations) */
  /* Insert-Code-Here {bHYPRE.HPCG.SetMaxIterations} (SetMaxIterations method) */

   int ierr = 0;
   struct bHYPRE_HPCG__data * data;
   data = bHYPRE_HPCG__get_data( self );

   data -> maxiter = max_iterations;

   return ierr;

    /* DO-NOT-DELETE splicer.end(bHYPRE.HPCG.SetMaxIterations) */
  }
}

/*
 * (Optional) Set the {\it logging level}, specifying the degree
 * of additional informational data to be accumulated.  Does
 * nothing by default (level = 0).  Other levels (if any) are
 * implementation-specific.  Must be called before {\tt Setup}
 * and {\tt Apply}.
 * DEPRECATED   use SetIntParameter
 */

#undef __FUNC__
#define __FUNC__ "impl_bHYPRE_HPCG_SetLogging"

#ifdef __cplusplus
extern "C"
#endif
int32_t
impl_bHYPRE_HPCG_SetLogging(
  /* in */ bHYPRE_HPCG self,
  /* in */ int32_t level,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(bHYPRE.HPCG.SetLogging) */
  /* Insert-Code-Here {bHYPRE.HPCG.SetLogging} (SetLogging method) */

   /* The normal way to implement this function would be to call the
    * corresponding HYPRE function to set the print level.  That can't
    * always be done because the HYPRE struct may not exist.  The
    * HYPRE struct may not exist because it can't be created until we
    * know the vector type - and that is not known until Apply is
    * first called.  So what we do is save the print level in a cache
    * belonging to this Babel interface, and copy it into the HYPRE
    * struct once Apply is called.  */
   int ierr = 0;
   struct bHYPRE_HPCG__data * data;
   data = bHYPRE_HPCG__get_data( self );

   data -> log_level = level;

   return ierr;

    /* DO-NOT-DELETE splicer.end(bHYPRE.HPCG.SetLogging) */
  }
}

/*
 * (Optional) Set the {\it print level}, specifying the degree
 * of informational data to be printed either to the screen or
 * to a file.  Does nothing by default (level=0).  Other levels
 * (if any) are implementation-specific.  Must be called before
 * {\tt Setup} and {\tt Apply}.
 * DEPRECATED   use SetIntParameter
 */

#undef __FUNC__
#define __FUNC__ "impl_bHYPRE_HPCG_SetPrintLevel"

#ifdef __cplusplus
extern "C"
#endif
int32_t
impl_bHYPRE_HPCG_SetPrintLevel(
  /* in */ bHYPRE_HPCG self,
  /* in */ int32_t level,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(bHYPRE.HPCG.SetPrintLevel) */
  /* Insert-Code-Here {bHYPRE.HPCG.SetPrintLevel} (SetPrintLevel method) */

   /* The normal way to implement this function would be to call the
    * corresponding HYPRE function to set the print level.  That can't
    * always be done because the HYPRE struct may not exist.  The
    * HYPRE struct may not exist because it can't be created until we
    * know the vector type - and that is not known until Apply is
    * first called.  So what we do is save the print level in a cache
    * belonging to this Babel interface, and copy it into the HYPRE
    * struct once Apply is called.  */
   int ierr = 0;
   struct bHYPRE_HPCG__data * data;
   data = bHYPRE_HPCG__get_data( self );

   data -> printlevel = level;

   return ierr;

    /* DO-NOT-DELETE splicer.end(bHYPRE.HPCG.SetPrintLevel) */
  }
}

/*
 * (Optional) Return the number of iterations taken.
 */

#undef __FUNC__
#define __FUNC__ "impl_bHYPRE_HPCG_GetNumIterations"

#ifdef __cplusplus
extern "C"
#endif
int32_t
impl_bHYPRE_HPCG_GetNumIterations(
  /* in */ bHYPRE_HPCG self,
  /* out */ int32_t* num_iterations,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(bHYPRE.HPCG.GetNumIterations) */
  /* Insert-Code-Here {bHYPRE.HPCG.GetNumIterations} (GetNumIterations method) */

   int ierr = 0;
   HYPRE_Solver solver;
   struct bHYPRE_HPCG__data * data;

   data = bHYPRE_HPCG__get_data( self );
   hypre_assert( data->solver != NULL );
   solver = data->solver;

   ierr += HYPRE_PCGGetNumIterations( solver, num_iterations );

   return ierr;

    /* DO-NOT-DELETE splicer.end(bHYPRE.HPCG.GetNumIterations) */
  }
}

/*
 * (Optional) Return the norm of the relative residual.
 */

#undef __FUNC__
#define __FUNC__ "impl_bHYPRE_HPCG_GetRelResidualNorm"

#ifdef __cplusplus
extern "C"
#endif
int32_t
impl_bHYPRE_HPCG_GetRelResidualNorm(
  /* in */ bHYPRE_HPCG self,
  /* out */ double* norm,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(bHYPRE.HPCG.GetRelResidualNorm) */
  /* Insert-Code-Here {bHYPRE.HPCG.GetRelResidualNorm} (GetRelResidualNorm method) */

   int ierr = 0;
   HYPRE_Solver solver;
   struct bHYPRE_HPCG__data * data;

   data = bHYPRE_HPCG__get_data( self );
   hypre_assert( data->solver != NULL );
   solver = data->solver;

   ierr += HYPRE_PCGGetFinalRelativeResidualNorm( solver, norm );

   return ierr;

    /* DO-NOT-DELETE splicer.end(bHYPRE.HPCG.GetRelResidualNorm) */
  }
}

/*
 * Set the MPI Communicator.
 * DEPRECATED, use Create:
 */

#undef __FUNC__
#define __FUNC__ "impl_bHYPRE_HPCG_SetCommunicator"

#ifdef __cplusplus
extern "C"
#endif
int32_t
impl_bHYPRE_HPCG_SetCommunicator(
  /* in */ bHYPRE_HPCG self,
  /* in */ bHYPRE_MPICommunicator mpi_comm,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(bHYPRE.HPCG.SetCommunicator) */
  /* Insert-Code-Here {bHYPRE.HPCG.SetCommunicator} (SetCommunicator method) */

   /* DEPRECATED  Use Create */

   int ierr = 0;
   struct bHYPRE_HPCG__data * data;
   data = bHYPRE_HPCG__get_data( self );
   data->comm = bHYPRE_MPICommunicator__get_data(mpi_comm)->mpi_comm;

   return ierr;
    /* DO-NOT-DELETE splicer.end(bHYPRE.HPCG.SetCommunicator) */
  }
}

/*
 * The Destroy function doesn't necessarily destroy anything.
 * It is just another name for deleteRef.  Thus it decrements the
 * object's reference count.  The Babel memory management system will
 * destroy the object if the reference count goes to zero.
 */

#undef __FUNC__
#define __FUNC__ "impl_bHYPRE_HPCG_Destroy"

#ifdef __cplusplus
extern "C"
#endif
void
impl_bHYPRE_HPCG_Destroy(
  /* in */ bHYPRE_HPCG self,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(bHYPRE.HPCG.Destroy) */
    /* Insert-Code-Here {bHYPRE.HPCG.Destroy} (Destroy method) */
     bHYPRE_HPCG_deleteRef(self,_ex);
     return;
    /* DO-NOT-DELETE splicer.end(bHYPRE.HPCG.Destroy) */
  }
}

/*
 * Set the int parameter associated with {\tt name}.
 */

#undef __FUNC__
#define __FUNC__ "impl_bHYPRE_HPCG_SetIntParameter"

#ifdef __cplusplus
extern "C"
#endif
int32_t
impl_bHYPRE_HPCG_SetIntParameter(
  /* in */ bHYPRE_HPCG self,
  /* in */ const char* name,
  /* in */ int32_t value,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(bHYPRE.HPCG.SetIntParameter) */
  /* Insert-Code-Here {bHYPRE.HPCG.SetIntParameter} (SetIntParameter method) */

   /* The normal way to implement this function would be to call the
    * corresponding HYPRE function to set the parameter.  That can't
    * always be done because the HYPRE struct may not exist.  The
    * HYPRE struct may not exist because it can't be created until we
    * know the vector type - and that is not known until Apply is
    * first called.  So what we do is save the parameter in a cache
    * belonging to this Babel interface, and copy it into the HYPRE
    * struct once Apply is called. (The copy into the HYPRE struct is
    * also done in Setup) */
   int ierr = 0;
   struct bHYPRE_HPCG__data * data;
   data = bHYPRE_HPCG__get_data( self );

   if ( strcmp(name,"TwoNorm")==0 || strcmp(name,"2-norm")==0 )
   {
      data -> twonorm = value;
   }
   else if ( strcmp(name,"MaxIter")==0 || strcmp(name,"MaxIterations")==0 )
   {
      data -> maxiter = value;
   }
   else if ( strcmp(name,"RelChange")==0 || strcmp(name,"relative change test")==0 )
   {
      data -> relchange = value;
   }
   else if ( strcmp(name,"Logging")==0 )
   {
      data -> log_level = value;
   }
   else if ( strcmp(name,"PrintLevel")==0 )
   {
      data -> printlevel = value;
   }
   else
   {
      ierr=1;
   }

   return ierr;
    /* DO-NOT-DELETE splicer.end(bHYPRE.HPCG.SetIntParameter) */
  }
}

/*
 * Set the double parameter associated with {\tt name}.
 */

#undef __FUNC__
#define __FUNC__ "impl_bHYPRE_HPCG_SetDoubleParameter"

#ifdef __cplusplus
extern "C"
#endif
int32_t
impl_bHYPRE_HPCG_SetDoubleParameter(
  /* in */ bHYPRE_HPCG self,
  /* in */ const char* name,
  /* in */ double value,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(bHYPRE.HPCG.SetDoubleParameter) */
  /* Insert-Code-Here {bHYPRE.HPCG.SetDoubleParameter} (SetDoubleParameter method) */

   /* The normal way to implement this function would be to call the
    * corresponding HYPRE function to set the parameter.  That can't
    * always be done because the HYPRE struct may not exist.  The
    * HYPRE struct may not exist because it can't be created until we
    * know the vector type - and that is not known until Apply is
    * first called.  So what we do is save the parameter in a cache
    * belonging to this Babel interface, and copy it into the HYPRE
    * struct once Apply is called.  */
   int ierr = 0;
   struct bHYPRE_HPCG__data * data;
   data = bHYPRE_HPCG__get_data( self );

   if ( strcmp(name,"AbsoluteTolFactor")==0 )
   {
      data -> atolf = value;
   }
   else if ( strcmp(name,"ConvergenceFactorTol")==0 )
   {
      /* tolerance for special test for slow convergence */
      data -> cf_tol = value;
   }
   else if ( strcmp(name,"Tolerance")==0  || strcmp(name,"Tol")==0 )
   {
      data -> tol = value;
   }
   else
   {
      ierr=1;
   }

   return ierr;

    /* DO-NOT-DELETE splicer.end(bHYPRE.HPCG.SetDoubleParameter) */
  }
}

/*
 * Set the string parameter associated with {\tt name}.
 */

#undef __FUNC__
#define __FUNC__ "impl_bHYPRE_HPCG_SetStringParameter"

#ifdef __cplusplus
extern "C"
#endif
int32_t
impl_bHYPRE_HPCG_SetStringParameter(
  /* in */ bHYPRE_HPCG self,
  /* in */ const char* name,
  /* in */ const char* value,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(bHYPRE.HPCG.SetStringParameter) */
  /* Insert-Code-Here {bHYPRE.HPCG.SetStringParameter} (SetStringParameter method) */

   return 1;

    /* DO-NOT-DELETE splicer.end(bHYPRE.HPCG.SetStringParameter) */
  }
}

/*
 * Set the int 1-D array parameter associated with {\tt name}.
 */

#undef __FUNC__
#define __FUNC__ "impl_bHYPRE_HPCG_SetIntArray1Parameter"

#ifdef __cplusplus
extern "C"
#endif
int32_t
impl_bHYPRE_HPCG_SetIntArray1Parameter(
  /* in */ bHYPRE_HPCG self,
  /* in */ const char* name,
  /* in rarray[nvalues] */ int32_t* value,
  /* in */ int32_t nvalues,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(bHYPRE.HPCG.SetIntArray1Parameter) */
  /* Insert-Code-Here {bHYPRE.HPCG.SetIntArray1Parameter} (SetIntArray1Parameter method) */

   return 1;

    /* DO-NOT-DELETE splicer.end(bHYPRE.HPCG.SetIntArray1Parameter) */
  }
}

/*
 * Set the int 2-D array parameter associated with {\tt name}.
 */

#undef __FUNC__
#define __FUNC__ "impl_bHYPRE_HPCG_SetIntArray2Parameter"

#ifdef __cplusplus
extern "C"
#endif
int32_t
impl_bHYPRE_HPCG_SetIntArray2Parameter(
  /* in */ bHYPRE_HPCG self,
  /* in */ const char* name,
  /* in array<int,2,column-major> */ struct sidl_int__array* value,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(bHYPRE.HPCG.SetIntArray2Parameter) */
  /* Insert-Code-Here {bHYPRE.HPCG.SetIntArray2Parameter} (SetIntArray2Parameter method) */

   return 1;

    /* DO-NOT-DELETE splicer.end(bHYPRE.HPCG.SetIntArray2Parameter) */
  }
}

/*
 * Set the double 1-D array parameter associated with {\tt name}.
 */

#undef __FUNC__
#define __FUNC__ "impl_bHYPRE_HPCG_SetDoubleArray1Parameter"

#ifdef __cplusplus
extern "C"
#endif
int32_t
impl_bHYPRE_HPCG_SetDoubleArray1Parameter(
  /* in */ bHYPRE_HPCG self,
  /* in */ const char* name,
  /* in rarray[nvalues] */ double* value,
  /* in */ int32_t nvalues,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(bHYPRE.HPCG.SetDoubleArray1Parameter) */
  /* Insert-Code-Here {bHYPRE.HPCG.SetDoubleArray1Parameter} (SetDoubleArray1Parameter method) */

   return 1;

    /* DO-NOT-DELETE splicer.end(bHYPRE.HPCG.SetDoubleArray1Parameter) */
  }
}

/*
 * Set the double 2-D array parameter associated with {\tt name}.
 */

#undef __FUNC__
#define __FUNC__ "impl_bHYPRE_HPCG_SetDoubleArray2Parameter"

#ifdef __cplusplus
extern "C"
#endif
int32_t
impl_bHYPRE_HPCG_SetDoubleArray2Parameter(
  /* in */ bHYPRE_HPCG self,
  /* in */ const char* name,
  /* in array<double,2,column-major> */ struct sidl_double__array* value,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(bHYPRE.HPCG.SetDoubleArray2Parameter) */
  /* Insert-Code-Here {bHYPRE.HPCG.SetDoubleArray2Parameter} (SetDoubleArray2Parameter method) */

   return 1;

    /* DO-NOT-DELETE splicer.end(bHYPRE.HPCG.SetDoubleArray2Parameter) */
  }
}

/*
 * Set the int parameter associated with {\tt name}.
 */

#undef __FUNC__
#define __FUNC__ "impl_bHYPRE_HPCG_GetIntValue"

#ifdef __cplusplus
extern "C"
#endif
int32_t
impl_bHYPRE_HPCG_GetIntValue(
  /* in */ bHYPRE_HPCG self,
  /* in */ const char* name,
  /* out */ int32_t* value,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(bHYPRE.HPCG.GetIntValue) */
  /* Insert-Code-Here {bHYPRE.HPCG.GetIntValue} (GetIntValue method) */

   /* A return value of -1234 means that the parameter has not been
      set yet.  In that case an error flag will be returned too. */
   int ierr = 0;
   HYPRE_Solver solver;
   struct bHYPRE_HPCG__data * data;

   data = bHYPRE_HPCG__get_data( self );
   hypre_assert( data->solver != NULL );
   solver = data->solver;

   /* The underlying HYPRE PCG object has actually been created if & only if
      data->vector_type is non-null.  If so, make sure our local parameter cache
      if up-to-date.  */
   if ( data -> vector_type != NULL )
      ierr += impl_bHYPRE_HPCG_Copy_Parameters_from_HYPRE_struct( self );

   if ( strcmp(name,"NumIterations")==0 )
   {
      ierr += HYPRE_PCGGetNumIterations( solver, value );
   }
   if ( strcmp(name,"Converged")==0 )
   {
      ierr += HYPRE_PCGGetConverged( solver, value );
   }
   else if ( strcmp(name,"TwoNorm")==0 || strcmp(name,"2-norm")==0 )
   {
      *value = data -> twonorm;
   }
   else if ( strcmp(name,"MaxIter")==0 || strcmp(name,"MaxIterations")==0 )
   {
      *value = data -> maxiter;
   }
   else if ( strcmp(name,"RelChange")==0 || strcmp(name,"relative change test")==0 )
   {
      *value = data -> relchange;
   }
   else if ( strcmp(name,"Logging")==0 )
   {
      *value = data -> log_level;
   }
   else if ( strcmp(name,"PrintLevel")==0 )
   {
      *value = data -> printlevel;
   }
   else
   {
      ierr=1;
   }

   if ( *value == -1234 ) ++ierr;
   return ierr;

    /* DO-NOT-DELETE splicer.end(bHYPRE.HPCG.GetIntValue) */
  }
}

/*
 * Get the double parameter associated with {\tt name}.
 */

#undef __FUNC__
#define __FUNC__ "impl_bHYPRE_HPCG_GetDoubleValue"

#ifdef __cplusplus
extern "C"
#endif
int32_t
impl_bHYPRE_HPCG_GetDoubleValue(
  /* in */ bHYPRE_HPCG self,
  /* in */ const char* name,
  /* out */ double* value,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(bHYPRE.HPCG.GetDoubleValue) */
  /* Insert-Code-Here {bHYPRE.HPCG.GetDoubleValue} (GetDoubleValue method) */

   /* A return value of -1234 means that the parameter has not been
      set yet.  In that case an error flag will be returned too. */
   int ierr = 0;
   HYPRE_Solver solver;
   struct bHYPRE_HPCG__data * data;

   data = bHYPRE_HPCG__get_data( self );
   hypre_assert( data->solver != NULL );
   solver = data->solver;

   /* The underlying HYPRE PCG object has actually been created if & only if
      data->vector_type is non-null.  If so, make sure our local parameter cache
      if up-to-date.  */
   if ( data -> vector_type != NULL )
      ierr += impl_bHYPRE_HPCG_Copy_Parameters_from_HYPRE_struct( self );

   if ( strcmp(name,"Final Relative Residual Norm")==0 ||
        strcmp(name,"FinalRelativeResidualNorm")==0 ||
        strcmp(name,"RelResidualNorm")==0 ||
        strcmp(name,"RelativeResidualNorm")==0 )
   {
      ierr += HYPRE_PCGGetFinalRelativeResidualNorm( solver, value );
   }
   else if ( strcmp(name,"AbsoluteTolFactor")==0 )
   {
      *value = data -> atolf;
   }
   else if ( strcmp(name,"ConvergenceFactorTol")==0 )
   {
      /* tolerance for special test for slow convergence */
      *value = data -> cf_tol;
   }
   else if ( strcmp(name,"Tolerance")==0  || strcmp(name,"Tol")==0 )
   {
      *value = data -> tol;
   }
   else
   {
      ierr = 1;
   }

   if ( *value == -1.234 ) ++ierr;
   return ierr;

    /* DO-NOT-DELETE splicer.end(bHYPRE.HPCG.GetDoubleValue) */
  }
}

/*
 * (Optional) Do any preprocessing that may be necessary in
 * order to execute {\tt Apply}.
 */

#undef __FUNC__
#define __FUNC__ "impl_bHYPRE_HPCG_Setup"

#ifdef __cplusplus
extern "C"
#endif
int32_t
impl_bHYPRE_HPCG_Setup(
  /* in */ bHYPRE_HPCG self,
  /* in */ bHYPRE_Vector b,
  /* in */ bHYPRE_Vector x,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(bHYPRE.HPCG.Setup) */
  /* Insert-Code-Here {bHYPRE.HPCG.Setup} (Setup method) */

   int ierr=0;
   MPI_Comm comm;
   HYPRE_Solver solver;
   HYPRE_Solver * psolver = &solver; /* will get a real value later */
   struct bHYPRE_HPCG__data * data;
   bHYPRE_Operator mat;
   HYPRE_Matrix HYPRE_A;
   bHYPRE_IJParCSRMatrix bHYPREP_A;
   bHYPRE_StructMatrix bHYPRES_A;
   bHYPRE_SStructMatrix bHYPRESS_A;
   HYPRE_ParCSRMatrix AA;
   HYPRE_IJMatrix ij_A;
   HYPRE_StructMatrix HS_A;
   HYPRE_SStructMatrix HSS_A;
   HYPRE_Vector HYPRE_x, HYPRE_b;
   bHYPRE_IJParCSRVector bHYPREP_b, bHYPREP_x;
   bHYPRE_StructVector bHYPRES_b, bHYPRES_x;
   bHYPRE_SStructVector bHYPRESS_b, bHYPRESS_x;
   HYPRE_ParVector bb, xx;
   HYPRE_IJVector ij_b, ij_x;
   HYPRE_StructVector HS_b, HS_x;
   HYPRE_SStructVector HSS_b, HSS_x;
   struct bHYPRE_IJParCSRMatrix__data * dataA;
   struct bHYPRE_StructMatrix__data * dataA_S;
   struct bHYPRE_SStructMatrix__data * dataA_SS;
   struct bHYPRE_IJParCSRVector__data * datab, * datax;
   struct bHYPRE_StructVector__data * datab_S, * datax_S;
   struct bHYPRE_SStructVector__data * datab_SS, * datax_SS;
   void * objectA, * objectb, * objectx;

   data = bHYPRE_HPCG__get_data( self );
   comm = data->comm;
   /* SetCommunicator should have been called earlier */
   hypre_assert( comm != MPI_COMM_NULL );
   mat = data->matrix;
   /* SetOperator should have been called earlier */
   hypre_assert( mat != NULL );

   if ( data -> vector_type == NULL )
   {
      /* This is the first time this Babel PCG object has seen a
       * vector.  So we are ready to create the bHYPRE PCG object. */
      if ( bHYPRE_Vector__cast2( b, "bHYPRE.IJParCSRVector", _ex) )
      {
         SIDL_CHECK(*_ex);   
         bHYPRE_Vector_deleteRef( b, _ex ); SIDL_CHECK(*_ex);   
         data -> vector_type = "ParVector";
         HYPRE_ParCSRPCGCreate( comm, psolver );
         hypre_assert( solver != NULL );
         data -> solver = *psolver;
      }
      else if ( bHYPRE_Vector__cast2( b, "bHYPRE.SStructVector", _ex) )
      {
         SIDL_CHECK(*_ex);
         bHYPRE_Vector_deleteRef( b, _ex ); SIDL_CHECK(*_ex);
         data -> vector_type = "SStructVector";
         HYPRE_SStructPCGCreate( comm, (HYPRE_SStructSolver *) psolver );
         hypre_assert( solver != NULL );
         data -> solver = *psolver;
      }
      else if ( bHYPRE_Vector__cast2( b, "bHYPRE.StructVector", _ex) )
      {
         SIDL_CHECK(*_ex);
         bHYPRE_Vector_deleteRef( b, _ex ); SIDL_CHECK(*_ex);
         data -> vector_type = "StructVector";
         HYPRE_StructPCGCreate( comm, (HYPRE_StructSolver *) psolver );
         hypre_assert( solver != NULL );
         data -> solver = *psolver;
      }
      /* Add more vector types here */
      else
      {
         SIDL_CHECK(*_ex);
         hypre_assert( "only IJParCSRVector and StructVector supported by PCG"==0 );
      }
      bHYPRE_HPCG__set_data( self, data );
      ierr += impl_bHYPRE_HPCG_Copy_Parameters_from_HYPRE_struct( self );
   }
   else
   {
      solver = data->solver;
      hypre_assert( solver != NULL );
   }
   /* The SetParameter functions set parameters in the local
    * Babel-interface struct, "data".  That is because the HYPRE
    * struct (where they are actually used) may not exist yet when the
    * functions are called.  At this point we finally know the HYPRE
    * struct exists, so we copy the parameters to it. */
   ierr += impl_bHYPRE_HPCG_Copy_Parameters_to_HYPRE_struct( self );
   if ( data->vector_type == "ParVector" )
   {
      bHYPREP_b = (bHYPRE_IJParCSRVector) bHYPRE_Vector__cast2( b, "bHYPRE.IJParCSRVector", _ex );
      datab = bHYPRE_IJParCSRVector__get_data( bHYPREP_b );
      ij_b = datab -> ij_b;
      ierr += HYPRE_IJVectorGetObject( ij_b, &objectb );
      bb = (HYPRE_ParVector) objectb;
      HYPRE_b = (HYPRE_Vector) bb;

      bHYPREP_x = (bHYPRE_IJParCSRVector) bHYPRE_Vector__cast2( x, "bHYPRE.IJParCSRVector", _ex );
      SIDL_CHECK(*_ex);
      datax = bHYPRE_IJParCSRVector__get_data( bHYPREP_x );
      ij_x = datax -> ij_b;
      ierr += HYPRE_IJVectorGetObject( ij_x, &objectx );
      xx = (HYPRE_ParVector) objectx;
      HYPRE_x = (HYPRE_Vector) xx;

      bHYPREP_A = (bHYPRE_IJParCSRMatrix) bHYPRE_Operator__cast2( mat, "bHYPRE.IJParCSRMatrix", _ex );
      SIDL_CHECK(*_ex);
      hypre_assert( bHYPREP_A != NULL );
      dataA = bHYPRE_IJParCSRMatrix__get_data( bHYPREP_A );
      ij_A = dataA -> ij_A;
      ierr += HYPRE_IJMatrixGetObject( ij_A, &objectA );
      AA = (HYPRE_ParCSRMatrix) objectA;
      HYPRE_A = (HYPRE_Matrix) AA;
   }
   else if ( data->vector_type == "StructVector" )
   {
      bHYPRES_b = (bHYPRE_StructVector) bHYPRE_Vector__cast2( b, "bHYPRE.StructVector", _ex );
      SIDL_CHECK(*_ex);
      datab_S = bHYPRE_StructVector__get_data( bHYPRES_b );
      HS_b = datab_S -> vec;
      HYPRE_b = (HYPRE_Vector) HS_b;

      bHYPRES_x = (bHYPRE_StructVector) bHYPRE_Vector__cast2( x, "bHYPRE.StructVector", _ex );
      SIDL_CHECK(*_ex);
      datax_S = bHYPRE_StructVector__get_data( bHYPRES_x );
      HS_x = datax_S -> vec;
      HYPRE_x = (HYPRE_Vector) HS_x;

      bHYPRES_A = (bHYPRE_StructMatrix) bHYPRE_Operator__cast2( mat, "bHYPRE.StructMatrix", _ex );
      SIDL_CHECK(*_ex);
      hypre_assert( bHYPRES_A != NULL );
      dataA_S = bHYPRE_StructMatrix__get_data( bHYPRES_A );
      HS_A = dataA_S -> matrix;
      HYPRE_A = (HYPRE_Matrix) HS_A;
   }
   else if ( data->vector_type == "SStructVector" )
   {
      bHYPRESS_b = (bHYPRE_SStructVector) bHYPRE_Vector__cast2( b, "bHYPRE.SStructVector", _ex );
      SIDL_CHECK(*_ex);
      datab_SS = bHYPRE_SStructVector__get_data( bHYPRESS_b );
      HSS_b = datab_SS -> vec;
      HYPRE_b = (HYPRE_Vector) HSS_b;

      bHYPRESS_x = (bHYPRE_SStructVector) bHYPRE_Vector__cast2( x, "bHYPRE.SStructVector", _ex );
      SIDL_CHECK(*_ex);
      datax_SS = bHYPRE_SStructVector__get_data( bHYPRESS_x );
      HSS_x = datax_SS -> vec;
      HYPRE_x = (HYPRE_Vector) HSS_x;

      bHYPRESS_A = (bHYPRE_SStructMatrix) bHYPRE_Operator__cast2( mat, "bHYPRE.SStructMatrix", _ex );
      SIDL_CHECK(*_ex);
      hypre_assert( bHYPRESS_A != NULL );
      dataA_SS = bHYPRE_SStructMatrix__get_data( bHYPRESS_A );
      HSS_A = dataA_SS -> matrix;
      HYPRE_A = (HYPRE_Matrix) HSS_A;
   }
   else
   {
      hypre_assert( "PCG supports only IJParCSRVector and StructVector"==0 );
   }
      
   ierr += HYPRE_PCGSetPrecond( solver, data->precond, data->precond_setup,
                                *(data->solverprecond) );
   HYPRE_PCGSetup( solver, HYPRE_A, HYPRE_b, HYPRE_x );

   return ierr;

   hypre_babel_exception_return_error(_ex);
    /* DO-NOT-DELETE splicer.end(bHYPRE.HPCG.Setup) */
  }
}

/*
 * Apply the operator to {\tt b}, returning {\tt x}.
 */

#undef __FUNC__
#define __FUNC__ "impl_bHYPRE_HPCG_Apply"

#ifdef __cplusplus
extern "C"
#endif
int32_t
impl_bHYPRE_HPCG_Apply(
  /* in */ bHYPRE_HPCG self,
  /* in */ bHYPRE_Vector b,
  /* inout */ bHYPRE_Vector* x,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(bHYPRE.HPCG.Apply) */
  /* Insert-Code-Here {bHYPRE.HPCG.Apply} (Apply method) */

   /* In the long run, the solver should be implemented right here,
    * calling the appropriate bHYPRE functions.  But for now we are
    * calling the existing HYPRE solver.  Advantages: don't want to
    * have two versions of the same PCG solver lying around.
    * Disadvantage: we have to cache user-supplied parameters until
    * the Apply call, where we make the PCG object and really set the
    * parameters - messy and unnatural. */
   int ierr=0;
   MPI_Comm comm;
   HYPRE_Solver solver;
   HYPRE_Solver * psolver = &solver; /* will get a real value later */
   struct bHYPRE_HPCG__data * data;
   bHYPRE_Operator mat;
   HYPRE_Matrix HYPRE_A;
   bHYPRE_IJParCSRMatrix bHYPREP_A;
   bHYPRE_StructMatrix bHYPRES_A;
   bHYPRE_SStructMatrix bHYPRESS_A;
   HYPRE_ParCSRMatrix AA;
   HYPRE_IJMatrix ij_A;
   HYPRE_StructMatrix HS_A;
   HYPRE_SStructMatrix HSS_A;
   HYPRE_Vector HYPRE_x, HYPRE_b;
   bHYPRE_IJParCSRVector bHYPREP_b, bHYPREP_x;
   bHYPRE_StructVector bHYPRES_b, bHYPRES_x;
   bHYPRE_SStructVector bHYPRESS_b, bHYPRESS_x;
   HYPRE_ParVector bb, xx;
   HYPRE_IJVector ij_b, ij_x;
   HYPRE_StructVector HS_b, HS_x;
   HYPRE_SStructVector HSS_b, HSS_x;
   struct bHYPRE_IJParCSRMatrix__data * dataA;
   struct bHYPRE_StructMatrix__data * dataA_S;
   struct bHYPRE_SStructMatrix__data * dataA_SS;
   struct bHYPRE_IJParCSRVector__data * datab, * datax;
   struct bHYPRE_StructVector__data * datab_S, * datax_S;
   struct bHYPRE_SStructVector__data * datab_SS, * datax_SS;
   void * objectA, * objectb, * objectx;

   data = bHYPRE_HPCG__get_data( self );
   comm = data->comm;
   /* SetCommunicator should have been called earlier */
   hypre_assert( comm != MPI_COMM_NULL );
   mat = data->matrix;
   /* SetOperator should have been called earlier */
   hypre_assert( mat != NULL );

   if ( data -> vector_type == NULL )
   {
      /* This is the first time this Babel PCG object has seen a
       * vector.  So we are ready to create the bHYPRE PCG object. */
      if ( bHYPRE_Vector__cast2( b, "bHYPRE.IJParCSRVector", _ex) )
      {
         SIDL_CHECK(*_ex);
         bHYPRE_Vector_deleteRef( b, _ex ); SIDL_CHECK(*_ex);
         data -> vector_type = "ParVector";
         HYPRE_ParCSRPCGCreate( comm, psolver );
         hypre_assert( solver != NULL );
         data -> solver = *psolver;
      }
      else if ( bHYPRE_Vector__cast2( b, "bHYPRE.StructVector", _ex) )
      {
         SIDL_CHECK(*_ex);
         bHYPRE_Vector_deleteRef( b, _ex ); SIDL_CHECK(*_ex);
         data -> vector_type = "StructVector";
         HYPRE_StructPCGCreate( comm, (HYPRE_StructSolver *) psolver );
         hypre_assert( solver != NULL );
         data -> solver = *psolver;
      }
      else if ( bHYPRE_Vector__cast2( b, "bHYPRE.SStructVector", _ex) )
      {
         SIDL_CHECK(*_ex);
         bHYPRE_Vector_deleteRef( b, _ex ); SIDL_CHECK(*_ex);
         data -> vector_type = "SStructVector";
         HYPRE_SStructPCGCreate( comm, (HYPRE_SStructSolver *) psolver );
         hypre_assert( solver != NULL );
         data -> solver = *psolver;
      }
      /* Add more vector types here */
      else
      {
         SIDL_CHECK(*_ex);
         hypre_assert( "PCG supports only IJParCSRVector, StructVector, and SStructVector"==0 );
      }
      bHYPRE_HPCG__set_data( self, data );
      ierr += impl_bHYPRE_HPCG_Copy_Parameters_from_HYPRE_struct( self );
   }
   else
   {
      solver = data->solver;
      hypre_assert( solver != NULL );
   }
   /* The SetParameter functions set parameters in the local
    * Babel-interface struct, "data".  That is because the HYPRE
    * struct (where they are actually used) may not exist yet when the
    * functions are called.  At this point we finally know the HYPRE
    * struct exists, so we copy the parameters to it. */
   ierr += impl_bHYPRE_HPCG_Copy_Parameters_to_HYPRE_struct( self );
   if ( data->vector_type == "ParVector" )
   {
      bHYPREP_b = (bHYPRE_IJParCSRVector) bHYPRE_Vector__cast2( b, "bHYPRE.IJParCSRVector", _ex );
      SIDL_CHECK(*_ex);
      datab = bHYPRE_IJParCSRVector__get_data( bHYPREP_b );
      ij_b = datab -> ij_b;
      ierr += HYPRE_IJVectorGetObject( ij_b, &objectb );
      bb = (HYPRE_ParVector) objectb;
      HYPRE_b = (HYPRE_Vector) bb;

      bHYPREP_x = (bHYPRE_IJParCSRVector) bHYPRE_Vector__cast2( *x, "bHYPRE.IJParCSRVector", _ex );
      SIDL_CHECK(*_ex);
      datax = bHYPRE_IJParCSRVector__get_data( bHYPREP_x );
      ij_x = datax -> ij_b;
      ierr += HYPRE_IJVectorGetObject( ij_x, &objectx );
      xx = (HYPRE_ParVector) objectx;
      HYPRE_x = (HYPRE_Vector) xx;

      bHYPREP_A = (bHYPRE_IJParCSRMatrix) bHYPRE_Operator__cast2( mat, "bHYPRE.IJParCSRMatrix", _ex );
      SIDL_CHECK(*_ex);
      hypre_assert( bHYPREP_A != NULL );
      dataA = bHYPRE_IJParCSRMatrix__get_data( bHYPREP_A );
      ij_A = dataA -> ij_A;
      ierr += HYPRE_IJMatrixGetObject( ij_A, &objectA );
      AA = (HYPRE_ParCSRMatrix) objectA;
      HYPRE_A = (HYPRE_Matrix) AA;
   }
   else if ( data->vector_type == "StructVector" )
   {
      bHYPRES_b = (bHYPRE_StructVector) bHYPRE_Vector__cast2( b, "bHYPRE.StructVector", _ex );
      SIDL_CHECK(*_ex);
      datab_S = bHYPRE_StructVector__get_data( bHYPRES_b );
      HS_b = datab_S -> vec;
      HYPRE_b = (HYPRE_Vector) HS_b;

      bHYPRES_x = (bHYPRE_StructVector) bHYPRE_Vector__cast2( *x, "bHYPRE.StructVector", _ex );
      SIDL_CHECK(*_ex);
      datax_S = bHYPRE_StructVector__get_data( bHYPRES_x );
      HS_x = datax_S -> vec;
      HYPRE_x = (HYPRE_Vector) HS_x;

      bHYPRES_A = (bHYPRE_StructMatrix) bHYPRE_Operator__cast2( mat, "bHYPRE.StructMatrix", _ex );
      SIDL_CHECK(*_ex);
      hypre_assert( bHYPRES_A != NULL );
      dataA_S = bHYPRE_StructMatrix__get_data( bHYPRES_A );
      HS_A = dataA_S -> matrix;
      HYPRE_A = (HYPRE_Matrix) HS_A;
   }
   else if ( data->vector_type == "SStructVector" )
   {
      bHYPRESS_b = (bHYPRE_SStructVector) bHYPRE_Vector__cast2( b, "bHYPRE.SStructVector", _ex );
      SIDL_CHECK(*_ex);
      datab_SS = bHYPRE_SStructVector__get_data( bHYPRESS_b );
      HSS_b = datab_SS -> vec;
      HYPRE_b = (HYPRE_Vector) HSS_b;

      bHYPRESS_x = (bHYPRE_SStructVector) bHYPRE_Vector__cast2( *x, "bHYPRE.SStructVector", _ex );
      SIDL_CHECK(*_ex);
      datax_SS = bHYPRE_SStructVector__get_data( bHYPRESS_x );
      HSS_x = datax_SS -> vec;
      HYPRE_x = (HYPRE_Vector) HSS_x;

      bHYPRESS_A = (bHYPRE_SStructMatrix) bHYPRE_Operator__cast2( mat, "bHYPRE.SStructMatrix", _ex );
      SIDL_CHECK(*_ex);
      hypre_assert( bHYPRESS_A != NULL );
      dataA_SS = bHYPRE_SStructMatrix__get_data( bHYPRESS_A );
      HSS_A = dataA_SS -> matrix;
      HYPRE_A = (HYPRE_Matrix) HSS_A;
   }
   else
   {
      hypre_assert( "only IJParCSRVector supported by PCG"==0 );
   }
      
   ierr += HYPRE_PCGSetPrecond( solver, data->precond, data->precond_setup,
                                *(data->solverprecond) );

   HYPRE_PCGSolve( solver, HYPRE_A, HYPRE_b, HYPRE_x );

   return ierr;

   hypre_babel_exception_return_error(_ex);
    /* DO-NOT-DELETE splicer.end(bHYPRE.HPCG.Apply) */
  }
}

/*
 * Apply the adjoint of the operator to {\tt b}, returning {\tt x}.
 */

#undef __FUNC__
#define __FUNC__ "impl_bHYPRE_HPCG_ApplyAdjoint"

#ifdef __cplusplus
extern "C"
#endif
int32_t
impl_bHYPRE_HPCG_ApplyAdjoint(
  /* in */ bHYPRE_HPCG self,
  /* in */ bHYPRE_Vector b,
  /* inout */ bHYPRE_Vector* x,
  /* out */ sidl_BaseInterface *_ex)
{
  *_ex = 0;
  {
    /* DO-NOT-DELETE splicer.begin(bHYPRE.HPCG.ApplyAdjoint) */
  /* Insert-Code-Here {bHYPRE.HPCG.ApplyAdjoint} (ApplyAdjoint method) */

   return 1; /* not implemented */

    /* DO-NOT-DELETE splicer.end(bHYPRE.HPCG.ApplyAdjoint) */
  }
}
/* Babel internal methods, Users should not edit below this line. */
struct bHYPRE_HPCG__object* impl_bHYPRE_HPCG_fconnect_bHYPRE_HPCG(const char* 
  url, sidl_bool ar, sidl_BaseInterface *_ex) {
  return bHYPRE_HPCG__connectI(url, ar, _ex);
}
struct bHYPRE_HPCG__object* impl_bHYPRE_HPCG_fcast_bHYPRE_HPCG(void* bi, 
  sidl_BaseInterface* _ex) {
  return bHYPRE_HPCG__cast(bi, _ex);
}
struct bHYPRE_MPICommunicator__object* 
  impl_bHYPRE_HPCG_fconnect_bHYPRE_MPICommunicator(const char* url, sidl_bool 
  ar, sidl_BaseInterface *_ex) {
  return bHYPRE_MPICommunicator__connectI(url, ar, _ex);
}
struct bHYPRE_MPICommunicator__object* 
  impl_bHYPRE_HPCG_fcast_bHYPRE_MPICommunicator(void* bi, sidl_BaseInterface* 
  _ex) {
  return bHYPRE_MPICommunicator__cast(bi, _ex);
}
struct bHYPRE_Operator__object* impl_bHYPRE_HPCG_fconnect_bHYPRE_Operator(const 
  char* url, sidl_bool ar, sidl_BaseInterface *_ex) {
  return bHYPRE_Operator__connectI(url, ar, _ex);
}
struct bHYPRE_Operator__object* impl_bHYPRE_HPCG_fcast_bHYPRE_Operator(void* bi,
  sidl_BaseInterface* _ex) {
  return bHYPRE_Operator__cast(bi, _ex);
}
struct bHYPRE_PreconditionedSolver__object* 
  impl_bHYPRE_HPCG_fconnect_bHYPRE_PreconditionedSolver(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex) {
  return bHYPRE_PreconditionedSolver__connectI(url, ar, _ex);
}
struct bHYPRE_PreconditionedSolver__object* 
  impl_bHYPRE_HPCG_fcast_bHYPRE_PreconditionedSolver(void* bi, 
  sidl_BaseInterface* _ex) {
  return bHYPRE_PreconditionedSolver__cast(bi, _ex);
}
struct bHYPRE_Solver__object* impl_bHYPRE_HPCG_fconnect_bHYPRE_Solver(const 
  char* url, sidl_bool ar, sidl_BaseInterface *_ex) {
  return bHYPRE_Solver__connectI(url, ar, _ex);
}
struct bHYPRE_Solver__object* impl_bHYPRE_HPCG_fcast_bHYPRE_Solver(void* bi, 
  sidl_BaseInterface* _ex) {
  return bHYPRE_Solver__cast(bi, _ex);
}
struct bHYPRE_Vector__object* impl_bHYPRE_HPCG_fconnect_bHYPRE_Vector(const 
  char* url, sidl_bool ar, sidl_BaseInterface *_ex) {
  return bHYPRE_Vector__connectI(url, ar, _ex);
}
struct bHYPRE_Vector__object* impl_bHYPRE_HPCG_fcast_bHYPRE_Vector(void* bi, 
  sidl_BaseInterface* _ex) {
  return bHYPRE_Vector__cast(bi, _ex);
}
struct sidl_BaseClass__object* impl_bHYPRE_HPCG_fconnect_sidl_BaseClass(const 
  char* url, sidl_bool ar, sidl_BaseInterface *_ex) {
  return sidl_BaseClass__connectI(url, ar, _ex);
}
struct sidl_BaseClass__object* impl_bHYPRE_HPCG_fcast_sidl_BaseClass(void* bi, 
  sidl_BaseInterface* _ex) {
  return sidl_BaseClass__cast(bi, _ex);
}
struct sidl_BaseInterface__object* impl_bHYPRE_HPCG_fconnect_sidl_BaseInterface(
  const char* url, sidl_bool ar, sidl_BaseInterface *_ex) {
  return sidl_BaseInterface__connectI(url, ar, _ex);
}
struct sidl_BaseInterface__object* impl_bHYPRE_HPCG_fcast_sidl_BaseInterface(
  void* bi, sidl_BaseInterface* _ex) {
  return sidl_BaseInterface__cast(bi, _ex);
}
struct sidl_ClassInfo__object* impl_bHYPRE_HPCG_fconnect_sidl_ClassInfo(const 
  char* url, sidl_bool ar, sidl_BaseInterface *_ex) {
  return sidl_ClassInfo__connectI(url, ar, _ex);
}
struct sidl_ClassInfo__object* impl_bHYPRE_HPCG_fcast_sidl_ClassInfo(void* bi, 
  sidl_BaseInterface* _ex) {
  return sidl_ClassInfo__cast(bi, _ex);
}
struct sidl_RuntimeException__object* 
  impl_bHYPRE_HPCG_fconnect_sidl_RuntimeException(const char* url, sidl_bool ar,
  sidl_BaseInterface *_ex) {
  return sidl_RuntimeException__connectI(url, ar, _ex);
}
struct sidl_RuntimeException__object* 
  impl_bHYPRE_HPCG_fcast_sidl_RuntimeException(void* bi, sidl_BaseInterface* 
  _ex) {
  return sidl_RuntimeException__cast(bi, _ex);
}
