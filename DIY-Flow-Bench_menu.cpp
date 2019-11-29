/*
    The code in this file uses open source libraries provided by thecoderscorner

    DO NOT EDIT THIS FILE, IT WILL BE GENERATED EVERY TIME YOU USE THE UI DESIGNER
    INSTEAD EITHER PUT CODE IN YOUR SKETCH OR CREATE ANOTHER SOURCE FILE.

    All the variables you may need access to are marked extern in this file for easy
    use elsewhere.
 */

#include <tcMenu.h>
#include "DIY-Flow-Bench_menu.h"

// Global variable declarations

LiquidCrystal lcd(2, 1, 0, 4, 5, 6, 7, ioFrom8574(0x20));
LiquidCrystalRenderer renderer(lcd, LCD_WIDTH, LCD_HEIGHT);

// Global Menu Item declarations

const PROGMEM AnyMenuInfo minfoSettingsLeakTestCheck = { "Leak Test Check", 9, 10, 0, checkLeakCalibration };
ActionMenuItem menuSettingsLeakTestCheck(&minfoSettingsLeakTestCheck, NULL);
const PROGMEM AnyMenuInfo minfoSettingsLeakTestCal = { "Leak Test Cal", 8, 10, 0, setLeakCalibrationValue };
ActionMenuItem menuSettingsLeakTestCal(&minfoSettingsLeakTestCal, &menuSettingsLeakTestCheck);
const PROGMEM AnyMenuInfo minfoSettingsFlowRefCheck = { "Flow Ref Check", 7, 10, 0, checkFlowCalibration };
ActionMenuItem menuSettingsFlowRefCheck(&minfoSettingsFlowRefCheck, &menuSettingsLeakTestCal);
const PROGMEM AnyMenuInfo minfoSettingsFlowRefCal = { "Flow Ref Cal", 6, 10, 0, setFlowCalibrationValue };
ActionMenuItem menuSettingsFlowRefCal(&minfoSettingsFlowRefCal, &menuSettingsFlowRefCheck);
RENDERING_CALLBACK_NAME_INVOKE(fnSettingsRtCall, backSubItemRenderFn, "Settings", 10, NULL)
const PROGMEM SubMenuInfo minfoSettings = { "Settings", 5, 10, 0, NO_CALLBACK };
BackMenuItem menuBackSettings(fnSettingsRtCall, &menuSettingsFlowRefCal);
SubMenuItem menuSettings(&minfoSettings, &menuBackSettings, NULL);
const PROGMEM AnalogMenuInfo minfoPitotDiffPres = { "Pitot (Diff Pres)", 4, 8, 255, NO_CALLBACK, 0, 1, "inWg" };
AnalogMenuItem menuPitotDiffPres(&minfoPitotDiffPres, 0, &menuSettings);
const PROGMEM AnalogMenuInfo minfoTemperature = { "Temperature", 3, 6, 255, NO_CALLBACK, 0, 1, "DegC" };
AnalogMenuItem menuTemperature(&minfoTemperature, 0, &menuPitotDiffPres);
const PROGMEM AnalogMenuInfo minfoRefPressure = { "Ref Pressure", 2, 4, 255, NO_CALLBACK, 0, 1, "inWg" };
AnalogMenuItem menuRefPressure(&minfoRefPressure, 0, &menuTemperature);
const PROGMEM AnalogMenuInfo minfoFlowRate = { "Flow Rate", 1, 2, 255, NO_CALLBACK, 0, 1, "cfm" };
AnalogMenuItem menuFlowRate(&minfoFlowRate, 0, &menuRefPressure);
const PROGMEM ConnectorLocalInfo applicationInfo = { "DIY Flow Bench", "0fc9ae97-7781-4600-a281-4a3425ce8371" };

// Set up code

void setupMenu() {
    Wire.begin();
    lcd.begin(LCD_WIDTH, LCD_HEIGHT);
    lcd.configureBacklightPin(3);
    lcd.backlight();
    switches.initialise(ioUsingArduino(), true);
    menuMgr.initForEncoder(&renderer, &menuFlowRate, ENCODER_PIN_A, ENCODER_PIN_B, ENCODER_PIN_OK);

    // Read only and local only function calls
    menuFlowRate.setReadOnly(true);
    menuRefPressure.setReadOnly(true);
    menuTemperature.setReadOnly(true);
    menuPitotDiffPres.setReadOnly(true);
}

