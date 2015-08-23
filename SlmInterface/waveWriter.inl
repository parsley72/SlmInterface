#ifndef _WAVEWRITER_H_
#error "do not include this file directly, include waveWriter.h instead"
#endif

#include <assert.h>
#include <fstream>

WaveWriter::WaveWriter( unsigned int bits, unsigned int samplerate, unsigned int channelmode ) :
_bits ( bits ),
_rate( samplerate )
{
    assert( ( channelmode == WaveWriter::MONO ) || ( channelmode == WaveWriter::STEREO ) && "wrong channel mode!" );

    if ( channelmode == MONO )
        _channels = 1;
    else
        _channels = 2;
}

WaveWriter::~WaveWriter()
{
}

void WaveWriter::writeHeader( std::fstream& stream, unsigned int dataLength )
{
    typedef struct
    {
        char        _id[ 4 ];                   /* "RIFF" */
        int         _size;
        char        _formatTag[ 4 ];            /* format type  "WAVE" */
    } RiffChunk;

    typedef struct 
    {
        char            _subChunk1ID[ 4 ];      /* "fmt " */
        unsigned int    _subChunk1Size;         /* 16 for PCM  */
        unsigned short  _audioFormat;           /* 1 for PCM  */
        unsigned short  _channels;              /* number of channels (i.e. mono, stereo...)  */
        unsigned int    _samplesPerSec;         /* sample rate  */
        unsigned int    _avgBytesPerSec;        /* for buffer estimation  */
        unsigned short  _blockAlign;            /* block size of data  */
        unsigned short  _bitsPerSample;         /* number of bits per sample of mono data */
    } FmtChunk;

    typedef struct 
    {
        char            _subChunk2ID[ 4 ];      /* "data" */
        unsigned int    _subChunk2Size;
    } DataChunk;

    typedef struct
    {
        RiffChunk       _riffchunk;
        FmtChunk        _fmtchunk;
        DataChunk       _datachunk;
    } WavHeader;
    
    WavHeader header;
    // fill in the RIFF chunk
//    strcpy_s( header._riffchunk._id, "RIFF" );
	header._riffchunk._id[0] = 'R';
	header._riffchunk._id[1] = 'I';
	header._riffchunk._id[2] = 'F';
	header._riffchunk._id[3] = 'F';

    header._riffchunk._size = 36 + _rate * _channels * _bits / 8;
//    strcpy_s( header._riffchunk._formatTag, "WAVE" );
	header._riffchunk._formatTag[0] = 'W';
	header._riffchunk._formatTag[1] = 'A';
	header._riffchunk._formatTag[2] = 'V';
	header._riffchunk._formatTag[3] = 'E';

    // fill in the subchunk 1
//    strcpy_s( header._fmtchunk._subChunk1ID, "fmt " );
	header._fmtchunk._subChunk1ID[0] = 'f';
	header._fmtchunk._subChunk1ID[1] = 'm';
	header._fmtchunk._subChunk1ID[2] = 't';
	header._fmtchunk._subChunk1ID[3] = ' ';

    header._fmtchunk._subChunk1Size  = 16; // 16 for PCM
    header._fmtchunk._audioFormat    = 1;  // 1  for PCM
    header._fmtchunk._channels       = _channels;
    header._fmtchunk._samplesPerSec  = _rate;
    header._fmtchunk._avgBytesPerSec = _rate * _channels * _bits / 8;
    header._fmtchunk._blockAlign     = _channels * _bits / 8;
    header._fmtchunk._bitsPerSample  = _bits;
    // fill in the subchunk 2
//    strcpy_s( header._datachunk._subChunk2ID, "data" );
	header._datachunk._subChunk2ID[0] = 'd';
	header._datachunk._subChunk2ID[1] = 'a';
	header._datachunk._subChunk2ID[2] = 't';
	header._datachunk._subChunk2ID[3] = 'a';
    header._datachunk._subChunk2Size = dataLength * _channels * _bits / 8;

    // write out the header
    char* p_buffer = reinterpret_cast< char* >( &header );
    unsigned int headersize = sizeof( header );
    for ( unsigned int cnt = 0; cnt < headersize; ++cnt )
	{
        stream << p_buffer[ cnt ];
	}
}

bool WaveWriter::write( const std::string& filename, const char* data, const unsigned int dataLength )
{
    std::fstream file;

    file.open( filename.c_str(), std::ios_base::out | std::ios_base::binary );
    if ( !file )
	{
        return false;
	}

    writeHeader( file, dataLength );

	unsigned int size = dataLength * (_bits / 8);

	file.write(data, size);

    file.close();

    return true;
}
