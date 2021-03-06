#pragma once

#ifndef __2610INTF_H__
#define __2610INTF_H__

#include "fm.h"


void ym2610_update_request(void *param);

typedef struct _ym2610_interface ym2610_interface;
struct _ym2610_interface
{
	void ( *handler )( const device_config *device, int irq );	/* IRQ handler for the YM2610 */
};

READ8_DEVICE_HANDLER( ym2610_r );
WRITE8_DEVICE_HANDLER( ym2610_w );

READ8_DEVICE_HANDLER( ym2610_status_port_a_r );
READ8_DEVICE_HANDLER( ym2610_status_port_b_r );
READ8_DEVICE_HANDLER( ym2610_read_port_r );

WRITE8_DEVICE_HANDLER( ym2610_control_port_a_w );
WRITE8_DEVICE_HANDLER( ym2610_control_port_b_w );
WRITE8_DEVICE_HANDLER( ym2610_data_port_a_w );
WRITE8_DEVICE_HANDLER( ym2610_data_port_b_w );


DEVICE_GET_INFO( ym2610 );
DEVICE_GET_INFO( ym2610b );

#define SOUND_YM2610 DEVICE_GET_INFO_NAME( ym2610 )
#define SOUND_YM2610B DEVICE_GET_INFO_NAME( ym2610b )

#endif /* __2610INTF_H__ */
