/** A lightweight struct encapsulating a single relative pose-graph SLAM
 * measurement sampled from the generative model using the complex number
 * representation.
 *
 * Copyright (C) 2016 - 2018 by David M. Rosen (dmrosen@mit.edu)
 */

#pragma once

#include <Eigen/Dense>
#include <iostream>

#include "CPLSync/CPLSync_types.h"

namespace CPLSync {

/** A simple struct that contains the elements of a relative pose measurement */
struct RelativePoseMeasurement {

  /** 0-based index of first pose */
  size_t i;

  /** 0-based index of second pose */
  size_t j;

  /** Rotational measurement */
  Complex R;

  /** Translational measurement */
  Complex t;

  /** Rotational measurement precision */
  Scalar kappa;

  /** Translational measurement precision */
  Scalar tau;

  /** Simple default constructor; does nothing */
  RelativePoseMeasurement() {}

  /** Basic constructor */
  RelativePoseMeasurement(size_t first_pose, size_t second_pose,
                          Complex const &relative_rotation,
                          Complex const &relative_translation,
                          Scalar rotational_precision,
                          Scalar translational_precision)
      : i(first_pose), j(second_pose), R(relative_rotation),
        t(relative_translation), kappa(rotational_precision),
        tau(translational_precision) {}

  /** A utility function for streaming Nodes to cout */
  inline friend std::ostream &
  operator<<(std::ostream &os, const RelativePoseMeasurement &measurement) {
    os << "i: " << measurement.i << std::endl;
    os << "j: " << measurement.j << std::endl;
    os << "R: " << std::endl << measurement.R << std::endl;
    os << "t: " << std::endl << measurement.t << std::endl;
    os << "Kappa: " << measurement.kappa << std::endl;
    os << "Tau: " << measurement.tau << std::endl;

    return os;
  }
};

/** Typedef for a vector of RelativePoseMeasurements */
typedef std::vector<CPLSync::RelativePoseMeasurement> measurements_t;
} // namespace CPLSync
