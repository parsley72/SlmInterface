#ifndef SLMINTERFACEDATA_H
#define SLMINTERFACEDATA_H

#include <crtdefs.h>
#include <Winsock2.h>

#define SLM_FILENAME_SIZE                  16
#define SLM_OVERALLTITLE_SIZE              64

// NUM_EVENT_COUNTERS -- 2 for SPL and 3 for peak triggers
#define SLM_NUM_EVENT_COUNTERS             5

// misc defines
#define SLM_FULLOCTAVE                     0
#define SLM_THIRDOCTAVE                    1
#define SLM_NUM11SPECTRABINS               12
#define SLM_NUMSPECTRABINS                 36
#define SLM_NUM_OCTAVES                    12
#define SLM_NUM_THIRD_OCTAVES              36
#define SLM_FULLOCTAVE_BINS                12
#define SLM_THIRDOCTAVE_BINS               36
#define SLM_NUM_SLM_DOSES                  2
#define SLM_NUM_LNS                        6
#define SLM_NUM_CALIBRATORS                5
#define SLM_NUM_MARKERS                    10
#define SLM_NUM_STAT_BINS                  2000
#define SLM_NUM_SLM_LN_BINS                (SLM_NUM_STAT_BINS + 2)
#define SLM_FILENAME_SIZE                  16
#define SLM_OVERALLTITLE_SIZE              64
#define SLM_MARKER_LEN                     32

// Weather defines...
#define SLM_WINDDIRSTATSBINS               8

#define SLM_UR_WGHT_A                      0    // WEIGHTING ARRAY INDEX CONSTANTS
#define SLM_UR_WGHT_C                      1
#define SLM_UR_WGHT_Z                      2
#define SLM_UR_WGHT_SIZE                   3

// stFileHeader_t
// Fileheader structure
typedef struct slmSFileHeader
{
	int nSerialNumber;
	// unicode interface
	wchar_t uszSerialNumber[16];
	wchar_t uszUser[64];
	wchar_t uszLocation[128];
	wchar_t uszJobDescription[128];
	wchar_t uszNote[512];
	wchar_t uszDataFileName[SLM_FILENAME_SIZE];
	wchar_t uszOverallTitle[SLM_OVERALLTITLE_SIZE];
	wchar_t uszModel[16];
	wchar_t uszFirmwareRev[16];
	wchar_t uszPreamp[16];
} slmSFileHeader_t;

// stSlmRecord_t

// Note: the order and type of the first six members of this structure
// must remain the same as the legacy struct _Spectra in OldStructs.h
// if not, you must change LegacySerialize() in the CSlmRecord class
// and all other classes that use this struct to compensate
typedef struct slmSSpectra
{
	int m_nType;
	int m_nBandWidth;
	int m_nRange;
	float OverallSpectra[SLM_NUMSPECTRABINS];
	float MaxSpectra[SLM_NUMSPECTRABINS];
	float MinSpectra[SLM_NUMSPECTRABINS];
} slmSSpectraInfo_t;

struct slmSOverloads
{
   int            count;
   float          duration;
   int            OBAcount;
   float          OBAduration;
};

struct slmSDailyNoise
{
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

struct slmSDegmin
{
   int            deg;
   float          min;
};

struct slmSGPS
{
   struct slmSDegmin  latitude;
   struct slmSDegmin  longitude;
   float          altitude;    // stored in SI meters
   unsigned long  time;        // (GMT time)  for 10:29:56=> time=102956
   unsigned long  date;        // 30/10/2006  => date = 30102006
   unsigned short flags;
};

struct slmSWeather
{
   float          WindSpeedAvg;     // Average Wind Speed in scaled units
   float          WindSpeedMax;     // Maximum Wind Speed in scaled units
   float          WindSpeedMin;     // Minimum Wind Speed in scaled units
   unsigned int   WindDirStats[SLM_WINDDIRSTATSBINS];  // Wind Direction Stats, 8 rose points counts
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
}; // end of slmSWeather

struct slmSPRM2102 { // Change VER_426A12_INFO if this changes
   float RH;
   float Temp;
   float Dew;
   unsigned int modelnum;
   unsigned int serialnum;
   unsigned int flags; // see SLM_Def.h (i.e. PRM2102_NEW_DATA)
};

struct slmSRHTemp { // Change VER_426A12_DATA if this changes
   float RHMax;
   float TempMax;
   float DewMax;
   float RHMin;
   float TempMin;
   float DewMin;
};

///
typedef struct
{
   unsigned int    total_count;     // number of samples taken
   unsigned int    average_count;   // number of samples used in average
   unsigned int    numFreqBands;    // 12 == BAND_OCTAVE, 36 BAND_OCTAVE_THIRD
   unsigned int    positions;       // number of run positions
} slmSRA_Common_t;

///
typedef struct
{
   //unsigned int   includedInAvg;           // flag to indicate whether this record was included in the average
   unsigned short includedInAvg;             // flag to indicate whether this record was included in the average
   unsigned short position;                  // position associated with this decay
   float          Leq[SLM_NUM_THIRD_OCTAVES];    // Leq OBA sprectrum
   float          Lmax[SLM_NUM_THIRD_OCTAVES];   // Max OBA sprectrum
   float          Lbk[SLM_NUM_THIRD_OCTAVES];    // Background noise OBA spectrum
   float          EDT[SLM_NUM_THIRD_OCTAVES];    // RT60 early decay time
   float          T20[SLM_NUM_THIRD_OCTAVES];    // RT60 20dB decay time
   float          T30[SLM_NUM_THIRD_OCTAVES];    // RT60 20dB decay time
   // These are used to determine quality indicators
   float          Cu[SLM_NUM_THIRD_OCTAVES];     // Curvature (calculated from both)
   float          Co_T20[SLM_NUM_THIRD_OCTAVES]; // Correlation Coefficient for T20
   float          Co_T30[SLM_NUM_THIRD_OCTAVES]; // Correlation Coefficient for T30
   float          SD_T20[SLM_NUM_THIRD_OCTAVES]; // Standard Deviation of T20
   float          SD_T30[SLM_NUM_THIRD_OCTAVES]; // Standard Deviation of T30
} slmSRT60_SampleT2_t;

///
typedef struct
{
   unsigned int StartPoint;
   unsigned int TwentydBPoint;
   unsigned int ThirtydBPoint;
   unsigned int StopPoint;
} slmSDataLimits_t;

typedef struct 
{
   slmSRT60_SampleT2_t   T2;
   slmSDataLimits_t      idxPts[SLM_NUM_THIRD_OCTAVES];
} slmSRT60_SampleT2WithLimits_t;

#define SLM_MAX_DECAYS_PER_POSITION  100

typedef struct 
{
   slmSRA_Common_t         com;
   slmSRT60_SampleT2_t     T2;
   unsigned char           DecaysPerPosition[SLM_MAX_DECAYS_PER_POSITION];  // number of included decays per position
} slmSRT60_AverageT2_t;

// structure to contain the overall data. If the spectral Ln table enable option
// is on, then the user must delete m_pSpectralLns, see comment below.
typedef struct slmSOverallData
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
	slmSSpectraInfo_t	m_11Spectra;
	slmSSpectraInfo_t	m_13Spectra;
	float m_fPauseTime;
	wchar_t m_uszPreamp[16];
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
	float m_fTWA[SLM_NUM_SLM_DOSES];
	struct slmSOverloads m_OverLoads;
	struct slmSDailyNoise m_DailyNoise;
	struct slmSGPS m_GPSData;

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
	int* m_pnSpectralLns[SLM_NUM_THIRD_OCTAVES];

	// weather
	struct slmSWeather m_Weather;

	struct slmSPRM2102 m_426A12Info;
	struct slmSRHTemp  m_426A12Data;

	slmSRT60_AverageT2_t m_T2Avg;
} slmSOverallData_t;

// Dose settings structure
/*
typedef struct slmSDose	// deprecated.  use stSlmDose1 instead
{
	wchar_t m_uszDoseName[9];
	unsigned char m_byThresholdLevelDB;
	unsigned char m_byExchangeRate;
	unsigned char m_byCriterionTimeHours;
	unsigned char m_byCriterionLevelDB;
	bool m_bThreshEnable;
} slmSDose_t;
*/

typedef struct slmSDose1
{
	wchar_t m_uszDoseName[9];
	float m_fThresholdLevelDB;
	unsigned char m_byExchangeRate;
	float m_fCriterionTimeHours;
	float m_fCriterionLevelDB;
	bool m_bThreshEnable;
} slmSDose1_t;

// Structure to contain all the settings in the 831 or LxT
typedef struct slmSSettings
{
	unsigned char m_byFrequencyWeighting;
	unsigned char m_byPeakWeighting;
	unsigned char m_byDetector;
//	slmSDose_t m_Doses[SLM_NUM_SLM_DOSES];	// deprecated.  use m_Doses1 instead
	float m_fSplTrig1;
	float m_fSplTrig2;
	float m_fPeakTrig1;
	float m_fPeakTrig2;
	float m_fPeakTrig3;
	wchar_t m_uszMarkerNames[SLM_NUM_MARKERS][SLM_MARKER_LEN+1];
	int   m_nOBABandWidth;
	int   m_nOBARange;  // also used for FFT
	unsigned int m_uiTHFlags1; // These three variables are bitwise flags indicating which timehistory data 
	unsigned int m_uiTHFlags2; // were collected by the 831/LxT. See defines.h for the bitwise flags under
	int   m_nNumFloatVals;
	int   m_nNumOBA11Vals;
	int   m_nNumOBA13Vals;
	int   m_nTHMiscStartIndex; // used to keep track of where miscellaneous data starts in the Float array. Not needed by third party software
	float m_fLnValues[SLM_NUM_LNS];
	int   m_nIntegration;
	unsigned long m_ulMeasurementPeriod;
	int   m_nSlmGain;
	int   m_nMeasLnTableEnable;
	wchar_t m_uszOverallTitle[SLM_OVERALLTITLE_SIZE];
	int   m_nSamplePeriod;     // time history period
	int   m_nSamplePeriodInMSecs;
	unsigned int m_uiMeasCounts;
	//Community stuff
	unsigned long m_ulDayTime;
	unsigned long m_ulEveningTime;
	unsigned long m_ulNightTime;
	float m_fEveningPenalty;
	float m_fNightPenalty;
	//measurement Audio Stuff
	bool  m_bMeasSnapShotEnable;
	unsigned long m_ulMeasSnapShotPeriod;
	unsigned long m_ulExcSnapShotPeriod;
	bool  m_bEnableExceedAudioSnapshot;
	int   m_nExcdTHCount;
	int   m_nExcdTHPreCount;
	int   m_nExcdTHSpectra;
	int   m_nExcdTHPeriod;
	unsigned long m_ulSnapShotPreTrig;
	int   m_nMsmntSpectralLn;
	unsigned char m_byOBAWeighting;
	int   m_nGPSControl;
	unsigned int m_uiPurOptions;
	float m_fWindScale;
	wchar_t m_uszWindUnits[48];
	int   m_nWindDirection;
	float m_fWindThreshold;
	float m_fWindExcdLevel;
	float m_fWindHysteresis;
	int   m_nWindPause;
	float m_fADC1Scale;
	float m_fADC1Offset;
	wchar_t m_uszADC1Units[48];
	wchar_t m_uszADC1Description[48];
	float m_fADC2Scale;
	float m_fADC2Offset;
	wchar_t m_uszADC2Units[48];
	wchar_t m_uszADC2Description[48];
	wchar_t m_uszSetupFileName[SLM_FILENAME_SIZE];
	unsigned int m_uiTHFlags3;
	int   m_nWeatherOption;
	int   m_nOBAMaxSpectra;

	slmSDose1_t m_Doses1[SLM_NUM_SLM_DOSES];

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
} slmSSettings_t;

// Preference structure
typedef struct slmSPreferences
{
	int m_nDateFormat;
	int m_nDecimalFormat;
	int m_nLanguage;
	int m_nTaktMetricEnable;
	int m_nUnits;
	int m_nRICorrection;

	// the following fields were added 24apr2007
	float m_fFullOctaveReferenceSpectra1[SLM_FULLOCTAVE_BINS];
	float m_fFullOctaveReferenceSpectra2[SLM_FULLOCTAVE_BINS];
	float m_fFullOctaveReferenceSpectra3[SLM_FULLOCTAVE_BINS];
	float m_fFullOctaveReferenceSpectra4[SLM_FULLOCTAVE_BINS];
	float m_fThirdOctaveReferenceSpectra1[SLM_THIRDOCTAVE_BINS];
	float m_fThirdOctaveReferenceSpectra2[SLM_THIRDOCTAVE_BINS];
	float m_fThirdOctaveReferenceSpectra3[SLM_THIRDOCTAVE_BINS];
	float m_fThirdOctaveReferenceSpectra4[SLM_THIRDOCTAVE_BINS];
	// unicode interface
	wchar_t m_uszFullOctaveReferenceSpectra1Name[12+1];
	wchar_t m_uszFullOctaveReferenceSpectra2Name[12+1];
	wchar_t m_uszFullOctaveReferenceSpectra3Name[12+1];
	wchar_t m_uszFullOctaveReferenceSpectra4Name[12+1];
	wchar_t m_uszThirdOctaveReferenceSpectra1Name[12+1];
	wchar_t m_uszThirdOctaveReferenceSpectra2Name[12+1];
	wchar_t m_uszThirdOctaveReferenceSpectra3Name[12+1];
	wchar_t m_uszThirdOctaveReferenceSpectra4Name[12+1];
} slmSPreferences_t;

typedef struct slmSTimeHistory
{
	unsigned int m_nAction;
	int m_nFlag;
	int m_nRecordNum; 
	//int m_nTimeStamp;
	struct timeval m_TimeStamp;
	int m_nMiscStartIndex;
	float m_pfTHFloatVals[256]; // Number of valid values given by m_nNumFloatVals in Settings.
	float m_pfTH11OBAVals[4][SLM_FULLOCTAVE_BINS];  // 0-4 spectra given by m_nNumOBA11Vals in Settings
	float m_pfTH13OBAVals[4][SLM_THIRDOCTAVE_BINS]; // 0-4 spectra given by m_nNumOBA13Vals in Settings
	float m_fDuration;
} slmSTimeHistory_t;

// structure for run records (run, stop, pause, etc.)
typedef struct slmSRunRecord
{
	int m_nType;
	int m_nCause;
	time_t m_tDate;
	int m_nVoiceDataIndex;  // this guy is incremented as voice records are added in and is used to access the SpeechData array
	int m_nTHRecord;        // this is the # the TH record will look for
	int m_nCount;
} slmSRunRecord_t;

// structure for both voice and audio records
typedef struct slmSSpeechData
{
/*
	int m_nNumSamples;  // number of frames
	int m_nType;        // whether compressed VOICE OR AUDIO TAG_VOICE_COMP or TAG_VOICE OR TAG_AUDIO as the flag
	int m_nSampleRate;  
	int m_nNumBitsPerSample;  // for now fixed at 16
	int m_nChannels;  // for now is 1
	int m_nDataSize;  //how many bytes of data, not number of frames.
	// BECAUSE UNKNOWN SIZE, m_pbyData IS ALLOCATED IN THE TRANSLATOR AND THE CALLER MUST DELETE i.e. HeapDelete m_pbyData
	unsigned char *m_pbyData;   // all the frames: length in bytes of speex frame	data block
*/
	wchar_t m_uszWavFile[MAX_PATH];
} slmSSpeechData_t;

typedef struct slmSSLnInfo
{
	int m_nLnTable[SLM_NUM_STAT_BINS+2]; // 831 checks from .10 to 200 dB add 2 for over and under which will always be empty but needed for the graph
	int m_nBaseDB;  // will always be 0
	int m_nStatus;
	int m_nSamples;	// NOT the number of ln bins....num of samples in this sample
} slmSLnInfo_t;

//structure of event counts. There are usually five, one for each trigger level
typedef struct slmSEventCounts
{
	int m_nCount;
	float m_fDuration;
} slmSEventCounts_t;

// The structure to contain the data for each measurement or level
typedef struct slmSInterval
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
	int m_nLnTable[SLM_NUM_STAT_BINS];
	int m_nSRNumber;
	int m_nNumOBA;
	float m_fAltitude; //(stored in SI meters)
	float m_fTWA[SLM_NUM_SLM_DOSES];
	// 12 OR 36 bins for each Ln so just set to 36
	float m_fSpectralLn[SLM_NUM_LNS][36]; 
	float m_fLnValues [SLM_NUM_LNS];
	float m_fLnPercents [SLM_NUM_LNS];
	float m_fLwIeq;
	float m_fLweq;
	slmSEventCounts_t m_ExceedCnts[SLM_NUM_EVENT_COUNTERS];
	struct slmSWeather m_Weather;
	struct slmSOverloads m_CurrentOverloads;
	slmSSpectraInfo_t m_11Spectra;
	slmSSpectraInfo_t m_13Spectra;
	struct slmSDegmin m_dgLatitude;
	struct slmSDegmin m_dgLongitude;
	struct slmSRHTemp m_426A12Data;
} slmSInterval_t;

// This is the time history record for an exceedance when the 
// time history is enabled for exceedances. There may or may
// not be OBA data for the time history, depending on what 
// options are purchased and what OBA settings are enables.
// This is determined by the m_nOBASize in the Event Time
// History manager
typedef struct slmSEventTimeHistory
{
	float m_fLevel;
	float m_fOBA[SLM_NUMSPECTRABINS];
} slmSEventTimeHistory_t;

// The event time history manager structure to manage the individual 
// Event time history records stored in an array allocated by the slm translator
// and must be deleted using HeapDelete in C++ when the data is no longer in use.
typedef struct slmSEventTimeHistoryMngr
{
	slmSEventTimeHistory_t *m_pETHRecs;
	int m_nNumSamples;
	int m_nOBASize;
} slmSEventTimeHistoryMngr_t;

// The structure to contain each exceedance record.
typedef struct slmSExceedenceRec
{
	int m_nID;
	int m_nTHIndex;
	time_t m_tStart;
	float m_fDuration;
	float m_fLeq;
	float m_fMaxSPL;
	time_t m_tMaxSPLTime;
	float m_fPeakMax;
	bool m_bOBAOverLoad;
	bool m_bOverLoad;
	bool m_bTHOverLoad;
	bool m_bOBATHOverLoad;
	int m_nNumTHSamples;
	int m_nNumPreTrigTHSamples;
	float m_fTrigLevel;
	int m_nSRNumber;
	int m_nExcTHIndex;
	float m_11OBALeq[SLM_FULLOCTAVE_BINS];   
	float m_11OBALMax[SLM_FULLOCTAVE_BINS];  
	float m_13OBALeq[SLM_THIRDOCTAVE_BINS];   
	float m_13OBALMax[SLM_THIRDOCTAVE_BINS];  
	slmSEventTimeHistoryMngr_t m_ETHData;
	int m_nNumPostTrigTHSamples;

	slmSRT60_SampleT2WithLimits_t m_T2Sample;
} slmSExceedence_t;

#define SLM_CAL_HISTS       11
#define SLM_CAL_TYPES       5

/******************************************************************************
   Calibration & Cal. History Structures
   -------------------------------------
   WARNING: Change VER_CALIBRATION whenever this structure is modified!
   See VER_CALIBRATION_FILE also.
******************************************************************************/
typedef struct slmSCalData
{
   unsigned int CalibrationDate [SLM_CAL_HISTS];
   float        CalibrationScale[SLM_CAL_HISTS];
} slmSCalData_t;

typedef struct slmSCalHistory
{
   struct slmSCalData types[SLM_CAL_TYPES];
} slmSCalHistory_t;

typedef struct slmSNoiseFloor
{
	int m_nNFPreampType;													// preamp type
	int m_nNFWeighting;														// freq weighting
	float m_fNFOverload;														// z-wght peak overload limit
	float m_fNFUnderRangeLimitsRms[SLM_UR_WGHT_SIZE];		// lower limit for RMS (under range or noise floor +10dB)
	float m_fNFUnderRangeLimitsPeak[SLM_UR_WGHT_SIZE];	// lower limit for peak under range indication
	float m_fNFUnderNoiseFloor[SLM_UR_WGHT_SIZE];				// combined noise floor
	float fUnderRangeLimitsOctave[SLM_NUM_OCTAVES]; // lower limit for Octave under range or noise floor+10dB
	float fUnderRangeLimitsThirdOctave[SLM_NUM_THIRD_OCTAVES]; // lower limit for third octave under range or noise floor+10dB
	float fNoiseFloorOctave[SLM_NUM_OCTAVES]; // Noise Floor for Octave
	float fNoiseFloorThirdOctave[SLM_NUM_THIRD_OCTAVES]; // Noise Floor for third octave
} slmSNoiseFloor_t;

// For 831 version 1.2 (LxT won't have this until 1.4) we have a new cal history with spectra
// which is in addition to the above structure, redundant but easier to maintain (AJR)
typedef struct slmSCalData2
{
   int          PreampType;
   unsigned int CalibrationDate;
   float        CalibrationScale;
   int          Bins;
   float        SpectralData[36];
} slmSCalData2_t;

typedef struct slmSCalHistory2S
{
   struct slmSCalData2 data[SLM_CAL_TYPES][SLM_CAL_HISTS];
} slmSCalHistory2S_t;

struct slmSCalCheckHistory
{
   struct slmSCalData2 data[SLM_CAL_HISTS];
   float fStdLevel[SLM_CAL_HISTS];
};

typedef struct slmSCalHistory2
{
	struct slmSCalHistory2S		m_CalHistory;
	struct slmSCalCheckHistory	m_CalCheckHistory;
} slmSCalHistory2_t;

// extended error information
typedef struct slmSExError
{
	unsigned int m_nExError;
} slmSExError_t;

// The structure below is defined so it can overlay of a structure of type float[36][2000] without overlap.
#define SLM_NUM_RT60_TIME_SAMPLES    (SLM_NUM_STAT_BINS-5)
typedef struct 
{
   float            freqTime[SLM_NUM_THIRD_OCTAVES][SLM_NUM_RT60_TIME_SAMPLES]; // frequency x samples
   slmSDataLimits_t     idxPts[SLM_NUM_THIRD_OCTAVES];  // RT60 index points
   unsigned int     total_count;                // number of samples taken
   unsigned int     average_count;              // number of samples used in average
   int              sample_count;               // the number of samples in the time series
   unsigned int     numFreqBands;               // 12 == BAND_OCTAVE, 36 BAND_OCTAVE_THIRD
   unsigned int     preTriggerCount;            // samples in pretrigger
   float            samplePeriod;               // time in seconds between samples
   unsigned int     RT60_Method;                // trigger method used when this sample was taken
   unsigned int     time_stamp;                 // time stamp of when first samples was started
} slmSByTimeSpectraLevel_t;

typedef struct slmSFftInfo
{
	unsigned int uiFlags;
	unsigned int uiStartSec;     // start time timestamp seconds
	unsigned int uiStartuSec;    // start time timestamp usecs
	float  fDuration;
	int    nCount;
	int    nOverloadCount;
	float  fOverloadDuration;
	float  fLeq;
	float  fLpeak;
	unsigned int uiArraySize;
} slmSFftInfo_t;

typedef struct slmSFftLevels
{
	float* pfLevelAvg;
	float* pfLevelMax;
} slmSFftLevels_t;

typedef enum eSLMFftLevels
{
	eSLMFftAvg = 0,
	eSLMFftMax,
	eSLMFftLvlMax
} eSLMFftLevels;

typedef struct slmSFftRecord
{
	slmSFftInfo_t   stInfo;
	slmSFftLevels_t stLevels;
	float        fLevels[eSLMFftLvlMax];
} slmSFftRecord_t;

// The main structure used by the translator to return the data
// retrieved by the translator one record at a time.
typedef struct slmSRecord
{
	int nRecType;
	slmSOverallData_t  m_OVData;
	slmSSettings_t     m_Settings;
	slmSFileHeader_t   m_FileHeader;
	slmSPreferences_t  m_Prefs;
	slmSTimeHistory_t  m_ThRec;
	slmSRunRecord_t    m_RunRec;
	slmSSpeechData_t   m_SpeechRec;
	slmSSpeechData_t   m_AudioRec;
	slmSLnInfo_t    m_OverAllLnTable;
	slmSEventCounts_t  m_EvntCnts[SLM_NUM_EVENT_COUNTERS];
	slmSInterval_t     m_Interval;
	slmSExceedence_t   m_Exceedences;
	float            m_fTWA[SLM_NUM_SLM_DOSES];
	slmSCalHistory     m_CalHistory;
	slmSNoiseFloor_t   m_NoiseFloor;
	slmSCalHistory2_t  m_CalHistory2;
	slmSExError_t      m_ExtendedError;
	slmSByTimeSpectraLevel_t m_ByTimeAvg;
	slmSFftRecord_t    m_Fft;
} slmSRecord_t;

// stDataCnts_t
// This structure is used to retrieve the number of records for the
// data types that can have variable numbers of records.
typedef struct slmSDataCnts
{
	int m_nNumEvents;
	int m_nNumTH;
	int m_nNumMeas;
	int m_nNumVoice;
	int m_nNumAudio;
	int m_nNumRunRecs;
} slmSDataCnts_t;

// flags to retrieve all records of a type that have a variable number of records
typedef enum eTypeBulk
{
	eTypeBulkTh = 0, // TYPE_BULK_TH
	eTypeBulkEvnt = 1, // TYPE_BULK_EVNT
	eTypeBulkMeas = 2, // TYPE_BULK_MEAS
	eTypeBulkRunRec = 3, // TYPE_BULK_RUNREC
	eTypeBulkVoice = 4, // TYPE_BULK_VOICE
	eTypeBulkAudio = 5, // TYPE_BULK_AUDIO
} eTypeBulk;

// stSlmBulkRecord_t
// Use this structure to retrieve all records of a given type
// when there can be a variable number of records.
typedef struct slmSBulkRecords
{
	eTypeBulk eRecType;
	slmSDataCnts_t	m_dataCounts;
	slmSTimeHistory_t *m_pThRecs;
	slmSInterval_t    *m_pInterval;
	slmSExceedence_t  *m_pExceedences;
	slmSRunRecord_t   *m_pRunRecord;
	slmSSpeechData_t  *m_pVoiceRecord;
	slmSSpeechData_t  *m_pAudioRecord;
} slmSBulkRecord_t;


#endif // SLMINTERFACEDATA_H
