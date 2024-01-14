/*
 * ringBuf.h
 *
 *  Created on: Dec 15, 2023
 *      Author: 7osensi
 */

#ifndef RINGBUF_H_
#define RINGBUF_H_

#include "Std_Types.h"

#define RINGBUF_SIZE (128)

typedef enum {
	EV_INIT,
    EV_UART_FRAME_REC
}EventType;

typedef struct {
    EventType type;
}Event;

typedef struct {
	u32 len;
	volatile u8 *buf;
	Event events[RINGBUF_SIZE];
	u32 read;
	u32 write;
}volatile ringBuffer;

#endif /* RINGBUF_H_ */
