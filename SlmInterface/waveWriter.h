#ifndef _WAVEWRITER_H_
#define _WAVEWRITER_H_

#include <string>

//! Class for writing a wav file given a collection of samples
class WaveWriter
{
public:
    //! Channel modes
    enum
    {
        MONO,
        STEREO
    } ChannelMode;

	//! Bits can be 8 for PCM8 or 16 for PCM16
    //! Sample rate can be 8000 or 16000, etc.
    //! Use MONO or STEREO for channelmode
    WaveWriter( unsigned int bits, unsigned int samplerate, unsigned int channelmode );

    virtual ~WaveWriter();

    //! Write out the content of buffer into given file
    bool write( const std::string& filename, const char* data, const unsigned int dataLength );

protected:
    void writeHeader( std::fstream& stream, unsigned int dataLength );

    unsigned int _rate;
    unsigned int _bits;
    unsigned int _channels;
};

//! Include the inline file
#include "wavewriter.inl"

#endif // _WAVEWRITER_H_
