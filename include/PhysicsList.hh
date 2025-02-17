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
/// \file electromagnetic/TestEm1/include/PhysicsList.hh
/// \brief Definition of the PhysicsList class
//
// $Id: PhysicsList.hh 82331 2014-06-16 09:54:40Z gcosmo $
//
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//
// 14.10.02 (V.Ivanchenko) provide modular list on base of old PhysicsList
//
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#ifndef PhysicsList_h
#define PhysicsList_h 1

#include "G4VModularPhysicsList.hh"
#include "globals.hh"
#include "Outgoing_Beam.hh"

class DetectorConstruction;
class PhysicsListMessenger;
class G4VPhysicsConstructor;
class PhysicsList_Messenger;

#ifdef NEUTRONS
// From LBE for neutrons
class G4StoppingPhysics;        // This builder encapsulate stopping processes
#endif

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class PhysicsList: public G4VModularPhysicsList
{
public:
  PhysicsList(DetectorConstruction*);
  ~PhysicsList();

  virtual void ConstructParticle();
  virtual void ConstructProcess();

#ifdef NEUTRONS
    // From LBE for neutrons
    virtual void ConstructHad();
#endif

  void SetOutgoingBeam(Outgoing_Beam *BO) {BeamOut = BO;}
  void AddReaction();

  void AddPhysicsList(const G4String& name);
    
  void AddDecay();
  void AddRadioactiveDecay();
  void AddStepMax();

  void GetRange(G4double);

  void SetGammaAngularCorrelations(bool);

  void SetUsePolarizedPhysics(bool);

private:    
  G4VPhysicsConstructor* fEmPhysicsList;
  G4String               fEmName;
    
  DetectorConstruction* fDet;

  Outgoing_Beam* BeamOut;

  PhysicsList_Messenger* theMessenger;
  bool usePolar;

#ifdef NEUTRONS
    // From LBE for neutrons
    G4StoppingPhysics* stoppingPhysics;
#endif

  //    PhysicsListMessenger* fMessenger;         
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

