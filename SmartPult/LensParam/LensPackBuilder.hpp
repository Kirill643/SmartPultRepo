/*
 * LensPackBuilder.hpp
 *
 *  Created on: 27 ����. 2019 �.
 *      Author: KapustinIV
 */

#ifndef MODULES_LENSDB_LENSPACKBUILDER_HPP_
#define MODULES_LENSDB_LENSPACKBUILDER_HPP_

#include "LensData.hpp"
#include "LensPack.hpp"
#include "Libs/ExchangeLib/Data/OutSerial.hpp"
#include "Libs/Containers/String.hpp"
#include "LensCrc.hpp"

namespace LensDb {

enum {addrWriteSize=0};

template<size_t maxPackLen>
class LensPackBuilder
{
private:
    LensPack & pack;
public:
    LensPackBuilder(LensPack & pack): pack(pack) {
    }
    inline void buildPack(LensObjective& lensObjective) {
        ExchangeLib::OutSerial outBytes(&pack[0], pack.getSize(),headerSize);
        uint8_t sizeName=lensObjective.name().getLength()+1;
        outBytes.write<uint8_t>(sizeName);//����� ������ �����
        outBytes.write<const char>(&lensObjective.name()[0], lensObjective.name().getLength());//����� ���
        char endStr='\0';
        outBytes.write<char>(endStr);
        writeAxis(lensObjective.zoom(), outBytes);//����� ���
        writeAxis(lensObjective.iris(), outBytes);//����� ���������
        writeAxis(lensObjective.focus(), outBytes);//����� �����
        uint16_t sizeWritedCount=outBytes.getWritedCount();
        outBytes.setOffset(addrWriteSize);
        outBytes.write<uint16_t>(sizeWritedCount);
        uint16_t crc = findCrc(&pack[0], sizeWritedCount); //������� ����������� �����
        outBytes.setOffset(sizeWritedCount);
        outBytes.write<uint16_t>(crc); //����� ����������� �����
    }
private:

    inline void writeAxis(LensAxis& axis, ExchangeLib::OutSerial& outBytes) {
        uint8_t pointsCount = axis.getSize();
        LensPoint* points =  axis.points();
        outBytes.write<uint8_t>(pointsCount); //����� ���������� �����
        outBytes.write<LensPoint>(points, pointsCount);//����� �����
    }
};

} /* namespace LensDb */

#endif /* MODULES_LENSDB_LENSPACKBUILDER_HPP_ */
