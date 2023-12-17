/*
 * ringBuf.h
 *
 *  Created on: Dec 15, 2023
 *      Author: 7osensi
 */

#ifndef RINGBUF_H_
#define RINGBUF_H_

#include "Std_Types.h"

typedef struct{
	u32 len;
	volatile u8* buf;
	volatile u32 read;
	volatile u32 write;
}volatile ringBuffer;

#define ringbuf_write(rb, x) \
  rb.buf[ rb.write ] = x; \
  if ( ( rb.write + 1 ) >= rb.len ) { rb.write = 0; } \
  else { rb.write = rb.write + 1; }

u8 ringbuf_read(ringBuffer* buf) {
	if (buf->read == buf->write ) { return '\0'; }
	  u8 read = buf->buf[ buf->read ];
	  buf->read = ( buf->read < (buf->len - 1)) ? ( buf->read + 1) : 0;
	  return read;
}

#endif /* RINGBUF_H_ */
