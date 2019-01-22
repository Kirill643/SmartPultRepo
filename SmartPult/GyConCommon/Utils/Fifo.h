#ifndef FIFO__H
#define FIFO__H

//typedef FifoStruct {
//
//} FifoStruct

//������ ������ ���� �������� ������: 4,8,16,32...128
#define Fifo( size )\
  struct {\
    UInt8 buf[size];\
    UInt8 tail;\
    UInt8 head;\
  }

//���������� ��������� � �������
#define Fifo_count(fifo)     (fifo.head-fifo.tail)

//������ fifoFifo_count
#define Fifo_size(fifo)      ( sizeof(fifo.buf)/sizeof(fifo.buf[0]) )

//fifo ���������?
#define Fifo_isFull(fifo)   (Fifo_count(fifo)==Fifo_size(fifo))

//fifo �����?
#define Fifo_isEmpty(fifo)  (fifo.tail==fifo.head)

//���������� ���������� ����� � fifo
#define Fifo_space(fifo)     (Fifo_size(fifo)-Fifo_count(fifo))

//��������� ������� � fifo
#define Fifo_push(fifo, byte) \
  {\
    fifo.buf[fifo.head & (Fifo_size(fifo)-1)]=byte;\
    fifo.head++;\
  }

//����� ������ ������� �� fifo
#define Fifo_front(fifo) (fifo.buf[fifo.tail & (Fifo_size(fifo)-1)])

//��������� ���������� ��������� � �������
#define Fifo_pop(fifo)   \
  {\
      fifo.tail++; \
  }

//�������� fifo
#define Fifo_flush(fifo)   \
  {\
    fifo.tail=0;\
    fifo.head=0;\
  }

#endif //FIFO__H
