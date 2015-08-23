//***********************************************************************************
// LxT831.h
// 
//***********************************************************************************

#pragma once

/// pulled from ld_types.h
//
typedef char                           int8;
typedef unsigned char                  uint8;
typedef unsigned char                  byte;   
typedef unsigned char                  BYTE;
typedef short                          int16;
typedef unsigned short                 uint16;
typedef int                            int32;
typedef unsigned int                   uint32;
typedef long long                      int64;
typedef unsigned long long             uint64;

/// end of ld_types.h

/// pulled from LxtCommDefs.h
//
// session log flags
#define PRM_ACTION_STOP                0x0001 // Stop action performed
#define PRM_ACTION_RUN                 0x0002 // Run
#define PRM_ACTION_PAUSE               0x0004 // Pause
#define PRM_ACTION_RESUME              0x0008 // Resume from Pause
#define PRM_ACTION_VOICE               0x0010 // Voice Recording
#define PRM_ACTION_AUDIO               0x0020 // Audio Recording {reserved for future}
#define PRM_ACTION_CAL                 0x0040 // Calibration record, need deviation stored also! {reserved for future}
#define PRM_ACTION_RESET               0x0080 // Reset {reserved for future}
#define PRM_ACTION_GPS_SYNC            0x0081 // GPS Time Sync
#define PRM_BACK_ERASE                 0x0082 // Back Erase Session Log
#define PRM_ACTION_MARKER              0x0083 // Marker set
#define PRM_ACTION_CALCHG              0x0084 // Calibration Change Performed
#define PRM_ACTION_PREAMPOFF           0x0085 // Preamp Removed (show type of preamp removed)
#define PRM_ACTION_PREAMPON            0x0086 // Preamp Connected (show type of preamp connected)
#define PRM_ACTION_FILE_AVG            0x0087 // Create a new average in the data explorer
#define PRM_ACTION_WATCHDOG            0x0088 // Phoenix watchdog reset

#define PRM_ACTION_RUN_RA_SHIFT_LEFT        2 // Run Mode for Room Acoustic shift left of RA_Run_Mode and add to PRM_ACTION_RUN
#define PRM_ACTION_RUN_MASK            0x00E3 // This mask works to detect PRM_ACTION_RUN for these cases also:
// Note: these must remain unique and not interfere with any other codes above
#define PRM_ACTION_RUN_RA_MODE_L1      0x0006 // 1<<2+2: Run Measuring RTA spectrum for L1
#define PRM_ACTION_RUN_RA_MODE_L2      0x000A // 2<<2+2: Run Measuring RTA spectrum for L2
#define PRM_ACTION_RUN_RA_MODE_B2      0x000E // 3<<2+2: Run Measuring RTA spectrum for B2
#define PRM_ACTION_RUN_RA_MODE_T2      0x0012 // 4<<2+2: Run Measuring RT60 Event and Spectral Time History
#define PRM_ACTION_RUN_RA_MODE_TH      0x0016 // 5<<2+2: Run Measuring RTA Time History (spectra for background noise analysis)

#define PRM_ACTION_MASK                0x00FF // mask for ACTION flags

#define PRM_CAUSE_KEY                  0x0100 // action caused by keyboard command     //SR Events Cause
#define PRM_CAUSE_IO                   0x0200 // action caused by I/O command               // SR Measurement
#define PRM_CAUSE_TIMER                0x0400 // action caused by the run or stable timer //SR Markers
#define PRM_CAUSE_POWER                0x0800 // stop due to power failure
#define PRM_CAUSE_MEMORY               0x1000 // stop due to out-of-memory
#define PRM_CAUSE_PREAMP_CONNECT       0x2000 // stop due to preamp connect
#define PRM_CAUSE_PREAMP_DISCONNECT    0x4000 // stop due to preamp disconnect
#define PRM_CAUSE_STABLE               0x8000 // stop on STABLE
#define PRM_CAUSE_831_INT_ET           0x8100 // Phoenix communications watchdog via 831 INTET
#define PRM_CAUSE_ANALOGMODEM          0x8200 // Phoenix UsbHost watchdog via Analog Modem
#define PRM_CAUSE_MASK                 0xFF00 // mask for CAUSE flags

//cause flags for markers (prm_action_marker)
#define PRM_CAUSE_MARKER1              0x0100
#define PRM_CAUSE_MARKER2              0x0200
#define PRM_CAUSE_MARKER3              0x0300
#define PRM_CAUSE_MARKER4              0x0400
#define PRM_CAUSE_MARKER5              0x0500
#define PRM_CAUSE_MARKER6              0x0600
#define PRM_CAUSE_MARKER7              0x0700
#define PRM_CAUSE_MARKER8              0x0800
#define PRM_CAUSE_MARKER9              0x0900
#define PRM_CAUSE_MARKER10             0x0a00

//gps time sync cause
#define PRM_CAUSE_GPS_POSITIVE         0x0100
#define PRM_CAUSE_GPS_NEGATIVE         0x0200


#define TAG_FIRMWARE                   0x00020000 
#define TAG_MODEL                      0x00020001
#define TAG_SERIALNUM                  0x00020002
#define TAG_REVISION                   0x00020003
#define TAG_RUNRECORDS                 0x00020004 
#define TAG_FREEMEM                    0x00020005
#define TAG_BATTERY                    0x00020006
#define TAG_STATUS                     0x00020007
#define TAG_GETOPTIONS                 0x00020008
#define TAG_SETOPTIONS                 0x00020009
#define TAG_STATUSFORMAT               0x0002000a
#define TAG_PREAMPTYPE                 0x0002000b
#define TAG_CALCHECK_STATUS            0x0002000c
#define TAG_GETOPTIONMASK              0x0002000d
#define TAG_SETOPTIONMASK              0x0002000e
#define TAG_SILICON                    0x0002000f
#define TAG_GETNUMSETTINGS             0x00020010
#define TAG_CONNECTEX_AVAILABLE        0x00020011
#define TAG_INSTRUMENT_INDEX           0x00020012
#define TAG_MODEM_CONNECTED            0x00020013
#define TAG_LASTBYTESREAD              0x00020014
#define TAG_STATUS_EX                  0x00020015
#define TAG_SYSCONSTANTS               0x00020016
#define TAG_FIRMWARE_STRING            0x00020a01
#define TAG_SBC_CONNECTED              0x00020a02
#define TAG_SBC_FIRMWARE               0x00020a03 
#define TAG_INBOOTMODE                 0x00020a04 
#define TAG_PREAMP_METRICS             0x00020a05

#define TAG_SET_PROGRESS               0X00040001 // these are used to set a hwnd for a progress dialog
#define TAG_UNSET_PROGRESS             0X00040002

#define CMD_CONNECT                    0x00030001
#define CMD_DISCONNECT                 0x00030002
#define CMD_LOADSECTOR                 0x00030003
// this one is to set the ui used flag in the Lxt so the User is warned not to open the dialogs
// When 831Util is connected.
#define CMD_SETLXTUI                   0x00030005
// enahnced USB connect. Waits for meter to be out of bootloader before returning.
#define CMD_CONNECTEX                  0x00030006

#define LDM_NOTIFY                     (WM_USER + 1)  // ProgDlg.cpp
#define LDM_NOTIFYEX                   (WM_USER + 2)  // ProgDlg.cpp
#define LUR_NOTIFY                     (WM_USER + 3)  // tcpipsbc.cpp
#define LUR_ROM_UPGRADE                (WM_USER + 4)  // tcpipsbc.cpp
#define WM_BEGINUPLOAD                 (WM_USER + 425)   // UploadFirmwareDlg.cpp
#define WM_PLAYSTREAM                  (WM_USER + 600)   // LiveStreamDlg.h
#define WM_STOPSTREAM                  (WM_USER + 601)  // LiveStreamDlg.h
#define WM_DATASTREAM                  (WM_USER + 602)  // LiveStreamDlg.h
#define WM_WAVMNGR_CREATE              (WM_USER + 700)  // WaveManager.h
#define WM_WAVMNGR_WRITE               (WM_USER + 701)  // WaveManager.h
#define WM_WAVMNGR_CLOSE               (WM_USER + 702)  // WaveManager.h
#define WM_WAVMNGR_ENDTHREAD           (WM_USER + 703)  // WaveManager.h
#define WM_FOLDERSEL                   (WM_USER + 1001) // filedlg.h
#define LDM_PUMPMESSAGES               (WM_USER + 5522)  // SlmComm.h
#define LDM_DEVICEREMOVED              (WM_USER + 0x1427)  // MainFrm.h
#define LDM_PROGRAMFIRMWARE            (WM_USER + 0x1428)  // MainFrm.h
#define LDM_REFORMATINSTRUMENT         (WM_USER + 0x1429)  // MainFrm.h
#define LDM_SHOWSCREENGRABBER          (WM_USER + 0x1430)  // MainFrm.h
#define LDM_SHOWLIVESTREAM             (WM_USER + 0x1431)  // MainFrm.h
#define LDM_CHANGEMODE                 (WM_USER + 0x1432)  // MainFrm.h
#define LDM_SHOWMANAGER                (WM_USER + 0x1433)  // MainFrm.h
#define LDM_PROGRAMSBC                 (WM_USER + 0x1434)  // MainFrm.h
#define LDM_INITIALIZE                 (WM_USER + 0x1457)  // MgrDownloadDlg.cpp
#define LDM_TRANSLATORNOTIFY           (WM_USER + 0x7FFF)  // Translator.cpp  (also defined in TranslatorProgDlg.cpp)

#define PACKETSIZE                     102400
#define PACKETSIZE100K                 102400
#define PACKETSIZE20K                  20480
#define PACKETSIZE5K                   5120
#define PACKETSIZEUSB                  PACKETSIZE100K
#define PACKETSIZERS232                PACKETSIZE5K
#define PACKETSIZEMODEM                PACKETSIZE5K
#define PACKETSIZETCPIP                5516	// MSS = 1380; need a even multiple so this is 4xMSS minus 4 for embedded ACK

/// end of LxTCommDefs.h


/// pulled from slm_tags.h
//*****************************************************************************
// Room Acoustics Control Tags

#define TAG_INSTRUMENT_MODE            'IM01'

#define TAG_RA_EXIT_TIME               'EX01'
#define TAG_RA_LOWEST_FREQ             'LF01'
#define TAG_RA_HIGHEST_FREQ            'HF01'
#define TAG_TIE_SOURCE_TO_CONTROL      'TS01'

#define TAG_RT60_NOISE_TYPE            'NT01'
#define TAG_RT60_NOISE_ATTENUATION     'NA01'
#define TAG_RT60_METHOD                'RTM1'
#define TAG_RT60_TRIGGER_SOURCE        'TRG2'
#define TAG_RT60_TRIGGER_LEVEL         'TRG3'
#define TAG_RT60_BANDWIDTH             'BW01'
#define TAG_RT60_BUILD_TIME            'BT01'
#define TAG_RT60_RUN_TIME              'RT02'
#define TAG_RT60_RUN_COUNT             'RC01'
#define TAG_RT60_SAMPLE_PERIOD         'SP01'
#define TAG_SAVE_AVERAGE_TIME_SERIES   'SVTA'
#define TAG_SAVE_ALL_TIME_SERIES       'SVTS'

#define TAG_VHEAT_STATE                'VH01'
#define TAG_VHEAT_ENA_TIME             'VH02'
#define TAG_VHEAT_DIS_TIME             'VH03'

//*****************************************************************************
// FFT Control Tags

#define TAG_FFT_WINDOW_TYPE            'FFT1'
#define TAG_FFT_FREQSPAN               'FFT2'
#define TAG_FFT_NUM_LINES              'FFT3'
#define TAG_FFT_RUN_MODE               'FFT4'
#define TAG_TONE_1996_2                'FFT5'
#define TAG_TONE_SEEK_DELTA            'FFT6'
#define TAG_REGRESSION_SPAN            'FFT7'


// ***********************************************************************************
//   Control Tags

// Date:Time
#define TAG_DATE_TIME                  'DT01'
// New Date:Time
#define TAG_DATE_TIME_EX               'DT02'
// Alarm Data:Time
#define TAG_ALARM                      'AL01'
// Measurement Mode
#define TAG_RUN_MODE                   'RM01'
// RunTimer
#define TAG_RUN_TIME                   'RM02'
// Stabel Timer
#define TAG_STABLE_TIME                'RM03'
// Stable Level
#define TAG_STABLE_LEVEL               'RM04'


// These are all new Run mode control settings for the 831 // Enable measurement History
#define TAG_MEASUREMENT_HISTORY        'RM05'
//Number of times to run the timed stop
#define TAG_MEASUREMENT_COUNTS         'RM06'
//Interval time
#define TAG_INTERVAL_TIME              'RM07'
//Enable daily auto-store
#define TAG_DAILY_STORE                'RM08'
//Enable Interval Clock Synchronization
#define TAG_INTERVAL_CLOCK_SYNC        'RM09'
//Start Date for Timers
#define TAG_TIMER_START_DATE           'RM10'
//Stop Date for Timers
#define TAG_TIMER_STOP_DATE            'RM11'
//Start Time 1 for timers
#define TAG_TIMER_START_TIME_1         'RM12'
//Start Time 2 for timers
#define TAG_TIMER_START_TIME_2         'RM13'
//Start Time 3 for timers
#define TAG_TIMER_START_TIME_3         'RM14'
//Stop Time 1 for timers
#define TAG_TIMER_STOP_TIME_1          'RM15'
//Stop Time 2 for timers
#define TAG_TIMER_STOP_TIME_2          'RM16'
//Stop Time 3 for timers
#define TAG_TIMER_STOP_TIME_3          'RM17'
//Number of timed runs during one day
#define TAG_NUM_BLOCK_TIMERS           'RM18'  // 0 ONE BLOCK, 1 TWO BLOCKS, 3 THREE BLOCKS
//Time to store daily data
#define TAG_DAILY_STORE_TIME           'RM19'
// ENABLE DAILY CAL CHECK
#define TAG_DAILY_CAL_CHECK            'RM20'
// DAILY CAL CHECK TIME
#define TAG_CAL_CHECK_TIME             'RM21'
// Enable Saving of the Ln Table in Measument History
#define TAG_LN_TABLE_ENABLE            'RM22'

// Lock Mode
#define TAG_LOCK_MODE                  'LK01'
// Lock Calibrate
#define TAG_LOCK_CAL                   'LK02'
// Lock Task Mode
#define TAG_LOCK_TASK                  'LK03'
// Lock Combination
#define TAG_LOCK_COM                   'LK04'
// Power Auto-OFF
#define TAG_POWER_OFF_TIME             'PW01'
// Power Auto-Sleep
#define TAG_POWER_SLEEP_TIME           'PW02'
// Power Back Light Timer
#define TAG_POWER_LIGHT_TIME           'PW03'
// Power Back Light Level
#define TAG_POWER_LIGHT                'PW04'
// Power Battery Type
#define TAG_POWER_BATT                 'PW05'
// Power External Battery Shutoff Voltage
#define TAG_POWER_EXT_SHUTOFF          'PW06'
//
#define TAG_OUTPUTS                    'OU01'
// Display Contrast
#define TAG_DISPLAY_CONTRAST           'DP01'
// Display Format Decimal Point
#define TAG_DISPLAY_DECIMAL            'DP02'
// Display Format Date
#define   TAG_DISPLAY_DATE             'DP03'
// AutoSyncDateTime
#define TAG_AUTOSYNC                   'DP04'
// User String 1
#define TAG_USER_STRING_1              'US01'
// User String 2
#define TAG_USER_STRING_2              'US02'
// User String 3
#define TAG_USER_STRING_3              'US03'
// MeasurementDescription
#define TAG_MDESC                      'MD01'
// Overall Title String
#define TAG_OVERALL_TITLE              'OT01'
// Defualt File Name
#define TAG_FILE_NAME                  'FN01'
// CurrentFileIndex
#define TAG_CURRENT_FILE_INDEX         'FN02'
// Defualt File Name Extension
#define TAG_FILE_EXTENSION             'FN03'
// Check data file exits
#define TAG_FILE_EXISTS                'FN04'
// Auto Store Mode
#define TAG_AUTO_STORE                 'AS01'
// Reset Prompt
#define TAG_RESET_PROMPT               'RP01'
// Language Selection
#define TAG_LANGUAGE                   'LG01'
// Overwrite Old files
#define TAG_OVERWRITE_OLD_FILES        'OOF1'
// Ltm5   enable
#define TAG_LTM5_ENABLE                'LTM5'
// Compress Data files
#define TAG_COMPRESS_DATA_FILES        'CDF1'
// USB Storage
#define TAG_USB_STORAGE                'USB1'
// Full Octave Reference Spectra
#define TAG_FULL_OCTAVE_REFERENCE_SPECTRA1   'FRS1'
#define TAG_FULL_OCTAVE_REFERENCE_SPECTRA2   'FRS2'
#define TAG_FULL_OCTAVE_REFERENCE_SPECTRA3   'FRS3'
#define TAG_FULL_OCTAVE_REFERENCE_SPECTRA4   'FRS4'
//Third Octave Reference Spectra
#define TAG_THIRD_OCTAVE_REFERENCE_SPECTRA1  'TRS1'
#define TAG_THIRD_OCTAVE_REFERENCE_SPECTRA2  'TRS2'
#define TAG_THIRD_OCTAVE_REFERENCE_SPECTRA3  'TRS3'
#define TAG_THIRD_OCTAVE_REFERENCE_SPECTRA4  'TRS4'

#define TAG_CALSCALE                   'CA01'
#define TAG_CALDATE                    'CA02'
#define TAG_SENSITIVITY                'CA03'

#define NUM_CALIBRATORS                 5

#define TAG_CALIBRATOR_LEVEL_1         'CB01'
#define TAG_CALIBRATOR_LEVEL_2         'CB02'
#define TAG_CALIBRATOR_LEVEL_3         'CB03'
#define TAG_CALIBRATOR_LEVEL_4         'CB04'

#define TAG_CALIBRATOR_FREQ_1          'CBF1'
#define TAG_CALIBRATOR_FREQ_2          'CBF2'
#define TAG_CALIBRATOR_FREQ_3          'CBF3'
#define TAG_CALIBRATOR_FREQ_4          'CBF4'

#define TAG_CALIBRATOR_STRING_1        'CBS1'
#define TAG_CALIBRATOR_STRING_2        'CBS2'
#define TAG_CALIBRATOR_STRING_3        'CBS3'
#define TAG_CALIBRATOR_STRING_4        'CBS4'

// User certification paramters
#define TAG_CERTIFICATION_INTERVAL     'CT01'
#define TAG_CERTIFICATION_REMIND       'CT02'
//  TEST MODE ONLY. Ceritification parameters
#define TAG_CERTIFICATION_XTIME        'CT00'
#define TAG_CERTIFICATION_STRING_1     'CTS1'
#define TAG_CERTIFICATION_STRING_2     'CTS2'
#define TAG_CERTIFICATION_STRING_3     'CTS3'
#define TAG_CERTIFICATION_STRING_4     'CTS4'
#define TAG_CERTIFICATION_STRING_5     'CTS5'

#define TAG_RANDOMCORRECTION           'RD01'

// Frequency Weighting
#define TAG_FREQ_WEIGHTING             'FW01'
// Detector Weighting
#define TAG_DET_WEIGHING               'DW01'
// Integration Input
#define TAG_INTEGRATION_INPUT          'DW02'
// SLM Gain
#define TAG_SLM_GAIN                   'GN00'

// Peak Frequency Weighting
#define TAG_PEAK_WEIGHTING             'PW10'

// History Period
#define TAG_HIST_PERIOD                'HP01'

// Sample Rate
#define TAG_SAMPLE_RATE                'SR01'

#define TAG_SR_RANGE                   'SR02'

// N's
#define TAG_LN                         'LN02'

// Bandwidth
#define TAG_OBA_BANDWIDTH              'OB02'
// Start Filter
#define TAG_OBA_START                  'OB03'
// End Filter
#define TAG_OBA_END                    'OB04'
// Range
#define TAG_OBA_RANGE                  'OB05'
// Input Filtering
#define TAG_OBA_WEIGHTING              'OB06'
// OBA Maximum Spectrum Mode
#define TAG_OBA_MAX_MODE               'OB07'


#define DOSE_CHANNELS                  2
// Dose Threshold
#define TAG_DOSE_THRESHOLD             'DS02'
// Dose Exchange Rate
#define TAG_DOSE_EXCHANGE_RATE         'DS03'
// Dose Criterion Level
#define TAG_DOSE_C_LEVEL               'DS04'
// Dose Criterion Time
#define TAG_DOSE_C_TIME                'DS05'
// Dose Name
#define TAG_DOSE_NAME                  'DS06'
// Dose Threshold Enable
#define TAG_DOSE_THRESHOLD_ENABLE      'DS07'

// for normalized spectra
#define NUM_REFERENCE_SPECTRA          4
#define FULLOCTAVE_BINS                12
#define THIRDOCTAVE_BINS               36

// Event Trigger Level
#define TAG_EVENT_LEVEL                'EV02'
// Event Trigger Frequency Weighting
#define TAG_EVENT_FREQ_WEIGHTING       'EV03'
// Event Trigger Detector Weighting + Peakoption
#define TAG_EVENT_DET_WEIGHING         'EV04'
// New Tags for 831
// Exceed Min duration
#define TAG_EVENT_MIN_DURATION         'EV05'
// Exceedance continuation period
#define TAG_EVENT_CONT_PERIOD          'EV06'
// Dynamic Trigger Offset
#define TAG_EVENT_DYN_TRIG_OFFSET      'EV07'
// Dynamic Response
#define TAG_EVENT_DYNAMIC_RESPONSE     'EV08'
// Exceedance trigger method
#define TAG_EVENT_TRIG_METHOD          'EV09'
// Exceedance TH period
#define TAG_EVENT_TH_PERIOD            'EV10'
// Audio snapshot period
#define TAG_EVENT_SNAPSHOT_PERIOD      'EV11'
// Audio snapshot pre-trigger period
#define TAG_EVENT_PRETRIGGER_PERIOD    'EV12'
// Enable Exceedance History
#define TAG_EVENT_HISTORY_ENABLE       'EV13'
// Enable exceedance time history
#define TAG_EVENT_TH_ENABLE            'EV14'
// Enable audio snapshot
#define TAG_EVENT_SNAPSHOT_ENABLE      'EV15'
// Enable Exceedance TH spectra
#define TAG_EVENT_TH_SPECTRA_ENABLE    'EV16'
//Narsi Added these tags
// Samples to be collected
#define TAG_EVENT_TH_MAX_SAMPLES       'EV17'
// pretrig period
#define TAG_EVENT_TH_PRE_TRIG          'EV18'
// post trigger count
#define TAG_EVENT_TH_POST_TRIG         'EV19'


// Save Measurement Audio Snapshot
#define TAG_MEASUREMENT_SNAPSHOT_ENABLE 'MS01'
// Measurement Audio Snapshot Period
#define TAG_MEASUREMENT_SNAPSHOT_PERIOD 'MS02'
// Save Measurement Level Distribution Table

#define TAG_SNAPSHOT_SAMPLING_RATE     'MS04'

#define TAG_MEASUEMENT_LEVEL_TABLE     'MS03'


// Voice Message Compression setting
#define TAG_VOICE_COMPRESSION          'VM01'

//Enable Time History
#define TAG_TIME_HISTORY_ENABLE        'TH01'
//Time History Period
#define TAG_TIME_HISTORY_PERIOD        'TH02'
//Time History Options
#define TAG_TIME_HISTORY_OPTIONS       'TH03'
//Time History Misc. Options
#define TAG_TIME_HISTORY_MISC          'TH04'
// for setting THFlags3
#define TAG_TIME_HISTORY_OPTIONS3      'TH05'


//Enable Short Time History
#define TAG_SHORT_TIME_HISTORY_ENABLE  'TH11'
//Time History Period
#define TAG_SHORT_TIME_HISTORY_PERIOD  'TH12'
//Time History Options
#define TAG_SHORT_TIME_HISTORY_OPTIONS 'TH13'

//Enable Stream History
#define TAG_STREAM_HISTORY_ENABLE      'TH21'
//Time History Period
#define TAG_STREAM_HISTORY_PERIOD      'TH22'
//Time History Options
#define TAG_STREAM_HISTORY_OPTIONS     'TH23'

///////////////////////////////////////////////////////////////////////////////
// markers
#define NUM_MARKERS                    10
#define TAG_MARKER_NAMES               'MK01'   ///< Marker Names
#define TAG_MARKER_AUDIO_RECORD        'MK02'   ///< Marker Audio Record
#define TAG_MARKER_PRERECORD_PERIOD    'MK03'   ///< Marker Prerecord Period
#define TAG_MARKER_RECORD_PERIOD       'MK04'   ///< Marker record Period

// day/might (community noise)
#define TAG_DAY_TIME                   'DN01'   ///< LDN & LDEN Day Start Time
#define TAG_EVENING_TIME               'DN02'   ///< LDEN Evening Start Time
#define TAG_NIGHT_TIME                 'DN03'   ///< LDN & LDEN Night Start Time
#define TAG_EVENING_PENALTY            'DN04'   ///< LDEN Evening Penalty
#define TAG_NIGHT_PENALTY              'DN05'   ///< LDN & LDEN Night Penalty
#define TAG_NIGHT_PENALTY_OLD          'DB05'   ///< LDN & LDEN Night Penalty Old to maintain compatability with slm server(uses old)
#define TAG_SPECTRAL_LN                'LN03'   ///< Spectral  Ln Mode
#define TAG_GRAPH_RELATIVE             'GR01'   ///< LDN & LDEN Night Penalty

// Analog Modem Communication
#define TAG_MODEM_PHONE_NO             'MOD1'
#define TAG_MODEM_PASSWD               'MOD2'
#define TAG_MODEM_MONITER_NO           'MOD3'
#define TAG_MODEM_MODEM_INIT           'MOD4'
#define TAG_MODEM_ON_OFF               'MOD5'
#define TAG_MODEM_DIAL_OUT             'MOD6'

// Edge Modem (GPRS) settings
#define TAG_WIRELESS_ON_OFF            'GPR1'
#define TAG_WIRELESS_APN               'GPR2'
#define TAG_WIRELESS_USR_NAME          'GPR3'
#define TAG_WIRELESS_APNPASSWD         'GPR4'
#define TAG_WIRELESS_PASSWD            'GPR5'
#define TAG_WIRELESS_MONITOR_NUM       'GPR6'

// GPS MODE
#define TAG_GPS_MODE                   'GPS1'

// UNITS
#define TAG_UNIT_CONV                  'UNT1'

// TIMEZONE CORRECTION
#define TAG_TIMEZONECORRECTION_HRS     'TZH1'
#define TAG_TIMEZONECORRECTION_MIN     'TZM1'

// Mic Corrections

// display options
#define TAG_STARTUPTAB                 'STT1'
#define TAG_DISPLAYOPTIONS1            'DSP1'
#define TAG_DISPLAYOPTIONS2            'DSP2'
#define TAG_DISPLAYOPTIONS3            'DSP3'
#define TAG_DISPLAYOPTIONS4            'DSP4'
#define TAG_DISPLAYOPTIONS5            'DSP5'
#define TAG_DISPLAYOPTIONS6            'DSP6'
#define TAG_DISPLAYOPTIONS7            'DSP7'
#define TAG_DISPLAYOPTIONS8            'DSP8'

#define TAG_MIC_SENSITIVITY            'SMS1'
#define TAG_MIC_NOISE_FLOOR            'SMNF'
#define TAG_MIC_INFO                   'SMIN'

#define TAG_USB_HOST_POWER             'UHPW'

#define TAG_FULL_REF_SP1               'FRN1'
#define TAG_FULL_REF_SP2               'FRN2'
#define TAG_FULL_REF_SP3               'FRN3'
#define TAG_FULL_REF_SP4               'FRN4'
#define TAG_THRD_REF_SP1               'TRN1'
#define TAG_THRD_REF_SP2               'TRN2'
#define TAG_THRD_REF_SP3               'TRN3'
#define TAG_THRD_REF_SP4               'TRN4'

#define TAG_LOGIC_IN                   'LOIN'
#define TAG_LOGIC_OUT                  'LOUT'

#define TAG_WIND_SCALE                 'WND1'
#define TAG_WIND_UNITS                 'WND2'
#define TAG_WIND_DIRECTION             'WND3'
#define TAG_WIND_THRESHOLD             'WND4'
#define TAG_WIND_LEVEL                 'WND5'
#define TAG_WIND_HYSTERESIS            'WND6'
#define TAG_WIND_PAUSE                 'WND7'

#define TAG_ADC1_SCALE                 'AD11'
#define TAG_ADC1_OFFSET                'AD12'
#define TAG_ADC1_UNITS                 'AD13'
#define TAG_ADC1_DESCRIPTION           'AD14'

#define TAG_ADC2_SCALE                 'AD21'
#define TAG_ADC2_OFFSET                'AD22'
#define TAG_ADC2_UNITS                 'AD23'
#define TAG_ADC2_DESCRIPTION           'AD24'

#define TAG_WEATHER_ENABLE             'AD01'

#define TAG_ALL_CONTROLS               'CO01'
#define TAG_ALL_PREFERENCES            'CO02'
#define TAG_ALL_SYSTEMS                'CO03'

#define TAG_RS232_ON_OFF               'RS01'
#define TAG_RS232_BAUD                 'RS02'

#define TAG_BLUETOOTH_ON_OFF           'BT01'

// mask options
#define TAG_MASK_OPTION                'MSK0'

// SMS
#define TAG_SMS_OUT_TYPE1              'SOT1'
#define TAG_SMS_OUT_TYPE2              'SOT2'
#define TAG_SMS_OUT_TYPE3              'SOT3'
#define TAG_SMS_NONE                   'SMNO'
#define TAG_SMS_EVENT                  'SMEV'
#define TAG_SMS_LOWMEM                 'SMLM'
#define TAG_SMS_SMSIN                  'SMSI'
#define TAG_SMS_ALL                    'SMAL'
#define TAG_SMS_OUT_NUMBER1            'SON1'
#define TAG_SMS_OUT_NUMBER2            'SON2'
#define TAG_SMS_OUT_NUMBER3            'SON3'

#define TAG_PHOENIX_STATE              'PHNX'

#define TAG_PRM2103_HEATER             'P3HT'

#define TAG_NETWORK_PASSWORD           'NPWD'

/// end of slm_tags.h

/// pulled from io_control_codes.h
/******************************************************************************
   Commands Function 01
******************************************************************************/

#define CMD_NOP                        0
#define CMD_RESET                      1
#define CMD_RECONFIGURE                2

#define CMD_ENABLE                     9
#define CMD_DISABLE                    10

#define CMD_RUN                        256
#define CMD_STOP                       257
#define CMD_TRIGGER                    258
#define CMD_LOAD_TEDS                  260
#define CMD_TEST                       261
#define CMD_DATA_LATCH                 262
#define CMD_STORE                      263
#define CMD_SETTING_STORE              264
#define CMD_DEL_SETTINGFILE            265
#define CMD_SETTING_FILENAME           266
#define CMD_EA_TURNON                  267
#define CMD_EA_TURNOFF                 268
#define CMD_CALCHECK_INIT              269
#define CMD_CALCHECK_END               270
#define CMD_CALCHECK_STR_STD           271

#define CMD_INITIALIZE                 514
#define CMD_WAKE                       515
#define CMD_SLEEP                      516
#define CMD_UPLOAD_ROM_FILE            517
#define CMD_DELETE_ROM_FILE            518
#define CMD_UPGRADE_ROM                519
#define CMD_REBOOT_831_INT_ET          520
#define CMD_UPLOAD_SBCDAEMON_FILE      521
#define CMD_DELETE_SBCDAEMON_FILE      522
#define CMD_UPGRADE_SBCDAEMON          523

#define CMD_VCXO_STEP                  0x807D // send int32 number to step from -99 to +99
#define PRM_VCXO_WRITE_ENABLE          100

#define CMD_TESTMODE_DISABLE           0x807E
#define CMD_TESTMODE_ENABLE            0x807F
#define CMD_SAVE_CALIBRATION           0x8080
#define CMD_TOGGLE_PRESENT             0x8084
#define CMD_PRM2103_SN_WRITE           0x8085

// Bootloader command - not valid for LxT app except REBOOT
#define CMD_FLASH_TO_RAM               0x80A0
#define CMD_RAM_TO_FLASH               0x81A1
#define CMD_INVALIDATE_RAM             0x82A2
#define CMD_EXIT_LOADER                0x83A2
#define CMD_REBOOT                     0x83A3
#define CMD_ERASE_FLASH                0x9454
#define CMD_RAM_TO_FLASH_STATUS        0x81A2


#define CMD_FORMAT                     0x9110
#define CMD_RECALL                     0x9111
#define CMD_DELETE                     0x9112
#define CMD_RENAME                     0x9113
#define CMD_LATCH_SETTINGS             0x9114
#define CMD_DELETE_ALL                 0x9115
#define CMD_FORMAT_831_BY_SBC          0x9116

// Keys are inserted by CMD_KEY | keycode.  The keycode is one byte
#define CMD_KEY                        0xAA00
#define CMD_LASTKEY                    0xAAFF

/// end of io_control_codes.h

/// pulled from slm_channels.h
//
typedef enum {
   GROUP_SYSTEM_COMMAND = 0,
   GROUP_SLM_CURRENT,  // 1
   GROUP_SLM_HISTORY,  // 2
   GROUP_SLM_OVERALL,  // 3
   GROUP_STAT_HISTORY, // 4
   GROUP_STAT_OVERALL, // 5
   GROUP_OBA11,        // 6
   GROUP_OBA13,        // 7
   GROUP_DOSE_1,       // 8
   GROUP_DOSE_2,       // 9
   GROUP_EVENT_1,      // 10
   GROUP_EVENT_2,      // 11
   GROUP_EVENT_3,      // 12
   GROUP_EVENT_4,      // 13
   GROUP_EVENT_5,      // 14
   GROUP_MARKER_1,     // 15
   GROUP_MARKER_2,     // 16
   GROUP_MARKER_3,     // 17
   GROUP_MARKER_4,     // 18
   GROUP_MARKER_5,     // 19
   GROUP_MARKER_6,     // 20
   GROUP_MARKER_7,     // 21
   GROUP_MARKER_8,     // 22
   GROUP_MARKER_9,     // 23
   GROUP_MARKER_10,    // 24
   GROUP_STREAM,       // 25
   GROUP_FFT           // 26
} Group_t;

/// end of slm_channels.h

/// pulled from defines.h

// RMS, Peak and detector settings
#define ID_RMS_A                       1
#define ID_RMS_C                       2
#define ID_RMS_Z                       3
#define ID_PEAK_C                      2
#define ID_PEAK_A                      4
#define ID_PEAK_Z                      5
#define ID_DETECTOR_FAST               1
#define ID_DETECTOR_SLOW               2
#define ID_DETECTOR_IMPL               3
// slm integration mode
#define ID_LINEAR                      0
#define ID_EXPONENTIAL                 1
// units
#define UNITS_SI                       0
#define UNITS_ENGLISH                  1
// wind direction
#define WINDDIR_COMPASS	               0
#define WINDDIR_DEGREES                1
#define WINDDIR_PERCENT                2
#define WINDDIR_VOLTS                  3
// yes/no boolean
#define ID_NO                          0
#define ID_YES                         1
// weather settings
#define WEATHER_NONE                   0
#define WEATHER_INT                    1
#define WEATHER_VAISALA                2
// periodic autostore settings
#define PAS_NEVER                      0
#define PAS_1PERDAY                    1
#define PAS_2PERDAY                    2
#define PAS_4PERDAY                    3
#define PAS_6PERDAY                    4
#define PAS_8PERDAY                    5
#define PAS_12PERDAY                   6
#define PAS_24PERDAY                   7
// exceedence spectral time history enable settings
#define ESTH_OFF                       0
#define ESTH_ON                        1
// spectral ln mode
#define SPECLN_OFF                     0
#define SPECLN_ON                      1
// exceedence trigger methods //future
#define TRIGGER_LEVEL                  0
#define TRIGGER_DYNAMIC                1
// usb storage options
#define USB_NO                         0
#define USB_AUTO                       1
// slm gain settings (831 only)
#define GAIN_0                         0
#define GAIN_20                        1
// oba bandwiths settings
#define OBA_OFF                        0
#define OBA_OCTAVE                     1
#define OBA_THIRD                      2
#define OBA_OCTAVE_THIRD               3	
// oba max spectrum modes
#define OBA_ATLMAX                     0
#define OBA_ATBINMAX                   1
// oba frequency weighting modes
#define OBA_FREQWTA                    0
#define OBA_FREQWTC                    1
#define OBA_FREQWTZ                    2
// slm oba range
#define ID_NORMAL                      0
#define ID_LOW                         1
// adc channels
#define ADC1                           0
#define ADC2                           1
// slm display options
#define ID_PERIOD                      0
#define ID_COMMA                       1
#define ID_YEARFIRST                   0
#define ID_DAYFIRST                    1
// run mode settings
#define RUNMANUAL                      0
#define RUNMEASTIME                    1
#define RUNSTABLE                      2
#define RUNCONTINUOUS                  3
#define RUNBLOCKTIMER                  4
#define RUNDAILYTIMER                  5
#define ONETIMER                       0
#define TWOTIMER                       1
#define THREETIMER                     2
// slm trigger methods
#define ID_LEVEL                       0
#define ID_DYNAMIC                     1

// exceedance trigger methods
#define TRIGGER_LEVEL                  0
#define TRIGGER_DYNAMIC                1

// USB Storage options
#define USB_NO                         0
#define USB_AUTO                       1

// slm gain settings (831 only)
#define GAIN_0                         0
#define GAIN_20                        1

// Exceedance spectral time history enable settings
#define ESTH_OFF                       0
#define ESTH_ON                        1

// Spectral Ln Mode
#define SPECLN_OFF                     0
#define SPECLN_ON                      1

// Generic ON/OFF
#define DEVICE_OFF                     0
#define DEVICE_ON                      1

// modem modes
#define MODEM_OFF                      0
#define MODEM_ON                       1

// modem modes
#define EDGE_MODEM_OFF                 0
#define EDGE_MODEM_ON                  1

#define DIALOUT_NONE                   0
#define DIALOUT_EXCD                   1
#define DIALOUT_ALARM                  2
#define DIALOUT_BOTH                   3

// RS-232 Modes
#define RS232_OFF                      0
#define RS232_ON                       1

// Baudrate Modes
#define BR9600                         0
#define BR115200                       3
#define BR57600                        2
#define BR19200                        1

// Bluetooth Modes
#define BLUETOOTH_OFF                  0
#define BLUETOOTH_ON                   1

// Flow Control Modes
#define ID_NONE                        0
#define ID_HARDWARE                    1
#define ID_XONOFF                      2

// Units
#define UNITS_SI                       0
#define UNITS_ENGLISH                  1

// GPS mode
#define GPSMODE_OFF                    0
#define GPSMODE_ON                     1
#define GPSMODE_AUTO                   2

// deprecated
//// RI correction
//#define RI_OFF                         0
//#define RI_RI2FF                       1
//#define RI_FF2RI                       2

// sound recorder range
#define SRRANGE_LOW                    0
#define SRRANGE_HIGH                   1

// USB PORT Switch for the hardware change
#define USBPORT_OFF                    0
#define USBPORT_ON                     1

// LogicIO settings  Any changes here must be in TEDS too : t_LogicOut and t_LogicIn
#define LOGICIN_NONE                   0
#define LOGICIN_RUNSTOP                1
#define LOGICIN_EVENT                  2
#define LOGICIN_ALARM                  3
#define LOGICOUT_OFF                   0
#define LOGICOUT_RUNSTATE              1
#define LOGICOUT_EVENT                 2

// SMS
#define SMS_NONE                       0
#define SMS_EVENT                      1
#define SMS_MEMLOW                     2
#define SMS_SMSIN                      3
#define SMS_ALL                        4
#define SMS_ALARM                      5

// Weather Stations
#define ID_WEATHERNONE                 0
#define ID_WEATHERINT                  1
#define ID_WEATHERVAISALA              2

// Daily Auto-Store Settings
#define DS_NEVER                       0  // Never auto-store daily
#define DS_1                           1  // auto-store once daily
#define DS_2                           2  // auto-store 2 times daily
#define DS_4                           3  // auto-store 4 times daily
#define DS_6                           4  // auto-store 6 times daily
#define DS_8                           5  // auto-store 8 times daily
#define DS_12                          6  // auto-store 12 times daily
#define DS_24                          7  // auto-store 24 times daily

// period settings for TimeHistoryPeriod and ExceedanceTimeHistoryPeriod
#define ID_50PS                        0  // 50 per second (20ms)
#define ID_20PS                        1  // 20 per second (50ms)
#define ID_10PS                        2  // 10 per second (100ms)
#define ID_5PS                         3  // 5 per second (200ms)
#define ID_2PS                         4  // 2 per second (500ms)
#define ID_1S                          5
#define ID_2S                          6
#define ID_5S                          7
#define ID_10S                         8
#define ID_15S                         9
#define ID_20S                         10
#define ID_30S                         11
#define ID_1MIN                        12
#define ID_2MIN                        13
#define ID_5MIN                        14
#define ID_10MIN                       15
#define ID_15MIN                       16
#define ID_20MIN                       17
#define ID_30MIN                       18
#define ID_1HR                         19
#define ID_24HR                        20
#define ID_400PS                       21 // 400 per second (2.5ms)
#define ID_200PS                       22 // 200 per second (5ms)
#define ID_100PS                       23 // 100 per second (10ms)

// period settings for StreamHistoryPeriod, see nStreamPeriod
#define SHP_20mS                        0  // TAG_50Hz
#define SHP_50mS                        1  // TAG_20Hz
#define SHP_100mS                       2  // TAG_10Hz
#define SHP_200mS                       3  // TAG_4Hz
#define SHP_500mS                       4  // TAG_2Hz
#define SHP_1S                          5  // TAG_1Sec
#define SHP_2S                          6  // TAG_2Sec
#define SHP_5S                          7  // TAG_5Sec
#define SHP_10S                         8  // TAG_10Sec
#define SHP_15S                         9  // TAG_15Sec
#define SHP_20S                        10  // TAG_20Sec
#define SHP_30S                        11  // TAG_30Sec
#define SHP_1MIN                       12  // TAG_1Min
#define SHP_2500uS                     13  // TAG_400Hz
#define SHP_5mS                        14  // TAG_200Hz
#define SHP_10mS                       15  // TAG_100Hz

// sound recorder sample rates
#define SR_SAMPLERATE48                0
#define SR_SAMPLERATE24                1
#define SR_SAMPLERATE16                2
#define SR_SAMPLERATE8                 3

//TimeHistoryOptions1
#define ID_TH_LEQ                      0x00000001
#define ID_TH_LPEAK                    0x00000002
#define ID_TH_SPL                      0x00000004
#define ID_TH_LMAX                     0x00000008
#define ID_TH_LMIN                     0x00000010
#define ID_TH_LTM5                     0x00000020
#define ID_TH_LTWA1                    0x00000040
#define ID_TH_LTWA2                    0x00000080
#define ID_TH_LTWA3                    0x00000100
#define ID_TH_LTWA4                    0x00000200
#define ID_TH_ALEQ                     0x00000400
#define ID_TH_APEAK                    0x00000800
#define ID_TH_ASLOWSPL                 0x00001000
#define ID_TH_ASLOWMAX                 0x00002000
#define ID_TH_ASLOWMIN                 0x00004000
#define ID_TH_AFASTSPL                 0x00008000
#define ID_TH_AFASTMAX                 0x00010000
#define ID_TH_AFASTMIN                 0x00020000
#define ID_TH_AIMPLSPL                 0x00040000
#define ID_TH_AIMPLMAX                 0x00080000
#define ID_TH_AIMPLMIN                 0x00100000
#define ID_TH_CLEQ                     0x00200000
#define ID_TH_CPEAK                    0x00400000
#define ID_TH_CSLOWSPL                 0x00800000
#define ID_TH_CSLOWMAX                 0x01000000
#define ID_TH_CSLOWMIN                 0x02000000
#define ID_TH_CFASTSPL                 0x04000000
#define ID_TH_CFASTMAX                 0x08000000
#define ID_TH_CFASTMIN                 0x10000000
#define ID_TH_CIMPLSPL                 0x20000000
#define ID_TH_CIMPLMAX                 0x40000000
#define ID_TH_CIMPLMIN                 0x80000000

// TimeHistoryOptions2
#define ID_TH_ZLEQ                     0x00000001
#define ID_TH_ZPEAK                    0x00000002
#define ID_TH_ZSLOWSPL                 0x00000004
#define ID_TH_ZSLOWMAX                 0x00000008
#define ID_TH_ZSLOWMIN                 0x00000010
#define ID_TH_ZFASTSPL                 0x00000020
#define ID_TH_ZFASTMAX                 0x00000040
#define ID_TH_ZFASTMIN                 0x00000080
#define ID_TH_ZIMPLSPL                 0x00000100
#define ID_TH_ZIMPLMAX                 0x00000200
#define ID_TH_ZIMPLMIN                 0x00000400
#define ID_TH_BATTERY                  0x00000800
#define ID_TH_EXTPOWER                 0x00001000
#define ID_TH_INTTEMP                  0x00002000
#define ID_TH_2102TEMPERATURE          0x00004000
#define ID_TH_2102HUMIDITY             0x00008000
#define ID_TH_WINDSPD                  0x00010000
#define ID_TH_GUSTDIR                  0x00020000
#define ID_TH_ADC1AVG                  0x00040000
#define ID_TH_ADC2AVG                  0x00080000
#define ID_TH_CMINUSA                  0x00100000
#define ID_TH_OBALEQ_UNUSED            0x00200000
#define ID_TH_OBALMAX_UNUSED           0x00400000
#define ID_TH_OBASPL_UNUSED            0x00800000
#define ID_TH_OBASPL11                 0x01000000
#define ID_TH_OBALEQ11                 0x02000000
#define ID_TH_OBAMAX11                 0x04000000
#define ID_TH_OBAMIN11                 0x08000000
#define ID_TH_OBASPL13                 0x10000000
#define ID_TH_OBALEQ13                 0x20000000
#define ID_TH_OBAMAX13                 0x40000000
#define ID_TH_OBAMIN13                 0x80000000

// TimeHistoryOptions3
#define ID_TH_GUSTSPEED                0x00000001
#define ID_TH_ADC1MAX                  0x00000002
#define ID_TH_ADC1MIN                  0x00000004
#define ID_TH_ADC2MAX                  0x00000008
#define ID_TH_ADC2MIN                  0x00000010
// reserved for future weather metrics
#define ID_TH_WEATHER1                 0x00000020
#define ID_TH_WEATHER2                 0x00000040
#define ID_TH_WEATHER3                 0x00000080
#define ID_TH_WEATHER4                 0x00000100
#define ID_TH_WEATHER5                 0x00000200
#define ID_TH_WEATHER6                 0x00000400
// option to save fractional portion of duration
#define ID_TH_DUR_FRAC                 0x00000800
// options for LXT-HSLOG option (OPT_LXT_HSLOG)
#define ID_TH_WSLOWSPL                 0x00001000
#define ID_TH_WFASTSPL                 0x00002000
#define ID_TH_WIMPLSPL                 0x00004000
#define ID_TH_WIMPLMINUSLEQ            0x00008000
// options to save broadband Ln statistics
#define ID_TH_LN1                      0x00010000
#define ID_TH_LN2                      0x00020000
#define ID_TH_LN3                      0x00040000
#define ID_TH_LN4                      0x00080000
#define ID_TH_LN5                      0x00100000
#define ID_TH_LN6                      0x00200000
#define ID_TH_LN_ENABLES               (ID_TH_LN1 | ID_TH_LN2 | ID_TH_LN3 | ID_TH_LN4 | ID_TH_LN5 | ID_TH_LN6)

// bit values for the streaming data option flag
#define ID_STH_ALEQ                    0x00000001
#define ID_STH_APEAK                   0x00000002
#define ID_STH_ASLOWSPL                0x00000004
#define ID_STH_AFASTSPL                0x00000008
#define ID_STH_AIMPLSPL                0x00000010
#define ID_STH_CLEQ                    0x00000020  
#define ID_STH_CPEAK                   0x00000040
#define ID_STH_CSLOWSPL                0x00000080
#define ID_STH_CFASTSPL                0x00000100
#define ID_STH_CIMPLSPL                0x00000200
#define ID_STH_ZLEQ                    0x00000400
#define ID_STH_ZPEAK                   0x00000800
#define ID_STH_ZSLOWSPL                0x00001000
#define ID_STH_ZFASTSPL                0x00002000
#define ID_STH_ZIMPLSPL                0x00004000
#define ID_STH_OBALEQ11                0x00008000
#define ID_STH_OBASPL11                0x00010000
#define ID_STH_OBALEQ13                0x00020000
#define ID_STH_OBASPL13                0x00040000
#define ID_STH_FLAGS                   0x00080000
#define ID_STH_WSLOWSPL                0x00100000
#define ID_STH_WFASTSPL                0x00200000
#define ID_STH_WIMPLSPL                0x00400000
#define ID_STH_TMS                     0x00800000

// misc defines
#define FULLOCTAVE                     0
#define THIRDOCTAVE                    1
#define NUM11SPECTRABINS               12
#define NUMSPECTRABINS                 36
#define NUM_OCTAVES                    12
#define NUM_THIRD_OCTAVES              36
#define FULLOCTAVE_BINS                12
#define THIRDOCTAVE_BINS               36
#define NUM_SLM_DOSES                  2
#define NUM_LNS                        6
#define NUM_CALIBRATORS                5
#define NUM_MARKERS                    10
#define NUM_STAT_BINS                  2000
#define NUM_SLM_LN_BINS                (NUM_STAT_BINS + 2)
#define FILENAME_SIZE                  16
#define OVERALLTITLE_SIZE              64
#define MARKER_LEN                     32

// rt60 sample period
#define RT60_SAMPLE_PERIOD_2_5_MS      0  ///< 2.5 mS
#define RT60_SAMPLE_PERIOD_5_MS        1  ///< 5   mS
#define RT60_SAMPLE_PERIOD_10_MS       2  ///< 10  mS
#define RT60_SAMPLE_PERIOD_20_MS       3  ///< 20  mS

// Output Jack
#define OUTPUT_OFF                     0    // Off output state
#define OUTPUT_ACDC                    1    // AC/DC output state
#define OUTPUT_HEADSET                 2    // Headset output state

// Noise Types
#define NOISE_NONE                     0
#define NOISE_WHITE                    1
#define NOISE_PINK                     2

// Link the source display to this noise control set
#define LINK_TO_NONE                   0
#define LINK_TO_RT60                   1
#define LINK_TO_RTA                    2

// RT-60 Methods
#define RT60_METHOD_IMPULSE            0
#define RT60_METHOD_INTERRUPTED        1

// Bandwidth
#define BAND_OCTAVE                    1  ///< WARNING: This MUST be 1 because of bit-wise operations in the code
#define BAND_THIRD_OCTAVE              2  ///< WARNING: This MUST be 2 because of bit-wise operations in the code
#define BAND_BOTH                      3  ///< BAND_BOTH = BAND_OCTAVE | BAND_THIRD_OCTAVE

// Trigger Source (Frequency Bandwidth or Band)
// * indicates filters that are generally used for 1/3 octave room acoustics
// # indicates filters that are generally used for 1/1 octave room acoustics
#define F_Z_WGHT                        0 ///< Z Weight broadband
#define F_MID_BAND                      1 ///< Midband Filters[27:37], energy sum
#define F_6_3                           2 ///< Filter  8
#define F_8                             3 ///< Filter  9
#define F_10                            4 ///< Filter 10
#define F_12_5                          5 ///< Filter 11
#define F_16                            6 ///< Filter 12
#define F_20                            7 ///< Filter 13
#define F_25                            8 ///< Filter 14
#define F_31_5                          9 ///< Filter 15
#define F_40                           10 ///< Filter 16
#define F_50                           11 ///< Filter 17 *
#define F_63                           12 ///< Filter 18 * #
#define F_80                           13 ///< Filter 19 *
#define F_100                          14 ///< Filter 20 *
#define F_125                          15 ///< Filter 21 * #
#define F_160                          16 ///< Filter 22 *
#define F_200                          17 ///< Filter 23 *
#define F_250                          18 ///< Filter 24 * #
#define F_315                          19 ///< Filter 25 *
#define F_400                          20 ///< Filter 26 *
#define F_500                          21 ///< Filter 27 * #
#define F_630                          22 ///< Filter 28 *
#define F_800                          23 ///< Filter 29 *
#define F_1000                         24 ///< Filter 30 * #
#define F_1250                         25 ///< Filter 31 *
#define F_1600                         26 ///< Filter 32 *
#define F_2000                         27 ///< Filter 33 * #
#define F_2500                         28 ///< Filter 34 *
#define F_3150                         29 ///< Filter 35 *
#define F_4000                         30 ///< Filter 36 * #
#define F_5000                         31 ///< Filter 37 *
#define F_6300                         32 ///< Filter 38 *
#define F_8000                         33 ///< Filter 39 * #
#define F_10000                        34 ///< Filter 40 *
#define F_12500                        35 ///< Filter 41
#define F_16000                        36 ///< Filter 42
#define F_20000                        37 ///< Filter 43

typedef WCHAR UNICHAR;

#define FILENAME_SIZE                  16
#define OVERALLTITLE_SIZE              64
#define MARKER_LEN                     32

#define SZ8                            8
#define SZ16                           16
#define SZ32                           32
#define SZ64                           64
#define SZ128                          128
#define SZ256                          256
#define SZ512                          512

#define MAX_FFT_LINES                  6401

typedef enum enumCmdTypes
{
	ECmdUnknown = 0,
	ECmdGetControl,
	ECmdSetControl,
	ECmdSetOperation,
	ECmdGetInfo,
	ECmdGetData,
	ECmdGetBinaryData,
	ECmdGetDataZModem,
	ECmdMax
};

// instrument type
typedef enum enumMeterType
{
	ETypeUnknown = 0, // INSTRUMENT_TYPE_UNDEFINED
	ETypeLxT,         // INSTRUMENT_TYPE_SLM
	EType831 = 3      // need to set this to 3 for backward compatiblity with INSTRUMENT_TYPE_831 
} EMeterType;

typedef enum enumMeterMode
{
	EModeSLM = 0,			// MODE_SLM in slm_controls.h
	EModeRt60,			   // MODE_ROOM_ACOUSTICS in slm_controls.h
	EModeRA = EModeRt60,	// right now, these are equivilent. decision was made to split RT60 as a completly seperate mode from RA
	EModeFFT,
	EModeMax
} EMeterMode;

typedef enum enumConnectMode
{
	EConnectNone = 0,
	EConnectUSB,
	EConnectRS232,
	EConnectModem,
	EConnectTCPIP,
	EConnectTAPI,
	EConnectSBC,
	EConnectMax
} EConnectMode;

typedef enum enumFftWindowType
{
	EWinHanning = 0,
	EWinFlattop,
	EWinRectangle,
	EWinMax
} EFftWindow;

typedef enum enumFftBandwidth
{
	EFftBand20000 = 0,
	EFftBand10000,
	EFftBand5000,
	EFftBand2000,
	EFftBand1000,
	EFftBand500,
	EFftBand200,
	EFftBand100,
	EFftBandMax
} EFftBandwidth;

typedef enum enumFftLines
{
	ELines6400 = 0,
	ELines3200,
	ELines1600,
	ELines800,
	ELines400,
	ELinesMax
} EFftLines;

typedef enum enumFftRunMode
{
	ERunManual = 0,
	ERunCount,
	ERunTimed,
	ERunMax
} EFftRunMode;

typedef enum enumFftLevels
{
	EFftAvg = 0,
	EFftMax,
	EFftLvlMax
} EFftLevels;

typedef enum enumFftLabels
{
	ELblRecordNum = 0,
	ELblDate,
	ELblTime,
	ELblDur,
	ELblOvld,
	ELblOvldDur,
	ELblCount,
	ELblBroadband,
	ELblFreq,
	ELblMax
} EFftLabels;

typedef enum enumFftTonalityStandard
{
	EToneNone = 0,
	ETone1996_2,
	EToneMax
} EFftTonality;

typedef enum enumToneSeekDelta
{
	E1dB = 0,
	E2dB,
	E3dB,
	E4dB
} EToneSeekDelta;

typedef enum enumRegressionRange
{
	ERange50 = 0,
	ERange75,
	ERange100,
	ERange150,
	ERange200
} ERegressionRange;

typedef enum enumPRM2103HeaterStates
{
   EHeaterOff = 0,
   EHeaterAuto,
   EHeaterLow,
	EHeaterHigh,
	EHeaterInvalid
} EPRM2103HeaterStates;

// convert Volts squared (Vsq) to ?
// added with FFT but may be useful for other modes in the future
typedef enum enumVsqConvert
{
	EVsqAsVsq = 0,    // no conversion
	EVsqAsdB,         // convert to dB
	EVsqAsMax
} EVsqConvert;

// internet connection timeout 
typedef enum enumNetTimeout
{
	ENetShort = 0,
	ENetMedium,
	ENetLong,
	ENetMax
} ENetTimeout;

// RI correction
typedef enum {
	RI_OFF               = 0,
	RI_RI2FF             = 1,
	RI_FF2RI             = 2,
	RI_FF2RI_2106_8      = 3,
	RI_FF2FF_2106_8      = 4,
	RI_FF290_2106_8      = 5,
	RI_NUM_VALUES        = 6
} RI_Correction_t;

typedef enum in_types
{
	IN_DIRECT = 0,    // 0: 831 and LxT
	IN_PRM831,        // 1: 831 only
	IN_ICP,           // 2: could be 426E02 or any device connected to ADP074
	IN_UNKNOWN,       // 3: 831 only
	IN_PRM2102,       // 4: 831 only: 426A12 (the old name was PRM2102)
	// all these (=> NUM_IN_TYPES) use IN_UNKNOWN calibration ()...
	IN_PRM2100,       // 5: 831 only
	IN_PRMLxT1,       // 6: 831 only
	IN_PRMLxT1L,      // 7: 831 only
	IN_PRMLxT2,       // 8: 831 only
	IN_PRMLxT2L,      // 9: 831 only
	IN_PRMLxT2B,      //10: 831 only
	IN_PRM2103,       //11: 831 only
	// synonyms/defines for LxT functions...
	IN_1 = 1,         // 1: LxT only, PRMLxT1
	IN_1L,            // 2: LxT only, PRMLxT1L
	IN_2,             // 3: LxT only, PRMLxT2
	IN_2L,            // 4: LxT only, PRMLxT2L
	// all these (=> NUM_IN_TYPES) use IN_2 or PRMLXT2 calibration ()...
	IN_PRMLxT2BX,     // 5: LxT only
	IN_PRM831X,       // 6: LxT only
	IN_UNKNOWNX       // 7: LxT only
} PreampType_t;

//***********************************************************************************
// translator
//***********************************************************************************
// translator error codes
#define LDFILETYPE_UNKNOWN             0
#define LDFILETYPE_SLMDL               1
#define LDFILETYPE_BINARY              2
#define LDFILETYPE_USBFILE             3

// translator extended error codes
#define EXERROR_PARSE_SREC             1

// translator notification messages
#define TM_BINFILE_SIZE                1
#define TM_BINFILE_CURLOC              2
#define TM_FILECONVERT_SIZE            3
#define TM_FILECONVERT_CURLOC          4
#define TM_POPULATEREC_COUNT           5
#define TM_POPULATEREC_STEP            6
#define TM_ENDTRANSLATION              7
#define TM_FILEREPAIR_BEGIN            8
#define TM_FILEREPAIR_END              9
#define TM_FILEREPAIR_STEP             10

// flags to retrieve all records of a type that have a variable number of records
#define TYPE_BULK_TH                   0
#define TYPE_BULK_EVNT                 1
#define TYPE_BULK_MEAS                 2
#define TYPE_BULK_RUNREC               3
#define TYPE_BULK_VOICE                4
#define TYPE_BULK_AUDIO                5

// flags to retrieve records one at a time.
#define TYPE_ALL                       (-1)
#define TYPE_PREFER                    0
#define TYPE_SETTINGS                  1
#define TYPE_OVERALL                   2 
#define TYPE_LN_TABLE                  3
#define TYPE_SESSION                   4
#define TYPE_AUDIO                     5
#define TYPE_TIMEHIST                  6
#define TYPE_VOICE                     7
#define TYPE_INTERVAL                  8
#define TYPE_EXCEEDENCE                9
#define TYPE_CAL                       10
#define TYPE_NOISEFLOOR                11
#define TYPE_CALHISTORY                12
#define TYPE_EXTENDED_ERROR            13
#define TYPE_BYTIMEAVG                 14
#define TYPE_FFT                       15
#define TYPE_FFTHISTORY                16
#define TYPE_FINISHED                  17

// communication error codes
#define E_FILEOPEN                     _HRESULT_TYPEDEF_(0x8003500AL)
#define E_INSTRUMENTINUSE              _HRESULT_TYPEDEF_(0x8003500BL)
#define E_FAILEDOPENFILE1              _HRESULT_TYPEDEF_(0x8003500CL)
#define E_FAILEDOPENFILE2              _HRESULT_TYPEDEF_(0x8003500DL)
#define E_FAILEDDOWNLOAD               _HRESULT_TYPEDEF_(0x8003500EL)
#define E_SETFILEINDEX                 _HRESULT_TYPEDEF_(0x8003500FL)
#define E_GETFILEINFO                  _HRESULT_TYPEDEF_(0x80035010L)
#define E_CREATETHREAD                 _HRESULT_TYPEDEF_(0x80035011L)
#define E_INVALIDARG1                  _HRESULT_TYPEDEF_(0x80035012L)
#define E_INVALIDARG2                  _HRESULT_TYPEDEF_(0x80035013L)
#define E_INVALIDARG3                  _HRESULT_TYPEDEF_(0x80035014L)
#define E_INVALIDACK                   _HRESULT_TYPEDEF_(0x80035015L)
#define E_INVALIDDIR                   _HRESULT_TYPEDEF_(0x80035016L)
#define E_FAILEDWRITE                  _HRESULT_TYPEDEF_(0x80035017L)
#define E_FAILEDREAD                   _HRESULT_TYPEDEF_(0x80035018L)
#define E_CANCELBYUSER                 _HRESULT_TYPEDEF_(0x80035019L)
#define E_INBOOTLOADER                 _HRESULT_TYPEDEF_(0x8003501AL)

#define DllExport __declspec(dllexport)
#define DllImport __declspec(dllimport)

/// end of defines.h


/// pulled from slm_controls.h
// Option Flags
#define OPT_THIRD_OCTAVE               (0x00000001) // third octave                                (LxT, 831)
#define OPT_ONE_OCTAVE                 (0x00000002) // full octave                                 (LxT, 831)
#define OPT_MESSAGE                    (0x00000004) // voice recording                             (LxT, 831)
#define OPT_AUDIO                      (0x00000008) // audio recording   (hi-fi, baby, yeah!)      (LxT, 831)
#define OPT_EVENTS                     (0x00000010) // exceedance events                           (831)
#define OPT_DATALOGGING                (0x00000020) // datalogging                                 (LxT, 831)
#define OPT_DOSE                       (0x00000040) // dose                                        (LxT, 831)
#define OPT_ANYDATA                    (0x00000080) // a,c,z data                                  (LxT, 831)
#define OPT_INTV                       (0x00000100) // Intervals, Daily, Timed meas. controls      (LxT, 831)
#define OPT_WEATHER                    (0x00000200) // Wind spd, wind dir., Temp., Humidity        (831)
#define OPT_COMMUNITY                  (0x00000400) // community noise (environmental)             (831)
#define OPT_GPS                        (0x00000800) // GPS                                         (831)
#define OPT_HSLOG                      (0x00001000) // High Speed Time Hist                        (LxT)
#define OPT_ENV                        (0x00002000) // Environ Monitoring, Simple Meas. Hist.      (LxT)
#define OPT_FST                        (0x00004000) // FST 2.5ms, 5ms, 10ms                        (831)
#define OPT_WIRELESS_MDM               (0x00008000) // Wireless Modem                              (831)
#define OPT_ANALOG_MDM                 (0x00010000) // Analog Modem                                (831)
#define OPT_ROOMS                      (0x00020000) // Room Acoustics (SIL)                        (831)
#define OPT_QC_TONALITY                (0x00040000) // Tonality for Canadians                      (LxT, 831)
#define OPT_RT60                       (0x00080000) // RT60 (subset of OPT_ROOMS)                  (831)
#define OPT_FFT                        (0x00100000) // FFT                                         (831)
#define OPT_RS232                      (0x00200000) // RS232                                       (831)
#define OPT_FILE_AVERAGING             (0x00400000) // File Averaging                              (831)
#define OPT_NF30_STATS                 (0x00800000) // NF30-101 (France Ln of 25-2k Hz)   ---         NF30-101
#define OPT_FAST_WEATHER               (0x01000000) // Fast Weather Time History          ---         831-FST-WTHR

// legacy names in the firmware were changed to better reflect what the option really is.
// These defines are to maintain backward compatibility with SW that uses this header.
#define OPT_COMM                       (OPT_WIRELESS_MDM)
#define OPT_MDM                        (OPT_ANALOG_MDM | OPT_RS232)

// SettingsLock bits  (StatusFlags)
#define UI_SETNG_SEMAPHORE             0x00000001
#define USB_SETNG_SEMAPHORE            0x00000002
#define UI_AT_BASE_LEVEL               0x00000004
#define UI_NOT_READY                   0x00000008

#define ANALOG_SETNG_SEMAPHORE         0x00000010
#define RS232_SETNG_SEMAPHORE          0x00000020
#define EDGE_SETNG_SEMAPHORE           0x00000040
#define UI_DATA_EXP_OPEN               0x00000080

/// end slm_controls.h

/// pulled from slm_def.h

// slm flags... (LxTFlags)
#define SLM_OPEN                       0x00000001
#define SLM_RUN                        0x00000002  // Running
#define SLM_VALID                      0x00000004  // Data is valid
#define SLM_OVER_NOW                   0x00000008
#define SLM_OVER_ALL                   0x00000010
#define SLM_OVER_BLINK                 0x00000020
#define SLM_OBA_OVER_NOW               0x00000040
#define SLM_OBA_OVER_ALL               0x00000080
#define SLM_OBA_OVER_BLINK             0x00000100
#define SLM_HIGH                       0x00000200
#define SLM_RESET                      0x00000400  // Data reset
#define SLM_PAUSED                     0x00000800  // Paused
#define SLM_RECORD                     0x00001000  // Recording a voice or audio file
#define SLM_PLAY                       0x00002000  // Playing a voice or audio file
#define SLM_SLEEP                      0x00004000  // In power-save mode, analog power is off...
#define SLM_TIMER_END                  0x00008000  // Timed run or until stable run completed
#define SLM_STORED                     0x00010000  // SLM data has been stored to file
#define SLM_STARTED                    0x00020000  // Instrument restarted
#define SLM_REV_C                      0x00040000  // A831.01 Board Revision C or newer
#define SLM_SLM_APP_RDY                0x00080000  // slm app has finished file system checks and is ready
#define SLM_BACK_ERASE                 0x00100000  // Back Erased
#define SOUND_RECORDING                0x00200000  // Sound_Recording is on
#define SLM_LOW_RNG_OVLD               0x00400000  // Low Range channel overloaded, use high range
#define SLM_REV_D                      0x00800000  // A831.01 Board Revision D or newer
#define SLM_FFT_ENABLE                 0x01000000  // FFT Enabled
#define SLM_OBA_UNDER_NOW              0x02000000  // OBA is now Under Range, shown for 1 second minimum
#define SLM_UNDER_NOW                  0x04000000  // Currently Under Range, shown for 1 second minimum
#define SLM_PREAMP_LOW_RG              0x08000000  // Preamp is 'L' type (PRMLxT1L or PRMLxT2L)
#define SLM_PREAMP_TYPE_1              0x10000000  // Type 1 Preamp (PRMLxT1 or PRMLxT1L, else PRMLxT2 or PRMLxT2L)
#define SLM_PREAMP                     0x20000000  // Preamp is attached, else Direct Input
#define SLM_THIRD_ENABLE               0x40000000
#define SLM_OCTAVE_ENABLE              0x80000000

// masks to keep the valid flags for the measurement context...
#define SLM_OA_MASK              (SLM_OCTAVE_ENABLE | SLM_THIRD_ENABLE | SLM_PREAMP | SLM_PREAMP_TYPE_1 | SLM_PREAMP_LOW_RG | SLM_FFT_ENABLE | SLM_REV_D | SLM_REV_C | SLM_RESET | SLM_OBA_OVER_ALL | SLM_OVER_ALL)
#define SLM_MH_MASK              (SLM_OCTAVE_ENABLE | SLM_THIRD_ENABLE | SLM_PREAMP | SLM_PREAMP_TYPE_1 | SLM_PREAMP_LOW_RG | SLM_FFT_ENABLE | SLM_REV_D | SLM_REV_C | SLM_RESET | SLM_OBA_OVER_ALL | SLM_OVER_ALL)
#define SLM_SD_MASK              (SLM_MH_MASK | SLM_UNDER_NOW | SLM_OBA_UNDER_NOW | SLM_STORED |SLM_PAUSED | SLM_OBA_OVER_BLINK | SLM_OBA_OVER_NOW | SLM_OVER_BLINK | SLM_OVER_NOW | SLM_VALID | SLM_RUN)

// Synonyms for other SLM Flags (regardless of SLM mode or not) use one of the above masks before OR'ing these flags...
#define SLM_MH_RA_MODE_MASK      (SLM_OPEN | SLM_RUN) // Matches two lsb of en_RA_Mode so that RA_MODE_L1, RA_MODE_L2 & RA_MODE_B2 can be merged into flags
#define SLM_MH_INCLUDE           (SLM_VALID)          // RA Measurement History Include Flag, 0 for Exclude
#define SLM_SLM_OVERRUN          (SLM_OVER_NOW )      // SLM OA & Measurement History Buffer Overrun Flag
#define SLM_FFT_OVERRUN          (SLM_OBA_OVER_NOW)   // FFT OA & Measurement History Buffer Overrun Flag
#define SLM_FFT_67               (SLM_RECORD)         // FFT OA & Measurement History Overlap 67% Flag
#define SLM_FFT_50               (SLM_PLAY)           // FFT OA & Measurement History Overlap 50% Flag
#define SLM_FFT_33               (SLM_SLEEP)          // FFT OA & Measurement History Overlap 33% Flag
#define SLM_FFT_0                (SLM_TIMER_END)      // FFT OA & Measurement History Overlap 0% Flag
#define SLM_EAON                 (SLM_OPEN)           // TT 5191 - Electrostatic Actuator On Flag - only for streaming data mask SLM_SD_MASK

// RunFlags bits (RunFlags)
#define RUNNING                        0x00000001
#define POST_RESET                     0x00000002
#define POST_RUN                       0x00000004
#define POST_STOP                      0x00000008
#define POST_STOP_INSIDEAPP            0x00000010
#define SOUND_RECORD                   0x00000020  // Sound Record Flag
#define INSTRUMENT_RESTART_WD          0x00000040
#define INSTRUMENT_RESTART             0x00000080
#define POST_PAUSE                     0x00000100
#define PAUSED                         0x00000200
#define POWERING_ON                    0x01000000 // Instrument is powering on
#define DATA_OVERRUN_SLM               0x02000000 // SLM queue over run error
#define DATA_OVERRUN_FFT               0x04000000 // FFT buffer over run error
#define DATA_WAIT                      0x08000000 // Flag to delay run, used for Room Acoustics Exit Time (see RA_ExitCounter)
#define DATA_RESET                     0x10000000 // Overall data has been reset
#define DATA_STORED                    0x20000000 // Data has been stored to a file but not reset
#define RECORD_MESSAGE                 0x40000000
#define DATA_VALID                     0x80000000 // See FILTER_VALID_TIME and filter_init_timer

// NUM_EVENT_COUNTERS -- 2 for SPL and 3 for peak triggers
#define NUM_EVENT_COUNTERS             5

// NUM_STAT_BINS is the number of level bins of 0.1dB resolution used for Ln percentile calculations
#define NUM_STAT_BINS                  2000

// Weather defines...
#define WINDDIRSTATSBINS               8

#define UR_WGHT_A                      0    // WEIGHTING ARRAY INDEX CONSTANTS
#define UR_WGHT_C                      1
#define UR_WGHT_Z                      2
#define UR_WGHT_SIZE                   3

/// end slm_def.h

