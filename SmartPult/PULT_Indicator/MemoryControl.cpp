/*
 * MemoryControl.cpp
 *
 *  Created on: 25 ���. 2018 �.
 *      Author: AhrameshinGN
 */


#include "MemoryControl.hpp"

    uint32_t EE_Working::profileID=0;

    const EepromDefault pkDefault               =  {       0,      1,         100};     //0
    const EepromDefault dkDefault               =  {       0,      1,         100};     //1
    const EepromDefault tkDefault               =  {       0,      1,         100};     //2
    const EepromDefault piDefault               =  {       0,      1,         100};     //3
    const EepromDefault diDefault               =  {       0,      1,         100};     //4
    const EepromDefault tiDefault               =  {       0,      1,         100};     //5
    const EepromDefault brightnessDefault       =  {       0,      1,       100};     //6

    const EepromDefault panEqlLine0Default      =  {       0,      0x001C0009,         0x00e60084};     //7
    const EepromDefault panEqlLine1Default      =  {       0,      0x00400018,         0x00e60084};     //8
    const EepromDefault panEqlLine2Default      =  {       0,      0x0060002C,         0x00e60084};     //9
    const EepromDefault panEqlLine3Default      =  {       0,      0x00810048,         0x00e60084};     //10
    const EepromDefault panEqlLine4Default      =  {       0,      0x00A5006C,         0x00e60084};     //11
    const EepromDefault panEqlLine5Default      =  {       0,      0x00C6009E,         0x00e60084};     //12
    const EepromDefault panEqlLine6Default      =  {       0,      0x00E600E6,         0x00e60084};     //13
    const EepromDefault panEqlLine7Default      =  {       0,      0x00E600E6,         0x00e60084};     //14
    const EepromDefault panEqlLine8Default      =  {       0,      0x00E600E6,         0x00e60084};     //15
    const EepromDefault panEqlLine9Default      =  {       0,      0x00E600E6,         0x00e60084};     //16

    const EepromDefault dutchEqlLine0Default    =  {       0,      0x0020000B,         0x00e600e6};     //17
    const EepromDefault dutchEqlLine1Default    =  {       0,      0x00400016,         0x00e600e6};     //18
    const EepromDefault dutchEqlLine2Default    =  {       0,      0x00600022,         0x00e600e6};     //19
    const EepromDefault dutchEqlLine3Default    =  {       0,      0x00810038,         0x00e600e6};     //20
    const EepromDefault dutchEqlLine4Default    =  {       0,      0x00A10060,         0x00e600e6};     //21
    const EepromDefault dutchEqlLine5Default    =  {       0,      0x00C30097,         0x00e600e6};     //22
    const EepromDefault dutchEqlLine6Default    =  {       0,      0x00E600E6,         0x00e600e6};     //23
    const EepromDefault dutchEqlLine7Default    =  {       0,      0x00e60084,         0x00e600e6};     //24
    const EepromDefault dutchEqlLine8Default    =  {       0,      0x00e60084,         0x00e600e6};     //25
    const EepromDefault dutchEqlLine9Default    =  {       0,      0x00e60084,         0x00e600e6};     //26

    const EepromDefault tiltEqlLine0Default     =  {       0,      0x00200009,         0x00e600D8};     //27
    const EepromDefault tiltEqlLine1Default     =  {       0,      0x00400017,         0x00e600D8};     //28
    const EepromDefault tiltEqlLine2Default     =  {       0,      0x00600026,         0x00e600D8};     //29
    const EepromDefault tiltEqlLine3Default     =  {       0,      0x00830041,         0x00e600D8};     //30
    const EepromDefault tiltEqlLine4Default     =  {       0,      0x00A50068,         0x00e600D8};     //31
    const EepromDefault tiltEqlLine5Default     =  {       0,      0x00C8009D,         0x00e600D8};     //32
    const EepromDefault tiltEqlLine6Default     =  {       0,      0x00E600DF,         0x00e600D8};     //33
    const EepromDefault tiltEqlLine7Default     =  {       0,      0x00e60084,         0x00e600D8};     //34
    const EepromDefault tiltEqlLine8Default     =  {       0,      0x00e60084,         0x00e600D8};     //35
    const EepromDefault tiltEqlLine9Default     =  {       0,      0x00e60084,         0x00e600D8};     //36

    const EepromDefault panSenseDefault         =  {       0,               2,                  3};     //37
    const EepromDefault dutchSenseDefault       =  {       0,               2,                  3};     //38
    const EepromDefault tiltSenseDefault        =  {       0,               2,                  3};     //39

    const EepromDefault shadowSettings0Default  =  {       0xC1A000BE,      0x3170A3D7,         0x41A000BE};    //40
    const EepromDefault shadowSettings1Default  =  {       0xC1A000BE,      0x3170A3D7,         0x41A000BE};    //41
    const EepromDefault shadowSettings2Default  =  {       0xC1A000BE,      0x3170A3D7,         0x41A000BE};    //42
    const EepromDefault shadowSettings3Default  =  {       0xC1A000BE,      0x3170A3D7,         0x41A000BE};    //43
    const EepromDefault shadowSettings4Default  =  {       0xC1A000BE,      0x3170A3D7,         0x41A000BE};    //44
    const EepromDefault shadowSettings5Default  =  {       0xC1A000BE,      0x3170A3D7,         0x41A000BE};    //45
    const EepromDefault shadowSettings6Default  =  {       0xC1A000BE,      0x3170A3D7,         0x41A000BE};    //46
    const EepromDefault shadowSettings7Default  =  {       0xC1A000BE,      0x3170A3D7,         0x41A000BE};    //47
    const EepromDefault shadowSettings8Default  =  {       0xC1A000BE,      0x3170A3D7,         0x41A000BE};    //48
    const EepromDefault shadowSettings9Default  =  {       0xC1A000BE,      0x3170A3D7,         0x41A000BE};    //49

    const EepromDefault joyConfigDefault        =  {       0,               0,                  2};             //50
    const EepromDefault motors1ModelDefault     =  {       0,      0,         0};                               //51
    const EepromDefault motors2ModelDefault     =  {       0,      0,         0};                               //52
    const EepromDefault motors3ModelDefault     =  {       0,      0,         0};                               //53
    const EepromDefault motors1TypeDefault      =  {       0,               0,                  1};             //54
    const EepromDefault motors2TypeDefault      =  {       0,               0,                  1};             //55
    const EepromDefault motors3TypeDefault      =  {       0,               0,                  1};             //56

    const EepromDefault zoomMotorIdDefault      =  {       0,               0,                  2};             //57
    const EepromDefault irisMotorIdDefault      =  {       0,               2,                  2};             //58
    const EepromDefault focusMotorIdDefault     =  {       0,               1,                  2};             //59

    const EepromDefault zoomEqlLine0Default     =  {       0,      0x00030030,         0x00e600e6};             //60
    const EepromDefault zoomEqlLine1Default     =  {       0,      0x00230039,         0x00e600e6};             //61
    const EepromDefault zoomEqlLine2Default     =  {       0,      0x004C0042,         0x00e600e6};             //62
    const EepromDefault zoomEqlLine3Default     =  {       0,      0x00750063,         0x00e600e6};             //63
    const EepromDefault zoomEqlLine4Default     =  {       0,      0x009C009F,         0x00e600e6};             //64
    const EepromDefault zoomEqlLine5Default     =  {       0,      0x00C100E6,         0x00e600e6};             //65
    const EepromDefault zoomEqlLine6Default     =  {       0,      0x00E600E6,         0x00e600e6};             //66
    const EepromDefault zoomEqlLine7Default     =  {       0,      0x00E600E6,         0x00e600e6};             //67
    const EepromDefault zoomEqlLine8Default     =  {       0,      0x00E600E6,         0x00e600e6};             //68
    const EepromDefault zoomEqlLine9Default     =  {       0,      0x00E600E6,         0x00e600e6};             //69

    const EepromDefault zoomSenseDefault        =  {       0,               0,                  3};             //70
    const EepromDefault cameraStartDefault      =  {       0,               0,                  7};             //71
    const EepromDefault overslangDefault        =  {       0,               1,                  1};             //72

    const EepromDefault panWheelSpeedDefault    =  {       0,      0x3d4cccc3,         0x3f800001};             //73
    const EepromDefault tiltWheelSpeedDefault   =  {       0,      0x3d4ccccF,         0x3f800001};             //74
    const EepromDefault tiltResonTypeDefault    =  {       0,               0,                  0};             //75
    const EepromDefault tiltResonFreqDefault    =  {       0,      0x40B3332D,         0x41100000};             //76

    const EepromDefault panMaxTorqDefault       =  {       0,             100,                100};             //77
    const EepromDefault dutchMaxTorqDefault     =  {       0,             100,                100};             //78
    const EepromDefault tiltMaxTorqDefault      =  {       0,             100,                100};             //79

    const EepromDefault panJoyDzDefault         =  {       0,              0,                100};             //80
    const EepromDefault dutchJoyDzDefault       =  {       0,              15,                100};             //81
    const EepromDefault tiltJoyDzDefault        =  {       0,              0,                100};             //82
    const EepromDefault zoomJoyDzDefault        =  {       0,              0,                100};             //83

    const EepromDefault dutchWheelSpeedDefault  =  {       0,      0x3d4ccccF,         0x3f800001};             //84

    const EepromDefault panResonanceTypeDefault =  {       0,               0,                  2};             //85
    const EepromDefault panResonanceFreqDefault =  {       0,      0x40BFFFF9,         0x41100000};             //86

    const EepromDefault panStartFluidDefault    =  {       0,               0,               100};              //87
    const EepromDefault dutchStartFluidDefault  =  {       0,               0,               100};              //88
    const EepromDefault tiltStartFluidDefault   =  {       0,               0,               100};              //89
    const EepromDefault zoomStartFluidDefault   =  {       0,               0,               100};              //90

    const EepromDefault zoomDriftDefault        =  {       0xFFFFFF00,      0,               100};              //91

    const EepromDefault prerolMasterDefault     =  {       0,               0,             30000};              //92
    const EepromDefault synchroSourceDefault    =  {       0,               0,                 1};              //93
    const EepromDefault prerolSlave1Default     =  {       0,               0,             30000};              //94
    const EepromDefault prerolSlave2Default     =  {       0,               0,             30000};              //95
    const EepromDefault prerolSlave3Default     =  {       0,               0,            300000};              //96

    const EepromDefault driftStopperOnDefault   =  {       0,               0,                 1};              //97
    const EepromDefault panFolowingDefault      =  {       0,               0,                 62};              //98
    const EepromDefault CRCDefault              =  {       0,      0,         0};                               //99




    const EepromDefault* defaultSettings[]=
    {
         &pkDefault,
         &dkDefault,
         &tkDefault,
         &piDefault,
         &diDefault,
         &tiDefault,
         &brightnessDefault,

         &panEqlLine0Default,
         &panEqlLine1Default,
         &panEqlLine2Default,
         &panEqlLine3Default,
         &panEqlLine4Default,
         &panEqlLine5Default,
         &panEqlLine6Default,
         &panEqlLine7Default,
         &panEqlLine8Default,
         &panEqlLine9Default,

         &dutchEqlLine0Default,
         &dutchEqlLine1Default,
         &dutchEqlLine2Default,
         &dutchEqlLine3Default,
         &dutchEqlLine4Default,
         &dutchEqlLine5Default,
         &dutchEqlLine6Default,
         &dutchEqlLine7Default,
         &dutchEqlLine8Default,
         &dutchEqlLine9Default,

         &tiltEqlLine0Default,
         &tiltEqlLine1Default,
         &tiltEqlLine2Default,
         &tiltEqlLine3Default,
         &tiltEqlLine4Default,
         &tiltEqlLine5Default,
         &tiltEqlLine6Default,
         &tiltEqlLine7Default,
         &tiltEqlLine8Default,
         &tiltEqlLine9Default,

         &panSenseDefault,
         &dutchSenseDefault,
         &tiltSenseDefault,

         &shadowSettings0Default,
         &shadowSettings1Default,
         &shadowSettings2Default,
         &shadowSettings3Default,
         &shadowSettings4Default,
         &shadowSettings5Default,
         &shadowSettings6Default,
         &shadowSettings7Default,
         &shadowSettings8Default,
         &shadowSettings9Default,

         &joyConfigDefault,
         &motors1ModelDefault,
         &motors2ModelDefault,
         &motors3ModelDefault,
         &motors1TypeDefault,
         &motors2TypeDefault,
         &motors3TypeDefault,

         &zoomMotorIdDefault,
         &irisMotorIdDefault,
         &focusMotorIdDefault,

         &zoomEqlLine0Default,
         &zoomEqlLine1Default,
         &zoomEqlLine2Default,
         &zoomEqlLine3Default,
         &zoomEqlLine4Default,
         &zoomEqlLine5Default,
         &zoomEqlLine6Default,
         &zoomEqlLine7Default,
         &zoomEqlLine8Default,
         &zoomEqlLine9Default,

         &zoomSenseDefault,
         &cameraStartDefault,
         &overslangDefault,

         &panWheelSpeedDefault,
         &tiltWheelSpeedDefault,
         &tiltResonTypeDefault,
         &tiltResonFreqDefault,

         &panMaxTorqDefault,
         &dutchMaxTorqDefault,
         &tiltMaxTorqDefault,

         &panJoyDzDefault,
         &dutchJoyDzDefault,
         &tiltJoyDzDefault,
         &zoomJoyDzDefault,

         &dutchWheelSpeedDefault,

         &panResonanceTypeDefault,
         &panResonanceFreqDefault,

         &panStartFluidDefault,
         &dutchStartFluidDefault,
         &tiltStartFluidDefault,
         &zoomStartFluidDefault,

         &zoomDriftDefault,

         &prerolMasterDefault,
         &synchroSourceDefault,
         &prerolSlave1Default,
         &prerolSlave2Default,
         &prerolSlave3Default,

         &driftStopperOnDefault,
         &panFolowingDefault,
         &CRCDefault
    };



    const EepromDefault& getSettingsLimits(EEPROM_Filds filed)
    {
        return (*defaultSettings[filed]);
    }


    const EepromDefault calibrationMainPan      =     {       0,      1860,         0xFFFF};
    const EepromDefault calibrationMainDutch    =     {       0,      1860,         0xFFFF};
    const EepromDefault calibrationMainTilt     =     {       0,      1860,         0xFFFF};
    const EepromDefault calibrationMainZoom     =     {       0,      1860,         0xFFFF};
    const EepromDefault calibrationExtPan       =     {       0,      1860,         0xFFFF};
    const EepromDefault calibrationExtDutch     =     {       0,      1860,         0xFFFF};
    const EepromDefault calibrationExtTilt      =     {       0,      1860,         0xFFFF};
    const EepromDefault calibrationExt2Dutch    =     {       0,      2110,         0xFFFF};
    const EepromDefault calibrationHours        =     {       0,      0,            0xFFFFFF};
    const EepromDefault calibrationCRC          =     {       0,      0,            0xFFFFFF};

    const EepromDefault* defaultCalibrationSettings[]=
    {
         &calibrationMainPan,
         &calibrationMainDutch ,
         &calibrationMainTilt,
         &calibrationMainZoom,
         &calibrationExtPan,
         &calibrationExtDutch,
         &calibrationExtTilt,
         &calibrationExt2Dutch,
         &calibrationHours,
         &calibrationCRC
    };

    const EepromDefault& getCalibrationLimits(EepromCalibrationAddressMap filed)
    {
        return (*defaultCalibrationSettings[filed]);
    }
