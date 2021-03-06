#ifndef COOLFluiD_Numerics_FluctSplit_WeakSlipWallEuler2DHOImpl_hh
#define COOLFluiD_Numerics_FluctSplit_WeakSlipWallEuler2DHOImpl_hh

//////////////////////////////////////////////////////////////////////////////

#include "FluctSplit/HONavierStokes/WeakSlipWall2DHOImpl.hh"

//////////////////////////////////////////////////////////////////////////////

namespace COOLFluiD {

  namespace Physics {
    namespace NavierStokes {
      class Euler2DVarSet;
    }
  }



    namespace FluctSplit {

//////////////////////////////////////////////////////////////////////////////

/**
 * This class represents an implicit weak slip wall bc (E. V. Weide) for Euler2D
 * for P2 elements
 * @author Nadege Villedieu
 *
 */
class WeakSlipWallEuler2DHOImpl : public WeakSlipWall2DHOImpl {
public:

  /**
   * Constructor.
   */
  WeakSlipWallEuler2DHOImpl(const std::string& name);

  /**
   * Default destructor
   */
  ~WeakSlipWallEuler2DHOImpl();

  /**
   * Set up private data and data of the aggregated classes
   * in this command before processing phase
   */
  virtual void setup();

protected:
  
  /**
   * Compute the normal flux and the corresponding jacobian
   */
  void computeNormalFluxAndJacob(const Framework::State& state,
				 const RealVector& normal,
				 RealVector& flux,
				 RealMatrix& fluxJacob);
protected:
  
  /// Euler var set
  Common::SafePtr<Physics::NavierStokes::Euler2DVarSet> _varSet;
  
  
}; // end of class WeakSlipWallEuler2DHOImpl

//////////////////////////////////////////////////////////////////////////////

    } // namespace FluctSplit



} // namespace COOLFluiD

//////////////////////////////////////////////////////////////////////////////

#endif // COOLFluiD_Numerics_FluctSplit_WeakSlipWallEuler2DHOImpl_hh
