// EMTG: Evolutionary Mission Trajectory Generator
// An open-source global optimization tool for preliminary mission design
// Provided by NASA Goddard Space Flight Center
//
// Copyright (c) 2013 - 2020 United States Government as represented by the
// Administrator of the National Aeronautics and Space Administration.
// All Other Rights Reserved.

// Licensed under the NASA Open Source License (the "License"); 
// You may not use this file except in compliance with the License. 
// You may obtain a copy of the License at:
// https://opensource.org/licenses/NASA-1.3
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either 
// express or implied.   See the License for the specific language
// governing permissions and limitations under the License.

// Acceleration model accuracy verification against MIRAGE data

#pragma once

#include <map>
#include "missionoptions.h"
#include "universe.h"
#include "Spacecraft.h"
#include "LaunchVehicle.h"

void MIRAGE_verification(EMTG::missionoptions& options,
	                     std::vector< EMTG::Astrodynamics::universe > TheUniverse,
	                     EMTG::HardwareModels::Spacecraft& mySpacecraft,
	                     EMTG::HardwareModels::LaunchVehicle& myLaunchVehicle);

typedef struct MIRAGE_data_row
{
    std::string epoch;
    double mass;

    std::map<std::string, EMTG::math::Matrix<double>> acceleration_components;
    EMTG::math::Matrix<double> rcp, vcp, cbp, sup, obl, rel,
        fmb, tot, mep, vep, eap, map,
        jup, sap, urp, nep, plp, mop, alb, inf;
};