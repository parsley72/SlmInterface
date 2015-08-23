//#define PRINT_DATA
//#define PRINT_DATA2

using System;
using System.Collections.Generic;
using System.Diagnostics;
using SlmInterface;
using System.Runtime.InteropServices;

namespace SlmInterfaceData
{
    public partial class SlmInterfaceDataClass
    {
        public struct SReplayData
        {
            private DateTime _tTime;
            private float _fData;
            private string _strFile;
            private TimeSpan _tTimeSinceStartOfFile;

            // Constructor:
            public SReplayData(DateTime tTime, float fData, string strFile, TimeSpan tTimeSinceStartOfFile)
            {
                this._tTime = tTime;
                this._fData = fData;
                this._strFile = strFile;
                this._tTimeSinceStartOfFile = tTimeSinceStartOfFile;
            }

            public DateTime Time
            {
                get { return _tTime; }
//                set { _tTime = value; }
            }

            public float Data
            {
                get { return _fData; }
//                set { _fData = value; }
            }

            public string File
            {
                get { return _strFile; }
//                set { _strFile = value; }
            }

            public TimeSpan TimeSinceStartOfFile
            {
                get { return _tTimeSinceStartOfFile; }
//                set { _tTimeSinceStartOfFile = value; }
            }
        }

        public static bool GetSlmData(string strFile, ref SortedList<DateTime, SReplayData> replayData)
        {
            Debug.WriteLine("GetSlmData(): strFile = " + strFile);
            
/*
            for (int i = 0; i < src.Length; i++)
            {
                src.Samples[i].x = i;
                src.Samples[i].y = (float)(((float)200 * Math.Sin((idx + 1) * (i + 1.0) * 48 / src.Length)));
            }
*/

//            string strFile = System.Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments);

//            List<SReplayData> replayData = new List<SReplayData>();
//            float fPeriod;

            int nFileBinaryVersion = 0;
            int nFileType;
            nFileType = NativeMethods.SI_GetLDFileType(strFile, ref nFileBinaryVersion);

            int nFile = 1;
            while (NativeMethods.SI_StartSlmTranslation(strFile, nFile))
            {
                SortedList<DateTime, SReplayData> fileData = new SortedList<DateTime, SReplayData>();
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
                    if (NativeMethods.SI_GetBulkDataEx(settings, ref bulkRecord))
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
                                DateTime timeStamp = new System.DateTime(1970, 1, 1);
                                timeStamp = timeStamp.AddSeconds(bulkRecord.m_pThRecs[i].m_TimeStamp.tv_sec);
                                timeStamp = timeStamp.AddMilliseconds(bulkRecord.m_pThRecs[i].m_TimeStamp.tv_usec / 1000);
                                SReplayData data = new SReplayData(
                                    timeStamp,
                                    bulkRecord.m_pThRecs[i].m_pfTHFloatVals[0],
                                    "",
                                    new TimeSpan());
#if PRINT_DATA2
//                                qDebug() << data.Time << data.Data;
                                Debug.WriteLine("{0} {1}", data.Time.ToString("MM/dd/yyyy hh:mm:ss.fff tt"), data.Data);
#endif // PRINT_DATA2

                                fileData.Add(data.Time, data);
                            }
                        }
                    }
                    else
                    {
                        Debug.WriteLine("SI_GetBulkDataEx(eTypeBulkTh) failed");
                    }

                    bulkRecord.m_pThRecs = null;
                }

                if (dataCounts.m_nNumAudio > 0)
                {
                    slmSBulkRecords bulkRecord = new slmSBulkRecords();
                    bulkRecord.m_dataCounts = dataCounts;
                    bulkRecord.m_pAudioRecord = new slmSSpeechData[dataCounts.m_nNumAudio];
                    bulkRecord.eRecType = eTypeBulk.eTypeBulkAudio;
                    if (NativeMethods.SI_GetBulkDataEx(settings, ref bulkRecord))
                    {
//                        for (int i = 0; i < dataCounts.m_nNumAudio; ++i) // TODO
                        int i = 0;
                        {
#if PRINT_DATA2
/*
stSpeechData_t
    int m_nNumSamples;  // number of frames
    int m_nType;        // whether compressed VOICE OR AUDIO TAG_VOICE_COMP or TAG_VOICE OR TAG_AUDIO as the flag
    int m_nSampleRate;
    int m_nNumBitsPerSample;  // for now fixed at 16
    int m_nChannels;  // for now is 1
    int m_nDataSize;  //how many bytes of data, not number of frames.
    // BECAUSE UNKNOWN SIZE, m_pbyData IS ALLOCATED IN THE TRANSLATOR AND THE CALLER MUST DELETE i.e. HeapDelete m_pbyData
    BYTE *m_pbyData;   // all the frames: length in bytes of speex frame	data block
*/
                            qDebug() << "bulkRecord.m_AudioRecord[" << i << "]";
                            qDebug() << "  m_nNumSamples       = " << bulkRecord.m_AudioRecord[i].m_nNumSamples;
                            qDebug() << "  m_nType             = 0x" << hex << bulkRecord.m_AudioRecord[i].m_nType;
                            qDebug() << "  m_nSampleRate       = " << bulkRecord.m_AudioRecord[i].m_nSampleRate;
                            qDebug() << "  m_nNumBitsPerSample = " << bulkRecord.m_AudioRecord[i].m_nNumBitsPerSample;
                            qDebug() << "  m_nChannels         = " << bulkRecord.m_AudioRecord[i].m_nChannels;
                            qDebug() << "  m_nDataSize         = " << bulkRecord.m_AudioRecord[i].m_nDataSize;
                            qDebug() << "  m_pbyData           = 0x" << hex << bulkRecord.m_AudioRecord[i].m_pbyData;
#endif // PRINT_DATA2

                            Debug.WriteLine("bulkRecord.m_pAudioRecord[" + i + "]");
                            Debug.WriteLine("  uszWavFile = " + bulkRecord.m_pAudioRecord[i].uszWavFile);

/*
                            byte[] orgData = new byte[bulkRecord.m_pAudioRecord[i].m_nDataSize];
                            Marshal.Copy(bulkRecord.m_pAudioRecord[i].m_pbyData, orgData, 0, bulkRecord.m_pAudioRecord[i].m_nDataSize);
                            short[] data = new short[bulkRecord.m_pAudioRecord[i].m_nDataSize / 2];
                            for (uint j = 0; j < bulkRecord.m_pAudioRecord[i].m_nDataSize; j += 2)
                            {
                                data[j / 2] =
                                    BitConverter.ToInt16(new byte[2]
                                    {
                                        orgData[j + 1],
                                        orgData[j]
                                    }, 0);
                            }
                            WavPcmFile.SaveToWave(
                                (short)bulkRecord.m_pAudioRecord[i].m_nChannels,
                                (short)bulkRecord.m_pAudioRecord[i].m_nNumBitsPerSample,
                                bulkRecord.m_pAudioRecord[i].m_nSampleRate,
                                data,
                                "filename2.wav");
*/
                            SortedList<DateTime, SReplayData> tempFileData = fileData;
                            fileData = new SortedList<DateTime, SReplayData>();
                            DateTime tStartTime = tempFileData.Values[0].Time;

                            foreach (KeyValuePair<DateTime, SReplayData> kvp in tempFileData)
                            {
                                SReplayData tempData = new SReplayData(
                                    kvp.Value.Time,
                                    kvp.Value.Data,
                                    bulkRecord.m_pAudioRecord[i].uszWavFile,
                                    kvp.Value.Time - tStartTime);
                                fileData.Add(tempData.Time, tempData);
                            }

                            Debug.WriteLine(strFile + "(" + nFile + "): " + fileData.Count + " from " + tStartTime + " to " + tempFileData.Values[fileData.Count - 1].Time);
                        }
                    }
                    else
                    {
                        Debug.WriteLine("SI_GetBulkDataEx(eTypeBulkAudio) failed");
                    }

                    bulkRecord.m_pAudioRecord = null;
                }

                NativeMethods.SI_EndSlmTranslation();

//                Debug.WriteLine(strFile + "(" + nFile + "): " + fileData.Count + " from " + fileData[0].Time + " to " + fileData[fileData.Count - 1].Time);
                replayData = fileData;

                nFile++;
            }

            if (replayData.Count == 0)
            {
                Debug.WriteLine("No data to replay from " + strFile);
            }
            else
            {
//                Debug.WriteLine(replayData.Count + " over " + (replayData[replayData.Count - 1].tTime - replayData[0].tTime).TotalSeconds + " seconds");

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

/*
                SortedList<DateTime, float> data = new SortedList<DateTime, float>();

                for (int i = 0; i < src.Length; i++)
                {
                    data.Add(replayData[i].tTime, replayData[i].fData);

                    src.Samples[i].x = i;
                    src.Samples[i].y = replayData[i].fData;
                }
*/
            }
/*
            replayEnded();
            deleteLater();
*/

            return true;
        }
    }
}
