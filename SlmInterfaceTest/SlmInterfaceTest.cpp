// SlmInterfaceTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <string>
#include <sstream>
#include <vector>

#include <SlmInterface.h>
#include "..\Slm\LxT831.h"

#define PRINT_DATA

typedef struct
{
    time_t   tTime;
    float    fData;
} SReplayData;

typedef struct
{
    int				nMask;
    std::wstring	wstrName;
} STimeHistoryOptions;

STimeHistoryOptions TimeHistoryOptions1 [] =
{
    {ID_TH_LEQ, L"ID_TH_LEQ"},
    {ID_TH_LPEAK, L"ID_TH_LPEAK"},
    {ID_TH_SPL, L"ID_TH_SPL"},
    {ID_TH_LMAX, L"ID_TH_LMAX"},
    {ID_TH_LMIN, L"ID_TH_LMIN"},
    {ID_TH_LTM5, L"ID_TH_LTM5"},
    {ID_TH_LTWA1, L"ID_TH_LTWA1"},
    {ID_TH_LTWA2, L"ID_TH_LTWA2"},
    {ID_TH_LTWA3, L"ID_TH_LTWA3"},
    {ID_TH_LTWA4, L"ID_TH_LTWA4"},
    {ID_TH_ALEQ, L"ID_TH_ALEQ"},
    {ID_TH_APEAK, L"ID_TH_APEAK"},
    {ID_TH_ASLOWSPL, L"ID_TH_ASLOWSPL"},
    {ID_TH_ASLOWMAX, L"ID_TH_ASLOWMAX"},
    {ID_TH_ASLOWMIN, L"ID_TH_ASLOWMIN"},
    {ID_TH_AFASTSPL, L"ID_TH_AFASTSPL"},
    {ID_TH_AFASTMAX, L"ID_TH_AFASTMAX"},
    {ID_TH_AFASTMIN, L"ID_TH_AFASTMIN"},
    {ID_TH_AIMPLSPL, L"ID_TH_AIMPLSPL"},
    {ID_TH_AIMPLMAX, L"ID_TH_AIMPLMAX"},
    {ID_TH_AIMPLMIN, L"ID_TH_AIMPLMIN"},
    {ID_TH_CLEQ, L"ID_TH_CLEQ"},
    {ID_TH_CPEAK, L"ID_TH_CPEAK"},
    {ID_TH_CSLOWSPL, L"ID_TH_CSLOWSPL"},
    {ID_TH_CSLOWMAX, L"ID_TH_CSLOWMAX"},
    {ID_TH_CSLOWMIN, L"ID_TH_CSLOWMIN"},
    {ID_TH_CFASTSPL, L"ID_TH_CFASTSPL"},
    {ID_TH_CFASTMAX, L"ID_TH_CFASTMAX"},
    {ID_TH_CFASTMIN, L"ID_TH_CFASTMIN"},
    {ID_TH_CIMPLSPL, L"ID_TH_CIMPLSPL"},
    {ID_TH_CIMPLMAX, L"ID_TH_CIMPLMAX"},
    {ID_TH_CIMPLMIN, L"ID_TH_CIMPLMIN"},
};

STimeHistoryOptions TimeHistoryOptions2 [] =
{
    {ID_TH_ZLEQ, L"ID_TH_ZLEQ"},
    {ID_TH_ZPEAK, L"ID_TH_ZPEAK"},
    {ID_TH_ZSLOWSPL, L"ID_TH_ZSLOWSPL"},
    {ID_TH_ZSLOWMAX, L"ID_TH_ZSLOWMAX"},
    {ID_TH_ZSLOWMIN, L"ID_TH_ZSLOWMIN"},
    {ID_TH_ZFASTSPL, L"ID_TH_ZFASTSPL"},
    {ID_TH_ZFASTMAX, L"ID_TH_ZFASTMAX"},
    {ID_TH_ZFASTMIN, L"ID_TH_ZFASTMIN"},
    {ID_TH_ZIMPLSPL, L"ID_TH_ZIMPLSPL"},
    {ID_TH_ZIMPLMAX, L"ID_TH_ZIMPLMAX"},
    {ID_TH_ZIMPLMIN, L"ID_TH_ZIMPLMIN"},
    {ID_TH_BATTERY, L"ID_TH_BATTERY"},
    {ID_TH_EXTPOWER, L"ID_TH_EXTPOWER"},
    {ID_TH_INTTEMP, L"ID_TH_INTTEMP"},
    {ID_TH_2102TEMPERATURE, L"ID_TH_2102TEMPERATURE"},
    {ID_TH_2102HUMIDITY, L"ID_TH_2102HUMIDITY"},
    {ID_TH_WINDSPD, L"ID_TH_WINDSPD"},
    {ID_TH_GUSTDIR, L"ID_TH_GUSTDIR"},
    {ID_TH_ADC1AVG, L"ID_TH_ADC1AVG"},
    {ID_TH_ADC2AVG, L"ID_TH_ADC2AVG"},
    {ID_TH_CMINUSA, L"ID_TH_CMINUSA"},
    {ID_TH_OBALEQ_UNUSED, L"ID_TH_OBALEQ_UNUSED"},
    {ID_TH_OBALMAX_UNUSED, L"ID_TH_OBALMAX_UNUSED"},
    {ID_TH_OBASPL_UNUSED, L"ID_TH_OBASPL_UNUSED"},
    {ID_TH_OBASPL11, L"ID_TH_OBASPL11"},
    {ID_TH_OBALEQ11, L"ID_TH_OBALEQ11"},
    {ID_TH_OBAMAX11, L"ID_TH_OBAMAX11"},
    {ID_TH_OBAMIN11, L"ID_TH_OBAMIN11"},
    {ID_TH_OBASPL13, L"ID_TH_OBASPL13"},
    {ID_TH_OBALEQ13, L"ID_TH_OBALEQ13"},
    {ID_TH_OBAMAX13, L"ID_TH_OBAMAX13"},
    {ID_TH_OBAMIN13, L"ID_TH_OBAMIN13"},
};

STimeHistoryOptions TimeHistoryOptions3 [] =
{
    {ID_TH_GUSTSPEED, L"ID_TH_GUSTSPEED"},
    {ID_TH_ADC1MAX, L"ID_TH_ADC1MAX"},
    {ID_TH_ADC1MIN, L"ID_TH_ADC1MIN"},
    {ID_TH_ADC2MAX, L"ID_TH_ADC2MAX"},
    {ID_TH_ADC2MIN, L"ID_TH_ADC2MIN"},
// reserved for future weather metrics
    {ID_TH_WEATHER1, L"ID_TH_WEATHER1"},
    {ID_TH_WEATHER2, L"ID_TH_WEATHER2"},
    {ID_TH_WEATHER3, L"ID_TH_WEATHER3"},
    {ID_TH_WEATHER4, L"ID_TH_WEATHER4"},
    {ID_TH_WEATHER5, L"ID_TH_WEATHER5"},
    {ID_TH_WEATHER6, L"ID_TH_WEATHER6"},
// option to save fractional portion of duration
    {ID_TH_DUR_FRAC, L"ID_TH_DUR_FRAC"},
// options for LXT-HSLOG option (OPT_LXT_HSLOG)
    {ID_TH_WSLOWSPL, L"ID_TH_WSLOWSPL"},
    {ID_TH_WFASTSPL, L"ID_TH_WFASTSPL"},
    {ID_TH_WIMPLSPL, L"ID_TH_WIMPLSPL"},
    {ID_TH_WIMPLMINUSLEQ, L"ID_TH_WIMPLMINUSLEQ"},
// options to save broadband Ln statistics
    {ID_TH_LN1, L"ID_TH_LN1"},
    {ID_TH_LN2, L"ID_TH_LN2"},
    {ID_TH_LN3, L"ID_TH_LN3"},
    {ID_TH_LN4, L"ID_TH_LN4"},
    {ID_TH_LN5, L"ID_TH_LN5"},
    {ID_TH_LN6, L"ID_TH_LN6"},
};

typedef struct
{
    std::wstring	wstrItem;
    int				nItemData;
    float			fPeriod;
} SPeriodInfo;

SPeriodInfo PeriodInfo [] =
{
    {L"20 ms",  ID_50PS, (float)0.020},
    {L"50 ms",  ID_20PS, (float)0.050},
    {L"100 ms", ID_10PS, (float)0.100},
    {L"200 ms", ID_5PS, (float)0.200},
    {L"500 ms", ID_2PS, (float)0.500},
    {L"1 sec",  ID_1S, (float)1.0},
    {L"2 sec",  ID_2S, (float)2.0},
    {L"5 sec",  ID_5S, (float)5.0},
    {L"10 sec", ID_10S, (float)10.0},
    {L"15 sec", ID_15S, (float)15.0},
    {L"20 sec", ID_20S, (float)20.0},
    {L"30 sec", ID_30S, (float)30.0},
    {L"1 min",  ID_1MIN, (float)60.0},
};


int _tmain(int argc, _TCHAR* argv[])
{
//    std::wstring strFile = L"..\\TestData\\20141102_133621.ldbin";
	std::wstring strFile = L"C:\\ProgramData\\AENZ\\RecordSituationViewerPlugin\\1502154c.LD0";
#ifdef PRINT_DATA
    std::wstringstream dbg;
#endif
    std::vector<SReplayData>	replayData;
    float						fPeriod;

    int nFileBinaryVersion = 0;
    int nFileType = SI_GetLDFileType(strFile.c_str(), &nFileBinaryVersion);

    int nFile = 1;
    while (SI_StartSlmTranslation(strFile.c_str(), nFile))
    {
        slmSFileHeader_t fileHeader = {0};
        SI_GetSlmHeaderEx(&fileHeader);

        slmSDataCnts dataCounts = {0};
        SI_GetBulkCountsEx(&dataCounts);
#ifdef PRINT_DATA
        dbg << "m_nNumEvents  = " << dataCounts.m_nNumEvents << std::endl; OutputDebugString(dbg.str().c_str()); dbg.clear();
        dbg << "m_nNumTH      = " << dataCounts.m_nNumTH << std::endl; OutputDebugString(dbg.str().c_str()); dbg.clear();
        dbg << "m_nNumMeas    = " << dataCounts.m_nNumMeas << std::endl; OutputDebugString(dbg.str().c_str()); dbg.clear();
        dbg << "m_nNumVoice   = " << dataCounts.m_nNumVoice << std::endl; OutputDebugString(dbg.str().c_str()); dbg.clear();
        dbg << "m_nNumAudio   = " << dataCounts.m_nNumAudio << std::endl; OutputDebugString(dbg.str().c_str()); dbg.clear();
        dbg << "m_nNumRunRecs = " << dataCounts.m_nNumRunRecs << std::endl; OutputDebugString(dbg.str().c_str()); dbg.clear();
#endif // PRINT_DATA

        slmSRecord slmRecordData = {0};
        slmSSettings settings = {0};
        if (SI_GetNextSlmRecordEx(&slmRecordData, 1 /* TYPE_SETTINGS */))
        {
#ifdef PRINT_DATA
            OutputDebugString(L"slmRecordData.nRecType = TYPE_SETTINGS\r\n");
            // These three variables are bitwise flags indicating which timehistory data
            // were collected by the 831/LxT. See defines.h for the bitwise flags under
            // "SLM Any-Level Flags set in TimeHistoryOptions1"
            {
                std::wstring wstrTimeHistoryOptions1;
                for (int i = 0; i < _countof(TimeHistoryOptions1); ++i)
                {
                    if ((slmRecordData.m_Settings.m_uiTHFlags1 & TimeHistoryOptions1[i].nMask) != 0)
                    {
                        if (wstrTimeHistoryOptions1.length() > 0)
                        {
                            wstrTimeHistoryOptions1 += L" ";
                        }
                        wstrTimeHistoryOptions1 += TimeHistoryOptions1[i].wstrName;
                    }
                }
                dbg << "  m_uiTHFlags1 = 0x" << std::hex << ", " << slmRecordData.m_Settings.m_uiTHFlags1 << wstrTimeHistoryOptions1 << std::endl; OutputDebugString(dbg.str().c_str()); dbg.clear();
            }
            {
                std::wstring wstrTimeHistoryOptions2;
                for (int i = 0; i < _countof(TimeHistoryOptions2); ++i)
                {
                    if ((slmRecordData.m_Settings.m_uiTHFlags2 & TimeHistoryOptions2[i].nMask) != 0)
                    {
                        if (wstrTimeHistoryOptions2.length() > 0)
                        {
                            wstrTimeHistoryOptions2 += L" ";
                        }
                        wstrTimeHistoryOptions2 += TimeHistoryOptions2[i].wstrName;
                    }
                }
                dbg << "  m_uiTHFlags2 = 0x" << std::hex << ", " << slmRecordData.m_Settings.m_uiTHFlags2 << wstrTimeHistoryOptions2 << std::endl; OutputDebugString(dbg.str().c_str()); dbg.clear();
            }
            {
                std::wstring wstrTimeHistoryOptions3;
                for (int i = 0; i < _countof(TimeHistoryOptions3); ++i)
                {
                    if ((slmRecordData.m_Settings.m_uiTHFlags3 & TimeHistoryOptions3[i].nMask) != 0)
                    {
                        if (wstrTimeHistoryOptions3.length() > 0)
                        {
                            wstrTimeHistoryOptions3 += L" ";
                        }
                        wstrTimeHistoryOptions3 += TimeHistoryOptions3[i].wstrName;
                    }
                }
                dbg << "  m_uiTHFlags3 = 0x" << std::hex << ", " << slmRecordData.m_Settings.m_uiTHFlags3 << wstrTimeHistoryOptions3 << std::endl; OutputDebugString(dbg.str().c_str()); dbg.clear();
            }
            dbg << "  m_nSamplePeriod = " << slmRecordData.m_Settings.m_nSamplePeriod << std::endl; OutputDebugString(dbg.str().c_str()); dbg.clear();
            dbg << "  m_nNumFloatVals = " << slmRecordData.m_Settings.m_nNumFloatVals << std::endl; OutputDebugString(dbg.str().c_str()); dbg.clear();
#endif // PRINT_DATA

            settings = slmRecordData.m_Settings;
        }

        if (settings.m_nNumFloatVals > 0)
        {
            for (int i = 0; i < _countof(PeriodInfo); ++i)
            {
                if (PeriodInfo[i].nItemData == slmRecordData.m_Settings.m_nSamplePeriod)
                {
                    fPeriod = PeriodInfo[i].fPeriod;
                    break;
                }
            }

            slmSBulkRecords bulkRecord;
            bulkRecord.m_pThRecs = new slmSTimeHistory_t[dataCounts.m_nNumTH];
            bulkRecord.m_dataCounts.m_nNumTH = dataCounts.m_nNumTH;
            bulkRecord.eRecType = eTypeBulkTh;
            if (SI_GetBulkDataEx(&bulkRecord))
            {
                for (int i = 0; i < dataCounts.m_nNumTH; ++i)
                {
#ifdef PRINT_DATA2
                    qDebug() << "bulkRecord.m_ThRecs[" << i << "]";
                    qDebug() << "  m_nAction    = 0x" << hex << bulkRecord.m_ThRecs[i].m_nAction;
                    qDebug() << "  m_nFlag      = 0x" << hex << bulkRecord.m_ThRecs[i].m_nFlag;
                    qDebug() << "  m_nRecordNum = " << bulkRecord.m_ThRecs[i].m_nRecordNum;
                    qDebug() << "  m_nTimeStamp = " << QDateTime::fromTime_t(bulkRecord.m_ThRecs[i].m_nTimeStamp);
//                    qDebug() << "  m_pfTHFloatVals = " << slmRecordData.m_ThRec.m_pfTHFloatVals[256]; // Number of valid values given by m_nNumFloatVals in Settings.
                    for (int j = 0; j < slmRecordData.m_Settings.m_nNumFloatVals; ++j)
                    {
                        qDebug() << "  m_pfTHFloatVals[" << i << "] = " << bulkRecord.m_ThRecs[i].m_pfTHFloatVals[j];
                    }
                    qDebug() << "  m_fDuration = " << bulkRecord.m_ThRecs[i].m_fDuration;
#endif // PRINT_DATA2

                    if (bulkRecord.m_pThRecs[i].m_nFlag == 0)
                    {
                        SReplayData data;
                        data.tTime = bulkRecord.m_pThRecs[i].m_nTimeStamp;
                        data.fData = bulkRecord.m_pThRecs[i].m_pfTHFloatVals[0];
#ifdef PRINT_DATA2
                        qDebug() << data.qTime << data.fData;
#endif // PRINT_DATA2

                        replayData.push_back(data);
                    }
                }
            }
            else
            {
                OutputDebugString(L"GetBulkDataEx() failed\r\n");
            }
            delete bulkRecord.m_pThRecs;
            bulkRecord.m_pThRecs = NULL;
        }

#if DEPRECATED
        stSlmRecord_t slmRecordData;
        stSettings_t  settings;
        bool bContinue = true;
        while (bContinue && GetNextSlmRecordEx(&slmRecordData, TYPE_ALL))
        {
            switch (slmRecordData.nRecType)
            {
//                    case TYPE_PREFER: qDebug() << "slmRecordData.nRecType = TYPE_PREFER"; break; // m_Prefer
                case TYPE_SETTINGS:
                {
                    qDebug() << "slmRecordData.nRecType = TYPE_SETTINGS";
                    // These three variables are bitwise flags indicating which timehistory data
                    // were collected by the 831/LxT. See defines.h for the bitwise flags under
                    // "SLM Any-Level Flags set in TimeHistoryOptions1"
                    qDebug() << "  m_uiTHFlags1 = 0x" << hex << slmRecordData.m_Settings.m_uiTHFlags1;
                    qDebug() << "  m_uiTHFlags2 = 0x" << hex << slmRecordData.m_Settings.m_uiTHFlags2;
                    qDebug() << "  m_uiTHFlags3 = 0x" << hex << slmRecordData.m_Settings.m_uiTHFlags3;
                    qDebug() << "  m_nSamplePeriod = " << slmRecordData.m_Settings.m_nSamplePeriod;
                    qDebug() << "  m_nNumFloatVals = " << slmRecordData.m_Settings.m_nNumFloatVals;

                    if (slmRecordData.m_Settings.m_nNumFloatVals == 0)
                    {
                        bContinue = false;
                        break;
                    }

                    settings = slmRecordData.m_Settings;

                    for (unsigned int i = 0; i < _countof(PeriodInfo); ++i)
                    {
                        if (PeriodInfo[i].nItemData == slmRecordData.m_Settings.m_nSamplePeriod)
                        {
                            fPeriod = PeriodInfo[i].fPeriod;
                            break;
                        }
                    }
                }
                break;
/*
                case TYPE_OVERALL: qDebug() << "slmRecordData.nRecType = TYPE_OVERALL"; break;
                case TYPE_LN_TABLE: qDebug() << "slmRecordData.nRecType = TYPE_LN_TABLE"; break;
                case TYPE_SESSION: qDebug() << "slmRecordData.nRecType = TYPE_SESSION"; break;
                case TYPE_AUDIO: qDebug() << "slmRecordData.nRecType = TYPE_AUDIO"; break;
*/
                case TYPE_TIMEHIST:
                {
                    qDebug() << "slmRecordData.nRecType = TYPE_TIMEHIST";
                    qDebug() << "  m_nAction    = 0x" << hex << slmRecordData.m_ThRec.m_nAction;
                    qDebug() << "  m_nFlag      = 0x" << hex << slmRecordData.m_ThRec.m_nFlag;
                    qDebug() << "  m_nRecordNum = " << slmRecordData.m_ThRec.m_nRecordNum;
                    qDebug() << "  m_nTimeStamp = " << QDateTime::fromTime_t(slmRecordData.m_ThRec.m_nTimeStamp);
                    qDebug() << "  m_nMiscStartIndex = " << slmRecordData.m_ThRec.m_nMiscStartIndex;
//                        qDebug() << "  m_pfTHFloatVals = " << slmRecordData.m_ThRec.m_pfTHFloatVals[256]; // Number of valid values given by m_nNumFloatVals in Settings.
                    for (int i = 0; i < settings.m_nNumFloatVals; ++i)
                    {
                        qDebug() << "  m_pfTHFloatVals[" << i << "] = " << slmRecordData.m_ThRec.m_pfTHFloatVals[i];
                    }
//                        qDebug() << "  m_pfTH11OBAVals = " << slmRecordData.m_ThRec.m_pfTH11OBAVals[4][FULLOCTAVE_BINS];  // 0-4 spectra given by m_nNumOBA11Vals in Settings
//                        qDebug() << "  m_pfTH13OBAVals = " << slmRecordData.m_ThRec.m_pfTH13OBAVals[4][THIRDOCTAVE_BINS]; // 0-4 spectra given by m_nNumOBA13Vals in Settings
                    qDebug() << "  m_fDuration = " << slmRecordData.m_ThRec.m_fDuration;

                    if (slmRecordData.m_ThRec.m_nFlag == 0)
                    {
                        SReplayData data;
                        data.qTime = QDateTime::fromTime_t(slmRecordData.m_ThRec.m_nTimeStamp);
                        data.fData = slmRecordData.m_ThRec.m_pfTHFloatVals[0];

                        replayData.append(data);
                    }
                }
                break;
//                    case TYPE_VOICE: qDebug() << "slmRecordData.nRecType = TYPE_VOICE"; break;
                case TYPE_INTERVAL:
                {
                    qDebug() << "slmRecordData.nRecType = TYPE_INTERVAL";
                    qDebug() << "  m_tStart = " << QDateTime::fromTime_t(slmRecordData.m_Interval.m_tStart);
                    qDebug() << "  m_tEnd   = " << QDateTime::fromTime_t(slmRecordData.m_Interval.m_tEnd);
                    qDebug() << "  m_fRunTime = " << slmRecordData.m_Interval.m_fRunTime;
                    qDebug() << "  m_fLeq     = " << slmRecordData.m_Interval.m_fLeq;
                    qDebug() << "  m_fLCeq    = " << slmRecordData.m_Interval.m_fLCeq;
                    qDebug() << "  m_fLAeq    = " << slmRecordData.m_Interval.m_fLAeq;
                    qDebug() << "  m_fSEL     = " << slmRecordData.m_Interval.m_fSEL;
                    qDebug() << "  m_fMax     = " << slmRecordData.m_Interval.m_fMax;
                    qDebug() << "  m_fPeak    = " << slmRecordData.m_Interval.m_fPeak;
                    qDebug() << "  m_fMin     = " << slmRecordData.m_Interval.m_fMin;
                    qDebug() << "  m_fSEA     = " << slmRecordData.m_Interval.m_fSEA;
                    qDebug() << "  m_fLTm5    = " << slmRecordData.m_Interval.m_fLTm5;
                }
                break;
/*
                case TYPE_EXCEEDENCE: qDebug() << "slmRecordData.nRecType = TYPE_EXCEEDENCE"; break;
                case TYPE_CAL: qDebug() << "slmRecordData.nRecType = TYPE_CAL"; break;
                case TYPE_NOISEFLOOR: qDebug() << "slmRecordData.nRecType = TYPE_NOISEFLOOR"; break;
                case TYPE_CALHISTORY: qDebug() << "slmRecordData.nRecType = TYPE_CALHISTORY"; break;
                case TYPE_EXTENDED_ERROR: qDebug() << "slmRecordData.nRecType = TYPE_EXTENDED_ERROR"; break;
                case TYPE_BYTIMEAVG: qDebug() << "slmRecordData.nRecType = TYPE_BYTIMEAVG"; break;
                case TYPE_FFT: qDebug() << "slmRecordData.nRecType = TYPE_FFT"; break;
                case TYPE_FFTHISTORY: qDebug() << "slmRecordData.nRecType = TYPE_FFTHISTORY"; break;
                case TYPE_FINISHED: qDebug() << "slmRecordData.nRecType = TYPE_FINISHED"; break;
                default: qDebug() << "slmRecordData.nRecType = " << slmRecordData.nRecType; break;
*/
#endif // 0

        SI_EndSlmTranslation();
        nFile++;
    }

    if (replayData.size() == 0)
    {
//        dbg << "No data to replay from " << strFile;
    }
    else
    {
/*
        dbg << replayData.size() << " over " << replayData[0].tTime.secsTo(replayData[replayData.size() - 1].tTime) << "seconds";

        QDateTime   qFirstTime = replayData[0].qTime;
        QDateTime   qStartTime = QDateTime::currentDateTime();
        for (int nCount = 0; nCount < replayData.size(); ++nCount)
        {
            if (_bStop)
                return;

            qDebug() << " " << replayData[nCount].qTime << replayData[nCount].fData;
            updateData(replayData[nCount].qTime, replayData[nCount].fData);

            qint64 msecsToNext = qFirstTime.msecsTo(replayData[nCount].qTime);
            qint64 msecsFrom = qStartTime.msecsTo(QDateTime::currentDateTime());
    //        qDebug() << msecsToNext;
    //        qDebug() << msecsFrom;
            if (msecsToNext > msecsFrom)
            {
                long msecs = (long)(msecsToNext - msecsFrom);
                QThread::msleep(msecs);
            }
        }
*/
    }

    return 0;
}
