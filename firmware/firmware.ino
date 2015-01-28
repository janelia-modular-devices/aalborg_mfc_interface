#include <EEPROM.h>
#include "Streaming.h"
#include "JsonParser.h"
#include "StandardCplusplus.h"
#include "MemoryFree.h"
#include "Flash.h"
#include "ModularDevice.h"
#include "Constants.h"
#include "Callbacks.h"

// See README.md for more information

using namespace ModularDevice;

void setup()
{
  // Pin Setup
  for (int mfc = 0; mfc < constants::MFC_COUNT; mfc++)
  {
    pinMode(constants::purge_pins[mfc],INPUT);
    pinMode(constants::valve_off_pins[mfc],INPUT);
  }

  // Device Info
  modular_device.setName(constants::device_name);
  modular_device.setModelNumber(constants::model_number);
  modular_device.setFirmwareNumber(constants::firmware_number);

  // Saved Variables
  modular_device.createSavedVariable(constants::flow_settings_name,constants::flow_settings_default);

  uint8 flow_settings[constants::MFC_COUNT];
  modular_device.getSavedVariableValue(constants::flow_settings_name,flow_settings);

  for (int mfc = 0; mfc < constants::MFC_COUNT; mfc++)
  {
    analogWrite(constants::pwm_pins[mfc],flow_settings[mfc]);
  }

  // Parameters
  Parameter& mfc_parameter = modular_device.createParameter(constants::mfc_parameter_name);
  percent_parameter.setRange(0,constants::MFC_COUNT-1);
  Parameter& percent_parameter = modular_device.createParameter(constants::percent_parameter_name);
  percent_parameter.setRange(constants::percent_min,constants::percent_max);

  // Methods
  Method& set_mfc_flow_method = modular_device.createMethod(constants::set_mfc_flow_method_name);
  set_mfc_flow_method.attachCallback(callbacks::setMfcFlowCallback);
  set_mfc_flow_method.addParameter(mfc_parameter);
  set_mfc_flow_method.addParameter(percent_parameter);

  Method& get_mfc_flow_setting_method = modular_device.createMethod(constants::get_mfc_flow_setting_method_name);
  get_mfc_flow_setting_method.attachCallback(callbacks::getMfcValueACallback);
  get_mfc_flow_setting_method.addParameter(mfc_parameter);

  Method& get_mfc_flow_measure_method = modular_device.createMethod(constants::get_mfc_flow_measure_method_name);
  get_mfc_flow_measure_method.attachCallback(callbacks::getMfcValueACallback);
  get_mfc_flow_measure_method.addParameter(mfc_parameter);

  // Start Server
  modular_device.startServer(constants::baudrate);
}

void loop()
{
  modular_device.handleServerRequests();
}
