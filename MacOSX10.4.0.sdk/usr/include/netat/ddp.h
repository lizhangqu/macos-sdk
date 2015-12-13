/*
 * Copyright (c) 2000 Apple Computer, Inc. All rights reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 * 
 * The contents of this file constitute Original Code as defined in and
 * are subject to the Apple Public Source License Version 1.1 (the
 * "License").  You may not use this file except in compliance with the
 * License.  Please obtain a copy of the License at
 * http://www.apple.com/publicsource and read it before using this file.
 * 
 * This Original Code and all software distributed under the License are
 * distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE OR NON-INFRINGEMENT.  Please see the
 * License for the specific language governing rights and limitations
 * under the License.
 * 
 * @APPLE_LICENSE_HEADER_END@
 */
/*
 *
 * ORIGINS: 82
 *
 * (C) COPYRIGHT Apple Computer, Inc. 1992-1996
 * All Rights Reserved
 *
 */                                                                   

#ifndef _NETAT_DDP_H_
#define _NETAT_DDP_H_
#include <sys/appleapiopts.h>

#ifdef __APPLE_API_OBSOLETE

/* Header and data sizes */

#define  DDP_HDR_SIZE                 5  /* DDP (short) header size */
#define  DDP_X_HDR_SIZE              13  /* DDP extended header size */
#define  DDP_DATA_SIZE              586  /* Maximum DataGram data size */
#define  DDP_DATAGRAM_SIZE          599  /* Maximum DataGram size */

/* DDP socket definitions */

#define  DDP_SOCKET_1st_RESERVED      1  /* First in reserved range */
#define  DDP_SOCKET_1st_EXPERIMENTAL 64  /* First in experimental range */
#define  DDP_SOCKET_1st_DYNAMIC     128  /* First in dynamic range */
#define  DDP_SOCKET_LAST            253  /* Last socket in any range */

/* DDP type used to replace "0" on packets sent out, for compatibility
   with Open Transport */
#define DEFAULT_OT_DDPTYPE 11

/* DDP well-known sockets */

#define RTMP_SOCKET	1	/* RTMP socket number 	*/
#define NBP_SOCKET	2  	/* NIS socket number */
#define	EP_SOCKET	4	/* EP socket number */
#define ZIP_SOCKET	6  	/* ZIP socket number */

/* DDP extended header packet format */

typedef struct {
        unsigned   unused:2,
		   hopcount:4,
		   length:10;  		/* Datagram length */
        ua_short   checksum;    	/* Checksum */
        at_net     dst_net;  		/* Destination network number */
        at_net     src_net;  		/* Source network number */
        at_node    dst_node;  		/* Destination node ID */
        at_node    src_node;  		/* Source node ID */
        at_socket  dst_socket; 		/* Destination socket number */
        at_socket  src_socket; 		/* Source socket number */
        u_char	   type;  		/* Protocol type */
        char       data[DDP_DATA_SIZE];
} at_ddp_t;

#define	DDPLEN_ASSIGN(ddp, len)		ddp->length = len
#define	DDPLEN_VALUE(ddp)		ddp->length

/* DDP module statistics and configuration */

typedef struct at_ddp_stats {
	/* General */

	/* Receive stats */
	u_int	rcv_bytes;
	u_int	rcv_packets;
	u_int	rcv_bad_length;
	u_int	rcv_unreg_socket;
	u_int	rcv_bad_socket;
	u_int	rcv_bad_checksum;
	u_int	rcv_dropped_nobuf;

	/* Transmit stats */
	u_int	xmit_bytes;
	u_int	xmit_packets;
	u_int	xmit_BRT_used;
	u_int	xmit_bad_length;
	u_int	xmit_bad_addr;
	u_int	xmit_dropped_nobuf;
} at_ddp_stats_t;


/* DDP streams module ioctls */

#define	AT_MID_DDP	203

#define DDP_IOC_MYIOCTL(i)      ((i>>8) == AT_MID_DDP)
#define DDP_IOC_GET_CFG        	((AT_MID_DDP<<8) | 1)

#ifdef NOT_USED
#define DDP_IOC_BIND_SOCK	((AT_MID_DDP<<8) | 2)
#define	DDP_IOC_GET_STATS	((AT_MID_DDP<<8) | 3)
#define DDP_IOC_LSTATUS_TABLE	((AT_MID_DDP<<8) | 4)
#define DDP_IOC_ULSTATUS_TABLE	((AT_MID_DDP<<8) | 5)
#define DDP_IOC_RSTATUS_TABLE	((AT_MID_DDP<<8) | 6)
#define DDP_IOC_SET_WROFF	((AT_MID_DDP<<8) | 7 )
#define DDP_IOC_SET_OPTS	((AT_MID_DDP<<8) | 8 )
#define DDP_IOC_GET_OPTS	((AT_MID_DDP<<8) | 9 )
#define DDP_IOC_GET_SOCK	((AT_MID_DDP<<8) | 10)
#define DDP_IOC_GET_PEER	((AT_MID_DDP<<8) | 11)
#define DDP_IOC_SET_PEER	((AT_MID_DDP<<8) | 12)
#define DDP_IOC_SET_PROTO	((AT_MID_DDP<<8) | 13)
#endif

#endif /* __APPLE_API_OBSOLETE */
#endif /* _NETAT_DDP_H_ */