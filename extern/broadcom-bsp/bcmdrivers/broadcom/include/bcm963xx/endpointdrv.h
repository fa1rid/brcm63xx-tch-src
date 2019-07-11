/****************************************************************************
*
* <:copyright-BRCM:2014:DUAL/GPL:standard
* 
*    Copyright (c) 2014 Broadcom 
*    All Rights Reserved
* 
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License, version 2, as published by
* the Free Software Foundation (the "GPL").
* 
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* 
* A copy of the GPL is available at http://www.broadcom.com/licenses/GPLv2.php, or by
* writing to the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
* Boston, MA 02111-1307, USA.
* 
* :>
*
 ***************************************************************************
 * File Name  : EndpointDrv.h
 *
 * Description: This file contains the definitions and structures for the
 *              Linux IOCTL interface that used between the user mode Endpoint
 *              API library and the kernel Endpoint API driver.
 *
 * Updates    : 04/04/2002  YD.  Created.
 ***************************************************************************/

#if !defined(_ENDPOINTDRV_H_)
#define _ENDPOINTDRV_H_

#if defined(__cplusplus)
extern "C" {
#endif

/* Includes. */
#include <bcmtypes.h>
#include <vrgEndpt.h>

/* Maximum size for the event data passed with the event callback */
#define MAX_EVENTDATA_SIZE    256

/* Maximum size of the string that can be printed from user-space (including NULL character) */
#define MAX_PRINTF_SIZE       4050

typedef enum
{
   IOCTL_STATUS_FAILURE = -1,
   IOCTL_STATUS_SUCCESS =  0,
   IOCTL_STATUS_SHUTDOWN,
   IOCTL_STATUS_EMPTY,
   IOCTL_STATUS_DEBUG,
} IOCTL_STATUS;


typedef enum ENDPOINTIOCTL_INDEX
{
   ENDPTIO_INIT_INDEX = 0,
   ENDPTIO_DEINIT_INDEX,
   ENDPTIO_CREATE_INDEX,
   ENDPTIO_DESTROY_INDEX,
   ENDPTIO_CAPABILITIES_INDEX,
   ENDPTIO_SIGNAL_INDEX,
   ENDPTIO_CREATE_CONNECTION_INDEX,
   ENDPTIO_MODIFY_CONNECTION_INDEX,
   ENDPTIO_DELETE_CONNECTION_INDEX,
   ENDPTIO_MUTE_CONNECTION_INDEX,
   ENDPTIO_LINK_INTERNAL_INDEX,
   ENDPTIO_PACKET_INDEX,
   ENDPTIO_GET_PACKET_INDEX,
   ENDPTIO_GET_EVENT_INDEX,
   ENDPTIO_GET_CODECMAP_INDEX,
   ENDPTIO_VOICESTAT_INDEX,
   ENDPTIO_ISINITIALIZED_INDEX,
   ENDPTIO_CONSOLE_CMD_INDEX,
   ENDPTIO_TEST_INDEX,
   ENDPTIO_ENDPOINTCOUNT_INDEX,
   ENDPTIO_FXSENDPOINTCOUNT_INDEX,
   ENDPTIO_FXOENDPOINTCOUNT_INDEX,
   ENDPTIO_DECTENDPOINTCOUNT_INDEX,
   ENDPTIO_ISPSTNLIFELINESUPPORTED_INDEX,
   ENDPTIO_NTR_CMD_INDEX,
   ENDPTIO_HOOKSTAT_INDEX,
   ENDPTIO_SEND_CAS_EVT_INDEX,
   ENDPTIO_SET_RELAY_INDEX,
   ENDPTIO_PRINTF_INDEX,
   ENDPTIO_PROV_SET_INDEX,
   ENDPTIO_PROV_GET_INDEX,
   ENDPTIO_PROBE_SET_INDEX,
   ENDPTIO_PROBE_GET_INDEX,
   ENDPTIO_GET_RTP_STATS_INDEX,
#if defined(BRCM_IDECT_CALLMGR) || defined(BRCM_EDECT_CALLMGR)
   ENDPTIO_DECT_INFO_INDEX,
   ENDPTIO_DECT_HS_INFO_INDEX,
   ENDPTIO_DECT_GET_NVS_INDEX,
   ENDPTIO_DECT_SET_NVS_INDEX,
#endif /* BRCM_IDECT_CALLMGR || BRCM_EDECT_CALLMGR */

   ENDPTIO_MAX_INDEX
} ENDPOINTIOCTL_INDEX;


/* Defines. */
#define ENDPOINTDRV_MAJOR            209 /* arbitrary unused value */

#define ENDPOINTIOCTL_ENDPT_INIT \
    _IOWR(ENDPOINTDRV_MAJOR, ENDPTIO_INIT_INDEX, ENDPOINTDRV_INIT_PARAM)

#define ENDPOINTIOCTL_ENDPT_DEINIT \
    _IOWR(ENDPOINTDRV_MAJOR, ENDPTIO_DEINIT_INDEX, ENDPOINTDRV_INIT_PARAM)

#define ENDPOINTIOCTL_ENDPT_CREATE \
    _IOWR(ENDPOINTDRV_MAJOR, ENDPTIO_CREATE_INDEX, ENDPOINTDRV_CREATE_PARM)

#define ENDPOINTIOCTL_ENDPT_DESTROY \
    _IOWR(ENDPOINTDRV_MAJOR, ENDPTIO_DESTROY_INDEX, ENDPOINTDRV_DESTROY_PARM)

#define ENDPOINTIOCTL_ENDPT_CAPABILITIES \
    _IOWR(ENDPOINTDRV_MAJOR, ENDPTIO_CAPABILITIES_INDEX, ENDPOINTDRV_CAP_PARM)

#define ENDPOINTIOCTL_ENDPT_SIGNAL \
    _IOWR(ENDPOINTDRV_MAJOR, ENDPTIO_SIGNAL_INDEX, ENDPOINTDRV_SIGNAL_PARM)

#define ENDPOINTIOCTL_ENDPT_CREATE_CONNECTION \
    _IOWR(ENDPOINTDRV_MAJOR, ENDPTIO_CREATE_CONNECTION_INDEX, ENDPOINTDRV_CONNECTION_PARM)

#define ENDPOINTIOCTL_ENDPT_MODIFY_CONNECTION \
    _IOWR(ENDPOINTDRV_MAJOR, ENDPTIO_MODIFY_CONNECTION_INDEX, ENDPOINTDRV_CONNECTION_PARM)

#define ENDPOINTIOCTL_ENDPT_DELETE_CONNECTION \
    _IOWR(ENDPOINTDRV_MAJOR, ENDPTIO_DELETE_CONNECTION_INDEX, ENDPOINTDRV_DELCONNECTION_PARM)

#define ENDPOINTIOCTL_ENDPT_MUTE_CONNECTION \
    _IOWR(ENDPOINTDRV_MAJOR, ENDPTIO_MUTE_CONNECTION_INDEX, ENDPOINTDRV_MUTECONNECTION_PARM)

#define ENDPOINTIOCTL_ENDPT_LINK_INTERNAL \
    _IOWR(ENDPOINTDRV_MAJOR, ENDPTIO_LINK_INTERNAL_INDEX, ENDPOINTDRV_LINKINTERNAL_PARM)

#define ENDPOINTIOCTL_ENDPT_PACKET \
    _IOWR(ENDPOINTDRV_MAJOR, ENDPTIO_PACKET_INDEX, ENDPOINTDRV_PACKET_PARM)

#define ENDPOINTIOCTL_ENDPT_GET_PACKET \
    _IOWR(ENDPOINTDRV_MAJOR, ENDPTIO_GET_PACKET_INDEX, ENDPOINTDRV_PACKET_PARM)

#define ENDPOINTIOCTL_ENDPT_GET_EVENT \
    _IOWR(ENDPOINTDRV_MAJOR, ENDPTIO_GET_EVENT_INDEX, ENDPOINTDRV_EVENT_PARM)

#define ENDPOINTIOCTL_ENDPT_GET_CODECMAP \
    _IOWR(ENDPOINTDRV_MAJOR, ENDPTIO_GET_CODECMAP_INDEX, ENDPOINTDRV_CODECMAP_PARM)

#define ENDPOINTIOCTL_ENDPT_VOICESTAT \
    _IOWR(ENDPOINTDRV_MAJOR, ENDPTIO_VOICESTAT_INDEX, ENDPOINTDRV_VOICESTAT_PARM)

#define ENDPOINTIOCTL_ISINITIALIZED \
    _IOWR(ENDPOINTDRV_MAJOR, ENDPTIO_ISINITIALIZED_INDEX, ENDPOINTDRV_ISINITIALIZED_PARM)

#define ENDPOINTIOCTL_ENDPT_CONSOLE_CMD \
    _IOWR(ENDPOINTDRV_MAJOR, ENDPTIO_CONSOLE_CMD_INDEX, ENDPOINTDRV_CONSOLE_CMD_PARM)

#define ENDPOINTIOCTL_TEST \
    _IOWR(ENDPOINTDRV_MAJOR, ENDPTIO_TEST_INDEX, ENDPOINTDRV_TESTPARM)

#define ENDPOINTIOCTL_ENDPOINTCOUNT \
    _IOWR(ENDPOINTDRV_MAJOR, ENDPTIO_ENDPOINTCOUNT_INDEX, ENDPOINTDRV_ENDPOINTCOUNT_PARM)

#define ENDPOINTIOCTL_FXSENDPOINTCOUNT \
    _IOWR(ENDPOINTDRV_MAJOR, ENDPTIO_FXSENDPOINTCOUNT_INDEX, ENDPOINTDRV_ENDPOINTCOUNT_PARM)

#define ENDPOINTIOCTL_FXOENDPOINTCOUNT \
    _IOWR(ENDPOINTDRV_MAJOR, ENDPTIO_FXOENDPOINTCOUNT_INDEX, ENDPOINTDRV_ENDPOINTCOUNT_PARM)

#define ENDPOINTIOCTL_DECTENDPOINTCOUNT \
    _IOWR(ENDPOINTDRV_MAJOR, ENDPTIO_DECTENDPOINTCOUNT_INDEX, ENDPOINTDRV_ENDPOINTCOUNT_PARM)

#define ENDPOINTIOCTL_ISPSTNLIFELINESUPPORTED \
    _IOWR(ENDPOINTDRV_MAJOR, ENDPTIO_ISPSTNLIFELINESUPPORTED_INDEX, ENDPOINTDRV_ISSUPPORTED_PARM)

#define ENDPTIO_NTR_CMD \
    _IOWR(ENDPOINTDRV_MAJOR, ENDPTIO_NTR_CMD_INDEX, ENDPOINTDRV_NTR_PARM)

#define ENDPOINTIOCTL_HOOKSTAT \
    _IOWR(ENDPOINTDRV_MAJOR, ENDPTIO_HOOKSTAT_INDEX, ENDPOINTDRV_HOOKSTAT_CMD_PARM)

#define ENDPOINTIOCTL_SEND_CAS_EVT \
    _IOWR(ENDPOINTDRV_MAJOR, ENDPTIO_SEND_CAS_EVT_INDEX, ENDPOINTDRV_SENDCASEVT_CMD_PARM)

#define ENDPOINTIOCTL_SET_RELAY \
    _IOWR(ENDPOINTDRV_MAJOR, ENDPTIO_SET_RELAY_INDEX, ENDPOINTDRV_RELAY_CMD_PARM)

#define ENDPOINTIOCTL_PRINTF \
    _IOWR(ENDPOINTDRV_MAJOR, ENDPTIO_PRINTF_INDEX, ENDPOINTDRV_PRINTF_PARM)

#define ENDPOINTIOCTL_PROV_SET \
    _IOWR(ENDPOINTDRV_MAJOR, ENDPTIO_PROV_SET_INDEX, ENDPOINTDRV_PROV_PARM)

#define ENDPOINTIOCTL_PROV_GET \
    _IOWR(ENDPOINTDRV_MAJOR, ENDPTIO_PROV_GET_INDEX, ENDPOINTDRV_PROV_PARM)

#define ENDPOINTIOCTL_PROBE_SET \
    _IOWR(ENDPOINTDRV_MAJOR, ENDPTIO_PROBE_SET_INDEX, ENDPOINTDRV_PROBE_PARM)

#define ENDPOINTIOCTL_PROBE_GET \
    _IOWR(ENDPOINTDRV_MAJOR, ENDPTIO_PROBE_GET_INDEX, ENDPOINTDRV_PROBE_PARM)

#define ENDPOINTIOCTL_GET_RTP_STATS \
    _IOWR(ENDPOINTDRV_MAJOR, ENDPTIO_GET_RTP_STATS_INDEX, ENDPOINTDRV_RTP_STATS_PARM)

#if defined(BRCM_IDECT_CALLMGR) || defined(BRCM_EDECT_CALLMGR)
#   define ENDPOINTIOCTL_DECT_INFO \
       _IOWR(ENDPOINTDRV_MAJOR, ENDPTIO_DECT_INFO_INDEX, ENDPOINTDRV_DECT_INFO_CMD_PARM)

#   define ENDPOINTIOCTL_DECT_HS_INFO \
       _IOWR(ENDPOINTDRV_MAJOR, ENDPTIO_DECT_HS_INFO_INDEX, ENDPOINTDRV_DECT_HS_INFO_CMD_PARM)
       
#   define ENDPOINTIOCTL_DECT_GET_NVS \
       _IOWR(ENDPOINTDRV_MAJOR, ENDPTIO_DECT_GET_NVS_INDEX, ENDPOINTDRV_DECT_NVS_CMD_PARM)       

#   define ENDPOINTIOCTL_DECT_SET_NVS \
       _IOWR(ENDPOINTDRV_MAJOR, ENDPTIO_DECT_SET_NVS_INDEX, ENDPOINTDRV_DECT_NVS_CMD_PARM)       
       
#endif /* BRCM_IDECT_CALLMGR || BRCM_EDECT_CALLMGR */


#define MAX_ENDPOINTDRV_IOCTL_COMMANDS   ENDPTIO_MAX_INDEX


typedef struct
{
   UINT32      size;    /* Size of the structure (including the size field) */
   VRG_ENDPT_INIT_CFG *endptInitCfg;
   EPSTATUS    epStatus;
} ENDPOINTDRV_INIT_PARAM, *PENDPOINTDRV_INIT_PARAM;

typedef struct
{
   UINT32   size;       /* Size of the structure (including the size field) */
   UINT32   physId;
   UINT32   lineId;
   VRG_ENDPT_STATE* endptState;
   EPSTATUS epStatus;
} ENDPOINTDRV_CREATE_PARM, *PENDPOINTDRV_CREATE_PARM;

typedef struct
{
   UINT32   size;       /* Size of the structure (including the size field) */
   VRG_ENDPT_STATE* endptState;
   EPSTATUS epStatus;
} ENDPOINTDRV_DESTROY_PARM, *PENDPOINTDRV_DESTROY_PARM;

typedef struct
{
   UINT32   size;       /* Size of the structure (including the size field) */
   EPZCAP*  capabilities;
   ENDPT_STATE* state;
   EPSTATUS epStatus;
} ENDPOINTDRV_CAP_PARM, *PENDPOINTDRV_CAP_PARM;

typedef struct
{
   UINT32      size;    /* Size of the structure (including the size field) */
   ENDPT_STATE* state;
   UINT32      cnxId;
   EPSIG       signal;
   UINT32      value;      // Reserve an array, can be a pointer
   EPSTATUS    epStatus;
   int         duration;
   int         period;
   int         repetition;
} ENDPOINTDRV_SIGNAL_PARM, *PENDPOINTDRV_SIGNAL_PARM;

typedef struct
{
   UINT32      size;    /* Size of the structure (including the size field) */
   ENDPT_STATE* state;
   int         cnxId;
   EPZCNXPARAM*   cnxParam;
   EPSTATUS    epStatus;
} ENDPOINTDRV_CONNECTION_PARM, *PENDPOINTDRV_CONNECTION_PARM;

typedef struct
{
   UINT32         size; /* Size of the structure (including the size field) */
   ENDPT_STATE*   state;
   int            cnxId;
   EPSTATUS       epStatus;
} ENDPOINTDRV_DELCONNECTION_PARM, *PENDPOINTDRV_DELCONNECTION_PARM;

typedef struct
{
   UINT32         size; /* Size of the structure (including the size field) */
   ENDPT_STATE*   state;
   int            cnxId;
   VRG_BOOL       mute;
   EPSTATUS       epStatus;
} ENDPOINTDRV_MUTECONNECTION_PARM, *PENDPOINTDRV_MUTECONNECTION_PARM;

typedef struct
{
   UINT32         size; /* Size of the structure (including the size field) */
   ENDPT_STATE*   state1;
   ENDPT_STATE*   state2;
   VRG_BOOL       link;
   EPSTATUS       epStatus;
} ENDPOINTDRV_LINKINTERNAL_PARM, *PENDPOINTDRV_LINKINTERNAL_PARM;

typedef struct
{
   UINT32   size;       /* Size of the structure (including the size field) */
   ENDPT_STATE*   state;
   int      cnxId;
   EPPACKET*      epPacket;
   int      length;
   UINT32   bufDesc;
   EPSTATUS epStatus;
} ENDPOINTDRV_PACKET_PARM, *PENDPOINTDRV_PACKET_PARM;

typedef struct
{
   UINT32   size;       /* Size of the structure (including the size field) */
   int      lineId;
   int      cnxId;
   int      length;
   EPEVT    event;
   UINT8    eventData[MAX_EVENTDATA_SIZE];
   UINT16   intData;
} ENDPOINTDRV_EVENT_PARM, *PENDPOINTDRV_EVENT_PARM;

typedef struct
{
   UINT32         size; /* Size of the structure (including the size field) */
   int            isInitialized;
} ENDPOINTDRV_ISINITIALIZED_PARM, *PENDPOINTDRV_ISINITIALIZED_PARM;

typedef struct
{
   UINT32         size; /* Size of the structure (including the size field) */
   UINT32         testParm1;
   UINT32         testParm2;
   EPZCNXPARAM*   testParm3;
   EPSTATUS       epStatus;
} ENDPOINTDRV_TESTPARM, *PENDPOINTDRV_TESTPARM;

typedef struct ENDPOINTDRV_PACKET
{
   UINT32   size;       /* Size of the structure (including the size field) */
   int      cnxId;
   int      length;
   EPMEDIATYPE mediaType;
   UINT8    data[1024];
} ENDPOINTDRV_PACKET;

typedef struct ENDPOINTDRV_CONSOLE_CMD_PARM
{
   UINT32         size;       /* Size of the structure (including the size field) */
   ENDPT_STATE*   state;
   int            cmd;
   int            lineId;
   EPCMD_PARMS*   consoleCmdParams;
   EPSTATUS       epStatus;
} ENDPOINTDRV_CONSOLE_CMD_PARM, *PENDPOINTDRV_CONSOLE_CMD_PARM;


typedef struct
{
   UINT32         size; /* Size of the structure (including the size field) */
   int            endpointNum;
} ENDPOINTDRV_ENDPOINTCOUNT_PARM, *PENDPOINTDRV_ENDPOINTCOUNT_PARM;

typedef struct
{
   UINT32         size; /* Size of the structure (including the size field) */
   VRG_BOOL       isSupported;
} ENDPOINTDRV_ISSUPPORTED_PARM, *PENDPOINTDRV_ISSUPPORTED_PARM;

typedef struct
{
   UINT32      size;   /* Size of the structure (including the size field) */
   UINT8       bNtrEnbl;       /* enable / disable feedback state in pcm block */
   INT32       pcmStepsAdjust; /* Number of fine-grain PCM register steps to make (dependent on PCM chip) */
   UINT32      localCount;     /* MIPS counter register reading */
   UINT32      ntrCount;       /* NTR counter register reading */
   UINT32      ndivInt;        /* NDIV_INT register reading */
   UINT32      ndivFrac;       /* NDIV_FRAC register reading */
   EPSTATUS    epStatus;       /* return value */
   UINT8       ntrAction;      /* enum of possible commands (get?/set?/debug_print?)*/
} ENDPOINTDRV_NTR_PARM, *PENDPOINTDRV_NTR_PARM;

typedef struct ENDPOINTDRV_HOOKSTAT_CMD_PARM
{
   UINT32         size;       /* Size of the structure (including the size field) */
   int            lineId;
   EPCASSTATE     hookstat;
   EPSTATUS       epStatus;
} ENDPOINTDRV_HOOKSTAT_CMD_PARM, *PENDPOINTDRV_HOOKSTAT_CMD_PARM;

typedef struct ENDPOINTDRV_SENDCASEVT_CMD_PARM
{
   UINT32                 size;       /* Size of the structure (including the size field) */
   int                    lineId;
   CAS_CTL_EVENT_TYPE     casCtlEvtType;
   CAS_CTL_EVENT          casCtlEvt;
   EPSTATUS               epStatus;
} ENDPOINTDRV_SENDCASEVT_CMD_PARM, *PENDPOINTDRV_SENDCASEVT_CMD_PARM;

typedef struct ENDPOINTDRV_RELAY_CMD_PARM
{
   UINT32         size;       /* Size of the structure (including the size field) */
   int            lineId;
   BOOL           cmd;
   EPSTATUS       epStatus;
} ENDPOINTDRV_RELAY_CMD_PARM, *PENDPOINTDRV_RELAY_CMD_PARM;

typedef struct ENDPOINTDRV_PRINTF_PARM
{
   UINT32         size;
   char           str[MAX_PRINTF_SIZE];
} ENDPOINTDRV_PRINTF_PARM, *PENDPOINTDRV_PRINTF_PARM;

typedef struct ENDPOINTDRV_PROV_PARM
{
   UINT32         size;       /* Size of this structure (including the size field) */
   int            line;
   EPPROV         provItemId;
   void*          provItemValue;
   int            provItemLength;
   EPSTATUS       epStatus;
} ENDPOINTDRV_PROV_PARM, *PENDPOINTDRV_PROV_PARM;

typedef struct ENDPOINTDRV_PROBE_PARM
{
   UINT32         size;       /* Size of this structure (including the size field) */
   int            deviceId;
   int            chan;
   int            reg;
   int            regSize;
   void           *probeValue;
   int            probeValueLength;
   int            indirectness;
   EPSTATUS       epStatus;
} ENDPOINTDRV_PROBE_PARM, *PENDPOINTDRV_PROBE_PARM;

typedef struct
{
   UINT32       size;    /* Size of the structure (including the size field) */
   ENDPT_STATE* state;
   int          cnxId;
   EPZCNXSTATS* stats;
   EPSTATUS     epStatus;
   BOOL         bReset; /* Reset the stats after querying */
} ENDPOINTDRV_RTP_STATS_PARM, *PENDPOINTDRV_RTP_STATS_PARM;

typedef enum
{
   ENDPT_SIGTYPE_EVENT,
   ENDPT_SIGTYPE_PACKET,
} ENDPT_SIGTYPE;

#if defined(BRCM_IDECT_CALLMGR) || defined(BRCM_EDECT_CALLMGR)
typedef struct ENDPOINTDRV_DECT_INFO_CMD_PARM
{
   UINT32           size;

   int              dectStatus;
   int              regWnd;
   char             accessCode[ VRG_DECT__ACCESS_CODE + 1 ];
   unsigned int     version;
   char             linkDate[ VRG_DECT__FW_LINK_DATE + 1 ];
   unsigned char    type;
   char             id[ VRG_DECT__BASE_ID + 1 ];
   unsigned int     manic;
   unsigned int     modic;
   unsigned int     maxHset;
   unsigned int     curHset;

   EPSTATUS         epStatus;

} ENDPOINTDRV_DECT_INFO_CMD_PARM, *PENDPOINTDRV_DECT_INFO_CMD_PARM;


typedef struct ENDPOINTDRV_DECT_HS_INFO_CMD_PARM
{
   UINT32           size;

   int              handsetId;
   int              status;
   unsigned int     timestamp;
   unsigned char    ipui[ VRG_DECT__IPUI ];
   unsigned int     manic;
   unsigned int     modic;

   EPSTATUS         epStatus;

} ENDPOINTDRV_DECT_HS_INFO_CMD_PARM, *PENDPOINTDRV_DECT_HS_INFO_CMD_PARM;


typedef struct ENDPOINTDRV_DECT_NVS_CMD_PARM
{
   UINT32           size;

   unsigned short   offset;
   unsigned short   nvsDataLength;
   unsigned char*   nvsDataPtr;

   EPSTATUS         epStatus;

} ENDPOINTDRV_DECT_NVS_CMD_PARM, *PENDPOINTDRV_DECT_NVS_CMD_PARM;

#endif /* BRCM_IDECT_CALLMGR || BRCM_EDECT_CALLMGR */

#if defined(__cplusplus)
}
#endif

#endif // _ENDPOINTDRV_H_
