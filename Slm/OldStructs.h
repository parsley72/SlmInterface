#pragma once

#ifndef _OLDSTRUCTS_H_
#define _OLDSTRUCTS_H_
#include "lxt831.h"
//#include "LxT_DataFiles.h"

/*
#define OLD_NUM_EVENT_COUNTERS	3

struct s_measurement_ver1
{	
 struct slm CurrentSlm;
 struct s_eventcounter CurrentEventCounter[NUM_EVENT_COUNTERS];
 struct s_Overloads CurrentOverloads;
 float CurrentCentiles[LNS];
 float CurrentPercent[LNS];
};

struct s_measurement_ver2
{	
 struct slm CurrentSlm;
 struct s_eventcounter CurrentEventCounter[NUM_EVENT_COUNTERS];
 struct s_Overloads CurrentOverloads;
 float CurrentCentiles[LNS];
 float CurrentPercent[LNS];
 float CurrentProfile[PROFILE_GRAPH_SIZE];
};

struct s_Exceedence_ver1
{
	short flag;									// overload flags, oba and slm, marker flags (see TIMEHIST_OVERLOAD)
	unsigned int timestamp;			// Occurrence, Date and Time
	float duration;			// Duration, Run Time
	float level;								// Equivalent Level
	float pkmax;								// Peak Maximum Level
	float max;									// Maximum SPL
	unsigned int tmax;					// Time stamp of Maximum SPL
	unsigned int ExTHcount;				// Number of Time History Samples
	unsigned int ExTHpretrigger;	// Number of pretrigger Time History Samples
	unsigned int THrecord;			// Number of associated Time History record, for linking
	float triglevel;						// Triggered at level (important for dynamic and +/-10dB)
};

struct s_Exceedence_ver2
{
	short flag;									// overload flags, oba and slm, marker flags (see TIMEHIST_OVERLOAD)
	unsigned int timestamp;			// Occurrence, Date and Time
	float duration;			// Duration, Run Time
	float level;								// Equivalent Level
	float pkmax;								// Peak Maximum Level
	float max;									// Maximum SPL
	unsigned int tmax;					// Time stamp of Maximum SPL
	unsigned int ExTHcount;				// Number of Time History Samples
	unsigned int ExTHpretrigger;	// Number of pretrigger Time History Samples
	unsigned int THrecord;			// Number of associated Time History record, for linking
	float triglevel;						// Triggered at level (important for dynamic and +/-10dB)
	unsigned int NumSR;					//=0 if no SR is associated with it else it would be the corresponding NumSR
	unsigned int CurrExTHlocation; //the ExTHlocation corresponding to this the record .
};

union s_timehistory_ver1
{
// The difference between these two struct is TIMEHIST_SESSION_LOG
	struct {
		int flags;
		unsigned int action;			// cause AND action flags see sport_ioctl.h (i.e. PRM_ACTION_STOP + PRM_CAUSE_KEY)
		int record;								// session log number associated
	}session;
	
	struct {
		int flags;								// marker and overload flags (MSB = session log)
		float duration;						// duration for this sample
		float level;							// one level must always be stored!
	}history;
	
};

struct s_DataFileHeader_ver1
{
	int length;					//total size of struct s_DataFileHeader
	int ver;					//s_DataFileHeader sturcture version number
	char name[8+1+3+1+3];		//data file name; added last 3 for integar alignment

  unsigned int began;			//date and time stamp of begining of measurement, see struct slm.stamp
  unsigned int ended;			//date and time stamp of ending of measurement, see , see struct slm.???

	float runtime;					//run time of measurement, see struct slm.time
	char title[30+1];				//description of measurement, see OverallTitle
	char model[10+1];				//model number string
	char serialnum[10+1];		//serial number string
	char version[10+1];			//firmware version number (see structure version numbers)
	unsigned int options;		//voice message, octave dis/enabled
	
	unsigned int numlogs; 		//number of session log records
	unsigned int firstlog; 		//offset to first session log record
	unsigned int lastlog; 		//offset to last session log record
	
	unsigned int numvoice; 		//number of voice log records
	unsigned int firstvoice; 	//offset to first voice records
	unsigned int lastvoice; 	//offset to last voice records
	
	unsigned int nummsmt; 		//number of measurement records
	unsigned int firstmsmt; 	//offset to measurement records
	unsigned int lastmsmt; 		//offset to measurement records
	
	unsigned int numexcd; 		//number of Exceedence records
	unsigned int firstexcd; 	//offset to first Exceedence record
	unsigned int lastexcd; 		//offset to last Exceedence record
	
	unsigned int numtimehist; 	//number of time history records
	unsigned int firsttimehist; //offset to time history records
	unsigned int lasttimehist; 	//offset to time history records
	
	unsigned int numaudio; 		//number of audio file records
	unsigned int firstaudio; 	//offset to audio file records
	unsigned int lastaudio; 	//offset to audio file records
};

struct slm_ver1
{
	int flags;
	float time;		// elapsed run time
	unsigned int count;
	unsigned int stamp;	// First Sample Time/Date
	struct dets a;
	struct dets c;
	struct dets z;
	struct det octave3;		// 8Hz
	struct det octave4;
	struct det octave5;
	struct det octave6;
	struct det octave7;
	struct det octave8;
	struct det octave9;
	struct det octave10;	// 1KHz
	struct det octave11;
	struct det octave12;
	struct det octave13;
	struct det octave14;	// 16kHz
	struct det third8;
	struct det third9;
	struct det third10;		// 10Hz
	struct det third11;
	struct det third12;
	struct det third13;
	struct det third14;
	struct det third15;
	struct det third16;
	struct det third17;
	struct det third18;
	struct det third19;
	struct det third20;		// 100Hz
	struct det third21;
	struct det third22;
	struct det third23;
	struct det third24;
	struct det third25;
	struct det third26;
	struct det third27;
	struct det third28;
	struct det third29;
	struct det third30;		// 1kHz
	struct det third31;
	struct det third32;
	struct det third33;
	struct det third34;
	struct det third35;
	struct det third36;
	struct det third37;
	struct det third38;
	struct det third39;
	struct det third40;		// 10kHz
	struct det third41;
	struct det third42;
	struct det third43;
};

struct s_preferences_ver1
{
	struct set_Enum LockCal;
	struct set_Enum LockTask;
	struct set_Enum LockMode;
	struct set_UnsignedInt LockCombination;
	struct set_Enum DateFormat;
	struct set_Enum AutoSyncDateTime;	
	struct set_Enum DecimalFormat;
	struct set_Enum AutoStoreMode;
	struct set_Enum ResetPrompt;
	struct set_Enum Language;	
	struct set_Enum PowerAutoSleep;
	struct set_Enum PowerAutoOff;
	struct set_Enum BackLight;
	struct set_Enum BackLightTimer;
	struct set_Enum BatteryType;
	struct set_Enum Outputs;
	struct set_Int DisplayContrast;
	struct set_Enum VoiceCompression;	// checkbox
	
	struct set_Enum OverwriteOldestFiles;	// y/n csn 05Oct2005
	struct set_Enum TaktMetricEnable;			// y/n csn 05Oct2005
	struct set_Enum CompressDataFiles;		// y/n csn 05Oct2005
	struct set_Enum USBStorage;						// NO=0, AUTO=1 csn 05Oct2005

	struct set_FloatArray11 FullOctaveReferenceSpectra1;
	struct set_FloatArray11 FullOctaveReferenceSpectra2;
	struct set_FloatArray11 FullOctaveReferenceSpectra3;
	struct set_FloatArray11 FullOctaveReferenceSpectra4;
	struct set_FloatArray13 ThirdOctaveReferenceSpectra1;
	struct set_FloatArray13 ThirdOctaveReferenceSpectra2;
	struct set_FloatArray13 ThirdOctaveReferenceSpectra3;
	struct set_FloatArray13 ThirdOctaveReferenceSpectra4;
};

struct s_preferences_ver2
{
	struct set_Enum LockCal;
	struct set_Enum LockTask;
	struct set_Enum LockMode;
	struct set_UnsignedInt LockCombination;
	struct set_Enum DateFormat;
	struct set_Enum AutoSyncDateTime;	
	struct set_Enum DecimalFormat;
	struct set_Enum AutoStoreMode;
	struct set_Enum ResetPrompt;
	struct set_Enum Language;	
	struct set_Enum PowerAutoSleep;
	struct set_Enum PowerAutoOff;
	struct set_Enum BackLight;
	struct set_Enum BackLightTimer;
	struct set_Enum BatteryType;
	struct set_Enum Outputs;
	struct set_Int DisplayContrast;
	struct set_Enum VoiceCompression;	// checkbox
	
	struct set_Enum OverwriteOldestFiles;	// y/n csn 05Oct2005
	struct set_Enum TaktMetricEnable;			// y/n csn 05Oct2005
	struct set_Enum CompressDataFiles;		// y/n csn 05Oct2005
	struct set_Enum USBStorage;						// NO=0, AUTO=1 csn 05Oct2005

	struct set_FloatArray11 FullOctaveReferenceSpectra1;
	struct set_FloatArray11 FullOctaveReferenceSpectra2;
	struct set_FloatArray11 FullOctaveReferenceSpectra3;
	struct set_FloatArray11 FullOctaveReferenceSpectra4;
	struct set_FloatArray13 ThirdOctaveReferenceSpectra1;
	struct set_FloatArray13 ThirdOctaveReferenceSpectra2;
	struct set_FloatArray13 ThirdOctaveReferenceSpectra3;
	struct set_FloatArray13 ThirdOctaveReferenceSpectra4;

	struct set_Int StartupTab;	// csn 21apr2006
	struct set_UnsignedInt DisplayOptions1;		// csn 21apr2006
	struct set_UnsignedInt DisplayOptions2;		// csn 21apr2006
	struct set_UnsignedInt DisplayOptions3;		// csn 21apr2006
	struct set_UnsignedInt DisplayOptions4;		// csn 21apr2006
	struct set_UnsignedInt DisplayOptions5;		// csn 21apr2006
	struct set_UnsignedInt DisplayOptions6;		// csn 21apr2006
	struct set_UnsignedInt DisplayOptions7;		// csn 21apr2006
	struct set_UnsignedInt DisplayOptions8;		// csn 21apr2006

	struct set_Int GraphBottom;	// csn 21apr2006
	struct set_Int GraphHeight;	// [20...140]
	struct set_Int OBAGraphBottom;	// csn 21apr2006
	struct set_Int OBAGraphHeight;	// [20...140]

	// anylevel data points selected by user. 1 is for live display, 2 is for current/overall
	struct set_Int AnyLevelItem1;
	struct set_Int AnyLevelItem2;

	// modem communication settings
	struct set_String ModemPhoneNumber;						// csn 06july2006
	struct set_String ModemPassword;							// csn 06july2006
	struct set_Int ModemMonitorNumber;						// csn 06july2006
	struct set_String ModemInitializationString;	// csn 06july2006
	struct set_Enum ModemOnOff;										// csn 06july2006	MODEM_OFF, MODEM_ON
	struct set_Int ModemDialOutSetting;						// csn 06july2006	DIALOUT_NONE, DIALOUT_EXCD, DIALOUT_ALARM, DIALOUT_BOTH

	struct set_Enum GPRSModemOnOff;								// csn 12july2006	GPRSMODEM_OFF, GPRSMODEM_ON
	struct set_String GPRSAPN;										// csn 12july2006
	struct set_String GPRSAPNUsername;						// csn 12july2006
	struct set_String GPRSAPNPassword;						// csn 12july2006
	struct set_String GPRSPassword;								// csn 06july2006
	struct set_Int GPRSMonitorNumber;							// csn 06july2006

	struct set_Enum Units;												// csn 12july2006	UNITS_SI, UNITS_ENGLISH
	struct set_Enum GPSMode;											// csn 12july2006 GPSMODE_OFF, GPSMODE_ON, GPSMODE_AUTO
	struct set_Enum RICorrection;									// csn 12july2006 RI_OFF, RI_RI2FF, RI_FF2RI
};

struct s_preferences_ver3
{
	struct set_Enum LockCal;
	struct set_Enum LockTask;
	struct set_Enum LockMode;
	struct set_UnsignedInt LockCombination;
	struct set_Enum DateFormat;
	struct set_Enum AutoSyncDateTime;	
	struct set_Enum DecimalFormat;
	struct set_Enum AutoStoreMode;
	struct set_Enum ResetPrompt;
	struct set_Enum Language;	
	struct set_Enum PowerAutoSleep;
	struct set_Enum PowerAutoOff;
	struct set_Enum BackLight;
	struct set_Enum BackLightTimer;
	struct set_Enum BatteryType;
	struct set_Enum Outputs;
	struct set_Int DisplayContrast;
	struct set_Enum VoiceCompression;	// checkbox
	
	struct set_Enum OverwriteOldestFiles;	// y/n csn 05Oct2005
	struct set_Enum TaktMetricEnable;			// y/n csn 05Oct2005
	struct set_Enum CompressDataFiles;		// y/n csn 05Oct2005
	struct set_Enum USBStorage;						// NO=0, AUTO=1 csn 05Oct2005

	struct set_FloatArray11 FullOctaveReferenceSpectra1;
	struct set_FloatArray11 FullOctaveReferenceSpectra2;
	struct set_FloatArray11 FullOctaveReferenceSpectra3;
	struct set_FloatArray11 FullOctaveReferenceSpectra4;
	struct set_FloatArray13 ThirdOctaveReferenceSpectra1;
	struct set_FloatArray13 ThirdOctaveReferenceSpectra2;
	struct set_FloatArray13 ThirdOctaveReferenceSpectra3;
	struct set_FloatArray13 ThirdOctaveReferenceSpectra4;

	struct set_Int StartupTab;	// csn 21apr2006
	struct set_UnsignedInt DisplayOptions1;		// csn 21apr2006
	struct set_UnsignedInt DisplayOptions2;		// csn 21apr2006
	struct set_UnsignedInt DisplayOptions3;		// csn 21apr2006
	struct set_UnsignedInt DisplayOptions4;		// csn 21apr2006
	struct set_UnsignedInt DisplayOptions5;		// csn 21apr2006
	struct set_UnsignedInt DisplayOptions6;		// csn 21apr2006
	struct set_UnsignedInt DisplayOptions7;		// csn 21apr2006
	struct set_UnsignedInt DisplayOptions8;		// csn 21apr2006

	//struct set_Int GraphMidpoint;	
	struct set_Int GraphBottom;	// csn 21apr2006
	struct set_Int GraphHeight;	// [20...140]
	struct set_Int OBAGraphBottom;	// csn 21apr2006
	struct set_Int OBAGraphHeight;	// [20...140]

	// anylevel data points selected by user. 1 is for live display, 2 is for current/overall
	struct set_Int AnyLevelItem1;
	struct set_Int AnyLevelItem2;

	// modem communication settings
	struct set_String ModemPhoneNumber;						// csn 06july2006
	struct set_String ModemPassword;							// csn 06july2006
	struct set_Int ModemMonitorNumber;						// csn 06july2006
	struct set_String ModemInitializationString;	// csn 06july2006
	struct set_Enum ModemOnOff;										// csn 06july2006	MODEM_OFF, MODEM_ON
	struct set_Int ModemDialOutSetting;						// csn 06july2006	DIALOUT_NONE, DIALOUT_EXCD, DIALOUT_ALARM, DIALOUT_BOTH

	struct set_Enum GPRSModemOnOff;								// csn 12july2006	GPRSMODEM_OFF, GPRSMODEM_ON
	struct set_String GPRSAPN;										// csn 12july2006
	struct set_String GPRSAPNUsername;						// csn 12july2006
	struct set_String GPRSAPNPassword;						// csn 12july2006
	struct set_String GPRSPassword;								// csn 06july2006
	struct set_Int GPRSMonitorNumber;							// csn 06july2006

	struct set_Enum Units;												// csn 12july2006	UNITS_SI, UNITS_ENGLISH
	struct set_Enum GPSMode;											// csn 12july2006 GPSMODE_OFF, GPSMODE_ON, GPSMODE_AUTO
	struct set_Enum RICorrection;									// csn 12july2006 RI_OFF, RI_RI2FF, RI_FF2RI
	struct set_Enum USBPORTOnOff;									// narasi 16aug2006	USBPORT_OFF, USBPORT_ON
	struct set_Int	TimezoneCorrectionHours;			// number of hours to add/subtract from GPS time
	struct set_Int	TimezoneCorrectionMinutes;		// number of minutes to add/subtract from GPS time

	struct set_Int	LogicIn;		// csn 29aug2006 LOGICIN_NONE, LOGICIN_RUNSTOP, LOGICIN_EVENT, LOGICIN_ALARM
	struct set_Int	LogicOut;		// csn 29aug2006 LOGICOUT_OFF, LOGICOUT_RUNSTATE, LOGICOUT_EVENT
};

struct s_Controls_ver1
{
// System
	struct set_UnsignedInt AlarmDateTime;
	struct set_UnsignedInt StableTimer;
	struct set_UnsignedInt RunTimer;
	struct set_Enum RunMode;
	struct set_Float StableDB;	
	struct set_String OverallTitle;
//not used	struct set_String MeasurementDescription;	
	struct set_String DefaultFileName;
// SLM
	struct set_Enum SlmFrequencyWeighting;
	struct set_Enum PeakFrequencyWeighting;
	struct set_Enum SlmDetector;
// SLM Overall use SLM values
	struct set_Enum IntegrationInput;
// History
	struct set_Int HistPeriod;
// Statistics
	struct set_TableFloatsLNS Percentiles;
// OBA
	struct set_Enum ObaWeighting;
	struct set_Enum ObaRange;
	struct set_Enum ObaBandwidth;
// Dose
	struct set_String DoseName[DOSE_CHANNELS];
	struct set_Float DoseThreshold[DOSE_CHANNELS];
	struct set_Enum DoseThresholdEnable[DOSE_CHANNELS];
	struct set_EnumFloats DoseExRate[DOSE_CHANNELS];
	struct set_Float DoseCriterionLevel[DOSE_CHANNELS];
	struct set_Float DoseCriterionTime[DOSE_CHANNELS];
// Events
	struct set_Enum EventWeighting[OLD_NUM_EVENT_COUNTERS];
	struct set_Enum EventDetector[OLD_NUM_EVENT_COUNTERS];
	struct set_Float EventLevel[OLD_NUM_EVENT_COUNTERS];
};

struct s_Controls_ver2
{
// System
	struct set_UnsignedInt AlarmDateTime;
	struct set_String OverallTitle;

// run control
	struct set_UnsignedInt StableTimer;
	struct set_UnsignedInt RunTimer;
	struct set_Enum RunMode;
	struct set_Float StableDB;	

	struct set_Enum MeasurementHistoryEnable;	// csn 07sep2005
	struct set_UnsignedInt MeasurementCounter;				// csn 07sep2005
	struct set_UnsignedInt IntervalTime;			// csn 08sep2005
	struct set_Enum ClockSync;								// csn 08sep2005
	struct set_Enum DailyAutoStore;						// csn 08sep2005
	struct set_UnsignedInt AutoStoreTime;			// csn 08sep2005
	struct set_Enum AutoCalCheck;							// csn 08sep2005
	struct set_UnsignedInt AutoCalCheckTime;	// csn 08sep2005
	struct set_UnsignedInt StartDate;					// csn 08sep2005
	struct set_UnsignedInt EndDate;						// csn 08sep2005
	struct set_UnsignedInt RunTime1;					// csn 08sep2005
	struct set_UnsignedInt StopTime1;					// csn 08sep2005
	struct set_Enum EnableTimer2;							// csn 08sep2005
	struct set_UnsignedInt RunTime2;					// csn 08sep2005
	struct set_UnsignedInt StopTime2;					// csn 08sep2005
	struct set_Enum EnableTimer3;							// csn 08sep2005
	struct set_UnsignedInt RunTime3;					// csn 08sep2005
	struct set_UnsignedInt StopTime3;					// csn 08sep2005
	struct set_Enum LnTableEnable;						// csn 07dec2005

	// time history
	struct set_Enum TimeHistoryEnable;						// csn 16sep2005
	struct set_Enum TimeHistoryPeriod;						// csn 16sep2005
	struct set_UnsignedInt TimeHistoryOptions1;		// csn 16sep2005
	struct set_UnsignedInt TimeHistoryOptions2;	// csn 16sep2005

	// Exceedence history
	struct set_Enum ExceedenceHistoryEnable;							// csn	19sep2005
	struct set_Enum ExceedenceTimeHistoryEnable;					// csn	19sep2005
	struct set_Enum ExceedenceSpectralTimeHistoryEnable;	// csn	19sep2005
	struct set_Float MinimumDuration;											// csn	19sep2005
	struct set_Enum TriggerMethod;												// csn	19sep2005
	struct set_UnsignedInt ContinuationPeriod;						// csn	19sep2005
	struct set_Enum ExceedenceTimeHistoryPeriod;					// csn	19sep2005
	
	// markers
	struct set_String MarkerNames [NUM_MARKERS];					// csn	20sep2005
	struct set_Enum MarkerAudioRecord [NUM_MARKERS];			// csn	20sep2005
	struct set_UnsignedInt MarkerRecordPeriod;						// csn	20sep2005
	struct set_UnsignedInt MarkerPreRecordPeriod;					// csn	20sep2005

	// day/night (community noise)
	struct set_UnsignedInt DayTime;												// csn	22sep2005
	struct set_UnsignedInt EveningTime;										// csn	22sep2005
	struct set_UnsignedInt NightTime;											// csn	22sep2005
	struct set_Float EveningPenalty;											// csn	22sep2005
	struct set_Float NightPenalty;												// csn	22sep2005

	// audio
	struct set_Enum SaveExcdAudioSnapshot;										// csn	2sep2005
	struct set_UnsignedInt ExcdAudioSnapshotPeriod;						// csn	22sep2005
	struct set_UnsignedInt ExcdAudioSnapshotPreTriggerPeriod;	// csn	22sep2005
	struct set_Enum SaveMsmtAudioSnapshot;										// csn	22sep2005
	struct set_UnsignedInt MsmtAudioSnapshotPeriod;						// csn	22sep2005
	struct set_Enum SaveMsmtLevelDistributionTable;						// csn	22sep2005

//not used	struct set_String MeasurementDescription;	
	struct set_String DefaultFileName;
// SLM
	struct set_Enum SlmFrequencyWeighting;
	struct set_Enum PeakFrequencyWeighting;
	struct set_Enum SlmDetector;
	struct set_Enum SlmGain;		// 831 only
// SLM Overall use SLM values
	struct set_Enum IntegrationInput;
// History
	struct set_Int HistPeriod;
// Statistics
	struct set_TableFloatsLNS Percentiles;
// OBA
	struct set_Enum ObaRange;
	struct set_Enum ObaBandwidth;
	struct set_Enum ObaMaxSpectrumMode;	// csn 07sep2005
	struct set_Enum	ObaWeighting;

// Dose
	struct set_String DoseName[DOSE_CHANNELS];
	struct set_Float DoseThreshold[DOSE_CHANNELS];
	struct set_Enum DoseThresholdEnable[DOSE_CHANNELS];
	struct set_EnumFloats DoseExRate[DOSE_CHANNELS];
	struct set_Float DoseCriterionLevel[DOSE_CHANNELS];
	struct set_Float DoseCriterionTime[DOSE_CHANNELS];
// Events
	struct set_Enum EventWeighting[NUM_EVENT_COUNTERS];
	struct set_Enum EventDetector[NUM_EVENT_COUNTERS];
	struct set_Float EventLevel[NUM_EVENT_COUNTERS];
	struct set_Float DynamicTriggerOffsetLevel;	// csn 07sep2005
	struct set_Int DynamicResponse;	// csn 07sep2005
};

struct s_controls_ver3
{
// System
	struct set_UnsignedInt AlarmDateTime;
	struct set_String OverallTitle;

// run control
	struct set_UnsignedInt StableTimer;
	struct set_UnsignedInt RunTimer;
	struct set_Enum RunMode;
	struct set_Float StableDB;	

	struct set_Enum MeasurementHistoryEnable;	// csn 07sep2005
	struct set_UnsignedInt MeasurementCounter;				// csn 07sep2005
	struct set_UnsignedInt IntervalTime;			// csn 08sep2005
	struct set_Enum ClockSync;								// csn 08sep2005
	struct set_Enum DailyAutoStore;						// csn 08sep2005
	struct set_UnsignedInt AutoStoreTime;			// csn 08sep2005
	struct set_Enum AutoCalCheck;							// csn 08sep2005
	struct set_UnsignedInt AutoCalCheckTime;	// csn 08sep2005
	struct set_UnsignedInt StartDate;					// csn 08sep2005
	struct set_UnsignedInt EndDate;						// csn 08sep2005
	struct set_UnsignedInt RunTime1;					// csn 08sep2005
	struct set_UnsignedInt StopTime1;					// csn 08sep2005
	struct set_Enum EnableTimer2;							// csn 08sep2005
	struct set_UnsignedInt RunTime2;					// csn 08sep2005
	struct set_UnsignedInt StopTime2;					// csn 08sep2005
	struct set_Enum EnableTimer3;							// csn 08sep2005
	struct set_UnsignedInt RunTime3;					// csn 08sep2005
	struct set_UnsignedInt StopTime3;					// csn 08sep2005
	struct set_Enum LnTableEnable;						// csn 07dec2005

	// time history
	struct set_Enum TimeHistoryEnable;						// csn 16sep2005
	struct set_Enum TimeHistoryPeriod;						// csn 16sep2005
	struct set_UnsignedInt TimeHistoryOptions1;		// csn 16sep2005
	struct set_UnsignedInt TimeHistoryOptions2;	// csn 16sep2005
	
	// Stream history
	struct set_Enum StreamHistoryPeriod;				// ljd 9feb2006
	struct set_UnsignedInt StreamHistoryOptions;		// ljd 9feb2006
	
	// Exceedence history
	struct set_Enum ExceedenceHistoryEnable;							// csn	19sep2005
	struct set_Enum ExceedenceTimeHistoryEnable;					// csn	19sep2005
	struct set_Enum ExceedenceSpectralTimeHistoryEnable;	// csn	19sep2005
	struct set_Float MinimumDuration;											// csn	19sep2005
	struct set_Enum TriggerMethod;												// csn	19sep2005
	struct set_UnsignedInt ContinuationPeriod;						// csn	19sep2005
	struct set_Enum ExceedenceTimeHistoryPeriod;					// csn	19sep2005
	
	// markers
	struct set_String MarkerNames [NUM_MARKERS];					// csn	20sep2005
	struct set_Enum MarkerAudioRecord [NUM_MARKERS];			// csn	20sep2005
	struct set_UnsignedInt MarkerRecordPeriod;						// csn	20sep2005
	struct set_UnsignedInt MarkerPreRecordPeriod;					// csn	20sep2005

	// day/night (community noise)
	struct set_UnsignedInt DayTime;												// csn	22sep2005
	struct set_UnsignedInt EveningTime;										// csn	22sep2005
	struct set_UnsignedInt NightTime;											// csn	22sep2005
	struct set_Float EveningPenalty;											// csn	22sep2005
	struct set_Float NightPenalty;												// csn	22sep2005

	// audio
	struct set_Enum SaveExcdAudioSnapshot;										// csn	2sep2005
	struct set_UnsignedInt ExcdAudioSnapshotPeriod;						// csn	22sep2005
	struct set_UnsignedInt ExcdAudioSnapshotPreTriggerPeriod;	// csn	22sep2005
	struct set_Enum SaveMsmtAudioSnapshot;										// csn	22sep2005
	struct set_UnsignedInt MsmtAudioSnapshotPeriod;						// csn	22sep2005
	struct set_Enum SaveMsmtLevelDistributionTable;						// csn	22sep2005

//not used	struct set_String MeasurementDescription;	
	struct set_String DefaultFileName;
// SLM
	struct set_Enum SlmFrequencyWeighting;
	struct set_Enum PeakFrequencyWeighting;
	struct set_Enum SlmDetector;
	struct set_Enum SlmGain;		// 831 only
// SLM Overall use SLM values
	struct set_Enum IntegrationInput;
// History
	struct set_Int HistPeriod;
// Statistics
	struct set_TableFloatsLNS Percentiles;
// OBA
	struct set_Enum ObaRange;
	struct set_Enum ObaBandwidth;
	struct set_Enum ObaMaxSpectrumMode;	// csn 07sep2005
	struct set_Enum	ObaWeighting;

// Dose
	struct set_String DoseName[DOSE_CHANNELS];
	struct set_Float DoseThreshold[DOSE_CHANNELS];
	struct set_Enum DoseThresholdEnable[DOSE_CHANNELS];
	struct set_EnumFloats DoseExRate[DOSE_CHANNELS];
	struct set_Float DoseCriterionLevel[DOSE_CHANNELS];
	struct set_Float DoseCriterionTime[DOSE_CHANNELS];
// Events
	struct set_Enum EventWeighting[NUM_EVENT_COUNTERS];
	struct set_Enum EventDetector[NUM_EVENT_COUNTERS];
	struct set_Float EventLevel[NUM_EVENT_COUNTERS];
	struct set_Float DynamicTriggerOffsetLevel;	// csn 07sep2005
	struct set_Int DynamicResponse;	// csn 07sep2005
};
*/
// Deprecated structs

// Fileheader structure
typedef struct _FileHeader
{
	char   m_szSerialNumber[SZ16];
	int    m_iSerialNumber;
	char   m_szUser[SZ64];
	char   m_szLocation[SZ128];
	char   m_szJobDescription[SZ128];
	char   m_szNote[SZ512];
	char   m_szDataFileName[SZ16];
	char   m_szOverallTitle[SZ64];
	char   m_szModel[SZ16];
	char   m_szFirmwareRev[SZ16];
	char   m_szPreamp[SZ16];

	// unicode interface
	UNICHAR m_uszSerialNumber[SZ16];
	UNICHAR m_uszUser[SZ64];
	UNICHAR m_uszLocation[SZ128];
	UNICHAR m_uszJobDescription[SZ128];
	UNICHAR m_uszNote[SZ512];
	UNICHAR m_uszDataFileName[SZ16];
	UNICHAR m_uszOverallTitle[SZ64];
	UNICHAR m_uszModel[SZ16];
	UNICHAR m_uszFirmwareRev[SZ16];
	UNICHAR m_uszPreamp[SZ16];

} FileHeader;

typedef struct
{
	int		m_iLNTable [NUM_STAT_BINS+2]; // 831 checks from .10 to 200 dB add 2 for over and under which will always be empty but needed for the graph
	int 	m_iBaseDB;  // will always be 0
	int		m_iStatus;
	int		m_iSamples;	// NOT the number of ln bins....num of samples in this sample
} SlmLNInfo;

typedef struct _Spectra
{
	int m_nType;
	int m_nBandWidth;
	int m_nRange;
	float OverallSpectra[NUMSPECTRABINS];
	float MaxSpectra[NUMSPECTRABINS];
	float MinSpectra[NUMSPECTRABINS];
} SpectraInfo;

typedef struct _Exceedence
{
	float m_fDuration;
	int   m_nCount;
} Exceedence;

typedef struct _EventCounts
{
	int   m_nCount;
	float m_fDuration;
} EventCounts;

typedef struct _s_Localgps
{
	struct degmin latitude;   //struct degmin is defined in defines.h
	struct degmin longitude;
	float altitude; //(stored in SI meters)
} stLocalgps;

typedef struct _SPEECHDATA
{
	int   m_nNumSamples;  // number of frames
	int   m_nType;        // whether compressed VOICE OR AUDIO TAG_VOICE_COMP or TAG_VOICE OR TAG_AUDIO as the flag
	int   m_nSampleRate;  
	int   m_nNumBitsPerSample;  // for now fixed at 16
	int   m_nChannels;  // for now is 1
	int   m_nDataSize;  //how many bytes of data, not number of frames.
	// BECAUSE UNKNOWN SIZE, m_pbtData IS ALLOCATED IN THE TRANSLATOR AND THE CALLER MUST DELETE i.e. HeapDelete m_pbtData
	BYTE  *m_pbtData;   // all the frames: length in bytes of speex frame	data block
} stSPEECHDATA;										

// structure for run records (run, stop, pause, etc.)
typedef struct _RUNRECORD
{
	int    m_nType;
	int    m_nCause;
	time_t m_nDate;
	int    m_nVoiceDataIndex;  // this guy is incremented as voice records are added in and is used to access the VoiceData array
	int    m_nTHRecord;        // this is the # the TH record will look for
	int	 m_nCount;
} stRUNRECORD;

// Individual time history record. The number of float values and number of OBA structures
// that are valid is set in the 831. These values are stored in the Settings structure
// in the following variables:
// m_nNumFloatVals
// m_nNumOBA11Vals
// m_nNumOBA13Vals
typedef struct _ThRec
{
	unsigned int m_ulAction;
	long   m_nFlag;
	long   m_nRecordNum; 
	int    m_nTimeStamp;
	int    m_nMiscStartIndex;
	float  m_pfTHFloatVals[256]; // Number of valid values given by m_nNumFloatVals in Settings.
	float  m_pfTH11OBAVals[4][12];  // 0-4 spectra given by m_nNumOBA11Vals in Settings
	float  m_pfTH13OBAVals[4][36]; // 0-4 spectra given by m_nNumOBA13Vals in Settings
	float  m_fDuration;
} stThRec;

// Preference structure
typedef struct _Preferences
{
	int m_nDateFormat;
	int m_nDecimalFormat;
	int m_nLanguage;
	int m_nTaktMetricEnable;
	int m_nUnits;

	// the following fields were added 24apr2007
	float m_flFullOctaveReferenceSpectra1 [NUM11SPECTRABINS];
	float m_flFullOctaveReferenceSpectra2 [NUM11SPECTRABINS];
	float m_flFullOctaveReferenceSpectra3 [NUM11SPECTRABINS];
	float m_flFullOctaveReferenceSpectra4 [NUM11SPECTRABINS];
	float m_flThirdOctaveReferenceSpectra1 [NUMSPECTRABINS];
	float m_flThirdOctaveReferenceSpectra2 [NUMSPECTRABINS];
	float m_flThirdOctaveReferenceSpectra3 [NUMSPECTRABINS];
	float m_flThirdOctaveReferenceSpectra4 [NUMSPECTRABINS];
	char m_szFullOctaveReferenceSpectra1Name [12+1];
	char m_szFullOctaveReferenceSpectra2Name [12+1];
	char m_szFullOctaveReferenceSpectra3Name [12+1];
	char m_szFullOctaveReferenceSpectra4Name [12+1];
	char m_szThirdOctaveReferenceSpectra1Name [12+1];
	char m_szThirdOctaveReferenceSpectra2Name [12+1];
	char m_szThirdOctaveReferenceSpectra3Name [12+1];
	char m_szThirdOctaveReferenceSpectra4Name [12+1];

	// unicode interface
	UNICHAR m_uszFullOctaveReferenceSpectra1Name [12+1];
	UNICHAR m_uszFullOctaveReferenceSpectra2Name [12+1];
	UNICHAR m_uszFullOctaveReferenceSpectra3Name [12+1];
	UNICHAR m_uszFullOctaveReferenceSpectra4Name [12+1];
	UNICHAR m_uszThirdOctaveReferenceSpectra1Name [12+1];
	UNICHAR m_uszThirdOctaveReferenceSpectra2Name [12+1];
	UNICHAR m_uszThirdOctaveReferenceSpectra3Name [12+1];
	UNICHAR m_uszThirdOctaveReferenceSpectra4Name [12+1];

} stPreferences;

typedef struct _NoiseFloor
{
	int m_nNFPreampType;													// preamp type
	int m_nNFWeighting;														// freq weighting
	float m_fNFOverload;														// z-wght peak overload limit
	float m_fNFUnderRangeLimitsRms[UR_WGHT_SIZE];		// lower limit for RMS (under range or noise floor +10dB)
	float m_fNFUnderRangeLimitsPeak[UR_WGHT_SIZE];	// lower limit for peak under range indication
	float m_fNFUnderNoiseFloor[UR_WGHT_SIZE];				// combined noise floor
	// VER_NOISEFLOORS == 2 changes
   float fUnderRangeLimitsOctave[NUM_OCTAVES]; // lower limit for Octave under range or noise floor+10dB
   float fUnderRangeLimitsThirdOctave[NUM_THIRD_OCTAVES]; // lower limit for third octave under range or noise floor+10dB
   float fNoiseFloorOctave[NUM_OCTAVES]; // Noise Floor for Octave
   float fNoiseFloorThirdOctave[NUM_THIRD_OCTAVES]; // Noise Floor for third octave
} stNoiseFloor;

// extended error information
typedef struct _ExError
{
	unsigned int m_nExError;
} stExError;


typedef struct
{
	// dose settings
		TCHAR   m_TDoseName[9];
		BYTE		m_byThresholdLevelDB;
		BYTE		m_byExchangeRate;
		BYTE		m_byCriterionTimeHours;
		BYTE		m_byCriterionLevelDB;
		BOOL    m_bThreshEnable;
} SlmDose;

typedef struct
{
	// dose settings
		TCHAR   m_TDoseName[9];
		float		m_flThresholdLevelDB;
		BYTE		m_byExchangeRate;
		float		m_flCriterionTimeHours;
		float		m_flCriterionLevelDB;
		BOOL    m_bThreshEnable;
} SlmDose1;

// Dose settings structure
typedef struct _SlmDose	// deprecated.  use stSlmDose1 instead
{
	// dose settings
		char		m_szDoseName[9];
		BYTE		m_byThresholdLevelDB;
		BYTE		m_byExchangeRate;
		BYTE		m_byCriterionTimeHours;
		BYTE		m_byCriterionLevelDB;
		BOOL    m_bThreshEnable;
		// unicode interface
		UNICHAR	m_uszDoseName[9];
} stSlmDose;

typedef struct _SlmDose1
{
	// dose settings
		char		m_szDoseName[9];
		float		m_flThresholdLevelDB;
		BYTE		m_byExchangeRate;
		float		m_flCriterionTimeHours;
		float		m_flCriterionLevelDB;
		BOOL    m_bThreshEnable;
		// unicode interface
		UNICHAR	m_uszDoseName[9];
} stSlmDose1;

// This structure is used to retrieve the number of records for the
// data types that can have variable numbers of records.
typedef struct _DataCnts
{
	int m_nNumEvents;
	int m_nNumTH;
	int m_nNumMeas;
	int m_nNumVoice;
	int m_nNumAudio;
	int m_nNumRunRecs;
} DataCnts;

// This is the time history record for an exceedance when the 
// time history is enabled for exceedances. There may or may
// not be OBA data for the time history, depending on what 
// options are purchased and what OBA settings are enables.
// This is determined by the m_nOBASize in the Event Time
// History manager
typedef struct _stEThRec
{
	float m_fLevel;
	float m_fpOBA[36];
} stEThRec;

// The event time history manager structure to manage the individual 
// Event time history records stored in an array allocated by the slm translator
// and must be deleted using HeapDelete in C++ when the data is no longer in use.
typedef struct _ETHMngr
{
	//User must HeapDelete  m_pETHRecs 
	stEThRec *m_pETHRecs; 
	int m_nNumSamples;
	int m_nOBASize;
} stEthMngr;

// The structure to contain each exceedance record.
typedef struct _ExceedenceRec
{
	int    m_nID;
	int    m_nTHIndex;
	time_t m_ctStart;
	float  m_fDuration;
	float  m_fLeq;
	float  m_fMaxSPL;
	time_t m_ctMaxSPLTime;
	float  m_fLPeakMax;
	BOOL   m_bOBAOverLoad;
	BOOL   m_bOverLoad;
	BOOL   m_bTHOverLoad;
	BOOL   m_bOBATHOverLoad;
	int    m_nNumTHSamples;
	int    m_nNumPreTrigTHSamples;
	float  m_fTrigLevel;
	int    m_nSRNumber;
	int    m_nExcTHIndex;
	float  m_11OBALeq[12];   
	float  m_11OBALMax[12];  
	float  m_13OBALeq[36];   
	float  m_13OBALMax[36];  
	stEthMngr m_THData;
	int    m_nNumPostTrigTHSamples;
} stExceedence;

// The structure to contain the data for each measurement or level
typedef struct _Interval
{
	unsigned long	m_tStart;
	unsigned long m_tEnd;
	float   			m_fRunTime;
	float					m_flLeq;
	float         m_flLCeq;
	float         m_flLAeq;
	float         m_flSEL;
	float					m_flMax;
	float					m_flPeak;
	float					m_flMin;
	float   			m_flSEA;
	float   			m_fLTm5;
	unsigned long	m_tPeakMaxTime;  // cant use CTime because of constructor problems.
	unsigned long	m_tMaxTime;
	unsigned long	m_tMinTime;
	float					m_fPauseTime;
	int           m_pnLnTable[NUM_STAT_BINS];  
	int           m_nSRNumber;
	int           m_nNumOBA;
	float         m_fAltitude; //(stored in SI meters)
	float         m_fTWA[NUM_SLM_DOSES];
	// 12 OR 36 bins for each Ln so just set to 36
	float         m_pSpectralLn[NUM_LNS][36]; 
	float					m_fLNValues [NUM_LNS];
	float         m_fLNPercents [NUM_LNS];
	Exceedence		m_ExceedCnts[NUM_EVENT_COUNTERS];
	struct s_Weather    m_Weather;
	struct s_Overloads  m_CurrentOverloads;
	SpectraInfo		m_11Spectra;
	SpectraInfo		m_13Spectra;
	struct degmin m_dgLatitude;
	struct degmin m_dgLongitude;

	// impulsivity data
	// added csn 04apr2007
	float 				m_flLWIeq;
	float 				m_flLWeq;

	// schema 8 additions
	// added jtm 09/16/09
	struct s_RHTemp  m_426A12Data;
	// end schema 8 additions

} stInterval;

// Structure to contain all the settings in the 831 or LxT
typedef struct _Settings
{
	BYTE					m_byFrequencyWeighting;
	BYTE					m_byPeakWeighting;
	BYTE					m_byDetector;
 	stSlmDose			m_Doses[NUM_SLM_DOSES];	// deprecated.  use m_Doses1 instead
	float					m_flSplTrig1;
	float					m_flSplTrig2;
	float					m_flPeakTrig1;
	float					m_flPeakTrig2;
	float					m_flPeakTrig3;
	char					m_szMarkerNames[NUM_MARKERS][MARKER_LEN+1];
	short					m_sOBABandWidth;
	short         m_sOBARange;
	unsigned long m_ulTHFlags1; // These three variables are bitwise flags indicating which timehistory data 
	unsigned long m_ulTHFlags2; // were collected by the 831/LxT. See defines.h for the bitwise flags under
	int						m_nNumFloatVals;
	int						m_nNumOBA11Vals;
	int						m_nNumOBA13Vals;
	int						m_nTHMiscStartIndex; // used to keep track of where miscellaneous data starts in the Float array. Not needed by third party software
	float					m_iLNValues [NUM_LNS];
	short					m_sIntegration;
	unsigned int  m_uiMeasurementPeriod;
	int						m_SlmGain;
	int						m_nMeasLnTableEnable;
	char   				m_cstrOverallTitle[OVERALLTITLE_SIZE];
	int						m_iSamplePeriod;     // time history period
	//Community stuff
	unsigned long m_uiDayTime;
	unsigned long m_uiEveningTime;
	unsigned long m_uiNightTime;
	float					m_fEveningPenalty;
	float					m_fNightPenalty;
	//measurement Audio Stuff
	BOOL          m_bEnableAudioSnapShot;
	unsigned long m_uiMeasSnapShotPeriod;  //Interval Audio snapshot period
	unsigned long m_uiExcSnapShotPeriod;
	BOOL					m_bEnableExceedAudioSnapshot;
	int           m_nExcdTHCount;
	int           m_nExcdTHPreCount;
	int           m_nExcdTHSpectra;
	int           m_nExcdTHPeriod;
	unsigned long m_uiSnapShotPreTrig; //Exceedence Audio Pre Tirger period, called m_nPreTriggerPeriod in setupdata
	int           m_nMsmntSpectralLn;
	BYTE          m_byOBAWeighting;
		// added schema 12  // had an interim partial release so needed to change the schema
	int           m_nGPSControl;  // 0 off, 1  Auto,  2  On
	unsigned long m_uiPurOptions;

	float					m_flWindScale;
	char		 			m_szWindUnits [48];
	int						m_nWindDirection;
	float					m_flWindThreshold;
	float					m_flWindExcdLevel;
	float					m_flWindHysteresis;
	int						m_nWindPause;
	float					m_flADC1Scale;
	float					m_flADC1Offset;
	char 					m_szADC1Units [48];
	char 					m_szADC1Description [48];
	float					m_flADC2Scale;
	float					m_flADC2Offset;
	char 					m_szADC2Units [48];
	char 					m_szADC2Description [48];
	char					m_szSetupFileName [FILENAME_SIZE];
	unsigned long m_ulTHFlags3; // "SLM Any-Level Flags set in TimeHistoryOptions1"
	// changed to int to support Vaisala 12/10/08 (jtm)
	//BOOL								m_bWeatherEnabled;
	int								m_nWeatherOption;
	// schema 24 additions
	// added jtm 07/31/09
	int m_nOBAMaxSpectra;
	// end schema 24 additions

 	stSlmDose1		m_Doses1[NUM_SLM_DOSES];

	// unicode interface
	UNICHAR				m_uszMarkerNames[NUM_MARKERS][MARKER_LEN+1];
	UNICHAR				m_uszOverallTitle[OVERALLTITLE_SIZE];
	UNICHAR				m_uszWindUnits [48];
	UNICHAR 			m_uszADC1Units [48];
	UNICHAR 			m_uszADC1Description [48];
	UNICHAR 			m_uszADC2Units [48];
	UNICHAR 			m_uszADC2Description [48];
	UNICHAR				m_uszSetupFileName [FILENAME_SIZE];

} stSettings;

// structure to contain the overall data. If the spectral Ln table enable option
// is on, then the user must delete m_pSpectralLns, see comment below.
typedef struct _OverallData
{
	int					m_nTrig1Count;
	int					m_nTrig2Count;
	int					m_nPeakCount;
	int					m_nPeak2Count;
	int					m_nPeak3Count;
	float				m_fTrig1Duration;
	float				m_fTrig2Duration;
	float				m_fPeakDuration;
	float				m_fPeak2Duration;
	float				m_fPeak3Duration;
	time_t			m_tStart;  
	time_t			m_tEnd;
	float				m_fRunTime;
	int         m_nNumOBA;    // number of OBA values for the spectral LNs if any, either 12 or 36
	SpectraInfo	m_11Spectra;
	SpectraInfo	m_13Spectra;
	float				m_fPauseTime;
	char        m_szPreamp[16];
	float    		m_flLeq;
	float		    m_flMax;
	float    		m_flPeak;
	float    		m_flMin;
	float       m_flSEA;
	time_t			m_tPeakMaxTime;
	time_t			m_tMaxTime;
	time_t			m_tMinTime;
	float				m_flLAeq;
	float				m_flLCeq;
	float				m_fLTm5;
	float       m_fTWA[NUM_SLM_DOSES];
	struct s_Overloads  m_sOverLoads;
	struct s_DailyNoise m_DailyNoise;
	stLocalgps m_GPSData;

	// noisefloor data added csn 17jan2007
	float m_flURLimit;
	float m_flURPeak;
	float m_flURNoiseFloor;
	float m_flNFOverload;

	// impulsivity data added csn 04apr2007
	float m_flLWIeq;
	float m_flLWeq;

	// because this can be 2000 * 36 * 4 bytes large, allocate it only if necessary
	// THE INDIVIDUAL BUCKETS MUST BE DELETED BY THE CALLING ROUTINE IN 
	// A LOOP i.e. for NUM_THIRD_OCTAVES ... HeapDelete m_pSpectralLns[i]
	int        *m_pSpectralLns[NUM_THIRD_OCTAVES]; 

	// weather
	struct s_Weather m_Weather;

	// schema 25 additions
	// added jtm 09/16/09
	struct s_prm2102 m_426A12Info;
	struct s_RHTemp  m_426A12Data;
	// end schema 25 additions

	// unicode interface
	UNICHAR     m_uszPreamp[16];
} OverallData;


struct _s_caldata2 {
	int PreampType;
	unsigned int CalibrationDate;
	float CalibrationScale;	
	int Bins;
	float SpectralData [36];
};

struct _s_calhistory2 {
	struct _s_caldata2 data[CAL_TYPES][CAL_HISTS];
};

struct _s_calcheckhistory {
	struct _s_caldata2 data[CAL_HISTS];
  float flStdLevel[CAL_HISTS];
};

typedef struct _CalHistory2
{
	struct _s_calhistory2			m_CalHistory;
	struct _s_calcheckhistory	m_CalCheckHistory;
} stCalHistory;

// The main structure used by the translator to return the data
// retrieved by the translator one record at a time.
typedef struct _SlmRecord
{
	int nRecType;
	union 
	{
		OverallData   m_OVData;
		stSettings    m_Settings;
		FileHeader    m_FileHeader;
		stPreferences m_Prefs;
		stThRec       m_ThRec;
		stRUNRECORD   m_RunRec;
		stSPEECHDATA  m_SpeechRec;
		stSPEECHDATA  m_AudioRec;
		SlmLNInfo     m_OverAllLnTable;
		EventCounts   m_EvntCnts[NUM_EVENT_COUNTERS];
		stInterval    m_Interval;
		stExceedence  m_Exceedences;
		float         m_fTWA[NUM_SLM_DOSES];
		s_calhistory  m_CalHistory;
		stNoiseFloor  m_NoiseFloor;
		stCalHistory  m_CalHistory2;
		stExError     m_ExtendedError;
	} Record;
} stSlmRecord;

// Use this structure to retrieve all records of a given type
// when there can be a variable number of records.
typedef struct _SlmBulkRecords
{
	int nRecType;
	union
	{
		stThRec       *m_ThRecs;
		stInterval    *m_Interval;
		stExceedence  *m_Exceedences;
		stRUNRECORD		*m_RunRecord;
		stSPEECHDATA	*m_VoiceRecord;
		stSPEECHDATA	*m_AudioRecord;
	} record;
} stSlmBulkRecord;

#endif