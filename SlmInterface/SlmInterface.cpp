// SlmInterface.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

#include "SlmInterfaceData.h"
#include "waveWriter.h"

#include "..\Slm\SlmTranslator.h"

#include <stdlib.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include "comutil.h"

static HANDLE s_hHeap = NULL;

#define DllExport __declspec(dllexport)
//#define DllImport __declspec(dllimport)

typedef struct
{
    char	strItem[128];
    int		nItemData;
    float   fPeriod;
	int		nPeriodInMSecs;
} SPeriodInfo;

static SPeriodInfo PeriodInfo[] =
{
    {"20 ms",  ID_50PS, 0.020f, 20},
    {"50 ms",  ID_20PS, 0.050f, 50},
    {"100 ms", ID_10PS, 0.100f, 100},
    {"200 ms", ID_5PS, 0.200f, 200},
    {"500 ms", ID_2PS, 0.500f, 500},
    {"1 sec",  ID_1S, 1.0f, 1000},
    {"2 sec",  ID_2S, 2.0f, 2000},
    {"5 sec",  ID_5S, 5.0f, 5000},
    {"10 sec", ID_10S, 10.0f, 10000},
    {"15 sec", ID_15S, 15.0f, 15000},
    {"20 sec", ID_20S, 20.0f, 20000},
    {"30 sec", ID_30S, 30.0f, 30000},
    {"1 min",  ID_1MIN, 60.0f, 60000},
};

void CopySlmFileHeader(stFileHeader_t &src, slmSFileHeader_t &dest)
{
    dest.nSerialNumber = src.nSerialNumber;
    wcscpy_s(dest.uszSerialNumber, src.uszSerialNumber);
    wcscpy_s(dest.uszUser, src.uszUser);
    wcscpy_s(dest.uszLocation, src.uszLocation);
    wcscpy_s(dest.uszJobDescription, src.uszJobDescription);
    wcscpy_s(dest.uszNote, src.uszNote);
    wcscpy_s(dest.uszDataFileName, src.uszDataFileName);
    wcscpy_s(dest.uszOverallTitle, src.uszOverallTitle);
    wcscpy_s(dest.uszModel, src.uszModel);
    wcscpy_s(dest.uszFirmwareRev, src.uszFirmwareRev);
    wcscpy_s(dest.uszPreamp, src.uszPreamp);
}

void ReleaseSlmFileHeader(slmSFileHeader_t data)
{
    // Nothing to do here
}

void CopySpectraInfo(stSpectraInfo_t &src, slmSSpectraInfo_t &dest)
{
    dest.m_nType = src.m_nType;
    dest.m_nBandWidth = src.m_nBandWidth;
    dest.m_nRange = src.m_nRange;
    for (unsigned int i = 0; i < _countof(src.OverallSpectra); i++)
    {
        dest.OverallSpectra[i] = src.OverallSpectra[i];
    }
    for (unsigned int i = 0; i < _countof(src.MaxSpectra); i++)
    {
        dest.MaxSpectra[i] = src.MaxSpectra[i];
    }
    for (unsigned int i = 0; i < _countof(src.MinSpectra); i++)
    {
        dest.MinSpectra[i] = src.MinSpectra[i];
    }
}

void ReleaseSpectraInfo(slmSSpectraInfo_t data)
{
    // Nothing to do here
}

void CopySlmOverloads(s_Overloads &src, slmSOverloads &dest)
{
   dest.count = src.count;
   dest.duration = src.duration;
   dest.OBAcount = src.OBAcount;
   dest.OBAduration = src.OBAduration;
}

void ReleaseSlmOverloads(slmSOverloads data)
{
    // Nothing to do here
}

void CopySlmDailyNoise(s_DailyNoise &src, slmSDailyNoise &dest)
{
    for (unsigned int i = 0; i < _countof(src.HNL); i++)
    {
        dest.HNL[i] = src.HNL[i];
    }
    dest.Time = src.Time;
    for (unsigned int i = 0; i < _countof(src.TimeHr); i++)
    {
        dest.TimeHr[i] = src.TimeHr[i];
    }
    dest.Lden_Day = src.Lden_Day;
    dest.T_Lden_Day = src.T_Lden_Day;
    dest.Lden_Eve = src.Lden_Eve;
    dest.T_Lden_Eve = src.T_Lden_Eve;
    dest.Lden_Night = src.Lden_Night;
    dest.T_Lden_Night = src.T_Lden_Night;
    dest.Ldn_Day = src.Ldn_Day;
    dest.T_Ldn_Day = src.T_Ldn_Day;
    dest.Ldn_Night = src.Ldn_Night;
    dest.T_Ldn_Night = src.T_Ldn_Night;
}

void ReleaseSlmDailyNoise(slmSDailyNoise data)
{
    // Nothing to do here
}

void CopySlmDegmin(degmin &src, slmSDegmin &dest)
{
   dest.deg = src.deg;
   dest.min = src.min;
}

void ReleaseSlmDegmin(slmSDegmin data)
{
    // Nothing to do here
}

void CopySlmGpsData(s_gps &src, slmSGPS &dest)
{
    CopySlmDegmin(src.latitude, dest.latitude);
    CopySlmDegmin(src.longitude, dest.longitude);
    dest.altitude = src.altitude;
    dest.time = src.time;
    dest.date = src.date;
    dest.flags = src.flags;
}

void ReleaseSlmGpsData(slmSGPS data)
{
    ReleaseSlmDegmin(data.latitude);
    ReleaseSlmDegmin(data.longitude);
}

void CopySlmWeather(s_Weather &src, slmSWeather &dest)
{
    dest.WindSpeedAvg = src.WindSpeedAvg;
    dest.WindSpeedMax = src.WindSpeedAvg;
    dest.WindSpeedMin = src.WindSpeedAvg;
    for (unsigned int i = 0; i < _countof(src.WindDirStats); i++)
    {
        dest.WindDirStats[i] = src.WindDirStats[i];
    }
    dest.WindDirMax = src.WindDirMax;
    dest.ADC1Avg = src.ADC1Avg;
    dest.ADC1Max = src.ADC1Max;
    dest.ADC1Min = src.ADC1Min;
    dest.ADC2Avg = src.ADC2Avg;
    dest.ADC2Max = src.ADC2Max;
    dest.ADC2Min = src.ADC2Min;
    dest.ADC3Avg = src.ADC3Avg;
    dest.ADC3Max = src.ADC3Max;
    dest.ADC3Min = src.ADC3Min;
    dest.RainTotal = src.RainTotal;
    dest.RainMaxRate = src.RainMaxRate;
    dest.RainDuration = src.RainDuration;
    dest.WindAccm = src.WindAccm;
    dest.WindCount = src.WindCount;
    dest.ADC1Accm = src.ADC1Accm;
    dest.ADC1Count = src.ADC1Count;
    dest.ADC2Accm = src.ADC2Accm;
    dest.ADC2Count = src.ADC2Count;
    dest.ADC3Accm = src.ADC3Accm;
    dest.ADC3Count = src.ADC3Count;
    dest.HailTotal = src.HailTotal;
    dest.HailMaxRate = src.HailMaxRate;
    dest.HailDuration = src.HailDuration;
}

void ReleaseSlmWeather(slmSWeather data)
{
    // Nothing to do here
}

void CopySlmPRM2102(s_prm2102 &src, slmSPRM2102 &dest)
{
   dest.RH = src.RH;
   dest.Temp = src.Temp;
   dest.Dew = src.Dew;
   dest.modelnum = src.modelnum;
   dest.serialnum = src.serialnum;
   dest.flags = src.flags;
}

void ReleaseSlmPRM2102(slmSPRM2102 data)
{
    // Nothing to do here
}

void CopySlmRHTemp(s_RHTemp &src, slmSRHTemp &dest)
{
   dest.RHMax = src.RHMax;
   dest.TempMax = src.TempMax;
   dest.DewMax = src.DewMax;
   dest.RHMin = src.RHMin;
   dest.TempMin = src.TempMin;
   dest.DewMin = src.DewMin;
}

void ReleaseSlmRHTemp(slmSRHTemp data)
{
    // Nothing to do here
}

void CopySlmRA_Common(RA_Common_t &src, slmSRA_Common_t &dest)
{
   dest.total_count = src.total_count;
   dest.average_count = src.average_count;
   dest.numFreqBands = src.numFreqBands;
   dest.positions = src.positions;
}

void ReleaseSlmRA_Common(slmSRA_Common_t data)
{
    // Nothing to do here
}

void CopySlmRT60_SampleT2(RT60_SampleT2_t &src, slmSRT60_SampleT2_t &dest)
{
   dest.includedInAvg = src.includedInAvg;
   for (unsigned int i = 0; i < NUM_THIRD_OCTAVES; i++)
   {
       dest.Leq[i] = src.Leq[i];
       dest.Lmax[i] = src.Lmax[i];
       dest.Lbk[i] = src.Lbk[i];
       dest.EDT[i] = src.EDT[i];
       dest.T20[i] = src.T20[i];
       dest.T30[i] = src.T30[i];
       dest.Cu[i] = src.Cu[i];
       dest.Co_T20[i] = src.Co_T20[i];
       dest.Co_T30[i] = src.Co_T30[i];
       dest.SD_T20[i] = src.SD_T20[i];
       dest.SD_T30[i] = src.SD_T20[i];
   }
}

void ReleaseSlmRT60_SampleT2(slmSRT60_SampleT2_t data)
{
    // Nothing to do here
}

void CopySlmDataLimits(DataLimits_t &src, slmSDataLimits_t &dest)
{
   dest.StartPoint = src.StartPoint;
   dest.TwentydBPoint = src.TwentydBPoint;
   dest.ThirtydBPoint = src.ThirtydBPoint;
   dest.StopPoint = src.StopPoint;
}

void ReleaseSlmDataLimits(slmSDataLimits_t data)
{
    // Nothing to do here
}

void CopySlmRT60_SampleT2WithLimits(RT60_SampleT2WithLimits_t &src, slmSRT60_SampleT2WithLimits_t &dest)
{
   CopySlmRT60_SampleT2(src.T2, dest.T2);
   for (unsigned int i = 0; i < _countof(src.idxPts); i++)
   {
       CopySlmDataLimits(src.idxPts[i], dest.idxPts[i]);
   }
}

void ReleaseSlmRT60_SampleT2WithLimits(slmSRT60_SampleT2WithLimits_t data)
{
   ReleaseSlmRT60_SampleT2(data.T2);
   for (unsigned int i = 0; i < _countof(data.idxPts); i++)
   {
       ReleaseSlmDataLimits(data.idxPts[i]);
   }
}

void CopySlmRT60_AverageT2(RT60_AverageT2_t &src, slmSRT60_AverageT2_t &dest)
{
    CopySlmRA_Common(src.com, dest.com);
    CopySlmRT60_SampleT2(src.T2, dest.T2);
}

void ReleaseSlmRT60_AverageT2(slmSRT60_AverageT2_t data)
{
    ReleaseSlmRA_Common(data.com);
    ReleaseSlmRT60_SampleT2(data.T2);
}

void CopySlmOverallData(stOverallData_t &src, slmSOverallData_t &dest)
{
    dest.m_nTrig1Count = src.m_nTrig1Count;
    dest.m_nTrig2Count = src.m_nTrig2Count;
    dest.m_nTrig2Count = src.m_nTrig2Count;
    dest.m_nTrig2Count = src.m_nTrig2Count;
    dest.m_nPeak3Count = src.m_nTrig2Count;
    dest.m_fTrig1Duration = src.m_fTrig1Duration;
    dest.m_fTrig2Duration = src.m_fTrig2Duration;
    dest.m_fPeakDuration = src.m_fTrig2Duration;
    dest.m_fPeak2Duration = src.m_fPeak2Duration;
    dest.m_fPeak3Duration = src.m_fPeak3Duration;
    dest.m_tStart = src.m_tStart;
    dest.m_tEnd = src.m_tEnd;
    dest.m_fRunTime = src.m_fRunTime;
    dest.m_nNumOBA = src.m_nNumOBA;
    CopySpectraInfo(src.m_11Spectra, dest.m_11Spectra);
    CopySpectraInfo(src.m_13Spectra, dest.m_13Spectra);
    dest.m_fPauseTime = src.m_fPauseTime;
    {
        size_t convertedChars = 0;
        mbstowcs_s(&convertedChars, dest.m_uszPreamp, src.m_szPreamp, strlen(src.m_szPreamp));
    }
    dest.m_fLeq = src.m_fLeq;
    dest.m_fMax = src.m_fMax;
    dest.m_fPeak = src.m_fMax;
    dest.m_fMin = src.m_fMin;
    dest.m_fSEA = src.m_fSEA;
    dest.m_tPeakMaxTime = src.m_tPeakMaxTime;
    dest.m_tMaxTime = src.m_tMaxTime;
    dest.m_tMinTime = src.m_tMinTime;
    dest.m_fLAeq = src.m_fLAeq;
    dest.m_fLCeq = src.m_fLCeq;
    dest.m_fLTm5 = src.m_fLTm5;
    for (unsigned int i = 0; i < _countof(src.m_fTWA); i++)
    {
        dest.m_fTWA[i] = src.m_fTWA[i];
    }
    CopySlmOverloads(src.m_OverLoads, dest.m_OverLoads);
    CopySlmDailyNoise(src.m_DailyNoise, dest.m_DailyNoise);
    CopySlmGpsData(src.m_GPSData, dest.m_GPSData);
    dest.m_fURLimit = src.m_fURLimit;
    dest.m_fURPeak = src.m_fURPeak;
    dest.m_fURNoiseFloor = src.m_fURNoiseFloor;
    dest.m_fNFOverload = src.m_fNFOverload;
    dest.m_fLwIeq = src.m_fLwIeq;
    dest.m_fLweq = src.m_fLweq;
    for (unsigned int i = 0; i < _countof(src.m_pnSpectralLns); i++)
    {
        if (src.m_pnSpectralLns[i] != NULL)
        {
            dest.m_pnSpectralLns[i] = src.m_pnSpectralLns[i];
        }
    }
    CopySlmWeather(src.m_Weather, dest.m_Weather);
    CopySlmPRM2102(src.m_426A12Info, dest.m_426A12Info);
    CopySlmRHTemp(src.m_426A12Data, dest.m_426A12Data);
    CopySlmRT60_AverageT2(src.m_T2Avg, dest.m_T2Avg);
    wcscpy_s(dest.m_uszPreamp, src.m_uszPreamp);
}

void ReleaseSlmOverallData(slmSOverallData_t data)
{
    ReleaseSpectraInfo(data.m_11Spectra);
    ReleaseSpectraInfo(data.m_13Spectra);
    ReleaseSlmOverloads(data.m_OverLoads);
    ReleaseSlmDailyNoise(data.m_DailyNoise);
    ReleaseSlmGpsData(data.m_GPSData);
    if (data.m_pnSpectralLns[0] != NULL)
	{
		for (unsigned int i = 0; i < _countof(data.m_pnSpectralLns); i++)
		{
			if (data.m_pnSpectralLns[i] != NULL)
			{
				HeapFree(s_hHeap, 0, data.m_pnSpectralLns[i]);
			}
		}
	}
    ReleaseSlmWeather(data.m_Weather);
    ReleaseSlmPRM2102(data.m_426A12Info);
    ReleaseSlmRHTemp(data.m_426A12Data);
    ReleaseSlmRT60_AverageT2(data.m_T2Avg);
}

/*
void CopySlmDose(stSlmDose_t &src, slmSDose &dest)
{
    {
        size_t convertedChars = 0;
        mbstowcs_s(&convertedChars, dest.m_uszDoseName, src.m_szDoseName, strlen(src.m_szDoseName));
    }
    dest.m_byThresholdLevelDB = src.m_byThresholdLevelDB;
    dest.m_byExchangeRate = src.m_byExchangeRate;
    dest.m_byCriterionTimeHours = src.m_byCriterionTimeHours;
    dest.m_byCriterionLevelDB = src.m_byCriterionLevelDB;
    src.m_bThreshEnable ? dest.m_bThreshEnable = true : dest.m_bThreshEnable = false;
}

void ReleaseSlmDose(slmSDose data)
{
    // Nothing to do here
}

void PrintSlmDose(slmSDose &data)
{
    std::wstringstream dbg;
    dbg << "  m_uszDoseName = " << data.m_uszDoseName << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "  m_byThresholdLevelDB = " << data.m_byThresholdLevelDB << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "  m_byExchangeRate = " << data.m_byExchangeRate << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "  m_byCriterionTimeHours = " << data.m_byCriterionTimeHours << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "  m_byCriterionLevelDB = " << data.m_byCriterionLevelDB << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "  m_bThreshEnable = " << data.m_bThreshEnable << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
}
*/

void CopySlmDose1(stSlmDose1_t &src, slmSDose1 &dest)
{
    wcscpy_s(dest.m_uszDoseName, src.m_uszDoseName);
    dest.m_fThresholdLevelDB = src.m_fThresholdLevelDB;
    dest.m_byExchangeRate = src.m_byExchangeRate;
    dest.m_fCriterionTimeHours = src.m_fCriterionTimeHours;
    dest.m_fCriterionLevelDB = src.m_fCriterionLevelDB;
    src.m_bThreshEnable ? dest.m_bThreshEnable = true : dest.m_bThreshEnable = false;
}

void ReleaseSlmDose1(slmSDose1 data)
{
    // Nothing to do here
}

void PrintSlmDose1(slmSDose1 &data)
{
    std::wstringstream dbg;
    dbg << "  m_uszDoseName = " << data.m_uszDoseName << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "  m_fThresholdLevelDB = " << data.m_fThresholdLevelDB << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "  m_byExchangeRate = " << data.m_byExchangeRate << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "  m_fCriterionTimeHours = " << data.m_fCriterionTimeHours << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "  m_fCriterionLevelDB = " << data.m_fCriterionLevelDB << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "  m_bThreshEnable = " << data.m_bThreshEnable << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
}

void CopySlmSettings(stSettings_t &src, slmSSettings_t &dest)
{
    dest.m_byFrequencyWeighting = src.m_byFrequencyWeighting;
    dest.m_byPeakWeighting = src.m_byPeakWeighting;
    dest.m_byDetector = src.m_byDetector;
/*
    for (unsigned int i = 0; i < _countof(src.m_Doses); i++)
    {
        CopySlmDose(src.m_Doses[i], dest.m_Doses[i]);
    }
*/
    dest.m_fSplTrig1 = src.m_fSplTrig1;
    dest.m_fSplTrig2 = src.m_fSplTrig2;
    dest.m_fPeakTrig1 = src.m_fPeakTrig1;
    dest.m_fPeakTrig2 = src.m_fPeakTrig2;
    dest.m_fPeakTrig3 = src.m_fPeakTrig2;
    for (unsigned int i = 0; i < NUM_MARKERS; i++)
    {
        size_t convertedChars = 0;
        mbstowcs_s(&convertedChars, dest.m_uszMarkerNames[i], src.m_szMarkerNames[i], strlen(src.m_szMarkerNames[i]));
    }
    dest.m_nOBABandWidth = src.m_nOBABandWidth;
    dest.m_nOBARange = src.m_nOBARange;
    dest.m_uiTHFlags1 = src.m_uiTHFlags1;
    dest.m_uiTHFlags2 = src.m_uiTHFlags2;
    dest.m_nNumFloatVals = src.m_nNumFloatVals;
    dest.m_nNumOBA11Vals = src.m_nNumFloatVals;
    dest.m_nNumOBA13Vals = src.m_nNumOBA13Vals;
    dest.m_nTHMiscStartIndex = src.m_nTHMiscStartIndex;
    for (unsigned int i = 0; i < _countof(src.m_fLnValues); i++)
    {
        dest.m_fLnValues[i] = src.m_fLnValues[i];
    }
    dest.m_nIntegration = src.m_nIntegration;
    dest.m_ulMeasurementPeriod = src.m_ulMeasurementPeriod;
    dest.m_nSlmGain = src.m_nSlmGain;
    dest.m_nMeasLnTableEnable = src.m_nMeasLnTableEnable;
    {
        size_t convertedChars = 0;
        mbstowcs_s(&convertedChars, dest.m_uszOverallTitle, src.m_szOverallTitle, strlen(src.m_szOverallTitle));
    }
    dest.m_nSamplePeriod = src.m_nSamplePeriod;
	dest.m_nSamplePeriodInMSecs = 0;
    for (int i = 0; i < _countof(PeriodInfo); ++i)
    {
        if (PeriodInfo[i].nItemData == dest.m_nSamplePeriod)
        {
            dest.m_nSamplePeriodInMSecs = PeriodInfo[i].nPeriodInMSecs;
            break;
        }
    }
    dest.m_uiMeasCounts = src.m_uiMeasCounts;
    dest.m_ulDayTime = src.m_ulDayTime;
    dest.m_ulEveningTime = src.m_ulEveningTime;
    dest.m_ulNightTime = src.m_ulNightTime;
    dest.m_fEveningPenalty = src.m_fEveningPenalty;
    dest.m_fNightPenalty = src.m_fNightPenalty;
    src.m_bMeasSnapShotEnable ? dest.m_bMeasSnapShotEnable = true : dest.m_bMeasSnapShotEnable = false;
    dest.m_ulMeasSnapShotPeriod = src.m_ulMeasSnapShotPeriod;
    dest.m_ulExcSnapShotPeriod = src.m_ulExcSnapShotPeriod;
    src.m_bEnableExceedAudioSnapshot ? dest.m_bEnableExceedAudioSnapshot = true : dest.m_bEnableExceedAudioSnapshot = false;
    dest.m_nExcdTHCount = src.m_nExcdTHCount;
    dest.m_nExcdTHPreCount = src.m_nExcdTHPreCount;
    dest.m_nExcdTHSpectra = src.m_nExcdTHSpectra;
    dest.m_nExcdTHPeriod = src.m_nExcdTHPeriod;
    dest.m_ulSnapShotPreTrig = src.m_ulSnapShotPreTrig;
    dest.m_nMsmntSpectralLn = src.m_nMsmntSpectralLn;
    dest.m_byOBAWeighting = src.m_byOBAWeighting;
    dest.m_nGPSControl = src.m_nGPSControl;
    dest.m_uiPurOptions = src.m_uiPurOptions;
    dest.m_fWindScale = src.m_fWindScale;
    {
        size_t convertedChars = 0;
        mbstowcs_s(&convertedChars, dest.m_uszWindUnits, src.m_szWindUnits, strlen(src.m_szWindUnits));
    }
    dest.m_nWindDirection = src.m_nWindDirection;
    dest.m_fWindThreshold = src.m_fWindThreshold;
    dest.m_fWindExcdLevel = src.m_fWindExcdLevel;
    dest.m_fWindHysteresis = src.m_fWindHysteresis;
    dest.m_nWindPause = src.m_nWindPause;
    dest.m_fADC1Scale = src.m_fADC1Scale;
    dest.m_fADC1Offset = src.m_fADC1Offset;
    {
        size_t convertedChars = 0;
        mbstowcs_s(&convertedChars, dest.m_uszADC1Units, src.m_szADC1Units, strlen(src.m_szADC1Units));
        mbstowcs_s(&convertedChars, dest.m_uszADC1Description, src.m_szADC1Description, strlen(src.m_szADC1Description));
    }
    dest.m_fADC2Scale = src.m_fADC2Scale;
    dest.m_fADC2Offset = src.m_fADC2Offset;
    {
        size_t convertedChars = 0;
        mbstowcs_s(&convertedChars, dest.m_uszADC2Units, src.m_szADC2Units, strlen(src.m_szADC2Units));
        mbstowcs_s(&convertedChars, dest.m_uszADC2Description, src.m_szADC2Description, strlen(src.m_szADC2Description));
        mbstowcs_s(&convertedChars, dest.m_uszSetupFileName, src.m_szSetupFileName, strlen(src.m_szSetupFileName));
    }
    dest.m_uiTHFlags3 = src.m_uiTHFlags3;
    dest.m_nWeatherOption = src.m_nWeatherOption;
    dest.m_nOBAMaxSpectra = src.m_nOBAMaxSpectra;
    for (unsigned int i = 0; i < _countof(dest.m_Doses1); i++)
    {
        CopySlmDose1(src.m_Doses1[i], dest.m_Doses1[i]);
    }
    dest.m_nInstrumentMode = src.m_nInstrumentMode;
    dest.m_nRAExitTime = src.m_nRAExitTime;
    dest.m_nRALoBand = src.m_nRALoBand;
    dest.m_nRAHiBand = src.m_nRAHiBand;
    dest.m_nRT60NoiseType = src.m_nRT60NoiseType;
    dest.m_fRT60Attenuation = src.m_fRT60Attenuation;
    dest.m_nRT60TriggerMethod = src.m_nRT60TriggerMethod;
    dest.m_nRT60TriggerSource = src.m_nRT60TriggerSource;
    dest.m_fRT60TriggerLevel = src.m_fRT60TriggerLevel;
    dest.m_nRT60Bandwidth = src.m_nRT60Bandwidth;
    dest.m_nRT60BuildTime = src.m_nRT60BuildTime;
    dest.m_nRT60RunTime = src.m_nRT60RunTime;
    dest.m_nRT60RunCount = src.m_nRT60RunCount;
    dest.m_nRT60SamplePeriod = src.m_nRT60SamplePeriod;
    dest.m_nRT60SaveAverage = src.m_nRT60SaveAverage;
    dest.m_nRT60SaveAll = src.m_nRT60SaveAll;
    dest.m_nRTANoiseType = src.m_nRTANoiseType;
    dest.m_fRTAAttenuation = src.m_fRTAAttenuation;
    dest.m_nFftWindow = src.m_nFftWindow;
    dest.m_nFftFreqSpan = src.m_nFftFreqSpan;
    dest.m_nFftLines = src.m_nFftLines;
    dest.m_nFftRunMode = src.m_nFftRunMode;
    dest.m_nFftTonality = src.m_nFftTonality;
    dest.m_nToneSeekDelta = src.m_nToneSeekDelta;
    dest.m_nRegressionRange = src.m_nRegressionRange;
    dest.m_uiRunTimer = src.m_uiRunTimer;
    dest.m_bMeasHistEnabled = src.m_bMeasHistEnabled;
    dest.m_nVaisalaHeaterState = src.m_nVaisalaHeaterState;
    dest.m_nVaisalaHeaterEnaTime = src.m_nVaisalaHeaterEnaTime;
    dest.m_nVaisalaHeaterDisTime = src.m_nVaisalaHeaterEnaTime;
    for (unsigned int i = 0; i < NUM_MARKERS; i++)
    {
        wcscpy_s(dest.m_uszMarkerNames[i], src.m_uszMarkerNames[i]);
    }
    wcscpy_s(dest.m_uszOverallTitle, src.m_uszOverallTitle);
    wcscpy_s(dest.m_uszWindUnits, src.m_uszWindUnits);
    wcscpy_s(dest.m_uszADC1Units, src.m_uszWindUnits);
    wcscpy_s(dest.m_uszADC1Description, src.m_uszADC1Description);
    wcscpy_s(dest.m_uszADC2Units, src.m_uszADC2Units);
    wcscpy_s(dest.m_uszADC2Description, src.m_uszADC2Description);
    wcscpy_s(dest.m_uszSetupFileName, src.m_uszSetupFileName);
}

void ReleaseSlmSettings(slmSSettings_t data)
{
/*
    for (unsigned int i = 0; i < _countof(data.m_Doses); i++)
    {
        ReleaseSlmDose(data.m_Doses[i]);
    }
*/
    for (unsigned int i = 0; i < _countof(data.m_Doses1); i++)
    {
        ReleaseSlmDose1(data.m_Doses1[i]);
    }
}

void PrintSlmSettings(slmSSettings_t &data)
{
    std::wstringstream dbg;
    dbg << "m_byFrequencyWeighting = " << data.m_byFrequencyWeighting << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_byPeakWeighting = " << data.m_byPeakWeighting << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_byDetector = " << data.m_byDetector << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
/*
    for (unsigned int i = 0; i < _countof(data.m_Doses); i++)
    {
        dbg << "m_Doses[" << i << "]:" << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
        PrintSlmDose(data.m_Doses[i]);
    }
*/
    dbg << "m_fSplTrig1 = " << data.m_fSplTrig1 << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_fSplTrig2 = " << data.m_fSplTrig2 << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_fPeakTrig1 = " << data.m_fPeakTrig1 << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_fPeakTrig2 = " << data.m_fPeakTrig2 << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_fPeakTrig3 = " << data.m_fPeakTrig3 << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    for (unsigned int i = 0; i < NUM_MARKERS; i++)
    {
        dbg << "m_uszMarkerNames[" << i << "] = " << data.m_uszMarkerNames[i] << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    }
    dbg << "m_nOBABandWidth = " << data.m_nOBABandWidth << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_nOBARange = " << data.m_nOBARange << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_uiTHFlags1 = " << data.m_uiTHFlags1 << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_uiTHFlags2 = " << data.m_uiTHFlags2 << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_nNumFloatVals = " << data.m_nNumFloatVals << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_nNumOBA11Vals = " << data.m_nNumOBA11Vals << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_nNumOBA13Vals = " << data.m_nNumOBA13Vals << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_nTHMiscStartIndex = " << data.m_nTHMiscStartIndex << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    for (unsigned int i = 0; i < _countof(data.m_fLnValues); i++)
    {
        dbg << "m_fLnValues[" << i << "] = " << data.m_fLnValues[i] << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    }
    dbg << "m_nIntegration = " << data.m_nIntegration << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_ulMeasurementPeriod = " << data.m_ulMeasurementPeriod << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_nSlmGain = " << data.m_nSlmGain << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_nMeasLnTableEnable = " << data.m_nMeasLnTableEnable << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_uszOverallTitle = " << data.m_uszOverallTitle << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_nSamplePeriod = " << data.m_nSamplePeriod << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_uiMeasCounts = " << data.m_uiMeasCounts << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_ulDayTime = " << data.m_ulDayTime << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_ulEveningTime = " << data.m_ulEveningTime << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_ulNightTime = " << data.m_ulNightTime << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_fEveningPenalty = " << data.m_fEveningPenalty << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_fNightPenalty = " << data.m_fNightPenalty << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_bMeasSnapShotEnable = " << data.m_bMeasSnapShotEnable << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_ulMeasSnapShotPeriod = " << data.m_ulMeasSnapShotPeriod << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_ulExcSnapShotPeriod = " << data.m_ulExcSnapShotPeriod << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_bEnableExceedAudioSnapshot = " << data.m_bEnableExceedAudioSnapshot << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_nExcdTHCount = " << data.m_nExcdTHCount << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_nExcdTHPreCount = " << data.m_nExcdTHPreCount << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_nExcdTHSpectra = " << data.m_nExcdTHSpectra << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_nExcdTHPeriod = " << data.m_nExcdTHPeriod << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_ulSnapShotPreTrig = " << data.m_ulSnapShotPreTrig << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_nMsmntSpectralLn = " << data.m_nMsmntSpectralLn << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_byOBAWeighting = " << data.m_byOBAWeighting << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_nGPSControl = " << data.m_nGPSControl << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_uiPurOptions = " << data.m_uiPurOptions << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_fWindScale = " << data.m_fWindScale << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_uszWindUnits = " << data.m_uszWindUnits << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_nWindDirection = " << data.m_nWindDirection << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_fWindThreshold = " << data.m_fWindThreshold << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_fWindExcdLevel = " << data.m_fWindExcdLevel << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_fWindHysteresis = " << data.m_fWindHysteresis << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_nWindPause = " << data.m_nWindPause << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_fADC1Scale = " << data.m_fADC1Scale << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_fADC1Offset = " << data.m_fADC1Offset << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_uszADC1Units = " << data.m_uszADC1Units << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_uszADC1Description = " << data.m_uszADC1Description << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_fADC2Scale = " << data.m_fADC2Scale << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_fADC2Offset = " << data.m_fADC2Offset << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_uszADC2Units = " << data.m_uszADC2Units << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_uszADC2Description = " << data.m_uszADC2Description << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_uszSetupFileName = " << data.m_uszSetupFileName << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_uiTHFlags3 = " << data.m_uiTHFlags3 << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_nWeatherOption = " << data.m_nWeatherOption << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_nOBAMaxSpectra = " << data.m_nOBAMaxSpectra << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    for (unsigned int i = 0; i < _countof(data.m_Doses1); i++)
    {
        dbg << "m_Doses1[" << i << "]:" << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
        PrintSlmDose1(data.m_Doses1[i]);
    }
    dbg << "m_nInstrumentMode = " << data.m_nInstrumentMode << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_nRAExitTime = " << data.m_nRAExitTime << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_nRALoBand = " << data.m_nRALoBand << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_nRAHiBand = " << data.m_nRAHiBand << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_nRT60NoiseType = " << data.m_nRT60NoiseType << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_fRT60Attenuation = " << data.m_fRT60Attenuation << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_nRT60TriggerMethod = " << data.m_nRT60TriggerMethod << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_nRT60TriggerSource = " << data.m_nRT60TriggerSource << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_fRT60TriggerLevel = " << data.m_fRT60TriggerLevel << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_nRT60Bandwidth = " << data.m_nRT60Bandwidth << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_nRT60BuildTime = " << data.m_nRT60BuildTime << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_nRT60RunTime = " << data.m_nRT60RunTime << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_nRT60RunCount = " << data.m_nRT60RunCount << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_nRT60SamplePeriod = " << data.m_nRT60SamplePeriod << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_nRT60SaveAverage = " << data.m_nRT60SaveAverage << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_nRT60SaveAll = " << data.m_nRT60SaveAll << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_nRTANoiseType = " << data.m_nRTANoiseType << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_fRTAAttenuation = " << data.m_fRTAAttenuation << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_nFftWindow = " << data.m_nFftWindow << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_nFftFreqSpan = " << data.m_nFftFreqSpan << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_nFftLines = " << data.m_nFftLines << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_nFftRunMode = " << data.m_nFftRunMode << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_nFftTonality = " << data.m_nFftTonality << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_nToneSeekDelta = " << data.m_nToneSeekDelta << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_nRegressionRange = " << data.m_nRegressionRange << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_uiRunTimer = " << data.m_uiRunTimer << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_bMeasHistEnabled = " << data.m_bMeasHistEnabled << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_nVaisalaHeaterState = " << data.m_nVaisalaHeaterState << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_nVaisalaHeaterEnaTime = " << data.m_nVaisalaHeaterEnaTime << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_nVaisalaHeaterDisTime = " << data.m_nVaisalaHeaterDisTime << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    for (unsigned int i = 0; i < NUM_MARKERS; i++)
    {
        dbg << "m_uszMarkerNames[" << i << "] = " << data.m_uszMarkerNames[i] << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    }
    dbg << "m_uszOverallTitle = " << data.m_uszOverallTitle << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_uszWindUnits = " << data.m_uszWindUnits << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_uszADC1Units = " << data.m_uszADC1Units << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_uszADC1Description = " << data.m_uszADC1Description << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_uszADC2Units = " << data.m_uszADC2Units << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_uszADC2Description = " << data.m_uszADC2Description << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
    dbg << "m_uszSetupFileName = " << data.m_uszSetupFileName << std::endl; OutputDebugString(dbg.str().c_str()); dbg = std::wstringstream();
}

void CopySlmPrefs(stPreferences_t &src, slmSPreferences_t &dest)
{
    dest.m_nDateFormat = src.m_nDateFormat;
    dest.m_nDecimalFormat = src.m_nDecimalFormat;
    dest.m_nLanguage = src.m_nLanguage;
    dest.m_nTaktMetricEnable = src.m_nTaktMetricEnable;
    dest.m_nUnits = src.m_nUnits;
    dest.m_nRICorrection = src.m_nRICorrection;
    for (unsigned int i = 0; i < FULLOCTAVE_BINS; i++)
    {
        dest.m_fFullOctaveReferenceSpectra1[i] = src.m_fFullOctaveReferenceSpectra1[i];
        dest.m_fFullOctaveReferenceSpectra2[i] = src.m_fFullOctaveReferenceSpectra2[i];
        dest.m_fFullOctaveReferenceSpectra3[i] = src.m_fFullOctaveReferenceSpectra3[i];
        dest.m_fFullOctaveReferenceSpectra4[i] = src.m_fFullOctaveReferenceSpectra4[i];
    }
    for (unsigned int i = 0; i < THIRDOCTAVE_BINS; i++)
    {
        dest.m_fThirdOctaveReferenceSpectra1[i] = src.m_fThirdOctaveReferenceSpectra1[i];
        dest.m_fThirdOctaveReferenceSpectra2[i] = src.m_fThirdOctaveReferenceSpectra2[i];
        dest.m_fThirdOctaveReferenceSpectra3[i] = src.m_fThirdOctaveReferenceSpectra3[i];
        dest.m_fThirdOctaveReferenceSpectra4[i] = src.m_fThirdOctaveReferenceSpectra4[i];
    }
    wcscpy_s(dest.m_uszFullOctaveReferenceSpectra1Name, src.m_uszFullOctaveReferenceSpectra1Name);
    wcscpy_s(dest.m_uszFullOctaveReferenceSpectra2Name, src.m_uszFullOctaveReferenceSpectra2Name);
    wcscpy_s(dest.m_uszFullOctaveReferenceSpectra3Name, src.m_uszFullOctaveReferenceSpectra3Name);
    wcscpy_s(dest.m_uszFullOctaveReferenceSpectra4Name, src.m_uszFullOctaveReferenceSpectra4Name);
    wcscpy_s(dest.m_uszThirdOctaveReferenceSpectra1Name, src.m_uszThirdOctaveReferenceSpectra1Name);
    wcscpy_s(dest.m_uszThirdOctaveReferenceSpectra2Name, src.m_uszThirdOctaveReferenceSpectra2Name);
    wcscpy_s(dest.m_uszThirdOctaveReferenceSpectra3Name, src.m_uszThirdOctaveReferenceSpectra3Name);
    wcscpy_s(dest.m_uszThirdOctaveReferenceSpectra4Name, src.m_uszThirdOctaveReferenceSpectra4Name);
}

void ReleaseSlmPrefs(slmSPreferences_t data)
{
    // Nothing to do here
}

void CopySlmTimeHistory(stTimeHistory_t &src, slmSTimeHistory_t &dest)
{
    dest.m_nAction = src.m_nAction;
    dest.m_nFlag = src.m_nFlag;
    dest.m_nRecordNum = src.m_nRecordNum;
//    dest.m_nTimeStamp = src.m_nTimeStamp;
	dest.m_TimeStamp.tv_sec = src.m_nTimeStamp;
	dest.m_TimeStamp.tv_usec = 0;
    dest.m_nMiscStartIndex = src.m_nMiscStartIndex;
    for (unsigned int i = 0; i < _countof(src.m_pfTHFloatVals); i++)
    {
        dest.m_pfTHFloatVals[i] = src.m_pfTHFloatVals[i];
    }
    for (unsigned int i = 0; i < 4; i++)
    {
        for (unsigned int j = 0; j < FULLOCTAVE_BINS; j++)
        {
            dest.m_pfTH11OBAVals[i][j] = src.m_pfTH11OBAVals[i][j];
        }
        for (unsigned int j = 0; j < THIRDOCTAVE_BINS; j++)
        {
            dest.m_pfTH13OBAVals[i][j] = src.m_pfTH13OBAVals[i][j];
        }
    }
    dest.m_fDuration = src.m_fDuration;
}

void ReleaseSlmTimeHistory(slmSTimeHistory_t data)
{
    // Nothing to do here
}

void CopySlmRunRecord(stRunRecord_t &src, slmSRunRecord_t dest)
{
    dest.m_nType = src.m_nType;
    dest.m_nCause = src.m_nCause;
    dest.m_tDate = src.m_tDate;
    dest.m_nVoiceDataIndex = src.m_nVoiceDataIndex;
    dest.m_nTHRecord = src.m_nTHRecord;
    dest.m_nCount = src.m_nCount;
}

void ReleaseSlmRunRecord(slmSRunRecord_t data)
{
    // Nothing to do here
}

void CopySlmSpeechData(stSpeechData_t &src, slmSSpeechData &dest)
{
/*
    dest.m_nNumSamples = src.m_nNumSamples;
    dest.m_nType = src.m_nType;
    dest.m_nSampleRate = src.m_nType;
    dest.m_nNumBitsPerSample = src.m_nNumBitsPerSample;
    dest.m_nChannels = src.m_nChannels;
    dest.m_nDataSize = src.m_nDataSize;
    dest.m_pbyData = src.m_pbyData;
*/
	char strFile[MAX_PATH] = {0};
	if (dest.m_uszWavFile != NULL)
	{
		if (wcslen(dest.m_uszWavFile) > 0)
		{
			size_t size = wcslen(dest.m_uszWavFile);
			wcstombs_s(&size, strFile, dest.m_uszWavFile, MAX_PATH);
		}
	}
	if (strlen(strFile) == 0)
	{
/*
		unsigned int nCount = 0;
		char strName[MAX_PATH] = {0};
		do {
			nCount++;
			sprintf_s(strName, "file%d.wav", nCount);
		}
		while (GetFileAttributesA(strName) != INVALID_FILE_ATTRIBUTES);
		strncpy_s(strFile, strName, strlen(strName));
*/
		DWORD dwRetVal = 0;
		UINT uRetVal   = 0;
		WCHAR szTempFileName[MAX_PATH];  
		WCHAR lpTempPathBuffer[MAX_PATH];

		//  Gets the temp path env string (no guarantee it's a valid path).
		dwRetVal = GetTempPath(MAX_PATH,          // length of the buffer
							   lpTempPathBuffer); // buffer for path 
		if (dwRetVal > MAX_PATH || (dwRetVal == 0))
		{
/*
			PrintError(TEXT("GetTempPath failed"));
			return (2);
*/
		}

		//  Generates a temporary file name.
		uRetVal = GetTempFileName(lpTempPathBuffer, // directory for tmp files
								  TEXT("WAV"),      // temp file name prefix 
								  0,                // create unique name 
								  szTempFileName);  // buffer for name 
		if (uRetVal == 0)
		{
/*
			PrintError(TEXT("GetTempFileName failed"));
			return (3);
*/
		}
		else
		{
			std::wstring newExt = TEXT("wav");
			std::wstring temp = szTempFileName;
			std::wstring::size_type i = temp.rfind('.', temp.length());

			if (i != std::wstring::npos)
			{
				temp.replace(i + 1, newExt.length(), newExt);
			}

			size_t size = temp.length();
			wcstombs_s(&size, strFile, temp.c_str(), MAX_PATH);
		}
	}
	if (strlen(strFile) > 0)
	{


		// write out the wave file
		WaveWriter wavwriter( src.m_nNumBitsPerSample, src.m_nSampleRate, (src.m_nChannels == 2 ? WaveWriter::STEREO : WaveWriter::MONO) );
		if ( !wavwriter.write( strFile, (const char *)src.m_pbyData, src.m_nDataSize / (src.m_nNumBitsPerSample == 16 ? 2 : 1) ) )
		{
//				std::cout << "cannot create wave file" << std::endl;
		}
		else
		{
			size_t size = strlen(strFile);
			mbstowcs_s(&size, dest.m_uszWavFile, strFile, MAX_PATH);
		}
	}
}

void ReleaseSlmSpeechData(slmSSpeechData data)
{
//    HeapFree(s_hHeap, 0, data.m_pbyData);
}

void CopySlmLnInfo(stSlmLnInfo_t &src, slmSLnInfo_t &dest)
{
    for (unsigned int i = 0; i < _countof(dest.m_nLnTable); i++)
    {
        dest.m_nLnTable[i] = src.m_nLnTable[i];
    }
    dest.m_nBaseDB = src.m_nBaseDB;
    dest.m_nStatus = src.m_nBaseDB;
    dest.m_nSamples = src.m_nSamples;
}

void ReleaseSlmLnInfo(slmSLnInfo_t data)
{
    // Nothing to do here
}

void CopySlmEventCounts(stEventCounts_t &src, slmSEventCounts &dest)
{
    dest.m_nCount = src.m_nCount;
    dest.m_fDuration = src.m_fDuration;
}

void ReleaseSlmEventCounts(slmSEventCounts data)
{
    // Nothing to do here
}

void CopySlmSpectraInfo(stSpectraInfo_t &src, slmSSpectraInfo_t &dest)
{
    dest.m_nType = src.m_nType;
    dest.m_nBandWidth = src.m_nBandWidth;
    dest.m_nRange = src.m_nRange;
    for (unsigned int i = 0; i < NUMSPECTRABINS; i++)
    {
        dest.OverallSpectra[i] = src.OverallSpectra[i];
        dest.MaxSpectra[i] = src.MaxSpectra[i];
        dest.MinSpectra[i] = src.MinSpectra[i];
    }
}

void ReleaseSlmSpectraInfo(slmSSpectraInfo_t data)
{
    // Nothing to do here
}

void CopySlmInterval(stInterval_t &src, slmSInterval_t &dest)
{
    dest.m_tStart = src.m_tStart;
    dest.m_tEnd = src.m_tEnd;
    dest.m_fRunTime = src.m_fRunTime;
    dest.m_fLeq = src.m_fLeq;
    dest.m_fLCeq = src.m_fLCeq;
    dest.m_fLAeq = src.m_fLAeq;
    dest.m_fSEL = src.m_fSEL;
    dest.m_fMax = src.m_fMax;
    dest.m_fPeak = src.m_fPeak;
    dest.m_fMin = src.m_fMin;
    dest.m_fSEA = src.m_fSEA;
    dest.m_fLTm5 = src.m_fLTm5;
    dest.m_tPeakMaxTime = src.m_tPeakMaxTime;
    dest.m_tMaxTime = src.m_tMaxTime;
    dest.m_tMinTime = src.m_tMinTime;
    dest.m_fPauseTime = src.m_fPauseTime;
    for (unsigned int i = 0; i < _countof(src.m_nLnTable); i++)
    {
        dest.m_nLnTable[i] = src.m_nLnTable[i];
    }
    dest.m_nSRNumber = src.m_nSRNumber;
    dest.m_nNumOBA = src.m_nNumOBA;
    dest.m_fAltitude = src.m_fAltitude;
    for (unsigned int i = 0; i < _countof(src.m_fTWA); i++)
    {
        dest.m_fTWA[i] = src.m_fTWA[i];
    }
    for (unsigned int i = 0; i < NUM_LNS; i++)
    {
        for (unsigned int j = 0; j < _countof(src.m_fSpectralLn[i]); j++)
        {
            dest.m_fSpectralLn[i][j] = src.m_fSpectralLn[i][j];
        }
        dest.m_fLnValues[i] = src.m_fLnValues[i];
        dest.m_fLnPercents[i] = src.m_fLnPercents[i];
    }
    dest.m_fLwIeq = src.m_fLwIeq;
    dest.m_fLweq = src.m_fLweq;
    for (unsigned int i = 0; i < _countof(src.m_ExceedCnts); i++)
    {
        CopySlmEventCounts(src.m_ExceedCnts[i], dest.m_ExceedCnts[i]);
    }
    CopySlmWeather(src.m_Weather, dest.m_Weather);
    CopySlmOverloads(src.m_CurrentOverloads, dest.m_CurrentOverloads);
    CopySlmSpectraInfo(src.m_11Spectra, dest.m_11Spectra);
    CopySlmSpectraInfo(src.m_13Spectra, dest.m_13Spectra);
    CopySlmDegmin(src.m_dgLatitude, dest.m_dgLatitude);
    CopySlmDegmin(src.m_dgLongitude, dest.m_dgLongitude);
    CopySlmRHTemp(src.m_426A12Data, dest.m_426A12Data);
}

void ReleaseSlmInterval(slmSInterval_t data)
{
    for (unsigned int i = 0; i < _countof(data.m_ExceedCnts); i++)
    {
        ReleaseSlmEventCounts(data.m_ExceedCnts[i]);
    }
    ReleaseSlmWeather(data.m_Weather);
    ReleaseSlmOverloads(data.m_CurrentOverloads);
    ReleaseSlmSpectraInfo(data.m_11Spectra);
    ReleaseSlmSpectraInfo(data.m_13Spectra);
    ReleaseSlmDegmin(data.m_dgLatitude);
    ReleaseSlmDegmin(data.m_dgLongitude);
    ReleaseSlmRHTemp(data.m_426A12Data);
}

void CopyClmEventTimeHistory(stEventTimeHistory_t &src, slmSEventTimeHistory_t &dest)
{
    dest.m_fLevel = src.m_fLevel;
    for (unsigned int i = 0; i < _countof(src.m_fOBA); i++)
    {
        dest.m_fOBA[i] = src.m_fOBA[i];
    }
}

void ReleaseClmEventTimeHistory(slmSEventTimeHistory_t data)
{
    // Nothing to do here
}

void CopySlmEventTimeHistoryMngr(stEventTimeHistoryMngr_t &src, slmSEventTimeHistoryMngr_t &dest)
{
    if (dest.m_pETHRecs != NULL)
    {
        // Error
    }
    dest.m_pETHRecs = static_cast<slmSEventTimeHistory_t *>(HeapAlloc(s_hHeap, HEAP_ZERO_MEMORY, sizeof(slmSEventTimeHistory_t) * src.m_nNumSamples));
    for (unsigned int i = 0; i < static_cast<unsigned int>(src.m_nNumSamples); i++)
    {
        CopyClmEventTimeHistory(src.m_pETHRecs[i], dest.m_pETHRecs[i]);
    }
    dest.m_nNumSamples = src.m_nNumSamples;
    dest.m_nOBASize = src.m_nOBASize;
}

void ReleaseSlmEventTimeHistoryMngr(slmSEventTimeHistoryMngr_t data)
{
    for (unsigned int i = 0; i < static_cast<unsigned int>(data.m_nNumSamples); i++)
    {
        ReleaseClmEventTimeHistory(data.m_pETHRecs[i]);
    }
    HeapFree(s_hHeap, 0, data.m_pETHRecs);
}

void CopySlmExceedences(stExceedence_t &src, slmSExceedence_t &dest)
{
    dest.m_nID = src.m_nID;
    dest.m_nTHIndex = src.m_nTHIndex;
    dest.m_tStart = src.m_tStart;
    dest.m_fDuration = src.m_fDuration;
    dest.m_fLeq = src.m_fLeq;
    dest.m_fMaxSPL = src.m_fMaxSPL;
    dest.m_tMaxSPLTime = src.m_tMaxSPLTime;
    dest.m_fPeakMax = src.m_fPeakMax;
    src.m_bOBAOverLoad ? dest.m_bOBAOverLoad = true : dest.m_bOBAOverLoad = false;
    src.m_bOverLoad ? dest.m_bOverLoad = true : dest.m_bOverLoad = false;
    src.m_bTHOverLoad ? dest.m_bTHOverLoad = true : dest.m_bTHOverLoad = false;
    src.m_bOBATHOverLoad ? dest.m_bOBATHOverLoad = true : dest.m_bOBATHOverLoad = false;
    dest.m_nNumTHSamples = src.m_nNumTHSamples;
    dest.m_nNumPreTrigTHSamples = src.m_nNumPreTrigTHSamples;
    dest.m_fTrigLevel = src.m_fTrigLevel;
    dest.m_nSRNumber = src.m_nSRNumber;
    dest.m_nExcTHIndex = src.m_nExcTHIndex;
    for (unsigned int i = 0; i < FULLOCTAVE_BINS; i++)
    {
        dest.m_11OBALeq[i] = src.m_11OBALeq[i];
        dest.m_11OBALMax[i] = src.m_11OBALMax[i];
    }
    for (unsigned int i = 0; i < THIRDOCTAVE_BINS; i++)
    {
        dest.m_13OBALeq[i] = src.m_13OBALeq[i];
        dest.m_13OBALMax[i] = src.m_13OBALMax[i];
    }
    CopySlmEventTimeHistoryMngr(src.m_ETHData, dest.m_ETHData);
    dest.m_nNumPostTrigTHSamples = src.m_nNumPostTrigTHSamples;
    CopySlmRT60_SampleT2WithLimits(src.m_T2Sample, dest.m_T2Sample);
}

void ReleaseSlmExceedences(slmSExceedence_t data)
{
    ReleaseSlmEventTimeHistoryMngr(data.m_ETHData);
    ReleaseSlmRT60_SampleT2WithLimits(data.m_T2Sample);
}

void CopySlmCalData(s_caldata &src, slmSCalData &dest)
{
   for (unsigned int i = 0; i < SLM_CAL_HISTS; i++)
   {
       dest.CalibrationDate[i] = src.CalibrationDate[i];
       dest.CalibrationScale[i] = src.CalibrationScale[i];
   }
}

void ReleaseSlmCalData(slmSCalData data)
{
    // Nothing to do here
}

void CopySlmCalHistory(s_calhistory &src, slmSCalHistory &dest)
{
   for (unsigned int i = 0; i < _countof(src.types); i++)
   {
       CopySlmCalData(src.types[i], dest.types[i]);
   }
}

void ReleaseSlmCalHistory(slmSCalHistory data)
{
   for (unsigned int i = 0; i < _countof(data.types); i++)
   {
       ReleaseSlmCalData(data.types[i]);
   }
}

void CopySlmNoiseFloor(stNoiseFloor_t &src, slmSNoiseFloor &dest)
{
    dest.m_nNFPreampType = src.m_nNFPreampType;
    dest.m_nNFWeighting = src.m_nNFWeighting;
    dest.m_fNFOverload = src.m_fNFOverload;
    for (unsigned int i = 0; i < UR_WGHT_SIZE; i++)
    {
        dest.m_fNFUnderRangeLimitsRms[i] = src.m_fNFUnderRangeLimitsRms[i];
        dest.m_fNFUnderRangeLimitsPeak[i] = src.m_fNFUnderRangeLimitsPeak[i];
        dest.m_fNFUnderNoiseFloor[i] = src.m_fNFUnderNoiseFloor[i];
    }
    for (unsigned int i = 0; i < NUM_OCTAVES; i++)
    {
        dest.fUnderRangeLimitsOctave[i] = src.fUnderRangeLimitsOctave[i];
        dest.fNoiseFloorOctave[i] = src.fNoiseFloorOctave[i];
    }
    for (unsigned int i = 0; i < NUM_THIRD_OCTAVES; i++)
    {
        dest.fUnderRangeLimitsThirdOctave[i] = src.fUnderRangeLimitsThirdOctave[i];
        dest.fNoiseFloorThirdOctave[i] = src.fNoiseFloorThirdOctave[i];
    }
}

void ReleaseSlmNoiseFloor(slmSNoiseFloor data)
{
    // Nothing to do here
}

void CopySlmCalData2(s_caldata2 &src, slmSCalData2 &dest)
{
   dest.PreampType = src.PreampType;
   dest.CalibrationDate = src.CalibrationDate;
   dest.CalibrationScale = src.CalibrationScale;
   dest.Bins = src.Bins;
   for (unsigned int i = 0; i < _countof(dest.SpectralData); i++)
   {
       dest.SpectralData[i] = src.SpectralData[i];
   }
}

void ReleaseSlmCalData2(slmSCalData2 data)
{
    // Nothing to do here
}

void CopySlmCalCheckHistory(s_calcheckhistory &src, slmSCalCheckHistory &dest)
{
    for (unsigned int i = 0; i < CAL_HISTS; i++)
    {
        CopySlmCalData2(src.data[i], dest.data[i]);
        dest.fStdLevel[i] = src.fStdLevel[i];
    }
}

void ReleaseSlmCalCheckHistory(slmSCalCheckHistory data)
{
    for (unsigned int i = 0; i < CAL_HISTS; i++)
    {
        ReleaseSlmCalData2(data.data[i]);
    }
}

void CopySlmCalHistory2(stCalHistory2_t &src, slmSCalHistory2_t &dest)
{
    for (unsigned int i = 0; i < CAL_TYPES; i++)
    {
        for (unsigned int j = 0; j < CAL_HISTS; j++)
        {
            CopySlmCalData2(src.m_CalHistory.data[i][j], dest.m_CalHistory.data[i][j]);
        }
    }
    CopySlmCalCheckHistory(src.m_CalCheckHistory, dest.m_CalCheckHistory);
}

void ReleaseSlmCalHistory2(slmSCalHistory2_t data)
{
    for (unsigned int i = 0; i < CAL_TYPES; i++)
    {
        for (unsigned int j = 0; j < CAL_HISTS; j++)
        {
            ReleaseSlmCalData2(data.m_CalHistory.data[i][j]);
        }
    }
    ReleaseSlmCalCheckHistory(data.m_CalCheckHistory);
}

void CopySlmExError(stExError_t &src, slmSExError &dest)
{
    dest.m_nExError = src.m_nExError;
}

void ReleaseSlmExError(slmSExError data)
{
    // Nothing to do here
}

void CopySlmTimeSpectraLevel(ByTimeSpectraLevel_t &src, slmSByTimeSpectraLevel_t &dest)
{
    for (unsigned int i = 0; i < NUM_THIRD_OCTAVES; i++)
    {
        for (unsigned int j = 0; j < NUM_RT60_TIME_SAMPLES; j++)
        {
            dest.freqTime[i][j] = src.freqTime[i][j];
        }
        CopySlmDataLimits(src.idxPts[i], dest.idxPts[i]);
    }
    dest.total_count = src.total_count;
    dest.average_count = src.average_count;
    dest.sample_count = src.sample_count;
    dest.numFreqBands = src.numFreqBands;
    dest.preTriggerCount = src.preTriggerCount;
    dest.samplePeriod = src.samplePeriod;
    dest.RT60_Method = src.RT60_Method;
    dest.time_stamp = src.time_stamp;
}

void ReleaseSlmTimeSpectraLevel(slmSByTimeSpectraLevel_t data)
{
    for (unsigned int i = 0; i < NUM_THIRD_OCTAVES; i++)
    {
        ReleaseSlmDataLimits(data.idxPts[i]);
    }
}

void CopySlmFftInfo(stFftInfo_t &src, slmSFftInfo_t &dest)
{
    dest.uiFlags = src.uiFlags;
    dest.uiStartSec = src.uiStartSec;
    dest.uiStartuSec = src.uiStartuSec;
    dest.fDuration = src.fDuration;
    dest.nCount = src.nCount;
    dest.nOverloadCount = src.nOverloadCount;
    dest.fOverloadDuration = src.fOverloadDuration;
    dest.fLeq = src.fLeq;
    dest.fLpeak = src.fLpeak;
    dest.uiArraySize = src.uiArraySize;
}

void ReleaseSlmFftInfo(slmSFftInfo_t data)
{
    // Nothing to do here
}

void CopySlmFftLevels(stFftLevels_t &src, slmSFftLevels_t &dest)
{
    dest.pfLevelAvg = src.pfLevelAvg;
    dest.pfLevelMax = src.pfLevelMax;
}

void ReleaseSlmFftLevels(slmSFftLevels_t data)
{
    // Nothing to do here
}

void CopySlmFftRecord(stFftRecord_t &src, slmSFftRecord_t &dest)
{
    CopySlmFftInfo(src.stInfo, dest.stInfo);
    CopySlmFftLevels(src.stLevels, dest.stLevels);
    for (unsigned int i = 0; i < _countof(src.pfLevels); i++)
    {
        dest.fLevels[i] = *src.pfLevels[i];
    };
}

void ReleaseSlmFftRecord(slmSFftRecord_t data)
{
    ReleaseSlmFftInfo(data.stInfo);
    ReleaseSlmFftLevels(data.stLevels);
}

void CopySlmRecord(stSlmRecord_t &src, slmSRecord &dest)
{
    dest.nRecType = src.nRecType;

/*
    #define TYPE_SESSION                   4
    #define TYPE_CAL                       10
    #define TYPE_CALHISTORY                12
    #define TYPE_BYTIMEAVG                 14
    #define TYPE_FFT                       15
    #define TYPE_FFTHISTORY                16
    #define TYPE_FINISHED                  17
*/
    if (src.nRecType == TYPE_OVERALL)
    {
        CopySlmOverallData(src.m_OVData, dest.m_OVData);
    }
    if (src.nRecType == TYPE_SETTINGS)
    {
        CopySlmSettings(src.m_Settings, dest.m_Settings);
    }
//	CopySlmFileHeader(src.m_FileHeader, dest.m_FileHeader);
    if (src.nRecType == TYPE_PREFER)
    {
        CopySlmPrefs(src.m_Prefs, dest.m_Prefs);
    }
    if (src.nRecType == TYPE_TIMEHIST)
    {
        CopySlmTimeHistory(src.m_ThRec, dest.m_ThRec);
    }
//	CopySlmRunRecord(src.m_RunRec, dest.m_RunRec);
    if (src.nRecType == TYPE_VOICE)
    {
        CopySlmSpeechData(src.m_SpeechRec, dest.m_SpeechRec);
    }
    if (src.nRecType == TYPE_AUDIO)
    {
        CopySlmSpeechData(src.m_AudioRec, dest.m_AudioRec);
    }
    if (src.nRecType == TYPE_LN_TABLE)
    {
        CopySlmLnInfo(src.m_OverAllLnTable, dest.m_OverAllLnTable);
    }
/*
    for (unsigned int i = 0; i < _countof(src.m_EvntCnts); i++)
    {
        CopySlmEventCounts(src.m_EvntCnts[i], dest.m_EvntCnts[i]);
    }
*/
    if (src.nRecType == TYPE_INTERVAL)
    {
        CopySlmInterval(src.m_Interval, dest.m_Interval);
    }
    if (src.nRecType == TYPE_EXCEEDENCE)
    {
        CopySlmExceedences(src.m_Exceedences, dest.m_Exceedences);
    }
/*
    for (unsigned int i = 0; i < _countof(src.m_fTWA); i++)
    {
        src.m_fTWA[i] = src.m_fTWA[i];
    }
*/
//	CopySlmCalHistory(src.m_CalHistory, dest.m_CalHistory);
    if (src.nRecType == TYPE_NOISEFLOOR)
    {
        CopySlmNoiseFloor(src.m_NoiseFloor, dest.m_NoiseFloor);
    }
//	CopySlmCalHistory2(src.m_CalHistory2, dest.m_CalHistory2);
    if (src.nRecType == TYPE_EXTENDED_ERROR)
    {
        CopySlmExError(src.m_ExtendedError, dest.m_ExtendedError);
    }
//	CopySlmTimeSpectraLevel(src.m_ByTimeAvg, dest.m_ByTimeAvg);
//	CopySlmFftRecord(src.m_Fft, dest.m_Fft);
}

void ReleaseSlmRecord(slmSRecord data)
{
    ReleaseSlmOverallData(data.m_OVData);
    ReleaseSlmSettings(data.m_Settings);
    ReleaseSlmFileHeader(data.m_FileHeader);
    ReleaseSlmPrefs(data.m_Prefs);
    ReleaseSlmTimeHistory(data.m_ThRec);
    ReleaseSlmRunRecord(data.m_RunRec);
    ReleaseSlmSpeechData(data.m_SpeechRec);
    ReleaseSlmSpeechData(data.m_AudioRec);
    ReleaseSlmLnInfo(data.m_OverAllLnTable);
    for (unsigned int i = 0; i < _countof(data.m_EvntCnts); i++)
    {
        ReleaseSlmEventCounts(data.m_EvntCnts[i]);
    }
    ReleaseSlmInterval(data.m_Interval);
    ReleaseSlmExceedences(data.m_Exceedences);
    ReleaseSlmCalHistory(data.m_CalHistory);
    ReleaseSlmNoiseFloor(data.m_NoiseFloor);
    ReleaseSlmCalHistory2(data.m_CalHistory2);
    ReleaseSlmExError(data.m_ExtendedError);
    ReleaseSlmTimeSpectraLevel(data.m_ByTimeAvg);
    ReleaseSlmFftRecord(data.m_Fft);
}

void CopyBulkCountsEx(stDataCnts_t &src, slmSDataCnts_t &dest)
{
    dest.m_nNumEvents = src.m_nNumEvents;
    dest.m_nNumTH = src.m_nNumTH;
    dest.m_nNumMeas = src.m_nNumMeas;
    dest.m_nNumVoice = src.m_nNumVoice;
    dest.m_nNumAudio = src.m_nNumAudio;
    dest.m_nNumRunRecs = src.m_nNumRunRecs;
}

void ReleaseBulkCountsEx(slmSDataCnts_t data)
{
    // Nothing to do here
}

void CopySlmBulkRecord(const int nSamplePeriodInMSecs, stSlmBulkRecord_t &src, slmSBulkRecord_t &dest)
{
    dest.eRecType = static_cast<eTypeBulk>(src.nRecType);
    switch (dest.eRecType)
    {
        case eTypeBulkTh: // TYPE_BULK_TH
        {
            if (dest.m_pThRecs != NULL)
            {
				struct timeval lastTime = {0};
                for (unsigned int i = 0; i < static_cast<unsigned int>(dest.m_dataCounts.m_nNumTH); i++)
                {
                    CopySlmTimeHistory(src.m_ThRecs[i], dest.m_pThRecs[i]);

					if ((dest.m_pThRecs[i].m_TimeStamp.tv_sec == lastTime.tv_sec) && (dest.m_pThRecs[i].m_TimeStamp.tv_usec == 0))
					{
						dest.m_pThRecs[i].m_TimeStamp.tv_usec = lastTime.tv_usec + (nSamplePeriodInMSecs * 1000);
					}
					lastTime.tv_sec = dest.m_pThRecs[i].m_TimeStamp.tv_sec;
					lastTime.tv_usec = dest.m_pThRecs[i].m_TimeStamp.tv_usec;
                }
            }
        }
        break;
        case eTypeBulkEvnt: // TYPE_BULK_EVNT
        {
            if (dest.m_pInterval != NULL)
            {
                for (unsigned int i = 0; i < static_cast<unsigned int>(dest.m_dataCounts.m_nNumEvents); i++)
                {
                    CopySlmInterval(src.m_Interval[i], dest.m_pInterval[i]);
                }
            }
        }
        break;
        case eTypeBulkMeas: // TYPE_BULK_MEAS
        {
            if (dest.m_pExceedences != NULL)
            {
                for (unsigned int i = 0; i < static_cast<unsigned int>(dest.m_dataCounts.m_nNumMeas); i++)
                {
                    CopySlmExceedences(src.m_Exceedences[i], dest.m_pExceedences[i]);
                }
            }
        }
        break;
        case eTypeBulkRunRec: // TYPE_BULK_RUNREC
        {
            if (dest.m_pRunRecord != NULL)
            {
                for (unsigned int i = 0; i < static_cast<unsigned int>(dest.m_dataCounts.m_nNumRunRecs); i++)
                {
                    CopySlmRunRecord(src.m_RunRecord[i], dest.m_pRunRecord[i]);
                }
            }
        }
        break;
        case eTypeBulkVoice: // TYPE_BULK_VOICE
        {
            if (dest.m_pVoiceRecord != NULL)
            {
                for (unsigned int i = 0; i < static_cast<unsigned int>(dest.m_dataCounts.m_nNumVoice); i++)
                {
                    CopySlmSpeechData(src.m_VoiceRecord[i], dest.m_pVoiceRecord[i]);
                }
            }
        }
        break;
        case eTypeBulkAudio: // TYPE_BULK_AUDIO
        {
            if (dest.m_pAudioRecord != NULL)
            {
                for (unsigned int i = 0; i < static_cast<unsigned int>(dest.m_dataCounts.m_nNumAudio); i++)
                {
                    CopySlmSpeechData(src.m_AudioRecord[i], dest.m_pAudioRecord[i]);
                }
            }
        }
        break;
    }
}

void ReleaseSlmBulkRecord(slmSBulkRecord_t data)
{
    switch (data.eRecType)
    {
        case eTypeBulkTh: // TYPE_BULK_TH
        {
            if (data.m_pThRecs != NULL)
            {
                for (unsigned int i = 0; i < static_cast<unsigned int>(data.m_dataCounts.m_nNumTH); i++)
                {
                    ReleaseSlmTimeHistory(data.m_pThRecs[i]);
                }
            }
        }
        break;
        case eTypeBulkEvnt: // TYPE_BULK_EVNT
        {
            if (data.m_pInterval != NULL)
            {
                for (unsigned int i = 0; i < static_cast<unsigned int>(data.m_dataCounts.m_nNumEvents); i++)
                {
                    ReleaseSlmInterval(data.m_pInterval[i]);
                }
            }
        }
        break;
        case eTypeBulkMeas: // TYPE_BULK_MEAS
        {
            if (data.m_pExceedences != NULL)
            {
                for (unsigned int i = 0; i < static_cast<unsigned int>(data.m_dataCounts.m_nNumMeas); i++)
                {
                    ReleaseSlmExceedences(data.m_pExceedences[i]);
                }
            }
        }
        break;
        case eTypeBulkRunRec: // TYPE_BULK_RUNREC
        {
            if (data.m_pRunRecord != NULL)
            {
                for (unsigned int i = 0; i < static_cast<unsigned int>(data.m_dataCounts.m_nNumRunRecs); i++)
                {
                    ReleaseSlmRunRecord(data.m_pRunRecord[i]);
                }
            }
        }
        break;
        case eTypeBulkVoice: // TYPE_BULK_VOICE
        {
            if (data.m_pVoiceRecord != NULL)
            {
                for (unsigned int i = 0; i < static_cast<unsigned int>(data.m_dataCounts.m_nNumVoice); i++)
                {
                    ReleaseSlmSpeechData(data.m_pVoiceRecord[i]);
                }
            }
        }
        break;
        case eTypeBulkAudio: // TYPE_BULK_AUDIO
        {
            if (data.m_pAudioRecord != NULL)
            {
                for (unsigned int i = 0; i < static_cast<unsigned int>(data.m_dataCounts.m_nNumAudio); i++)
                {
                    ReleaseSlmSpeechData(data.m_pAudioRecord[i]);
                }
            }
        }
        break;
    }
}


void Init()
{
    s_hHeap = HeapCreate(0, 0, 0);
}

extern "C" DllExport bool SI_StartSlmTranslation(const wchar_t *pwstrFilename, int nIndex)
{
    char strFilename[MAX_PATH] = {0};
    size_t convertedChars = 0;
    wcstombs_s(&convertedChars, strFilename, pwstrFilename, MAX_PATH);
    if (StartSlmTranslation(strFilename, nIndex))
    {
        return true;
    }
    return false;
}

extern "C" DllExport void SI_EndSlmTranslation(void)
{
    return EndSlmTranslation();
}

extern "C" DllExport int SI_GetLDFileType(const wchar_t *pwstrFilename, int *pnVersion)
{
    char strFilename[MAX_PATH] = {0};
    size_t convertedChars = 0;
    wcstombs_s(&convertedChars, strFilename, pwstrFilename, MAX_PATH);
    return GetLDFileType(strFilename, pnVersion);
}

/*
extern "C" DllExport void SI_SetNotifyWnd(long hWnd, int nMsg)
{
    SetNotifyWnd(hWnd, nMsg);
}

extern "C" DllExport bool SI_ConvertUSBFileToBinFile(char **pszIn, int nFiles, char *pszOut)
{
    if (ConvertUSBFileToBinFile(pszIn, nFiles, pszOut))
    {
        return true;
    }
    return false;
}
*/

extern "C" DllExport bool SI_GetSlmHeaderEx(slmSFileHeader_t *pfh)
{
    stFileHeader_t fh = {0};
    bool bReturn = false;
    if (GetSlmHeaderEx(fh))
    {
        bReturn = true;

        CopySlmFileHeader(fh, *pfh);
    }
    return bReturn;
}

extern "C" DllExport bool SI_GetNextSlmRecordEx_Settings(slmSSettings_t *pSettings)
{
    if (pSettings == NULL)
    {
        return false;
    }

    bool bReturn = false;
    stSlmRecord_t slmRecord = {0};
    if (GetNextSlmRecordEx(&slmRecord, TYPE_SETTINGS))
    {
        CopySlmSettings(slmRecord.m_Settings, *pSettings);

        bReturn = true;
    }
    return bReturn;
}

extern "C" DllExport bool SI_GetNextSlmRecordEx(slmSRecord_t *pRec, int nIndex)
{
    if (pRec == NULL)
    {
        return false;
    }

    bool bReturn = false;
    stSlmRecord_t slmRecord = {0};
    if (GetNextSlmRecordEx(&slmRecord, nIndex))
    {
        CopySlmRecord(slmRecord, *pRec);

        bReturn = true;
    }
    return bReturn;
}

extern "C" DllExport void SI_GetBulkCountsEx(slmSDataCnts_t *pDataCnts)
{
    if (pDataCnts == NULL)
    {
        return;
    }

    stDataCnts_t	dataCnts = {0};
    GetBulkCountsEx(&dataCnts);
    CopyBulkCountsEx(dataCnts, *pDataCnts);
}

extern "C" DllExport bool SI_GetBulkDataEx(const int nSamplePeriodInMSecs, slmSBulkRecord_t *pSlmBulkRec)
{
    if (pSlmBulkRec == NULL)
    {
        return false;
    }

    bool bReturn = false;
    stSlmBulkRecord_t slmBulkRecord = {0};
    switch (pSlmBulkRec->eRecType)
    {
        case eTypeBulkTh: // TYPE_BULK_TH
        {
            slmBulkRecord.m_ThRecs = static_cast<stTimeHistory_t *>(HeapAlloc(s_hHeap, HEAP_ZERO_MEMORY, sizeof(stTimeHistory_t) * pSlmBulkRec->m_dataCounts.m_nNumTH));
            slmBulkRecord.nRecType = TYPE_BULK_TH;
        }
        break;
        case eTypeBulkEvnt: // TYPE_BULK_EVNT
        {
            slmBulkRecord.m_Interval = static_cast<stInterval_t *>(HeapAlloc(s_hHeap, HEAP_ZERO_MEMORY, sizeof(stInterval_t) * pSlmBulkRec->m_dataCounts.m_nNumEvents));
            slmBulkRecord.nRecType = TYPE_BULK_EVNT;
        }
        break;
        case eTypeBulkMeas: // TYPE_BULK_MEAS
        {
            slmBulkRecord.m_Exceedences = static_cast<stExceedence_t *>(HeapAlloc(s_hHeap, HEAP_ZERO_MEMORY, sizeof(stExceedence_t) * pSlmBulkRec->m_dataCounts.m_nNumMeas));
            slmBulkRecord.nRecType = TYPE_BULK_MEAS;
        }
        break;
        case eTypeBulkRunRec: // TYPE_BULK_RUNREC
        {
            slmBulkRecord.m_RunRecord = static_cast<stRunRecord_t *>(HeapAlloc(s_hHeap, HEAP_ZERO_MEMORY, sizeof(stRunRecord_t) * pSlmBulkRec->m_dataCounts.m_nNumRunRecs));
            slmBulkRecord.nRecType = TYPE_BULK_RUNREC;
        }
        break;
        case eTypeBulkVoice: // TYPE_BULK_VOICE
        {
            slmBulkRecord.m_VoiceRecord = static_cast<stSpeechData_t *>(HeapAlloc(s_hHeap, HEAP_ZERO_MEMORY, sizeof(stSpeechData_t) * pSlmBulkRec->m_dataCounts.m_nNumVoice));
            slmBulkRecord.nRecType = TYPE_BULK_VOICE;
        }
        break;
        case eTypeBulkAudio: // TYPE_BULK_AUDIO
        {
            slmBulkRecord.m_AudioRecord = static_cast<stSpeechData_t *>(HeapAlloc(s_hHeap, HEAP_ZERO_MEMORY, sizeof(stSpeechData_t) * pSlmBulkRec->m_dataCounts.m_nNumAudio));
            slmBulkRecord.nRecType = TYPE_BULK_AUDIO;
        }
        break;
    }

    if (GetBulkDataEx(&slmBulkRecord))
    {
        CopySlmBulkRecord(nSamplePeriodInMSecs, slmBulkRecord, *pSlmBulkRec);

        switch (slmBulkRecord.nRecType)
        {
            case TYPE_BULK_TH:
            {
                HeapFree(s_hHeap, 0, slmBulkRecord.m_ThRecs);
            }
            break;
            case TYPE_BULK_EVNT:
            {
                HeapFree(s_hHeap, 0, slmBulkRecord.m_Interval);
            }
            break;
            case TYPE_BULK_MEAS:
            {
                HeapFree(s_hHeap, 0, slmBulkRecord.m_Exceedences);
            }
            break;
            case TYPE_BULK_RUNREC:
            {
                HeapFree(s_hHeap, 0, slmBulkRecord.m_RunRecord);
            }
            break;
            case TYPE_BULK_VOICE:
            {
                HeapFree(s_hHeap, 0, slmBulkRecord.m_VoiceRecord);
            }
            break;
            case TYPE_BULK_AUDIO:
            {
                HeapFree(s_hHeap, 0, slmBulkRecord.m_AudioRecord);
            }
            break;
        }

        bReturn = true;
    }
    return bReturn;
}

extern "C" DllExport void SI_ReleaseSlmHeaderEx(slmSFileHeader_t *pfh)
{
    if (pfh == NULL)
    {
        return;
    }

    ReleaseSlmFileHeader(*pfh);
}

extern "C" DllExport void SI_ReleaseNextSlmRecordEx(slmSRecord_t *pRec)
{
    if (pRec == NULL)
    {
        return;
    }

    ReleaseSlmRecord(*pRec);
}

extern "C" DllExport void SI_ReleaseBulkCountsEx(slmSDataCnts_t *pDataCnts)
{
    if (pDataCnts == NULL)
    {
        return;
    }

    ReleaseBulkCountsEx(*pDataCnts);
}

extern "C" DllExport void SI_ReleaseBulkDataEx(slmSBulkRecord_t *pSlmBulkRec)
{
    if (pSlmBulkRec == NULL)
    {
        return;
    }

    ReleaseSlmBulkRecord(*pSlmBulkRec);
}

extern "C" DllExport int SI_GetInstrumentMode(void) // -1=N/A, 0=SLM, 1=RA, 2=FFT
{
    return GetInstrumentMode();
}
