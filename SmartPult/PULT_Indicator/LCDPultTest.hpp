/*
 * LCDPultTest.hpp
 *
 *  Created on: 1 ���. 2019 �.
 *      Author: Kirill
 */

#ifndef PULT_INDICATOR_LCDPULTTEST_HPP_
#define PULT_INDICATOR_LCDPULTTEST_HPP_




#include "LCD Classes.h"
#include "../Pult/PultClasses.h"
#include "Libs/StandartElement/galetniy Perecluxhatel.hpp"
#include "Libs/StandartElement/encoder.hpp"
#include "LCDBase.hpp"

namespace LCD {

const char* menuName = "ZIF REVERS MENU";

LCDHeaderSettings settingsHeader = {
                            .visibleHeader=true,
                            .visiblePointerLeft=false,
                            .visiblePointerRight=false,
                            .visiblePointerUp=false,
                            .visiblePointerDown=false,
                            .textHeader= menuName
    };

const char * startStringTest[] = {"������ ���� ������",
                                  "������ ���� ������������"};

const char * stringButtonTest[] = {   "�������� � �������� ����",               //1
                                      "������� ������� ��",                     //2
                                      "������� ������� Left",                   //3
                                      "������� ������� Right",                  //4
                                      "������� ������� Up",                     //5
                                      "������� ������� Down",                   //6
                                      "������� ������� Play/Pause",             //7
                                      "������� ������� Stop",                   //8
                                      "������� ������� Delete",                 //9
                                      "������� ������� Revers play",            //10
                                      "������� ������� ESC",                    //11
                                      "������� ������� CAMERA START",           //12
                                      "������� ������� PK",                     //13
                                      "������� ������� PI",                     //14
            #ifndef USAEdition
                                      "������� ������� DK",                     //15
                                      "������� ������� DI",                     //16
            #else
                                      "������� ������� RK",                     //15
                                      "������� ������� RI",                     //16
            #endif
                                      "������� ������� TK",                     //17
                                      "������� ������� TI",                     //18
                                      "������� ������� Pan Sens",               //19
            #ifndef USAEdition
                                      "������� ������� Dutch Sens",             //20
            #else
                                      "������� ������� Roll Sens",              //20
            #endif
                                      "������� ������� Tilt Sens",              //21
                                      "������� ������� GV Calibration",         //22
            #ifdef Garanin
                                      "������� ������� Fast Level Correct",     //23
            #else
                                      "������� ������� Shaker",                 //23
            #endif
                                      "������� ������� GV/ACC",                 //24
                                      "������� PAN REVERS � ON",                //25
            #ifndef USAEdition
                                      "������� DUTCH REVERS � ON",              //26
            #else
                                      "������� ROLL REVERS � ON",               //26
            #endif
                                      "������� TILT REVERS � ON",               //27
                                      "������� MOTORS � ON",                    //28
                                      "������� JOYSTICK � ON",                  //29
                                      "������� LEVEL SETUP � ON",               //30
                                      "������� Backlight � ON"                  //31
                                        };

const char * stringResistorsTest[] = {   "PAN SPEED in MIN",            //1
                                         "PAN SPEED in MAX",            //2
                                         "PAN FLUID in MIN",            //3
                                         "PAN FLUID in MAX",            //4
                                         "PAN DRIFT in MIN",            //5
                                         "PAN DRIFT in MAX",            //6
            #ifndef USAEdition
                                         "DUTCH SPEED in MIN",          //7
                                         "DUTCH SPEED in MAX",          //8
                                         "DUTCH FLUID in MIN",          //9
                                         "DUTCH FLUID in MAX",          //10
                                         "DUTCH DRIFT in MIN",          //11
                                         "DUTCH DRIFT in MAX",          //12
            #else
                                         "ROLL SPEED in MIN",           //7
                                         "ROLL SPEED in MAX",           //8
                                         "ROLL FLUID in MIN",           //9
                                         "ROLL FLUID in MAX",           //10
                                         "ROLL DRIFT in MIN",           //11
                                         "ROLL DRIFT in MAX",           //12
            #endif
                                         "TILT SPEED in MIN",           //13
                                         "TILT SPEED in MAX",           //14
                                         "TILT FLUID in MIN",           //15
                                         "TILT FLUID in MAX",           //16
                                         "TILT DRIFT in MIN",           //17
                                         "TILT DRIFT in MAX",           //18
                                         "ZOOM SPEED in MIN",           //19
                                         "ZOOM SPEED in MAX",           //20
                                         "SPEED LEVEL CORRECT in MIN",  //21
                                         "SPEED LEVEL CORRECT in MAX",  //22
                                         "IRIS in MIN",                 //23
                                         "IRIS in MAX",                 //24
                                         "FOCUS in MIN",                //25
                                         "FOCUS in MAX",                //26
                                         "PAN JOY MAX LEFT",            //27
                                         "PAN JOY MAX RIGHT",           //28
                                         "TILT JOY MAX BACKWARD",       //29
                                         "TILT JOY MAX FORWARD",        //30
#ifndef USAEdition
                                         "DUTCH JOY MAX LEFT",          //31
                                         "DUTCH JOY MAX RIGHT",         //32
#else
                                         "ROLL JOY MAX LEFT",           //31
                                         "ROLL JOY MAX RIGHT",          //32
#endif
                                         "ZOOM MAX BACKWARD",           //33
                                         "ZOOM MAX FORWARD"             //34
                                        };

const char * korrectData[]   = { "������ ���������",
                                 "������ �����������"};

    LCDWorkcEditSettings startStringSettings = {
        .text=&startStringTest[0],
        .maxRisk=2-1
        };

    LCDWorkcEditSettings stringButtonTest = {
        .text=&stringButtonTest[0],
        .maxRisk=2-1
        };

    LCDWorkcEditSettings stringResistorsTest = {
        .text=&stringButtonTest[0],
        .maxRisk=2-1
        };

    LCDWorkcEditSettings korrectData = {
        .text=&stringButtonTest[0],
        .maxRisk=2-1
        };


enum {
    cellNumber=3
    }
class PultScrineTest {

private:
    LCDBaseNoRotation<cellNumber> form;

public:

    PultScrineTest() {

        }

private:

    inline void buttonTest () {
        
        }
        
    inline void potenciometrTest () {
            
        }
    
    
    };
}



#endif /* PULT_INDICATOR_LCDPULTTEST_HPP_ */
