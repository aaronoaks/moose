//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#pragma once

#include "FVMatAdvection.h"

class PNSFVUpwindAdvectorAndAdvected : public FVMatAdvection
{
public:
  static InputParameters validParams();
  PNSFVUpwindAdvectorAndAdvected(const InputParameters & params);

protected:
  virtual ADReal computeQpResidual() override;

  /// The porosity on the element
  const MaterialProperty<Real> & _eps_elem;

  /// The porosity on the neighbor
  const MaterialProperty<Real> & _eps_neighbor;
};