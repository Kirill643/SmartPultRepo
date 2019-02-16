/*
 * LensParam.cpp
 *
 *  Created on: 15 ����. 2019 �.
 *      Author: Cheverev kirill
 */

#include <LensParam/LensParam.hpp>

using namespace LanseParam;

void lenseAxisParametr::setObectivName (nameObektivParam inputValue) { obektiv= inputValue; }

nameObektivParam lenseAxisParametr::getObectivName() { return obektiv;}

void lenseAxisParametr::setAxisParametr(Uint8 axisName, float procent, float position,Uint8 point) {
switch (axisName)
        {
case zoomAxis:
    zoomParam.position[point]=position;
    zoomParam.procent[point]=procent;
    return;
case irisAxis:
    irisParam.position[point]=position;
    irisParam.procent[point]=procent;
    return;
case focusAxis:
    focusParam.position[point]=position;
    focusParam.procent[point]=procent;
    return;
    }
}

void lenseAxisParametr::setMaxPoint(Uint8 axisName, Uint8 point) {
    switch (axisName)
            {
    case zoomAxis:
        zoomParam.maxPoint=point;
        return;
    case irisAxis:
        irisParam.maxPoint=point;
        return;
    case focusAxis:
        focusParam.maxPoint=point;
        return;
        }
}



paramLenseAxis lenseAxisParametr::getAxisParametr(Uint8 axisName) {
switch (axisName)
    {
    case zoomAxis:
        return zoomParam;
    case irisAxis:
        return irisParam;
    case focusAxis:
        return focusParam;
    }
}

paramLenseAxis lenseAxisParametr:: aprocsimatorAxis(paramLenseAxis param) {
    if (param.maxPoint==0)
        return param;
    if (param.maxPoint==63)
        return param;
    if (param.procent[param.maxPoint]==100.0) {
        for (Uint8 i=param.maxPoint+1; i<64; i++) {
            param.position[i]=param.position[param.maxPoint];
            param.procent[i]=param.procent[param.maxPoint];
            }
        return param;
    }
    float deltaPos=param.position[param.maxPoint]-param.position[param.maxPoint-1];
    float deltaProc=param.procent[param.maxPoint]-param.procent[param.maxPoint-1];
    for (Uint8 i=param.maxPoint+1; i<64;i++) {
        param.procent[i]=param.procent[i-1]+deltaPos;
        param.position[i]=param.position[i-1]+deltaProc;
        if (param.procent[i]>100.0) {
            //����� �������� �����������
            float aproximationLiner=100.0-param.procent[i-1];
            aproximationLiner/=deltaProc;
            aproximationLiner*=deltaPos;
            param.procent[i]=100.0;
            param.position[i]=param.position[i-1]+aproximationLiner;
            deltaProc=0;
            deltaPos=0;
            }
        }
    return param;
    }

