#ifndef TPC_TPCDISTORTIONCORRECTIONCONTAINER_H
#define TPC_TPCDISTORTIONCORRECTIONCONTAINER_H

/*!
 * \file TpcDistortionCorrectionContainer.h
 * \brief stores distortion correction histograms on the node tree
 * \author Hugo Pereira Da Costa <hugo.pereira-da-costa@cea.fr>
 */

#include <array>

class TH1;

class TpcDistortionCorrectionContainer
{
 public:
  //! constructor
  TpcDistortionCorrectionContainer() = default;

  //! flag to tell us whether to read z data or just 2d data
  int m_dimensions = 3;

  bool m_use_scalefactor = false;
  float m_scalefactor = 1.0;

  //! set the phi histogram to be interpreted as radians rather than mm
  bool m_phi_hist_in_radians = true;
  //! flag to tell us how to handle 2d corrections: interpolate to 0 at readout or assume the correction has no z dependence
  bool m_interpolate_z = true;

  //!@name space charge distortion histograms
  //@{
  std::array<TH1*, 2> m_hDRint = {{nullptr, nullptr}};
  std::array<TH1*, 2> m_hDPint = {{nullptr, nullptr}};
  std::array<TH1*, 2> m_hDZint = {{nullptr, nullptr}};

  /// keep track of number of entries in each bin
  /**
   * used temporarily  when building distortion corrections on the fly
   * it is not used to actually apply corrections to a given 3D point
   */
  std::array<TH1*, 2> m_hentries = {{nullptr, nullptr}};
  //@}
};

#endif
