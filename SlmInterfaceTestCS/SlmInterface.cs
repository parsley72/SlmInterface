using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.InteropServices;

namespace SlmInterfaceTestCS
{
    public partial class NativeConstants
    {
        /// SLM_FILENAME_SIZE -> 16
        public const uint SLM_FILENAME_SIZE = 16;
        /// SLM_OVERALLTITLE_SIZE -> 64
        public const uint SLM_OVERALLTITLE_SIZE = 64;
        /// SLM_NUM_EVENT_COUNTERS -> 5
        public const uint SLM_NUM_EVENT_COUNTERS = 5;
        /// SLM_FULLOCTAVE -> 0
        public const uint SLM_FULLOCTAVE = 0;
        /// SLM_THIRDOCTAVE -> 1
        public const uint SLM_THIRDOCTAVE = 1;
        /// SLM_NUM11SPECTRABINS -> 12
        public const uint SLM_NUM11SPECTRABINS = 12;
        /// SLM_NUMSPECTRABINS -> 36
        public const uint SLM_NUMSPECTRABINS = 36;
        /// SLM_NUM_OCTAVES -> 12
        public const uint SLM_NUM_OCTAVES = 12;
        /// SLM_NUM_THIRD_OCTAVES -> 36
        public const uint SLM_NUM_THIRD_OCTAVES = 36;
        /// SLM_FULLOCTAVE_BINS -> 12
        public const uint SLM_FULLOCTAVE_BINS = 12;
        /// SLM_THIRDOCTAVE_BINS -> 36
        public const uint SLM_THIRDOCTAVE_BINS = 36;
        /// SLM_NUM_SLM_DOSES -> 2
        public const uint SLM_NUM_SLM_DOSES = 2;
        /// SLM_NUM_LNS -> 6
        public const uint SLM_NUM_LNS = 6;
        /// SLM_NUM_CALIBRATORS -> 5
        public const uint SLM_NUM_CALIBRATORS = 5;
        /// SLM_NUM_MARKERS -> 10
        public const uint SLM_NUM_MARKERS = 10;
        /// SLM_NUM_STAT_BINS -> 2000
        public const uint SLM_NUM_STAT_BINS = 2000;
        /// SLM_NUM_SLM_LN_BINS -> (SLM_NUM_STAT_BINS + 2)
        public const uint SLM_NUM_SLM_LN_BINS = (NativeConstants.SLM_NUM_STAT_BINS + 2);
        /// SLM_MARKER_LEN -> 32
        public const uint SLM_MARKER_LEN = 32;
        /// SLM_WINDDIRSTATSBINS -> 8
        public const uint SLM_WINDDIRSTATSBINS = 8;
        /// SLM_UR_WGHT_A -> 0
        public const uint SLM_UR_WGHT_A = 0;
        /// SLM_UR_WGHT_C -> 1
        public const uint SLM_UR_WGHT_C = 1;
        /// SLM_UR_WGHT_Z -> 2
        public const uint SLM_UR_WGHT_Z = 2;
        /// SLM_UR_WGHT_SIZE -> 3
        public const uint SLM_UR_WGHT_SIZE = 3;
        /// SLM_MAX_DECAYS_PER_POSITION -> 100
        public const uint SLM_MAX_DECAYS_PER_POSITION = 100;
        /// SLM_CAL_HISTS -> 11
        public const uint SLM_CAL_HISTS = 11;
        /// SLM_CAL_TYPES -> 5
        public const uint SLM_CAL_TYPES = 5;
        /// SLM_NUM_RT60_TIME_SAMPLES -> (SLM_NUM_STAT_BINS-5)
        public const uint SLM_NUM_RT60_TIME_SAMPLES = (NativeConstants.SLM_NUM_STAT_BINS - 5);

        /// TYPE_ALL -> (-1)
        public const int TYPE_ALL = -1;
        /// TYPE_PREFER -> 0
        public const int TYPE_PREFER = 0;
        /// TYPE_SETTINGS -> 1
        public const int TYPE_SETTINGS = 1;
        /// TYPE_OVERALL -> 2
        public const int TYPE_OVERALL = 2;
        /// TYPE_LN_TABLE -> 3
        public const int TYPE_LN_TABLE = 3;
        /// TYPE_SESSION -> 4
        public const int TYPE_SESSION = 4;
        /// TYPE_AUDIO -> 5
        public const int TYPE_AUDIO = 5;
        /// TYPE_TIMEHIST -> 6
        public const int TYPE_TIMEHIST = 6;
        /// TYPE_VOICE -> 7
        public const int TYPE_VOICE = 7;
        /// TYPE_INTERVAL -> 8
        public const int TYPE_INTERVAL = 8;
        /// TYPE_EXCEEDENCE -> 9
        public const int TYPE_EXCEEDENCE = 9;
        /// TYPE_CAL -> 10
        public const int TYPE_CAL = 10;
        /// TYPE_NOISEFLOOR -> 11
        public const int TYPE_NOISEFLOOR = 11;
        /// TYPE_CALHISTORY -> 12
        public const int TYPE_CALHISTORY = 12;
        /// TYPE_EXTENDED_ERROR -> 13
        public const int TYPE_EXTENDED_ERROR = 13;
        /// TYPE_BYTIMEAVG -> 14
        public const int TYPE_BYTIMEAVG = 14;
        /// TYPE_FFT -> 15
        public const int TYPE_FFT = 15;
        /// TYPE_FFTHISTORY -> 16
        public const int TYPE_FFTHISTORY = 16;
        /// TYPE_FINISHED -> 17
        public const int TYPE_FINISHED = 17;

        // TimeHistoryOptions1
        /// ID_TH_LEQ -> 0x00000001
        public const uint ID_TH_LEQ = 0x00000001;
        /// ID_TH_LPEAK -> 0x00000002
        public const uint ID_TH_LPEAK = 0x00000002;
        /// ID_TH_SPL -> 0x00000004
        public const uint ID_TH_SPL = 0x00000004;
        /// ID_TH_LMAX -> 0x00000008
        public const uint ID_TH_LMAX = 0x00000008;
        /// ID_TH_LMIN -> 0x00000010
        public const uint ID_TH_LMIN = 0x00000010;
        /// ID_TH_LTM5 -> 0x00000020
        public const uint ID_TH_LTM5 = 0x00000020;
        /// ID_TH_LTWA1 -> 0x00000040
        public const uint ID_TH_LTWA1 = 0x00000040;
        /// ID_TH_LTWA2 -> 0x00000080
        public const uint ID_TH_LTWA2 = 0x00000080;
        /// ID_TH_LTWA3 -> 0x00000100
        public const uint ID_TH_LTWA3 = 0x00000100;
        /// ID_TH_LTWA4 -> 0x00000200
        public const uint ID_TH_LTWA4 = 0x00000200;
        /// ID_TH_ALEQ -> 0x00000400
        public const uint ID_TH_ALEQ = 0x00000400;
        /// ID_TH_APEAK -> 0x00000800
        public const uint ID_TH_APEAK = 0x00000800;
        /// ID_TH_ASLOWSPL -> 0x00001000
        public const uint ID_TH_ASLOWSPL = 0x00001000;
        /// ID_TH_ASLOWMAX -> 0x00002000
        public const uint ID_TH_ASLOWMAX = 0x00002000;
        /// ID_TH_ASLOWMIN -> 0x00004000
        public const uint ID_TH_ASLOWMIN = 0x00004000;
        /// ID_TH_AFASTSPL -> 0x00008000
        public const uint ID_TH_AFASTSPL = 0x00008000;
        /// ID_TH_AFASTMAX -> 0x00010000
        public const uint ID_TH_AFASTMAX = 0x00010000;
        /// ID_TH_AFASTMIN -> 0x00020000
        public const uint ID_TH_AFASTMIN = 0x00020000;
        /// ID_TH_AIMPLSPL -> 0x00040000
        public const uint ID_TH_AIMPLSPL = 0x00040000;
        /// ID_TH_AIMPLMAX -> 0x00080000
        public const uint ID_TH_AIMPLMAX = 0x00080000;
        /// ID_TH_AIMPLMIN -> 0x00100000
        public const uint ID_TH_AIMPLMIN = 0x00100000;
        /// ID_TH_CLEQ -> 0x00200000
        public const uint ID_TH_CLEQ = 0x00200000;
        /// ID_TH_CPEAK -> 0x00400000
        public const uint ID_TH_CPEAK = 0x00400000;
        /// ID_TH_CSLOWSPL -> 0x00800000
        public const uint ID_TH_CSLOWSPL = 0x00800000;
        /// ID_TH_CSLOWMAX -> 0x01000000
        public const uint ID_TH_CSLOWMAX = 0x01000000;
        /// ID_TH_CSLOWMIN -> 0x02000000
        public const uint ID_TH_CSLOWMIN = 0x02000000;
        /// ID_TH_CFASTSPL -> 0x04000000
        public const uint ID_TH_CFASTSPL = 0x04000000;
        /// ID_TH_CFASTMAX -> 0x08000000
        public const uint ID_TH_CFASTMAX = 0x08000000;
        /// ID_TH_CFASTMIN -> 0x10000000
        public const uint ID_TH_CFASTMIN = 0x10000000;
        /// ID_TH_CIMPLSPL -> 0x20000000
        public const uint ID_TH_CIMPLSPL = 0x20000000;
        /// ID_TH_CIMPLMAX -> 0x40000000
        public const uint ID_TH_CIMPLMAX = 0x40000000;
        /// ID_TH_CIMPLMIN -> 0x80000000
        public const uint ID_TH_CIMPLMIN = 0x80000000;

        // TimeHistoryOptions2
        /// ID_TH_ZLEQ -> 0x00000001
        public const uint ID_TH_ZLEQ = 0x00000001;
        /// ID_TH_ZPEAK -> 0x00000002
        public const uint ID_TH_ZPEAK = 0x00000002;
        /// ID_TH_ZSLOWSPL -> 0x00000004
        public const uint ID_TH_ZSLOWSPL = 0x00000004;
        /// ID_TH_ZSLOWMAX -> 0x00000008
        public const uint ID_TH_ZSLOWMAX = 0x00000008;
        /// ID_TH_ZSLOWMIN -> 0x00000010
        public const uint ID_TH_ZSLOWMIN = 0x00000010;
        /// ID_TH_ZFASTSPL -> 0x00000020
        public const uint ID_TH_ZFASTSPL = 0x00000020;
        /// ID_TH_ZFASTMAX -> 0x00000040
        public const uint ID_TH_ZFASTMAX = 0x00000040;
        /// ID_TH_ZFASTMIN -> 0x00000080
        public const uint ID_TH_ZFASTMIN = 0x00000080;
        /// ID_TH_ZIMPLSPL -> 0x00000100
        public const uint ID_TH_ZIMPLSPL = 0x00000100;
        /// ID_TH_ZIMPLMAX -> 0x00000200
        public const uint ID_TH_ZIMPLMAX = 0x00000200;
        /// ID_TH_ZIMPLMIN -> 0x00000400
        public const uint ID_TH_ZIMPLMIN = 0x00000400;
        /// ID_TH_BATTERY -> 0x00000800
        public const uint ID_TH_BATTERY = 0x00000800;
        /// ID_TH_EXTPOWER -> 0x00001000
        public const uint ID_TH_EXTPOWER = 0x00001000;
        /// ID_TH_INTTEMP -> 0x00002000
        public const uint ID_TH_INTTEMP = 0x00002000;
        /// ID_TH_2102TEMPERATURE -> 0x00004000
        public const uint ID_TH_2102TEMPERATURE = 0x00004000;
        /// ID_TH_2102HUMIDITY -> 0x00008000
        public const uint ID_TH_2102HUMIDITY = 0x00008000;
        /// ID_TH_WINDSPD -> 0x00010000
        public const uint ID_TH_WINDSPD = 0x00010000;
        /// ID_TH_GUSTDIR -> 0x00020000
        public const uint ID_TH_GUSTDIR = 0x00020000;
        /// ID_TH_ADC1AVG -> 0x00040000
        public const uint ID_TH_ADC1AVG = 0x00040000;
        /// ID_TH_ADC2AVG -> 0x00080000
        public const uint ID_TH_ADC2AVG = 0x00080000;
        /// ID_TH_CMINUSA -> 0x00100000
        public const uint ID_TH_CMINUSA = 0x00100000;
        /// ID_TH_OBALEQ_UNUSED -> 0x00200000
        public const uint ID_TH_OBALEQ_UNUSED = 0x00200000;
        /// ID_TH_OBALMAX_UNUSED -> 0x00400000
        public const uint ID_TH_OBALMAX_UNUSED = 0x00400000;
        /// ID_TH_OBASPL_UNUSED -> 0x00800000
        public const uint ID_TH_OBASPL_UNUSED = 0x00800000;
        /// ID_TH_OBASPL11 -> 0x01000000
        public const uint ID_TH_OBASPL11 = 0x01000000;
        /// ID_TH_OBALEQ11 -> 0x02000000
        public const uint ID_TH_OBALEQ11 = 0x02000000;
        /// ID_TH_OBAMAX11 -> 0x04000000
        public const uint ID_TH_OBAMAX11 = 0x04000000;
        /// ID_TH_OBAMIN11 -> 0x08000000
        public const uint ID_TH_OBAMIN11 = 0x08000000;
        /// ID_TH_OBASPL13 -> 0x10000000
        public const uint ID_TH_OBASPL13 = 0x10000000;
        /// ID_TH_OBALEQ13 -> 0x20000000
        public const uint ID_TH_OBALEQ13 = 0x20000000;
        /// ID_TH_OBAMAX13 -> 0x40000000
        public const uint ID_TH_OBAMAX13 = 0x40000000;
        /// ID_TH_OBAMIN13 -> 0x80000000
        public const uint ID_TH_OBAMIN13 = 0x80000000;

        // TimeHistoryOptions3
        /// ID_TH_GUSTSPEED -> 0x00000001
        public const uint ID_TH_GUSTSPEED = 0x00000001;
        /// ID_TH_ADC1MAX -> 0x00000002
        public const uint ID_TH_ADC1MAX = 0x00000002;
        /// ID_TH_ADC1MIN -> 0x00000004
        public const uint ID_TH_ADC1MIN = 0x00000004;
        /// ID_TH_ADC2MAX -> 0x00000008
        public const uint ID_TH_ADC2MAX = 0x00000008;
        /// ID_TH_ADC2MIN -> 0x00000010
        public const uint ID_TH_ADC2MIN = 0x00000010;
        // reserved for future weather metrics
        /// ID_TH_WEATHER1 -> 0x00000020
        public const uint ID_TH_WEATHER1 = 0x00000020;
        /// ID_TH_WEATHER2 -> 0x00000040
        public const uint ID_TH_WEATHER2 = 0x00000040;
        /// ID_TH_WEATHER3 -> 0x00000080
        public const uint ID_TH_WEATHER3 = 0x00000080;
        /// ID_TH_WEATHER4 -> 0x00000100
        public const uint ID_TH_WEATHER4 = 0x00000100;
        /// ID_TH_WEATHER5 -> 0x00000200
        public const uint ID_TH_WEATHER5 = 0x00000200;
        /// ID_TH_WEATHER6 -> 0x00000400
        public const uint ID_TH_WEATHER6 = 0x00000400;
        // option to save fractional portion of duration
        /// ID_TH_DUR_FRAC -> 0x00000800
        public const uint ID_TH_DUR_FRAC = 0x00000800;
        // options for LXT-HSLOG option (OPT_LXT_HSLOG)
        /// ID_TH_WSLOWSPL -> 0x00001000
        public const uint ID_TH_WSLOWSPL = 0x00001000;
        /// ID_TH_WFASTSPL -> 0x00002000
        public const uint ID_TH_WFASTSPL = 0x00002000;
        /// ID_TH_WIMPLSPL -> 0x00004000
        public const uint ID_TH_WIMPLSPL = 0x00004000;
        /// ID_TH_WIMPLMINUSLEQ -> 0x00008000
        public const uint ID_TH_WIMPLMINUSLEQ = 0x00008000;
        // options to save broadband Ln statistics
        /// ID_TH_LN1 -> 0x00010000
        public const uint ID_TH_LN1 = 0x00010000;
        /// ID_TH_LN2 -> 0x00020000
        public const uint ID_TH_LN2 = 0x00020000;
        /// ID_TH_LN3 -> 0x00040000
        public const uint ID_TH_LN3 = 0x00040000;
        /// ID_TH_LN4 -> 0x00080000
        public const uint ID_TH_LN4 = 0x00080000;
        /// ID_TH_LN5 -> 0x00100000
        public const uint ID_TH_LN5 = 0x00100000;
        /// ID_TH_LN6 -> 0x00200000
        public const uint ID_TH_LN6 = 0x00200000;
        /// ID_TH_LN_ENABLES -> (ID_TH_LN1 | ID_TH_LN2 | ID_TH_LN3 | ID_TH_LN4 | ID_TH_LN5 | ID_TH_LN6)
        public const uint ID_TH_LN_ENABLES = (NativeConstants.ID_TH_LN1
                    | (NativeConstants.ID_TH_LN2
                    | (NativeConstants.ID_TH_LN3
                    | (NativeConstants.ID_TH_LN4
                    | (NativeConstants.ID_TH_LN5 | NativeConstants.ID_TH_LN6)))));

        // period settings for TimeHistoryPeriod and ExceedanceTimeHistoryPeriod
        /// ID_50PS -> 0
        public const uint ID_50PS = 0;  // 50 per second (20ms)
        /// ID_20PS -> 1
        public const uint ID_20PS = 1;  // 20 per second (50ms)
        /// ID_10PS -> 2
        public const uint ID_10PS = 2;  // 10 per second (100ms)
        /// ID_5PS -> 3
        public const uint ID_5PS = 3;  // 5 per second (200ms)
        /// ID_2PS -> 4
        public const uint ID_2PS = 4;  // 2 per second (500ms)
        /// ID_1S -> 5
        public const uint ID_1S = 5;
        /// ID_2S -> 6
        public const uint ID_2S = 6;
        /// ID_5S -> 7
        public const uint ID_5S = 7;
        /// ID_10S -> 8
        public const uint ID_10S = 8;
        /// ID_15S -> 9
        public const uint ID_15S = 9;
        /// ID_20S -> 10
        public const uint ID_20S = 10;
        /// ID_30S -> 11
        public const uint ID_30S = 11;
        /// ID_1MIN -> 12
        public const uint ID_1MIN = 12;
        /// ID_2MIN -> 13
        public const uint ID_2MIN = 13;
        /// ID_5MIN -> 14
        public const uint ID_5MIN = 14;
        /// ID_10MIN -> 15
        public const uint ID_10MIN = 15;
        /// ID_15MIN -> 16
        public const uint ID_15MIN = 16;
        /// ID_20MIN -> 17
        public const uint ID_20MIN = 17;
        /// ID_30MIN -> 18
        public const uint ID_30MIN = 18;
        /// ID_1HR -> 19
        public const uint ID_1HR = 19;
        /// ID_24HR -> 20
        public const uint ID_24HR = 20;
        /// ID_400PS -> 21
        public const uint ID_400PS = 21; // 400 per second (2.5ms)
        /// ID_200PS -> 22
        public const uint ID_200PS = 22; // 200 per second (5ms)
        /// ID_100PS -> 23
        public const uint ID_100PS = 23; // 100 per second (10ms)
    }

    [System.Runtime.InteropServices.StructLayoutAttribute(System.Runtime.InteropServices.LayoutKind.Sequential, CharSet = System.Runtime.InteropServices.CharSet.Unicode)]
    public struct slmSFileHeader
    {
        /// int
        public int nSerialNumber;

        /// wchar_t[16]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValTStr, SizeConst = 16)]
        public string uszSerialNumber;

        /// wchar_t[64]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValTStr, SizeConst = 64)]
        public string uszUser;

        /// wchar_t[128]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValTStr, SizeConst = 128)]
        public string uszLocation;

        /// wchar_t[128]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValTStr, SizeConst = 128)]
        public string uszJobDescription;

        /// wchar_t[512]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValTStr, SizeConst = 512)]
        public string uszNote;

        /// wchar_t[16]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValTStr, SizeConst = 16)]
        public string uszDataFileName;

        /// wchar_t[64]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValTStr, SizeConst = 64)]
        public string uszOverallTitle;

        /// wchar_t[16]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValTStr, SizeConst = 16)]
        public string uszModel;

        /// wchar_t[16]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValTStr, SizeConst = 16)]
        public string uszFirmwareRev;

        /// wchar_t[16]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValTStr, SizeConst = 16)]
        public string uszPreamp;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute(System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct slmSSpectra
    {
        /// int
        public int m_nType;

        /// int
        public int m_nBandWidth;

        /// int
        public int m_nRange;

        /// float[36]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 36, ArraySubType = System.Runtime.InteropServices.UnmanagedType.R4)]
        public float[] OverallSpectra;

        /// float[36]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 36, ArraySubType = System.Runtime.InteropServices.UnmanagedType.R4)]
        public float[] MaxSpectra;

        /// float[36]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 36, ArraySubType = System.Runtime.InteropServices.UnmanagedType.R4)]
        public float[] MinSpectra;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute(System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct slmSOverloads
    {
        /// int
        public int count;

        /// float
        public float duration;

        /// int
        public int OBAcount;

        /// float
        public float OBAduration;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute(System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct slmSDailyNoise
    {
        /// float[24]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 24, ArraySubType = System.Runtime.InteropServices.UnmanagedType.R4)]
        public float[] HNL;

        /// float
        public float Time;

        /// float[24]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 24, ArraySubType = System.Runtime.InteropServices.UnmanagedType.R4)]
        public float[] TimeHr;

        /// float
        public float Lden_Day;

        /// float
        public float T_Lden_Day;

        /// float
        public float Lden_Eve;

        /// float
        public float T_Lden_Eve;

        /// float
        public float Lden_Night;

        /// float
        public float T_Lden_Night;

        /// float
        public float Ldn_Day;

        /// float
        public float T_Ldn_Day;

        /// float
        public float Ldn_Night;

        /// float
        public float T_Ldn_Night;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute(System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct slmSDegmin
    {
        /// int
        public int deg;

        /// float
        public float AnonymousMember1;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute(System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct slmSGPS
    {
        /// slmSDegmin
        public slmSDegmin latitude;

        /// slmSDegmin
        public slmSDegmin longitude;

        /// float
        public float altitude;

        /// unsigned int
        public uint time;

        /// unsigned int
        public uint date;

        /// unsigned short
        public ushort flags;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute(System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct slmSWeather
    {
        /// float
        public float WindSpeedAvg;

        /// float
        public float WindSpeedMax;

        /// float
        public float WindSpeedMin;

        /// unsigned int[8]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 8, ArraySubType = System.Runtime.InteropServices.UnmanagedType.U4)]
        public uint[] WindDirStats;

        /// float
        public float WindDirMax;

        /// float
        public float ADC1Avg;

        /// float
        public float ADC1Max;

        /// float
        public float ADC1Min;

        /// float
        public float ADC2Avg;

        /// float
        public float ADC2Max;

        /// float
        public float ADC2Min;

        /// float
        public float ADC3Avg;

        /// float
        public float ADC3Max;

        /// float
        public float ADC3Min;

        /// float
        public float RainTotal;

        /// float
        public float RainMaxRate;

        /// float
        public float RainDuration;

        /// unsigned int
        public uint WindAccm;

        /// unsigned int
        public uint WindCount;

        /// float
        public float ADC1Accm;

        /// unsigned int
        public uint ADC1Count;

        /// float
        public float ADC2Accm;

        /// unsigned int
        public uint ADC2Count;

        /// float
        public float ADC3Accm;

        /// unsigned int
        public uint ADC3Count;

        /// float
        public float HailTotal;

        /// float
        public float HailMaxRate;

        /// float
        public float HailDuration;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute(System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct slmSPRM2102
    {
        /// float
        public float RH;

        /// float
        public float Temp;

        /// float
        public float Dew;

        /// unsigned int
        public uint modelnum;

        /// unsigned int
        public uint serialnum;

        /// unsigned int
        public uint flags;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute(System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct slmSRHTemp
    {
        /// float
        public float RHMax;

        /// float
        public float TempMax;

        /// float
        public float DewMax;

        /// float
        public float RHMin;

        /// float
        public float TempMin;

        /// float
        public float DewMin;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute(System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct slmSRA_Common_t
    {
        /// unsigned int
        public uint total_count;

        /// unsigned int
        public uint average_count;

        /// unsigned int
        public uint numFreqBands;

        /// unsigned int
        public uint positions;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute(System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct slmSRT60_SampleT2_t
    {
        /// unsigned short
        public ushort includedInAvg;

        /// unsigned short
        public ushort position;

        /// float[36]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 36, ArraySubType = System.Runtime.InteropServices.UnmanagedType.R4)]
        public float[] Leq;

        /// float[36]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 36, ArraySubType = System.Runtime.InteropServices.UnmanagedType.R4)]
        public float[] Lmax;

        /// float[36]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 36, ArraySubType = System.Runtime.InteropServices.UnmanagedType.R4)]
        public float[] Lbk;

        /// float[36]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 36, ArraySubType = System.Runtime.InteropServices.UnmanagedType.R4)]
        public float[] EDT;

        /// float[36]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 36, ArraySubType = System.Runtime.InteropServices.UnmanagedType.R4)]
        public float[] T20;

        /// float[36]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 36, ArraySubType = System.Runtime.InteropServices.UnmanagedType.R4)]
        public float[] T30;

        /// float[36]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 36, ArraySubType = System.Runtime.InteropServices.UnmanagedType.R4)]
        public float[] Cu;

        /// float[36]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 36, ArraySubType = System.Runtime.InteropServices.UnmanagedType.R4)]
        public float[] Co_T20;

        /// float[36]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 36, ArraySubType = System.Runtime.InteropServices.UnmanagedType.R4)]
        public float[] Co_T30;

        /// float[36]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 36, ArraySubType = System.Runtime.InteropServices.UnmanagedType.R4)]
        public float[] SD_T20;

        /// float[36]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 36, ArraySubType = System.Runtime.InteropServices.UnmanagedType.R4)]
        public float[] SD_T30;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute(System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct slmSDataLimits_t
    {
        /// unsigned int
        public uint StartPoint;

        /// unsigned int
        public uint TwentydBPoint;

        /// unsigned int
        public uint ThirtydBPoint;

        /// unsigned int
        public uint StopPoint;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute(System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct slmSRT60_SampleT2WithLimits_t
    {
        /// slmSRT60_SampleT2_t->Anonymous_2c566f66_a303_4ff1_9af8_3c4e20a58185
        public slmSRT60_SampleT2_t T2;

        /// slmSDataLimits_t[36]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 36, ArraySubType = System.Runtime.InteropServices.UnmanagedType.Struct)]
        public slmSDataLimits_t[] idxPts;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute(System.Runtime.InteropServices.LayoutKind.Sequential, CharSet = System.Runtime.InteropServices.CharSet.Ansi)]
    public struct slmSRT60_AverageT2_t
    {
        /// slmSRA_Common_t->Anonymous_72be78e3_e5d1_4672_a311_3c80cf7f3d3b
        public slmSRA_Common_t com;

        /// slmSRT60_SampleT2_t->Anonymous_2c566f66_a303_4ff1_9af8_3c4e20a58185
        public slmSRT60_SampleT2_t T2;

        /// unsigned char[100]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValTStr, SizeConst = 100)]
        public string DecaysPerPosition;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute(System.Runtime.InteropServices.LayoutKind.Sequential, CharSet = System.Runtime.InteropServices.CharSet.Unicode)]
    public struct slmSOverallData
    {
        /// int
        public int m_nTrig1Count;

        /// int
        public int m_nTrig2Count;

        /// int
        public int m_nPeakCount;

        /// int
        public int m_nPeak2Count;

        /// int
        public int m_nPeak3Count;

        /// float
        public float m_fTrig1Duration;

        /// float
        public float m_fTrig2Duration;

        /// float
        public float m_fPeakDuration;

        /// float
        public float m_fPeak2Duration;

        /// float
        public float m_fPeak3Duration;

        /// time_t->__time32_t->int
        public int m_tStart;

        /// time_t->__time32_t->int
        public int m_tEnd;

        /// float
        public float m_fRunTime;

        /// int
        public int m_nNumOBA;

        /// slmSSpectraInfo_t->slmSSpectra
        public slmSSpectra m_11Spectra;

        /// slmSSpectraInfo_t->slmSSpectra
        public slmSSpectra m_13Spectra;

        /// float
        public float m_fPauseTime;

        /// wchar_t[16]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValTStr, SizeConst = 16)]
        public string m_uszPreamp;

        /// float
        public float m_fLeq;

        /// float
        public float m_fMax;

        /// float
        public float m_fPeak;

        /// float
        public float m_fMin;

        /// float
        public float m_fSEA;

        /// time_t->__time32_t->int
        public int m_tPeakMaxTime;

        /// time_t->__time32_t->int
        public int m_tMaxTime;

        /// time_t->__time32_t->int
        public int m_tMinTime;

        /// float
        public float m_fLAeq;

        /// float
        public float m_fLCeq;

        /// float
        public float m_fLTm5;

        /// float[2]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 2, ArraySubType = System.Runtime.InteropServices.UnmanagedType.R4)]
        public float[] m_fTWA;

        /// slmSOverloads
        public slmSOverloads m_OverLoads;

        /// slmSDailyNoise
        public slmSDailyNoise m_DailyNoise;

        /// slmSGPS
        public slmSGPS m_GPSData;

        /// float
        public float m_fURLimit;

        /// float
        public float m_fURPeak;

        /// float
        public float m_fURNoiseFloor;

        /// float
        public float m_fNFOverload;

        /// float
        public float m_fLwIeq;

        /// float
        public float m_fLweq;

        /// int*[36]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 36, ArraySubType = System.Runtime.InteropServices.UnmanagedType.SysUInt)]
        public System.IntPtr[] m_pnSpectralLns;

        /// slmSWeather
        public slmSWeather m_Weather;

        /// slmSPRM2102
        public slmSPRM2102 m_426A12Info;

        /// slmSRHTemp
        public slmSRHTemp m_426A12Data;

        /// slmSRT60_AverageT2_t->Anonymous_539fbe00_4a97_4bb1_9b4a_be59045ed2c3
        public slmSRT60_AverageT2_t m_T2Avg;
    }

/*
    [System.Runtime.InteropServices.StructLayoutAttribute(System.Runtime.InteropServices.LayoutKind.Sequential, CharSet = System.Runtime.InteropServices.CharSet.Unicode)]
    public struct slmSDose
    {
        /// wchar_t[9]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValTStr, SizeConst = 9)]
        public string m_uszDoseName;

        /// unsigned char
        public byte m_byThresholdLevelDB;

        /// unsigned char
        public byte m_byExchangeRate;

        /// unsigned char
        public byte m_byCriterionTimeHours;

        /// unsigned char
        public byte m_byCriterionLevelDB;

        /// boolean
        public bool m_bThreshEnable;
    }
*/

    [System.Runtime.InteropServices.StructLayoutAttribute(System.Runtime.InteropServices.LayoutKind.Sequential, CharSet = System.Runtime.InteropServices.CharSet.Unicode)]
    public struct slmSDose1
    {
        /// wchar_t[9]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValTStr, SizeConst = 9)]
        public string m_uszDoseName;

        /// float
        public float m_fThresholdLevelDB;

        /// unsigned char
        public byte m_byExchangeRate;

        /// float
        public float m_fCriterionTimeHours;

        /// float
        public float m_fCriterionLevelDB;

        /// boolean
        public bool m_bThreshEnable;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute(System.Runtime.InteropServices.LayoutKind.Sequential, CharSet = System.Runtime.InteropServices.CharSet.Unicode)]
    public struct slmSSettings
    {
        /// unsigned char
        public byte m_byFrequencyWeighting;

        /// unsigned char
        public byte m_byPeakWeighting;

        /// unsigned char
        public byte m_byDetector;

/*
        /// slmSDose_t[2]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 2, ArraySubType = System.Runtime.InteropServices.UnmanagedType.Struct)]
        public slmSDose[] m_Doses;
*/

        /// float
        public float m_fSplTrig1;

        /// float
        public float m_fSplTrig2;

        /// float
        public float m_fPeakTrig1;

        /// float
        public float m_fPeakTrig2;

        /// float
        public float m_fPeakTrig3;

        /// wchar_t[330]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValTStr, SizeConst = 330)]
        public string m_uszMarkerNames;

        /// int
        public int m_nOBABandWidth;

        /// int
        public int m_nOBARange;

        /// unsigned int
        public uint m_uiTHFlags1;

        /// unsigned int
        public uint m_uiTHFlags2;

        /// int
        public int m_nNumFloatVals;

        /// int
        public int m_nNumOBA11Vals;

        /// int
        public int m_nNumOBA13Vals;

        /// int
        public int m_nTHMiscStartIndex;

        /// float[6]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 6, ArraySubType = System.Runtime.InteropServices.UnmanagedType.R4)]
        public float[] m_fLnValues;

        /// int
        public int m_nIntegration;

        /// unsigned int
        public uint m_ulMeasurementPeriod;

        /// int
        public int m_nSlmGain;

        /// int
        public int m_nMeasLnTableEnable;

        /// wchar_t[64]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValTStr, SizeConst = 64)]
        public string m_uszOverallTitle;

        /// int
        public int m_nSamplePeriod;

        /// unsigned int
        public uint m_uiMeasCounts;

        /// unsigned int
        public uint m_ulDayTime;

        /// unsigned int
        public uint m_ulEveningTime;

        /// unsigned int
        public uint m_ulNightTime;

        /// float
        public float m_fEveningPenalty;

        /// float
        public float m_fNightPenalty;

        /// boolean
        public bool m_bMeasSnapShotEnable;

        /// unsigned int
        public uint m_ulMeasSnapShotPeriod;

        /// unsigned int
        public uint m_ulExcSnapShotPeriod;

        /// boolean
        public bool m_bEnableExceedAudioSnapshot;

        /// int
        public int m_nExcdTHCount;

        /// int
        public int m_nExcdTHPreCount;

        /// int
        public int m_nExcdTHSpectra;

        /// int
        public int m_nExcdTHPeriod;

        /// unsigned int
        public uint m_ulSnapShotPreTrig;

        /// int
        public int m_nMsmntSpectralLn;

        /// unsigned char
        public byte m_byOBAWeighting;

        /// int
        public int m_nGPSControl;

        /// unsigned int
        public uint m_uiPurOptions;

        /// float
        public float m_fWindScale;

        /// wchar_t[48]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValTStr, SizeConst = 48)]
        public string m_uszWindUnits;

        /// int
        public int m_nWindDirection;

        /// float
        public float m_fWindThreshold;

        /// float
        public float m_fWindExcdLevel;

        /// float
        public float m_fWindHysteresis;

        /// int
        public int m_nWindPause;

        /// float
        public float m_fADC1Scale;

        /// float
        public float m_fADC1Offset;

        /// wchar_t[48]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValTStr, SizeConst = 48)]
        public string m_uszADC1Units;

        /// wchar_t[48]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValTStr, SizeConst = 48)]
        public string m_uszADC1Description;

        /// float
        public float m_fADC2Scale;

        /// float
        public float m_fADC2Offset;

        /// wchar_t[48]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValTStr, SizeConst = 48)]
        public string m_uszADC2Units;

        /// wchar_t[48]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValTStr, SizeConst = 48)]
        public string m_uszADC2Description;

        /// wchar_t[16]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValTStr, SizeConst = 16)]
        public string m_uszSetupFileName;

        /// unsigned int
        public uint m_uiTHFlags3;

        /// int
        public int m_nWeatherOption;

        /// int
        public int m_nOBAMaxSpectra;

        /// slmSDose1_t[2]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 2, ArraySubType = System.Runtime.InteropServices.UnmanagedType.Struct)]
        public slmSDose1[] m_Doses1;

        /// int
        public int m_nInstrumentMode;

        /// int
        public int m_nRAExitTime;

        /// int
        public int m_nRALoBand;

        /// int
        public int m_nRAHiBand;

        /// int
        public int m_nRT60NoiseType;

        /// float
        public float m_fRT60Attenuation;

        /// int
        public int m_nRT60TriggerMethod;

        /// int
        public int m_nRT60TriggerSource;

        /// float
        public float m_fRT60TriggerLevel;

        /// int
        public int m_nRT60Bandwidth;

        /// int
        public int m_nRT60BuildTime;

        /// int
        public int m_nRT60RunTime;

        /// int
        public int m_nRT60RunCount;

        /// int
        public int m_nRT60SamplePeriod;

        /// int
        public int m_nRT60SaveAverage;

        /// int
        public int m_nRT60SaveAll;

        /// int
        public int m_nRTANoiseType;

        /// float
        public float m_fRTAAttenuation;

        /// int
        public int m_nFftWindow;

        /// int
        public int m_nFftFreqSpan;

        /// int
        public int m_nFftLines;

        /// int
        public int m_nFftRunMode;

        /// int
        public int m_nFftTonality;

        /// int
        public int m_nToneSeekDelta;

        /// int
        public int m_nRegressionRange;

        /// int
        public int m_uiRunTimer;

        /// int
        public int m_bMeasHistEnabled;

        /// int
        public int m_nVaisalaHeaterState;

        /// int
        public int m_nVaisalaHeaterEnaTime;

        /// int
        public int m_nVaisalaHeaterDisTime;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute(System.Runtime.InteropServices.LayoutKind.Sequential, CharSet = System.Runtime.InteropServices.CharSet.Unicode)]
    public struct slmSPreferences
    {
        /// int
        public int m_nDateFormat;

        /// int
        public int m_nDecimalFormat;

        /// int
        public int m_nLanguage;

        /// int
        public int m_nTaktMetricEnable;

        /// int
        public int m_nUnits;

        /// int
        public int m_nRICorrection;

        /// float[12]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 12, ArraySubType = System.Runtime.InteropServices.UnmanagedType.R4)]
        public float[] m_fFullOctaveReferenceSpectra1;

        /// float[12]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 12, ArraySubType = System.Runtime.InteropServices.UnmanagedType.R4)]
        public float[] m_fFullOctaveReferenceSpectra2;

        /// float[12]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 12, ArraySubType = System.Runtime.InteropServices.UnmanagedType.R4)]
        public float[] m_fFullOctaveReferenceSpectra3;

        /// float[12]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 12, ArraySubType = System.Runtime.InteropServices.UnmanagedType.R4)]
        public float[] m_fFullOctaveReferenceSpectra4;

        /// float[36]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 36, ArraySubType = System.Runtime.InteropServices.UnmanagedType.R4)]
        public float[] m_fThirdOctaveReferenceSpectra1;

        /// float[36]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 36, ArraySubType = System.Runtime.InteropServices.UnmanagedType.R4)]
        public float[] m_fThirdOctaveReferenceSpectra2;

        /// float[36]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 36, ArraySubType = System.Runtime.InteropServices.UnmanagedType.R4)]
        public float[] m_fThirdOctaveReferenceSpectra3;

        /// float[36]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 36, ArraySubType = System.Runtime.InteropServices.UnmanagedType.R4)]
        public float[] m_fThirdOctaveReferenceSpectra4;

        /// wchar_t[13]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValTStr, SizeConst = 13)]
        public string m_uszFullOctaveReferenceSpectra1Name;

        /// wchar_t[13]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValTStr, SizeConst = 13)]
        public string m_uszFullOctaveReferenceSpectra2Name;

        /// wchar_t[13]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValTStr, SizeConst = 13)]
        public string m_uszFullOctaveReferenceSpectra3Name;

        /// wchar_t[13]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValTStr, SizeConst = 13)]
        public string m_uszFullOctaveReferenceSpectra4Name;

        /// wchar_t[13]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValTStr, SizeConst = 13)]
        public string m_uszThirdOctaveReferenceSpectra1Name;

        /// wchar_t[13]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValTStr, SizeConst = 13)]
        public string m_uszThirdOctaveReferenceSpectra2Name;

        /// wchar_t[13]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValTStr, SizeConst = 13)]
        public string m_uszThirdOctaveReferenceSpectra3Name;

        /// wchar_t[13]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValTStr, SizeConst = 13)]
        public string m_uszThirdOctaveReferenceSpectra4Name;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute(System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct slmSTimeHistory
    {
        /// unsigned int
        public uint m_nAction;

        /// int
        public int m_nFlag;

        /// int
        public int m_nRecordNum;

        /// int
        public int m_nTimeStamp;

        /// int
        public int m_nMiscStartIndex;

        /// float[256]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 256, ArraySubType = System.Runtime.InteropServices.UnmanagedType.R4)]
        public float[] m_pfTHFloatVals;

        /// float[48]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 48, ArraySubType = System.Runtime.InteropServices.UnmanagedType.R4)]
        public float[] m_pfTH11OBAVals;

        /// float[144]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 144, ArraySubType = System.Runtime.InteropServices.UnmanagedType.R4)]
        public float[] m_pfTH13OBAVals;

        /// float
        public float m_fDuration;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute(System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct slmSRunRecord
    {
        /// int
        public int m_nType;

        /// int
        public int m_nCause;

        /// time_t->__time32_t->int
        public int m_tDate;

        /// int
        public int m_nVoiceDataIndex;

        /// int
        public int m_nTHRecord;

        /// int
        public int m_nCount;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute(System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct slmSSpeechData
    {
        /// int
        public int m_nNumSamples;

        /// int
        public int m_nType;

        /// int
        public int m_nSampleRate;

        /// int
        public int m_nNumBitsPerSample;

        /// int
        public int m_nChannels;

        /// int
        public int m_nDataSize;

        /// unsigned char*
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.LPStr)]
        public string m_pbyData;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute(System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct slmSSLnInfo
    {
        /// int[2002]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 2002, ArraySubType = System.Runtime.InteropServices.UnmanagedType.I4)]
        public int[] m_nLnTable;

        /// int
        public int m_nBaseDB;

        /// int
        public int m_nStatus;

        /// int
        public int m_nSamples;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute(System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct slmSEventCounts
    {
        /// int
        public int m_nCount;

        /// float
        public float m_fDuration;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute(System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct slmSInterval
    {
        /// time_t->__time32_t->int
        public int m_tStart;

        /// time_t->__time32_t->int
        public int m_tEnd;

        /// float
        public float m_fRunTime;

        /// float
        public float m_fLeq;

        /// float
        public float m_fLCeq;

        /// float
        public float m_fLAeq;

        /// float
        public float m_fSEL;

        /// float
        public float m_fMax;

        /// float
        public float m_fPeak;

        /// float
        public float m_fMin;

        /// float
        public float m_fSEA;

        /// float
        public float m_fLTm5;

        /// time_t->__time32_t->int
        public int m_tPeakMaxTime;

        /// time_t->__time32_t->int
        public int m_tMaxTime;

        /// time_t->__time32_t->int
        public int m_tMinTime;

        /// float
        public float m_fPauseTime;

        /// int[2000]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 2000, ArraySubType = System.Runtime.InteropServices.UnmanagedType.I4)]
        public int[] m_nLnTable;

        /// int
        public int m_nSRNumber;

        /// int
        public int m_nNumOBA;

        /// float
        public float m_fAltitude;

        /// float[2]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 2, ArraySubType = System.Runtime.InteropServices.UnmanagedType.R4)]
        public float[] m_fTWA;

        /// float[216]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 216, ArraySubType = System.Runtime.InteropServices.UnmanagedType.R4)]
        public float[] m_fSpectralLn;

        /// float[6]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 6, ArraySubType = System.Runtime.InteropServices.UnmanagedType.R4)]
        public float[] m_fLnValues;

        /// float[6]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 6, ArraySubType = System.Runtime.InteropServices.UnmanagedType.R4)]
        public float[] m_fLnPercents;

        /// float
        public float m_fLwIeq;

        /// float
        public float m_fLweq;

        /// slmSEventCounts_t[5]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 5, ArraySubType = System.Runtime.InteropServices.UnmanagedType.Struct)]
        public slmSEventCounts[] m_ExceedCnts;

        /// slmSWeather
        public slmSWeather m_Weather;

        /// slmSOverloads
        public slmSOverloads m_CurrentOverloads;

        /// slmSSpectraInfo_t->slmSSpectra
        public slmSSpectra m_11Spectra;

        /// slmSSpectraInfo_t->slmSSpectra
        public slmSSpectra m_13Spectra;

        /// slmSDegmin
        public slmSDegmin m_dgLatitude;

        /// slmSDegmin
        public slmSDegmin m_dgLongitude;

        /// slmSRHTemp
        public slmSRHTemp m_426A12Data;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute(System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct slmSEventTimeHistory
    {
        /// float
        public float m_fLevel;

        /// float[36]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 36, ArraySubType = System.Runtime.InteropServices.UnmanagedType.R4)]
        public float[] m_fOBA;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute(System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct slmSEventTimeHistoryMngr
    {
        /// slmSEventTimeHistory_t*
        public System.IntPtr m_pETHRecs;

        /// int
        public int m_nNumSamples;

        /// int
        public int m_nOBASize;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute(System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct slmSExceedenceRec
    {
        /// int
        public int m_nID;

        /// int
        public int m_nTHIndex;

        /// time_t->__time32_t->int
        public int m_tStart;

        /// float
        public float m_fDuration;

        /// float
        public float m_fLeq;

        /// float
        public float m_fMaxSPL;

        /// time_t->__time32_t->int
        public int m_tMaxSPLTime;

        /// float
        public float m_fPeakMax;

        /// boolean
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.I1)]
        public bool m_bOBAOverLoad;

        /// boolean
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.I1)]
        public bool m_bOverLoad;

        /// boolean
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.I1)]
        public bool m_bTHOverLoad;

        /// boolean
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.I1)]
        public bool m_bOBATHOverLoad;

        /// int
        public int m_nNumTHSamples;

        /// int
        public int m_nNumPreTrigTHSamples;

        /// float
        public float m_fTrigLevel;

        /// int
        public int m_nSRNumber;

        /// int
        public int m_nExcTHIndex;

        /// float[12]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 12, ArraySubType = System.Runtime.InteropServices.UnmanagedType.R4)]
        public float[] m_11OBALeq;

        /// float[12]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 12, ArraySubType = System.Runtime.InteropServices.UnmanagedType.R4)]
        public float[] m_11OBALMax;

        /// float[36]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 36, ArraySubType = System.Runtime.InteropServices.UnmanagedType.R4)]
        public float[] m_13OBALeq;

        /// float[36]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 36, ArraySubType = System.Runtime.InteropServices.UnmanagedType.R4)]
        public float[] m_13OBALMax;

        /// slmSEventTimeHistoryMngr_t->slmSEventTimeHistoryMngr
        public slmSEventTimeHistoryMngr m_ETHData;

        /// int
        public int m_nNumPostTrigTHSamples;

        /// slmSRT60_SampleT2WithLimits_t->Anonymous_dcca7d72_3fc3_4b32_a478_23231a2c8011
        public slmSRT60_SampleT2WithLimits_t m_T2Sample;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute(System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct slmSCalData
    {
        /// unsigned int[11]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 11, ArraySubType = System.Runtime.InteropServices.UnmanagedType.U4)]
        public uint[] CalibrationDate;

        /// float[11]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 11, ArraySubType = System.Runtime.InteropServices.UnmanagedType.R4)]
        public float[] CalibrationScale;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute(System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct slmSCalHistory
    {
        /// slmSCalData[5]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 5, ArraySubType = System.Runtime.InteropServices.UnmanagedType.Struct)]
        public slmSCalData[] types;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute(System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct slmSNoiseFloor
    {
        /// int
        public int m_nNFPreampType;

        /// int
        public int m_nNFWeighting;

        /// float
        public float m_fNFOverload;

        /// float[3]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 3, ArraySubType = System.Runtime.InteropServices.UnmanagedType.R4)]
        public float[] m_fNFUnderRangeLimitsRms;

        /// float[3]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 3, ArraySubType = System.Runtime.InteropServices.UnmanagedType.R4)]
        public float[] m_fNFUnderRangeLimitsPeak;

        /// float[3]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 3, ArraySubType = System.Runtime.InteropServices.UnmanagedType.R4)]
        public float[] m_fNFUnderNoiseFloor;

        /// float[12]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 12, ArraySubType = System.Runtime.InteropServices.UnmanagedType.R4)]
        public float[] fUnderRangeLimitsOctave;

        /// float[36]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 36, ArraySubType = System.Runtime.InteropServices.UnmanagedType.R4)]
        public float[] fUnderRangeLimitsThirdOctave;

        /// float[12]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 12, ArraySubType = System.Runtime.InteropServices.UnmanagedType.R4)]
        public float[] fNoiseFloorOctave;

        /// float[36]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 36, ArraySubType = System.Runtime.InteropServices.UnmanagedType.R4)]
        public float[] fNoiseFloorThirdOctave;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute(System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct slmSCalData2
    {
        /// int
        public int PreampType;

        /// unsigned int
        public uint CalibrationDate;

        /// float
        public float CalibrationScale;

        /// int
        public int Bins;

        /// float[36]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 36, ArraySubType = System.Runtime.InteropServices.UnmanagedType.R4)]
        public float[] SpectralData;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute(System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct slmSCalHistory2S
    {
        /// slmSCalData2[55]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 55, ArraySubType = System.Runtime.InteropServices.UnmanagedType.Struct)]
        public slmSCalData2[] data;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute(System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct slmSCalCheckHistory
    {
        /// slmSCalData2[11]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 11, ArraySubType = System.Runtime.InteropServices.UnmanagedType.Struct)]
        public slmSCalData2[] data;

        /// float[11]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 11, ArraySubType = System.Runtime.InteropServices.UnmanagedType.R4)]
        public float[] fStdLevel;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute(System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct slmSCalHistory2
    {
        /// slmSCalHistory2S
        public slmSCalHistory2S m_CalHistory;

        /// slmSCalCheckHistory
        public slmSCalCheckHistory m_CalCheckHistory;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute(System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct slmSExError
    {
        /// unsigned int
        public uint m_nExError;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute(System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct slmSByTimeSpectraLevel_t
    {
        /// float[71820]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 71820, ArraySubType = System.Runtime.InteropServices.UnmanagedType.R4)]
        public float[] freqTime;

        /// slmSDataLimits_t[36]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 36, ArraySubType = System.Runtime.InteropServices.UnmanagedType.Struct)]
        public slmSDataLimits_t[] idxPts;

        /// unsigned int
        public uint total_count;

        /// unsigned int
        public uint average_count;

        /// int
        public int sample_count;

        /// unsigned int
        public uint numFreqBands;

        /// unsigned int
        public uint preTriggerCount;

        /// float
        public float samplePeriod;

        /// unsigned int
        public uint RT60_Method;

        /// unsigned int
        public uint time_stamp;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute(System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct slmSFftInfo
    {
        /// unsigned int
        public uint uiFlags;

        /// unsigned int
        public uint uiStartSec;

        /// unsigned int
        public uint uiStartuSec;

        /// float
        public float fDuration;

        /// int
        public int nCount;

        /// int
        public int nOverloadCount;

        /// float
        public float fOverloadDuration;

        /// float
        public float fLeq;

        /// float
        public float fLpeak;

        /// unsigned int
        public uint uiArraySize;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute(System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct slmSFftLevels
    {
        /// float*
        public System.IntPtr pfLevelAvg;

        /// float*
        public System.IntPtr pfLevelMax;
    }

    public enum eSLMFftLevels
    {
        /// eSLMFftAvg -> 0
        eSLMFftAvg = 0,

        eSLMFftMax,

        eSLMFftLvlMax,
    }

    [System.Runtime.InteropServices.StructLayoutAttribute(System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct slmSFftRecord
    {
        /// slmSFftInfo_t->slmSFftInfo
        public slmSFftInfo stInfo;

        /// slmSFftLevels_t->slmSFftLevels
        public slmSFftLevels stLevels;

        /// float[]
        public float[] fLevels;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute(System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct slmSRecord
    {
        /// int
        public int nRecType;

        /// slmSOverallData_t->slmSOverallData
        public slmSOverallData m_OVData;

        /// slmSSettings_t->slmSSettings
        public slmSSettings m_Settings;

        /// slmSFileHeader_t->slmSFileHeader
        public slmSFileHeader m_FileHeader;

        /// slmSPreferences_t->slmSPreferences
        public slmSPreferences m_Prefs;

        /// slmSTimeHistory_t->slmSTimeHistory
        public slmSTimeHistory m_ThRec;

        /// slmSRunRecord_t->slmSRunRecord
        public slmSRunRecord m_RunRec;

        /// slmSSpeechData_t->slmSSpeechData
        public slmSSpeechData m_SpeechRec;

        /// slmSSpeechData_t->slmSSpeechData
        public slmSSpeechData m_AudioRec;

        /// slmSLnInfo_t->slmSSLnInfo
        public slmSSLnInfo m_OverAllLnTable;

        /// slmSEventCounts_t[5]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 5, ArraySubType = System.Runtime.InteropServices.UnmanagedType.Struct)]
        public slmSEventCounts[] m_EvntCnts;

        /// slmSInterval_t->slmSInterval
        public slmSInterval m_Interval;

        /// slmSExceedence_t->slmSExceedenceRec
        public slmSExceedenceRec m_Exceedences;

        /// float[2]
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 2, ArraySubType = System.Runtime.InteropServices.UnmanagedType.R4)]
        public float[] m_fTWA;

        /// slmSCalHistory
        public slmSCalHistory m_CalHistory;

        /// slmSNoiseFloor_t->slmSNoiseFloor
        public slmSNoiseFloor m_NoiseFloor;

        /// slmSCalHistory2_t->slmSCalHistory2
        public slmSCalHistory2 m_CalHistory2;

        /// slmSExError_t->slmSExError
        public slmSExError m_ExtendedError;

        /// slmSByTimeSpectraLevel_t->Anonymous_6e002311_f80a_448c_ade7_e92ff0805640
        public slmSByTimeSpectraLevel_t m_ByTimeAvg;

        /// slmSFftRecord_t->slmSFftRecord
        public slmSFftRecord m_Fft;
    }

    [System.Runtime.InteropServices.StructLayoutAttribute(System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct slmSDataCnts
    {
        /// int
        public int m_nNumEvents;

        /// int
        public int m_nNumTH;

        /// int
        public int m_nNumMeas;

        /// int
        public int m_nNumVoice;

        /// int
        public int m_nNumAudio;

        /// int
        public int m_nNumRunRecs;
    }

    public enum eTypeBulk
    {
        /// eTypeBulkTh -> 0
        eTypeBulkTh = 0,

        /// eTypeBulkEvnt -> 1
        eTypeBulkEvnt = 1,

        /// eTypeBulkMeas -> 2
        eTypeBulkMeas = 2,

        /// eTypeBulkRunRec -> 3
        eTypeBulkRunRec = 3,

        /// eTypeBulkVoice -> 4
        eTypeBulkVoice = 4,

        /// eTypeBulkAudio -> 5
        eTypeBulkAudio = 5,
    }

    [System.Runtime.InteropServices.StructLayoutAttribute(System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct slmSBulkRecords_DLL
    {
        /// eTypeBulk
        public eTypeBulk eRecType;

        /// slmSDataCnts_t->slmSDataCnts
        public slmSDataCnts m_dataCounts;

        /// slmSTimeHistory_t*
        public System.IntPtr m_pThRecs;

        /// slmSInterval_t*
        public System.IntPtr m_pInterval;

        /// slmSExceedence_t*
        public System.IntPtr m_pExceedences;

        /// slmSRunRecord_t*
        public System.IntPtr m_pRunRecord;

        /// slmSSpeechData_t*
        public System.IntPtr m_pVoiceRecord;

        /// slmSSpeechData_t*
        public System.IntPtr m_pAudioRecord;
    }

    public struct slmSBulkRecords
    {
        /// eTypeBulk
        public eTypeBulk eRecType;

        /// slmSDataCnts_t->slmSDataCnts
        public slmSDataCnts m_dataCounts;

        /// slmSTimeHistory_t[]
        public slmSTimeHistory[] m_pThRecs;

        /// slmSInterval_t[]
        public slmSInterval[] m_pInterval;

        /// slmSExceedence_t[]
        public slmSExceedenceRec[] m_pExceedences;

        /// slmSRunRecord_t[]
        public slmSRunRecord[] m_pRunRecord;

        /// slmSSpeechData_t[]
        public slmSSpeechData[] m_pVoiceRecord;

        /// slmSSpeechData_t[]
        public slmSSpeechData[] m_pAudioRecord;
    }

    public partial class NativeMethods
    {
        /// Return Type: boolean
        ///pwstrFilename: wchar_t*
        ///nIndex: int
        [System.Runtime.InteropServices.DllImportAttribute("SlmInterface.dll", EntryPoint = "SI_StartSlmTranslation", CallingConvention = CallingConvention.Cdecl)]
        [return: System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.I1)]
        public static extern bool SI_StartSlmTranslation([System.Runtime.InteropServices.InAttribute()] [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.LPWStr)] string pwstrFilename, int nIndex);

        /// Return Type: void
        [System.Runtime.InteropServices.DllImportAttribute("SlmInterface.dll", EntryPoint = "SI_EndSlmTranslation", CallingConvention = CallingConvention.Cdecl)]
        public static extern void SI_EndSlmTranslation();

        /// Return Type: int
        ///pwstrFilename: wchar_t*
        ///pnVersion: int*
        [System.Runtime.InteropServices.DllImportAttribute("SlmInterface.dll", EntryPoint = "SI_GetLDFileType", CallingConvention = CallingConvention.Cdecl)]
        public static extern int SI_GetLDFileType([System.Runtime.InteropServices.InAttribute()] [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.LPWStr)] string pwstrFilename, ref int pnVersion);

        /// Return Type: boolean
        ///pfh: slmSFileHeader_t*
        [System.Runtime.InteropServices.DllImportAttribute("SlmInterface.dll", EntryPoint = "SI_GetSlmHeaderEx", CallingConvention = CallingConvention.Cdecl)]
        [return: System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.I1)]
        public static extern bool SI_GetSlmHeaderEx(ref slmSFileHeader pfh);

        /// Return Type: boolean
        ///pRec: slmSRecord_t*
        ///nIndex: int
        [System.Runtime.InteropServices.DllImportAttribute("SlmInterface.dll", EntryPoint = "SI_GetNextSlmRecordEx_Settings", CallingConvention = CallingConvention.Cdecl)]
        [return: System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.I1)]
        public static extern bool SI_GetNextSlmRecordEx_Settings(ref slmSSettings pSettings);

        public static bool SI_GetNextSlmRecordEx(ref slmSRecord pRec, int nIndex)
        {
            switch (nIndex)
            {
                case NativeConstants.TYPE_SETTINGS: return SI_GetNextSlmRecordEx_Settings(ref pRec.m_Settings);
            }

            return false;
        }

        /// Return Type: void
        ///pDataCnts: slmSDataCnts_t*
        [System.Runtime.InteropServices.DllImportAttribute("SlmInterface.dll", EntryPoint = "SI_GetBulkCountsEx", CallingConvention = CallingConvention.Cdecl)]
        public static extern void SI_GetBulkCountsEx(ref slmSDataCnts pDataCnts);

        /// Return Type: boolean
        ///pSlmBulkRec: slmSBulkRecord_t*
        [System.Runtime.InteropServices.DllImportAttribute("SlmInterface.dll", EntryPoint = "SI_GetBulkDataEx", CallingConvention = CallingConvention.Cdecl)]
        [return: System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.I1)]
        private static extern bool SI_GetBulkDataEx_DLL(ref slmSBulkRecords_DLL pSlmBulkRec);

        public static bool SI_GetBulkDataEx(ref slmSBulkRecords pSlmBulkRec)
        {
            slmSBulkRecords_DLL bulkRecords_DLL = new slmSBulkRecords_DLL();
            bulkRecords_DLL.eRecType = pSlmBulkRec.eRecType;
            bulkRecords_DLL.m_dataCounts = pSlmBulkRec.m_dataCounts;
            bulkRecords_DLL.m_pThRecs = Marshal.AllocHGlobal(Marshal.SizeOf(typeof(slmSTimeHistory)) * pSlmBulkRec.m_dataCounts.m_nNumTH);

            bool bReturn = SI_GetBulkDataEx_DLL(ref bulkRecords_DLL);
            if (bReturn)
            {
                IntPtr pPtr = bulkRecords_DLL.m_pThRecs;
                for (int i = 0; i < pSlmBulkRec.m_dataCounts.m_nNumTH; i++)
                {
                    pSlmBulkRec.m_pThRecs[i] = (slmSTimeHistory)Marshal.PtrToStructure(pPtr, typeof(slmSTimeHistory));

                    pPtr = (IntPtr)((int)pPtr + Marshal.SizeOf(typeof(slmSTimeHistory)));
                }
            }

            Marshal.FreeHGlobal(bulkRecords_DLL.m_pThRecs);
            return bReturn;
        }

        /// Return Type: void
        ///pfh: slmSFileHeader_t*
        [System.Runtime.InteropServices.DllImportAttribute("SlmInterface.dll", EntryPoint = "SI_ReleaseSlmHeaderEx", CallingConvention = CallingConvention.Cdecl)]
        public static extern void SI_ReleaseSlmHeaderEx(ref slmSFileHeader pfh);

        /// Return Type: void
        ///pRec: slmSRecord_t*
        [System.Runtime.InteropServices.DllImportAttribute("SlmInterface.dll", EntryPoint = "SI_ReleaseNextSlmRecordEx", CallingConvention = CallingConvention.Cdecl)]
        public static extern void SI_ReleaseNextSlmRecordEx(ref slmSRecord pRec);

        /// Return Type: void
        ///pDataCnts: slmSDataCnts_t*
        [System.Runtime.InteropServices.DllImportAttribute("SlmInterface.dll", EntryPoint = "SI_ReleaseBulkCountsEx", CallingConvention = CallingConvention.Cdecl)]
        public static extern void SI_ReleaseBulkCountsEx(ref slmSDataCnts pDataCnts);

        /// Return Type: void
        ///pSlmBulkRec: slmSBulkRecord_t*
        [System.Runtime.InteropServices.DllImportAttribute("SlmInterface.dll", EntryPoint = "SI_ReleaseBulkDataEx", CallingConvention = CallingConvention.Cdecl)]
        public static extern void SI_ReleaseBulkDataEx(ref slmSBulkRecords pSlmBulkRec);

        /// Return Type: int
        [System.Runtime.InteropServices.DllImportAttribute("SlmInterface.dll", EntryPoint = "SI_GetInstrumentMode", CallingConvention = CallingConvention.Cdecl)]
        public static extern int SI_GetInstrumentMode();
    }
}
