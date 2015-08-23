#pragma once

#include "LxT831.h"


#pragma pack(4)

// RA enums and structures
enum MeasurementType
{
   RA_MEASUREMENT_EDT = 0,
   RA_MEASUREMENT_T20,
   RA_MEASUREMENT_T30,
   RA_MEASUREMENT_LEQ,
   RA_MEASUREMENT_LMAX,
   RA_MEASUREMENT_LBK,     // quality background noise
   RA_MEASUREMENT_Co,      // quality - Correlation Coefficients
   RA_MEASUREMENT_Cu,      // quality - Curvature
   RA_MEASUREMENT_SD,      // quality - Standard Deviation
   RA_MEASUREMENT_L1,
   RA_MEASUREMENT_L2,
   RA_MEASUREMENT_B2,
   RA_MEASUREMENT_T2
};


///
typedef struct
{
   float        Cu;
   float        Co_T20;
   float        Co_T30;
   float        SD_T20;
   float        SD_T30;
} RT60_QI_t;


///
typedef struct
{
   uint32   StartPoint;
   uint32   TwentydBPoint;
   uint32   ThirtydBPoint;
   uint32   StopPoint;
} DataLimits_t;

// To support EDT a new DataLimits_t typedef is created called DataLimitsEDT_t;
// It is only used to support EDT
typedef struct {
   uint32   PeakPoint;       // peak value, used as the start point for EDT
   uint32   TendBPoint;      // -10dB point used for EDT
} DataLimitsEDT_t;

///
typedef struct
{
   float    T20_slope;
   float    T20_intercept;
   float    T20_Rt60_Decay;
   float    T30_slope;
   float    T30_intercept;
   float    T30_Rt60_Decay;
   float    EDT_slope;        // These three items are the new indices for EDT
   float    EDT_intercept;    //
   float    EDT_Rt60_Decay;   //
} Rt60Data_t;


///
typedef struct
{
   unsigned int    total_count;     // number of samples taken
   unsigned int    average_count;   // number of samples used in average
   unsigned int    numFreqBands;    // 12 == BAND_OCTAVE, 36 BAND_OCTAVE_THIRD
   unsigned int    positions;       // number of run positions
} RA_Common_t;

// After learning more about Room Acoustics is seems it would be better to have
// a typedef with a more appropriate name than numFreqBands. This is not suited
// for Rooms. In Rooms what is needed is Measurement Type so a new typedef is
// created below.
typedef struct {
   unsigned int    total_count;     // number of samples taken
   unsigned int    average_count;   // number of samples used in average
   unsigned int    flags;           // Measurement Type, L1=1, L2=2, B2=3
   unsigned int    positions;       // number of run positions
} RA_Header_t;

///
typedef struct
{
   //unsigned int   includedInAvg;           // flag to indicate whether this record was included in the average
   unsigned short includedInAvg;             // flag to indicate whether this record was included in the average
   unsigned short position;                  // position associated with this decay
   float          Leq[NUM_THIRD_OCTAVES];    // Leq OBA sprectrum
   float          Lmax[NUM_THIRD_OCTAVES];   // Max OBA sprectrum
   float          Lbk[NUM_THIRD_OCTAVES];    // Background noise OBA spectrum
   float          EDT[NUM_THIRD_OCTAVES];    // RT60 early decay time
   float          T20[NUM_THIRD_OCTAVES];    // RT60 20dB decay time
   float          T30[NUM_THIRD_OCTAVES];    // RT60 20dB decay time
   // These are used to determine quality indicators
   float          Cu[NUM_THIRD_OCTAVES];     // Curvature (calculated from both)
   float          Co_T20[NUM_THIRD_OCTAVES]; // Correlation Coefficient for T20
   float          Co_T30[NUM_THIRD_OCTAVES]; // Correlation Coefficient for T30
   float          SD_T20[NUM_THIRD_OCTAVES]; // Standard Deviation of T20
   float          SD_T30[NUM_THIRD_OCTAVES]; // Standard Deviation of T30
} RT60_SampleT2_t;


typedef struct 
{
   RT60_SampleT2_t   T2;
   DataLimits_t      idxPts[NUM_THIRD_OCTAVES];
} RT60_SampleT2WithLimits_t;

#define MAX_DECAYS_PER_POSITION  100

typedef struct 
{
   RA_Common_t         com;
   RT60_SampleT2_t     T2;
   BYTE                DecaysPerPosition[MAX_DECAYS_PER_POSITION];  // number of included decays per position
} RT60_AverageT2_t;


// The structure below is defined so it can overlay of a structure of type float[36][2000] without overlap.
#define NUM_RT60_TIME_SAMPLES    (NUM_STAT_BINS-5)
typedef struct 
{
   float            freqTime[NUM_THIRD_OCTAVES][NUM_RT60_TIME_SAMPLES]; // frequency x samples
   DataLimits_t     idxPts[NUM_THIRD_OCTAVES];  // RT60 index points
   unsigned int     total_count;                // number of samples taken
   unsigned int     average_count;              // number of samples used in average
   int              sample_count;               // the number of samples in the time series
   unsigned int     numFreqBands;               // 12 == BAND_OCTAVE, 36 BAND_OCTAVE_THIRD
   unsigned int     preTriggerCount;            // samples in pretrigger
   float            samplePeriod;               // time in seconds between samples
   unsigned int     RT60_Method;                // trigger method used when this sample was taken
   unsigned int     time_stamp;                 // time stamp of when first samples was started
   unsigned int     not_used[28];               // Unused elements remaining in this overlay definition.
                                                // When a new variable is needed, insert it before this
                                                // array and reduce the array size by the size of the 
                                                // elements that were added.
} ByTimeSpectraLevel_t;


typedef struct 
{
   RA_Header_t    hdr;
   float          fOctave[NUM_OCTAVES];
   float          fThirdOctave[NUM_THIRD_OCTAVES];
} RA_RTA_t;


struct s_Weather 
{
   float          WindSpeedAvg;     // Average Wind Speed in scaled units
   float          WindSpeedMax;     // Maximum Wind Speed in scaled units
   float          WindSpeedMin;     // Minimum Wind Speed in scaled units
   unsigned int   WindDirStats[WINDDIRSTATSBINS];  // Wind Direction Stats, 8 rose points counts
   float          WindDirMax;       // Wind Direction at maximum, 0 to 359.9 degrees
   float          ADC1Avg;          // Average ADC1 in user units, scaled and offset (Temperature)
   float          ADC1Max;          // Maximum ADC1 in user units, scaled and offset
   float          ADC1Min;          // Minimum ADC1 in user units, scaled and offset
   float          ADC2Avg;          // Average ADC2 in user units, scaled and offset (Humidity)
   float          ADC2Max;          // Maximum ADC2 in user units, scaled and offset
   float          ADC2Min;          // Minimum ADC2 in user units, scaled and offset
   float          ADC3Avg;          // Reserved for Barometer
   float          ADC3Max;          // Reserved for Barometer
   float          ADC3Min;          // Reserved for Barometer
   float          RainTotal;        // Reserved for RainFall accumulation
   float          RainMaxRate;      // Reserved for RainFall maximum rate
   float          RainDuration;     // Reserved for RainFall duration

   // private data used to build average values
   unsigned int   WindAccm;         // Accumulator for WindSpeedAvg (sensor cycles)
   unsigned int   WindCount;        // Count for WindSpeedAvg   (time in WINDTICKSPERSECOND increments)
   float          ADC1Accm;         // Accumulator for ADC1Avg
   unsigned int   ADC1Count;        // Count for ADC1Avg
   float          ADC2Accm;         // Accumulator for ADC2Avg
   unsigned int   ADC2Count;        // Count for ADC2Avg
   float          ADC3Accm;         // Accumulator for ADC3Avg (reserved)
   unsigned int   ADC3Count;        // Count for ADC3Avg (reserved)

   //Narsi: Added this for Hail only available > Rev 1.505
   float          HailTotal;        // Reserved for Live RainFall accumulation
   float          HailMaxRate;      // Reserved for Live RainFall maximum rate
   float          HailDuration;     // Reserved for Live RainFall duration
}; // end of s_Weather

struct s_Overloads 
{
   int            count;
   float          duration;
   int            OBAcount;
   float          OBAduration;
};

struct degmin
{
   int            deg;
   float          min;
};

struct s_gps
{
   struct degmin  latitude;
   struct degmin  longitude;
   float          altitude;    // stored in SI meters
   unsigned long  time;        // (GMT time)  for 10:29:56=> time=102956
   unsigned long  date;        // 30/10/2006  => date = 30102006
   unsigned short flags;
};

struct s_prm2102 { // Change VER_426A12_INFO if this changes
   float RH;
   float Temp;
   float Dew;
   unsigned int modelnum;
   unsigned int serialnum;
   unsigned int flags; // see SLM_Def.h (i.e. PRM2102_NEW_DATA)
};

// s_prm2103 is the same as s_prm2102 with the version added... (see 105 data read command)
struct s_prm2103 {
	float    RH;
	float    Temp;
	float    Dew;
	uint32   modelnum;
	uint32   serialnum;
	uint32   flags; // see SLM_Def.h (i.e. PRM2102_NEW_DATA, etc)
	uint32   version;
};

struct s_RHTemp { // Change VER_426A12_DATA if this changes
   float RHMax;
   float TempMax;
   float DewMax;
   float RHMin;
   float TempMin;
   float DewMin;
};

struct s_DailyNoise {
   //float          Ldn;            // Day Night Level
   //float          Lden;           // Day Evening Night Level
   float          HNL[24];          // Day's hourly noise levels

   float          Time;             // Day  Night runtime and Day Evening Night runtime
   float          TimeHr[24];       // Day's hourly runtime

   float          Lden_Day;
   float          T_Lden_Day;
   float          Lden_Eve;
   float          T_Lden_Eve;
   float          Lden_Night;
   float          T_Lden_Night;

   float          Ldn_Day;
   float          T_Ldn_Day;
   float          Ldn_Night;
   float          T_Ldn_Night;
};


#define CAL_HISTS       11
#define CAL_TYPES       5

/******************************************************************************
   Calibration & Cal. History Structures
   -------------------------------------
   WARNING: Change VER_CALIBRATION whenever this structure is modified!
   See VER_CALIBRATION_FILE also.
******************************************************************************/
typedef struct s_caldata
{
   unsigned int CalibrationDate [CAL_HISTS];
   float        CalibrationScale[CAL_HISTS];
} CalData_t;

typedef struct s_calhistory
{
   struct s_caldata types[CAL_TYPES];
} CalHistory_t;

// For 831 version 1.2 (LxT won't have this until 1.4) we have a new cal history with spectra
// which is in addition to the above structure, redundant but easier to maintain (AJR)
typedef struct s_caldata2
{
   int          PreampType;
   unsigned int CalibrationDate;
   float        CalibrationScale;
   int          Bins;
   float        SpectralData[36];
} CalData2_t;

typedef struct s_calhistory2
{
   struct s_caldata2 data[CAL_TYPES][CAL_HISTS];
} CalHistory2_t;

typedef struct s_calcheckhistory
{
   struct s_caldata2 data[CAL_HISTS];
   float fStdLevel[CAL_HISTS];
} CalCheckHistory_t;


//  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// NOTE: ALL DATA THAT ARE SHOWN AS POINTERS IN THE STRUCTURES BELOW MUST BE DELETED BY THE
// CALLING PROGRAM. THE CALLING ROUTINE MUST USE HeapDelete RATHER THAN free OR delete.
// PAY ATTENTION TO THE COMMENTS WITH THE POINTER VARIABLES, THEY EXPLAIN ANY NUANCES IN THE DELETION
// OF THE POINTER VARIABLE.

typedef struct tagSlmLnInfo
{
	int m_nLnTable[NUM_STAT_BINS+2]; // 831 checks from .10 to 200 dB add 2 for over and under which will always be empty but needed for the graph
	int m_nBaseDB;  // will always be 0
	int m_nStatus;
	int m_nSamples;	// NOT the number of ln bins....num of samples in this sample
} stSlmLnInfo_t;

// Note: the order and type of the first six members of this structure
// must remain the same as the legacy struct _Spectra in OldStructs.h
// if not, you must change LegacySerialize() in the CSlmRecord class
// and all other classes that use this struct to compensate
typedef struct tagSpectra
{
	int m_nType;
	int m_nBandWidth;
	int m_nRange;
	float OverallSpectra[NUMSPECTRABINS];
	float MaxSpectra[NUMSPECTRABINS];
	float MinSpectra[NUMSPECTRABINS];
} stSpectraInfo_t;

#ifdef TODO
// This structure is used to get the pre and post cal data for run records.
typedef struct tagCalData
{
	CString m_csPreamp;  // this was added for the Lxt. it is not used for the Spark
	float m_fCalLevel;
	float m_fCalOffset;
	CString m_csCalDate;
} stCalData_t, CALDATA;

// This struct hold the calibrator descriptions
typedef struct tagCalibrator
{
	CString csDesc;
	float fLevel;
	float fFreq;
} stCalibrator_t, CALIBRATOR;
#endif // TODO

//structure of event counts. There are usually five, one for each trigger level
typedef struct tagEventCounts
{
	int m_nCount;
	float m_fDuration;
} stEventCounts_t;

// structure for both voice and audio records
typedef struct tagSpeechData
{
	int m_nNumSamples;  // number of frames
	int m_nType;        // whether compressed VOICE OR AUDIO TAG_VOICE_COMP or TAG_VOICE OR TAG_AUDIO as the flag
	int m_nSampleRate;  
	int m_nNumBitsPerSample;  // for now fixed at 16
	int m_nChannels;  // for now is 1
	int m_nDataSize;  //how many bytes of data, not number of frames.
	// BECAUSE UNKNOWN SIZE, m_pbyData IS ALLOCATED IN THE TRANSLATOR AND THE CALLER MUST DELETE i.e. HeapDelete m_pbyData
	BYTE *m_pbyData;   // all the frames: length in bytes of speex frame	data block
} stSpeechData_t;

// structure for run records (run, stop, pause, etc.)
typedef struct tagRunRecord
{
	int m_nType;
	int m_nCause;
	time_t m_tDate;
	int m_nVoiceDataIndex;  // this guy is incremented as voice records are added in and is used to access the SpeechData array
	int m_nTHRecord;        // this is the # the TH record will look for
	int m_nCount;
} stRunRecord_t;

// Individual time history record. The number of float values and number of OBA structures
// that are valid are set in the 831. These values are stored in the Settings structure
// in the following variables:
// m_nNumFloatVals
// m_nNumOBA11Vals
// m_nNumOBA13Vals

typedef struct tagTimeHistory
{
	UINT m_nAction;
	int m_nFlag;
	int m_nRecordNum; 
	int m_nTimeStamp;
	int m_nMiscStartIndex;
	float m_pfTHFloatVals[256]; // Number of valid values given by m_nNumFloatVals in Settings.
	float m_pfTH11OBAVals[4][FULLOCTAVE_BINS];  // 0-4 spectra given by m_nNumOBA11Vals in Settings
	float m_pfTH13OBAVals[4][THIRDOCTAVE_BINS]; // 0-4 spectra given by m_nNumOBA13Vals in Settings
	float m_fDuration;
} stTimeHistory_t;

// Fileheader structure
typedef struct tagFileHeader
{
	int nSerialNumber;
	char szSerialNumber[16];
	char szUser[64];
	char szLocation[128];
	char szJobDescription[128];
	char szNote[512];
	char szDataFileName[FILENAME_SIZE];
	char szOverallTitle[OVERALLTITLE_SIZE];
	char szModel[16];
	char szFirmwareRev[16];
	char szPreamp[16];

	// unicode interface
	UNICHAR uszSerialNumber[16];
	UNICHAR uszUser[64];
	UNICHAR uszLocation[128];
	UNICHAR uszJobDescription[128];
	UNICHAR uszNote[512];
	UNICHAR uszDataFileName[FILENAME_SIZE];
	UNICHAR uszOverallTitle[OVERALLTITLE_SIZE];
	UNICHAR uszModel[16];
	UNICHAR uszFirmwareRev[16];
	UNICHAR uszPreamp[16];

} stFileHeader_t;

// Preference structure
typedef struct tagPreferences
{
	int m_nDateFormat;
	int m_nDecimalFormat;
	int m_nLanguage;
	int m_nTaktMetricEnable;
	int m_nUnits;
	int m_nRICorrection;

	// the following fields were added 24apr2007
	float m_fFullOctaveReferenceSpectra1[FULLOCTAVE_BINS];
	float m_fFullOctaveReferenceSpectra2[FULLOCTAVE_BINS];
	float m_fFullOctaveReferenceSpectra3[FULLOCTAVE_BINS];
	float m_fFullOctaveReferenceSpectra4[FULLOCTAVE_BINS];
	float m_fThirdOctaveReferenceSpectra1[THIRDOCTAVE_BINS];
	float m_fThirdOctaveReferenceSpectra2[THIRDOCTAVE_BINS];
	float m_fThirdOctaveReferenceSpectra3[THIRDOCTAVE_BINS];
	float m_fThirdOctaveReferenceSpectra4[THIRDOCTAVE_BINS];
	char m_szFullOctaveReferenceSpectra1Name[12+1];
	char m_szFullOctaveReferenceSpectra2Name[12+1];
	char m_szFullOctaveReferenceSpectra3Name[12+1];
	char m_szFullOctaveReferenceSpectra4Name[12+1];
	char m_szThirdOctaveReferenceSpectra1Name[12+1];
	char m_szThirdOctaveReferenceSpectra2Name[12+1];
	char m_szThirdOctaveReferenceSpectra3Name[12+1];
	char m_szThirdOctaveReferenceSpectra4Name[12+1];

	// unicode interface
	UNICHAR m_uszFullOctaveReferenceSpectra1Name[12+1];
	UNICHAR m_uszFullOctaveReferenceSpectra2Name[12+1];
	UNICHAR m_uszFullOctaveReferenceSpectra3Name[12+1];
	UNICHAR m_uszFullOctaveReferenceSpectra4Name[12+1];
	UNICHAR m_uszThirdOctaveReferenceSpectra1Name[12+1];
	UNICHAR m_uszThirdOctaveReferenceSpectra2Name[12+1];
	UNICHAR m_uszThirdOctaveReferenceSpectra3Name[12+1];
	UNICHAR m_uszThirdOctaveReferenceSpectra4Name[12+1];

} stPreferences_t;

typedef struct tagNoiseFloor
{
	int m_nNFPreampType;													// preamp type
	int m_nNFWeighting;														// freq weighting
	float m_fNFOverload;														// z-wght peak overload limit
	float m_fNFUnderRangeLimitsRms[UR_WGHT_SIZE];		// lower limit for RMS (under range or noise floor +10dB)
	float m_fNFUnderRangeLimitsPeak[UR_WGHT_SIZE];	// lower limit for peak under range indication
	float m_fNFUnderNoiseFloor[UR_WGHT_SIZE];				// combined noise floor
	float fUnderRangeLimitsOctave[NUM_OCTAVES]; // lower limit for Octave under range or noise floor+10dB
	float fUnderRangeLimitsThirdOctave[NUM_THIRD_OCTAVES]; // lower limit for third octave under range or noise floor+10dB
	float fNoiseFloorOctave[NUM_OCTAVES]; // Noise Floor for Octave
	float fNoiseFloorThirdOctave[NUM_THIRD_OCTAVES]; // Noise Floor for third octave
} stNoiseFloor_t;

// extended error information
typedef struct tagExError
{
	unsigned int m_nExError;
} stExError_t;

// Dose settings structure
typedef struct tagSlmDose	// deprecated.  use stSlmDose1 instead
{
	// dose settings
	char m_szDoseName[9];
	BYTE m_byThresholdLevelDB;
	BYTE m_byExchangeRate;
	BYTE m_byCriterionTimeHours;
	BYTE m_byCriterionLevelDB;
	BOOL m_bThreshEnable;
	// unicode interface
	UNICHAR m_uszDoseName[9];
} stSlmDose_t;

typedef struct tagSlmDose1
{
	// dose settings
	char m_szDoseName[9];
	float m_fThresholdLevelDB;
	BYTE m_byExchangeRate;
	float m_fCriterionTimeHours;
	float m_fCriterionLevelDB;
	BOOL m_bThreshEnable;
	// unicode interface
	UNICHAR m_uszDoseName[9];
} stSlmDose1_t;

#ifdef TODO
typedef struct tagDoseCriteria
{
	CString csDoseName;
	BOOL bThreshEnable;
	BYTE byExchRate;
	float fThreshold;
	float fCritLevel;
	float fCritDuration;
} stDoseCriteria_t;
#endif // TODO

// This structure is used to retrieve the number of records for the
// data types that can have variable numbers of records.
typedef struct tagDataCnts
{
	int m_nNumEvents;
	int m_nNumTH;
	int m_nNumMeas;
	int m_nNumVoice;
	int m_nNumAudio;
	int m_nNumRunRecs;
} stDataCnts_t;

// This is the time history record for an exceedance when the 
// time history is enabled for exceedances. There may or may
// not be OBA data for the time history, depending on what 
// options are purchased and what OBA settings are enables.
// This is determined by the m_nOBASize in the Event Time
// History manager
typedef struct tagEventTimeHistory
{
	float m_fLevel;
	float m_fOBA[NUMSPECTRABINS];
} stEventTimeHistory_t;

// The event time history manager structure to manage the individual 
// Event time history records stored in an array allocated by the slm translator
// and must be deleted using HeapDelete in C++ when the data is no longer in use.
typedef struct tagEventTimeHistoryMngr
{
	//User must HeapDelete  m_pETHRecs 
	stEventTimeHistory_t *m_pETHRecs; 
	int m_nNumSamples;
	int m_nOBASize;
} stEventTimeHistoryMngr_t;

// The structure to contain each exceedance record.
typedef struct tagExceedenceRec
{
	int m_nID;
	int m_nTHIndex;
	time_t m_tStart;
	float m_fDuration;
	float m_fLeq;
	float m_fMaxSPL;
	time_t m_tMaxSPLTime;
	float m_fPeakMax;
	BOOL m_bOBAOverLoad;
	BOOL m_bOverLoad;
	BOOL m_bTHOverLoad;
	BOOL m_bOBATHOverLoad;
	int m_nNumTHSamples;
	int m_nNumPreTrigTHSamples;
	float m_fTrigLevel;
	int m_nSRNumber;
	int m_nExcTHIndex;
	float m_11OBALeq[FULLOCTAVE_BINS];   
	float m_11OBALMax[FULLOCTAVE_BINS];  
	float m_13OBALeq[THIRDOCTAVE_BINS];   
	float m_13OBALMax[THIRDOCTAVE_BINS];  
	stEventTimeHistoryMngr_t m_ETHData;
	int m_nNumPostTrigTHSamples;

	RT60_SampleT2WithLimits_t m_T2Sample;

} stExceedence_t;

// The structure to contain the data for each measurement or level
typedef struct tagInterval
{
	time_t m_tStart;
	time_t m_tEnd;
	float m_fRunTime;
	float m_fLeq;
	float m_fLCeq;
	float m_fLAeq;
	float m_fSEL;
	float m_fMax;
	float m_fPeak;
	float m_fMin;
	float m_fSEA;
	float m_fLTm5;
	time_t m_tPeakMaxTime;  // cant use CTime because of constructor problems.
	time_t m_tMaxTime;
	time_t m_tMinTime;
	float m_fPauseTime;
	int m_nLnTable[NUM_STAT_BINS];  
	int m_nSRNumber;
	int m_nNumOBA;
	float m_fAltitude; //(stored in SI meters)
	float m_fTWA[NUM_SLM_DOSES];
	// 12 OR 36 bins for each Ln so just set to 36
	float m_fSpectralLn[NUM_LNS][36]; 
	float m_fLnValues [NUM_LNS];
	float m_fLnPercents [NUM_LNS];
	float m_fLwIeq;
	float m_fLweq;
	stEventCounts_t m_ExceedCnts[NUM_EVENT_COUNTERS];
	struct s_Weather m_Weather;
	struct s_Overloads m_CurrentOverloads;
	stSpectraInfo_t m_11Spectra;
	stSpectraInfo_t m_13Spectra;
	struct degmin m_dgLatitude;
	struct degmin m_dgLongitude;
	struct s_RHTemp m_426A12Data;

} stInterval_t;

// Structure to contain all the settings in the 831 or LxT
typedef struct tagSettings
{
	BYTE  m_byFrequencyWeighting;
	BYTE  m_byPeakWeighting;
	BYTE  m_byDetector;
	stSlmDose_t m_Doses[NUM_SLM_DOSES];	// deprecated.  use m_Doses1 instead
	float m_fSplTrig1;
	float m_fSplTrig2;
	float m_fPeakTrig1;
	float m_fPeakTrig2;
	float m_fPeakTrig3;
	char  m_szMarkerNames[NUM_MARKERS][MARKER_LEN+1];
	int   m_nOBABandWidth;
	int   m_nOBARange;  // also used for FFT
	UINT  m_uiTHFlags1; // These three variables are bitwise flags indicating which timehistory data 
	UINT  m_uiTHFlags2; // were collected by the 831/LxT. See defines.h for the bitwise flags under
	int   m_nNumFloatVals;
	int   m_nNumOBA11Vals;
	int   m_nNumOBA13Vals;
	int   m_nTHMiscStartIndex; // used to keep track of where miscellaneous data starts in the Float array. Not needed by third party software
	float m_fLnValues[NUM_LNS];
	int   m_nIntegration;
	ULONG m_ulMeasurementPeriod;
	int   m_nSlmGain;
	int   m_nMeasLnTableEnable;
	char  m_szOverallTitle[OVERALLTITLE_SIZE];
	int   m_nSamplePeriod;     // time history period
	UINT  m_uiMeasCounts;
	//Community stuff
	ULONG m_ulDayTime;
	ULONG m_ulEveningTime;
	ULONG m_ulNightTime;
	float m_fEveningPenalty;
	float m_fNightPenalty;
	//measurement Audio Stuff
	BOOL  m_bMeasSnapShotEnable;
	ULONG m_ulMeasSnapShotPeriod;  //Interval Audio snapshot period
	ULONG m_ulExcSnapShotPeriod;
	BOOL  m_bEnableExceedAudioSnapshot;
	int   m_nExcdTHCount;
	int   m_nExcdTHPreCount;
	int   m_nExcdTHSpectra;
	int   m_nExcdTHPeriod;
	ULONG m_ulSnapShotPreTrig; //Exceedence Audio Pre Tirger period, called m_nPreTriggerPeriod in setupdata
	int   m_nMsmntSpectralLn;
	BYTE  m_byOBAWeighting;
		// added schema 12  // had an interim partial release so needed to change the schema
	int   m_nGPSControl;  // 0 off, 1  Auto,  2  On
	UINT  m_uiPurOptions;
	float m_fWindScale;
	char  m_szWindUnits[48];
	int   m_nWindDirection;
	float m_fWindThreshold;
	float m_fWindExcdLevel;
	float m_fWindHysteresis;
	int   m_nWindPause;
	float m_fADC1Scale;
	float m_fADC1Offset;
	char  m_szADC1Units[48];
	char  m_szADC1Description[48];
	float m_fADC2Scale;
	float m_fADC2Offset;
	char  m_szADC2Units[48];
	char  m_szADC2Description[48];
	char  m_szSetupFileName[FILENAME_SIZE];
	UINT  m_uiTHFlags3; // "SLM Any-Level Flags set in TimeHistoryOptions1"
	// changed to int to support Vaisala 12/10/08 (jtm)
	//BOOL								m_bWeatherEnabled;
	int   m_nWeatherOption;
	int   m_nOBAMaxSpectra;

	stSlmDose1_t m_Doses1[NUM_SLM_DOSES];

	// new Room Acoustics settings
   int m_nInstrumentMode;
   int m_nRAExitTime;
   int m_nRALoBand;
   int m_nRAHiBand;
   int m_nRT60NoiseType;
   float m_fRT60Attenuation;
   int m_nRT60TriggerMethod;
   int m_nRT60TriggerSource;
   float m_fRT60TriggerLevel;
   int m_nRT60Bandwidth;
   int m_nRT60BuildTime;
   int m_nRT60RunTime;
   int m_nRT60RunCount;
   int m_nRT60SamplePeriod;
   int m_nRT60SaveAverage;
   int m_nRT60SaveAll;
   int m_nRTANoiseType;
   float m_fRTAAttenuation;

	// FFT
	int m_nFftWindow;           //         FFT_WindowType;
	int m_nFftFreqSpan;         //         FFT_FreqSpan;
	int m_nFftLines;            //         FFT_NumLines;
	int m_nFftRunMode;          //         FFT_RunMode;
	int m_nFftTonality;         //         Tonality_1996_2;
	int m_nToneSeekDelta;       //         ToneSeekDelta;
	int m_nRegressionRange;     //         RegressionSpan;
	int m_uiRunTimer;
	int m_bMeasHistEnabled;

	// Vaisala Heater controls
	int m_nVaisalaHeaterState;
	int m_nVaisalaHeaterEnaTime;
	int m_nVaisalaHeaterDisTime;

	// unicode interface
	UNICHAR m_uszMarkerNames[NUM_MARKERS][MARKER_LEN+1];
	UNICHAR m_uszOverallTitle[OVERALLTITLE_SIZE];
	UNICHAR m_uszWindUnits[48];
	UNICHAR m_uszADC1Units[48];
	UNICHAR m_uszADC1Description[48];
	UNICHAR m_uszADC2Units[48];
	UNICHAR m_uszADC2Description[48];
	UNICHAR m_uszSetupFileName[FILENAME_SIZE];

} stSettings_t;

typedef struct tagFftInfo
{
	uint32 uiFlags;
	uint32 uiStartSec;     // start time timestamp seconds
	uint32 uiStartuSec;    // start time timestamp usecs
	float  fDuration;
	int    nCount;
	int    nOverloadCount;
	float  fOverloadDuration;
	float  fLeq;
	float  fLpeak;
	uint32 uiArraySize;
} stFftInfo_t;

typedef struct tagFftLevels
{
	float* pfLevelAvg;
	float* pfLevelMax;
} stFftLevels_t;

typedef struct tagFftRecord
{
	stFftInfo_t   stInfo;
	union
	{
		stFftLevels_t stLevels;
		float*        pfLevels[EFftLvlMax];
	};
} stFftRecord_t;

// structure to contain the overall data. If the spectral Ln table enable option
// is on, then the user must delete m_pSpectralLns, see comment below.
typedef struct tagOverallData
{
	int m_nTrig1Count;
	int m_nTrig2Count;
	int m_nPeakCount;
	int m_nPeak2Count;
	int m_nPeak3Count;
	float m_fTrig1Duration;
	float m_fTrig2Duration;
	float m_fPeakDuration;
	float m_fPeak2Duration;
	float m_fPeak3Duration;
	time_t m_tStart;  
	time_t m_tEnd;
	float m_fRunTime;
	int m_nNumOBA;    // number of OBA values for the spectral LNs if any, either 12 or 36
	stSpectraInfo_t	m_11Spectra;
	stSpectraInfo_t	m_13Spectra;
	float m_fPauseTime;
	char m_szPreamp[16];
	float m_fLeq;
	float m_fMax;
	float m_fPeak;
	float m_fMin;
	float m_fSEA;
	time_t m_tPeakMaxTime;
	time_t m_tMaxTime;
	time_t m_tMinTime;
	float m_fLAeq;
	float m_fLCeq;
	float m_fLTm5;
	float m_fTWA[NUM_SLM_DOSES];
	struct s_Overloads m_OverLoads;
	struct s_DailyNoise m_DailyNoise;
	struct s_gps m_GPSData;

	// noisefloor data added csn 17jan2007
	float m_fURLimit;
	float m_fURPeak;
	float m_fURNoiseFloor;
	float m_fNFOverload;

	// impulsivity data added csn 04apr2007
	float m_fLwIeq;
	float m_fLweq;

	// because this can be 2000 * 36 * 4 bytes large, allocate it only if necessary
	// THE INDIVIDUAL BUCKETS MUST BE DELETED BY THE CALLING ROUTINE IN 
	// A LOOP i.e. for NUM_THIRD_OCTAVES ... HeapDelete m_pSpectralLns[i]
	int *m_pnSpectralLns[NUM_THIRD_OCTAVES]; 

	// weather
	struct s_Weather m_Weather;

	struct s_prm2102 m_426A12Info;
	struct s_RHTemp  m_426A12Data;

	RT60_AverageT2_t m_T2Avg;
	//RA_RTA_t         m_L1;
	//RA_RTA_t         m_L2;
	//RA_RTA_t         m_B2;

	// unicode interface
	UNICHAR m_uszPreamp[16];
} stOverallData_t;

typedef struct tagCalHistory2
{
	struct s_calhistory2			m_CalHistory;
	struct s_calcheckhistory	m_CalCheckHistory;
} stCalHistory2_t;

// The main structure used by the translator to return the data
// retrieved by the translator one record at a time.
typedef struct tagSlmRecord
{
	int nRecType;
	union 
	{
		stOverallData_t  m_OVData;
		stSettings_t     m_Settings;
		stFileHeader_t   m_FileHeader;
		stPreferences_t  m_Prefs;
		stTimeHistory_t  m_ThRec;
		stRunRecord_t    m_RunRec;
		stSpeechData_t   m_SpeechRec;
		stSpeechData_t   m_AudioRec;
		stSlmLnInfo_t    m_OverAllLnTable;
		stEventCounts_t  m_EvntCnts[NUM_EVENT_COUNTERS];
		stInterval_t     m_Interval;
		stExceedence_t   m_Exceedences;
		float            m_fTWA[NUM_SLM_DOSES];
		s_calhistory     m_CalHistory;
		stNoiseFloor_t   m_NoiseFloor;
		stCalHistory2_t  m_CalHistory2;
		stExError_t      m_ExtendedError;
		ByTimeSpectraLevel_t m_ByTimeAvg;
		stFftRecord_t    m_Fft;
	};
} stSlmRecord_t;

// Use this structure to retrieve all records of a given type
// when there can be a variable number of records.
typedef struct tagSlmBulkRecords
{
	int nRecType;
	union
	{
		stTimeHistory_t *m_ThRecs;
		stInterval_t    *m_Interval;
		stExceedence_t  *m_Exceedences;
		stRunRecord_t   *m_RunRecord;
		stSpeechData_t  *m_VoiceRecord;
		stSpeechData_t  *m_AudioRecord;
	};
} stSlmBulkRecord_t;

// New TAG_STATUS_EX status command structure
typedef struct tagStatus
{
    unsigned int  uiStatusFlags; ///< Setting Semaphore Lock Flags
    unsigned int  uiLxTFlags;    ///< Live data flags, i.e. SLM_RUN (latch command not needed)
    unsigned int  uiRunFlags;    ///< Live RunFlags, i.e. RUNNING
    int           nMode;         ///< Instument Mode (RA, SLM, etc.)
    unsigned long tv_sec;
    unsigned long tv_usec;
    float         fSPL;
    float         fPeak;
    float         fBatVolt;
    float         fExtVolt;
    float         fTemperature;  ///< Internal Temperature degrees C
    int           nEventNum;     ///< Number of the last high level Event, used for event notification (added version 1.604 AJR)
    float         fEventLevel;   ///< Level of the last high level Event (added version 1.604 AJR)
    unsigned int  nEventTime;    ///< Time of the last high level Event (added version 1.604 AJR)
    unsigned int  nErrorFlags;   ///< g_SlmErrorFlags, see LDERR_FLASH_READ_FAILURE (v2.200)
    union
    {
        char   byVal[4];
        short  sVal[2];
        int    nVal[1];
        float  fVal[1];
    } pad;      // this union is used to pad the tagStatus structure to exactly 64 bytes

} stStatus_t, stStatus, s_status, STATUS, *PSTATUS;

// this struct is the pre-2.0 info used for file downloads
typedef struct iofileinfo
{
   char name[SZ16]; // nnnnnnnn.xxx format; the last three bytes are with packing turned off.
   int size;        // int has be written on a 4 byte boundary.
} stIoFileInfo_t, s_iofileinfo, IOFILEINFO, *PIOFILEINFO;

// this is the expanded file info structure for 2.0+
typedef struct tagIoFileInfoEx
{
	stIoFileInfo_t Io;
	UINT uiFileTime;
	int nFileNdx;
} stIoFileInfoEx_t, s_iofileinfoex, IOFILEINFOEX, *PIOFILEINFOEX;

#ifdef TODO
// this struct combines the IoFileInfoEx struct with a CString name for G3
typedef struct tagFileInfo
{
	CString csName;
	stIoFileInfoEx_t Iox;
} stFileInfo_t, FILEINFO, *PFILEINFO;
#endif // TODO

#pragma pack()
