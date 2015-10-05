
#ifndef RING_BUFFER_H_INCLUDED
#define RING_BUFFER_H_INCLUDED

/*
    We may read more than one Packet of the same type in the same telegram.
    Hence we store them in ringbuffers and record the number of valid packets in the Counter struct.
*/
struct RingBuffer
{
    ...
};

typedef struct RingBuffer RingBuffer;

#endif // RING_BUFFER_H_INCLUDED

