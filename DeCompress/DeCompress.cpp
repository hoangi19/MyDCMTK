#include <iostream>
#include "dcmtk/dcmjpeg/djdecode.h"
#include "dcmtk/dcmjpeg/djencode.h"
#include "dcmtk/dcmdata/dcfilefo.h"
#include "dcmtk/dcmdata/dcdatset.h"
#include "dcmtk/dcmdata/dcitem.h"
#include "dcmtk/dcmjpeg/djrplol.h"
#include "dcmtk/dcmdata/dctk.h"

int main(int argc, char const *argv[])
{
    DJDecoderRegistration::registerCodecs(); // register JPEG codecs
    DcmFileFormat fileformat;
    if (fileformat.loadFile("..\\..\\..\\test_Encodejpeg.dcm").good())
    {
        DcmDataset *dataset = fileformat.getDataset();

    // decompress data set if compressed
    if (dataset->chooseRepresentation(EXS_LittleEndianExplicit, NULL).good() &&
        dataset->canWriteXfer(EXS_LittleEndianExplicit))
        {
            fileformat.saveFile("..\\..\\res_decompressed.dcm", EXS_LittleEndianExplicit);
        }
    }
    DJDecoderRegistration::cleanup(); // deregister JPEG codecs
    return 0;
}
