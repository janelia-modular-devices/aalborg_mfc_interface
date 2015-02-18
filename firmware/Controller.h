// ----------------------------------------------------------------------------
// Controller.h
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------

#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "ModularDevice.h"
#include "StandaloneInterface.h"
#include "BetterMap.h"
#include "Constants.h"
#include "Callbacks.h"

class Controller
{
public:
  Controller();
  void setup();
  void update();
  void executeStandaloneCallback();
  bool getLedsPowered();
  void setMfcFlow(const uint8_t mfc, const uint8_t percent);
  uint8_t getMfcFlowSetting(const uint8_t mfc);
  uint8_t getMfcFlowMeasure(const uint8_t mfc);
  // void saveState(int state);
  // void recallState(int state);
  // uint32_t* getStatesArray();
private:
  Standalone::StandaloneInterface standalone_interface_;
  uint8_t flow_settings_array_[constants::MFC_COUNT];
  Standalone::DisplayVariable *mfc0_dsp_var_ptr_;
  Standalone::DisplayVariable *mfc1_dsp_var_ptr_;
  Standalone::DisplayVariable *mfc2_dsp_var_ptr_;
  void updateDisplayVariables();
  // Standalone::InteractiveVariable *mfc0_int_var_ptr_;
  // Standalone::InteractiveVariable *mfc1_int_var_ptr_;
  // Standalone::InteractiveVariable *mfc2_int_var_ptr_;
  // Standalone::InteractiveVariable *state_int_var_ptr_;
};

extern Controller controller;

#endif