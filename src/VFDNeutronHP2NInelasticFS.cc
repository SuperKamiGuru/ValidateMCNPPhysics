//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
// neutron_hp -- source file
// J.P. Wellisch, Nov-1996
// A prototype of the low energy neutron transport model.
//
#include "../include/VFDNeutronHP2NInelasticFS.hh"
#include "G4Nucleus.hh"
#include "G4Alpha.hh"

G4HadFinalState * VFDNeutronHP2NInelasticFS::ApplyYourself(const G4HadProjectile & theTrack)
{

// these are the particle types in the final state

  G4ParticleDefinition * theDefs[2];
  theDefs[0] = G4Neutron::Neutron();
  theDefs[1] = G4Neutron::Neutron();

// fill the final state
  VFDNeutronHPInelasticBaseFS::BaseApply(theTrack, theDefs, 2);

// return the result
   return &theResult;
}

void VFDNeutronHP2NInelasticFS::
Init (G4double A, G4double Z, G4int M, G4String & dirName, G4String & aFSType)
{
   VFDNeutronHPInelasticBaseFS::Init(A, Z, M, dirName, aFSType);
   G4double ResidualA = A-1;
   G4double ResidualZ = Z;
   VFDNeutronHPInelasticBaseFS::InitGammas(ResidualA, ResidualZ);
}