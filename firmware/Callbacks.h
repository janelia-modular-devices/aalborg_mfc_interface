// ----------------------------------------------------------------------------
// Callbacks.h
//
//
// Authors:
// Peter Polidoro peter@polidoro.io
// ----------------------------------------------------------------------------
#ifndef CALLBACKS_H
#define CALLBACKS_H
#include "ArduinoJson.h"
#include "ModularDevice.h"
#include "Constants.h"
#include "Controller.h"


namespace callbacks
{
void getLedsPoweredCallback();

void setMfcFlowCallback();

void setMfcFlowsCallback();

void getMfcFlowSettingCallback();

void getMfcFlowSettingsCallback();

void getMfcFlowMeasureCallback();

void getMfcFlowMeasuresCallback();

void getAnalogInputCallback();

void getAnalogInputsCallback();

void saveStateCallback();

void recallStateCallback();

void getSavedStatesCallback();

void pulseBncBCallback();

// Standalone Callbacks
void executeStandaloneCallbackCallback();

void saveStateStandaloneCallback();

void recallStateStandaloneCallback();

void pulseBncBStandaloneCallback();

// EventController Callbacks
void setBncBHighCallback(int index);

void setBncBLowCallback(int index);
}
#endif
