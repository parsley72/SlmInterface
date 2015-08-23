#define PRINT_DATA

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.InteropServices;
using System.Diagnostics;
using SlmInterface;
using SlmInterfaceData;

namespace SlmInterfaceTestCS
{
    class Program
    {
        struct SReplayData
        {
            public DateTime tTime;
            public float fData;
        }

        class STimeHistoryOptions
        {
            public uint nMask { get; private set; }
            public string strName { get; private set; }

            public STimeHistoryOptions(uint mask, string name)
            {
                nMask = mask;
                strName = name;
            }
        }

        static readonly STimeHistoryOptions[] TimeHistoryOptions1 = new STimeHistoryOptions[]
        {
            new STimeHistoryOptions(NativeConstants.ID_TH_LEQ, "ID_TH_LEQ"),
            new STimeHistoryOptions(NativeConstants.ID_TH_LPEAK, "ID_TH_LPEAK"),
            new STimeHistoryOptions(NativeConstants.ID_TH_SPL, "ID_TH_SPL"),
            new STimeHistoryOptions(NativeConstants.ID_TH_LMAX, "ID_TH_LMAX"),
            new STimeHistoryOptions(NativeConstants.ID_TH_LMIN, "ID_TH_LMIN"),
            new STimeHistoryOptions(NativeConstants.ID_TH_LTM5, "ID_TH_LTM5"),
            new STimeHistoryOptions(NativeConstants.ID_TH_LTWA1, "ID_TH_LTWA1"),
            new STimeHistoryOptions(NativeConstants.ID_TH_LTWA2, "ID_TH_LTWA2"),
            new STimeHistoryOptions(NativeConstants.ID_TH_LTWA3, "ID_TH_LTWA3"),
            new STimeHistoryOptions(NativeConstants.ID_TH_LTWA4, "ID_TH_LTWA4"),
            new STimeHistoryOptions(NativeConstants.ID_TH_ALEQ, "ID_TH_ALEQ"),
            new STimeHistoryOptions(NativeConstants.ID_TH_APEAK, "ID_TH_APEAK"),
            new STimeHistoryOptions(NativeConstants.ID_TH_ASLOWSPL, "ID_TH_ASLOWSPL"),
            new STimeHistoryOptions(NativeConstants.ID_TH_ASLOWMAX, "ID_TH_ASLOWMAX"),
            new STimeHistoryOptions(NativeConstants.ID_TH_ASLOWMIN, "ID_TH_ASLOWMIN"),
            new STimeHistoryOptions(NativeConstants.ID_TH_AFASTSPL, "ID_TH_AFASTSPL"),
            new STimeHistoryOptions(NativeConstants.ID_TH_AFASTMAX, "ID_TH_AFASTMAX"),
            new STimeHistoryOptions(NativeConstants.ID_TH_AFASTMIN, "ID_TH_AFASTMIN"),
            new STimeHistoryOptions(NativeConstants.ID_TH_AIMPLSPL, "ID_TH_AIMPLSPL"),
            new STimeHistoryOptions(NativeConstants.ID_TH_AIMPLMAX, "ID_TH_AIMPLMAX"),
            new STimeHistoryOptions(NativeConstants.ID_TH_AIMPLMIN, "ID_TH_AIMPLMIN"),
            new STimeHistoryOptions(NativeConstants.ID_TH_CLEQ, "ID_TH_CLEQ"),
            new STimeHistoryOptions(NativeConstants.ID_TH_CPEAK, "ID_TH_CPEAK"),
            new STimeHistoryOptions(NativeConstants.ID_TH_CSLOWSPL, "ID_TH_CSLOWSPL"),
            new STimeHistoryOptions(NativeConstants.ID_TH_CSLOWMAX, "ID_TH_CSLOWMAX"),
            new STimeHistoryOptions(NativeConstants.ID_TH_CSLOWMIN, "ID_TH_CSLOWMIN"),
            new STimeHistoryOptions(NativeConstants.ID_TH_CFASTSPL, "ID_TH_CFASTSPL"),
            new STimeHistoryOptions(NativeConstants.ID_TH_CFASTMAX, "ID_TH_CFASTMAX"),
            new STimeHistoryOptions(NativeConstants.ID_TH_CFASTMIN, "ID_TH_CFASTMIN"),
            new STimeHistoryOptions(NativeConstants.ID_TH_CIMPLSPL, "ID_TH_CIMPLSPL"),
            new STimeHistoryOptions(NativeConstants.ID_TH_CIMPLMAX, "ID_TH_CIMPLMAX"),
            new STimeHistoryOptions(NativeConstants.ID_TH_CIMPLMIN, "ID_TH_CIMPLMIN"),
        };

        static readonly STimeHistoryOptions[] TimeHistoryOptions2 = new STimeHistoryOptions[]
        {
            new STimeHistoryOptions(NativeConstants.ID_TH_ZLEQ, "ID_TH_ZLEQ"),
            new STimeHistoryOptions(NativeConstants.ID_TH_ZPEAK, "ID_TH_ZPEAK"),
            new STimeHistoryOptions(NativeConstants.ID_TH_ZSLOWSPL, "ID_TH_ZSLOWSPL"),
            new STimeHistoryOptions(NativeConstants.ID_TH_ZSLOWMAX, "ID_TH_ZSLOWMAX"),
            new STimeHistoryOptions(NativeConstants.ID_TH_ZSLOWMIN, "ID_TH_ZSLOWMIN"),
            new STimeHistoryOptions(NativeConstants.ID_TH_ZFASTSPL, "ID_TH_ZFASTSPL"),
            new STimeHistoryOptions(NativeConstants.ID_TH_ZFASTMAX, "ID_TH_ZFASTMAX"),
            new STimeHistoryOptions(NativeConstants.ID_TH_ZFASTMIN, "ID_TH_ZFASTMIN"),
            new STimeHistoryOptions(NativeConstants.ID_TH_ZIMPLSPL, "ID_TH_ZIMPLSPL"),
            new STimeHistoryOptions(NativeConstants.ID_TH_ZIMPLMAX, "ID_TH_ZIMPLMAX"),
            new STimeHistoryOptions(NativeConstants.ID_TH_ZIMPLMIN, "ID_TH_ZIMPLMIN"),
            new STimeHistoryOptions(NativeConstants.ID_TH_BATTERY, "ID_TH_BATTERY"),
            new STimeHistoryOptions(NativeConstants.ID_TH_EXTPOWER, "ID_TH_EXTPOWER"),
            new STimeHistoryOptions(NativeConstants.ID_TH_INTTEMP, "ID_TH_INTTEMP"),
            new STimeHistoryOptions(NativeConstants.ID_TH_2102TEMPERATURE, "ID_TH_2102TEMPERATURE"),
            new STimeHistoryOptions(NativeConstants.ID_TH_2102HUMIDITY, "ID_TH_2102HUMIDITY"),
            new STimeHistoryOptions(NativeConstants.ID_TH_WINDSPD, "ID_TH_WINDSPD"),
            new STimeHistoryOptions(NativeConstants.ID_TH_GUSTDIR, "ID_TH_GUSTDIR"),
            new STimeHistoryOptions(NativeConstants.ID_TH_ADC1AVG, "ID_TH_ADC1AVG"),
            new STimeHistoryOptions(NativeConstants.ID_TH_ADC2AVG, "ID_TH_ADC2AVG"),
            new STimeHistoryOptions(NativeConstants.ID_TH_CMINUSA, "ID_TH_CMINUSA"),
            new STimeHistoryOptions(NativeConstants.ID_TH_OBALEQ_UNUSED, "ID_TH_OBALEQ_UNUSED"),
            new STimeHistoryOptions(NativeConstants.ID_TH_OBALMAX_UNUSED, "ID_TH_OBALMAX_UNUSED"),
            new STimeHistoryOptions(NativeConstants.ID_TH_OBASPL_UNUSED, "ID_TH_OBASPL_UNUSED"),
            new STimeHistoryOptions(NativeConstants.ID_TH_OBASPL11, "ID_TH_OBASPL11"),
            new STimeHistoryOptions(NativeConstants.ID_TH_OBALEQ11, "ID_TH_OBALEQ11"),
            new STimeHistoryOptions(NativeConstants.ID_TH_OBAMAX11, "ID_TH_OBAMAX11"),
            new STimeHistoryOptions(NativeConstants.ID_TH_OBAMIN11, "ID_TH_OBAMIN11"),
            new STimeHistoryOptions(NativeConstants.ID_TH_OBASPL13, "ID_TH_OBASPL13"),
            new STimeHistoryOptions(NativeConstants.ID_TH_OBALEQ13, "ID_TH_OBALEQ13"),
            new STimeHistoryOptions(NativeConstants.ID_TH_OBAMAX13, "ID_TH_OBAMAX13"),
            new STimeHistoryOptions(NativeConstants.ID_TH_OBAMIN13, "ID_TH_OBAMIN13"),
        };

        static readonly STimeHistoryOptions[] TimeHistoryOptions3 = new STimeHistoryOptions[]
        {
            new STimeHistoryOptions(NativeConstants.ID_TH_GUSTSPEED, "ID_TH_GUSTSPEED"),
            new STimeHistoryOptions(NativeConstants.ID_TH_ADC1MAX, "ID_TH_ADC1MAX"),
            new STimeHistoryOptions(NativeConstants.ID_TH_ADC1MIN, "ID_TH_ADC1MIN"),
            new STimeHistoryOptions(NativeConstants.ID_TH_ADC2MAX, "ID_TH_ADC2MAX"),
            new STimeHistoryOptions(NativeConstants.ID_TH_ADC2MIN, "ID_TH_ADC2MIN"),
            // reserved for future weather metrics
            new STimeHistoryOptions(NativeConstants.ID_TH_WEATHER1, "ID_TH_WEATHER1"),
            new STimeHistoryOptions(NativeConstants.ID_TH_WEATHER2, "ID_TH_WEATHER2"),
            new STimeHistoryOptions(NativeConstants.ID_TH_WEATHER3, "ID_TH_WEATHER3"),
            new STimeHistoryOptions(NativeConstants.ID_TH_WEATHER4, "ID_TH_WEATHER4"),
            new STimeHistoryOptions(NativeConstants.ID_TH_WEATHER5, "ID_TH_WEATHER5"),
            new STimeHistoryOptions(NativeConstants.ID_TH_WEATHER6, "ID_TH_WEATHER6"),
            // option to save fractional portion of duration
            new STimeHistoryOptions(NativeConstants.ID_TH_DUR_FRAC, "ID_TH_DUR_FRAC"),
            // options for LXT-HSLOG option (OPT_LXT_HSLOG)
            new STimeHistoryOptions(NativeConstants.ID_TH_WSLOWSPL, "ID_TH_WSLOWSPL"),
            new STimeHistoryOptions(NativeConstants.ID_TH_WFASTSPL, "ID_TH_WFASTSPL"),
            new STimeHistoryOptions(NativeConstants.ID_TH_WIMPLSPL, "ID_TH_WIMPLSPL"),
            new STimeHistoryOptions(NativeConstants.ID_TH_WIMPLMINUSLEQ, "ID_TH_WIMPLMINUSLEQ"),
            // options to save broadband Ln statistics
            new STimeHistoryOptions(NativeConstants.ID_TH_LN1, "ID_TH_LN1"),
            new STimeHistoryOptions(NativeConstants.ID_TH_LN2, "ID_TH_LN2"),
            new STimeHistoryOptions(NativeConstants.ID_TH_LN3, "ID_TH_LN3"),
            new STimeHistoryOptions(NativeConstants.ID_TH_LN4, "ID_TH_LN4"),
            new STimeHistoryOptions(NativeConstants.ID_TH_LN5, "ID_TH_LN5"),
            new STimeHistoryOptions(NativeConstants.ID_TH_LN6, "ID_TH_LN6"),
        };

        class SPeriodInfo
        {
            public string strItem { get; private set; }
            public uint nItemData { get; private set; }
            public float fPeriod { get; private set; }

            public SPeriodInfo(string item, uint itemData, float period)
            {
                strItem = item;
                nItemData = itemData;
                fPeriod = period;
            }
        }

        static readonly SPeriodInfo[] PeriodInfo = new SPeriodInfo[]
        {
            new SPeriodInfo("20 ms",  NativeConstants.ID_50PS, (float)0.020),
            new SPeriodInfo("50 ms",  NativeConstants.ID_20PS, (float)0.050),
            new SPeriodInfo("100 ms", NativeConstants.ID_10PS, (float)0.100),
            new SPeriodInfo("200 ms", NativeConstants.ID_5PS, (float)0.200),
            new SPeriodInfo("500 ms", NativeConstants.ID_2PS, (float)0.500),
            new SPeriodInfo("1 sec",  NativeConstants.ID_1S, (float)1.0),
            new SPeriodInfo("2 sec",  NativeConstants.ID_2S, (float)2.0),
            new SPeriodInfo("5 sec",  NativeConstants.ID_5S, (float)5.0),
            new SPeriodInfo("10 sec", NativeConstants.ID_10S, (float)10.0),
            new SPeriodInfo("15 sec", NativeConstants.ID_15S, (float)15.0),
            new SPeriodInfo("20 sec", NativeConstants.ID_20S, (float)20.0),
            new SPeriodInfo("30 sec", NativeConstants.ID_30S, (float)30.0),
            new SPeriodInfo("1 min",  NativeConstants.ID_1MIN, (float)60.0),
        };

        static void Main(string[] args)
        {
//            string strFile = "C:\\Users\\Mobotix LD\\Documents\\AENZ\\20141102_133621.ldbin";
            string strFile = "C:\\ProgramData\\AENZ\\RecordSituationViewerPlugin\\1502154c.LD0";

            List<SlmInterfaceData.SlmInterfaceDataClass.SReplayData> replayData = new List<SlmInterfaceData.SlmInterfaceDataClass.SReplayData>();
            SlmInterfaceDataClass.GetSlmData(strFile, replayData);
#if false
            List<SReplayData> replayData = new List<SReplayData>();
            float fPeriod;

            int nFileBinaryVersion = 0;
            int nFileType;
            nFileType = NativeMethods.SI_GetLDFileType(strFile, ref nFileBinaryVersion);

            int nFile = 1;
            while (NativeMethods.SI_StartSlmTranslation(strFile, nFile))
            {
                slmSFileHeader fileHeader = new slmSFileHeader();
                NativeMethods.SI_GetSlmHeaderEx(ref fileHeader);

                slmSDataCnts dataCounts = new slmSDataCnts();
                NativeMethods.SI_GetBulkCountsEx(ref dataCounts);
#if PRINT_DATA
                Debug.WriteLine("m_nNumEvents  = {0}", dataCounts.m_nNumEvents);
                Debug.WriteLine("m_nNumTH      = {0}", dataCounts.m_nNumTH);
                Debug.WriteLine("m_nNumMeas    = {0}", dataCounts.m_nNumMeas);
                Debug.WriteLine("m_nNumVoice   = {0}", dataCounts.m_nNumVoice);
                Debug.WriteLine("m_nNumAudio   = {0}", dataCounts.m_nNumAudio);
                Debug.WriteLine("m_nNumRunRecs = {0}", dataCounts.m_nNumRunRecs);
#endif // PRINT_DATA

                slmSRecord slmRecordData = new slmSRecord();
                slmSSettings settings = new slmSSettings();
                if (NativeMethods.SI_GetNextSlmRecordEx(ref slmRecordData, NativeConstants.TYPE_SETTINGS))
                {
#if PRINT_DATA
                    Debug.WriteLine("slmRecordData.nRecType = TYPE_SETTINGS");
                    // These three variables are bitwise flags indicating which timehistory data
                    // were collected by the 831/LxT. See defines.h for the bitwise flags under
                    // "SLM Any-Level Flags set in TimeHistoryOptions1"
                    {
                        string strTimeHistoryOptions1 = "";
                        for (int i = 0; i < TimeHistoryOptions1.Count(); ++i)
                        {
                            if ((slmRecordData.m_Settings.m_uiTHFlags1 & TimeHistoryOptions1[i].nMask) != 0)
                            {
                                if (strTimeHistoryOptions1.Length > 0)
                                {
                                    strTimeHistoryOptions1 += " ";
                                }
                                strTimeHistoryOptions1 += TimeHistoryOptions1[i].strName;
                            }
                        }
                        Debug.WriteLine("  m_uiTHFlags1 = 0x{0:x}, {1}", slmRecordData.m_Settings.m_uiTHFlags1, strTimeHistoryOptions1);
                    }
                    {
                        string strTimeHistoryOptions2 = "";
                        for (int i = 0; i < TimeHistoryOptions2.Count(); ++i)
                        {
                            if ((slmRecordData.m_Settings.m_uiTHFlags2 & TimeHistoryOptions2[i].nMask) != 0)
                            {
                                if (strTimeHistoryOptions2.Length > 0)
                                {
                                    strTimeHistoryOptions2 += " ";
                                }
                                strTimeHistoryOptions2 += TimeHistoryOptions2[i].strName;
                            }
                        }
                        Debug.WriteLine("  m_uiTHFlags2 = 0x{0:x}, {1}", slmRecordData.m_Settings.m_uiTHFlags2, strTimeHistoryOptions2);
                    }
                    {
                        string strTimeHistoryOptions3 = "";
                        for (int i = 0; i < TimeHistoryOptions3.Count(); ++i)
                        {
                            if ((slmRecordData.m_Settings.m_uiTHFlags3 & TimeHistoryOptions3[i].nMask) != 0)
                            {
                                if (strTimeHistoryOptions3.Length > 0)
                                {
                                    strTimeHistoryOptions3 += " ";
                                }
                                strTimeHistoryOptions3 += TimeHistoryOptions3[i].strName;
                            }
                        }
                        Debug.WriteLine("  m_uiTHFlags3 = 0x{0:x}, {1}", slmRecordData.m_Settings.m_uiTHFlags3, strTimeHistoryOptions3);
                    }

/*
                    for (int i = 0; i < PeriodInfo.Count(); ++i)
                    {
                        if (PeriodInfo[i].nItemData == slmRecordData.m_Settings.m_nSamplePeriod)
                        {
                            fPeriod = PeriodInfo[i].fPeriod;
                            break;
                        }
                    }
*/
                    fPeriod = PeriodInfo.First(p => p.nItemData == slmRecordData.m_Settings.m_nSamplePeriod).fPeriod;

                    Debug.WriteLine("  m_nSamplePeriod = {0} ({1})", slmRecordData.m_Settings.m_nSamplePeriod, fPeriod);
                    Debug.WriteLine("  m_nNumFloatVals = {0}", slmRecordData.m_Settings.m_nNumFloatVals);
#endif // PRINT_DATA

                    settings = slmRecordData.m_Settings;
                }

                if (settings.m_nNumFloatVals > 0)
                {
                    slmSBulkRecords bulkRecord = new slmSBulkRecords();
                    bulkRecord.m_dataCounts = dataCounts;
                    bulkRecord.m_pThRecs = new slmSTimeHistory[dataCounts.m_nNumTH];
                    bulkRecord.eRecType = eTypeBulk.eTypeBulkTh;
                    if (NativeMethods.SI_GetBulkDataEx(ref bulkRecord))
                    {
                        for (int i = 0; i < dataCounts.m_nNumTH; ++i)
                        {
#if PRINT_DATA2
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
                                data.tTime = new System.DateTime(1970, 1, 1).AddSeconds(bulkRecord.m_pThRecs[i].m_nTimeStamp);
                                data.fData = bulkRecord.m_pThRecs[i].m_pfTHFloatVals[0];
#if PRINT_DATA2
                                qDebug() << data.qTime << data.fData;
#endif // PRINT_DATA2

                                replayData.Add(data);
                            }
                        }
                    }
                    else
                    {
                        Debug.WriteLine("GetBulkDataEx() failed");
                    }

                    bulkRecord.m_pThRecs = null;
                }

                NativeMethods.SI_EndSlmTranslation();
                nFile++;
            }
#endif

            if (replayData.Count == 0)
            {
                Debug.WriteLine("No data to replay from " + strFile);
            }
            else
            {
                Debug.WriteLine(replayData.Count + " over " + (replayData[replayData.Count - 1].tTime - replayData[0].tTime).TotalSeconds + " seconds");

/*
                DateTime   qFirstTime = replayData[0].qTime;
                DateTime   qStartTime = DateTime.Now; // currentDateTime();
                for (int nCount = 0; nCount < replayData.Count; ++nCount)
                {
                    if (_bStop)
                        return;

                    Debug.WriteLine(" " + replayData[nCount].qTime + " " + replayData[nCount].fData);
                    updateData(replayData[nCount].qTime, replayData[nCount].fData);

                    qint64 msecsToNext = qFirstTime.msecsTo(replayData[nCount].qTime);
                    qint64 msecsFrom = qStartTime.msecsTo(DateTime.Now);
            //        qDebug() << msecsToNext;
            //        qDebug() << msecsFrom;
                    if (msecsToNext > msecsFrom)
                    {
                        int msecs = msecsToNext - msecsFrom;
                        Thread.Sleep(msecs);
                    }
                }
*/
            }
/*
            replayEnded();
            deleteLater();
*/
        }
    }
}
